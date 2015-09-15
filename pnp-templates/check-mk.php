<?php
# +------------------------------------------------------------------+
# |             ____ _               _        __  __ _  __           |
# |            / ___| |__   ___  ___| | __   |  \/  | |/ /           |
# |           | |   | '_ \ / _ \/ __| |/ /   | |\/| | ' /            |
# |           | |___| | | |  __/ (__|   <    | |  | | . \            |
# |            \____|_| |_|\___|\___|_|\_\___|_|  |_|_|\_\           |
# |                                                                  |
# | Copyright Mathias Kettner 2014             mk@mathias-kettner.de |
# +------------------------------------------------------------------+
#
# This file is part of Check_MK.
# Copyright by Mathias Kettner and Mathias Kettner GmbH.  All rights reserved.
#
# Check_MK is free software;  you can redistribute it and/or modify it
# under the  terms of the  GNU General Public License  as published by
# the Free Software Foundation in version 2.
#
# Check_MK is  distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY;  without even the implied warranty of
# MERCHANTABILITY  or  FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have  received  a copy of the  GNU  General Public
# License along with Check_MK.  If  not, email to mk@mathias-kettner.de
# or write to the postal address provided at www.mathias-kettner.de

$range = $CRIT[1];

$opt[1] = "--vertical-label 'time (s)' -l 0  --title '$hostname: Check_MK check execution time' ";

$def[1] = "DEF:extime=$RRDFILE[1]:$DS[1]:MAX ";
$def[1] .= "AREA:extime#d080af:\"execution time \" ";
$def[1] .= "LINE1:extime#d020a0: ";
$def[1] .= "GPRINT:extime:LAST:\"last\: %8.2lf s\" ";
$def[1] .= "GPRINT:extime:MAX:\"max\: %8.2lf s \" ";
$def[1] .= "GPRINT:extime:AVERAGE:\"avg\: %8.2lf s\\n\" ";

if (isset($RRDFILE[2])) {

$opt[2] = "--vertical-label 'time (s)' -l 0  --title '$hostname: Check_MK process times' ";
$def[2] = "DEF:user_time=$RRDFILE[2]:$DS[1]:MAX ";
$def[2] .= "LINE1:user_time#d020a0:\"user time\" ";
$def[2] .= "GPRINT:user_time:LAST:\"          last\: %8.2lf s\" ";
$def[2] .= "GPRINT:user_time:MAX:\"max\: %8.2lf s \" ";
$def[2] .= "GPRINT:user_time:AVERAGE:\"avg\: %8.2lf s\\n\" ";

$def[2] .= "DEF:system_time=$RRDFILE[3]:$DS[1]:MAX ";
$def[2] .= "LINE1:system_time#d08400:\"system time\" ";
$def[2] .= "GPRINT:system_time:LAST:\"        last\: %8.2lf s\" ";
$def[2] .= "GPRINT:system_time:MAX:\"max\: %8.2lf s \" ";
$def[2] .= "GPRINT:system_time:AVERAGE:\"avg\: %8.2lf s\\n\" ";

$def[2] .= "DEF:children_user_time=$RRDFILE[4]:$DS[1]:MAX ";
$def[2] .= "LINE1:children_user_time#308400:\"childr. user time \" ";
$def[2] .= "GPRINT:children_user_time:LAST:\" last\: %8.2lf s\" ";
$def[2] .= "GPRINT:children_user_time:MAX:\"max\: %8.2lf s \" ";
$def[2] .= "GPRINT:children_user_time:AVERAGE:\"avg\: %8.2lf s\\n\" ";

$def[2] .= "DEF:children_system_time=$RRDFILE[5]:$DS[1]:MAX ";
$def[2] .= "LINE1:children_system_time#303400:\"childr. system time\" ";
$def[2] .= "GPRINT:children_system_time:LAST:\"last\: %8.2lf s\" ";
$def[2] .= "GPRINT:children_system_time:MAX:\"max\: %8.2lf s \" ";
$def[2] .= "GPRINT:children_system_time:AVERAGE:\"avg\: %8.2lf s\\n\" ";
}

?>
