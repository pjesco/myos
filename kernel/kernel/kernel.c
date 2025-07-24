#include <stdio.h>

#include <kernel/tty.h>
#include <kernel/pgdirectory.h>
#include <kernel/pgtable.h>

uint32_t page_directory[1024] __attribute__((aligned(4096)));
uint32_t first_page_table[1024] __attribute__((aligned(4096)));

void kernel_main(void) {
	initialize_pgdirectory(page_directory);
	initialize_pgtable(first_page_table);

	page_directory[0] = ((unsigned int)first_page_table) | 3; // attributes: supervisor level, read/write, present

	loadPageDirectory(page_directory);
	enablePaging();

	terminal_initialize();
	printf("Hello, Paging World!\n");
}
