CC := gcc
BUILDDIR := build
SOURCE := $(shell find src -name "*.c") 
LIBOBJ := $(patsubst %.c,%.o, $(patsubst src/%,%, $(SOURCE)))

.PHONY: all clean lib dir
all: dir
	$(CC) $(SOURCE) -o $(BUILDDIR)/$(PROJECT_NAME).elf $(LIB_LOC) $(LINKS)

lib: dir
	$(CC) $(SOURCE) -c -o $(BUILDDIR)/$(LIBOBJ)
	ar -cvq $(BUILDDIR)/$(PROJECT_NAME).a $(BUILDDIR)/*.o

clean: 
	rm -rf $(BUILDDIR)

dir:
	mkdir -p $(BUILDDIR)