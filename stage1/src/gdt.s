; Copyright 2026 dywoq
; 
; This code is published under Apache License 2.0:
; http://www.apache.org/licenses/LICENSE-2.0
; 
; The repository:
; https://github.com/dywoq/zero

%ifndef STAGE1_GDT_S
%define STAGE1_GDT_S

gdt_start:
gdt_null:
    dq 0
gdt_code:
    dw 0xFFFF
    dw 0x0000
    db 0x00
    db 10011010b
    db 11001111b
    db 0x00
gdt_data:
    dw 0xFFFF
    dw 0x0000
    db 0x00
    db 10010010b
    db 11001111b
    db 0x00
gdt_end:

gdt_ptr:
    dw gdt_end - gdt_start - 1
    dd gdt_start


%endif