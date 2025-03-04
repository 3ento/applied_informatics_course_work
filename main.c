// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/**@brief: takes a string containing numbers, seperated by a space, and stores them as integers in an int array
 * @param input: char array in the format [number-space-number-space-number]
 * @param results: integer array to store the numbers from input
 * @param input_size: size of the input, used to iterate through it
 * */
void split_by_space(char *input, int *results, size_t input_size) {
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

void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

int partition(int array[], int low, int high)
{
	int pivotValue = array[high];
	int i = low;

	for (int j = low; j < high; j++) {
		if (array[j] <= pivotValue) {
			swap(&array[i], &array[j]);
			i++;
		}
	}
	swap(&array[i], &array[high]);

	return i;
}

void qsort_recursion(int array[], int low, int high)
{
	if (low < high) {
		int pivotIdx = partition(array, low, high);
		qsort_recursion(array, low, pivotIdx-1);
		qsort_recursion(array, pivotIdx+1, high);
	}
}

void qsort_wrapper(int array[], int len)
{
	qsort_recursion(array, 0, len);
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