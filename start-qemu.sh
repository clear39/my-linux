#!/bin/sh


../qemu/build/qemu-system-aarch64 \
	-machine virt \
        -cpu cortex-a72 \
        -M type=virt \
        -m 2048 \
        -smp 2 \
        -kernel arch/arm64/boot/Image \
        -initrd rootfs.cpio.gz \
        -append "rdinit=/linuxrc console=ttyAMA0" \
	-nographic
