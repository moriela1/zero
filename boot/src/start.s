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
    db 0x10        ; size of DAP
    db 0x00        ; reserved
    dw 8           ; sectors
    dw 0x0000      ; offset
    dw 0x1000      ; segment
    dq 0x00000001 


times 510-($-$$) db 0
dw 0xaa55
