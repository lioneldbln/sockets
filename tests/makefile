CCFLAGS = -Wall -std=c++11
LIB = -lgmock -lpthread
LIBDIR = -L /usr/lib/
OBJDIR = ./obj
BINDIR = ./bin

.PHONY: clean

$(BINDIR)/socketstest:: $(OBJDIR)/maintest.o $(OBJDIR)/sockettest.o | $(BINDIR)
	g++ $(LIBDIR) $< -o $@ $(LIB)

$(OBJDIR)/sockettest.o: sockettest.cpp | $(OBJDIR)
	g++ $(CCFLAGS) -c $< -o $@

$(OBJDIR)/maintest.o: maintest.cpp | $(OBJDIR)
	g++ $(CCFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

clean:
	rm -rf $(BINDIR) $(OBJDIR)
