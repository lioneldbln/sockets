EXEC = $(BINDIR)clienttest
SRCDIR = ./
TESTSRCDIR = ../src/
COMMONSRCDIR = ../../common/src/
COMMONTESTSRCDIR = ../../common/tests/
OBJDIR = ./obj/
BINDIR = ./bin/
SOURCES = $(wildcard $(SRCDIR)*.cpp)
OBJECTS = $(addprefix $(OBJDIR), $(notdir $(SOURCES:.cpp=.o)))
TESTSOURCES = $(wildcard $(TESTSRCDIR)*.cpp)
TESTOBJECTS = $(addprefix $(OBJDIR), $(notdir $(TESTSOURCES:.cpp=.o)))
COMMONSOURCES = $(wildcard $(COMMONSRCDIR)*.cpp)
COMMONOBJECTS = $(addprefix $(OBJDIR), $(notdir $(COMMONSOURCES:.cpp=.o)))
COMMONTESTSOURCES = $(wildcard $(COMMONTESTSRCDIR)*.cpp)
COMMONTESTOBJECTS = $(addprefix $(OBJDIR), $(notdir $(COMMONTESTSOURCES:.cpp=.o)))
CFLAGS = -Wall -std=c++11
COPTINC = -I ./inc/ -I ../inc/ -I ../../common/inc/ -I /usr/include/
LOPTDIR = -L /usr/lib/
LOPTLIB = -lgmock -lpthread

.PHONY: all clean run

$(EXEC): $(OBJECTS) $(TESTOBJECTS) $(COMMONOBJECTS) $(COMMONTESTOBJECTS) | $(BINDIR)
	g++ $(LOPTDIR) $^ -o $@ $(LOPTLIB)

$(OBJDIR)%.o: %.cpp | $(OBJDIR)
	g++ $(CFLAGS) $(COPTINC) -c $< -o $@

$(OBJDIR)%.o: $(TESTSRCDIR)%.cpp | $(OBJDIR)
	g++ $(CFLAGS) $(COPTINC) -c $< -o $@

$(OBJDIR)%.o: $(COMMONSRCDIR)%.cpp | $(OBJDIR)
	g++ $(CFLAGS) $(COPTINC) -c $< -o $@

$(OBJDIR)%.o: $(COMMONTESTSRCDIR)%.cpp | $(OBJDIR)
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
