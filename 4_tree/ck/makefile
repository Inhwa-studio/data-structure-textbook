# Variables
CC = g++
TARGET = BinarySearchTree.exe  # Build target
INCLUDE_DIR = include\\

CFLAGS = -I$(INCLUDE_DIR)
LIBS = 

# Source files
SRCINCLUDE = contact.cpp contactsBST.cpp
SRCINCLUDE := $(addprefix $(INCLUDE_DIR), $(SRCINCLUDE))
SRCS = main.cpp $(SRCINCLUDE)

# Object files
OBJS = $(SRCS:.cpp=.o)


# Build rule
$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS)

# Rule for creating object files
$(INCLUDE_DIR)%.o: $(INCLUDE_DIR)%.cpp
	$(CC) $(CFLAGS) -c $< -o $@	

# Clean target
clean:
	del /F $(OBJS) $(TARGET)

re: clean $(TARGET)