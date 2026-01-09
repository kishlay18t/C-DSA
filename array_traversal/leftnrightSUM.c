/* Given an array. 
Find the element such that the sum of elements on its right side = left side */

#include <stdio.h>
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

    int global_sum = 0; // global information
    for (int i = 0; i < n; i++)
    {
        global_sum += arr[i];
    }

    int left_sum = 0, right_sum;
    int key = -1;
    for (int i = 1; i < n; i++)
    {
        left_sum += arr[i-1];
        right_sum = global_sum - (left_sum + arr[i]);

        if (left_sum == right_sum)
        {
            key = i;
            break;
        }
    }

    if (key != -1)  printf("Result: %dth element\n", key+1);
    else    printf("The required element doesn't exist!\n");
}