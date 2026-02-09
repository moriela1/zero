-- Copyright 2026 dywoq
--
-- This code is released under the Apache License 2.0:
-- https://www.apache.org/licenses/LICENSE-2.0
--
-- Repository:
-- https://github.com/dywoq/lumen

-- Module overview
--
-- This module contains utility functions that automatically
-- handle environment variable check.

local M = {}

local requirements = {}
local checked = false

local log = require("scripts.log")

function M.add_requirement(name)
    table.insert(requirements, name)
end

function M.check()
    if #requirements == 0 then
        log.info("env: No requirements found")
        checked = true
        return
    end

    local missing = {}
    local ok = true

    for _, name in ipairs(requirements) do
        if not os.getenv(name) then
            ok = false
            table.insert(missing, name)
        end
    end

    if not ok then
        log.error("env: Check requirements failed: " .. table.concat(missing, ", ") .. " are not defined or empty.")
    end

    checked = true
end

function M.get(name)
    if not checked then
        log.error("Can't get env variable: check is not ran")
    end
    return os.getenv(name)
end

return M