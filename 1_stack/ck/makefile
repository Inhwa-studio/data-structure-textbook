# Variables
CC = g++
TARGET = stack.exe  # Build target
LIB_DIR =         # Library directory (if applicable)
INCLUDE_DIR = include\\

CFLAGS = -I$(INCLUDE_DIR)
LDFLAGS = -L$(LIB_DIR)
LIBS = 

# Source files
SRCINCLUDE = 
SRCINCLUDE := $(addprefix $(INCLUDE_DIR), $(SRCINCLUDE))
SRCS = main.cpp $(SRCINCLUDE)

# Object files
OBJS = $(SRCS:.cpp=.o)

# Build rule
$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS)

# Rule for creating object files
$(INCLUDE_DIR)%.o: $(INCLUDE_DIR)%.cpp
	$(CC) $(CFLAGS) -cpp $< -o $@

# Clean target
clean:
	del /F $(OBJS) $(TARGET)

re: clean $(TARGET)