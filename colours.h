// Copyright 2024 jack@pngu.org
// SPDX-License-Identifier: MIT/X
#pragma once

static const char *colorname[] = {
#if COLOUR_SCHEME == nord
    "#3B4252", "#BF616A", "#A3BE8C", "#EBCB8B", "#81A1C1", "#B48EAD", "#88C0D0",
    "#E5E9F0", "#4C566A", "#BF616A", "#A3BE8C", "#EBCB8B", "#81A1C1", "#B48EAD",
    "#8FBCBB", "#ECEFF4", [255] = 0, "#D8DEE9", "#2E3440",
#elif COLOUR_SCHEME == solarized
    "#073642", "#dc322f", "#859900", "#b58900", "#268bd2", "#d33682",
    "#2aa198", "#eee8d5", "#002b36", "#cb4b16", "#586e75", "#657b83",
    "#839496", "#6c71c4", "#93a1a1", "#fdf6e3"
#elif COLOUR_SCHEME == gruvbox
    "#1d2021", "#cc241d", "#98971a", "#d79921", "#458588", "#b16286",
    "#689d6a", "#a89984", "#928374", "#fb4934", "#b8bb26", "#fabd2f",
    "#83a598", "#d3869b", "#8ec07c", "#ebdbb2"
#endif
};
