#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

int
main(int argc, char *argv[]) {
	if (argc != 2) {
		fprintf(stderr, "Give me a file\n");
		return EXIT_FAILURE;
	}
	unsigned int fabric[SIZE][SIZE] = { 0 };
	FILE *input = fopen(argv[1], "r");
	unsigned int x, y, width, height;
	while (fscanf(input, "#%*u @ %u,%u: %ux%u\n", &x, &y, &width, &height) != EOF) {
		for (size_t row = y; row < y + height; row += 1) {
			for (size_t column = x; column < x + width; column += 1) {
				fabric[row][column] += 1;
			}
		}
	}
	unsigned int total = 0;
	for (size_t i = 0; i < SIZE; i += 1) {
		for (size_t j = 0; j < SIZE; j += 1) {
			if (fabric[i][j] > 1) {
				total += 1;
			}
		}
	}
	printf("%u\n", total);
	return EXIT_SUCCESS;
}
