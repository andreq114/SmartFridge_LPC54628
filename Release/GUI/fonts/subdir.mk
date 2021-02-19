################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../GUI/fonts/font_pl.c \
../GUI/fonts/font_pl_12.c \
../GUI/fonts/font_pl_16.c \
../GUI/fonts/font_pl_20.c \
../GUI/fonts/font_pl_28.c 

OBJS += \
./GUI/fonts/font_pl.o \
./GUI/fonts/font_pl_12.o \
./GUI/fonts/font_pl_16.o \
./GUI/fonts/font_pl_20.o \
./GUI/fonts/font_pl_28.o 

C_DEPS += \
./GUI/fonts/font_pl.d \
./GUI/fonts/font_pl_12.d \
./GUI/fonts/font_pl_16.d \
./GUI/fonts/font_pl_20.d \
./GUI/fonts/font_pl_28.d 


# Each subdirectory must supply rules for building sources it contributes
GUI/fonts/%.o: ../GUI/fonts/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -DCPU_LPC54628J512ET180=1 -DA_LITTLE_ENDIAN -DCPU_LPC54628J512ET180_cm4 -DCPU_LPC54628 -D__USE_CMSIS -DLV_CONF_INCLUDE_SIMPLE=1 -DLV_EX_CONF_INCLUDE_SIMPLE=1 -DSERIAL_PORT_TYPE_UART=1 -DFSL_RTOS_FREE_RTOS -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -DNDEBUG -D__REDLIB__ -DSDK_OS_FREE_RTOS -I"C:\Users\andre\Documents\MCUXpressoIDE_11.3.0_5222\NTAG\OM13098_Smart_Fridge\utilities" -I"C:\Users\andre\Documents\MCUXpressoIDE_11.3.0_5222\NTAG\OM13098_Smart_Fridge\freertos\freertos_kernel\include" -I"C:\Users\andre\Documents\MCUXpressoIDE_11.3.0_5222\NTAG\OM13098_Smart_Fridge\freertos\freertos_kernel\portable\GCC\ARM_CM4F" -I"C:\Users\andre\Documents\MCUXpressoIDE_11.3.0_5222\NTAG\OM13098_Smart_Fridge\CMSIS" -I"C:\Users\andre\Documents\MCUXpressoIDE_11.3.0_5222\NTAG\OM13098_Smart_Fridge\drivers" -I"C:\Users\andre\Documents\MCUXpressoIDE_11.3.0_5222\NTAG\OM13098_Smart_Fridge\source" -I"C:\Users\andre\Documents\MCUXpressoIDE_11.3.0_5222\NTAG\OM13098_Smart_Fridge\touchpanel" -I"C:\Users\andre\Documents\MCUXpressoIDE_11.3.0_5222\NTAG\OM13098_Smart_Fridge\littlevgl\lvgl" -I"C:\Users\andre\Documents\MCUXpressoIDE_11.3.0_5222\NTAG\OM13098_Smart_Fridge\littlevgl\lvgl\porting" -I"C:\Users\andre\Documents\MCUXpressoIDE_11.3.0_5222\NTAG\OM13098_Smart_Fridge\littlevgl\lvgl\src" -I"C:\Users\andre\Documents\MCUXpressoIDE_11.3.0_5222\NTAG\OM13098_Smart_Fridge\littlevgl\lvgl\src\lv_core" -I"C:\Users\andre\Documents\MCUXpressoIDE_11.3.0_5222\NTAG\OM13098_Smart_Fridge\littlevgl\lvgl\src\lv_draw" -I"C:\Users\andre\Documents\MCUXpressoIDE_11.3.0_5222\NTAG\OM13098_Smart_Fridge\littlevgl\lvgl\src\lv_font" -I"C:\Users\andre\Documents\MCUXpressoIDE_11.3.0_5222\NTAG\OM13098_Smart_Fridge\littlevgl\lvgl\src\lv_gpu" -I"C:\Users\andre\Documents\MCUXpressoIDE_11.3.0_5222\NTAG\OM13098_Smart_Fridge\littlevgl\lvgl\src\lv_hal" -I"C:\Users\andre\Documents\MCUXpressoIDE_11.3.0_5222\NTAG\OM13098_Smart_Fridge\littlevgl\lvgl\src\lv_misc" -I"C:\Users\andre\Documents\MCUXpressoIDE_11.3.0_5222\NTAG\OM13098_Smart_Fridge\littlevgl\lvgl\src\lv_themes" -I"C:\Users\andre\Documents\MCUXpressoIDE_11.3.0_5222\NTAG\OM13098_Smart_Fridge\littlevgl\lvgl\src\lv_widgets" -I"C:\Users\andre\Documents\MCUXpressoIDE_11.3.0_5222\NTAG\OM13098_Smart_Fridge\component\uart" -I"C:\Users\andre\Documents\MCUXpressoIDE_11.3.0_5222\NTAG\OM13098_Smart_Fridge\component\lists" -I"C:\Users\andre\Documents\MCUXpressoIDE_11.3.0_5222\NTAG\OM13098_Smart_Fridge\device" -I"C:\Users\andre\Documents\MCUXpressoIDE_11.3.0_5222\NTAG\OM13098_Smart_Fridge\component\serial_manager" -I"C:\Users\andre\Documents\MCUXpressoIDE_11.3.0_5222\NTAG\OM13098_Smart_Fridge\littlevgl" -I"C:\Users\andre\Documents\MCUXpressoIDE_11.3.0_5222\NTAG\OM13098_Smart_Fridge\board" -I"C:\Users\andre\Documents\MCUXpressoIDE_11.3.0_5222\NTAG\OM13098_Smart_Fridge" -I"C:\Users\andre\Documents\MCUXpressoIDE_11.3.0_5222\NTAG\OM13098_Smart_Fridge\littlevgl\lv_examples\src\lv_demo_widgets" -I"C:\Users\andre\Documents\MCUXpressoIDE_11.3.0_5222\NTAG\OM13098_Smart_Fridge\littlevgl\lv_examples" -I"C:\Users\andre\Documents\MCUXpressoIDE_11.3.0_5222\NTAG\OM13098_Smart_Fridge\wifi_qca\port\boards\lpcxpresso54628\freertos\gt202" -I"C:\Users\andre\Documents\MCUXpressoIDE_11.3.0_5222\NTAG\OM13098_Smart_Fridge\wifi_qca\port\boards\lpcxpresso54628\freertos" -I"C:\Users\andre\Documents\MCUXpressoIDE_11.3.0_5222\NTAG\OM13098_Smart_Fridge\wifi_qca\port\env\freertos" -I"C:\Users\andre\Documents\MCUXpressoIDE_11.3.0_5222\NTAG\OM13098_Smart_Fridge\wifi_qca" -I"C:\Users\andre\Documents\MCUXpressoIDE_11.3.0_5222\NTAG\OM13098_Smart_Fridge\wifi_qca\common_src\hcd" -I"C:\Users\andre\Documents\MCUXpressoIDE_11.3.0_5222\NTAG\OM13098_Smart_Fridge\wifi_qca\common_src\include" -I"C:\Users\andre\Documents\MCUXpressoIDE_11.3.0_5222\NTAG\OM13098_Smart_Fridge\wifi_qca\common_src\stack_common" -I"C:\Users\andre\Documents\MCUXpressoIDE_11.3.0_5222\NTAG\OM13098_Smart_Fridge\wifi_qca\custom_src\include" -I"C:\Users\andre\Documents\MCUXpressoIDE_11.3.0_5222\NTAG\OM13098_Smart_Fridge\wifi_qca\custom_src\stack_custom" -I"C:\Users\andre\Documents\MCUXpressoIDE_11.3.0_5222\NTAG\OM13098_Smart_Fridge\wifi_qca\include\AR6002" -I"C:\Users\andre\Documents\MCUXpressoIDE_11.3.0_5222\NTAG\OM13098_Smart_Fridge\wifi_qca\include\AR6002\hw2.0\hw" -I"C:\Users\andre\Documents\MCUXpressoIDE_11.3.0_5222\NTAG\OM13098_Smart_Fridge\wifi_qca\include\AR6002\hw4.0\hw" -I"C:\Users\andre\Documents\MCUXpressoIDE_11.3.0_5222\NTAG\OM13098_Smart_Fridge\wifi_qca\include" -I"C:\Users\andre\Documents\MCUXpressoIDE_11.3.0_5222\NTAG\OM13098_Smart_Fridge\wifi_qca\port" -I"C:\Users\andre\Documents\MCUXpressoIDE_11.3.0_5222\NTAG\OM13098_Smart_Fridge\wifi_qca\port\drivers\flexcomm_freertos" -I"C:\Users\andre\Documents\MCUXpressoIDE_11.3.0_5222\NTAG\OM13098_Smart_Fridge\wifi_qca\port\boards\lpcxpresso54628\freertos\wifi10click" -I"C:\Users\andre\Documents\MCUXpressoIDE_11.3.0_5222\NTAG\OM13098_Smart_Fridge\wifi_qca\common_src\wmi" -I"C:\Users\andre\Documents\MCUXpressoIDE_11.3.0_5222\NTAG\OM13098_Smart_Fridge\GUI" -I"C:\Users\andre\Documents\MCUXpressoIDE_11.3.0_5222\NTAG\OM13098_Smart_Fridge\GUI\Icons" -I"C:\Users\andre\Documents\MCUXpressoIDE_11.3.0_5222\NTAG\OM13098_Smart_Fridge\GUI\config" -I"C:\Users\andre\Documents\MCUXpressoIDE_11.3.0_5222\NTAG\OM13098_Smart_Fridge\GUI\fonts" -I"C:\Users\andre\Documents\MCUXpressoIDE_11.3.0_5222\NTAG\OM13098_Smart_Fridge\RC522" -I"C:\Users\andre\Documents\MCUXpressoIDE_11.3.0_5222\NTAG\OM13098_Smart_Fridge\GUI\screens" -Os -fno-common -g -Wall -c  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


