/* SPDX-License-Identifier: GPL-2.0-only */
/* Atlantic Network Driver
 * Copyright (C) 2020 Marvell International Ltd.
 */

/* File hw_atl2_internal.h: Definition of Atlantic2 chip specific
 * constants.
 */

#ifndef HW_ATL2_INTERNAL_H
#define HW_ATL2_INTERNAL_H

#include "aq_common.h"

#define HW_ATL2_MTU_JUMBO  16352U
#define HW_ATL2_MTU        1514U

#define HW_ATL2_TX_RINGS 4U
#define HW_ATL2_RX_RINGS 4U

#define HW_ATL2_RINGS_MAX 32U
#define HW_ATL2_TXD_SIZE       (16U)
#define HW_ATL2_RXD_SIZE       (16U)

#define HW_ATL2_MAC_UC   0U
#define HW_ATL2_MAC_MIN  1U
#define HW_ATL2_MAC_MAX  38U

/* UCAST/MCAST filters */
#define HW_ATL2_UCAST_FILTERS_MAX 38

/* interrupts */
#define HW_ATL2_ERR_INT 8U
#define HW_ATL2_INT_MASK  (0xFFFFFFFFU)

#define HW_ATL2_TXD_CTL_DESC_TYPE_TXTS  (0x00000003)
#define HW_ATL2_TXD_CTL_TS_EN       (0x40000000)
#define HW_ATL2_TXD_CTL_TS_TSG0      (0x80000000)

#define HW_ATL2_TXBUF_MAX              128U
#define HW_ATL2_PTP_TXBUF_SIZE           8U

#define HW_ATL2_RXBUF_MAX              172U
#define HW_ATL2_PTP_RXBUF_SIZE          16U

#define HW_ATL2_PTP_FTC_RING_IDX        16U

#ifdef TSN_SUPPORT
#define HW_ATL2_AVB0_TXBUF_SIZE         20U
#define HW_ATL2_AVB0_RXBUF_SIZE         30U
#define HW_ATL2_AVB1_TXBUF_SIZE         20U
#define HW_ATL2_AVB1_RXBUF_SIZE         30U

#define HW_ATL2_AVB0_4TC_RING_IDX        8U
#define HW_ATL2_AVB0_8TC_RING_IDX        4U
#define HW_ATL2_AVB0_FTC_RING_IDX       17U

#define HW_ATL2_AVB1_4TC_RING_IDX       24U
#define HW_ATL2_AVB1_8TC_RING_IDX       12U
#define HW_ATL2_AVB1_FTC_RING_IDX       18U
#endif

#define HW_ATL2_RSS_REDIRECTION_MAX 64U

#define HW_ATL2_TCRSS_4_8  1
#define HW_ATL2_TC_MAX 8U
#define HW_ATL2_RSS_MAX 8U

#define HW_ATL2_RS_SLIP_ENABLED  0U

/* (256k -1(max pay_len) - 54(header)) */
#define HAL_ATL2_LSO_MAX_SEGMENT_SIZE 262089U

/* (256k -1(max pay_len) - 74(header)) */
#define HAL_ATL2_LSO_IPV6_MAX_SEGMENT_SIZE 262069U

#define HW_ATL2_RXD_WB_PKTTYPE_VLAN		(1 << 5)
#define HW_ATL2_RXD_WB_PKTTYPE_VLAN_DOUBLE	(1 << 6)

#define HW_ATL2_INTR_MODER_MAX  0x1FF
#define HW_ATL2_INTR_MODER_MIN  0xFF

#define HW_ATL2_MIN_RXD \
	(ALIGN(AQ_CFG_SKB_FRAGS_MAX + 1U, AQ_HW_RXD_MULTIPLE))
#define HW_ATL2_MIN_TXD \
	(ALIGN(AQ_CFG_SKB_FRAGS_MAX + 1U, AQ_HW_TXD_MULTIPLE))

#define HW_ATL2_MAX_RXD 8184U
#define HW_ATL2_MAX_TXD 8184U

#define HW_ATL2_FW_SM_ACT_RSLVR  0x3U

#define HW_ATL2_RPF_TAG_UC_OFFSET      0x0
#define HW_ATL2_RPF_TAG_ALLMC_OFFSET   0x6
#define HW_ATL2_RPF_TAG_ET_OFFSET      0x7
#define HW_ATL2_RPF_TAG_VLAN_OFFSET    0xA
#define HW_ATL2_RPF_TAG_UNTAG_OFFSET   0xE
#define HW_ATL2_RPF_TAG_L3_V4_OFFSET   0xF
#define HW_ATL2_RPF_TAG_L3_V6_OFFSET   0x12
#define HW_ATL2_RPF_TAG_L4_OFFSET      0x15
#define HW_ATL2_RPF_TAG_L4_FLEX_OFFSET 0x18
#define HW_ATL2_RPF_TAG_FLEX_OFFSET    0x1B
#define HW_ATL2_RPF_TAG_PCP_OFFSET     0x1D

#define HW_ATL2_RPF_TAG_UC_MASK    (0x0000003F << HW_ATL2_RPF_TAG_UC_OFFSET)
#define HW_ATL2_RPF_TAG_ALLMC_MASK (0x00000001 << HW_ATL2_RPF_TAG_ALLMC_OFFSET)
#define HW_ATL2_RPF_TAG_UNTAG_MASK (0x00000001 << HW_ATL2_RPF_TAG_UNTAG_OFFSET)
#define HW_ATL2_RPF_TAG_VLAN_MASK  (0x0000000F << HW_ATL2_RPF_TAG_VLAN_OFFSET)
#define HW_ATL2_RPF_TAG_ET_MASK    (0x00000007 << HW_ATL2_RPF_TAG_ET_OFFSET)
#define HW_ATL2_RPF_TAG_L3_V4_MASK (0x00000007 << HW_ATL2_RPF_TAG_L3_V4_OFFSET)
#define HW_ATL2_RPF_TAG_L3_V6_MASK (0x00000007 << HW_ATL2_RPF_TAG_L3_V6_OFFSET)
#define HW_ATL2_RPF_TAG_L4_MASK    (0x00000007 << HW_ATL2_RPF_TAG_L4_OFFSET)
#define HW_ATL2_RPF_TAG_FLEX_MASK  (0x00000001 << HW_ATL2_RPF_TAG_FLEX_OFFSET)
#define HW_ATL2_RPF_TAG_PCP_MASK   (0x00000007 << HW_ATL2_RPF_TAG_PCP_OFFSET)

#define HW_ATL2_RPF_TAG_BC         1
#define HW_ATL2_RPF_TAG_BASE_UC    BIT(HW_ATL2_RPF_TAG_UC_OFFSET)
#define HW_ATL2_RPF_TAG_BASE_ALLMC BIT(HW_ATL2_RPF_TAG_ALLMC_OFFSET)
#define HW_ATL2_RPF_TAG_BASE_UNTAG BIT(HW_ATL2_RPF_TAG_UNTAG_OFFSET)
#define HW_ATL2_RPF_TAG_BASE_VLAN  BIT(HW_ATL2_RPF_TAG_VLAN_OFFSET)

enum HW_ATL2_RPF_ART_INDEX {
	HW_ATL2_RPF_L2_PROMISC_OFF_INDEX,
	HW_ATL2_RPF_VLAN_PROMISC_OFF_INDEX,
	HW_ATL2_RPF_CHAIN_INDEX = 16,
	HW_ATL2_RPF_FLEX_INDEX = HW_ATL2_RPF_CHAIN_INDEX + 14,
	HW_ATL2_RPF_L3L4_USER_INDEX	= HW_ATL2_RPF_FLEX_INDEX + 2,
	HW_ATL2_RPF_ET_PCP_USER_INDEX = HW_ATL2_RPF_L3L4_USER_INDEX + 16,
	HW_ATL2_RPF_VLAN_USER_INDEX	= HW_ATL2_RPF_ET_PCP_USER_INDEX + 8,
	HW_ATL2_RPF_DST_FIRST_INDEX = HW_ATL2_RPF_VLAN_USER_INDEX + 12,
	HW_ATL2_RPF_PCP_TO_TC_INDEX	= HW_ATL2_RPF_DST_FIRST_INDEX + 4,
	HW_ATL2_RPF_INDEX_NUMBER = HW_ATL2_RPF_PCP_TO_TC_INDEX + 8,
};

#define HW_ATL2_RPF_L3_CMD_EN       BIT(0)
#define HW_ATL2_RPF_L3_CMD_SA_EN    BIT(1)
#define HW_ATL2_RPF_L3_CMD_DA_EN    BIT(2)
#define HW_ATL2_RPF_L3_CMD_PROTO_EN BIT(3)
#define HW_ATL2_RPF_L3_V6_V4_SELECT BIT(7)

#define HW_ATL2_RPF_L3_V6_CMD_EN       BIT(0x10)
#define HW_ATL2_RPF_L3_V6_CMD_SA_EN    BIT(0x11)
#define HW_ATL2_RPF_L3_V6_CMD_DA_EN    BIT(0x12)
#define HW_ATL2_RPF_L3_V6_CMD_PROTO_EN BIT(0x13)

#define HW_ATL2_RPF_L4_CMD_EN       BIT(0)
#define HW_ATL2_RPF_L4_CMD_DP_EN    BIT(1)
#define HW_ATL2_RPF_L4_CMD_SP_EN    BIT(2)

#define HW_ATL2_ACTION(ACTION, RSS, INDEX, VALID) \
	((((ACTION) & 0x3U) << 8) | \
	(((RSS) & 0x1U) << 7) | \
	(((INDEX) & 0x3FU) << 2) | \
	(((VALID) & 0x1U) << 0))

#define HW_ATL2_ACTION_DROP HW_ATL2_ACTION(0, 0, 0, 1)
#define HW_ATL2_ACTION_DISABLE HW_ATL2_ACTION(0, 0, 0, 0)
#define HW_ATL2_ACTION_ASSIGN_QUEUE(QUEUE) HW_ATL2_ACTION(1, 0, (QUEUE), 1)
#define HW_ATL2_ACTION_ASSIGN_TC(TC) HW_ATL2_ACTION(1, 1, (TC), 1)

#define HW_ATL2_RPF_L3L4_FILTERS 8
#define HW_ATL2_RPF_L3V4_FILTERS 8
#define HW_ATL2_RPF_L3V6_FILTERS 6
#define HW_ATL2_RPF_L4_FILTERS 8
#define HW_ATL2_RPF_VLAN_FILTERS 16
#define HW_ATL2_RPF_ETYPE_FILTERS 16
#define HW_ATL2_RPF_ETYPE_TAGS 7

#define HW_ATL2_FLEX0_AVAILABLE_BIT BIT(0)
enum HW_ATL2_RPF_RSS_HASH_TYPE {
	HW_ATL2_RPF_RSS_HASH_TYPE_NONE = 0,
	HW_ATL2_RPF_RSS_HASH_TYPE_IPV4 = BIT(0),
	HW_ATL2_RPF_RSS_HASH_TYPE_IPV4_TCP = BIT(1),
	HW_ATL2_RPF_RSS_HASH_TYPE_IPV4_UDP = BIT(2),
	HW_ATL2_RPF_RSS_HASH_TYPE_IPV6 = BIT(3),
	HW_ATL2_RPF_RSS_HASH_TYPE_IPV6_TCP = BIT(4),
	HW_ATL2_RPF_RSS_HASH_TYPE_IPV6_UDP = BIT(5),
	HW_ATL2_RPF_RSS_HASH_TYPE_IPV6_EX = BIT(6),
	HW_ATL2_RPF_RSS_HASH_TYPE_IPV6_EX_TCP = BIT(7),
	HW_ATL2_RPF_RSS_HASH_TYPE_IPV6_EX_UDP = BIT(8),
	HW_ATL2_RPF_RSS_HASH_TYPE_ALL = HW_ATL2_RPF_RSS_HASH_TYPE_IPV4 |
					HW_ATL2_RPF_RSS_HASH_TYPE_IPV4_TCP |
					HW_ATL2_RPF_RSS_HASH_TYPE_IPV4_UDP |
					HW_ATL2_RPF_RSS_HASH_TYPE_IPV6 |
					HW_ATL2_RPF_RSS_HASH_TYPE_IPV6_TCP |
					HW_ATL2_RPF_RSS_HASH_TYPE_IPV6_UDP |
					HW_ATL2_RPF_RSS_HASH_TYPE_IPV6_EX |
					HW_ATL2_RPF_RSS_HASH_TYPE_IPV6_EX_TCP |
					HW_ATL2_RPF_RSS_HASH_TYPE_IPV6_EX_UDP,
};

#define HW_ATL_MCAST_FLT_ANY_TO_HOST 0x00010FFFU
#define HW_ATL2_FLEX1_AVAILABLE_BIT BIT(1)

struct hw_atl2_l3_filter {
	u8 ipv6:1;
	u32 cmd_l3;
	u32 srcip[4];
	u32 dstip[4];
};

struct hw_atl2_l4_filter {
	u16 cmd_l4;
	u16 sport;
	u16 dport;
};

struct hw_atl2_l3l4_filter {
	s8 l3_index;
	s8 l4_index;
	u32 action;
};

/** Find tag with the same action or new free tag
 *  top - top inclusive tag value
 *  action - action for ActionResolverTable
 *
static inline int hw_atl2_filter_tag_get(struct hw_atl2_tag_policy *tags,
					 int top, u16 action)
{
	int i;

	for (i = 1; i <= top; i++)
		if ((tags[i].usage > 0) && (tags[i].action == action)) {
			tags[i].usage++;
			return i;
		}

	for (i = 1; i <= top; i++)
		if (tags[i].usage == 0) {
			tags[i].usage = 1;
			tags[i].action = action;
			return i;
		}

	return -1;
}

static inline void hw_atl2_filter_tag_put(struct hw_atl2_tag_policy *tags,
					  int tag)
{
	if (tags[tag].usage > 0)
		tags[tag].usage--;
}
*/
struct hw_atl2_priv {
	u8 special_uc_tag[HW_ATL2_MAC_MAX - HW_ATL2_MAC_MIN];
	struct statistics_s last_stats;
	u32 cable_diag_tid1;
	u32 ext_int_flags;
	u32 ptp_check_cntr; //W/A for bug ANTIGUAA0-366
	s32 ppb;
	unsigned int art_base_index;
	unsigned int art_count;
	unsigned int l2_filters_base_index;
	unsigned int l2_filter_count;
	unsigned int etype_filter_base_index;
	unsigned int etype_filter_count;
	unsigned int etype_filter_tag_top;
	unsigned int vlan_filter_base_index;
	unsigned int vlan_filter_count;
	unsigned int l3_v4_filter_base_index;
	unsigned int l3_v4_filter_count;
	unsigned int l3_v6_filter_base_index;
	unsigned int l3_v6_filter_count;
	unsigned int l4_filter_base_index;
	unsigned int l4_filter_count;
	unsigned int flex_filter_available;
};

#endif /* HW_ATL2_INTERNAL_H */
