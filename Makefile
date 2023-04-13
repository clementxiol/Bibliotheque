#
# Makefile.c
#

TARGET = all
CPP = g++
CPPFLAGS = -std=c++17 -Wall -Wextra -Wpedantic

#Version materielle
INCLDIRS =
LIBDIRS =

LIBS64 = -lm

SRCS = $(wildcard *.cpp)


OBJS = ${SRCS:.cpp=.o}

$(TARGET): $(OBJS)
	$(CPP) $(CPPFLAGS) $(INCLDIRS) -o $@ $(OBJS) $(LIBS64)

$(OBJS):
	$(CPP) $(CPPFLAGS) $(INCLDIRS) -c $*.cpp


clean:
	rm -f $(OBJS) core

veryclean: clean
	rm -f $(TARGET) a.out *.*~
	rm -rf $(TARGET).dSYM
