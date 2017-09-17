CC = arm-none-linux-gnueabi-gcc
CXX = arm-none-linux-gnueabi-g++
CFLAGS   = -Wall -MMD
CXXFLAGS = -Wall -MMD
LDFLAGS  = -lpthread


SRCS=$(shell ls *.c *.cpp *.cc)
OBJS=$(addsuffix .o, $(basename $(SRCS)))
TARGET=Server104

all:clean Server104

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
