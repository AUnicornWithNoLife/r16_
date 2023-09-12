all: setup link

clean:
	@rm -rf ./.build

libs:
	@clang -c -o ./.build/.tmp/lib/carg-parse.o ./lib/carg-parse/carg-parse.c

setup:
	@mkdir -p ./.build/
	@mkdir -p ./.build/.tmp/

%.o: %.c
	clang -c -o $@ $<

link: $(wildcard *.o)
