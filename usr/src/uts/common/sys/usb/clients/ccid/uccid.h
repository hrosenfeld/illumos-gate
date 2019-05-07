/*
 * This file and its contents are supplied under the terms of the
 * Common Development and Distribution License ("CDDL"), version 1.0.
 * You may only use this file in accordance with the terms of version
 * 1.0 of the CDDL.
 *
 * A full copy of the text of the CDDL should have accompanied this
 * source.  A copy of the CDDL is also available via the Internet at
 * http://www.illumos.org/license/CDDL.
 */

/*
 * Copyright 2019, Joyent, Inc.
 */

#ifndef _SYS_USB_UCCID_H
#define	_SYS_USB_UCCID_H

/*
 * Definitions for the userland CCID interface.
 */

#include <sys/types.h>
#include <sys/ccompile.h>
#include <sys/port.h>
#include <sys/usb/clients/ccid/ccid.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * The maximum size of a normal APDU. This is the upper bound of what a user can
 * read or write to a given card.
 */
#define	UCCID_APDU_SIZE_MAX	261

/*
 * This is the maximum length of an ATR as per ISO/IEC 7816-3:2006.
 */
#define	UCCID_ATR_MAX		33


#define	UCCID_IOCTL	(('u' << 24) | ('c' << 16) | ('d') << 8)

#define	UCCID_VERSION_ONE	1
#define	UCCID_CURRENT_VERSION	UCCID_VERSION_ONE

/*
 * Attempt to obtain exclusive access. If the UCN_TXN_DONT_BLOCK flag is
 * specified, the ioctl will return immediately if exclusive access cannot be
 * gained. Otherwise, it will block in an interruptable fashion. The argument is
 * a uccid_cmd_txn_begin_t.
 */
#define	UCCID_CMD_TXN_BEGIN	(UCCID_IOCTL | 0x01)
#define	UCCID_TXN_DONT_BLOCK	0x01

typedef struct uccid_cmd_txn_begin {
	uint32_t	uct_version;
	uint32_t	uct_flags;
} __packed uccid_cmd_txn_begin_t;

/*
 * Relinquish exclusive access. Takes a uccid_cmd_txn_end_t. The callers should
 * specify one of UCCID_TXN_END_RESET or UCCID_TXN_END_RELEASE. These indicate
 * what behavior should be taken when we release the transaction. It is
 * considered an error if neither is specified. If the caller exits without
 * calling this function, then the ICC will be reset.
 */
#define	UCCID_CMD_TXN_END	(UCCID_IOCTL | 0x02)
#define	UCCID_TXN_END_RESET	0x01
#define	UCCID_TXN_END_RELEASE	0x02

typedef struct uccid_cmd_txn_end {
	uint32_t	uct_version;
	uint32_t	uct_flags;
} __packed uccid_cmd_txn_end_t;

/*
 * Obtain the status of the slot. Fills in ucs_flags.
 */
#define	UCCID_CMD_STATUS	(UCCID_IOCTL | 0x3)

/*
 * Protocol definitions. This should match common/ccid/atr.h.
 */
typedef enum {
	UCCID_PROT_T0	= 1 << 0,
	UCCID_PROT_T1	= 1 << 1
} uccid_prot_t;

/*
 * Bits for UCS Status
 */
#define	UCCID_STATUS_F_CARD_PRESENT	0x01
#define	UCCID_STATUS_F_CARD_ACTIVE	0x02
#define	UCCID_STATUS_F_PRODUCT_VALID	0x04
#define	UCCID_STATUS_F_SERIAL_VALID	0x08
#define	UCCID_STATUS_F_PARAMS_VALID	0x10

typedef struct uccid_cmd_status {
	uint32_t	ucs_version;
	uint32_t	ucs_status;
	int32_t		ucs_instance;
	uint32_t	ucs_slot;
	uint8_t		ucs_atr[UCCID_ATR_MAX];
	uint8_t		ucs_atrlen;
	uint8_t		ucs_pad[6];
	int8_t		ucs_product[256];
	int8_t		ucs_serial[256];
	ccid_class_descr_t	ucs_class;
	uccid_prot_t	ucs_prot;
	ccid_params_t	ucs_params;
	uint64_t	ucs_gen;
} __packed uccid_cmd_status_t;

/*
 * Modify the state of the ICC, if present.
 */
#define	UCCID_CMD_ICC_MODIFY	(UCCID_IOCTL | 0x04)

#define	UCCID_ICC_POWER_ON	0x01
#define	UCCID_ICC_POWER_OFF	0x02
#define	UCCID_ICC_WARM_RESET	0x03

typedef struct uccid_cmd_icc_modify {
	uint32_t uci_version;
	uint32_t uci_action;
} __packed uccid_cmd_icc_modify_t;

/*
 * CCID events
 */
typedef struct uccid_event {
	dev_obj_t	ce_dev_obj;
	uint32_t	ce_version;
	uint32_t	ce_size;
	uint64_t	ce_icc_insert_gen;
	uint64_t	ce_icc_remove_gen;
	uint64_t	ce_icc_on_gen;
	uint64_t	ce_icc_off_gen;
} __packed uccid_event_t;

#define	UCCID_EVENT_ICC_INSERTED		0x001
#define	UCCID_EVENT_ICC_REMOVED			0x002
#define	UCCID_EVENT_ICC_POWERED_ON		0x004
#define	UCCID_EVENT_ICC_POWERED_OFF		0x008
#define	UCCID_EVENT_TRANSACTION_READY		0x010
#define	UCCID_EVENT_COMMAND_SUBMISSION_READY	0x020
#define	UCCID_EVENT_COMMAND_COMPLETED		0x040
#define	UCCID_EVENT_TRANSACTION_ERROR		0x080
#define	UCCID_EVENT_READER_GONE			0x100

#define	UCCID_EVENTS_ALL			\
	(UCCID_EVENT_ICC_INSERTED |		\
	UCCID_EVENT_ICC_REMOVED |		\
	UCCID_EVENT_ICC_POWERED_ON |		\
	UCCID_EVENT_ICC_POWERED_OFF |		\
	UCCID_EVENT_TRANSACTION_READY |		\
	UCCID_EVENT_COMMAND_SUBMISSION_READY |	\
	UCCID_EVENT_COMMAND_COMPLETED |		\
	UCCID_EVENT_TRANSACTION_ERROR |		\
	UCCID_EVENT_READER_GONE)

#define	UCCID_EVENTS_ALWAYS_ENABLED	\
	(UCCID_EVENT_TRANSACTION_ERROR | UCCID_EVENT_READER_GONE)


#ifdef __cplusplus
}
#endif


#endif /* _SYS_USB_UCCID_H */
