# Specify the target file and the main object files
TARGET = connections
MAIN_OBJS = main.o 

# Specify the target library file and the object files
LIBRARY = my_mat.a
LIB_OBJECT = my_mat.o

# Specify the compiler and compiler flags
CC = gcc
CFLAGS = -Wall -g -lm -fPIC

# Define the valgrind command and flags
VALGRIND = valgrind
VFLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes

# Define the targets that are not associated with a specific file or directory
.PHONY: clean run valgrind

# Define the default target (to build the program)
all: $(LIBRARY) $(TARGET)

# Define the target for building the program
$(TARGET): $(MAIN_OBJS) $(LIBRARY)
	$(CC) $(CFLAGS) -o $(TARGET) $(MAIN_OBJS) $(LIBRARY)

# Define the targets for each object file
main.o: main.c my_mat.h
	$(CC) $(CFLAGS) -c main.c

my_mat.o: my_mat.c my_mat.h
	$(CC) $(CFLAGS) -c my_mat.c

#Define the target for building the library
$(LIBRARY): $(LIB_OBJECT) 
	ar -rcs $(LIBRARY) $(LIB_OBJECT)

# Define the target for running the program
run: $(TARGET)
	./$(TARGET)

# Define the target for running the valgrind test
valgrind: $(TARGET)
	$(VALGRIND) $(VFLAGS) ./$(TARGET)

# Define the target for cleaning up the directory
clean:
	rm -f *.o *.a *.so *.txt connections