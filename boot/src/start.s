; Copyright 2026 dywoq
;
; This code is published under Apache License 2.0:
; http://www.apache.org/licenses/LICENSE-2.0
;
; The repository:
; https://github.com/dywoq/zero

bits 16
org 0x7c00

; Represents the bootloader entry, which starts kernel.
_start:
    cli
    xor ax, ax ; Make sure AX is always zero
    mov ds, ax ; Data segment
    mov es, ax ; Extra segment
    mov ss, ax ; Stack segment
    mov sp, 0x7c00 ; Set stack pointer at 0x7c00
    sti

    ; Load kernel.bin from disk
    mov ah, 0x42       ; Extended read
    mov dl, 0x80       ; 0x80 = First HDD
    mov si, kernel_dap ; Load stage 1 DAP
    int 0x13           ; Call BIOS

    ; Jump to kernel
    jmp 0x1000:0x0000

    ; Unreachable
    hlt

kernel_dap:
    db 0 ; Size of DAP
    db 0 ; Unused (I'm not even sure what does this mean...)
    dw 1 ; How much sectors we read (512 bytes = 1 sector. If the stage 1 grows, we adjust it)
    dw 0x0000 ; Offset
    dw 0x1000 ; Segment
    dq 1 ; Lower bits of LBA address

times 510-($-$$) db 0
dw 0xaa55
