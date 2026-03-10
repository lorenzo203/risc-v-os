#!/bin/bash
set -xue

QEMU=qemu-system-riscv32

OS=$(uname)

# path to clang(CC) + compiler flags
if [ "$OS" = "Darwin" ]; then
    # macOS settings 
    CC=/opt/homebrew/opt/llvm/bin/clang
elif [ "$OS" = "Linux" ]; then
    # Linux settings
    CC=clang
fi
CFLAGS="-std=c11 -O2 -g3 -Wall -Wextra --target=riscv32-unknown-elf -fuse-ld=lld -fno-stack-protector -ffreestanding -nostdlib"

# build the kernel
$CC $CFLAGS -Wl,-Tkernel.ld -Wl,-Map=kernel.map -o kernel.elf \
    kernel.c common.c

# start qemu 
$QEMU -machine virt -bios default -nographic -serial mon:stdio --no-reboot \
    -kernel kernel.elf
