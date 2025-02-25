// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int c_counter = 0;

int* split_by_space(char* input, int cols, int input_len, int* numbers) {
    int digitIdxStart = 0;
    int digitIdxEnd = 0;
    char temp[5];
    
    int tempIdx = 0;
    int numbersIdx = 0;
    int temp_digit;
    for (int i = 0; i < input_len; i++) {
        if (isspace(input[i])) {
            digitIdxEnd = i-1;
            for (int j = digitIdxStart; j <= digitIdxEnd; j++) {
                temp[tempIdx] = input[j];
                //printf("Start: %d, End: %d, Current number: %c, Current temp idx: %d\n", digitIdxStart, digitIdxEnd, input[j], tempIdx);
                tempIdx++;
            }
            sscanf(temp, "%d", &temp_digit);
            numbers[numbersIdx] = temp_digit;
            
            numbersIdx++;
            digitIdxStart = i+1;

            memset(temp, '\0', sizeof(temp));
            tempIdx = 0;
        }else if (i==input_len-1) {
            digitIdxEnd = i;
            for (int j = digitIdxStart; j <= digitIdxEnd; j++) {
                temp[tempIdx] = input[j];
                //printf("Start: %d, End: %d, Current number: %c, Current temp idx: %d\n", digitIdxStart, digitIdxEnd, input[j], tempIdx);
                tempIdx++;
            }
            sscanf(temp, "%d", &temp_digit);
            numbers[numbersIdx] = temp_digit;
            
            numbersIdx++;
            digitIdxStart = i+1;
            
            memset(temp, '\0', sizeof(temp));
            tempIdx = 0;
        }
    
    }
    
    return numbers;
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
    printf("print the task instructions (here they are!)\n"
    "• print the task instructions\n"
    "• print the solution authors name\n"
    "• enter input data for array A\n"
    "• print the entered input data\n"
    "• create a one-dimensional array, C, containing the elements from array A that fall within the specified range [K-L], where K & L are input values\n"
    "• sort array C in ascending order\n"
    "• print array C before & after sorting\n");

    printf("\nAuthor: Boris-Mihail Gazibarov\n");
}

int* create_array_c(int** matrix, int* C, int bottom_range, int top_range, int rows) {
    c_counter = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            if (matrix[i][j] >= bottom_range && matrix[i][j] <= top_range) {
            } else {
                C[c_counter]=matrix[i][j];
                c_counter++;
            }
        }
    }
    
    return C;
}

int compare( const void* a, const void* b)
{
     int int_a = * ( (int*) a );
     int int_b = * ( (int*) b );
     
     if ( int_a == int_b ) return 0;
     else if ( int_a < int_b ) return -1;
     else return 1;
}

int main() {
    print_instructions();
    
    char crows[10], ccols[10];
    printf("\nEnter number of matrix rows: ");
    fgets(crows, 10, stdin);
    printf("Enter number of matrix columns: ");
    fgets(ccols, 10, stdin);
    
    int rows = atoi(crows);
    int cols = atoi(ccols);
    
    const int MAX_ROW_LEN = get_input_size(cols);
    char input[255];
    int input_len;
    
    int numbers[cols];
    int** matrix = malloc(sizeof(int*)*rows);
    for (int i = 0; i < rows; i++) {
        matrix[i] = malloc(sizeof(int)*cols);
        printf("Enter row #%d of the matrix:\n", i);
        
        fgets(input, MAX_ROW_LEN, stdin);
        input_len = get_array_len(input, sizeof(input) / sizeof(input[0]));
        int* converted_input = split_by_space(input, rows, input_len, numbers);
        
        for (int j = 0; j < cols; j++) {
                matrix[i][j] = converted_input[j];
        }
    }
    
    printf("Here's the matrix: \n");
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    int K, L;
    printf("\nEnter range for C: ");
    scanf("%d %d", &K, &L);

    int* C = create_array_c(matrix, numbers, K, L, rows);
    printf("Arary C (before sorting): \n");
    for (int i = 0; i < c_counter; i++) {
        printf("%d ", C[i]);
    }
    
    printf("\nArary C (after sorting): \n");
    qsort(C, c_counter, sizeof(int), compare);
    for (int i = 0; i < c_counter; i++) {
        printf("%d ", C[i]);
    }

    return 0;
}