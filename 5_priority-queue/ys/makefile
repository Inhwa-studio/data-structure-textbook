# Variables
CC = gcc
TARGET = practice.exe  # Build target
SRCINCLUDE_DIR = ./include/

CFLAGS = -I$(SRCINCLUDE_DIR)
LIBS = 

# Source files
SRCINCLUDE = priority_queue.c simulate.c
SRCINCLUDE := $(addprefix $(SRCINCLUDE_DIR), $(SRCINCLUDE))
SRCS = main.c $(SRCINCLUDE)

# Object files
OBJS = $(SRCS:.c=.o)

# Build rule
$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS)

# Rule for creating object files
$(SRCINCLUDE_DIR)%.o: $(SRCINCLUDE_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target
clean:
	rm -f $(OBJS) $(TARGET)

re: clean $(TARGET)