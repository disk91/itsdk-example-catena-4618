/**
  ******************************************************************************
  * File Name          : gpio.c
  * Description        : This file provides code for the configuration
  *                      of all used GPIO pins.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"
/* USER CODE BEGIN 0 */
#include <it_sdk/config.h>
#include <it_sdk/wrappers.h>
/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/** Configure pins as
        * Analog
        * Input
        * Output
        * EVENT_OUT
        * EXTI
        * Free pins are configured automatically as Analog (this feature is enabled through
        * the Code Generation settings)
     PA2   ------> USART2_TX
     PA3   ------> USART2_RX
*/
void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(PA15_RESERVED_GPIO_Port, PA15_RESERVED_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5|GPIO_PIN_7|GPIO_PIN_2, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, PA12_RESERVED_Pin|GPIO_PIN_8|PA1_RESERVED_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, PC1_RESERVED_Pin|PC0_RESERVED_Pin|PC2_RESERVED_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = PA15_RESERVED_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  HAL_GPIO_Init(PA15_RESERVED_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PB5 PB7 PB2 */
  GPIO_InitStruct.Pin = GPIO_PIN_5|GPIO_PIN_7|GPIO_PIN_2;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PB9 PB6 PB8 PB15
                           PB14 PB13 PB11 PB12
                           PB10 */
  GPIO_InitStruct.Pin = GPIO_PIN_9|GPIO_PIN_6|GPIO_PIN_8|GPIO_PIN_15
                          |GPIO_PIN_14|GPIO_PIN_13|GPIO_PIN_11|GPIO_PIN_12
                          |GPIO_PIN_10;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PAPin PAPin */
  GPIO_InitStruct.Pin = PA12_RESERVED_Pin|PA1_RESERVED_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PBPin PBPin PBPin */
  GPIO_InitStruct.Pin = PB4_RESERVED_Pin|PB1_RESERVED_Pin|PB0_RESERVED_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = PC13_RESERVED_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(PC13_RESERVED_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PCPin PCPin PCPin */
  GPIO_InitStruct.Pin = PC1_RESERVED_Pin|PC0_RESERVED_Pin|PC2_RESERVED_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : PA8 */
  GPIO_InitStruct.Pin = GPIO_PIN_8;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PA11 PA0 PA4 */
  GPIO_InitStruct.Pin = GPIO_PIN_11|GPIO_PIN_0|GPIO_PIN_4;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PAPin PAPin */
  GPIO_InitStruct.Pin = STLINK_RX_Pin|STLINK_TX_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF4_USART2;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : PA5 */
  GPIO_InitStruct.Pin = GPIO_PIN_5;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI0_1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI0_1_IRQn);

  HAL_NVIC_SetPriority(EXTI4_15_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI4_15_IRQn);

}

/* USER CODE BEGIN 2 */
void stm32l_lowPowerRestoreGpioConfig() {

	  /* GPIO Ports Clock Enable */
	  __HAL_RCC_GPIOA_CLK_ENABLE();
	  __HAL_RCC_GPIOB_CLK_ENABLE();
	  __HAL_RCC_GPIOC_CLK_ENABLE();
	  __HAL_RCC_GPIOH_CLK_ENABLE();

	  // RF sw
	  gpio_configure_ext(ITSDK_MURATA_ANTSW_RX_BANK,ITSDK_MURATA_ANTSW_RX_PIN,GPIO_OUTPUT_PP,ITSDK_GPIO_SPEED_HIGH,ITSDK_GPIO_ALT_NONE);

	  // LoRa NSS
	  gpio_configure_ext(ITSDK_SX1276_NSS_BANK,ITSDK_SX1276_NSS_PIN,GPIO_OUTPUT_PULLUP,ITSDK_GPIO_SPEED_HIGH,ITSDK_GPIO_ALT_NONE);

	  // LoRa TCXO
	  gpio_configure_ext(ITSDK_SX1276_TCXO_VCC_BANK,ITSDK_SX1276_TCXO_VCC_PIN,GPIO_OUTPUT_PP,ITSDK_GPIO_SPEED_LOW,ITSDK_GPIO_ALT_NONE);

	  // LoRa DIO0-1-2-3-4
	  gpio_configure_ext(ITSDK_SX1276_DIO_0_BANK,ITSDK_SX1276_DIO_0_PIN,GPIO_INTERRUPT_RISING,ITSDK_GPIO_SPEED_HIGH,ITSDK_GPIO_ALT_NONE);
	  gpio_configure_ext(ITSDK_SX1276_DIO_1_BANK,ITSDK_SX1276_DIO_1_PIN,GPIO_INTERRUPT_RISING,ITSDK_GPIO_SPEED_HIGH,ITSDK_GPIO_ALT_NONE);
	  gpio_configure_ext(ITSDK_SX1276_DIO_2_BANK,ITSDK_SX1276_DIO_2_PIN,GPIO_INTERRUPT_RISING,ITSDK_GPIO_SPEED_HIGH,ITSDK_GPIO_ALT_NONE);
	  gpio_configure_ext(ITSDK_SX1276_DIO_3_BANK,ITSDK_SX1276_DIO_3_PIN,GPIO_INTERRUPT_RISING,ITSDK_GPIO_SPEED_HIGH,ITSDK_GPIO_ALT_NONE);
	  gpio_configure_ext(ITSDK_SX1276_DIO_4_BANK,ITSDK_SX1276_DIO_4_PIN,GPIO_INTERRUPT_RISING,ITSDK_GPIO_SPEED_HIGH,ITSDK_GPIO_ALT_NONE);


	  /* EXTI interrupt init*/
	  HAL_NVIC_SetPriority(EXTI0_1_IRQn, 0, 0);
	  HAL_NVIC_EnableIRQ(EXTI0_1_IRQn);

	  HAL_NVIC_SetPriority(EXTI4_15_IRQn, 0, 0);
	  HAL_NVIC_EnableIRQ(EXTI4_15_IRQn);

}
/* USER CODE END 2 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
