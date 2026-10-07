#include <stdio.h>

int main()
{
    int n, data;
    int A[100];
    int l, r, mid;
    int flag = 0;
    int count = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100)
    {
        printf("Invalid number of elements.\n");
        return 1;
    }

    printf("Enter the elements in ascending order:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    printf("Enter the item to be searched: ");
    scanf("%d", &data);

    l = 0;
    r = n - 1;

    while (l <= r)
    {
        count++;
        mid = l + (r - l) / 2;

        if (A[mid] == data)
        {
            printf("Item found at index %d\n", mid);
            flag = 1;
            break;
        }
        else if (data < A[mid])
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    if (flag == 0)
    {
        printf("Item not found\n");
    }

    printf("\nNumber of comparisons/iterations = %d\n", count);

    printf("\nTime Complexity:\n");
    printf("Best Case    = O(1)\n");
    printf("Average Case = O(log n)\n");
    printf("Worst Case   = O(log n)\n");

    printf("\nSpace Complexity:\n");
    printf("Auxiliary Space = O(1)\n");
    printf("Input Space     = O(n)\n");

    return 0;
}
