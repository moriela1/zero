-- Copyright 2026 dywoq
--
-- This code is released under the Apache License 2.0:
-- https://www.apache.org/licenses/LICENSE-2.0
--
-- Repository:
-- https://github.com/dywoq/zero

-- Module overview
--
-- This module contains utility functions that automatically
-- handle commands management.

local log = require("scripts.log")

local M = {}

--- Run an external command with optional arguments.
---
--- Quotes arguments that contain spaces to prevent shell word splitting.
--- Captures the combined standard output and standard error of the command.
--- Logs an error if the command fails to execute or returns a non-zero exit code.
---
--- @param cmd string The command to execute (e.g., "ls", "git").
--- @param args table? Optional table of strings, arguments to pass to the command.
--- @return string output The full output of the command.
--- @return number exit_code
function M.run(cmd, args)
    args = args or {}

    local safe_args = {}
    for i, a in ipairs(args) do
        if string.find(a, "%s") then
            a = '"' .. a .. '"'
        end
        table.insert(safe_args, a)
    end

    local cmd_str = cmd .. " " .. table.concat(safe_args, " ")
    local handle, err = io.popen(cmd_str)
    if not handle then
        log.error("Failed to open command: " .. err)
        return "", 1
    end

    local output = handle:read("*a") or ""
    local ok, exit_type, exit_code = handle:close()

    exit_code = exit_code or -1  -- fallback if nil

    if exit_code ~= 0 then
        log.error("Failed to run \"" .. cmd_str .. "\" (exit code " .. tostring(exit_code) .. "):\n" .. output)
    end

    return output, exit_code
end

return M