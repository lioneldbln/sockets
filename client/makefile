EXEC = $(BINDIR)client
SRCDIR = ./src/
OBJDIR = ./obj/
BINDIR = ./bin/
SOURCES = $(wildcard $(SRCDIR)*.cpp)
OBJECTS = $(addprefix $(OBJDIR), $(notdir $(SOURCES:.cpp=.o)))
CFLAGS = -Wall -std=c++11
COPTIONSINC = -I ./inc/

.PHONY: all test clean run

$(EXEC): $(OBJDIR)main.o $(OBJECTS) | $(BINDIR)
	g++ $^ -o $@

$(OBJDIR)%.o: $(SRCDIR)%.cpp | $(OBJDIR)
	g++ $(CFLAGS) $(COPTIONSINC) -c $< -o $@

$(OBJDIR)main.o: main.cpp | $(OBJDIR)
	g++ $(CFLAGS) $(COPTIONSINC) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

all: clean $(EXEC) test

test:
	(cd ./tests; $(MAKE) all)

clean:
	rm -rf $(BINDIR)* $(OBJDIR)*

run:
	$(EXEC)
