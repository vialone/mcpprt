all: clean test run
test: example mrt
	@ld -lc main.o mrt.o
mrt:
	@g++ -g -fno-rtti -fno-exceptions -c mrt.cpp -o mrt.o
example:
	@g++ -g -fno-rtti -fno-exceptions -c example.cpp -o main.o
clean:
	@rm -f *.o *.S
run:
	@./a.out
