# RISC-V OS (Minimal Kernel)

A small educational RISC-V operating system project focused on building and running a minimal kernel from scratch.

Built primarily by following the excellent tutorial "Operating System in 1000 Lines" by [Seiya Nuta](https://github.com/nuta).

This repo is focused on early boot flow, linker-driven memory layout, trap handling, and simple physical page allocation on RV32 with QEMU.


## Project Files

- `kernel.c`, `kernel.h`: Boot path, SBI calls, trap handling, and kernel entry logic.
- `common.c`, `common.h`: Minimal freestanding utilities (`printf`, `memset`, `memcpy`, string helpers).
- `kernel.ld`: Kernel memory layout and linker symbols.
- `run.sh`: Build and run script (Clang + QEMU).

## Notes

This repository is intentionally minimal in order to experiment with low-level OS concepts such as boot flow, linking, and early kernel initialization.