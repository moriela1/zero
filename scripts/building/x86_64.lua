-- Copyright 2026 dywoq
--
-- This code is released under the Apache License 2.0:
-- https://www.apache.org/licenses/LICENSE-2.0
--
-- Repository:
-- https://github.com/dywoq/zero

local env = require("scripts.env")
local log = require("scripts.log")
local cmd = require("scripts.cmd")

-- Do env variables check before running program.
env.add_requirement("BUILD_TYPE")
env.check()

local build_type = env.get("BUILD_TYPE")

-- Create build file
log.info("Creating \"build\" folder and its subdirectories...")
cmd.run("mkdir", { "build", "-p" })
cmd.run("mkdir", { "build/iso", "-p" })
cmd.run("mkdir", { "build/iso/EFI", "-p" })
cmd.run("mkdir", { "build/iso/EFI/BOOT", "-p" })

-- Build kernel/bootloader
log.info("Beginning to build kernel + bootloader...")
local build_flags = { "build", "--target", "x86_64-unknown-uefi", "--manifest-path", "rust/Cargo.toml" }
if build_type == "release" then
    table.insert(build_flags, "--release")
end
cmd.run("cargo", build_flags)

log.info("Successfully built kernel + bootloader.")

log.info("Creating FAT image...")

-- Take out compiled kernel, and bootloader files from rust/target
local kernel_compiled = "rust/target/x86_64-unknown-uefi/" .. build_type .. "/zero_kernel.efi"
local bootloader_compiled = "rust/target/x86_64-unknown-uefi/" .. build_type .. "/zero_bootloader.efi"
local kernel_total = "build/iso/EFI/BOOT/kernel.EFI"
local bootloader_total = "build/iso/EFI/BOOT/BOOTX64.EFI"
cmd.run("cp", { kernel_compiled, kernel_total })
cmd.run("cp", { bootloader_compiled, bootloader_total })

-- Create the FAT image, and copy kernel/bootloader to put it into it
local esp_path = "build/esp.img"
cmd.run("dd", { "if=/dev/zero", "of=" .. esp_path, "bs=1M", "count=16" })
cmd.run("mkfs.fat", { esp_path })
cmd.run("mmd", { "-i", esp_path, "::/EFI" })
cmd.run("mmd", { "-i", esp_path, "::/EFI/BOOT" })
cmd.run("mcopy", { "-i", esp_path, bootloader_total, "::/EFI/BOOT" })
cmd.run("mcopy", { "-i", esp_path, kernel_total, "::/EFI/BOOT" })

log.info("Successfully created FAT image.")

-- Build .ISO image
log.info("Building ISO image...")
local iso_path = "build/zero.iso"
cmd.run("xorriso", { "-as", "mkisofs",
    "-o", iso_path,
    "-e", "EFI/BOOT/BOOTX64.EFI",
    "-no-emul-boot",
    "build/iso"
})
log.info("Successfully built ISO image.")

log.info("The building is done :>")
