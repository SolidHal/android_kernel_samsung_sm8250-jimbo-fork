/*
 * HND Run Time Environment ioctl.
 *
 * Copyright (C) 2019, Broadcom.
 *
 *      Unless you and Broadcom execute a separate written software license
 * agreement governing use of this software, this software is licensed to you
 * under the terms of the GNU General Public License version 2 (the "GPL"),
 * available at http://www.broadcom.com/licenses/GPLv2.php, with the
 * following added to such license:
 *
 *      As a special exception, the copyright holders of this software give you
 * permission to link this software with independent modules, and to copy and
 * distribute the resulting executable under terms of your choice, provided that
 * you also meet, for each linked independent module, the terms and conditions of
 * the license of that module.  An independent module is a module which is not
 * derived from this software.  The special exception does not apply to any
 * modifications of the software.
 *
 *
 * <<Broadcom-WL-IPTag/Open:>>
 */

#ifndef _dngl_ioctl_h_
#define _dngl_ioctl_h_

/* ==== Dongle IOCTLs i.e. non-d11 IOCTLs ==== */

#ifndef _rte_ioctl_h_
/* ================================================================ */
/* These are the existing ioctls moved from src/include/rte_ioctl.h */
/* ================================================================ */

/* RTE IOCTL definitions for generic ether devices */
#define RTEIOCTLSTART		0x8901
#define RTEGHWADDR		0x8901
#define RTESHWADDR		0x8902
#define RTEGMTU			0x8903
#define RTEGSTATS		0x8904
#define RTEGALLMULTI		0x8905
#define RTESALLMULTI		0x8906
#define RTEGPROMISC		0x8907
#define RTESPROMISC		0x8908
#define RTESMULTILIST	0x8909
#define RTEGUP			0x890A
#define RTEGPERMADDR		0x890B
#define RTEDEVPWRSTCHG		0x890C	/* Device pwr state change for PCIedev */
#define RTEDEVPMETOGGLE		0x890D	/* Toggle PME# to wake up the host */
#define RTEDEVTIMESYNC		0x890E	/* Device TimeSync */
#define RTEDEVDSNOTIFY		0x890F	/* Bus DS state notification */
#define RTED11DMALPBK_INIT	0x8910	/* D11 DMA loopback init */
#define RTED11DMALPBK_UNINIT	0x8911	/* D11 DMA loopback uninit */
#define RTED11DMALPBK_RUN	0x8912	/* D11 DMA loopback run */
#define RTEDEVTSBUFPOST		0x8913	/* Async interface for tsync buffer post */
#define RTED11DMAHOSTLPBK_RUN	0x8914  /* D11 DMA host memory loopback run */
#define RTEDEVGETTSF		0x8915  /* Get device TSF */
#define RTEDURATIONUNIT		0x8916  /* Duration unit */
#define RTEWRITE_WAR_REGS	0x8917  /* write workaround regs */
/* Ensure last RTE IOCTL define val is assigned to RTEIOCTLEND */
#define RTEIOCTLEND		0x8917  /* LAST RTE IOCTL value */

#define RTE_IOCTL_QUERY		0x00
#define RTE_IOCTL_SET		0x01
#define RTE_IOCTL_OVL_IDX_MASK	0x1e
#define RTE_IOCTL_OVL_RSV	0x20
#define RTE_IOCTL_OVL		0x40
#define RTE_IOCTL_OVL_IDX_SHIFT	1

enum hnd_ioctl_cmd {
	HND_RTE_DNGL_IS_SS = 1, /* true if device connected at super speed */

	/* PCIEDEV specific wl <--> bus ioctls */
	BUS_GET_VAR = 2,
	BUS_SET_VAR = 3,
	BUS_FLUSH_RXREORDER_Q = 4,
	BUS_SET_LTR_STATE = 5,
	BUS_FLUSH_CHAINED_PKTS = 6,
	BUS_SET_COPY_COUNT = 7,
	BUS_UPDATE_FLOW_PKTS_MAX = 8,
	BUS_UPDATE_EXTRA_TXLFRAGS = 9,
	BUS_UPDATE_FRWD_RESRV_BUFCNT = 10,
	BUS_PCIE_CONFIG_ACCESS = 11,
	BUS_HC_EVENT_MASK_UPDATE = 12,
	BUS_SET_MAC_WAKE_STATE = 13,
	BUS_FRWD_PKT_RXCMPLT = 14,
	BUS_PCIE_LATENCY_ENAB = 15, /* to enable latency feature in pcie */
	BUS_GET_MAXITEMS = 16
};

#define SDPCMDEV_SET_MAXTXPKTGLOM	1
#define RTE_MEMUSEINFO_VER 0x00

typedef struct memuse_info {
	uint16 ver;			/* version of this struct */
	uint16 len;			/* length in bytes of this structure */
	uint32 tot;			/* Total memory */
	uint32 text_len;	/* Size of Text segment memory */
	uint32 data_len;	/* Size of Data segment memory */
	uint32 bss_len;		/* Size of BSS segment memory */

	uint32 arena_size;	/* Total Heap size */
	uint32 arena_free;	/* Heap memory available or free */
	uint32 inuse_size;	/* Heap memory currently in use */
	uint32 inuse_hwm;	/* High watermark of memory - reclaimed memory */
	uint32 inuse_overhead;	/* tally of allocated mem_t blocks */
	uint32 inuse_total;	/* Heap in-use + Heap overhead memory  */
	uint32 free_lwm;        /* Least free size since reclaim */
	uint32 mf_count;        /* Malloc failure count */
} memuse_info_t;

#define D11_DMA_LOOPBACK	1
#define BMC_DMA_LOOPBACK	2
#define D11_DMA_HOST_MEM_LPBK	4

/* For D11 DMA loopback test */
typedef struct d11_dmalpbk_init_args {
	uint8 core_num;
	uint8 lpbk_mode;
} d11_dmalpbk_init_args_t;

typedef struct d11_dmalpbk_args {
	uint8 *buf;
	int32 len;
	void *p;
	uint8 core_num;
	uint8 pad[3];
} d11_dmalpbk_args_t;

/* ================================================================ */
/* These are the existing ioctls moved from src/include/rte_ioctl.h */
/* ================================================================ */
#endif /* _rte_ioctl_h_ */

/* MPU test iovar version */
#define MPU_TEST_STRUCT_VER	0

/* MPU test OP */
#define MPU_TEST_OP_READ	0
#define MPU_TEST_OP_WRITE	1
#define MPU_TEST_OP_EXECUTE	2

/* Debug iovar for MPU testing */
typedef struct mpu_test_args {
	/* version control */
	uint16 ver;
	uint16 len;	/* the length of this structure */
	/* data */
	uint32 addr;
	uint8 op;	/* see MPU_TEST_OP_XXXX */
	uint8 rsvd;
	uint16 size;	/* valid for read/write */
	uint8 val[];
} mpu_test_args_t;

#endif /* _dngl_ioctl_h_ */
