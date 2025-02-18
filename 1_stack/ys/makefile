# Variables
CC = gcc
TARGET = stack.exe  # Build target
LIB_DIR =         # Library directory (if applicable)
INCLUDE_DIR = ..\\include\\
SRCINCLUDE_DIR = ..\\src\\

CFLAGS = -I$(INCLUDE_DIR)
LDFLAGS = -L$(LIB_DIR)
LIBS = 

# Source files
SRCINCLUDE =
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
	del /F $(OBJS) $(TARGET)

re: clean $(TARGET)