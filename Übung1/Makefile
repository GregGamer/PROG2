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

clean:
	@echo "Cleaning up"
	rm *.exe

%: %.c
	gcc -o $@ -g -Wall $< -lm 

abgabe:
	tar cf ${USER}-bsp.tar *.c Makefile
	gzip *.tar
