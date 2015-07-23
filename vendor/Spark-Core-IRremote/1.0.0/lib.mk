libdir := $(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))/src
INCLUDE_FILES ?=

INCLUDE_FILES += $(libdir)/IRremote.h
INCLUDE_FILES += $(libdir)/IRremote.cpp

default:
	@ echo $(INCLUDE_FILES)

