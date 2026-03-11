# RISC-V OS (Minimal Kernel)

A small educational RISC-V operating system project focused on building and running a minimal kernel from scratch.

Built primarily by following the excellent tutorial "Operating System in 1000 Lines" by [Seiya Nuta](github.com/nuta).

## Project Files

- `kernel.c`, `kernel.h`: Kernel entry logic and core interfaces.
- `common.c`, `common.h`: Shared utilities used by kernel code.
- `kernel.ld`: Linker script defining kernel memory layout.
- `run.sh`: Convenience script to build and run the kernel (in this case through a QEMU emulator).

## Notes

This repository is intentionally minimal in order to experiment with low-level OS concepts such as boot flow, linking, and early kernel initialization.