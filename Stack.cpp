#include <iostream>

using namespace std;

template <typename T, int size>
class Stack
{

    T arr[size];
    int cursor;

public:
    Stack() : cursor(0){};

    void push(T data)
    {
        if (cursor + 1 == size)
        {
            cout << "Stack full" << endl;
        }
        arr[cursor++] = data;
    }
    T pop()
    {
        if (cursor == -1)
        {
            throw exception invalid_argument;
        }
        return arr[cursor--];
    }
    T peek(T data)
    {
        return arr[cursor];
    }
    void display()
    {
        for (int i = 0; i < cursor; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{

    Stack<int, 1000> a = Stack<int, 1000>();
    a.push(20);
    a.push(20);
    a.push(20);
    a.pop();
    a.pop();

    a.pop();
    a.pop();
    a.display();
}