EXEC = $(BINDIR)sockets
SRCDIR = ./src/
OBJDIR = ./obj/
BINDIR = ./bin/
SOURCES = $(wildcard $(SRCDIR)*.cpp)
OBJECTS = $(addprefix $(OBJDIR), $(notdir $(SOURCES:.cpp=.o)))
CIDIR = -I ./inc/
CFLAGS = -Wall -std=c++11

.PHONY: all clean run

$(EXEC): $(OBJDIR)main.o $(OBJECTS) | $(BINDIR)
	g++ $< -o $@

$(OBJDIR)%.o: $(SRCDIR)%.cpp | $(OBJDIR)
	g++ $(CFLAGS) $(CIDIR) -c $< -o $@

$(OBJDIR)main.o: main.cpp
	g++ $(CFLAGS) $(CIDIR) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

all: clean $(EXEC) run

clean:
	rm -rf $(BINDIR)* $(OBJDIR)*

run:
	$(EXEC)
