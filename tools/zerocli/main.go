// Copyright 2026 dywoq
//
// This code is released under the Apache License 2.0:
// https://www.apache.org/licenses/LICENSE-2.0
//
// Repository:
// https://github.com/dywoq/zero

package main

import (
	"fmt"
	"os"

	"github.com/dywoq/zero/tools/zerocli/internal/cmd"
)

// die Checks if err is not nil.
// If it's true, it prints a formatted message and exits with code 1.
func die(err error, format string, v ...any) {
	if err != nil {
		fmt.Fprintf(os.Stderr, "ERROR: %v\n", fmt.Sprintf(format, v...))
		os.Exit(1)
	}
}

func main() {
	err := cmd.Root().Execute()
	die(err, "Failed to execute root command: %v", err)
}
