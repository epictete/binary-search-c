#include <stdio.h>
#include <stdbool.h>

int BinarySearch(int A[], int n, int x, bool searchFirst)
{
    int start = 0, end = n - 1, result = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (x == A[mid])
        {
            result = mid;
            if (searchFirst) end = mid - 1;
            else start = mid + 1;
        }
        else if (x < A[mid]) end = mid - 1;
        else start = mid + 1;
    }

    return result;
}

int main(void)
{
    int A[] = {1, 1, 3, 3, 5, 5, 5, 5, 5, 9, 9, 11};
    int n = sizeof(A) / sizeof(A[0]);
    int x;

    printf("Enter a number : ");
    scanf("%d", &x);

    int firstIndex = BinarySearch(A, n, x, true);

    if (firstIndex == -1) printf("Number %d could not be found\n", x);
    else
    {
        int lastIndex = BinarySearch(A, n, x, false);
        printf("Count of %d is %d\n", x, lastIndex - firstIndex + 1);
    }

    return 0;
}