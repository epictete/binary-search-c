/* This algorithm assumes :
 * 1. A circularly rotated (sorted) array
 * 2. That there are no duplicates in the array
 */

#include <stdio.h>

int CircularArraySearch(int A[], int n, int x)
{
    int start = 0, end  =n - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (x == A[mid]) return mid;
        else if (A[mid] <= A[end])
        {
            if (x > A[mid] && x <= A[end]) start = mid + 1;
            else end = mid - 1;
        }
        else
        {
            if (x >= A[start] && x < A[mid]) end = mid - 1;
            else start = mid + 1;
        }
    }

    return -1;
}

int main(void)
{
    int A[] = {12, 14, 18, 21, 3, 6, 8, 9};
    int n = sizeof(A) / sizeof(A[0]);
    int x;

    printf("Enter a number : ");
    scanf("%d", &x);

    int index = CircularArraySearch(A, n, x);

    if (index != -1) printf("Number %d was found at index %d\n", x, index);
    else printf("Number %d could not be found\n", x);

    return 0;
}