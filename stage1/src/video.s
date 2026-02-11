; Copyright 2026 dywoq
; 
; This code is published under Apache License 2.0:
; http://www.apache.org/licenses/LICENSE-2.0
; 
; The repository:
; https://github.com/dywoq/zero

%ifndef STAGE1_VIDEO_S
%define STAGE1_VIDEO_S

; Setups video.
; 
; Parameters: None
; Returns: None
; Registers affected: AX
video_setup:
    mov ax, 0x03
    int 0x10
    ret

%endif