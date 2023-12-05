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
    "#073642", "#dc322f", "#859900", "#b58900", "#268bd2", "#d33682",
    "#2aa198", "#eee8d5", "#002b36", "#cb4b16", "#586e75", "#657b83",
    "#839496", "#6c71c4", "#93a1a1", "#fdf6e3",
};

unsigned int defaultfg = 12;
unsigned int defaultbg = 8;
unsigned int defaultcs = 14;
static unsigned int defaultrcs = 15;
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
