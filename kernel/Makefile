CC := gcc
CFLAGS := -m32 \
          -ffreestanding \
          -Iinc/ \
          -Wall -Wextra \
          -fno-pie -fno-pic \
          --std=c23

LD := ld
LD_FLAGS := -m elf_i386 -T linker.ld

BUILD := .build
OBJ_DIR := $(BUILD)/obj

SRCS := $(shell find src -name '*.c')
OBJS := $(patsubst src/%, $(OBJ_DIR)/%, $(SRCS:.c=.o))

TARGET := $(BUILD)/kernel.bin

all: $(BUILD) $(TARGET)

$(TARGET): $(OBJS)
	@echo "lumen_kernel: linking $@"
	@$(LD) $(LD_FLAGS) $(OBJS) -o $@
	@echo "lumen_kernel: successfully built $@!!"

$(OBJS): $(OBJ_DIR)/%.o : src/%.c
	@echo "lumen_kernel: building $< into $@"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(BUILD):
	@echo "lumen_kernel: creating build directory $(BUILD)"
	@mkdir -p $(OBJ_DIR)

clean:
	@echo "lumen_kernel: removing build directory $(BUILD)"
	@rm -rf $(BUILD)
