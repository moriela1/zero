# Zero

Zero - is an open-source operating system, written in Rust. Its goal is to be ABI stable, to support the most-used architectures and provide modern, clean SDKs and tools.

# Roadmap

Below, you can see the roadmap of the project (may change):

| Name                             | Status          | Languages |
| -------------------------------- | --------------- | --------- |
| Scripts                          | Almost done     | Lua       |
| Automation tools                 | Being developed | Go        |
| Bootloader                       | Being developed | Rust      |
| Kernel                           | Not ready       | Rust      |
| Public SDKs, libraries and tools | Not ready       | C/C++     |

# Motivation

Why do I need to create another operating system? Well.. there are lot of reasons ;>

1. First, we already have got MacOS, Linux and Windows:

- Windows is closed-source, but provides end-user experience.
- Linux is open-source, but it's not made for everyone and specifically used by developers.
- MacOS stands in the middle between Linux and Windows, but also closed-source as Windows.

I wanted something like MacOS, but open-source and made for everyone,
including end-users and developers.

2. To be honest, their SDKs are really old and doesn't fit modern standards. Every time I work with `<unistd.h>`, `<windows.h>` (not in Zero) in my own C/C++ standard library implementations, I had to make sure their symbols don't collide with mine. Unfortunately, the C/C++ standard library requires support of POSIX/Windows to make it work on a lot of machines, so I have to use them in my implementations.

And, yeah, POSIX - I dislike it and I won't support it in my OS.

3. Just educational project for myself :>
   Even it won't become popular and widely adopted, I'll keep doing it because I like it.

Is it possible to do this alone? I think so, but it requires a lot of time and practice.
Creating an operating system is endless - and I like it too.
