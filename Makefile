ARCH ?= x86_64
BUILD_TYPE ?= debug

build:
	BUILD_TYPE=$(BUILD_TYPE) lua ./scripts/building/$(ARCH).lua
