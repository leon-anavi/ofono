/*
 *
 *  RIL library with GLib integration
 *
 *  Copyright (C) 2008-2011  Intel Corporation. All rights reserved.
 *  Copyright (C) 2012-2013  Canonical Ltd.
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

#ifndef __GRILUNSOL_H
#define __GRILUNSOL_H

#include <ofono/types.h>

#include "gril.h"

#ifdef __cplusplus
extern "C" {
#endif

struct ril_data_call {
	guint status;
	gint cid;
	guint active;
	guint protocol;
	char *ifname;
	gchar *ip_addr;
	gchar **dns_addrs;
	gchar **gateways;
};

struct ril_data_call_list {
	guint version;
	GSList *calls;
};

void g_ril_unsol_free_data_call_list(struct ril_data_call_list *data_call_list);


struct ril_data_call_list *g_ril_unsol_parse_data_call_list(GRil *gril,
						const struct ril_msg *message);

#ifdef __cplusplus
}
#endif

#endif /* __GRILUNSOL_H */
