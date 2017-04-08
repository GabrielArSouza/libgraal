# Makefile #

# GABRIEL A S #

## DIRS
INCDIR = includes
BINDIR = build
SRCDIR = src
OBJDIR = build

# TARGET #
TARGET = $(BINDIR)/a


## EXTENSIONS 
SRCEXT = cpp

## SOURCES LIST
SOURCES = $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))

## OBJECTS 
OBJS = $(patsubst $(SRCDIR)/%, $(OBJDIR)/%, $(SOURCES:.$(SRCEXT)=.o))

## COMPILER
CC = g++

## FLAGS
WARN = -Wall
INCFLAG = -I $(INCDIR)/
CFLAGS = $(WARN) -std=c++11 -c $(INCFLAG)
#ar rvs build/libgraal.a build/graal.o

## Lib generate
LIB = ar
COMP = rvs

#g++ -Wall -std=c++11 -c -I include/ src/graal.cpp -o build/graal.o
$(OBJDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@echo "Gerando código objeto..."	
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $^ -o $@ 

$(TARGET): $(OBJS)
	@echo "Gerando biblioteca..."
	$(LIB) $(COMP) $@ $^


clean:
	@echo "Limpando..."
#	@rm -rf $(OBJDIR)/*
#	@rm -rf $(TARGET)


.PHONY: clean
