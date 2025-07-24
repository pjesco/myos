#ifndef _KERNEL_PGTABLE_H
#define _KERNEL_PGTABLE_H

#include <stdint.h>

void initialize_pgtable(uint32_t* page_table);

#endif