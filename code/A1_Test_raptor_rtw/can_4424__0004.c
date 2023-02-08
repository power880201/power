/*****************************************************************************
   can_4424__0004.c
   Generated By:
   Raptor 2021b_2.0.14465 (6183)
   Matlab (R2021b) 9.11

   Copyright (c) 2018 New Eagle Products, Inc.
   All rights reserved.

   Code Generated at: Sun Jan  1 18:42:51 2023
 *****************************************************************************/

/* CAN interface: CAN2 */
/*   HW Resource: CAN2 */
#include "A1_Test.h"
#include "can_4424__0004.h"
#include "sdk_can.h"
#define MAX_AGE                        65535

int started_4424__0004 = 0;
const uint32_T CAN_CAN2_baud_rate = 500000;
uint32_T CAN_CAN2_get_baud_rate(void)
{
  return(CAN_CAN2_baud_rate);
}

/* Message Receive data storage */
/* Block: UDS_Boot_receive_CAN2 */
void rxFn_uds_boot_receive_CAN2(unsigned int id, uint8_T len, uint8_T* data);
uint8_T rxBuf_uds_boot_receive_CAN2[1][8];
uint8_T rxLen_uds_boot_receive_CAN2[1];
uint16_T rxAge_uds_boot_receive_CAN2;
uint32_T rxID_uds_boot_receive_CAN2[1];
uint8_T rxQHead_uds_boot_receive_CAN2 = 0;
uint8_T rxQTail_uds_boot_receive_CAN2 = 0;

/* Transmit CAN Object Declarations */
/* UDS_send_CAN2 */
uint8_T txData_uds_send_CAN2[1][8];
uint32_T txID_uds_send_CAN2[1];
uint8_T txExt_uds_send_CAN2[1];
uint8_T txLen_uds_send_CAN2[1];
uint8_T txQHead_uds_send_CAN2 = 0;
uint8_T txQTail_uds_send_CAN2 = 0;

/* Functions */
void pre_start_CAN_4424__0004(void)
{
}                                      // end pre_start_CAN_4424__0004

void rxFn_uds_boot_receive_CAN2(unsigned int id, uint8_T length, uint8_T* data)
{
  uint8_T i;
  uint8_T* b = data;
  if (1 ) {
    for (i = 0; i < length; i++) {
      rxBuf_uds_boot_receive_CAN2[rxQHead_uds_boot_receive_CAN2][i] = b[i];
    }

    rxLen_uds_boot_receive_CAN2[rxQHead_uds_boot_receive_CAN2] = length;
    rxID_uds_boot_receive_CAN2[rxQHead_uds_boot_receive_CAN2] = id;
    if ((rxQHead_uds_boot_receive_CAN2 == rxQTail_uds_boot_receive_CAN2) &&
        (rxAge_uds_boot_receive_CAN2 == 0))
      rxQTail_uds_boot_receive_CAN2 = (rxQTail_uds_boot_receive_CAN2 + 1) % 1;
    if ((rxQHead_uds_boot_receive_CAN2 == (rxQTail_uds_boot_receive_CAN2 + 1)% 1)
        && (rxAge_uds_boot_receive_CAN2 != 0))
      rxQTail_uds_boot_receive_CAN2 = (rxQTail_uds_boot_receive_CAN2 + 1) % 1;
    rxQHead_uds_boot_receive_CAN2 = (rxQHead_uds_boot_receive_CAN2 + 1 ) % 1;
    rxAge_uds_boot_receive_CAN2 = 0;

    {
      extern void uds_boot_request_trigger_CAN2();
      uds_boot_request_trigger_CAN2();
    }
  }
}

uint8_T can_get_uds_boot_receive_CAN2(uint16_T *age, uint32_T* id, uint8_T
  * extended, uint8_T *data, uint8_T length)
{
  uint8_T i;
  if (age != NULL)
    *age = rxAge_uds_boot_receive_CAN2;
  if (id != NULL)
    *id = rxID_uds_boot_receive_CAN2[rxQTail_uds_boot_receive_CAN2];
  if (extended != NULL)
    *extended = 0;
  if (length > 8)
    length = 8;
  if (length > rxLen_uds_boot_receive_CAN2[rxQTail_uds_boot_receive_CAN2])
    length = rxLen_uds_boot_receive_CAN2[rxQTail_uds_boot_receive_CAN2];
  if (data != NULL)
    for (i = 0; i < length; i++)
      data[i] = rxBuf_uds_boot_receive_CAN2[rxQTail_uds_boot_receive_CAN2][i];
  if ((rxQHead_uds_boot_receive_CAN2 != (rxQTail_uds_boot_receive_CAN2 + 1)% 1) &&
      (rxAge_uds_boot_receive_CAN2 == 0))
    rxQTail_uds_boot_receive_CAN2 = (rxQTail_uds_boot_receive_CAN2 + 1) % 1;
  else if (rxAge_uds_boot_receive_CAN2 < MAX_AGE)
    rxAge_uds_boot_receive_CAN2++;
  return length;
}

void can_send_uds_send_CAN2(uint32_T id, uint8_T extended, uint8_T length, const
  uint8_T *data)
{
  if (!started_4424__0004) {
    pre_start_CAN_4424__0004();
  }

  send_can_message(CAN2, extended, id, data, length);
}

void can_update_uds_send_CAN2(uint32_T id, uint8_T extended, uint8_T length,
  const uint8_T *data)
{
}

uint32_T can_set_period_uds_send_CAN2(uint32_T period)
{
  if (period > 65535)
    period = 65535;
  return period;
}

void CAN_ReceiveDispatch_4424__0004(boolean extended, uint32_t id, uint8_t *
  data, uint8_t data_len)
{
  if (extended == 0) {
    if ((id & 0x1FFFFFFF) == (UDSServerAddr_RAM_Data() & 0x1FFFFFFF) ) {
      rxFn_uds_boot_receive_CAN2(id, data_len, data);
    }
  }
}

void post_start_CAN_4424__0004(void)
{
  if (started_4424__0004) {
    return;
  }

  started_4424__0004 = 1;
  start_CAN(CAN2, CAN_CAN2_baud_rate );
  register_receive_all_object( CAN2, CAN_ReceiveDispatch_4424__0004 );
}                                      // end post_start_CAN_4424__0004
