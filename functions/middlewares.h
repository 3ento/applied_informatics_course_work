void split_by_space(char *input, int *results, size_t input_size);

int get_input_size(int columns);

int get_array_len(char *arr, int size);

void print_instructions();

int* create_array_c(int** matrix, int* C, int bottom_range, int top_range, int rows, int *c_counter);

void swap(int *x, int *y);

int partition(int array[], int low, int high);

void qsort_recursion(int array[], int low, int high);

void qsort_wrapper(int array[], int len);

void clear_input_buffer();

int get_valid_digit(const char *prompt);