// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

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

int main() {
    char crows[10], ccols[10];
    printf("Enter number of matrix rows: ");
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
    
    printf("\n");
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}