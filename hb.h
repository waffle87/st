// Copyright 2024 jack@pngu.org
// SPDX-License-Identifier: MIT/X
#pragma once

#include <X11/Xft/Xft.h>
#include <hb-ft.h>
#include <hb.h>

void hbunloadfonts();
void hbtransform(XftGlyphFontSpec *, const Glyph *, size_t, int, int);
