PROGRAM_NAME=slapt-get
VERSION=0.9.6h
ARCH=i386
RELEASE=1
CC=gcc
CURLFLAGS=`curl-config --libs`
OBJS=src/configuration.o src/package.o src/curl.o src/transaction.o src/action.o src/main.o
RCDEST=/etc/slapt-getrc
RCSOURCE=example.slapt-getrc
SBINDIR=/sbin/
DEFINES=-DPROGRAM_NAME="\"$(PROGRAM_NAME)\"" -DVERSION="\"$(VERSION)\"" -DRC_LOCATION="\"$(RCDEST)\""
CFLAGS=-W -Werror -Wall -O2 -ansi -pedantic -Iinclude $(DEFINES)

default: $(PROGRAM_NAME)

all: pkg

$(OBJS): 

$(PROGRAM_NAME): $(OBJS)
	$(CC) -o $(PROGRAM_NAME) $(OBJS) $(CFLAGS) $(CURLFLAGS)

static: $(OBJS)
	$(CC) -o $(PROGRAM_NAME) $(OBJS) $(CFLAGS) $(CURLFLAGS) -static

install: $(PROGRAM_NAME)
	install $(PROGRAM_NAME) $(SBINDIR)
	install --mode=0644 -b $(RCSOURCE) $(RCDEST)
	install $(PROGRAM_NAME).8 /usr/man/man8/
	install -d /var/$(PROGRAM_NAME)

uninstall:
	-rm /sbin/$(PROGRAM_NAME)
	-@echo leaving $(RCDEST)

clean:
	-if [ -f $(PROGRAM_NAME) ]; then rm $(PROGRAM_NAME);fi
	-rm src/*.o
	-if [ -d pkg ]; then rm -rf pkg ;fi

pkg: $(PROGRAM_NAME)
	-@mkdir pkg
	-@mkdir -p pkg/sbin
	-@mkdir -p pkg/etc
	-@mkdir -p pkg/install
	-@mkdir -p pkg/usr/man/man8
	-@cp $(PROGRAM_NAME) ./pkg/sbin/
	-@cp example.slapt-getrc ./pkg/etc/slapt-getrc.new
	-@mkdir -p ./pkg/usr/doc/$(PROGRAM_NAME)-$(VERSION)/
	-@cp COPYING Changelog INSTALL README FAQ TODO ./pkg/usr/doc/$(PROGRAM_NAME)-$(VERSION)/
	-@echo "if [ ! -f etc/slapt-getrc ]; then mv etc/slapt-getrc.new etc/slapt-getrc; else diff -q etc/slapt-getrc etc/slapt-getrc.new >/dev/null 2>&1 && rm etc/slapt-getrc.new; fi" > pkg/install/doinst.sh
	-@cp slack-desc pkg/install/
	-@cp slack-required pkg/install/
	-@cp $(PROGRAM_NAME).8 pkg/usr/man/man8/
	@( cd pkg; makepkg -c y $(PROGRAM_NAME)-$(VERSION)-$(ARCH)-$(RELEASE).tgz )

