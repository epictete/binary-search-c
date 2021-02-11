#include <stdio.h>

int BinarySearch(int A[], int start, int end, int x)
{
    if (start > end) return -1;
    
    int mid = start + (end - start) / 2;

    if (x == A[mid]) return mid;
    else if (x < A[mid]) return BinarySearch(A, start, mid - 1, x);
    else return BinarySearch(A, mid + 1, end, x);
}

int main(void)
{
    int A[] = {2, 6, 13, 21, 36, 47, 63, 81, 97};
    int n = sizeof(A) / sizeof(A[0]);
    int x;

    printf("Enter a number : ");
    scanf("%d", &x);

    int index = BinarySearch(A, 0, n - 1, x);

    if (index > -1) printf("Number %d was found at index %d\n", x, index);
    else printf("Number %d could not be found\n", x);

    return 0;
}