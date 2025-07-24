#include <kernel/pgtable.h>

void initialize_pgtable(uint32_t* page_table) {
    unsigned int i;
    for (i = 0; i < 1024; i++) {
        page_table[i] = (i * 0x1000) | 3; // attributes: supervisor level, read/write, present.
    }
}