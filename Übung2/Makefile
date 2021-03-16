I={1..11}
USER= WaG
SOURCES = $(shell find . -iname '*.c' -exec basename {} .c ';') 

all: $(SOURCES) 
	@echo "compiliere"

say_hello:
	echo "Hello World"

files:
	@echo "Creating empty text files..."
	touch ${USER}-bsp{1..11}.c

clearn:
	@echo "Cleaning up"
	rm *.exe

%: %.c
	gcc -o $@.exe -lm -g -Wall $<
