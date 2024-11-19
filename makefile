
# define the C compiler to use
CC = g++

# define any compile-time flags
CFLAGS = -ggdb

# define the compile command by compiler and flags
CC_OPTIONS = $(CC) $(CFLAGS)

# define the C source files
SRCS = main.cpp

# define the C object files 
#
# This uses Suffix Replacement within a macro:
#   $(name:string1=string2)
#         For each word in 'name' replace 'string1' with 'string2'
# Below we are replacing the suffix .c of all words in the macro SRCS
# with the .o suffix
#
OBJS = $(SRCS:.cpp=.o)

# define the executable file 
MAIN = path


#
# The following part of the makefile is generic; it can be used to 
# build any executable just by changing the definitions above and by
# deleting dependencies appended to the file from 'make depend'
#

all:$(MAIN)
	@echo  The $(MAIN) has been compiled!

$(MAIN):$(OBJS)
	$(CC_OPTIONS) -o $@ $(OBJS)

# this is a suffix replacement rule for building .o's from .c's
# it uses automatic variables 
# $<: the name of the prerequisite of the rule(a .c/cpp file) 
# and $@: the name of the target of the rule (a .o file) 
# (see the gnu make manual section about automatic variables)
#.c.o:
#.cpp.o:
%.o: %.cpp %.h 
	$(CC) $(CFLAGS) -c $< -o $@

vis: $(BIN)
	./$(BIN) | dot -Tpdf > vis.pdf

clean:
	$(RM) -r $(OBJS) $(MAIN) $(BIN) *.dSYM vis.pdf



# Original makefile
# ------------------------
#main:main.o city.o
#	g++ -ggdb -o main main.o city.o
#main.o:main.cpp
#	g++ -ggdb -c main.cpp
#city.o: city.cpp city.h
#	g++ -ggdb -c city.cpp
#clean:
#	rm *.o main
#vis: example.dot
#	example.dot | dot -Tpdf > vis.pdf