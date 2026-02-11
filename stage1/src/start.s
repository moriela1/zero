; Copyright 2026 dywoq
; 
; This code is published under Apache License 2.0:
; http://www.apache.org/licenses/LICENSE-2.0
; 
; The repository:
; https://github.com/dywoq/zero

bits 16
org 0x8000

; Represents the entry of stage 1, which setups necessary components,
; and enters protected mode, starting kernel.
_start:
    cli
    xor ax, ax ; Make sure AX is always zero
    mov ds, ax ; Data segment
    mov es, ax ; Extra segment
    mov ss, ax ; Stack segment
    mov sp, 0x9000 ; Set stack pointer at 0x9000
    sti

    call a20_setup
    call video_setup

    ; Load kernel DPA
kernel_dap:
    db 0x10 ; Size of DAP
    db 0 ; Unused
    dw 8 ; How much sectors we read (512 bytes = 1 sector. If kernel grows, we adjust it)
    dw 0x0000 ; Offset
    dw 0x1000 ; Segment
    dq 2 ; Lower bits of LBA address
    
    ; Load kernel.bin from disk
    mov ah, 0x42       ; Extended read
    mov dl, 0x80       ; 0x80 = First HDD
    mov si, kernel_dap ; Load kernel DAP
    int 0x13           ; Call BIOS

    ; Load GDT pointer and jump to protected mode
    cli
    lgdt [gdt_ptr]
    mov eax, cr0
    or eax, 1
    mov cr0, eax
    jmp 0x08:pm_start

bits 32
pm_start:
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    mov esp, 0x90000

    ; Jump to kernel ;>
    jmp 0x10000

bits 32
%include "src/gdt.s"

bits 16
%include "src/a20.s"
%include "src/video.s"

times 512-($-$$) db 0
