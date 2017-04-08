# Makefile #

# GABRIEL A S #

## DIRS
INCDIR = includes
BINDIR = build
SRCDIR = src
OBJDIR = build

# TARGET #
TARGET = $(BINDIR)/libgraal.a


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

## Lib generate
LIB = ar
COMP = rvs

$(OBJDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@echo "Gerando código objeto..."	
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $^ -o $@ 

$(TARGET): $(OBJS)
	@echo "Gerando biblioteca..."
	$(LIB) $(COMP) $@ $^

.PHONY: clean mrproper

##Gerar aplicação para cliente
##Depois disso cliente só precisa usar seu make
	@echo "Gerando código cliente"
	@cp build/libgraal.a ../App/lib/
	@cp includes/graal.h ../App/includes/


clean:
	@echo "Limpando..."
	mrproper: clean
	@rm -rf $(OBJDIR)/*.o


