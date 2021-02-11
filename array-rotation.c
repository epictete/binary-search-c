/* This algorithm assumes :
 * 1. A circularly rotated (sorted) array
 * 2. That there are no duplicates in the array
 */

#include <stdio.h>

int FindRotationCount(int A[], int n)
{
    int start = 0, end = n - 1;

    while(start <= end)
    {
        if (A[start] <= A[end]) return start;

        int mid = start + (end - start) / 2;
        int next = (mid + 1) % n;
        int prev = (mid - 1 + n) % n;

        if (A[mid] <= A[next] && A[mid] <= A[prev]) return mid;
        else if (A[start] <= A[mid]) start = mid + 1;
        else if (A[mid] <= A[end]) end = mid - 1;
    }

    return -1;
}

int main(void)
{
    int A[] = {15, 22, 23, 28, 31, 38, 5, 6, 8, 10, 12};
    int n = sizeof(A) / sizeof(A[0]);

    int count = FindRotationCount(A, n);

    printf("The array is rotated %d time(s)\n", count);

    return 0;
}