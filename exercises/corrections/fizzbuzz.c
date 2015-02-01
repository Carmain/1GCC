#include <stdio.h>

#define LIMIT 100

int main(void) {
	printf("FIZZBUZZ exercise, from 1 to %d :\n", LIMIT);

	for(int i = 1; i < LIMIT; i++) {
		if (i % 15 == 0) {
			printf("fizzbuzz ");
		} else if (i % 5 == 0) {
			printf("buzz ");
		} else if (i % 3 == 0) {
			printf("fizz ");
		} else {
			printf("%d ", i);
		}

		if (i % 10 == 0) {
			printf("\n");
		}
	}

	return 0;
}
