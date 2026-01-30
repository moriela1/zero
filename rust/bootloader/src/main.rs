#![no_main]
#![no_std]

pub(crate) mod panic;

use uefi::{Status, entry};

#[entry]
fn main() -> Status {
    uefi::helpers::init().unwrap();
    Status::SUCCESS
}
