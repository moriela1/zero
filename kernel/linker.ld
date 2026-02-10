OUTPUT_FORMAT("binary")
ENTRY(_start)
SECTIONS
{
  . = 0x10000;
  .kernel_init : { KEEP(*(.kernel_init)) }  /* must go first */
  .text : { *(.text) }
  .data : { *(.data) }
  .bss  : { *(.bss)  }
}
