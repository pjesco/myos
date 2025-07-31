#ifndef _KERNEL_EXCEPTIONHANDLER_H
#define _KERNEL_EXCEPTIONHANDLER_H

__attribute__((noreturn))
void exception_handler(void);
void exception_handler() {
    __asm__ volatile ("cli; hlt");
}

#endif