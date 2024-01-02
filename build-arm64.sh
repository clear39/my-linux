#!/bin/bash
mkdir build
make ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- O=build defconfig 
make ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- O=build
