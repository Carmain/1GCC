#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 0
#define MAX 100
#define LIVES 5

int randint(int min, int max);

int main(void) {
	// On définit le point de départ de rand()
	srand(time(NULL));

	for (int i = LIVES; i--; ) {
		printf("%d\n", randint(MIN, MAX));
	}

	return 0;
}

/* randint : return a randomly generated number between min and max */
int randint(int min, int max) {
	return rand() % (max - min) + min;
}
