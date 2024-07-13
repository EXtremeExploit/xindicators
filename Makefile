LIBNAME = xindicators
TARGET = $(LIBNAME).so

# Support luajit and check for it
LUA = $(shell basename "$$(command -v luajit || command -v lua)")

ifeq ($(LUA),)
$(error Please install luajit or lua)
endif 

PKGS      = x11 $(LUA)

INCS     := $(shell pkg-config --cflags --print-errors $(PKGS))
CFLAGS   := -std=gnu99 -ggdb -W -Wall -Wextra -Werror -fPIC -pedantic $(INCS) $(CFLAGS)

LIBS     := $(shell pkg-config --libs --print-errors $(PKGS))
LDFLAGS  := $(LIBS) $(LDFLAGS) $(LIBFLAG) -Wl,--export-dynamic --shared

SRCS  = $(wildcard *.c)
HEADS = $(wildcard *.h)
OBJS  = $(foreach obj,$(SRCS:.c=.o),$(obj))

$(TARGET): $(OBJS)
	@$(CC) -o $@ $(OBJS) $(LDFLAGS)

print-lua:
	echo $(LUA)

clean:
	rm -f $(TARGET) $(OBJS)

test:
	lua -e "require('$(LIBNAME)')"

install: $(TARGET)
	cp $(TARGET) $(INST_LIBDIR)

all: $(TARGET)
