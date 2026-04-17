#include <stdio.h>
int main() {
    int arr[5] = {3, 6, 9, 12, 15};
    int *p = &arr[0];
    int *q = &arr[3];

    int diff = *q - *p;
    printf("Difference = %d\n", diff);

    return 0;
}