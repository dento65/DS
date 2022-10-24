#include <iostream>

using namespace std;

int main()
{

    int arr[10] = {4,
                   2,
                   56,
                   52,
                   415,
                   44,
                   31,
                   1,
                   2,
                   5};

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (arr[i] < arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl
         << "Enter the number to be searched: ";
    int num;
    cin >> num;
    int mid = 10 / 2;
    for (int i = 0; i < 4; i++)
    {

        if (arr[mid] == num)
        {
            cout << "Found at " << mid;
            return 0;
        }
        else if (arr[mid] > num)
        {
            mid = mid / 2;
        }
        else if (arr[mid] < num)
        {
            mid = mid + mid / 2;
        }
    }
}