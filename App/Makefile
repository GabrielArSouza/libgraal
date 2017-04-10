##########
# Gabriel A S #
##########
## DIRS
INCDIR = includes
SRCDIR = src
OBJDIR = build
LIBDIR = lib

# TARGET
TARGET = $(OBJDIR)/drive_graal

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
CFLAGS = $(WARN) -std=c++11 $(INCFLAG) -c
OBJFLAGS = $(INCFLAG) $(INLFLAG)

#g++ -Wall -std=c++11 src/drive_graal.cpp -I includes -L lib -l graal -o build/drive_graa 
#all: $(TARGET) clean
all: $(TARGET) clean	
#g++ -Wall -I includes -std=c++11 -c -o 	
$(OBJDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@echo "Gerando código objeto..."
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $^ -o $@

$(TARGET): $(OBJS)
	@echo "Compilando..."
	$(CC) $^ $(INLFLAG) -o $@  

.PHONY: clean
clean:
	@echo "Limpando..."
	@rm -rf $(OBJDIR)/*.o
	
