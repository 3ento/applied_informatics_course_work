#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "functions/middlewares.c"
#include "functions/quicksort.c"

int main() {
	print_instructions();

    int rows = get_valid_digit("Enter number of matrix rows (1-9): ");
    int cols = get_valid_digit("Enter number of matrix columns (1-9): ");

	const int MAX_ROW_LEN = get_input_size(cols);
	char input[MAX_ROW_LEN];
	int input_len;

	int numbers[cols] = {};
	int** matrix = malloc(sizeof(int*)*rows);
	for (int i = 0; i < rows; i++) {
		matrix[i] = malloc(sizeof(int)*cols);
		printf("Enter %d elments for row #%d of the matrix:\n", cols, i+1);

		fgets(input, MAX_ROW_LEN, stdin);
		input_len = get_array_len(input, sizeof(input) / sizeof(input[0]));
		split_by_space(input, numbers, input_len);
		for (int j = 0; j < cols; j++) {
			matrix[i][j] = numbers[j];
		}
		memset(numbers, 0, sizeof(numbers));
	}

	printf("Here's the matrix: \n");
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}

	int K, L;
    printf("\nEnter range for C: ");
    while (1) {
        if (scanf("%d %d", &K, &L) == 2) {  
            break;
        }
        printf("Invalid input. The range must be comprised of two numbers.\n");
        clear_input_buffer(); 
        printf("\nEnter range for C: ");  
    }

	int c_counter;
	int* C = create_array_c(matrix, numbers, K, L, rows, &c_counter);
	printf("Arary C (before sorting): \n");
	for (int i = 0; i < c_counter; i++) {
		printf("%d ", C[i]);
	}

	printf("\nArary C (after sorting): \n");
	qsort_wrapper(C, c_counter);
	for (int i = 0; i < c_counter; i++) {
		printf("%d ", C[i]);
	}
	
	free(matrix);

	return 0;
}

