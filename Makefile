CC=gcc
BUILD_DIR=./build/
INCLUDE_DIR=./include/
SRC_DIR=./src/
CFLAGS=-I"$(INCLUDE_DIR)" -Wall -g
OBJS=$(BUILD_DIR)main.o $(BUILD_DIR)mips_decode.o
EXE=$(BUILD_DIR)a.out

all: $(EXE)
	@echo Compiling a.out

$(EXE): $(BUILD_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(BUILD_DIR):
	if [ ! -d $(BUILD_DIR) ]; then \
		mkdir $(BUILD_DIR); \
	fi

$(BUILD_DIR)main.o: $(SRC_DIR)main.c
	$(CC) $(CFLAGS) $? -c -o $@

$(BUILD_DIR)mips_decode.o: $(SRC_DIR)mips_decode.c
	$(CC) $(CFLAGS) $? -c -o $@

clean:
	rm -f $(BUILD_DIR)*
