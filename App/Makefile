##########
# Gabriel A S #
##########
## DIRS
INCDIR = includes
BINDIR = build
SRCDIR = src
OBJDIR = build
LIBDIR = lib

# TARGET
TARGET = $(BINDIR)/drive_graal

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
INCFLAG = -I $(INCDIR)
INLFLAG = -L $(LIBDIR) -l graal
CFLAGS = $(WARN) -std=c++11 $(INCFLAG) $(INLFLAG) -c

#g++ -Wall -std=c++11 src/drive_graal.cpp -I includes -L lib -l graal -o build/drive_graa
order:
	@echo "Copiando biblioteca..."
	@cp ../graal/build/libgraal.a lib/
	@echo "Copiando includes..."
	@cp ../graal/includes/graal.h includes/

.PHONY: order

$(OBJDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $^ -o $@

$(TARGET): $(OBJS)
	@echo "Compilando..."
	$(CC) -o $@ $^

clean:
	@echo "Limpando..."
	@rm -rf $(OBJDIR)/*.o
	
.PHONY: clean