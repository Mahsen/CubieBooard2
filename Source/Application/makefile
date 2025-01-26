#    File : makefile
#    Programmer : Mohammad Lotfi
#    Used : make
#    Design Pattern : none
#    Types of memory : none
#    Total Tread : Nothing
#    Site : https://www.mahsen.ir
#    Tel : +989124662703
#    Email : info@mahsen.ir
#    Last Update : 2025/1/26

# Publish
PUBLISH_SERVER = "root@192.168.88.9"
# Export STAGING_DIR 
STAGING_DIR = ../OpenWRT/staging_dir
export STAGING_DIR
# Library  
LIBRARY_DIR = -L$(STAGING_DIR)/target-arm_cortex-a7+neon-vfpv4_musl_eabi/usr/lib
LIBRARY = -lcjson
# Compiler
CXX = $(STAGING_DIR)/toolchain-arm_cortex-a7+neon-vfpv4_gcc-13.3.0_musl_eabi/bin/arm-openwrt-linux-g++
# Compiler flags
CXXFLAGS = -Wall -g -pthread
# Build dir
BUILD_DIR = Build
# Target executable
TARGET = $(BUILD_DIR)/Application
# Target executable Web
TARGET_WEB = $(BUILD_DIR)/Web
# Source files
SRCS = *.cpp \
	Module/*.cpp \
	Driver/*.c \
	Core/*.c
# Source files Web
SRCS_WEB = Web/*.cpp \
	Module/*.cpp \
	Driver/*.c \
	Core/*.c
# Source files www
SRCS_WWW = Web/www/*

all:
	clang-format -i -style=file  $(SRCS)
	clear
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)
	chmod +x $(TARGET)
	$(CXX) $(CXXFLAGS) $(SRCS_WEB) -o $(TARGET_WEB) $(LIBRARY_DIR) $(LIBRARY)
	chmod +x $(TARGET_WEB)

#   cp $(TARGET) ../OpenWRT/files/root
#   cp $(SRCS_WWW) ../OpenWRT/files/www
#   cp $(TARGET_WEB) ../OpenWRT/files/www/cgi-bin/

	./Publish.sh $(PUBLISH_SERVER) "$(SRCS_WWW)" "/www"
	./Publish.sh $(PUBLISH_SERVER) "$(TARGET_WEB)" "/www/cgi-bin"


clean:
	del $(TARGET)
	del $(TARGET_WEB)
