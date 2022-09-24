#include <stdio.h>

#define BUFFER_SIZE (1<<24)

static unsigned char buf1[BUFFER_SIZE];
static unsigned char buf2[BUFFER_SIZE];

int main(int argc, char** argv) {
	FILE *f1, *f2;
	size_t i;

	if (argc != 3) {
		fprintf(stderr, "USAGE: %s FILE1 FILE2\n", argv[0]);
		return 1;
	}

	f1 = fopen(argv[1], "rb");
	f2 = fopen(argv[2], "rb");

	if (!f1) {
		fprintf(stderr, "Could not read file '%s'\n", argv[1]);
		return 1;
	}
	if (!f2) {
		fprintf(stderr, "Could not read file '%s'\n", argv[2]);
		return 1;
	}

	for (;;) {
		size_t s1 = fread(buf1, 1, BUFFER_SIZE, f1);
		size_t s2 = fread(buf2, 1, BUFFER_SIZE, f2);
		size_t s = s1 > s2 ? s1 : s2;

		if (!s) {
			break;
		}

		for (i = 0; i < s; ++i) {
			putchar(buf1[i] | buf2[i]);
		}
	}

	return 0;
}
