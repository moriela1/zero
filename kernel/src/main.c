[[noreturn]]
void
_start() {
    while (true) {
        __asm volatile("hlt");
    }
}
