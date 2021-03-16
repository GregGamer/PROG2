I={1..11}
say_hello:
	echo "Hello World"

files:
	@echo "Creating empty text files..."
	touch WaG-bsp{1..11}.c

clearn:
	@echo "Cleaning up"
	rm *.exe

compile:
	gcc -o WaG-bsp${I}.exe -Wall -g WaG-bsp${I}.c
