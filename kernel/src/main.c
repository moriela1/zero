void _start() {
    __asm volatile("mov $65, %al\n"
                   "mov $0x0E, %ah\n"
                   "int $0x10\n");
    while (1)
        ;
}
