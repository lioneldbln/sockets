CCFLAGS = -Wall -std=c++11
OBJDIR = ./obj
BINDIR = ./bin

.PHONY: clean

$(BINDIR)/sockets: $(OBJDIR)/main.o | $(BINDIR)
	g++ $< -o $@

$(OBJDIR)/main.o: main.cpp | $(OBJDIR)
	g++ $(CCFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

clean:
	rm -rf $(BINDIR) $(OBJDIR)
