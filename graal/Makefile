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

all: $(TARGET) install clean

$(OBJDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@echo "(1) Gerando código objeto..."	
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $^ -o $@ 

$(TARGET): $(OBJS) 
	@echo "(2) Gerando biblioteca..."
	$(LIB) $(COMP) $@ $^

##Gerar aplicação para cliente
##Depois disso cliente só precisa usar seu make
.PHONY: install
install:
	@echo "(3) Instalando Graal..."
	@cp build/libgraal.a ../App/lib/
	@cp includes/graal.h ../App/includes/

.PHONY: clean
clean: 
	@echo "(4) Limpando..."
	@rm -rf $(OBJDIR)/*.o
	@rm -rf $(OBJDIR)/*.a








