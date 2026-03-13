CC = gcc
CFLAGS = -Iinclude -O2 -DBGLVL=2
TARGET_MAIN = bin\lab_1.exe
TARGET_TESTS = bin\tests.exe
SRCDIR = src
OBJDIR = build

TEST_SRC = double.c integer.c matrix.c output.c tests.c
MAIN_SRC = double.c integer.c main.c matrix.c output.c

TEST_OBJS = $(TEST_SRC:%.c=$(OBJDIR)/%.o)
MAIN_OBJS = $(MAIN_SRC:%.c=$(OBJDIR)/%.o) 

all: $(TARGET_TESTS) $(TARGET_MAIN)

$(TARGET_TESTS): $(TEST_OBJS)
	$(CC) $^ -o $@

$(TARGET_MAIN): $(MAIN_OBJS)
	$(CC) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@


 .PHONY: all clean cleanall

 clean:
	del /f $(TARGET_TESTS) $(TARGET_MAIN) 2>nul

cleanall:
	del /f $(TARGET_TESTS) $(TARGET_MAIN) 2>nul
	del /f $(OBJDIR)\*.o 2>nul