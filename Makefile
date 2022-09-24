.PHONY: clean build

merge: merge.c
	cc $^ -o $@ -Wall -Wextra -Werror -ansi -pedantic -O3 $(CCFLAGS)

build: merge

clean:
	rm -f merge
