#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100
int arr[MAX_SIZE];

void swap(int *p1, int *p2) {
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
    return;
}

void printArrLines(int arr[], int arrSize) {
    for (int i=0; i<arrSize; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return;
}

bool isValedNumber(char str[]) {
    for (int i=0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') return false;
    }
    return true;
}

int main(void) {
    int arrIdx = 0;

    printf("숫자를 입력하시면 배열에 넣어드려요! (\"Y\"를 입력할 시 입력이 완료됩니다.)\n");
    while(1) {
        char str[20];
        scanf("%s", str);
        if (str[0] == 'Y') break;
        // 이 아래에 atoi 가 작동 안될 시 에러메세지
        else if (!isValedNumber(str)) printf("숫자를 입력해주세욧!!!\n");
        else arr[arrIdx++] = atoi(str);
    }

    for (int i=0; i<arrIdx/2; i++) {
        swap(&arr[i], &arr[arrIdx-i-1]);
    }

    int arrSize = arrIdx;
    
    printArrLines(arr, arrSize);

    return 0;
}
