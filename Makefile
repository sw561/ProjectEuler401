CC=g++
CFLAGS= -Wall -Wextra -pedantic -O3 -ansi
SOURCES=main.cpp set.cpp divisor.cpp
OBJECTS=$(SOURCES:.cpp=.o)
.PRECIOUS: test.o $(SOURCES:.cpp=_test.o)
EXECUTABLE=main

all: $(EXECUTABLE)

-include $(SOURCES:.cpp=.d) test.d

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

%_test: %_test.o %.o test.o 
	$(CC) $(CFLAGS) $*_test.o $*.o test.o -o $@

divisor_test: divisor_test.o divisor.o test.o set.o
	$(CC) $(CFLAGS) divisor_test.o divisor.o test.o set.o -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@
	$(CC) -MM $< > $*.d

%_defi.h.auto %_decl.h.auto %_proc.h.auto: %_list.txt
	python generate.py $<

clean:
	rm -f *.o $(EXECUTABLE) *_test *.pyc *.auto *.d
