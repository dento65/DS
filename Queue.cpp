#include <iostream>

using namespace std;
template <typename T, int size>
class Queue
{
    T arr[size];
    int rcursor = 0;
    int fcursor = 0;

public:
    Queue() {}

    void queue(T data)
    {
        if (rcursor + 1 == fcursor)
        {
            throw 500;
        }
        if (rcursor + 1 > size)
        {
            arr[rcursor] = data;
            rcursor = 0;
        }
        arr[rcursor++] = data;
    }
    T dequeue()
    {
        if (fcursor + 1 > size)
        {

            fcursor = 0;
        }
        return arr[fcursor++];
    }
    void print()
    {
        cout << fcursor << " " << rcursor << endl;
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
        if (rcursor <= fcursor)
        {

            for (int i = fcursor; i < size; i++)
                cout
                    << arr[i] << " ";

            for (int i = 0; i < rcursor; i++)
                cout << arr[i] << " ";
        }
        else
        {
            cout << fcursor << rcursor;

            for (int i = fcursor; i < rcursor; i++)
                cout << arr[i] << " ";
        }
    }
};

int main()
{
    Queue<int, 5> Q = Queue<int, 5>();

    Q.queue(20);
    Q.queue(30);
    Q.queue(40);
    Q.queue(50);
    Q.queue(60);
    Q.dequeue();
    Q.dequeue();

    Q.queue(80);

    Q.print();
}