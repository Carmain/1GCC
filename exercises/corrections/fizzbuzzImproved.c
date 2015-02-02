#include <stdio.h>
#include <stdlib.h>

#define LIMIT 100

const char *words[] = {"%d ", "fizz ", "buzz ", "fizzbuzz "};

int main(void)
{
	printf("FIZZBUZZ exercise, from 1 to %d :\n\n", LIMIT);

	for (int i = 1; i < LIMIT; ++i) {
		printf(words[!(i % 3) + 2 * !(i % 5)], i);
	}

	return 0;
}
