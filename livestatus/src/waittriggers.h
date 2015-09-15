// +------------------------------------------------------------------+
// |             ____ _               _        __  __ _  __           |
// |            / ___| |__   ___  ___| | __   |  \/  | |/ /           |
// |           | |   | '_ \ / _ \/ __| |/ /   | |\/| | ' /            |
// |           | |___| | | |  __/ (__|   <    | |  | | . \            |
// |            \____|_| |_|\___|\___|_|\_\___|_|  |_|_|\_\           |
// |                                                                  |
// | Copyright Mathias Kettner 2014             mk@mathias-kettner.de |
// +------------------------------------------------------------------+
//
// This file is part of Check_MK.
// Copyright by Mathias Kettner and Mathias Kettner GmbH.  All rights reserved.
//
// Check_MK is free software;  you can redistribute it and/or modify it
// under the  terms of the  GNU General Public License  as published by
// the Free Software Foundation in version 2.
//
// Check_MK is  distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY;  without even the implied warranty of
// MERCHANTABILITY  or  FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have  received  a copy of the  GNU  General Public
// License along with Check_MK.  If  not, email to mk@mathias-kettner.de
// or write to the postal address provided at www.mathias-kettner.de

#ifndef waittriggers_h
#define waittriggers_h

#include "pthread.h"

#define WT_NONE         -1
#define WT_ALL           0
#define WT_CHECK         1
#define WT_STATE         2
#define WT_LOG           3
#define WT_DOWNTIME      4
#define WT_COMMENT       5
#define WT_COMMAND       6
#define WT_PROGRAM       7
#define WT_NUM_TRIGGERS  8

#define WT_ALLNAMES "all, check, state, log, downtime, comment, command and program"

#ifdef __cplusplus
extern "C"
{
#endif
void trigger(int what);
#ifdef __cplusplus
}
#endif


extern const char *wt_names[];
extern pthread_cond_t g_wait_cond[];
extern pthread_mutex_t g_wait_mutex;


#endif // waittriggers_h

