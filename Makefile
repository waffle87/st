PREFIX = /usr

DEPS = wayland-client wayland-cursor xkbcommon wld
XDG_SHELL_PROTO = `pkg-config --variable=pkgdatadir wayland-protocols`/stable/xdg-shell/xdg-shell.xml
WLD_FLAGS = DRM_DRIVERS=intel PREFIX=/usr

LDFLAGS = -L/usr/lib -lc -lm -lrt -lutil `pkg-config --libs ${DEPS}`
CFLAGS = -I. -I/usr/include `pkg-config --cflags ${DEPS}` \
         -DVERSION=\"0.9\" -D_XOPEN_SOURCE=600


SRC = st.c wl.c xdg-shell-protocol.c
OBJ = $(SRC:.c=.o)

ifeq ($(if $(V),$(V),0), 0)
	define quiet
        @echo "  $1	$@"
        @$(if $2,$2,$($1))
    endef
else
    quiet = $(if $2,$2,$($1))
endif

all: wld st

xdg-shell-protocol.c:
	$(call quiet,GEN)
	@wayland-scanner private-code $(XDG_SHELL_PROTO) $@

xdg-shell-client-protocol.h:
	$(call quiet,GEN)
	@wayland-scanner client-header $(XDG_SHELL_PROTO) $@

.c.o:
	$(call quiet,CC) $(CFLAGS) -c $<

st.o: st.h win.h
wl.o: arg.h st.h win.h config.h xdg-shell-client-protocol.h

$(OBJ): config.h

st: $(OBJ)
	$(call quiet,CCLD,cc) -o $@ $(OBJ) $(LDFLAGS)

wld:
	make -sC lib/wld ${WLD_FLAGS}

clean:
	rm -f st $(OBJ) xdg-shell-*
	make -C lib/wld clean

install: st
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp -f st $(DESTDIR)$(PREFIX)/bin
	chmod 755 $(DESTDIR)$(PREFIX)/bin/st

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/st
