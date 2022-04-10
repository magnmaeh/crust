CC := gcc
PROJECT_NAME := cserver
BUILDDIR := build
SOURCE := $(shell find src -name "*.c") 

all:
	mkdir -p $(BUILDDIR)
	$(CC) $(SOURCE) -o $(BUILDDIR)/$(PROJECT_NAME).elf

.PHONY: clean
clean: 
	rm -rf $(BUILDDIR)