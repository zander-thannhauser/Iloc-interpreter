
CC = gcc

CPPFLAGS += -D _GNU_SOURCE
CPPFLAGS += -I .
CPPFLAGS += -isystem ./extern

CFLAGS += -m32 -Wall -Werror -Wfatal-errors

LDFLAGS += -m32

FINDFLAGS ?= -name '*.c'

buildtype ?= release

ifeq ($(buildtype), release)
CPPFLAGS += -D RELEASE
CPPFLAGS += -D ENTER=
CPPFLAGS += -D HERE=
CPPFLAGS += -D EXIT=
CPPFLAGS += -D 'dpv(_)='
CPPFLAGS += -D 'dpvc(_)='
CPPFLAGS += -D 'dpvb(_)='
CPPFLAGS += -D 'dpvs(_)='
CPPFLAGS += -D 'dpvsn(_, __)='
CPPFLAGS += -D 'ddprintf(...)='
CPPFLAGS += -D TODO='assert(!"TODO")'
CPPFLAGS += -D CHECK='assert(!"CHECK")'

CFLAGS += -O2 # causes problems?!
CFLAGS += -flto

LDFLAGS += -flto=auto
else ifeq ($(buildtype), test)
CPPFLAGS += -D TESTING

CFLAGS += -include debug.h
CFLAGS += -g
CFLAGS += -Wno-unused-variable
CFLAGS += -Wno-unused-function
CFLAGS += -Wno-unused-but-set-variable
else ifeq ($(buildtype), debug)
CPPFLAGS += -D DEBUGGING

CFLAGS += -include debug.h
CFLAGS += -g
CFLAGS += -Wno-unused-variable
CFLAGS += -Wno-unused-function
CFLAGS += -Wno-unused-but-set-variable
else
$(error "invalid buildtype!");
endif

link ?= dynamic
#link ?= static

ifeq ($(link), static)
CPPFLAGS += -D STATIC_LINK
LDFLAGS += -static
LDFLAGS += -fwhole-program
else ifeq ($(link), dynamic)
CPPFLAGS += -D DYNAMIC_LINK
else
$(error "invalid link value!");
endif

libc ?= system
#libc ?= local

ifeq ($(libc), system)
CPPFLAGS += -D SYSTEM_LIBC

LDLIBS += -lm

FINDFLAGS += -! -path './extern/zlibc/*'
else ifeq ($(libc), local)
CPPFLAGS += -D LOCAL_LIBC
CPPFLAGS += -nostdinc
CPPFLAGS += -isystem ./extern/zlibc

CFLAGS += -fno-stack-protector

LDFLAGS += -Wno-free-nonheap-object
LDFLAGS += -nostdlib -nodefaultlibs

FINDFLAGS += -or -name '*.S'
else
$(error "invalid libc option!");
endif

on_error ?= do_nothing

ifeq ($(on_error), do_nothing)
ON_ERROR =
else ifeq ($(on_error), open_editor)
ON_ERROR += || ($$EDITOR $<; false)
else
$(error "invalid libc option!");
endif

buildprefix = gen/$(buildtype)-build/$(link)-link/$(libc)-libc

default: $(buildprefix)/interpreter

#ARGS += -v
#ARGS += -d
ARGS += -s

#ARGS += -i ./examples/test.il

#ARGS += -i ./examples/arrayparam.il  # working
#ARGS += -i ./examples/bubble.il      # working
#ARGS += -i ./examples/check.dbre.il  # working
#ARGS += -i ./examples/check.il       # working
#ARGS += -i ./examples/dynamic.il     # doesn't work
#ARGS += -i ./examples/fib.il         # working
#ARGS += -i ./examples/gcd.il         # working
ARGS += -i ./examples/helloworld.il  # working
#ARGS += -i ./examples/newdyn.il      # doesn't work
#ARGS += -i ./examples/qs.il          # working
#ARGS += -i ./examples/while_array.il # working

run: $(buildprefix)/interpreter
	$< $(ARGS)

gdbrun: $(buildprefix)/interpreter
	gdb $<

valrun: $(buildprefix)/interpreter
	valgrind $< $(ARGS)

valrun-stop: $(buildprefix)/interpreter
	valgrind --gen-suppressions=yes -- $< ${ARGS}

valrun-leak: $(buildprefix)/interpreter
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -- $< ${ARGS}

tracerun: $(buildprefix)/interpreter
	strace $< $(ARGS)

.PRECIOUS: %/

%/:
	@ mkdir -p $@

gen/%/srclist.mk: | gen/%/
	@ echo "searching for source files..."
	@ find $(FINDFLAGS) | sort -Vr | sed 's/^/srcs += /' > $@

ifneq "$(MAKECMDGOALS)" "clean"
include $(buildprefix)/srclist.mk
endif

objs := $(patsubst %.c,$(buildprefix)/%.o,$(srcs))
objs := $(patsubst %.S,$(buildprefix)/%.o,$(objs))

deps := $(patsubst %.c,$(buildprefix)/%.d,$(srcs))
deps := $(patsubst %.S,$(buildprefix)/%.d,$(deps))

$(buildprefix)/%.o $(buildprefix)/%.d: %.c | $(buildprefix)/%/
	@ echo "compiling $<"
	@ $(CC) -c $(CPPFLAGS) $(CFLAGS) $< -MD -o $(buildprefix)/$*.o $(ON_ERROR)

$(buildprefix)/%.o $(buildprefix)/%.d: %.S | $(buildprefix)/%/
	@ echo "assembling $<"
	@ $(CC) -c $(CPPFLAGS) $(ASFLAGS) $< -MD -o $(buildprefix)/$*.o $(ON_ERROR)

$(buildprefix)/interpreter: $(objs)
	@ echo "linking $@"
	@ $(CC) $(LDFLAGS) $^ $(LOADLIBES) $(LDLIBS) -o $@

clean:
	for l in $$(cat .gitignore); do rm -rvf $$l; done

ifneq "$(MAKECMDGOALS)" "clean"
include $(deps)
endif
















