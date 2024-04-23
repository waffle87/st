VERSION = 0.9
PREFIX = /usr/local

DEPS = fontconfig wayland-client wayland-cursor xkbcommon pixman-1
XDG_SHELL_PROTO = `pkg-config --variable=pkgdatadir wayland-protocols`/stable/xdg-shell/xdg-shell.xml

INCS = -I. -I/usr/include `pkg-config --cflags ${DEPS}`
LIBS = -L/usr/lib -lc -lm -lrt -lutil `pkg-config --libs ${DEPS}`

CFLAGS += -g -std=c99 -pedantic -Wall -Wvariadic-macros -Os
LDFLAGS += lib/wld/libwld.a -g ${LIBS}
STCPPFLAGS = -DVERSION=\"$(VERSION)\" -D_XOPEN_SOURCE=600
STCFLAGS = $(INCS) $(STCPPFLAGS) $(CFLAGS)
STLDFLAGS = $(LIBS) $(LDFLAGS)

SRC = st.c wl.c xdg-shell-protocol.c
OBJ = $(SRC:.c=.o)

all: wld st

xdg-shell-protocol.c:
	@echo GEN $@
	@wayland-scanner private-code $(XDG_SHELL_PROTO) $@

xdg-shell-client-protocol.h:
	@echo GEN $@
	@wayland-scanner client-header $(XDG_SHELL_PROTO) $@

.c.o:
	$(CC) $(STCFLAGS) -c $<

st.o: st.h win.h
wl.o: arg.h st.h win.h config.h xdg-shell-client-protocol.h

$(OBJ): config.h

st: $(OBJ)
	$(CC) -o $@ $(OBJ) $(STLDFLAGS)

wld:
	make -C lib/wld DRM_DRIVERS=intel

clean:
	rm -f st $(OBJ) xdg-shell-*
	make -C lib/wld clean

install: st
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp -f st $(DESTDIR)$(PREFIX)/bin
	chmod 755 $(DESTDIR)$(PREFIX)/bin/st

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/st
