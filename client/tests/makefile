EXEC = $(BINDIR)socketstest
SRCDIR = ./
XSRCDIR = ../src/
OBJDIR = ./obj/
BINDIR = ./bin/
SOURCES = $(wildcard $(SRCDIR)*.cpp)
XSOURCES = $(wildcard $(XSRCDIR)*.cpp)
OBJECTS = $(addprefix $(OBJDIR), $(notdir $(SOURCES:.cpp=.o)))
XOBJECTS = $(addprefix $(OBJDIR), $(notdir $(XSOURCES:.cpp=.o)))
CFLAGS = -Wall -std=c++11
COPTINC = -I ../inc/ -I /usr/include
LOPTDIR = -L /usr/lib/
LOPTLIB = -lgmock -lpthread

.PHONY: all clean run

$(EXEC): $(OBJECTS) $(XOBJECTS) | $(BINDIR)
	g++ $(LOPTDIR) $^ -o $@ $(LOPTLIB)

$(OBJDIR)%.o: %.cpp | $(OBJDIR)
	g++ $(CFLAGS) $(COPTINC) -c $< -o $@

$(OBJDIR)%.o: $(XSRCDIR)%.cpp | $(OBJDIR)
	g++ $(CFLAGS) $(COPTINC) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

all: clean $(EXEC) run

clean:
	rm -rf $(BINDIR)* $(OBJDIR)*

run:
	$(EXEC)
