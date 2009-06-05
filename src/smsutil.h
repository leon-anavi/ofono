/*
 *
 *  oFono - Open Source Telephony
 *
 *  Copyright (C) 2008-2009  Intel Corporation. All rights reserved.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#ifndef __SMSUTIL_H__
#define __SMSUTIL_H__

#define CBS_PAYLOAD_CHARACTERS 93

enum sms_type {
	SMS_TYPE_DELIVER = 0,
	SMS_TYPE_DELIVER_REPORT_ACK,
	SMS_TYPE_DELIVER_REPORT_ERROR,
	SMS_TYPE_STATUS_REPORT,
	SMS_TYPE_SUBMIT,
	SMS_TYPE_SUBMIT_REPORT_ACK,
	SMS_TYPE_SUBMIT_REPORT_ERROR,
	SMS_TYPE_COMMAND
};

/* 23.040 Section 9.1.2.5 */
enum sms_number_type {
	SMS_NUMBER_TYPE_UNKNOWN = 0,
	SMS_NUMBER_TYPE_INTERNATIONAL = 1,
	SMS_NUMBER_TYPE_NATIONAL = 2,
	SMS_NUMBER_TYPE_NETWORK_SPECIFIC = 3,
	SMS_NUMBER_TYPE_SUBSCRIBER = 4,
	SMS_NUMBER_TYPE_ALPHANUMERIC = 5,
	SMS_NUMBER_TYPE_ABBREVIATED = 6,
	SMS_NUMBER_TYPE_RESERVED = 7
};

/* 23.040 Section 9.1.2.5 */
enum sms_numbering_plan {
	SMS_NUMBERING_PLAN_UNKNOWN = 0,
	SMS_NUMBERING_PLAN_ISDN = 1,
	SMS_NUMBERING_PLAN_DATA = 3,
	SMS_NUMBERING_PLAN_TELEX = 4,
	SMS_NUMBERING_PLAN_SC1 = 5,
	SMS_NUMBERING_PLAN_SC2 = 6,
	SMS_NUMBERING_PLAN_NATIONAL = 8,
	SMS_NUMBERING_PLAN_PRIVATE = 9,
	SMS_NUMBERING_PLAN_ERMES = 10,
	SMS_NUMBERING_PLAN_RESERVED = 15
};

enum sms_validity_period_format {
	SMS_VALIDITY_PERIOD_FORMAT_ABSENT = 0,
	SMS_VALIDITY_PERIOD_FORMAT_ENHANCED = 1,
	SMS_VALIDITY_PERIOD_FORMAT_RELATIVE = 2,
	SMS_VALIDITY_PERIOD_FORMAT_ABSOLUTE = 3,
};

enum sms_st {
	SMS_ST_COMPLETED_RECEIVED = 0x0,
	SMS_ST_COMPLETED_UNABLE_TO_CONFIRM = 0x1,
	SMS_ST_COMPLETED_REPLACED = 0x2,
	SMS_ST_COMPLETED_LAST = 0x1F,
	SMS_ST_TEMPORARY_CONGESTION = 0x20,
	SMS_ST_TEMPORARY_SME_BUSY = 0x21,
	SMS_ST_TEMPORARY_NO_RESPONSE = 0x22,
	SMS_ST_TEMPORARY_SERVICE_REJECTED = 0x23,
	SMS_ST_TEMPORARY_QOS_UNAVAILABLE = 0x24,
	SMS_ST_TEMPORARY_SME_ERROR = 0x25,
	SMS_ST_TEMPORARY_LAST = 0x2F,
	SMS_ST_PERMANENT_RP_ERROR = 0x40,
	SMS_ST_PERMANENT_INVALID_DESTINATION = 0x41,
	SMS_ST_PERMANENT_CONNECTION_REJECTED = 0x42,
	SMS_ST_PERMANENT_NOT_OBTAINABLE = 0x43,
	SMS_ST_PERMANENT_QOS_UNAVAILABLE = 0x44,
	SMS_ST_PERMANENT_INTERWORKING_UNAVAILABLE = 0x45,
	SMS_ST_PERMANENT_VALIDITY_PERIOD_EXPIRED = 0x46,
	SMS_ST_PERMANENT_DELETED = 0x47,
	SMS_ST_PERMANENT_SC_ADMIN_DELETED = 0x48,
	SMS_ST_PERMANENT_SM_DOES_NOT_EXIST = 0x49,
	SMS_ST_PERMANENT_LAST = 0x4F,
	SMS_ST_TEMPFINAL_CONGESTION = 0x60,
	SMS_ST_TEMPFINAL_SME_BUSY = 0x61,
	SMS_ST_TEMPFINAL_NO_RESPONSE = 0x62,
	SMS_ST_TEMPFINAL_SERVICE_REJECTED = 0x63,
	SMS_ST_TEMPFINAL_QOS_UNAVAILABLE = 0x64,
	SMS_ST_TEMPFINAL_SME_ERROR = 0x65,
	SMS_ST_TEMPFINAL_LAST = 0x6F,
};

enum sms_ct {
	SMS_CT_ENQUIRY = 0,
	SMS_CT_CANCEL_SRR = 1,
	SMS_CT_DELETE_SM = 2,
	SMS_CT_ENABLE_SRR = 3
};

enum sms_iei {
	SMS_IEI_CONCATENATED_8BIT = 0x00,
	SMS_IEI_SPECIAL_MESSAGE_INDICATION = 0x01,
	SMS_IEI_APPLICATION_ADDRESSS_8BIT = 0x04,
	SMS_IEI_APPLICATION_ADDRESS_16BIT = 0x05,
	SMS_IEI_SMSC_CONTROL_PARAMETERS = 0x06,
	SMS_IEI_UDH_SOURCE_INDICATOR = 0x07,
	SMS_IEI_CONCATENATED_16BIT = 0x08,
	SMS_IEI_WCMP = 0x09,
	SMS_IEI_TEXT_FORMAT = 0x0A,
	SMS_IEI_PREDEFINED_SOUND = 0x0B,
	SMS_IEI_USER_DEFINED_SOUND = 0x0C,
	SMS_IEI_PREDEFINED_ANIMATION = 0x0D,
	SMS_IEI_LARGE_ANIMATION = 0x0E,
	SMS_IEI_SMALL_ANIMATION = 0x0F,
	SMS_IEI_LARGE_PICTURE = 0x10,
	SMS_IEI_SMALL_PICTURE = 0x11,
	SMS_IEI_VARIABLE_PICTURE = 0x12,
	SMS_IEI_USER_PROMPT_INDICATOR = 0x13,
	SMS_IEI_EXTENDED_OBJECT = 0x14,
	SMS_IEI_REUSED_EXTENDED_OBJECT = 0x15,
	SMS_IEI_COMPRESSION_CONTROL = 0x16,
	SMS_IEI_OBJECT_DISTRIBUTION_INDICATOR = 0x17,
	SMS_IEI_STANDARD_WVG_OBJECT = 0x18,
	SMS_IEI_CHARACTER_SIZE_WVG_OBJECT = 0x19,
	SMS_IEI_EXTENDED_OBJECT_DATA_REQUEST_COMMAND = 0x1A,
	SMS_IEI_RFC822_EMAIL_HEADER = 0x20,
	SMS_IEI_HYPERLINK_ELEMENT = 0x21,
	SMS_IEI_REPLY_ADDRESS_ELEMENT = 0x22,
	SMS_IEI_ENHANCED_VOICE_MAIL_INFORMATION = 0x23,
	SMS_IEI_NATIONAL_LANGUAGE_SINGLE_SHIFT = 0x24,
	SMS_IEI_NATIONAL_LANGUAGE_LOCKING_SHIFT = 0x25,
	SMS_IEI_INVALID = 0xFFF
};

enum sms_class {
	SMS_CLASS_0 = 0,
	SMS_CLASS_1 = 1,
	SMS_CLASS_2 = 2,
	SMS_CLASS_3 = 3,
	SMS_CLASS_UNSPECIFIED = 4,
};

enum sms_charset {
	SMS_CHARSET_7BIT = 0,
	SMS_CHARSET_8BIT = 1,
	SMS_CHARSET_UCS2 = 2,
};

struct sms_address {
	enum sms_number_type number_type;
	enum sms_numbering_plan numbering_plan;
	char address[21]; /* Max 20 in semi-octet, 11 in alnum */
};

struct sms_scts {
	guint8 year;
	guint8 month;
	guint8 day;
	guint8 hour;
	guint8 minute;
	guint8 second;
	gint8 timezone;
};

struct sms_validity_period {
	union {
		guint8 relative;
		struct sms_scts absolute;
		guint8 enhanced[7];
	};
};

struct sms_deliver {
	gboolean mms;
	gboolean sri;
	gboolean udhi;
	gboolean rp;
	struct sms_address oaddr;
	guint8 pid;
	guint8 dcs;
	struct sms_scts scts;
	guint8 udl;
	guint8 ud[140];
};

struct sms_deliver_err_report {
	gboolean udhi;
	guint8 fcs;
	guint8 pi;
	guint8 pid;
	guint8 dcs;
	guint8 udl;
	guint8 ud[158];
};

struct sms_deliver_ack_report {
	gboolean udhi;
	guint8 pi;
	guint8 pid;
	guint8 dcs;
	guint8 udl;
	guint8 ud[159];
};

struct sms_command {
	gboolean udhi;
	gboolean srr;
	guint8 mr;
	guint8 pid;
	enum sms_ct ct;
	guint8 mn;
	struct sms_address daddr;
	guint8 cdl;
	guint8 cd[156];
};

struct sms_status_report {
	gboolean udhi;
	gboolean mms;
	gboolean srq;
	guint8 mr;
	struct sms_address raddr;
	struct sms_scts scts;
	struct sms_scts dt;
	enum sms_st st;
	guint8 pi;
	guint8 pid;
	guint8 dcs;
	guint8 udl;
	guint8 ud[143];
};

struct sms_submit {
	gboolean rd;
	enum sms_validity_period_format vpf;
	gboolean rp;
	gboolean udhi;
	gboolean srr;
	guint8 mr;
	struct sms_address daddr;
	guint8 pid;
	guint8 dcs;
	struct sms_validity_period vp;
	guint8 udl;
	guint8 ud[140];
};

struct sms_submit_ack_report {
	gboolean udhi;
	guint8 pi;
	struct sms_scts scts;
	guint8 pid;
	guint8 dcs;
	guint8 udl;
	guint8 ud[152];
};

struct sms_submit_err_report {
	gboolean udhi;
	guint8 fcs;
	guint8 pi;
	struct sms_scts scts;
	guint8 pid;
	guint8 dcs;
	guint8 udl;
	guint8 ud[151];
};

struct sms {
	struct sms_address sc_addr;
	enum sms_type type;
	union {
		struct sms_deliver deliver;
		struct sms_deliver_ack_report deliver_ack_report;
		struct sms_deliver_err_report deliver_err_report;
		struct sms_submit submit;
		struct sms_submit_ack_report submit_ack_report;
		struct sms_submit_err_report submit_err_report;
		struct sms_command command;
		struct sms_status_report status_report;
	};
};

struct sms_udh_iter {
	struct sms *sms;
	guint8 *data;
	guint8 offset;
};

gboolean sms_decode(const unsigned char *pdu, int len, gboolean outgoing,
			int tpdu_len, struct sms *out);

gboolean sms_encode(const struct sms *in, int *len, int *tpdu_len,
			unsigned char *pdu);

int sms_udl_in_bytes(guint8 ud_len, guint8 dcs);

time_t sms_scts_to_time(struct sms_scts *scts, struct tm *remote);

gboolean sms_udh_iter_init(struct sms *sms, struct sms_udh_iter *iter);
enum sms_iei sms_udh_iter_get_ie_type(struct sms_udh_iter *iter);
guint8 sms_udh_iter_get_ie_length(struct sms_udh_iter *iter);
void sms_udh_iter_get_ie_data(struct sms_udh_iter *iter, guint8 *data);
gboolean sms_udh_iter_has_next(struct sms_udh_iter *iter);
gboolean sms_udh_iter_next(struct sms_udh_iter *iter);

gboolean sms_dcs_decode(guint8 dcs, enum sms_class *cls,
			enum sms_charset *charset,
			gboolean *compressed, gboolean *autodelete);
#endif
