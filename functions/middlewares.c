#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/**@brief: takes a string containing numbers, seperated by a space, and stores them as integers in an int array
 * @param input: char array in the format [number-space-number-space-number]
 * @param results: integer array to store the numbers from input
 * @param input_size: size of the input, used to iterate through it
 * */
void split_by_space(char *input, int *results, int input_size) {
	int is_prev_element_a_number = 0;
	int current_results_idx = 0;
	int negative = 0;

	for (int i = 0; i < input_size; i++) {
		if (isspace(input[i])) {
			if (negative == 1) {
				results[current_results_idx] *= -1;
				negative = 0;
			}
			
			if (is_prev_element_a_number == 1) {
			    current_results_idx++;
			    is_prev_element_a_number = 0;
			}
			continue;
		} else if (input[i]=='-') {
			negative = 1;
			is_prev_element_a_number = 1;
			continue;
		} else if (isdigit(input[i])) {
		    results[current_results_idx] *= 10;
    		results[current_results_idx] += input[i] - '0';
    		is_prev_element_a_number = 1;
		}
		
	}
	if (negative == 1) {
		results[current_results_idx] *= -1;
	}
}

int get_input_size(int columns) {
	return (columns*5)+(columns-1)+2;
}

int get_array_len(char *arr, int size) {
	for (int i = 0; i<size; i++) {
		if (arr[i] == '\0') {
			return i;
		}
	}
	return 0;
}

void print_instructions() {
	printf("Write a program to process a two-dimensional array, A[N][N], containing integers within the range[-1000, 1000]. Actions:\n");
	printf("print the task instructions (here they are!)\n");
	printf("print the task instructions\n");
	printf("print the solution authors name\n");
	printf("enter input data for array A\n");
	printf("print the entered input data\n");
	printf("create a one-dimensional array, C, containing the elements from array A that fall within the specified range [K-L], where K & L are input values\n");
	printf("sort array C in ascending order\n");
	printf("print array C before & after sorting\n");
	printf("\nAuthor: Boris-Mihail Gazibarov\n");
}

int* create_array_c(int** matrix, int* C, int bottom_range, int top_range, int rows, int *c_counter) {
	*c_counter = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < rows; j++) {
			if (matrix[i][j] >= bottom_range && matrix[i][j] <= top_range) {
			} else {
				C[*c_counter]=matrix[i][j];
				(*c_counter)++;
			}
		}
	}

	return C;
}

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int get_valid_digit(const char *prompt) {
    char input[3];
    printf("%s", prompt);
    while (1) {
        if (fgets(input, sizeof(input), stdin)) {
            if (isdigit(input[0]) && input[1] == '\n' && input[0] >= '1' && input[0] <= '9') {
                return input[0] - '0';
            }
        }
        printf("Invalid input. Try again...\n");
        clear_input_buffer();
    }
}