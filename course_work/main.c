// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

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
    char str_cols[4];
    printf("Enter columns of the matrix: ");
    fgets(str_cols, 4, stdin);
    int cols = atoi(str_cols);

    int MAX_ROW_LEN = get_input_size(cols);


    char input[MAX_ROW_LEN];
    fgets(input, MAX_ROW_LEN, stdin);
    
    //char input[10] = {'-', '1', '2', ' ', '2'};
    
    int digitIdxStart = 0;
    int digitIdxEnd = 0;
    int numbers[cols];
    char temp[5];
    
    int input_len = get_array_len(input, sizeof(input) / sizeof(input[0]));
    
    int tempIdx = 0;
    int numbersIdx = 0;
    int temp_digit;
    for (int i = 0; i < input_len; i++) {
        if (isspace(input[i])) {
            digitIdxEnd = i-1;
            for (int j = digitIdxStart; j <= digitIdxEnd; j++) {
                temp[tempIdx] = input[j];
                printf("Start: %d, End: %d, Current number: %c, Current temp idx: %d\n", digitIdxStart, digitIdxEnd, input[j], tempIdx);
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
                printf("Start: %d, End: %d, Current number: %c, Current temp idx: %d\n", digitIdxStart, digitIdxEnd, input[j], tempIdx);
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
    
    for (int i = 0; i < cols; i++) {
        printf("%d ", numbers[i]);
    }

    return 0;
}