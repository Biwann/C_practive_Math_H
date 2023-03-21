CC=gcc
CFLAGS=-c -Wall -Wextra -Werror -std=c11 -pedantic
LDFLAGS=-lm -lcheck
GCFLAGS=-fprofile-arcs -ftest-coverage
GLFLAGS=-lgcov --coverage
CHECKFLAGS=$(shell pkg-config --cflags --libs check)
GDBFLAGS=#-g
SANFLAGS=#-fsanitize=address -fsanitize=leak
SLSOURCES=s21_math.c s21_fabs.c s21_fmod.c s21_cos.c s21_abs.c s21_asin.c s21_acos.c s21_atan.c s21_sqrt.c s21_pow.c s21_ceil.c s21_floor.c s21_sin.c s21_exp.c s21_tan.c s21_log.c
SLOBJECTS=$(SLSOURCES:.c=.o)
SLIBRARY=s21_math.a
SOURCES=test.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=test

all: clean s21_math.a

clean:
	rm -rf $(EXECUTABLE) *.a *.o *.gcov *.gcda *.gcno *.info ./gcov_report

s21_math.a: clean $(SLOBJECTS)
	ar rc $(SLIBRARY) $(SLOBJECTS)
	ranlib $(SLIBRARY)

$(OBJECTS):
	$(CC) $(CFLAGS) $(SOURCES) $(SANFLAGS) $(GDBFLAGS)

$(SLOBJECTS):
	$(CC) $(CFLAGS) $(SLSOURCES) $(SANFLAGS) $(GDBFLAGS)

gcov_report: test
	lcov -t "s21_math" -o s21_math.info -c -d .
	genhtml -o s21_math_report s21_math.info
	rm -f *.gcda *.gcno *.gcov *.info test
	open s21_math_report/index.html

test: clean
	$(CC) $(CFLAGS) $(GCFLAGS) $(SLSOURCES) $(SOURCES) $(GDBFLAGS)
	$(CC) $(OBJECTS) $(SLOBJECTS) $(CHECKFLAGS) -o test $(GLFLAGS) $(SANFLAGS) $(LDFLAGS)
	./test

lintc:
	clang-format -n *.c

linth: 
	clang-format -n *.h

leaks:
	leaks -atExit -- ./$(EXECUTABLE)
