#ifndef _KERNEL_PGDIRECTORY_H
#define _KERNEL_PGDIRECTORY_H

#include <stdint.h>

void initialize_pgdirectory(uint32_t* page_directory);
extern void loadPageDirectory(uint32_t*);
extern void enablePaging();

#endif