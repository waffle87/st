// Copyright 2024 jack@pngu.org
// SPDX-License-Identifier: MIT/X
#pragma once

static char *font =
    "JetBrainsMono Nerd Font:pixelsize=15:antialias=true:autohint=true";
static int borderpx = 8;
static char *shell = "/bin/zsh";
char *utmp = NULL;
char *stty_args = "stty raw pass8 nl -echo -iexten -cstopb 38400";
char *vtiden = "\033[?6c";
static float cwscale = 1.0;
static float chscale = 1.0;
wchar_t *worddelimiters = L" ";
static uint doubleclicktimeout = 300;
static uint tripleclicktimeout = 600;
int allowaltscreen = 1;

static uint keyrepeatdelay = 500;
static uint keyrepeatinterval = 25;

static uint blinktimeout = 0;
static uint cursorthickness = 2;
char *termname = "st";
uint tabspaces = 4;

static const char *colorname[] = {
    "#3B4252", "#BF616A", "#A3BE8C", "#EBCB8B", "#81A1C1", "#B48EAD", "#88C0D0",
    "#E5E9F0", "#4C566A", "#BF616A", "#A3BE8C", "#EBCB8B", "#81A1C1", "#B48EAD",
    "#8FBCBB", "#ECEFF4", [255] = 0, "#D8DEE9", "#2E3440",
};

uint defaultfg = 256;
uint defaultbg = 257;
static uint defaultcs = 256;
static uint defaultrcs = 256;
static uint cursorshape = 2;
static uint cols = 80;
static uint rows = 24;

static char mouseshape[] = "xterm";
static uint defaultattr = 11;

static MouseShortcut mshortcuts[] = {{-1, MOD_MASK_NONE, ""}};

static Axiskey ashortcuts[] = {
    {AXIS_VERTICAL, +1, MOD_MASK_ANY, "\031"},
    {AXIS_VERTICAL, -1, MOD_MASK_ANY, "\005"},
};

#define TERMMOD MOD_MASK_SHIFT | MOD_MASK_CTRL

static Shortcut shortcuts[] = {
    {TERMMOD, XKB_KEY_C, clipcopy, {.i = 0}},
    {TERMMOD, XKB_KEY_V, clippaste, {.i = 0}},
};

static uint ignoremod = 0;
static uint forceselmod = MOD_MASK_SHIFT;

static Key key[] = {{XKB_KEY_Up, MOD_MASK_ANY, "\033[A", 0, -1},
                    {XKB_KEY_Up, MOD_MASK_ANY, "\033OA", 0, +1},
                    {XKB_KEY_Down, MOD_MASK_ANY, "\033[B", 0, -1},
                    {XKB_KEY_Down, MOD_MASK_ANY, "\033OB", 0, +1},
                    {XKB_KEY_Right, MOD_MASK_ANY, "\033[C", 0, -1},
                    {XKB_KEY_Right, MOD_MASK_ANY, "\033OC", 0, +1},
                    {XKB_KEY_Left, MOD_MASK_ANY, "\033[D", 0, -1},
                    {XKB_KEY_Left, MOD_MASK_ANY, "\033OD", 0, +1},
                    {XKB_KEY_BackSpace, MOD_MASK_NONE, "\177", 0, 0}};

static uint selmasks[] = {
    [SEL_RECTANGULAR] = MOD_MASK_ALT,
};

static char ascii_printable[] = " !\"#$%&'()*+,-./0123456789:;<=>?"
                                "@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_"
                                "`abcdefghijklmnopqrstuvwxyz{|}~";
