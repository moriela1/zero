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
local target = "x86_64-unknown-uefi"
local iso_folder_path = "build/iso-x86_64"

-- Create build directory
log.info("Creating \"build\" folder and its subdirectories for x86_64...")
cmd.run("mkdir", { "build", "-p" })
cmd.run("mkdir", { iso_folder_path, "-p" })
cmd.run("mkdir", { iso_folder_path .. "/EFI", "-p" })
cmd.run("mkdir", { iso_folder_path .. "/EFI/BOOT", "-p" })

-- Build kernel/bootloader
log.info("Beginning to build kernel + bootloader for target: " .. target .. "...")
local build_flags = { "build", "--target", target, "--manifest-path", "rust/Cargo.toml" }
if build_type == "release" then
    table.insert(build_flags, "--release")
end
cmd.run("cargo", build_flags)

log.info("Successfully built kernel + bootloader for x86_64.")

log.info("Creating FAT image...")

-- Take out compiled kernel, and bootloader files from rust/target
local kernel_compiled = string.format("rust/target/%s/%s/zero_kernel.efi", target, build_type)
local bootloader_compiled = string.format("rust/target/%s/%s/zero_bootloader.efi", target, build_type)
local kernel_total = iso_folder_path .. "/EFI/BOOT/kernel.EFI"
local bootloader_total = iso_folder_path .. "/EFI/BOOT/BOOTX64.EFI"
cmd.run("mv", { kernel_compiled, kernel_total })
cmd.run("mv", { bootloader_compiled, bootloader_total })

-- Create the FAT image, and copy kernel/bootloader to put it into it
local esp_path = "build/esp-x86_64.img"
cmd.run("dd", { "if=/dev/zero", "of=" .. esp_path, "bs=1M", "count=16" })
cmd.run("mkfs.fat", { esp_path })
cmd.run("mmd", { "-i", esp_path, "::/EFI" })
cmd.run("mmd", { "-i", esp_path, "::/EFI/BOOT" })
cmd.run("mcopy", { "-i", esp_path, bootloader_total, "::/EFI/BOOT" })
cmd.run("mcopy", { "-i", esp_path, kernel_total, "::/EFI/BOOT" })

log.info("Successfully created FAT image.")

-- Build .ISO image
log.info("Building ISO image...")
local iso_path = "build/zero-x86_64.iso"
cmd.run("cp", { esp_path, iso_folder_path .. "/esp-x86_64.img" })
log.info("Building ISO image...")
cmd.run("xorriso", { 
    "-as", "mkisofs",
    "-o", iso_path,
    "-e", "esp-x86_64.img",  -- Point to FAT image, not .EFI file
    "-no-emul-boot",
    iso_folder_path
})
log.info("Successfully built ISO image.")

log.info("The building is done :>")
