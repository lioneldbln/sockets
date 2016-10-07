EXEC = $(BINDIR)client
SRCDIR = ./src/
COMMONSRCDIR = ../common/src/
OBJDIR = ./obj/
BINDIR = ./bin/
SOURCES = $(wildcard $(SRCDIR)*.cpp)
OBJECTS = $(addprefix $(OBJDIR), $(notdir $(SOURCES:.cpp=.o)))
COMMONSOURCES = $(wildcard $(COMMONSRCDIR)*.cpp)
COMMONOBJECTS = $(addprefix $(OBJDIR), $(notdir $(COMMONSOURCES:.cpp=.o)))
CFLAGS = -Wall -std=c++11
COPTIONSINC = -I ./inc/ -I ../common/inc/

.PHONY: all test alltest clean run checkmem

$(EXEC): $(OBJDIR)main.o $(OBJECTS) $(COMMONOBJECTS) | $(BINDIR)
	g++ $^ -o $@

$(OBJDIR)%.o: $(SRCDIR)%.cpp | $(OBJDIR)
	g++ $(CFLAGS) $(COPTIONSINC) -c $< -o $@

$(OBJDIR)%.o: $(COMMONSRCDIR)%.cpp | $(OBJDIR)
	g++ $(CFLAGS) $(COPTIONSINC) -c $< -o $@

$(OBJDIR)main.o: main.cpp | $(OBJDIR)
	g++ $(CFLAGS) $(COPTIONSINC) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

all: clean $(EXEC) alltest

test:
	(cd ./tests; $(MAKE))
	(cd ./tests; $(MAKE) run)

alltest:
	(cd ./tests; $(MAKE) all)

clean:
	rm -rf $(BINDIR)* $(OBJDIR)*

run:
	$(EXEC)

checkmem:
	valgrind --leak-check=yes $(EXEC)
	
