PREFIX = /usr

COLOUR_SCHEME ?= nord

DEPS = fontconfig harfbuzz

CFLAGS = -I/usr/X11R6/include `pkg-config --cflags ${DEPS}` \
         -DVERSION=\"0.9\" -D_XOPEN_SOURCE=700

LDFLAGS = -L/usr/X11R6/lib -lm -lX11 -lXft \
          `pkg-config --libs ${DEPS}`

SRC = st.c x.c boxdraw.c hb.c
OBJ = $(SRC:.c=.o)

all: st

.c.o:
	cc $(CFLAGS) -c $<

st.o: config.h st.h win.h
x.o: arg.h config.h st.h win.h hb.h
hb.o: st.h
boxdraw.o: config.h st.h boxdraw_data.h

$(OBJ): config.h

st: $(OBJ)
	cc -o $@ $(OBJ) $(LDFLAGS)

clean:
	rm -f st $(OBJ) *.orig *.rej

install: st
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp -f st $(DESTDIR)$(PREFIX)/bin
	chmod 755 $(DESTDIR)$(PREFIX)/bin/st

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/st
