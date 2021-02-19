/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

#ifndef _PIN_MUX_H_
#define _PIN_MUX_H_

/*!
 * @addtogroup pin_mux
 * @{
 */

/***********************************************************************************************************************
 * API
 **********************************************************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Calls initialization functions.
 *
 */
void BOARD_InitBootPins(void);

/*!
 * @brief Enables digital function */
#define IOCON_PIO_DIGITAL_EN 0x0100u
/*!
 * @brief Selects pin function 0 */
#define IOCON_PIO_FUNC0 0x00u
/*!
 * @brief Selects pin function 1 */
#define IOCON_PIO_FUNC1 0x01u
/*!
 * @brief Selects pin function 6 */
#define IOCON_PIO_FUNC6 0x06u
/*!
 * @brief High drive: 20 mA */
#define IOCON_PIO_I2CDRIVE_HIGH 0x0400u
/*!
 * @brief I2C 50 ns glitch filter enabled */
#define IOCON_PIO_I2CFILTER_EN 0x00u
/*!
 * @brief I2C mode */
#define IOCON_PIO_I2CSLEW_I2C 0x00u
/*!
 * @brief Input filter disabled */
#define IOCON_PIO_INPFILT_OFF 0x0200u
/*!
 * @brief Input function is not inverted */
#define IOCON_PIO_INV_DI 0x00u
/*!
 * @brief No addition pin function */
#define IOCON_PIO_MODE_INACT 0x00u
/*!
 * @brief Selects pull-up function */
#define IOCON_PIO_MODE_PULLUP 0x20u
/*!
 * @brief Open drain is disabled */
#define IOCON_PIO_OPENDRAIN_DI 0x00u
/*!
 * @brief Fast mode, slew rate control is disabled */
#define IOCON_PIO_SLEW_FAST 0x0400u
/*!
 * @brief Standard mode, output slew rate control is enabled */
#define IOCON_PIO_SLEW_STANDARD 0x00u
/*!
 * @brief Select Analog/Digital mode.: Digital mode. */
#define PIO122_DIGIMODE_DIGITAL 0x01u
/*!
 * @brief Selects pin function.: Alternative connection 0. */
#define PIO122_FUNC_ALT0 0x00u
/*!
 * @brief
 * Selects function mode (on-chip pull-up/pull-down resistor control).
 * : Pull-down.
 * Pull-down resistor enabled.
 */
#define PIO122_MODE_PULL_DOWN 0x01u

/*! @name PIO0_7 (coord H12), U28[D9]/RP5[3]/P0_7-EMC_D5
  @{ */
#define BOARD_INITPINS_EMC_D5_PORT 0U                  /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_EMC_D5_PIN 7U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_EMC_D5_PIN_MASK (1U << 7U)      /*!<@brief PORT pin mask */
                                                       /* @} */

/*! @name PIO0_8 (coord H10), U28[D8]/RP5[2]/P0_8-EMC_D6
  @{ */
#define BOARD_INITPINS_EMC_D6_PORT 0U                  /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_EMC_D6_PIN 8U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_EMC_D6_PIN_MASK (1U << 8U)      /*!<@brief PORT pin mask */
                                                       /* @} */

/*! @name PIO0_9 (coord G12), U28[E9]/RP5[1]/P0_9-EMC_D7
  @{ */
#define BOARD_INITPINS_EMC_D7_PORT 0U                  /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_EMC_D7_PIN 9U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_EMC_D7_PIN_MASK (1U << 9U)      /*!<@brief PORT pin mask */
                                                       /* @} */

/*! @name PIO0_15 (coord L4), U28[F9]/P0_15-EMC_WEn
  @{ */
#define BOARD_INITPINS_EMC_WEn_PORT 0U                   /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_EMC_WEn_PIN 15U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_EMC_WEn_PIN_MASK (1U << 15U)      /*!<@brief PORT pin mask */
                                                         /* @} */

/*! @name PIO0_18 (coord C14), U28[H7]/P0_18-EMC_A0
  @{ */
#define BOARD_INITPINS_EMC_A0_PORT 0U                   /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_EMC_A0_PIN 18U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_EMC_A0_PIN_MASK (1U << 18U)      /*!<@brief PORT pin mask */
                                                        /* @} */

/*! @name PIO0_19 (coord C6), U28[H8]/P0_19-EMC_A1
  @{ */
#define BOARD_INITPINS_EMC_A1_PORT 0U                   /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_EMC_A1_PIN 19U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_EMC_A1_PIN_MASK (1U << 19U)      /*!<@brief PORT pin mask */
                                                        /* @} */

/*! @name PIO0_20 (coord D13), U28[J8]/P0_20-EMC_A2
  @{ */
#define BOARD_INITPINS_EMC_A2_PORT 0U                   /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_EMC_A2_PIN 20U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_EMC_A2_PIN_MASK (1U << 20U)      /*!<@brief PORT pin mask */
                                                        /* @} */

/*! @name PIO0_21 (coord C13), U28[J7]/P0_21-EMC_A3
  @{ */
#define BOARD_INITPINS_EMC_A3_PORT 0U                   /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_EMC_A3_PIN 21U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_EMC_A3_PIN_MASK (1U << 21U)      /*!<@brief PORT pin mask */
                                                        /* @} */

/*! @name PIO1_4 (coord D4), U28[C2]/RP4[1]/P1_4-EMC_D11
  @{ */
#define BOARD_INITPINS_EMC_D11_PORT 1U                  /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_EMC_D11_PIN 4U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_EMC_D11_PIN_MASK (1U << 4U)      /*!<@brief PORT pin mask */
                                                        /* @} */

/*! @name PIO1_5 (coord E4), U28[J3]/P1_5-EMC_A4
  @{ */
#define BOARD_INITPINS_EMC_A4_PORT 1U                  /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_EMC_A4_PIN 5U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_EMC_A4_PIN_MASK (1U << 5U)      /*!<@brief PORT pin mask */
                                                       /* @} */

/*! @name PIO1_6 (coord G4), U28[J2]/P1_6-EMC_A5
  @{ */
#define BOARD_INITPINS_EMC_A5_PORT 1U                  /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_EMC_A5_PIN 6U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_EMC_A5_PIN_MASK (1U << 6U)      /*!<@brief PORT pin mask */
                                                       /* @} */

/*! @name PIO1_7 (coord N1), U28[H3]/P1_7-EMC_A6
  @{ */
#define BOARD_INITPINS_EMC_A6_PORT 1U                  /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_EMC_A6_PIN 7U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_EMC_A6_PIN_MASK (1U << 7U)      /*!<@brief PORT pin mask */
                                                       /* @} */

/*! @name PIO1_8 (coord P8), U28[H2]/P1_8-EMC_A7
  @{ */
#define BOARD_INITPINS_EMC_A7_PORT 1U                  /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_EMC_A7_PIN 8U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_EMC_A7_PIN_MASK (1U << 8U)      /*!<@brief PORT pin mask */
                                                       /* @} */

/*! @name PIO1_9 (coord K6), U28[F7]/P1_9-EMC_CASn
  @{ */
#define BOARD_INITPINS_EMC_CASn_PORT 1U                  /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_EMC_CASn_PIN 9U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_EMC_CASn_PIN_MASK (1U << 9U)      /*!<@brief PORT pin mask */
                                                         /* @} */

/*! @name PIO1_19 (coord L1), U28[E1]/RP4[4]/P1_19-EMC_D8
  @{ */
#define BOARD_INITPINS_EMC_D8_PORT 1U                   /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_EMC_D8_PIN 19U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_EMC_D8_PIN_MASK (1U << 19U)      /*!<@brief PORT pin mask */
                                                        /* @} */

/*! @name PIO1_20 (coord M1), U28[D2]/RP4[3]/P1_20-EMC_D9
  @{ */
#define BOARD_INITPINS_EMC_D9_PORT 1U                   /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_EMC_D9_PIN 20U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_EMC_D9_PIN_MASK (1U << 20U)      /*!<@brief PORT pin mask */
                                                        /* @} */

/*! @name PIO1_21 (coord N8), U28[D1]/RP4[2]/P1_21-EMC_D10
  @{ */
#define BOARD_INITPINS_EMC_D10_PORT 1U                   /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_EMC_D10_PIN 21U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_EMC_D10_PIN_MASK (1U << 21U)      /*!<@brief PORT pin mask */
                                                         /* @} */

/*! @name PIO1_10 (coord N9), U28[F8]/P1_10-EMC_RASn
  @{ */
#define BOARD_INITPINS_EMC_RASn_PORT 1U                   /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_EMC_RASn_PIN 10U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_EMC_RASn_PIN_MASK (1U << 10U)      /*!<@brief PORT pin mask */
                                                          /* @} */

/*! @name PIO1_11 (coord B4), U28[F2]/P1_11-EMC_CLK0
  @{ */
#define BOARD_INITPINS_EMC_CLK0_PORT 1U                   /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_EMC_CLK0_PIN 11U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_EMC_CLK0_PIN_MASK (1U << 11U)      /*!<@brief PORT pin mask */
                                                          /* @} */

/*! @name PIO1_12 (coord K9), U28[G9]/P1_12-EMC_DYCSn0
  @{ */
#define BOARD_INITPINS_EMC_DYCSn0_PORT 1U                   /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_EMC_DYCSn0_PIN 12U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_EMC_DYCSn0_PIN_MASK (1U << 12U)      /*!<@brief PORT pin mask */
                                                            /* @} */

/*! @name PIO1_13 (coord G10), U28[E8]/P1_13-EMC_DQM0
  @{ */
#define BOARD_INITPINS_EMC_DQM0_PORT 1U                   /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_EMC_DQM0_PIN 13U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_EMC_DQM0_PIN_MASK (1U << 13U)      /*!<@brief PORT pin mask */
                                                          /* @} */

/*! @name PIO1_14 (coord C12), U28[F1]/P1_14-EMC_DQM1
  @{ */
#define BOARD_INITPINS_EMC_DQM1_PORT 1U                   /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_EMC_DQM1_PIN 14U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_EMC_DQM1_PIN_MASK (1U << 14U)      /*!<@brief PORT pin mask */
                                                          /* @} */

/*! @name PIO1_15 (coord A11), U28[F3]/P1_15-EMC_CKE0
  @{ */
#define BOARD_INITPINS_EMC_CKE0_PORT 1U                   /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_EMC_CKE0_PIN 15U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_EMC_CKE0_PIN_MASK (1U << 15U)      /*!<@brief PORT pin mask */
                                                          /* @} */

/*! @name PIO1_16 (coord B7), U28[H9]/P1_16-EMC_A10
  @{ */
#define BOARD_INITPINS_EMC_A10_PORT 1U                   /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_EMC_A10_PIN 16U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_EMC_A10_PIN_MASK (1U << 16U)      /*!<@brief PORT pin mask */
                                                         /* @} */

/*! @name PIO1_23 (coord M10), U28[G2]/P1_23-EMC_A11
  @{ */
#define BOARD_INITPINS_EMC_A11_PORT 1U                   /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_EMC_A11_PIN 23U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_EMC_A11_PIN_MASK (1U << 23U)      /*!<@brief PORT pin mask */
                                                         /* @} */

/*! @name PIO1_24 (coord N14), U28[G1]/P1_24-EMC_A12
  @{ */
#define BOARD_INITPINS_EMC_A12_PORT 1U                   /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_EMC_A12_PIN 24U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_EMC_A12_PIN_MASK (1U << 24U)      /*!<@brief PORT pin mask */
                                                         /* @} */

/*! @name PIO1_25 (coord M12), U28[G7]/P1_25-EMC_A13
  @{ */
#define BOARD_INITPINS_EMC_A13_PORT 1U                   /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_EMC_A13_PIN 25U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_EMC_A13_PIN_MASK (1U << 25U)      /*!<@brief PORT pin mask */
                                                         /* @} */

/*! @name PIO1_28 (coord E12), U28[C1]/RP2[4]/P1_28-EMC_D12
  @{ */
#define BOARD_INITPINS_EMC_D12_PORT 1U                   /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_EMC_D12_PIN 28U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_EMC_D12_PIN_MASK (1U << 28U)      /*!<@brief PORT pin mask */
                                                         /* @} */

/*! @name PIO1_29 (coord C11), U28[B2]/RP2[3]/P1_29-EMC_D13
  @{ */
#define BOARD_INITPINS_EMC_D13_PORT 1U                   /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_EMC_D13_PIN 29U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_EMC_D13_PIN_MASK (1U << 29U)      /*!<@brief PORT pin mask */
                                                         /* @} */

/*! @name PIO1_30 (coord A8), U28[B1]/RP2[2]/P1_30-EMC_D14
  @{ */
#define BOARD_INITPINS_EMC_D14_PORT 1U                   /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_EMC_D14_PIN 30U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_EMC_D14_PIN_MASK (1U << 30U)      /*!<@brief PORT pin mask */
                                                         /* @} */

/*! @name PIO1_31 (coord C5), U28[A2]/RP2[1]/P1_31-EMC_D15
  @{ */
#define BOARD_INITPINS_EMC_D15_PORT 1U                   /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_EMC_D15_PIN 31U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_EMC_D15_PIN_MASK (1U << 31U)      /*!<@brief PORT pin mask */
                                                         /* @} */

/*! @name PIO1_26 (coord J10), U28[H1]/P1_26-EMC_A8
  @{ */
#define BOARD_INITPINS_EMC_A8_PORT 1U                   /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_EMC_A8_PIN 26U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_EMC_A8_PIN_MASK (1U << 26U)      /*!<@brief PORT pin mask */
                                                        /* @} */

/*! @name PIO1_27 (coord F10), U28[G3]/P1_27-EMC_A9
  @{ */
#define BOARD_INITPINS_EMC_A9_PORT 1U                   /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_EMC_A9_PIN 27U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_EMC_A9_PIN_MASK (1U << 27U)      /*!<@brief PORT pin mask */
                                                        /* @} */

/*! @name PIO3_25 (coord P9), U28[G8]/P3_25-EMC_A14
  @{ */
#define BOARD_INITPINS_EMC_A14_PORT 3U                   /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_EMC_A14_PIN 25U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_EMC_A14_PIN_MASK (1U << 25U)      /*!<@brief PORT pin mask */
                                                         /* @} */

/*! @name PIO2_11 (coord K3), J16[31]/P2_11-LCD_PWR
  @{ */
#define BOARD_INITPINS_LCD_PWR_PORT 2U                   /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_LCD_PWR_PIN 11U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_LCD_PWR_PIN_MASK (1U << 11U)      /*!<@brief PORT pin mask */
                                                         /* @} */

/*! @name PIO2_13 (coord P7), J16[30]/P2_13-LCD_DCLK
  @{ */
#define BOARD_INITPINS_LCD_DCLK_PORT 2U                   /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_LCD_DCLK_PIN 13U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_LCD_DCLK_PIN_MASK (1U << 13U)      /*!<@brief PORT pin mask */
                                                          /* @} */

/*! @name PIO2_14 (coord L7), J16[33]/P2_14-LCD_FP
  @{ */
#define BOARD_INITPINS_LCD_FP_PORT 2U                   /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_LCD_FP_PIN 14U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_LCD_FP_PIN_MASK (1U << 14U)      /*!<@brief PORT pin mask */
                                                        /* @} */

/*! @name PIO2_15 (coord M8), J16[34]/P2_15-LCD_AC_ENAB_M
  @{ */
#define BOARD_INITPINS_LCD_AC_ENAB_M_PORT 2U                   /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_LCD_AC_ENAB_M_PIN 15U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_LCD_AC_ENAB_M_PIN_MASK (1U << 15U)      /*!<@brief PORT pin mask */
                                                               /* @} */

/*! @name PIO2_16 (coord L8), J16[32]/P2_16-LCD_LP
  @{ */
#define BOARD_INITPINS_LCD_LP_PORT 2U                   /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_LCD_LP_PIN 16U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_LCD_LP_PIN_MASK (1U << 16U)      /*!<@brief PORT pin mask */
                                                        /* @} */

/*! @name PIO2_21 (coord L10), J16[8]/P2_21-LCD_VD3
  @{ */
#define BOARD_INITPINS_LCD_VD3_PORT 2U                   /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_LCD_VD3_PIN 21U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_LCD_VD3_PIN_MASK (1U << 21U)      /*!<@brief PORT pin mask */
                                                         /* @} */

/*! @name PIO2_22 (coord K10), J16[9]/P2_22-LCD_VD4
  @{ */
#define BOARD_INITPINS_LCD_VD4_PORT 2U                   /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_LCD_VD4_PIN 22U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_LCD_VD4_PIN_MASK (1U << 22U)      /*!<@brief PORT pin mask */
                                                         /* @} */

/*! @name PIO2_23 (coord M14), J16[10]/P2_23-LCD_VD5
  @{ */
#define BOARD_INITPINS_LCD_VD5_PORT 2U                   /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_LCD_VD5_PIN 23U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_LCD_VD5_PIN_MASK (1U << 23U)      /*!<@brief PORT pin mask */
                                                         /* @} */

/*! @name PIO2_24 (coord K14), J16[11]/P2_24-LCD_VD6
  @{ */
#define BOARD_INITPINS_LCD_VD6_PORT 2U                   /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_LCD_VD6_PIN 24U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_LCD_VD6_PIN_MASK (1U << 24U)      /*!<@brief PORT pin mask */
                                                         /* @} */

/*! @name PIO2_25 (coord J11), J16[12]/P2_25-LCD_VD7
  @{ */
#define BOARD_INITPINS_LCD_VD7_PORT 2U                   /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_LCD_VD7_PIN 25U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_LCD_VD7_PIN_MASK (1U << 25U)      /*!<@brief PORT pin mask */
                                                         /* @} */

/*! @name PIO2_28 (coord G13), J16[15]/P2_28-LCD_VD10
  @{ */
#define BOARD_INITPINS_LCD_VD10_PORT 2U                   /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_LCD_VD10_PIN 28U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_LCD_VD10_PIN_MASK (1U << 28U)      /*!<@brief PORT pin mask */
                                                          /* @} */

/*! @name PIO2_29 (coord G11), J16[16]/P2_29-LCD_VD11
  @{ */
#define BOARD_INITPINS_LCD_VD11_PORT 2U                   /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_LCD_VD11_PIN 29U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_LCD_VD11_PIN_MASK (1U << 29U)      /*!<@brief PORT pin mask */
                                                          /* @} */

/*! @name PIO2_30 (coord F12), J16[17]/P2_30-LCD_VD12
  @{ */
#define BOARD_INITPINS_LCD_VD12_PORT 2U                   /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_LCD_VD12_PIN 30U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_LCD_VD12_PIN_MASK (1U << 30U)      /*!<@brief PORT pin mask */
                                                          /* @} */

/*! @name PIO2_31 (coord D14), J16[18]/P2_31-LCD_VD13
  @{ */
#define BOARD_INITPINS_LCD_VD13_PORT 2U                   /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_LCD_VD13_PIN 31U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_LCD_VD13_PIN_MASK (1U << 31U)      /*!<@brief PORT pin mask */
                                                          /* @} */

/*! @name PIO3_0 (coord D12), J16[19]/JS36[1]/P3_0-LCD_VD14
  @{ */
#define BOARD_INITPINS_LCD_VD14_PORT 3U                  /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_LCD_VD14_PIN 0U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_LCD_VD14_PIN_MASK (1U << 0U)      /*!<@brief PORT pin mask */
                                                         /* @} */

/*! @name PIO3_1 (coord D11), J16[20]/JS33[1]/P3_1-LCD_VD15
  @{ */
#define BOARD_INITPINS_LCD_VD15_PORT 3U                  /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_LCD_VD15_PIN 1U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_LCD_VD15_PIN_MASK (1U << 1U)      /*!<@brief PORT pin mask */
                                                         /* @} */

/*! @name PIO3_5 (coord B10), J16[24]/P3_5-LCD_VD19
  @{ */
#define BOARD_INITPINS_LCD_VD19_PORT 3U                  /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_LCD_VD19_PIN 5U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_LCD_VD19_PIN_MASK (1U << 5U)      /*!<@brief PORT pin mask */
                                                         /* @} */

/*! @name PIO3_6 (coord C9), J16[25]/P3_6-LCD_VD20
  @{ */
#define BOARD_INITPINS_LCD_VD20_PORT 3U                  /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_LCD_VD20_PIN 6U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_LCD_VD20_PIN_MASK (1U << 6U)      /*!<@brief PORT pin mask */
                                                         /* @} */

/*! @name PIO3_7 (coord B8), J16[26]/P3_7-LCD_VD21
  @{ */
#define BOARD_INITPINS_LCD_VD21_PORT 3U                  /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_LCD_VD21_PIN 7U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_LCD_VD21_PIN_MASK (1U << 7U)      /*!<@brief PORT pin mask */
                                                         /* @} */

/*! @name PIO3_8 (coord A7), J16[27]/P3_8-LCD_VD22
  @{ */
#define BOARD_INITPINS_LCD_VD22_PORT 3U                  /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_LCD_VD22_PIN 8U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_LCD_VD22_PIN_MASK (1U << 8U)      /*!<@brief PORT pin mask */
                                                         /* @} */

/*! @name PIO3_9 (coord C7), J16[28]/P3_9-LCD_VD23
  @{ */
#define BOARD_INITPINS_LCD_VD23_PORT 3U                  /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_LCD_VD23_PIN 9U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_LCD_VD23_PIN_MASK (1U << 9U)      /*!<@brief PORT pin mask */
                                                         /* @} */

/*! @name PIO3_23 (coord C2), J11[10]/J9[3]/U10[3]/J17[5]/U19[10]/P3_23-FC2_SDAX
  @{ */
#define BOARD_INITPINS_FC2_SDAX_PORT 3U                   /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_FC2_SDAX_PIN 23U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_FC2_SDAX_PIN_MASK (1U << 23U)      /*!<@brief PORT pin mask */
                                                          /* @} */

/*! @name PIO3_24 (coord E2), J11[9]/J9[1]/U10[2]/J17[4]/U19[2]/P3_24-FC2_SCLX
  @{ */
#define BOARD_INITPINS_FC2_SCLX_PORT 3U                   /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_FC2_SCLX_PIN 24U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_FC2_SCLX_PIN_MASK (1U << 24U)      /*!<@brief PORT pin mask */
                                                          /* @} */

/*! @name PIO1_22 (coord P11), J13[1]/P1_22-CT2MAT3
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_INITPINS_BUZZ_GPIO GPIO                 /*!<@brief GPIO peripheral base pointer */
#define BOARD_INITPINS_BUZZ_GPIO_PIN_MASK (1U << 22U) /*!<@brief GPIO pin mask */
#define BOARD_INITPINS_BUZZ_PORT 1U                   /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_BUZZ_PIN 22U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_BUZZ_PIN_MASK (1U << 22U)      /*!<@brief PORT pin mask */
                                                      /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPins(void); /* Function assigned for the Cortex-M4F */

/*!
 * @brief Select Analog/Digital mode.: Digital mode. */
#define PIO016_DIGIMODE_DIGITAL 0x01u
/*!
 * @brief Selects pin function.: Alternative connection 0. */
#define PIO016_FUNC_ALT0 0x00u
/*!
 * @brief Select Analog/Digital mode.: Digital mode. */
#define PIO10_DIGIMODE_DIGITAL 0x01u
/*!
 * @brief Selects pin function.: Alternative connection 0. */
#define PIO10_FUNC_ALT0 0x00u
/*!
 * @brief
 * Selects function mode (on-chip pull-up/pull-down resistor control).
 * : Pull-down.
 * Pull-down resistor enabled.
 */
#define PIO10_MODE_PULL_DOWN 0x01u
/*!
 * @brief Select Analog/Digital mode.: Digital mode. */
#define PIO314_DIGIMODE_DIGITAL 0x01u
/*!
 * @brief Selects pin function.: Alternative connection 0. */
#define PIO314_FUNC_ALT0 0x00u
/*!
 * @brief
 * Selects function mode (on-chip pull-up/pull-down resistor control).
 * : Pull-down.
 * Pull-down resistor enabled.
 */
#define PIO314_MODE_PULL_DOWN 0x01u
/*!
 * @brief Select Analog/Digital mode.: Digital mode. */
#define PIO320_DIGIMODE_DIGITAL 0x01u
/*!
 * @brief Selects pin function.: Alternative connection 1. */
#define PIO320_FUNC_ALT1 0x01u
/*!
 * @brief Select Analog/Digital mode.: Digital mode. */
#define PIO321_DIGIMODE_DIGITAL 0x01u
/*!
 * @brief Selects pin function.: Alternative connection 1. */
#define PIO321_FUNC_ALT1 0x01u
/*!
 * @brief Select Analog/Digital mode.: Digital mode. */
#define PIO322_DIGIMODE_DIGITAL 0x01u
/*!
 * @brief Selects pin function.: Alternative connection 1. */
#define PIO322_FUNC_ALT1 0x01u
/*!
 * @brief Select Analog/Digital mode.: Digital mode. */
#define PIO330_DIGIMODE_DIGITAL 0x01u
/*!
 * @brief Selects pin function.: Alternative connection 1. */
#define PIO330_FUNC_ALT1 0x01u

/*! @name PIO3_14 (coord E3), PWRON
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_INITWIFI10CLICKSHIELD_PWRON_GPIO GPIO                 /*!<@brief GPIO peripheral base pointer */
#define BOARD_INITWIFI10CLICKSHIELD_PWRON_GPIO_PIN_MASK (1U << 14U) /*!<@brief GPIO pin mask */
#define BOARD_INITWIFI10CLICKSHIELD_PWRON_PORT 3U                   /*!<@brief PORT peripheral base pointer */
#define BOARD_INITWIFI10CLICKSHIELD_PWRON_PIN 14U                   /*!<@brief PORT pin number */
#define BOARD_INITWIFI10CLICKSHIELD_PWRON_PIN_MASK (1U << 14U)      /*!<@brief PORT pin mask */
                                                                    /* @} */

/*! @name PIO0_16 (coord M4), IRQ
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_INITWIFI10CLICKSHIELD_IRQ_GPIO GPIO                 /*!<@brief GPIO peripheral base pointer */
#define BOARD_INITWIFI10CLICKSHIELD_IRQ_GPIO_PIN_MASK (1U << 16U) /*!<@brief GPIO pin mask */
#define BOARD_INITWIFI10CLICKSHIELD_IRQ_PORT 0U                   /*!<@brief PORT peripheral base pointer */
#define BOARD_INITWIFI10CLICKSHIELD_IRQ_PIN 16U                   /*!<@brief PORT pin number */
#define BOARD_INITWIFI10CLICKSHIELD_IRQ_PIN_MASK (1U << 16U)      /*!<@brief PORT pin mask */
                                                                  /* @} */

/*! @name PIO1_0 (coord N3), KFET
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_INITWIFI10CLICKSHIELD_KFET_GPIO GPIO                /*!<@brief GPIO peripheral base pointer */
#define BOARD_INITWIFI10CLICKSHIELD_KFET_GPIO_PIN_MASK (1U << 0U) /*!<@brief GPIO pin mask */
#define BOARD_INITWIFI10CLICKSHIELD_KFET_PORT 1U                  /*!<@brief PORT peripheral base pointer */
#define BOARD_INITWIFI10CLICKSHIELD_KFET_PIN 0U                   /*!<@brief PORT pin number */
#define BOARD_INITWIFI10CLICKSHIELD_KFET_PIN_MASK (1U << 0U)      /*!<@brief PORT pin mask */
                                                                  /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitWiFi10ClickShield(void); /* Function assigned for the Cortex-M4F */

#define PIO20_DIGIMODE_DIGITAL 0x01u  /*!<@brief Select Analog/Digital mode.: Digital mode. */
#define PIO20_FUNC_ALT2 0x02u         /*!<@brief Selects pin function.: Alternative connection 2. */
#define PIO21_DIGIMODE_DIGITAL 0x01u  /*!<@brief Select Analog/Digital mode.: Digital mode. */
#define PIO21_FUNC_ALT2 0x02u         /*!<@brief Selects pin function.: Alternative connection 2. */
#define PIO311_DIGIMODE_DIGITAL 0x01u /*!<@brief Select Analog/Digital mode.: Digital mode. */
#define PIO311_FUNC_ALT2 0x02u        /*!<@brief Selects pin function.: Alternative connection 2. */
#define PIO45_DIGIMODE_DIGITAL 0x01u  /*!<@brief Select Analog/Digital mode.: Digital mode. */
#define PIO45_FUNC_ALT3 0x03u         /*!<@brief Selects pin function.: Alternative connection 3. */
#define PIO47_DIGIMODE_DIGITAL 0x01u  /*!<@brief Select Analog/Digital mode.: Digital mode. */
#define PIO47_FUNC_ALT0 0x00u         /*!<@brief Selects pin function.: Alternative connection 0. */

/*! @name PIO4_7 (coord A14), P4_7
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_INITRC522MODULE_RESET_GPIO GPIO                /*!<@brief GPIO peripheral base pointer */
#define BOARD_INITRC522MODULE_RESET_GPIO_PIN_MASK (1U << 7U) /*!<@brief GPIO pin mask */
#define BOARD_INITRC522MODULE_RESET_PORT 4U                  /*!<@brief PORT peripheral base pointer */
#define BOARD_INITRC522MODULE_RESET_PIN 7U                   /*!<@brief PORT pin number */
#define BOARD_INITRC522MODULE_RESET_PIN_MASK (1U << 7U)      /*!<@brief PORT pin mask */
                                                             /* @} */

/*! @name PIO3_11 (coord B2), J11[8]/J12[7]/P3_11-MCLK-PMOD2_GPIO
  @{ */
#define BOARD_INITRC522MODULE_MCLK_PORT 3U                   /*!<@brief PORT peripheral base pointer */
#define BOARD_INITRC522MODULE_MCLK_PIN 11U                   /*!<@brief PORT pin number */
#define BOARD_INITRC522MODULE_MCLK_PIN_MASK (1U << 11U)      /*!<@brief PORT pin mask */
                                                             /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitRC522Module(void); /* Function assigned for the Cortex-M4F */

#define PIO023_DIGIMODE_DIGITAL 0x01u /*!<@brief Select Analog/Digital mode.: Digital mode. */
#define PIO023_FUNC_ALT6 0x06u        /*!<@brief Selects pin function.: Alternative connection 6. */
#define PIO024_DIGIMODE_DIGITAL 0x01u /*!<@brief Select Analog/Digital mode.: Digital mode. */
#define PIO024_FUNC_ALT6 0x06u        /*!<@brief Selects pin function.: Alternative connection 6. */
#define PIO025_DIGIMODE_DIGITAL 0x01u /*!<@brief Select Analog/Digital mode.: Digital mode. */
#define PIO025_FUNC_ALT6 0x06u        /*!<@brief Selects pin function.: Alternative connection 6. */
#define PIO026_DIGIMODE_DIGITAL 0x01u /*!<@brief Select Analog/Digital mode.: Digital mode. */
#define PIO026_FUNC_ALT6 0x06u        /*!<@brief Selects pin function.: Alternative connection 6. */
#define PIO027_DIGIMODE_DIGITAL 0x01u /*!<@brief Select Analog/Digital mode.: Digital mode. */
#define PIO027_FUNC_ALT6 0x06u        /*!<@brief Selects pin function.: Alternative connection 6. */
#define PIO028_DIGIMODE_DIGITAL 0x01u /*!<@brief Select Analog/Digital mode.: Digital mode. */
#define PIO028_FUNC_ALT6 0x06u        /*!<@brief Selects pin function.: Alternative connection 6. */

/*! @name PIO0_23 (coord N7), J13[8]/U27[1]/P0_23-SPIFI_CSn-MCLK
  @{ */
#define BOARD_INITSPIFI_SPIFI_CSn_PORT 0U                   /*!<@brief PORT peripheral base pointer */
#define BOARD_INITSPIFI_SPIFI_CSn_PIN 23U                   /*!<@brief PORT pin number */
#define BOARD_INITSPIFI_SPIFI_CSn_PIN_MASK (1U << 23U)      /*!<@brief PORT pin mask */
                                                            /* @} */

/*! @name PIO0_24 (coord M7), J13[6]/U27[5]/P0_24-SPIFI_IO0
  @{ */
#define BOARD_INITSPIFI_SPIFI_IO0_PORT 0U                   /*!<@brief PORT peripheral base pointer */
#define BOARD_INITSPIFI_SPIFI_IO0_PIN 24U                   /*!<@brief PORT pin number */
#define BOARD_INITSPIFI_SPIFI_IO0_PIN_MASK (1U << 24U)      /*!<@brief PORT pin mask */
                                                            /* @} */

/*! @name PIO0_25 (coord K8), J13[4]/U27[2]/P0_25-SPIFI_IO1
  @{ */
#define BOARD_INITSPIFI_SPIFI_IO1_PORT 0U                   /*!<@brief PORT peripheral base pointer */
#define BOARD_INITSPIFI_SPIFI_IO1_PIN 25U                   /*!<@brief PORT pin number */
#define BOARD_INITSPIFI_SPIFI_IO1_PIN_MASK (1U << 25U)      /*!<@brief PORT pin mask */
                                                            /* @} */

/*! @name PIO0_26 (coord M13), J13[2]/U27[6]/P0_26-SPIFI_CLK
  @{ */
#define BOARD_INITSPIFI_SPIFI_CLK_PORT 0U                   /*!<@brief PORT peripheral base pointer */
#define BOARD_INITSPIFI_SPIFI_CLK_PIN 26U                   /*!<@brief PORT pin number */
#define BOARD_INITSPIFI_SPIFI_CLK_PIN_MASK (1U << 26U)      /*!<@brief PORT pin mask */
                                                            /* @} */

/*! @name PIO0_27 (coord L9), J13[12]/U27[7]/P0_27-SPIFI_IO3
  @{ */
#define BOARD_INITSPIFI_SPIFI_IO3_PORT 0U                   /*!<@brief PORT peripheral base pointer */
#define BOARD_INITSPIFI_SPIFI_IO3_PIN 27U                   /*!<@brief PORT pin number */
#define BOARD_INITSPIFI_SPIFI_IO3_PIN_MASK (1U << 27U)      /*!<@brief PORT pin mask */
                                                            /* @} */

/*! @name PIO0_28 (coord M9), J13[10]/U27[3]/P0_28-SPIFI_IO2-USB0_OCURRn
  @{ */
#define BOARD_INITSPIFI_SPIFI_IO2_PORT 0U                   /*!<@brief PORT peripheral base pointer */
#define BOARD_INITSPIFI_SPIFI_IO2_PIN 28U                   /*!<@brief PORT pin number */
#define BOARD_INITSPIFI_SPIFI_IO2_PIN_MASK (1U << 28U)      /*!<@brief PORT pin mask */
                                                            /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitSPIFI(void); /* Function assigned for the Cortex-M4F */

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* _PIN_MUX_H_ */

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
