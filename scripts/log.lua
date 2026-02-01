-- Copyright 2026 dywoq
--
-- This code is released under the Apache License 2.0:
-- https://www.apache.org/licenses/LICENSE-2.0
--
-- Repository:
-- https://github.com/dywoq/zero

-- Module overview
--
-- Logging functions with colored prefixes

local colors = {
    reset = "\27[0m",
    red   = "\27[31m",
    green = "\27[32m",
    yellow = "\27[33m",
    blue  = "\27[34m",
    magenta = "\27[35m",
    cyan = "\27[36m",
    white = "\27[37m"
}

local M = {}

--- Prints an error message into console, and exits the program with code 1,
--- outputting debug trace.
function M.error(message)
    print("[zero] " .. colors.red .. "error: " .. colors.reset .. message)
    print(debug.traceback())
    os.exit(1)
end

--- Prints an warning message into console.
function M.warn(message)
    print("[zero] " .. colors.yellow .. "warn: " .. colors.reset .. message)
end

--- Prints an info message into console.
function M.info(message)
    print("[zero] " .. colors.green .. "info: " .. colors.reset .. message)
end

return M
