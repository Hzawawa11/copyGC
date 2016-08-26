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

run:
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET) *.o *.d
