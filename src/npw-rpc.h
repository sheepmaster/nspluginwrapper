/*
 *  npw-rpc.h - Remote Procedure Calls (NPAPI specialisation)
 *
 *  nspluginwrapper (C) 2005-2009 Gwenole Beauchesne
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef NPW_RPC_H
#define NPW_RPC_H

#ifdef __cplusplus
extern "C" {
#endif

// NPAPI methods
enum {
  RPC_METHOD_NP_GET_VALUE = 1,					/*  1 */
  RPC_METHOD_NP_GET_MIME_DESCRIPTION,
  RPC_METHOD_NP_INITIALIZE,
  RPC_METHOD_NP_SHUTDOWN,

  RPC_METHOD_NPN_USER_AGENT,					/*  5 */
  RPC_METHOD_NPN_GET_VALUE,
  RPC_METHOD_NPN_SET_VALUE,
  RPC_METHOD_NPN_GET_URL,
  RPC_METHOD_NPN_GET_URL_NOTIFY,
  RPC_METHOD_NPN_POST_URL,						/* 10 */
  RPC_METHOD_NPN_POST_URL_NOTIFY,
  RPC_METHOD_NPN_STATUS,
  RPC_METHOD_NPN_PRINT_DATA,
  RPC_METHOD_NPN_REQUEST_READ,
  RPC_METHOD_NPN_NEW_STREAM,					/* 15 */
  RPC_METHOD_NPN_DESTROY_STREAM,
  RPC_METHOD_NPN_WRITE,
  RPC_METHOD_NPN_PUSH_POPUPS_ENABLED_STATE,
  RPC_METHOD_NPN_POP_POPUPS_ENABLED_STATE,
  RPC_METHOD_NPN_FORCE_REDRAW,					/* 20 */
  RPC_METHOD_NPN_INVALIDATE_RECT,
  RPC_METHOD_NPN_INVALIDATE_REGION,

  RPC_METHOD_NPP_NEW,
  RPC_METHOD_NPP_DESTROY,
  RPC_METHOD_NPP_SET_WINDOW,					/* 25 */
  RPC_METHOD_NPP_HANDLE_EVENT,
  RPC_METHOD_NPP_GET_VALUE,
  RPC_METHOD_NPP_SET_VALUE,
  RPC_METHOD_NPP_URL_NOTIFY,
  RPC_METHOD_NPP_NEW_STREAM,					/* 30 */
  RPC_METHOD_NPP_DESTROY_STREAM,
  RPC_METHOD_NPP_WRITE_READY,
  RPC_METHOD_NPP_WRITE,
  RPC_METHOD_NPP_STREAM_AS_FILE,
  RPC_METHOD_NPP_PRINT,							/* 35 */

  RPC_METHOD_NPN_CREATE_OBJECT,
  RPC_METHOD_NPN_RETAIN_OBJECT,
  RPC_METHOD_NPN_RELEASE_OBJECT,
  RPC_METHOD_NPN_INVOKE,
  RPC_METHOD_NPN_INVOKE_DEFAULT,				/* 40 */
  RPC_METHOD_NPN_EVALUATE,
  RPC_METHOD_NPN_GET_PROPERTY,
  RPC_METHOD_NPN_SET_PROPERTY,
  RPC_METHOD_NPN_REMOVE_PROPERTY,
  RPC_METHOD_NPN_HAS_PROPERTY,					/* 45 */
  RPC_METHOD_NPN_HAS_METHOD,
  RPC_METHOD_NPN_SET_EXCEPTION,
  RPC_METHOD_NPN_ENUMERATE,
  RPC_METHOD_NPN_CONSTRUCT,

  RPC_METHOD_NPN_GET_STRING_IDENTIFIER,			/* 50 */
  RPC_METHOD_NPN_GET_STRING_IDENTIFIERS,
  RPC_METHOD_NPN_GET_INT_IDENTIFIER,
  RPC_METHOD_NPN_IDENTIFIER_IS_STRING,
  RPC_METHOD_NPN_UTF8_FROM_IDENTIFIER,
  RPC_METHOD_NPN_INT_FROM_IDENTIFIER,			/* 55 */

  RPC_METHOD_NPCLASS_INVALIDATE,
  RPC_METHOD_NPCLASS_HAS_METHOD,
  RPC_METHOD_NPCLASS_INVOKE,
  RPC_METHOD_NPCLASS_INVOKE_DEFAULT,
  RPC_METHOD_NPCLASS_HAS_PROPERTY,				/* 60 */
  RPC_METHOD_NPCLASS_GET_PROPERTY,
  RPC_METHOD_NPCLASS_SET_PROPERTY,
  RPC_METHOD_NPCLASS_REMOVE_PROPERTY
};

// NPAPI data types
enum {
  RPC_TYPE_NPP = 1,								/*  1 */
  RPC_TYPE_NP_STREAM,
  RPC_TYPE_NP_BYTE_RANGE,
  RPC_TYPE_NP_SAVED_DATA,
  RPC_TYPE_NP_NOTIFY_DATA,						/*  5 */
  RPC_TYPE_NP_RECT,
  RPC_TYPE_NP_WINDOW,
  RPC_TYPE_NP_EVENT,
  RPC_TYPE_NP_PRINT,
  RPC_TYPE_NP_FULL_PRINT,						/* 10 */
  RPC_TYPE_NP_EMBED_PRINT,
  RPC_TYPE_NP_PRINT_DATA,
  RPC_TYPE_NP_OBJECT,
  RPC_TYPE_NP_IDENTIFIER,
  RPC_TYPE_NP_STRING,							/* 15 */
  RPC_TYPE_NP_VARIANT,
  RPC_TYPE_NP_UTF8,
  RPC_TYPE_NPW_PLUGIN_INSTANCE
};

// NPPrintData is used to get the plugin printed tmpfile
typedef struct _NPPrintData {
  uint32_t size;
  uint8_t data[4096];
} NPPrintData;

// Initialize marshalers for NS4 plugin types
extern int rpc_add_np_marshalers(rpc_connection_t *connection) attribute_hidden;

// RPC types
extern int rpc_type_of_NPNVariable(int variable) attribute_hidden;
extern int rpc_type_of_NPPVariable(int variable) attribute_hidden;

#ifdef __cplusplus
}
#endif

#endif /* NPW_RPC_H */
