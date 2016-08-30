SRCS=	$(wildcard *.c)
OBJS=	$(SRCS:.c=.o)
TARGET=	minGC
CC= gcc
CFLAGS=	-O3 -Wall

all:$(TARGET)

$(TARGET):$(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LDFLAGS) $(CFLAGS)

.c.o:
	$(CC) -c -w $<

debug:
	$(CC) -o $(TARGET)  -g $(SRCS) $(LDFLAGS) -O0

drun:
	lldb -f $(TARGET)

run:
	./$(TARGET)

clean:
	rm -rf $(OBJS) $(TARGET) *.o *.d *.dSYM
