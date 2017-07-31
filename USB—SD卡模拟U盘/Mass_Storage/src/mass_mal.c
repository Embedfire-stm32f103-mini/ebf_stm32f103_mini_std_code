/**
  ******************************************************************************
  * @file    mass_mal.c
  * @author  MCD Application Team
  * @version V3.4.0
  * @date    29-June-2012
  * @brief   Medium Access Layer interface
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2012 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */


/* Includes ------------------------------------------------------------------*/


#include "./sdcard/bsp_spi_sdcard.h"
#include "mass_mal.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
uint32_t Mass_Memory_Size[2];
uint32_t Mass_Block_Size[2];
uint32_t Mass_Block_Count[2];
__IO uint32_t Status = 0;

//SD_CardInfo mSDCardInfo;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/*******************************************************************************
* Function Name  : MAL_Init
* Description    : Initializes the Media on the STM32
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
uint16_t MAL_Init(uint8_t lun)
{
  uint16_t status = MAL_OK;

  switch (lun)
  {
    case 0:
      Status = SD_Init();
      break;
//    case 1:
//      NAND_Init();
//      break;
    default:
      return MAL_FAIL;
  }
  return status;
}
/*******************************************************************************
* Function Name  : MAL_Write
* Description    : Write sectors
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
uint16_t MAL_Write(uint8_t lun, uint32_t Memory_Offset, uint32_t *Writebuff, uint16_t Transfer_Length)
{

  switch (lun)
  {
    case 0:
   // Status = SD_WriteMultiBlocks((uint8_t*)Writebuff, Memory_Offset, Transfer_Length,1);
   Status =	SD_WriteBlock((uint8_t*)Writebuff, Memory_Offset, Transfer_Length);
//    Status = SD_WaitWriteOperation();  
//    while(SD_GetStatus() != SD_TRANSFER_OK);
      if ( Status != SD_RESPONSE_NO_ERROR )
      {
        return MAL_FAIL;
      }      
      break;
//    case 1:
//      NAND_Write(Memory_Offset, Writebuff, Transfer_Length);
//      break;
    default:
      return MAL_FAIL;
  }
  return MAL_OK;
}

/*******************************************************************************
* Function Name  : MAL_Read
* Description    : Read sectors
* Input          : None
* Output         : None
* Return         : Buffer pointer
*******************************************************************************/
uint16_t MAL_Read(uint8_t lun, uint32_t Memory_Offset, uint32_t *Readbuff, uint16_t Transfer_Length)
{

  switch (lun)
  {
    case 0:

     // SD_ReadMultiBlocks((uint8_t*)Readbuff, Memory_Offset, Transfer_Length, 1);
      SD_ReadBlock((uint8_t*)Readbuff, Memory_Offset, Transfer_Length);
//	  Status = SD_WaitReadOperation();
//      while(SD_GetStatus() != SD_TRANSFER_OK)
//      {
//      }
//    Status = SD_WaitWriteOperation();
//    while(SD_GetStatus() != SD_TRANSFER_OK);
      
      if ( Status != SD_RESPONSE_NO_ERROR )
      {
        return MAL_FAIL;
      }
      break;
//    case 1:
//      NAND_Read(Memory_Offset, Readbuff, Transfer_Length);
//      ;
//      break;
    default:
      return MAL_FAIL;
  }
  return MAL_OK;
}

/*******************************************************************************
* Function Name  : MAL_GetStatus
* Description    : Get status
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
uint16_t MAL_GetStatus (uint8_t lun)
{
//  NAND_IDTypeDef NAND_ID;

  if (lun == 0)
  {
    if (SD_Init() == SD_RESPONSE_NO_ERROR)
    {
      SD_GetCardInfo(&SDCardInfo);

      if ( Status != SD_RESPONSE_NO_ERROR )
      {
        return MAL_FAIL;
      }	      

			Mass_Memory_Size[0] = SDCardInfo.CardCapacity;  
			Mass_Block_Size[0]  = SDCardInfo.CardBlockSize;

			Mass_Block_Count[0] = SDCardInfo.CardCapacity/Mass_Block_Size[0];

      return MAL_OK;

    }
  }
//  else
//  {
//    FSMC_NAND_ReadID(&NAND_ID);
//    if (NAND_ID.Device_ID != 0 )
//    {
//      /* only one zone is used */
//      Mass_Block_Count[1] = NAND_ZONE_SIZE * NAND_BLOCK_SIZE * NAND_MAX_ZONE ;
//      Mass_Block_Size[1]  = NAND_PAGE_SIZE;
//      Mass_Memory_Size[1] = (Mass_Block_Count[1] * Mass_Block_Size[1]);
//      return MAL_OK;
//    }
//  }
  return MAL_FAIL;
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

