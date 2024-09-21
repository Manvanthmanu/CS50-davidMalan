#include <stdio.h>

int main()
{

    const int length = 10;
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int digit = 11;

    int low = 0;
    int high = 9;

    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr1[mid] == digit)
        {
            printf("%d\n", mid);
            break;
        }
        else if (arr1[mid] > digit)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
        if (low > high)
        {
            printf("Digit not found\n"); // Print if the digit was not found
        }
    }

    return 0;
}