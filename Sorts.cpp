#include <iostream>

using namespace std;

template <typename T>
class Sort
{
public:
    static void insertionSort(T arr[], int size)
    {
        int j, key, i;
        for (i = 1; i < size; i++)
        {
            key = arr[i];
            j = i - 1;
            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    };
    static void selectionSort(T arr[], int size)
    {
        int i, j, min_indx;
        for (i = 0; i < n - 1; i++)
        {

            min_idx = i;
            for (j = i + 1; j < n; j++)
                if (arr[j] < arr[min_idx])
                    min_idx = j;

            if (min_idx != i)
                swap(&arr[min_idx], &arr[i]);
        }
    }
};

int main()
{
    int arr[] = {4, 3, 5, 6, 9, 8, 7, 1};

    Sort<int>::insertionSort(arr, 7);
    for (int i = 0; i < 8; i++)
    {
        cout << arr[i] << " ";
    }
}
