/*
 * Copyright (C) 2003,2004,2005 Jason Woodward <woodwardj at jaos dot org>
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

struct head_data_t {
  char *data;
  size_t size;
};

/* this is the main download routine */
int download_data(FILE *fh,const char *url,size_t bytes,
                  const rc_config *global_config);
char *head_request(const char *url);

/*
  this fills FILE with data from url, used for PACKAGES.TXT and CHECKSUMS
*/
int get_mirror_data_from_source(FILE *fh,const rc_config *global_config,
                                const char *base_url,const char *filename);

/* download pkg, calls download_data */
int download_pkg(const rc_config *global_config,pkg_info_t *pkg);

/* callback for curl progress */
char spinner(void);
int progress_callback(void *clientp, double dltotal, double dlnow,
                      double ultotal, double ulnow);

