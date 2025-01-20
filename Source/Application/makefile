# Export STAGING_DIR
STAGING_DIR = ../OpenWRT/staging_dir
export STAGING_DIR
# Compiler
CXX = ../OpenWRT/staging_dir/toolchain-arm_cortex-a7+neon-vfpv4_gcc-13.3.0_musl_eabi/bin/arm-openwrt-linux-g++
# Compiler flags
CXXFLAGS = -Wall -g -pthread
# Build dir
BUILD_DIR = Build
# Target executable
TARGET = $(BUILD_DIR)/Application
# Source files
SRCS = *.cpp \
	Module/*.cpp \
	Driver/*.c \
	Core/*.c

all:
	clear
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)
	cp $(TARGET) ../OpenWRT/files/root
	
clean:
	del $(TARGET)
