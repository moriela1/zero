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

func main() {
	cmd := cmd.Parser{}
	
	file, err := os.Open("help.toml")
	if err != nil {
		panic(err)
	}
	
	conf, err := cmd.Parse(file)
	if err != nil {
		panic(err)
	}
	
	fmt.Printf("conf: %v\n", conf)
}
