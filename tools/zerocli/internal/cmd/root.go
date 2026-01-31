// Copyright 2026 dywoq
//
// This code is released under the Apache License 2.0:
// https://www.apache.org/licenses/LICENSE-2.0
//
// Repository:
// https://github.com/dywoq/zero

package cmd

import "github.com/spf13/cobra"

// Root returns a instance of root command of zerocli.
func Root() *cobra.Command {
	root := &cobra.Command{
		Use: "zerocli",
		Short: "Manage Zero source code much safer",
	}
	return root
}
