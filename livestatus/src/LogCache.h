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

#ifndef LogCache_h
#define LogCache_h

#include <map>
#include <time.h>
#include "config.h"
#include "Table.h"

class Logfile;

typedef map<time_t, Logfile *> _logfiles_t;

class LogCache
{
    pthread_mutex_t _lock;
    unsigned long   _max_cached_messages;
    unsigned long   _num_at_last_check;
    _logfiles_t     _logfiles;

public:
    LogCache(unsigned long max_cached_messages);
    ~LogCache();
    void setMaxCachedMessages(unsigned long m);
    time_t _last_index_update;

    const char *name() { return "log"; }
    const char *prefixname() { return "logs"; }
    bool isAuthorized(contact *ctc, void *data);
    void handleNewMessage(Logfile *logfile, time_t since, time_t until, unsigned logclasses);
    Column *column(const char *colname); // override in order to handle current_
    _logfiles_t *logfiles() { return &_logfiles; };
    void forgetLogfiles();
    void updateLogfileIndex();

    bool logCachePreChecks();
    void lockLogCache();
    void unlockLogCache();

private:
    void scanLogfile(char *path, bool watch);
    _logfiles_t::iterator findLogfileStartingBefore(time_t);
    void dumpLogfiles();
};

#endif // LogCache_h
