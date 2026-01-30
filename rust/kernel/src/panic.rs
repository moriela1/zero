use core::panic::PanicInfo;
use uefi::println;

/// A custom panic handler, used across bootloader.
///
/// # Note
///
/// If you get:
/// `found duplicate lang item panic_impl`
///
/// You may ignore it.
/// It doesn't affect the compilation.
#[panic_handler]
pub fn panic_impl(info: &PanicInfo) -> ! {
    println!("panic {}", info);
    loop {}
}
