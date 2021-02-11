#include <stdio.h>

int BinarySearch(int A[], int n, int x)
{
    int start = 0, end = n - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (x == A[mid]) return mid;
        else if (x < A[mid]) end = mid - 1;
        else start = mid + 1;
    }

    return -1;
}

int main(void)
{
    int A[] = {2, 6, 13, 21, 36, 47, 63, 81, 97};
    int n = sizeof(A) / sizeof(A[0]);
    int x;

    printf("Enter a number : ");
    scanf("%d", &x);

    int index = BinarySearch(A, n, x);

    if (index > -1) printf("Number %d was found at index %d\n", x, index);
    else printf("Number %d could not be found\n", x);

    return 0;
}