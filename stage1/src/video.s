%ifndef STAGE1_VIDEO_S
%define STAGE1_VIDEO_S

; Setups video.
; 
; Parameters: None
; Returns: None
; Registers affected: AX
video_setup:
    mov ax, 13h
    int 0x10
    ret

%endif