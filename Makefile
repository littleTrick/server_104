CC = gcc
CXX = g++
CFLAGS   = -Wall -MMD
CXXFLAGS = -Wall -MMD
LDFLAGS  = -lpthread


SRCS=$(shell ls *.c *.cpp)
OBJS=$(addsuffix .o, $(basename $(SRCS)))
TARGET=Server104

all:Server104

Server104:$(OBJS)
	@echo "Linking $@"
	@$(CXX) -o $@  $^ $(LDFLAGS)

%.o:%.c
	@echo "Compiling $@"
	@$(CC) $(CFLAGS) -o $@ -c $<

%.o:%.cpp
	@echo "Compiling $@"
	@$(CXX) $(CXXFLAGS) -o $@ -c $<

.PHONY:clean

clean:
	@echo "cleanning"
	-@$(RM) *.o *.d $(TARGET)

-include *.d
