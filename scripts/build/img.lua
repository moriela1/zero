-- Copyright 2026 dywoq
--
-- This code is released under the Apache License 2.0:
-- https://www.apache.org/licenses/LICENSE-2.0
--
-- Repository:
-- https://github.com/dywoq/zero

local cmd = require("scripts.cmd")
local log = require("scripts.log")

-- Create build directory
local build_dir = ".build"
cmd.run("rm", {build_dir, "-fr"})
cmd.run("mkdir", { build_dir, "-p" })

local target = build_dir .. "/zero.img"

-- Build kernel, bootloader, and stage1
log.info("building stage0/stage1/kernel...")
cmd.run("cd kernel && make clean all")
cmd.run("cd stage0 && make clean all")
cmd.run("cd stage1 && make clean all")
-- Take their binaries and put them into build/
cmd.run("mv", { "kernel/.build/kernel.bin", build_dir })
cmd.run("mv", { "stage0/.build/stage0.bin", build_dir })
cmd.run("mv", { "stage1/.build/stage1.bin", build_dir })
log.info("building done!")

-- Generate .img
log.info("generating \"" .. target .. "\" file...")
cmd.run("dd", { "if=/dev/zero", "of=" ..target, "bs=1M", "count=10" })
cmd.run("dd", { "if=" .. build_dir .. "/stage0.bin", "of=" ..target, "bs=512", "count=1", "conv=notrunc" })
cmd.run("dd", { "if=" .. build_dir .. "/stage1.bin", "of=" ..target, "bs=512", "seek=1", "conv=notrunc" })
cmd.run("dd", { "if=" .. build_dir .. "/kernel.bin", "of=" ..target, "bs=512", "seek=2", "conv=notrunc" })
log.info("generating \"" .. target .. "\" file done!")
