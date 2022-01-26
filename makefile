
CC = gcc

CPPFLAGS += -D _GNU_SOURCE
CPPFLAGS += -I .
CPPFLAGS += -isystem ./extern

CFLAGS += -m32 -Wall -Werror -Wfatal-errors

LDFLAGS += -m32

LDLIBS += -lm

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
CPPFLAGS += -D 'dpvo(_)='
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

asm ?= quiet
#asm ?= verbose

ifeq ($(asm), verbose)
CPPFLAGS += -D ASM_VERBOSE
else ifeq ($(asm), quiet)
CPPFLAGS += -D ASM_QUIET
else
$(error "invalid asm option!");
endif

on_error ?= do_nothing

ifeq ($(on_error), do_nothing)
ON_ERROR =
else ifeq ($(on_error), open_editor)
ON_ERROR += || ($$EDITOR $<; false)
else
$(error "invalid on_error option!");
endif

buildprefix = gen/$(asm)-asm/$(buildtype)-build

default: $(buildprefix)/interpreter
	@ ln -svf $<

ARGS += -s

#ARGS += -i ./examples/test.il
#ARGS += -i ./examples/external.il

#ARGS += -i ./examples/arrayparam.il
#ARGS += -i ./examples/arrayparam.oil
#ARGS += -i ./examples/bubble.il
#ARGS += -i ./examples/bubble.oil
#ARGS += -i ./examples/check.il
#ARGS += -i ./examples/check.oil
#ARGS += -i ./examples/dynamic.il
#ARGS += -i ./examples/dynamic.oil
#ARGS += -i ./examples/fib.il
#ARGS += -i ./examples/fib.oil
#ARGS += -i ./examples/gcd.il
#ARGS += -i ./examples/gcd.oil
#ARGS += -i ./examples/helloworld.il
#ARGS += -i ./examples/helloworld.oil
#ARGS += -i ./examples/newdyn.il
#ARGS += -i ./examples/newdyn.oil
#ARGS += -i ./examples/qs.il
#ARGS += -i ./examples/qs.oil
#ARGS += -i ./examples/while_array.il
ARGS += -i ./examples/while_array.oil

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
	@ $(CC) -c $(CPPFLAGS) $(ASFLAGS) $./examples/dynamic.il< -MD -o $(buildprefix)/$*.o $(ON_ERROR)

$(buildprefix)/interpreter: $(objs)
	@ echo "linking $@"
	@ $(CC) $(LDFLAGS) $^ $(LOADLIBES) $(LDLIBS) -o $@

clean:
	for l in $$(cat .gitignore); do rm -rvf $$l; done

ifneq "$(MAKECMDGOALS)" "clean"
include $(deps)
endif
















