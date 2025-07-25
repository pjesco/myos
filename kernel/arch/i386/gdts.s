#global gdt_flush

#gdt_flush:
#    MOV eax, [esp+4]
#    LGDT [eax]

#    MOV eax, 0x10
#    MOV ds, ax
#    MOV es, ax
#    MOV fs, ax
#    MOV gs, ax
#    MOV ss, ax
#    JMP 0x08:.flush
#.flush:
#    RET

.globl gdt_flush

gdt_flush:
    mov 4(%esp), %eax
    lgdt (%eax)

    mov $0x10, %eax
    mov %ax, %ds
    mov %ax, %es
    mov %ax, %fs
    mov %ax, %gs
    mov %ax, %ss
    jmp $0x08, $flush
flush:
    ret