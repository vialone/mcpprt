all: clean test run
test: example celrt
	@ld -lc main.o celrt.o
celrt:
	@g++ -g -fno-rtti -fno-exceptions -c celrt.cpp -o celrt.o
example:
	@g++ -g -fno-rtti -fno-exceptions -c example.cpp -o main.o
clean:
	@rm -f *.o *.S
run:
	@./a.out
