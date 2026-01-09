/* You are given an array of numbers.
You must choose one continuous part of the array
Which such continuous part has the largest possible sum */

#include <stdio.h>
#include <stdlib.h>

#define max(a,b)    (a>b)?a:b

int main()
{
    int n;
    printf("Enter the size of array: ");
    scanf(" %d", &n);
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter the %dth element: ", i+1);
        scanf(" %d", arr + i);
    }

    printf("\nArray: ");
    for (int i = 0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
    int best_sofar = 0; // Best sum so far --> compare to running every iteration.
    int running = 0; // Running sum --> Discard if negative.

    for (int i = 0; i < n; i++)
    {
        running += arr[i];
        if (running < 0)
            running = 0;

        best_sofar = max(best_sofar, running);
    }

    printf("\nMaximum sum in the array: %d\n", best_sofar);
    return 0;
}