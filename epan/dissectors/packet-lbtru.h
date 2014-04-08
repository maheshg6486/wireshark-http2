/* packet-lbtru.h
 * Routines for LBT-RU Packet dissection
 *
 * Copyright (c) 2005-2014 Informatica Corporation. All Rights Reserved.
 *
 * Wireshark - Network traffic analyzer
 * By Gerald Combs <gerald@wireshark.org>
 * Copyright 1998 Gerald Combs
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef PACKET_LBTRU_H_INCLUDED
#define PACKET_LBTRU_H_INCLUDED

#include "config.h"
#include <glib.h>
#include <epan/address.h>
#include <epan/value_string.h>
#include <epan/wmem/wmem.h>
#include "packet-lbm.h"

typedef struct
{
    address source_address;
    guint16 source_port;
    guint32 session_id;
    guint64 channel;
    guint32 next_client_id;
    wmem_list_t * client_list;
} lbtru_transport_t;

typedef struct
{
    address receiver_address;
    guint16 receiver_port;
    guint32 id;
    lbtru_transport_t * transport;
    wmem_tree_t * frame;
    lbm_transport_frame_t * last_frame;
    lbm_transport_frame_t * last_data_frame;
    lbm_transport_frame_t * last_sm_frame;
    lbm_transport_frame_t * last_nak_frame;
    lbm_transport_frame_t * last_ncf_frame;
    lbm_transport_frame_t * last_ack_frame;
    lbm_transport_frame_t * last_creq_frame;
    lbm_transport_frame_t * last_rst_frame;
    wmem_tree_t * data_sqn;
    wmem_tree_t * sm_sqn;
    guint32 data_high_sqn;
    guint32 sm_high_sqn;
} lbtru_client_transport_t;

lbtru_transport_t * lbtru_transport_add(const address * source_address, guint16 source_port, guint32 session_id, guint32 frame);
char * lbtru_transport_source_string(const address * source_address, guint16 source_port, guint32 session_id);

#endif

/*
 * Editor modelines  -  http://www.wireshark.org/tools/modelines.html
 *
 * Local variables:
 * c-basic-offset: 4
 * tab-width: 4
 * indent-tabs-mode: nil
 * End:
 *
 * vi: set shiftwidth=4 tabstop=4 expandtab:
 * :indentSize=4:tabSize=4:noTabs=true:
 */