# Compiler
CC = gcc

# Flags
CFLAGS = -Wall -Wextra -std=c11 -I.

# Output
TARGET = project

# Source directories
SRC = main.c \
modules/ds/hashmap.c \
modules/ds/linkedlist.c \
modules/ds/trie.c \
modules/encryption/encryption.c \
modules/failure/failure_detector.c \
modules/hashing/consistent_hash.c \
modules/index/index_manager.c \
modules/node/node_manager.c \
modules/replication/replication_manager.c \
modules/stats/stats.c \
modules/storage/storage.c

# Object files
OBJ = $(SRC:.c=.o)

# Default target
all: $(TARGET)

# Build executable
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

# Compile each .c → .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(OBJ) $(TARGET)

# Rebuild everything
rebuild: clean all