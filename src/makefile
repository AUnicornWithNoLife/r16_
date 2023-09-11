setup:
	@mkdir ./.build/
	@mkdir ./.build/.tmp/
	@mkdir ./.build/.tmp/lib/

finish:
	@rm -rf ./.build/.tmp

clean:
	@rm -rf ./.build

libs:
	@clang -c -o ./.build/.tmp/lib/carg-parse.o ./lib/carg-parse/carg-parse.c

main:
	echo not done yet

all:
	setup

	libs
	main

	finish