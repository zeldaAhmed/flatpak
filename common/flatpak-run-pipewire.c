/* vi:set et sw=2 sts=2 cin cino=t0,f0,(0,{s,>2s,n-s,^-s,e-s:
 * Copyright © 2026 Para-Real Ltd-
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 *
 * Authors:
 *       Zelda Ahmed <zahmed@gnome.org>
 */

#include "config.h"
#include "flatpak-run-pipewire-private.h"

#include "flatpak-utils-private.h"

/* 1. Enumerate all possible pipewire conf files https://docs.pipewire.org/page_daemon.html,
   *   WIll require also potentially looking at env vars for config file overrides and prioritising those?
   *     https://docs.pipewire.org/page_man_pipewire_conf_5.html
   * 2. Look over each file, find `core.name` inside of `context.properties`
   * 3. If `core.name` in is found, this is one of the socket names that *should* be mounted
   * 4. Find `libpipewire-module-protocol-native` and enumerate all listed sockets it uses.
   * 5. For all found socket names, check they actually exist (they may not if the config files
   * files weren't setup properly!) - if it doesnt, warn and exit.
   * 6. If the sockets exist, attempt to mount in bwrap. Hey presto, the apps now have access
   *    to pipewire directly instead of through a proxy, and we can use appd to configure their permissions!
   */

static char *
get_pipewire_config_path_from_env_vars (void)
{
  const char * pipewire_config_dir;
  const char * pipewire_config_prefix;
  const char * pipewire_config_name;

  /* We need both the prefix and name to be set to be able to use
   * a custom config file set using envvars.*/
  pipewire_config_prefix = g_strdup (g_getenv ("PIPEWIRE_CONFIG_PREFIX"));
  pipewire_config_name = g_strdup (g_getenv ("PIPEWIRE_CONFIG_NAME"));

  if (pipewire_config_name && pipewire_config_prefix)
    {

    }
}

static char *
get_pipewire_config_path (void)
{
  staitc const char * config_paths[] =
  {
    "/etc/pipewire/pipewire.conf",
    "/usr/share/pipewire/pipewire.conf",
  }

  g_autofree char *pipewire_user_config = NULL;
}

static char *
get_pipewire_socket_path (void)
{
  g_autofree char *user_runtime_dir = flatpak_get_real_xdg_runtime_dir ();

  /* return g_build_filename (user_runtime_dir, PW_SOCKET_NAME, NULL); */
}

void
flatpak_run_add_pipewire_args (FlatpakBwrap *bwrap)
{
  g_autofree char *pipewire_socket = get_pipewire_socket_path ();

  if (!g_file_test (pipewire_socket, G_FILE_TEST_EXISTS))
    {
      flatpak_bwrap_add_args (bwrap,
                              "--ro-bind", pipewire_socket, pipewire_socket,
                              NULL);
      return;
    }
  else
    {
      g_info ("Could not find pipewire socket.");
    }
}
