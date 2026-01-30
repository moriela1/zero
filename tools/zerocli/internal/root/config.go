// Copyright 2026 dywoq
//
// This code is released under the Apache License 2.0:
// https://www.apache.org/licenses/LICENSE-2.0
//
// Repository:
// https://github.com/dywoq/zero

package root

import (
	"io"

	"github.com/BurntSushi/toml"
)

// Config represents the root configuration of zerocli.
type Config struct {
	CommandsDir string `toml:"commands_dir"`
}

// ConfigParser represents the config parser.
type ConfigParser struct {
}

// Parse parses .TOML config from r, decoding.
// Returns an error if it fails.
func (c *ConfigParser) Parse(r io.Reader) (*Config, error) {
	var config Config
	_, err := toml.NewDecoder(r).Decode(&config)
	if err != nil {
		return nil, err
	}
	return &config, nil
}
