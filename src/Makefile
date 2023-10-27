CC = g++ 
FLAGS = -std=c++17 -Wall -Werror -Wextra# -fsanitize=address -g
CLEAN = clean
TESTS = TEST/
SRCS = $(wildcard *.cc)
OBJS = ${SRCS:.cc = .o}
TEST_OBJS = ${SRCS_TEST:.cc = .o}
SRCS_TEST = $(wildcard $(TESTS)*.cc)
UNAME := $(shell uname)
TARGET = test

ifeq ($(UNAME), Linux)
 TEST_FLAGS += -lgtest -lsubunit -lrt -lpthread -lm
else
 TEST_FLAGS += -lgtest -lm
endif

%.o: %.c
	${CC} -c ${FLAGS} $@ $<

${TESTS}%.o: ${TESTS}%.c
	${CC} -c ${FLAGS} $@ $< 

all: ${CLEAN} install ${TARGET} dvi dist

.PHONY: ${TARGET} 
${TARGET} : $(SRCS) ${SRCS_TEST}
	${CC} ${FLAGS} -o TESTS ${SRCS} ${SRCS_TEST} ${TEST_FLAGS} 
	./TESTS

# qcustomplot:
# 	@if [ ! -d QCustomPlot-library ] || [ -z "$(ls -A QCustomPlot-library)" ]; then \
# 		git clone https://github.com/legerch/QCustomPlot-library; \
# 	fi

install:
	rm -rf Build_Calc; \
	mkdir Build_Calc; \
	(cd Build_Calc && cmake ../); \
	(cd Build_Calc && make); \

uninstall:
	rm -rf Build_Calc QCustomPlot-library

dist: |install
	tar --totals -cvf smart_calc.tar .

dvi:
	Doxygen .
	open html/index.html

build_file:
	mkdir Build_test

$(CLEAN) :
	rm -rf html latex Build_Calc Build_test TESTS *.a *.o $(TESTS).o *.out app *.tar *.info html_report TEST/*.o *.gcno *.gcda QCustomPlot-library
