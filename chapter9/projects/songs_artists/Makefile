CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

SRCDIR = src
TESTDIR = test
OBJDIR = obj
BINDIR = bin

SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS))
TEST_SRCS = $(wildcard $(TESTDIR)/*_test.cpp)
TEST_BINS = $(patsubst $(TESTDIR)/%.cpp,$(BINDIR)/%,$(TEST_SRCS))

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(SRCDIR)/*.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BINDIR)/%: $(OBJDIR)/%.o $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

.PHONY: all
all: $(TEST_BINS)

$(TEST_BINS): $(BINDIR)/%: $(TESTDIR)/%.cpp $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

.PHONY: clean
clean:
	rm -f $(OBJDIR)/*.o $(BINDIR)/*
