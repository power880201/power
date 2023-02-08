/*****************************************************************************
   XCP_App.c
   Generated By:
   Raptor 2021b_2.0.14465 (6183)
   Matlab (R2021b) 9.11

   Copyright (c) 2018 New Eagle Products, Inc.
   All rights reserved.

   Code Generated at: Sun Jan  1 18:42:51 2023
 *****************************************************************************/

#include "A1_Test.h"
#include "A1_Test_private.h"
#include "data.h"
#include "string.h"
#include "time_api.h"

/* S-Function Block: <S3>/raptor_xcp_update */
uint32_T CAN1__XCP_TX_ID_RAM = 768U;
XcpCan_MsgObjId_t g_msgObjId;

#define TIMESUB(A,B)                   ((A >= B) ? (A-B):(0xFFFFFFFF-B+1+A))
#if defined __cplusplus || defined _cplusplus

extern "C" {
  extern void Xcp_CmdProcessor(void);

#endif

  extern void XcpCan_RxCallback(uint32_T, uint8_T, uint8_T*);
  extern void XcpApp_CanTransmit( XcpCan_MsgObjId_t msgObjId, uint32_T msgId,
    uint8_T numBytes, Xcp_StatePtr8 pBytes );
  extern void XCP_TX_CALLBACK_HANDLER(uint8_t busid);

#if defined __cplusplus || defined _cplusplus

}
#endif

void RxTrig_XCP_BC_CAN1(void)
{
  uint32_T id;
  uint8_T length;
  uint16_T age;
  uint8_T extended;
  uint8_T data[8];
  uint32_T id_temp;
  length = can_get_RxTrig_XCP_BC_CAN1(&age, &id, &extended, &data[0], 8);
  id_temp = 0x100;
  if (extended) {
    id_temp |= 0x80000000;
  }

  XcpCan_RxCallback(id_temp, length, &data[0]);
  Xcp_CmdProcessor();
}

void RxTrig_XCP_CMD_CAN1(void)
{
  uint32_T id;
  uint8_T length;
  uint16_T age;
  uint8_T extended;
  uint8_T data[8];
  uint32_T id_temp;
  length = can_get_RxTrig_XCP_CMD_CAN1(&age, &id, &extended, &data[0], 8);
  id_temp = 0x200;
  if (extended) {
    id_temp |= 0x80000000;
  }

  XcpCan_RxCallback(id_temp, length, &data[0]);
  Xcp_CmdProcessor();
}

void XcpApp_CanTransmit( XcpCan_MsgObjId_t msgObjId, uint32_T msgId, uint8_T
  numBytes, Xcp_StatePtr8 pBytes )
{
  /* Tx_XCP_CAN1  ------      */
  uint32_T id = CAN1__XCP_TX_ID_RAM;   //msgId & 0x1fffffff;
  uint8_T length = numBytes;
  uint8_T extended = ((msgId & 0x80000000) > 0);
  uint8_T data[8];
  memcpy(&data[0], pBytes, numBytes);
  can_send_Tx_XCP_CAN1(id, extended, length, &data[0]);
  g_msgObjId = msgObjId;
  g_msgObjId = msgObjId;
}

void XCP_TX_CALLBACK_HANDLER( uint8_t __attribute__((unused))busid )
{
  if (g_msgObjId != XCPCAN_INVALID_MSGOBJID) {
    XcpCan_TxCallback(g_msgObjId);
  }
}

extern void can_init_rxIdRxTrig_XCP_CMD_CAN1(uint32_T, uint8_T);
extern void can_init_rxIdRxTrig_XCP_BC_CAN1(uint32_T, uint8_T);
void CAN1_XCP_CAN_PreStart(uint32_T bc_id, uint32_T rx_id, uint32_T tx_id)
{
  CAN1__XCP_TX_ID_RAM = tx_id;
  XCP_MSG_RX_ID = rx_id;               /* Rx Id Type is Standard */
  can_init_rxIdRxTrig_XCP_BC_CAN1(bc_id, 0);
  can_init_rxIdRxTrig_XCP_CMD_CAN1(rx_id, 0);
  extern void register_xcp_tx_callback_object( E_CAN_CONTROLLER busId, const
    CANTxCallBack callback );
  register_xcp_tx_callback_object( CAN1, (CANTxCallBack)XCP_TX_CALLBACK_HANDLER );
}

void Timed_Trigger_XCP(void)
{
  {
    /* DAQ LIST Rate : 10 ms */
    static uint32_T cnt_daq_10ms = 0;
    if (cnt_daq_10ms >= 2) {
      cnt_daq_10ms = 0;
      Xcp_DoDaqForEvent(0);
    }

    cnt_daq_10ms++;
  }

  {
    /* DAQ LIST Rate : 100 ms */
    static uint32_T cnt_daq_100ms = 1;
    if (cnt_daq_100ms >= 20) {
      cnt_daq_100ms = 0;
      Xcp_DoDaqForEvent(1);
    }

    cnt_daq_100ms++;
  }

  Xcp_CmdProcessor();
}
