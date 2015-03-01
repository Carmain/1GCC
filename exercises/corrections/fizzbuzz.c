#include <stdio.h>

#define LIMIT 100

int main(void) {
        printf("FIZZBUZZ exercise, from 1 to %d :\n\n", LIMIT);

        for(int i = 1; i < LIMIT; i++) {
                if (i % 15 == 0) {
                        printf("fizzbuzz\n");

                } else if (i % 5 == 0) {
                        printf("buzz\n");
                } else if (i % 3 == 0) {
                        printf("fizz\n");
                } else {
                        printf("%d\n", i);
                }
        }

        return 0;
}
