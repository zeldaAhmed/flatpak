/* vi:set et sw=2 sts=2 cin cino=t0,f0,(0,{s,>2s,n-s,^-s,e-s:
 * flatpak-run-pipewire-private.h
 *
 * Copyright 2026 Zelda Ahmed <zoeyahmed10@proton.me>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#pragma once

#include "libglnx.h"

#include "flatpak-bwrap-private.h"
#include "flatpak-common-types-private.h"
#include "flatpak-context-private.h"

G_BEGIN_DECLS

void
flatpak_run_add_pipewire_args (FlatpakBwrap         *bwrap);

G_END_DECLS
