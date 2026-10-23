
#include <stdio.h>

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements: ");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int k = 0;

    for (int i = 0; i < n; i++)
    {
        int duplicate = 0;

        // Check if arr[i] already exists
        for (int j = 0; j < k; j++)
        {
            if (arr[i] == arr[j])
            {
                duplicate = 1;
                break;
            }
        }

        // If not duplicate, keep the element
        if (duplicate == 0)
        {
            arr[k] = arr[i];
            k++;
        }
    }

    printf("Array after removing duplicates: ");

    for (int i = 0; i < k; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\nNumber of unique elements (k) = %d", k);

    return 0;
}