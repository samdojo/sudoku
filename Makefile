CC = g++
SOURCE_FILES = src/*.cpp
HEADER_FILES = src/*.h
TEST_FILES = src/test/*.cpp
MAIN_FILE = src/main/main.cpp
TEST_LIBS = -lgtest -pthread -lgtest_main
COMMON_FLAGS = -std=c++20 -Isrc/ -o $@
DEBUG_FLAGS = $(COMMON_FLAGS) -Og -g
RELEASE_FLAGS = $(COMMON_FLAGS) -Ofast

all: solver-debug solver-release test

solver-debug: $(SOURCE_FILES) $(HEADER_FILES) $(MAIN_FILE)
	$(CC) $(SOURCE_FILES) $(MAIN_FILE) $(DEBUG_FLAGS)

solver-release: $(SOURCE_FILES) $(HEADER_FILES) $(MAIN_FILE)
	$(CC) $(SOURCE_FILES) $(MAIN_FILE) $(RELEASE_FLAGS)

clean:
	rm -f solver-* test

test: $(SOURCE_FILES) $(HEADER_FILES) $(TEST_FILES)
	$(CC) $(SOURCE_FILES) $(TEST_FILES) $(TEST_LIBS) $(DEBUG_FLAGS)
