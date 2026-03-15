CC = gcc
AR = ar
CFLAGS = -Iinclude -O2 -DBGLVL=2

TARGET_MAIN = bin\lab_1.exe
TARGET_TESTS = bin\tests.exe
LIB_NAME = build\libmatrix.a
MAIN_FILE = main.c

SRCDIR = src
TESTDIR = tests
OBJDIR = build

LIB_SRC = double.c integer.c matrix.c output.c matrix_errors.c
TEST_SRC = test_runner.c test_creating.c assertions.c test_setter.c test_matrix_addition.c\
		test_matrix_multiply.c test_scalar_multiply.c\
		test_linear_combination.c test_integer.c test_double.c


LIB_OBJS = $(LIB_SRC:%.c=$(OBJDIR)/%.o)
TEST_OBJS = $(TEST_SRC:%.c=$(OBJDIR)/%.o)
MAIN_OBJ = $(MAIN_FILE:%.c=$(OBJDIR)/%.o)

all: $(LIB_NAME) $(TARGET_MAIN) $(TARGET_TESTS)

$(LIB_NAME): $(LIB_OBJS)
	$(AR) rcs $@ $^

$(TARGET_MAIN): $(MAIN_OBJ) $(LIB_NAME)
	$(CC) $(MAIN_OBJ) -Lbuild -lmatrix -o $@

$(TARGET_TESTS): $(TEST_OBJS) $(LIB_NAME)
	$(CC) $(TEST_OBJS) -Lbuild -lmatrix -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@
	
$(OBJDIR)/%.o: $(TESTDIR)/%.c
	$(CC) $(CFLAGS) -Itests -c $< -o $@

.PHONY: all clean cleanall

clean:
	del /f $(TARGET_MAIN) $(TARGET_TESTS) $(LIB_NAME) 2>nul

cleanall:
	del /f $(TARGET_MAIN) $(TARGET_TESTS) $(LIB_NAME) 2>nul
	del /f $(OBJDIR)\*.o 2>nul

