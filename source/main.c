/*
 * Copyright 2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */


// AKTUALNA WERSJA PROJEKTU --------------------------------------------------------
#include "FreeRTOS.h"
#include "task.h"

#include "fsl_debug_console.h"
#include "littlevgl_support.h"
#include "board.h"

#include "data.h"
#include "pin_mux.h"
#include "qcom_api.h"
#include "wlan_qcom.h"
#include <stdbool.h>
#include "fsl_spi.h"
#include "smart_fridge.h"
#include "RC522.h"
#include "peripherals.h"
#include "GUI.h"
#include "GUI_ExtData.h"
#include <fsl_rtc.h>
#include "fsl_spifi.h"


#define TIME_SERVER "showcase.api.linx.twenty57.net"

//#define SPIFI_DATA_START_ADDRESS 819200
//#define SPIFI_NUMBER_OF_PRODUCTS_ADDRESS SPIFI_DATA_START_ADDRESS+3501

#define SPIFI_DATA_START_ADDRESS 143360
#define SPIFI_NUMBER_OF_PRODUCTS_ADDRESS SPIFI_DATA_START_ADDRESS+56001
#define SPIFI_SHOP_LIST_ADDRESS 225280
#define SPIFI_NETWORK_DATA_ADDRESS 241664

#define NETWORK_DATA_LENGTH 98
#define PRODUCTS_DATA_LENGTH_BYTES 3500

//#define SPIFI_WIFI_SSID_ADDRESS

#define EXAMPLE_SPI_MASTER          SPI0/*
#define EXAMPLE_SPI_MASTER_IRQ      FLEXCOMM0_IRQn
#define EXAMPLE_SPI_MASTER_CLK_SRC  kCLOCK_Flexcomm0
#define EXAMPLE_SPI_MASTER_CLK_FREQ CLOCK_GetFlexCommClkFreq(0)
#define EXAMPLE_SPI_SSEL            0
#define EXAMPLE_SPI_SPOL            kSPI_SpolActiveAllLow

/*******************************************************************************
 * Definitions
 ******************************************************************************/
static volatile bool s_lvgl_initialized = false;
static volatile bool GUI_Initialized = false;

SemaphoreHandle_t xSemaphore = NULL;
/*******************************************************************************
 * Prototypes
 ******************************************************************************/

const int TASK_MAIN_PRIO       = configMAX_PRIORITIES - 3;
const int TASK_MAIN_STACK_SIZE = 800;

portSTACK_TYPE *task_main_stack = NULL;
TaskHandle_t task_main_task_handler;
TaskHandle_t task_disp_task_handler;

// Hardwired SSID, passphrase, auth and cipher algo of AP to connect to
// Change this to fit your AP

#define SSID_LENGTH 33
#define PASSWORD_LENGTH 65
typedef struct{
	char WIFI_SSID[33];
	char WIFI_PASSWORD[65];
	int SSID_LEN;
	int PASSWORD_LEN;
}WIFI_AUTH;

WIFI_AUTH wifi_data;


QCOM_SSID g_ssid;
QCOM_PASSPHRASE g_passphrase;

WLAN_AUTH_MODE g_auth    = WLAN_AUTH_WPA2_PSK;
WLAN_CRYPT_TYPE g_cipher = WLAN_CRYPT_AES_CRYPT;

// ============================================================================
// Menu Handling
// ============================================================================

extern int numIrqs;
extern int initTime;

lv_obj_t *label3;
int licznik = 0;


enum STATE
{
    STATE_IDLE,
    STATE_CONNECTING,
    STATE_CONNECTED,
};

int state = STATE_IDLE;
/*******************************************************************************
 * Prototypes
 ******************************************************************************/

spifi_command_t command[COMMAND_NUM] = {
		{PAGE_SIZE, false, kSPIFI_DataInput, 1, kSPIFI_CommandDataQuad, kSPIFI_CommandOpcodeAddrThreeBytes, 0x6B},
		{PAGE_SIZE, false, kSPIFI_DataOutput, 0, kSPIFI_CommandDataQuad, kSPIFI_CommandOpcodeAddrThreeBytes, 0x32},
		{1, false, kSPIFI_DataInput, 0, kSPIFI_CommandAllSerial, kSPIFI_CommandOpcodeOnly, 0x05},
		{0, false, kSPIFI_DataOutput, 0, kSPIFI_CommandAllSerial, kSPIFI_CommandOpcodeAddrThreeBytes, 0x20},
		{0, false, kSPIFI_DataOutput, 0, kSPIFI_CommandAllSerial, kSPIFI_CommandOpcodeOnly, 0x06},
		{1, false, kSPIFI_DataOutput, 0, kSPIFI_CommandAllSerial, kSPIFI_CommandOpcodeOnly, 0x31}};


void check_if_finish();
void saveNetworkInFlash(void);
bool connectWiF(const char *ssid, const char *password){

	apDisconnect();
	strcpy(wifi_data.WIFI_SSID,ssid);
	strcpy(wifi_data.WIFI_PASSWORD,password);
	wifi_data.SSID_LEN = SSID_LENGTH;
	wifi_data.PASSWORD_LEN = PASSWORD_LENGTH;

	strcpy(g_ssid.ssid,ssid);
	strcpy(g_passphrase.passphrase,password);

	bool dhcpGetted = false;
	int wifiTimer = 0;
	apConnect(&g_ssid, &g_passphrase, g_auth, g_cipher);

	//dispPRINTF("Before get dhcp",label3);
	while(wifiTimer < 5){
		if(!dhcpGetted){
			if(isConnected()){
				if(getDhcp()){
					///dispPRINTF("Polaczono\n",label3);
					PRINTF("POL");
					GPIO_PinWrite(GPIO,1,22,1);
					vTaskDelay(MSEC_TO_TICK(200));
					GPIO_PinWrite(GPIO,1,22,0);
					vTaskDelay(MSEC_TO_TICK(200));
					GPIO_PinWrite(GPIO,1,22,1);
					vTaskDelay(MSEC_TO_TICK(200));
					GPIO_PinWrite(GPIO,1,22,0);
					vTaskDelay(MSEC_TO_TICK(200));
					GPIO_PinWrite(GPIO,1,22,1);
					vTaskDelay(MSEC_TO_TICK(400));
					GPIO_PinWrite(GPIO,1,22,0);
					state = STATE_CONNECTED;
					dhcpGetted = true;
					saveNetworkInFlash();
					return true;
				}
				else{
					PRINTF("POL");
					GPIO_PinWrite(GPIO,1,22,1);
					vTaskDelay(MSEC_TO_TICK(900));
					GPIO_PinWrite(GPIO,1,22,0);

				}
			}
		}
		wifiTimer++;
		vTaskDelay(MSEC_TO_TICK(1000));
	}
	//dispPRINTF("Nie polaczono\n",label3);
	return false;
}

void disconnectWifi(void){
	if(isConnected()){
		GPIO_PinWrite(GPIO,1,22,1);
		vTaskDelay(MSEC_TO_TICK(300));
		GPIO_PinWrite(GPIO,1,22,0);
		vTaskDelay(MSEC_TO_TICK(300));
		GPIO_PinWrite(GPIO,1,22,1);
		vTaskDelay(MSEC_TO_TICK(900));
		GPIO_PinWrite(GPIO,1,22,0);
		apDisconnect();
	}else{
		GPIO_PinWrite(GPIO,1,22,1);
		vTaskDelay(MSEC_TO_TICK(300));
		GPIO_PinWrite(GPIO,1,22,0);
		vTaskDelay(MSEC_TO_TICK(300));
		GPIO_PinWrite(GPIO,1,22,1);
		vTaskDelay(MSEC_TO_TICK(900));
		GPIO_PinWrite(GPIO,1,22,0);
		vTaskDelay(MSEC_TO_TICK(300));
		GPIO_PinWrite(GPIO,1,22,1);
		vTaskDelay(MSEC_TO_TICK(900));
		GPIO_PinWrite(GPIO,1,22,0);
	}
}

void saveNetworkInFlash(void){

	uint32_t data=0, page=0;
	int i=0;
	int j=0;
	int k=0;
	char *ptr = &wifi_data.WIFI_SSID[0];


	SPIFI_SetCommand(BOARD_FLASH_SPIFI, &command[WRITE_ENABLE]);
	SPIFI_SetCommandAddress(BOARD_FLASH_SPIFI, SPIFI_NETWORK_DATA_ADDRESS);
	SPIFI_SetCommand(BOARD_FLASH_SPIFI, &command[ERASE_SECTOR]);
	check_if_finish();


	while (page < (SECTOR_SIZE / PAGE_SIZE))
	{
		SPIFI_SetCommand(BOARD_FLASH_SPIFI, &command[WRITE_ENABLE]);
		SPIFI_SetCommandAddress(BOARD_FLASH_SPIFI, SPIFI_NETWORK_DATA_ADDRESS + page * PAGE_SIZE);
		SPIFI_SetCommand(BOARD_FLASH_SPIFI, &command[PROGRAM_PAGE]);
		for (i = 0; i < PAGE_SIZE; i += 4)
		{
			if(k < 4096){
				for (j = 0; j < 4; j++)
				{
					if(k < 4096){
						data |= ((uint32_t)(*ptr)) << (j * 8);
						ptr++;
						k++;
					}
				}

				SPIFI_WriteData(BOARD_FLASH_SPIFI, data);
				data = 0;
			}
		}
		page++;
		check_if_finish();
	}

	/* Reset to memory command mode */
	SPIFI_ResetCommand(BOARD_FLASH_SPIFI);
	SPIFI_SetMemoryCommand(BOARD_FLASH_SPIFI, &command[READ]);
}

void autoConnectWifi(void){
	uint8_t *val;
	/* Reset to memory command mode */
	SPIFI_ResetCommand(BOARD_FLASH_SPIFI);

	SPIFI_SetMemoryCommand(BOARD_FLASH_SPIFI, &command[READ]);

	char *readproducts;
	readproducts = &wifi_data.WIFI_SSID[0];
	for (int i = 0; i < SECTOR_SIZE; i++)	// Odczyta to max. 3 produkty, do odczytania 50 produktow zwiekszyc do 56000
	{
		if(i < 98){
			val = (uint8_t *)(FSL_FEATURE_SPIFI_START_ADDR+SPIFI_NETWORK_DATA_ADDRESS + i);
			*readproducts = *val;
			readproducts++;

		}
	}

	connectWiF(wifi_data.WIFI_SSID,wifi_data.WIFI_PASSWORD);



}



void translateList(){
	if(products_numb >= 25)
		products_numb = 0;

	for(int i=0;i<products_numb;i++){
		DATA_ProdList[i].category = ((int)products[i].productCategory[0])- '0';

		for(int j=0;j<11;j++){
			DATA_ProdList[i].date[j] = products[i].expirationDate[j];
		}



		int j = 0;
		int k = 0;

		while(products[i].productName[k] != '\0'){
			DATA_ProdList[i].name[j] = products[i].productName[k];
			j++;
			k++;
		}
		DATA_ProdList[i].name[j] = ' ';
		j++;

		k = 0;
		while(products[i].productBrand[k] != '\0'){
			DATA_ProdList[i].name[j] = products[i].productBrand[k];
			j++;
			k++;
		}
		DATA_ProdList[i].name[j] = ' ';
		j++;

		k = 0;
		while(products[i].productDetails[k] != '\0'){
			DATA_ProdList[i].name[j] = products[i].productDetails[k];
			j++;
			k++;
		}
		DATA_ProdList[i].name[j] = ' ';
		j++;

		k = 0;
		while(products[i].productCapacity[k] != '\0'){
			DATA_ProdList[i].name[j] = products[i].productCapacity[k];
			j++;
			k++;
		}
		DATA_ProdList[i].name[j] = '\0';
		//j++;




	}
}
void check_if_finish()
{
    uint8_t val = 0;
    /* Check WIP bit */
    do
    {
        SPIFI_SetCommand(BOARD_FLASH_SPIFI, &command[GET_STATUS]);
        while ((BOARD_FLASH_SPIFI->STAT & SPIFI_STAT_INTRQ_MASK) == 0U)
        {
        }
        val = SPIFI_ReadDataByte(BOARD_FLASH_SPIFI);
    } while (val & 0x1);
}

void loadDataFromFlashMemory(){
	uint8_t *val;
	/* Reset to memory command mode */
	SPIFI_ResetCommand(BOARD_FLASH_SPIFI);

	SPIFI_SetMemoryCommand(BOARD_FLASH_SPIFI, &command[READ]);

	uint8_t *readproducts;
	char *shoplistptr;

	// Read products from flash
	readproducts = &products[0].size;
	for (int i = 0; i < PRODUCTS_DATA_LENGTH_BYTES; i++)
	{
		val = (uint8_t *)(FSL_FEATURE_SPIFI_START_ADDR+SPIFI_DATA_START_ADDRESS + i);


		*readproducts = *val;
		readproducts++;
	}

	// Read number of products from flash
	val = (uint8_t *)(FSL_FEATURE_SPIFI_START_ADDR+SPIFI_NUMBER_OF_PRODUCTS_ADDRESS);
	products_numb = *val;

	// Read shop list from flash
	shoplistptr = &shoplist[0][0];

	int licznik = 0;
	bool ptr1 = false;
	bool ptr2 = false;
	bool ptr3 = false;
	bool ptr4 = false;
	bool ptr5 = false;
	bool ptr6 = false;
	bool ptr7 = false;
	bool ptr8 = false;
	bool ptr9 = false;
	bool ptr10= false;

	for(int i=0;i<SHOPLIST_NAME_SIZE*5;i++){
		val = (uint8_t *)(FSL_FEATURE_SPIFI_START_ADDR+SPIFI_SHOP_LIST_ADDRESS + i);

		if(i >=50 && i<100){
			if(!ptr2){
				shoplistptr = &shoplist[1][0];
				ptr2 = true;
			}
		}else if(i >=100 && i<150){
			if(!ptr3){
				shoplistptr = &shoplist[2][0];
				ptr3 = true;
			}
		}else if(i >=150 && i<200){
			if(!ptr4){
				shoplistptr = &shoplist[3][0];
				ptr4 = true;
			}
		}else if(i >=200 && i<250){
			if(!ptr5){
				shoplistptr = &shoplist[4][0];
				ptr5 = true;
			}
		}
		*shoplistptr = *val;
		shoplistptr++;
	}





}
//void saveDataInFlash(){
//
//
//	/* Setup memory command */
//		//SPIFI_SetMemoryCommand(BOARD_FLASH_SPIFI, &command[READ]);
//
//		/* Reset the SPIFI to switch to command mode */
//		SPIFI_ResetCommand(BOARD_FLASH_SPIFI);
//
//		EnableIRQ(SPIFI0_IRQn);
//
//
//		// WRITE TO SPIFI
//		uint8_t *productsptr;
//		uint32_t data=0, page=0;
//		int i=0;
//		int j=0;
//		int k=0;
//
//		productsptr = &products[0].size;
//
//			/* Write enable */
//			SPIFI_SetCommand(BOARD_FLASH_SPIFI, &command[WRITE_ENABLE]);
//			/* Set address */
//			SPIFI_SetCommandAddress(BOARD_FLASH_SPIFI, 0U+SPIFI_DATA_START_ADDRESS);
//			/* Erase sector */
//			SPIFI_SetCommand(BOARD_FLASH_SPIFI, &command[ERASE_SECTOR]);
//			/* Check if finished */
//			check_if_finish();
//			while (page < ((SECTOR_SIZE / PAGE_SIZE))-8)
//			{
//				SPIFI_SetCommand(BOARD_FLASH_SPIFI, &command[WRITE_ENABLE]);
//				SPIFI_SetCommandAddress(BOARD_FLASH_SPIFI, SPIFI_DATA_START_ADDRESS+ page * PAGE_SIZE);
//				SPIFI_SetCommand(BOARD_FLASH_SPIFI, &command[PROGRAM_PAGE]);
//				for (i = 0; i < PAGE_SIZE; i += 4)
//				{
//					if(k < 3500){
//						for (j = 0; j < 4; j++)
//						{
//							if(k < 3500){
//								data |= ((uint32_t)(*productsptr)) << (j * 8);
//								productsptr++;
//								k++;
//							}
//						}
//
//						SPIFI_WriteData(BOARD_FLASH_SPIFI, data);
//						data = 0;
//					}
//				}
//				page++;
//				check_if_finish();
//			}
//
//
//
//		// WRITE NUMBER OF PRODUCTS
//		SPIFI_SetCommand(BOARD_FLASH_SPIFI, &command[WRITE_ENABLE]);
//		SPIFI_SetCommandAddress(BOARD_FLASH_SPIFI, SPIFI_NUMBER_OF_PRODUCTS_ADDRESS);
//		SPIFI_SetCommand(BOARD_FLASH_SPIFI, &command[PROGRAM_PAGE]);
//
//		//data |= ((index)) << (j * 8);
//		SPIFI_WriteData(BOARD_FLASH_SPIFI, index);
//		check_if_finish();
//
//		/* Reset to memory command mode */
//		SPIFI_ResetCommand(BOARD_FLASH_SPIFI);
//		SPIFI_SetMemoryCommand(BOARD_FLASH_SPIFI, &command[READ]);
//		dataUpdateAvailable = false;
//}

void saveDataInFlash(){


	/* Setup memory command */
	//SPIFI_SetMemoryCommand(BOARD_FLASH_SPIFI, &command[READ]);

	/* Reset the SPIFI to switch to command mode */
	SPIFI_ResetCommand(BOARD_FLASH_SPIFI);

	EnableIRQ(SPIFI0_IRQn);


	// WRITE TO SPIFI
	uint8_t *productsptr;
	char *shoplistptr;
	uint32_t data=0, page=0;
	int i=0;
	int j=0;
	int k=0;
	int l=0;
	productsptr = &products[0].size;
	//while(l < 14){
		/* Write enable */
		SPIFI_SetCommand(BOARD_FLASH_SPIFI, &command[WRITE_ENABLE]);
		/* Set address */
		SPIFI_SetCommandAddress(BOARD_FLASH_SPIFI, 0U+SPIFI_DATA_START_ADDRESS+l*4096);
		/* Erase sector */
		SPIFI_SetCommand(BOARD_FLASH_SPIFI, &command[ERASE_SECTOR]);
		/* Check if finished */
		check_if_finish();


		while (page < 14)
		{
			SPIFI_SetCommand(BOARD_FLASH_SPIFI, &command[WRITE_ENABLE]);
			SPIFI_SetCommandAddress(BOARD_FLASH_SPIFI, SPIFI_DATA_START_ADDRESS+l*4096+ page * PAGE_SIZE);
			SPIFI_SetCommand(BOARD_FLASH_SPIFI, &command[PROGRAM_PAGE]);
			for (i = 0; i < PAGE_SIZE; i += 4)
			{
				if(k < PRODUCTS_DATA_LENGTH_BYTES){
					for (j = 0; j < 4; j++)
					{
						if(k < PRODUCTS_DATA_LENGTH_BYTES){
							data |= ((uint32_t)(*productsptr)) << (j * 8);
							productsptr++;
							k++;
						}else{
							data|=((uint32_t)(0)) << (j * 8);
						}
					}
					SPIFI_WriteData(BOARD_FLASH_SPIFI, data);
					data = 0;
				}else{
					SPIFI_WriteData(BOARD_FLASH_SPIFI, data);
					data = 0;
				}

			}
			page++;
			check_if_finish();
		}
		//l++;
	//}
		vTaskDelay(200);



		SPIFI_SetCommand(BOARD_FLASH_SPIFI, &command[WRITE_ENABLE]);
		/* Set address */
		SPIFI_SetCommandAddress(BOARD_FLASH_SPIFI, SPIFI_NUMBER_OF_PRODUCTS_ADDRESS);
		/* Erase sector */
		SPIFI_SetCommand(BOARD_FLASH_SPIFI, &command[ERASE_SECTOR]);
		/* Check if finished */
		check_if_finish();
		// WRITE NUMBER OF PRODUCTS
		SPIFI_SetCommand(BOARD_FLASH_SPIFI, &command[WRITE_ENABLE]);
		SPIFI_SetCommandAddress(BOARD_FLASH_SPIFI, SPIFI_NUMBER_OF_PRODUCTS_ADDRESS);
		SPIFI_SetCommand(BOARD_FLASH_SPIFI, &command[PROGRAM_PAGE]);

	for (i = 0; i < PAGE_SIZE; i += 4)
	{
		if(i == 0){


			SPIFI_WriteData(BOARD_FLASH_SPIFI, products_numb);

		}else{
			for (j = 0; j < 4; j++)
			{
				data |= ((uint32_t)(0)) << (j * 8);

			}
			SPIFI_WriteData(BOARD_FLASH_SPIFI, data);
		}

	}
	check_if_finish();


	//data |= ((index)) << (j * 8);
	//SPIFI_WriteData(BOARD_FLASH_SPIFI, products_numb);



//	// WRITE SHOP LIST
	SPIFI_SetCommand(BOARD_FLASH_SPIFI, &command[WRITE_ENABLE]);
	SPIFI_SetCommandAddress(BOARD_FLASH_SPIFI, SPIFI_SHOP_LIST_ADDRESS);
	SPIFI_SetCommand(BOARD_FLASH_SPIFI, &command[ERASE_SECTOR]);
	check_if_finish();



	SPIFI_SetCommand(BOARD_FLASH_SPIFI, &command[WRITE_ENABLE]);
	SPIFI_SetCommandAddress(BOARD_FLASH_SPIFI, SPIFI_SHOP_LIST_ADDRESS);
	SPIFI_SetCommand(BOARD_FLASH_SPIFI, &command[PROGRAM_PAGE]);

	k=0;
	data = 0;
	bool ptr2 = false;
	bool ptr3 = false;
	bool ptr4 = false;
	bool ptr5 = false;
	shoplistptr = &shoplist[0][0];
	for (i = 0; i < PAGE_SIZE; i += 4)
	{

		for (j = 0; j < 4; j++)
		{
			if(i+j >=50 && i<100){
				if(!ptr2){
					shoplistptr = &shoplist[1][0];
					ptr2 = true;
				}
			}else if(i+j >=100 && i<150){
				if(!ptr3){
					shoplistptr = &shoplist[2][0];
					ptr3 = true;
				}
			}else if(i+j >=150 && i<200){
				if(!ptr4){
					shoplistptr = &shoplist[3][0];
					ptr4 = true;
				}
			}else if(i+j >=200 && i<250){
				if(!ptr5){
					shoplistptr = &shoplist[4][0];
					ptr5 = true;
				}
			}else{

			}
			if(i < 250){
				data |= ((uint32_t)(*shoplistptr)) << (j * 8);
				shoplistptr++;
			}else{
				data = 0;
			}
		}

			SPIFI_WriteData(BOARD_FLASH_SPIFI, data);
			data = 0;




	}
	check_if_finish();



	/* Reset to memory command mode */
	SPIFI_ResetCommand(BOARD_FLASH_SPIFI);
	SPIFI_SetMemoryCommand(BOARD_FLASH_SPIFI, &command[READ]);
}


// Przeniesione do Init_Peripherals
/*
void RC522_SPI_Config(){
	spi_master_config_t userConfig = {0};
	uint32_t srcFreq               = 0;
	/* attach 12 MHz clock to SPI9
	CLOCK_AttachClk(kFRO12M_to_FLEXCOMM0);
	/* reset FLEXCOMM for SPI
	RESET_PeripheralReset(kFC0_RST_SHIFT_RSTn);
    SPI_MasterGetDefaultConfig(&userConfig);
    srcFreq            = EXAMPLE_SPI_MASTER_CLK_FREQ;
    userConfig.sselNum = (spi_ssel_t)EXAMPLE_SPI_SSEL;
    userConfig.sselPol = (spi_spol_t)EXAMPLE_SPI_SPOL;
    SPI_MasterInit(EXAMPLE_SPI_MASTER, &userConfig, srcFreq);
    status_t status = SPI_MasterSetBaud(EXAMPLE_SPI_MASTER,4000000,EXAMPLE_SPI_MASTER_CLK_FREQ);
    if(status == kStatus_Success){
    	//dispPRINTF("\r\nUSTAWIONO BAUD",label3);
    }else if(status == kStatus_SPI_BaudrateNotSupport){
    	//dispPRINTF("\r\nNie obslugiwany baud",label3);
    }
    for(volatile int i=0;i<100000;i++);
}
*/


static void myConsole();
static void event_handler(lv_obj_t *obj,lv_event_t event) {
	if(event == LV_EVENT_CLICKED){
		lv_textarea_set_text(label3, "");
	}
}

/*
static void reset_button(void) {
  /*Add a button
  lv_obj_t *btn1 = lv_btn_create(lv_scr_act(), NULL);           /*Add to the active screen
  lv_obj_set_event_cb(btn1,event_handler);
  lv_obj_align(btn1,NULL,LV_ALIGN_IN_TOP_RIGHT,0,0);
  //lv_obj_set_pos(btn1, 2, 2);                                    /*Adjust the position
  //lv_obj_set_size(btn1, 96, 30);                                 /* set size of button


  /*Add text
  lv_obj_t *label = lv_label_create(btn1, NULL);                  /*Put on 'btn1'
  lv_label_set_text(label, "Clear");
}

*/



static void myConsole(void) {
    /*Create a Label on the currently active screen*/
    lv_obj_t *titlel =  lv_label_create(lv_scr_act(), NULL);
    lv_obj_t *label2 =  lv_label_create(lv_scr_act(), NULL);
    label3 =  lv_textarea_create(lv_scr_act(), NULL);

    /*Modify the Label's text*/
    lv_label_set_text(titlel, "TERMINAL");
    lv_label_set_text(label2, "-----------------------------------------------------------------------------------------------");
    lv_textarea_set_text(label3, "");
    lv_obj_set_size(label3, 490, 200);


    /* Align the Label to the center
     * NULL means align on parent (which is the screen now)
     * 0, 0 at the end means an x, y offset after alignment*/
    lv_obj_align(titlel, NULL, LV_ALIGN_IN_TOP_LEFT, 205, 0);
    lv_obj_align(label2, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 30);
    lv_obj_align(label3, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 60);

    reset_button();
}


static void scanNetworks(){
	apScan(DATA_Networks);
}





//#define WWW_SERVER "cr.yp.to"

// ============================================================================
// Main
// ============================================================================

void task_sendProductsToThingspeak(void *param){

//	while(!GUI_Initialized){
//		vTaskDelay(200);
//	}

	//DATA_DataChanged = true;
	while(1){
		if(dataUpdateAvailable || shopListChanged){
			if(isConnected() && state == STATE_CONNECTED){
				sendProductsToThinkspeak(shoplist);


			}
			saveDataInFlash();

		}

		vTaskDelay(MSEC_TO_TICK(20000));
		//scanNetworks();
	}
}


void task_main(void *param)
{
	//vTaskSuspend(task_disp_task_handler);
	PRINTF("CREATING WIFI TASK\r\n");
    int32_t result = 0;
    (void)result;

    /* Initialize WIFI shield */
    result = WIFISHIELD_Init();
    PRINTF("CREATING WIFI TASK1\r\n");
    assert(A_OK == result);

    /* Initialize the WIFI driver (thus starting the driver task) */
    result = wlan_driver_start();
    PRINTF("CREATING WIFI TASK2\r\n");
    assert(A_OK == result);
    //vTaskResume(task_disp_task_handler);
    //vTaskDelay( 100 );
    GPIO_PinWrite(GPIO,1,22,1);
    vTaskDelay(MSEC_TO_TICK(500));
    GPIO_PinWrite(GPIO,1,22,0);


    autoConnectWifi();
    //apScan();
    //connectWiFi();
    //apDisconnect();
    //lv_textarea_add_text(label3, "Polaczono!");

    //Configure RTC


    while (1)
    {


    	vTaskDelay(MSEC_TO_TICK(50));

    }
}



static void AppTask(void *param)
{

    lv_port_pre_init();
    lv_init();
    lv_port_disp_init();
    lv_port_indev_init();


    s_lvgl_initialized = true;
    //myConsole();
    //setConsoleLabel(label3);


    GUI_Init();
    GUI_SetProductList(DATA_ProdList, &products_numb);
    GUI_SetDate(&DATA_Date);
    GUI_SetDataChanged(&DATA_DataChanged);
    GUI_SetShopListChanged(&shopListChanged);
    GUI_SetNetworkList(DATA_Networks);

    // WIFI Events
    GUI_SetScanNetworkEvent(scanNetworks);
    GUI_SetConnectNetworkEvent(connectWiF);
    GUI_SetDisconnectNetworkEvent(disconnectWifi);

    shoplist = GUI_GetShopList();
//
    loadDataFromFlashMemory();
    translateList();
    //GUI_Initialized = true;

#if INITIAL_PRODUCTS == 1
    translateList();
    DATA_DataChanged = true;
#endif

    //dispPRINTF("BEFORE LITTLEVGL LOOP\n",label3);
    for (;;)
    {
        lv_task_handler();
        //vTaskSuspend();
    	vTaskDelay(5);
    }
}

static void task_updateTime(void *param){
	while(state != STATE_CONNECTED){
		vTaskDelay(MSEC_TO_TICK(1000));
	}
	char timeBuff[500];
	httpGet(TIME_SERVER,"UnixTime/tounix?date=now",timeBuff);
	uint32_t number;
	int timeBuffLength = strlen(timeBuff);
	char timeTable[30];
	rtc_datetime_t time_date_struct;
	for(int i=0;i<11;i++)
		timeTable[i] = timeBuff[timeBuffLength-10+i];
	number = atoi(timeTable);
	number = number + 3600;
	RTC_SecondToDateTime(number,&time_date_struct);
	RTC_EnableTimer(RTC, false);

	/* Set RTC time to default */
	RTC_SetDatetime(RTC, &time_date_struct);
	/* Start the RTC time counter */
	RTC_EnableTimer(RTC, true);

	while(1){
		DATA_Date = RTC_GetSecondFromRTC(RTC);
		vTaskDelay(MSEC_TO_TICK(1000));
	}

}

static void RFID_Task(void *param){
	//BOARD_InitRC522Module();					//Init RC522 pins
	//RC522_SPI_Config();							//Config SPI for RC522
	startRFID_Module(EXAMPLE_SPI_MASTER,4,7);	//Init RC522, reset

	//dispPRINTF("SKONFIGUROWANO RFID\n",label3);
	while (1)
	{
		//dispPRINTF("SZUKAM PRODUKTU\n");
		if(detectProduct()){
			translateList();
			DATA_DataChanged = true;
			//products_numb = 5;
			//dispPRINTF("WYKRYLEM!\n",label3);


		}else{
			//dispPRINTF("NIE WYKRYLEM..\n",label3);
		}

		vTaskDelay(MSEC_TO_TICK(460));

	}
}
/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * @brief Main function
 */
int main(void)
{
	   BaseType_t stat;



       CLOCK_EnableClock(kCLOCK_InputMux);

       BOARD_InitBootPins();
       BOARD_BootClockPLL220M();
       BOARD_InitBootClocks();
       BOARD_InitSDRAM();
       BOARD_InitPeripherals();
       SYSCON->RTCOSCCTRL |= SYSCON_RTCOSCCTRL_EN_MASK;

       RTC_Init(RTC);

       BOARD_InitQSPI_FLASH();
      // BOARD_InitDebugConsole();
       //xSemaphore = xSemaphoreCreateBinary();


       stat = xTaskCreate(AppTask, "littlevgl", configMINIMAL_STACK_SIZE + 800, NULL, tskIDLE_PRIORITY + 2, NULL);

       if (pdPASS != stat)
       {
    	   PRINTF("Failed to create littlevgl task");
    	   while (1)
    		   ;
       }

       stat =
    		   xTaskCreate(task_main, "main", TASK_MAIN_STACK_SIZE, NULL, tskIDLE_PRIORITY + 2, &task_main_task_handler);
       assert(pdPASS == stat);

       if (pdPASS != stat)
       {
    	   PRINTF("Failed to create wifi task");
    	   while (1)
    		   ;
       }

       stat = xTaskCreate(RFID_Task, "RFID Detector", configMINIMAL_STACK_SIZE + 800, NULL, tskIDLE_PRIORITY + 2, NULL);

       if (pdPASS != stat)
       {
    	   PRINTF("Failed to create RC522 task");
    	   while (1)
    		   ;
       }

       stat = xTaskCreate(task_sendProductsToThingspeak, "Update products in thingspeak", configMINIMAL_STACK_SIZE + 800, NULL, tskIDLE_PRIORITY + 2, NULL);

       if (pdPASS != stat)
       {
    	   PRINTF("Failed to create thingspeak task");
    	   while (1)
    		   ;
       }

       stat = xTaskCreate(task_updateTime, "Update products in thingspeak", configMINIMAL_STACK_SIZE + 800, NULL, tskIDLE_PRIORITY + 2, NULL);

       if (pdPASS != stat)
       {
    	   PRINTF("Failed to create thingspeak task");
    	   while (1)
    		   ;
       }





    vTaskStartScheduler();

    for (;;)
    {
    } /* should never get here */

}

/*!
 * @brief Malloc failed hook.
 */
void vApplicationMallocFailedHook(void)
{
    for (;;)
        ;
}

/*!
 * @brief FreeRTOS tick hook.
 */
void vApplicationTickHook(void)
{

    if (s_lvgl_initialized)
    {
        lv_tick_inc(1);
    }
}

/*!
 * @brief Stack overflow hook.
 */
void vApplicationStackOverflowHook(TaskHandle_t xTask, signed char *pcTaskName)
{
    (void)pcTaskName;
    (void)xTask;

    for (;;)
        ;
}
