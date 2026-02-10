START := src/start.s

ASM := nasm
ASM_FLAGS := -f bin

BUILD := .build

TARGET := $(BUILD)/boot.bin

all: $(TARGET)

$(TARGET): $(BUILD)
	@$(ASM) $(ASM_FLAGS) $(START) -o $(TARGET)
	@echo "zero_stage0: built $(TARGET)"

$(BUILD):
	@mkdir $(BUILD) -p
	@echo "zero_stage0: created $(BUILD) directory"
	
clean:
	@rm $(BUILD) -fr
	@echo "zero_stage0: removed $(BUILD) directory"
