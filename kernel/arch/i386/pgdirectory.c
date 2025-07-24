#include <kernel/pgdirectory.h>

void initialize_pgdirectory(uint32_t* page_directory) {
    int i;
    for (i = 0; i < 1024; i++) {
        //Sets following flags
        //  Supervisor: Only kernel access
        //  Write enabled: both rw
        //  Not present: page table not present
        page_directory[i] = 0x00000002;
    }
}

asm(
	".text\n\t"
	".globl loadPageDirectory\n\t"
	"loadPageDirectory:\n\t"
	"push %ebp\n\t"
	"mov %esp, %ebp\n\t"
	"mov 8(%esp), %eax\n\t"
	"mov %eax, %cr3\n\t"
	"mov %ebp, %esp\n\t"
	"pop %ebp\n\t"
	"ret\n\t"
);

asm(
	".text\n\t"
    ".globl enablePaging\n\t"
    "enablePaging:\n\t"
    "push %ebp\n\t"
    "mov %esp, %ebp\n\t"
    "mov %cr0, %eax\n\t"
    "or $0x80000000, %eax\n\t"
    "mov %eax, %cr0\n\t"
    "mov %ebp, %esp\n\t"
    "pop %ebp\n\t"
    "ret\n\t"
);