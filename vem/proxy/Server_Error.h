/*
 * Server_Error.h
 *
 *  Created on: Jan 29, 2014
 *      Author: d
 */

#ifndef SERVER_ERROR_H_
#define SERVER_ERROR_H_


enum
{
	BH_SRVR_FAILURE = 0,
	BH_SRVR_SUCCESS,
	BH_SRVR_UNKNOWN,
	BH_SRVR_GETADDRINFO_ERR,
	BH_SRVR_SOCKET_BIND,
	BH_SRVR_LISTEN,
	BH_SRVR_UNINITIALIZED,
	BH_SRVR_SHUTDOWN_ERR,
	BH_SRVR_ALREADY_STARTED,
	BH_SRVR_ACCEPT_ERR,
	BH_SRVR_NULL,
	BH_SRVR_SOCKET_CLOSED,
	BH_SRVR_SENDERR,
	BH_SRVR_RECVERR,
	BH_SRVR_OUT_OF_MEMORY,
	BH_SRVR_HANDSHAKE_KEY_MISMATCH,
	BH_SRVR_SELECTERR,
	BH_SRVR_BUFFERSIZE_ERR,
	BH_SRVR_ARRAYALIGNEMNT_ERR,
	BH_SRVR_ARRAYKEYMISMATCH,
	BH_SRVR_PROTOCOLMISMATCH
};

typedef int bh_server_error;

#endif /* SERVER_ERROR_H_ */
