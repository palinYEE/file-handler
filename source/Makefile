CC = gcc -m64
CFLAGS = -I../include
CFLAGS += -Wall -O2
OBJS = file_handler.o yj_utils.o file_handler_main.o
TARGET = yj_file_handler

all : $(TARGET)
    
$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

.c.o:
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.o
	rm $(TARGET)
	find -type f ! -name "*.c" ! -name "Makefile" -exec rm {} \;