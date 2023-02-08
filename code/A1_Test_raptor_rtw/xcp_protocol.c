/*****************************************************************************
   xcp_protocol.c
   Generated By:
   Raptor 2021b_2.0.14465 (6183)
   Matlab (R2021b) 9.11

   Copyright (c) 2018 New Eagle Products, Inc.
   All rights reserved.

   Code Generated at: Sun Jan  1 18:42:51 2023
 *****************************************************************************/

#include "rtwtypes.h"
#include "xcp_protocol.h"
#include "A1_Test.h"
#include "A1_Test_private.h"
#ifdef XCP_ENABLE

const uint16_T* Xcp_IdTableRevPtr = &CONSTVariables.IdTableRev;
Xcp_SlaveId_t Xcp_SlaveIds[] = {
  {
    11,
    (Xcp_CfgPtr8)"A1_Test_083",
    (Xcp_CfgPtr8)&CONSTVariables.HardwareType,
    (Xcp_CfgPtr8)EcuAddr_RAM_Ptr(),
    14,
    (Xcp_CfgPtr8)"A1_Test_083_A1",
    15,
    (Xcp_CfgPtr8)&CONSTVariables.CalIdTxt,
    21,
    (Xcp_CfgPtr8)&CONSTVariables.BuildUID,
    (Xcp_CfgPtr8)UDSServerAddr_RAM_Ptr(),
    (Xcp_CfgPtr8)UDSClientAddr_RAM_Ptr(),
  },
};

/******************************************************************************
 *
 * CAN channel structures
 *
 ******************************************************************************/
XcpCan_ChannelCfg_t XcpCan0_ChannelCfg[] = {
  {                                    /* Command channel */
    XCP_CAN_RX_CMD_START,              /* idxStart */
    XCP_CAN_RX_CMD_END,                /* idxEnd */
    XCP0_CAN_RX_MSGID,                 /* msgId */
    XCPCAN_INVALID_MSGOBJID,           /* msgObjId - unused */
  },

  {                                    /* EVENT channel */
    XCP_CAN_TX_EVENT_START,            /* idxStart */
    XCP_CAN_TX_EVENT_END,              /* idxEnd */
    XCP0_CAN_TX_MSGID,                 /* msgId */
    1,                                 /* msgObjId */
  },

  {                                    /* Response channel */
    XCP_CAN_TX_CRM_START,              /* idxStart */
    XCP_CAN_TX_CRM_END,                /* idxEnd */
    XCP0_CAN_TX_MSGID,                 /* msgId */
    1,                                 /* msgObjId */
  },

  {                                    /* DYNDAQ0 channel */
    XCP0_CAN_DYNDAQ0_START,            /* idxStart */
    XCP0_CAN_DYNDAQ0_END,              /* idxEnd   */
    XCP0_CAN_DYNDAQ_MSGID,             /* Default msgId    */
    1,                                 /* msgObjId */
  },

  {                                    /* DYNDAQ1 channel */
    XCP0_CAN_DYNDAQ1_START,            /* idxStart */
    XCP0_CAN_DYNDAQ1_END,              /* idxEnd   */
    XCP0_CAN_DYNDAQ_MSGID,             /* Default msgId    */
    1,                                 /* msgObjId */
  },
};

/******************************************************************************
 *
 * CAN queue structures
 *
 ******************************************************************************/
XcpCan_QueuePos_t XcpCan0_QueuePositions [ XCP0_CAN_NUM_CHANNELS ];
XcpCan_QueueBuf_t XcpCan0_QueueBuffers [ XCP0_CAN_QUEUEALL_NUMBUF ];

/* Each element has values from XcpCan_QueueBufStates_t. If an element contains XCP_TXNOTSENT or XCP_TXINPROGRESS,
 * the upper nibble will also contain the number of bytes currently used in the corresponding buffer. */
XcpCan_QueueBufProps_t XcpCan0_QueueBufferStates [ XCP0_CAN_QUEUEALL_NUMBUF ];
XcpCan_DynDaqMsgId_t XcpCan0_DynDaqMsgIds [ XCP0_NUM_DYN_DAQ ];

/******************************************************************************
 *
 * CAN session structures
 *
 ******************************************************************************/
XCP_STATE_TYPE uint8_T XcpCan_TxPendingOnMsgObj [ XCP_CAN_MAX_TXMSGOBJID + 1 ];
XcpCan_Session_t XcpCan0_Session;
XcpCan_SessionCfg_t XcpCan0_SessionCfg = {
  XcpCan0_ChannelCfg,                  /* pChannelCfgs */
  XcpCan0_QueuePositions,              /* pQueuePositions */
  XcpCan0_QueueBuffers,                /* pQueueBuffers */
  XcpCan0_QueueBufferStates,           /* pQueueBufferStates */
  XcpCan0_DynDaqMsgIds,                /* pDynDaqMsgIds */
  XCP0_CAN_BROADCAST_MSGID,            /* broadcastMsgId */
  XCP0_CAN_NUM_CHANNELS,               /* numChannels */
  XCP0_CAN_NUM_CHANNELS,               /* firstRxStimChannel */
  5,                                   /* lastTxChannel */
};

/******************************************************************************
 *
 * SEGMENT and PAGE data structures
 *
 ******************************************************************************/
Xcp_PageConfig_t Xcp0_PageConfigs0[] = { { 0 }, { 1 } };
        // the second entry here is to allow CM0711 to build with a bad LCF file

Xcp_PageConfig_t Xcp0_PageConfigs1[] = { { 1 }, { 1 } };

Xcp_SegConfig_t Xcp0_SegConfigs[] = { { Xcp0_PageConfigs0, 1 }, {
    Xcp0_PageConfigs1, 2 } };

Xcp_SegState_t Xcp0_SegStates[ 2 ];

/******************************************************************************
 *
 * DAQ data structures
 *
 ******************************************************************************/
Xcp_OdtEntryAddr_t Xcp0_OdtEntryAddrs[ XCP0_ODT_LIST_SIZE ];
Xcp_OdtEntryCfg_t Xcp0_OdtEntryCfgs[ XCP0_ODT_LIST_SIZE ];
Xcp_Daq_t Xcp0_DaqStates[ XCP0_NUM_ALL_DAQ ];
uint8_T odtEntryNums[XCP0_NUM_DYN_DAQ][ XCP_MAX_ODT_ENTRIES_DYNDAQ ];
Xcp_DaqDynConfig_t Xcp0_DaqDynConfigs[ XCP0_NUM_DYN_DAQ ]= {
  { 0, &odtEntryNums[0][0] },

  { 0, &odtEntryNums[1][0] },
};

Xcp_DaqConfig_t Xcp0_DaqConfigs[XCP0_NUM_ALL_DAQ] = {
  {                                    /* DYNDAQ0 */
    XCP0_FIRST_PID_DYNDAQ0,            /* firstPid */
    XCP0_NUM_ODT_DYNDAQ,               /* numOdt - Max ODT per DAQ list */
    XCP0_DYNDAQ0_START,                /* idxDaqStart */
    XCP0_NUM_ODT_ENTRIES_DYNDAQ,       /* numOdtEntries */
    XCP_DAQLISTPROPERTY_DAQ,           /* properties */
    0                                  /* defaultEvent */
  },

  {                                    /* DYNDAQ1 */
    XCP0_FIRST_PID_DYNDAQ1,            /* firstPid */
    XCP0_NUM_ODT_DYNDAQ,               /* numOdt - Max ODT per DAQ list */
    XCP0_DYNDAQ1_START,                /* idxDaqStart */
    XCP0_NUM_ODT_ENTRIES_DYNDAQ,       /* numOdtEntries */
    XCP_DAQLISTPROPERTY_DAQ,           /* properties */
    0                                  /* defaultEvent */
  },
};

/******************************************************************************
 *
 * Session data structures
 *
 ******************************************************************************/
Xcp_SessionConfig_t Xcp_SessionConfigs[] = {
  {
    &XcpCan0_SessionCfg,               /* pTransportCfg */
    &XcpCan0_Session,                  /* pTransport */
    XcpCan_GetTxBuf,                   /* pGetTxBuf */
    XcpCan_GetRxBuf,                   /* pGetRxBuf */

#ifdef XCP_ENABLE_STIM

    XcpCan_PeekRxBuf,                  /* pPeekRxBuf */

#endif

    XcpCan_TxNext,                     /* pTxNext */
    XcpCan_RxNext,                     /* pRxNext */
    XcpCan_CmdProc,                    /* pCmdProc */

#ifdef XCP_ENABLE_RESUME

    XcpCan_PrepareResume,              /* pPrepareResume */
    XcpCan_DoResume,                   /* pDoResume */

#endif

    XcpCan_ResetDaqList,               /* pResetDaqList */
    Xcp0_OdtEntryAddrs,                /* pOdtEntryAddrs */
    Xcp0_OdtEntryCfgs,                 /* pOdtEntryCfgs */
    Xcp0_DaqConfigs,                   /* pDaqConfigs */

#ifdef XCP_ENABLE_DYNDAQ

    Xcp0_DaqDynConfigs,                /* pDaqDynConfigs */

#endif

    Xcp0_DaqStates,                    /* pDaqStates */
    XCP0_NUM_STATIC_DAQ,               /* numStatDaqLists */
    XCP0_NUM_DYN_DAQ,                  /* maxDynDaqLists */
    XCP0_ODT_LIST_SIZE,                /* totOdtEntries */
    XCP0_MAXDTO,                       /* maxDtoLen */
    XCP0_MAXCTO,                       /* maxCtoLen */
    XCP_RESOURCE_CAL_PAG | XCP_RESOURCE_STIM | XCP_RESOURCE_PGM |
    XCP_RESOURCE_DAQ,                  /* defResourceProtection */
    100 / XCP_POLL_INTERVAL,           /* eventPendingTimeout */
    4,                                 /* numBytesTimestamp */
    8,                                 /* maxOdtEntryLen */

#ifdef XCP_ENABLE_CALPAG

    2,                                 /* numSegs */
    Xcp0_SegConfigs,                   /* pSegConfigs */
    Xcp0_SegStates,                    /* pSegStates */

#endif

#ifdef XCP_ENABLE_RESUME

    XCP0_NV_START_IDX,                 /* nvStartIdx */

#endif

    XCP_CAN                            /* transportLayerId */
  },
};

#if defined __cplusplus || defined _cplusplus

extern "C" {

#endif

  extern Xcp_Session_t Xcp_Sessions[ XCP_NUM_SESSIONS ];
  extern const uint8_T XCP_NUM_EVENTS;
  extern uint32_T XCP_MSG_RX_ID;

#ifdef XCP_ENABLE_SEEDNKEY

  extern const uint16_T *XcpProjectIdPtr;
  extern const uint32_T XcpPGMSecret;
  extern const uint32_T XcpSTIMSecret;
  extern const uint32_T XcpDAQSecret;
  extern const uint32_T XcpCALSecret;
  extern XCPSecurityFn XcpCustSecurity;

#endif

#if defined __cplusplus || defined _cplusplus

}
#endif

Xcp_Session_t Xcp_Sessions[ XCP_NUM_SESSIONS ];
const uint8_T XCP_NUM_EVENTS = 2;
uint32_T XCP_MSG_RX_ID = 0;

#ifdef XCP_ENABLE_SEEDNKEY

const uint16_T *XcpProjectIdPtr = CAN1__XCP_Security_Ptr();
const uint32_T XcpPGMSecret = 0;
const uint32_T XcpSTIMSecret = 0;
const uint32_T XcpDAQSecret = 0;
const uint32_T XcpCALSecret = 0;
XCPSecurityFn XcpCustSecurity = 0;

#endif
#endif                                 /* XCP_ENABLE */
