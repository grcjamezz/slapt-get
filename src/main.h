/*
 * Copyright (C) 2003 Jason Woodward <woodwardj at jaos dot org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Library General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

/* std includes */
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include <curl/curl.h>
#include <curl/types.h>
#include <curl/easy.h>
#include <regex.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <ctype.h>
#include <openssl/evp.h>
/* */

/* local includes */
#include "configuration.h"
#include "package.h"
#include "curl.h"
#include "action.h"
/* */

/* function defs */
void usage(void);
void version_info(void);
/* */

/* variable defs */
/* */

#define DEBUG 0
#define PKG_LIST "PACKAGES.TXT"
#define PKG_LIST_L "package_data_list"
#define PATCHES_LIST "FILE_LIST"
#define PATCHES_LIST_L "patches_list"
#define PATCHDIR "patches/"
#define REMOVE_CMD "/sbin/removepkg "
#define INSTALL_CMD "/sbin/installpkg "
#define UPGRADE_CMD "/sbin/upgradepkg "
#define CHECKSUM_FILE "CHECKSUMS.md5"

