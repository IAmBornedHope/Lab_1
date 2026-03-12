CC = gcc
CFLAGS = -Iinclude -O2 -DBGLVL=2
TARGET = bin\lab_1.exe
SRCDIR = src
OBJDIR = build

SRC = double.c integer.c main.c matrix.c output.c

OBJ = $(SRC:%.c=%.o)
OBJS = $(OBJ:%=$(OBJDIR)/%) 

$(TARGET): $(OBJS)
	$(CC) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@


 .PHONY: all clean cleanall

 clean:
	del /f $(TARGET)

cleanall:
	del /f $(TARGET)
	del /f $(OBJDIR)\*.o