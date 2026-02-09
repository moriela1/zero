; Copyright 2026 dywoq
; 
; This code is published under Apache License 2.0:
; http://www.apache.org/licenses/LICENSE-2.0
; 
; The repository:
; https://github.com/dywoq/zero

%ifndef STAGE1_A20_S
%define STAGE1_A20_S

; Turns on A20 line.
; 
; Parameters: None
; Returns: None
; Registers affected: AL
a20_setup:
    ; Use fast gate to turn A20 line
    in al, 0x92
    or al, 2
    out 0x92, al
    ret

%endif