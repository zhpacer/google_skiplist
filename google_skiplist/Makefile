C = gcc
XX = g++
#C = /home/haizhu_bak/intel/bin/icc
#XX = /home/haizhu_bak/intel/bin/icc
CFLAGS = -fPIC  -Wall  -O2 -D__USE_LARGEFILE64 -D_JIANPIN_SENT 
#CFLAGS = -fPIC  -Wall  -g  -D__USE_LARGEFILE64 -D_JIANPIN_SENT
#AI_SO_LIB = aiinput_debug
#AI_SO_LIB = aiinput
#AI_SO_LIB = ./libaiinput_mobile.so
AI_STATIC_LIB = libaiinput_mobile.a
TARGET = skiplist_test
LIBLINK = -fpie -fPIC -shared
INCLUDEDIR = -I./
LINKFLAGS = -lpthread
%.o: %.c
	$(CC) $(INCLUDEDIR) $(CFLAGS) -c $< -o $@
%.o:%.cc
	$(XX) $(INCLUDEDIR) $(CFLAGS) -c $< -o $@
SOURCES = $(wildcard *.c *.cc)

OBJS = $(patsubst %.c,%.o,$(patsubst %.cc,%.o,$(SOURCES)))
$(TARGET):$(OBJS)
	$(XX)    $(INCLUDEDIR) $(OBJS)  -o $(TARGET) 
clean:
	rm -rf *.o $(TARGET)
