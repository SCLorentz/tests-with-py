.global write_asm
write_asm:
    mov x0, 1
    mov x8, 64
    svc #0
    ret
