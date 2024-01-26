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
static unsigned int doubleclicktimeout = 300;
static unsigned int tripleclicktimeout = 600;
int allowaltscreen = 1;
static double minlatency = 8;
static double maxlatency = 33;
static unsigned int blinktimeout = 0;
int ximspot_update_interval = 1000;
static unsigned int cursorthickness = 2;
const int boxdraw = 1;
const int boxdraw_bold = 1;
const int boxdraw_braille = 1;
static int bellvolume = 0;
char *termname = "st";
unsigned int tabspaces = 4;
float alpha = 1.0;

static const char *colorname[] = {
    "#3B4252", "#BF616A", "#A3BE8C", "#EBCB8B", "#81A1C1", "#B48EAD", "#88C0D0",
    "#E5E9F0", "#4C566A", "#BF616A", "#A3BE8C", "#EBCB8B", "#81A1C1", "#B48EAD",
    "#8FBCBB", "#ECEFF4", [255] = 0, "#D8DEE9", "#2E3440",
};

unsigned int defaultfg = 256;
unsigned int defaultbg = 257;
unsigned int defaultcs = 256;
static unsigned int defaultrcs = 256;
static unsigned int cursorshape = 2;
static unsigned int cols = 80;
static unsigned int rows = 24;
static unsigned int mouseshape = XC_xterm;
static unsigned int mousefg = 7;
static unsigned int mousebg = 0;
static unsigned int defaultattr = 11;
const unsigned int mousescrollincrement = 3;

MouseKey mkeys[] = {
    {Button4, XK_NO_MOD, kscrollup, {.i = mousescrollincrement}},
    {Button5, XK_NO_MOD, kscrolldown, {.i = mousescrollincrement}}};

static Shortcut shortcuts[] = {
    {ControlMask | ShiftMask, XK_V, clippaste, {.i = 0}},
};

static KeySym mappedkeys[] = {-1};
static uint ignoremod = Mod2Mask | XK_SWITCH_MOD;
static uint forceselmod = ShiftMask;

static Key key[] = {{XK_Up, XK_ANY_MOD, "\033[A", 0, -1},
                    {XK_Up, XK_ANY_MOD, "\033OA", 0, +1},
                    {XK_Down, XK_ANY_MOD, "\033[B", 0, -1},
                    {XK_Down, XK_ANY_MOD, "\033OB", 0, +1},
                    {XK_Left, XK_ANY_MOD, "\033[D", 0, -1},
                    {XK_Left, XK_ANY_MOD, "\033OD", 0, +1},
                    {XK_Right, XK_ANY_MOD, "\033[C", 0, -1},
                    {XK_Right, XK_ANY_MOD, "\033OC", 0, +1},
                    {XK_BackSpace, XK_NO_MOD, "\177", 0, 0}};

static uint selmasks[] = {
    [SEL_RECTANGULAR] = Mod1Mask,
};

static char ascii_printable[] = " !\"#$%&'()*+,-./0123456789:;<=>?"
                                "@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_"
                                "`abcdefghijklmnopqrstuvwxyz{|}~";
