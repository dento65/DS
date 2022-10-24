#include <iostream>

using namespace std;

template <typename T>
class CircularLinkedList
{

    class Node
    {
    public:
        T data;
        Node *next;
    };
    Node *head = new Node();
    Node *tail = new Node();

public:
    CircularLinkedList(T data)
    {
        head->data = data;
        head->next = head;
        tail = head;
    }
    void push(T data)
    {

        Node *newNode = new Node();
        newNode->data = data;

        tail->next = newNode;

        newNode->next = head;
        this->tail = newNode;
    }
    void print()
    {
        Node *temp = head;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    }
    T pop()
    {
        Node *temp = head;

        while (temp->next != tail)
        {
            temp = temp->next;
        }
        T a = temp->next->data;
        delete temp->next;
        temp->next = head;
        tail = temp;
        return a;
    }
    void addAfter(T data, T compare)
    {
        Node *temp = head;
        while (temp->data != compare)
        {

            temp = temp->next;
        }
        Node *newNode = new Node();
        newNode->data = data;

        Node *temp2 = temp->next;
        temp->next = newNode;
        newNode->next = temp2;
    }
};

int main()
{
    CircularLinkedList<int> a = CircularLinkedList<int>(10);
    a.push(102);
    a.push(103);
    a.push(104);
    a.push(105);
    a.push(1062);

    cout << a.pop() << endl;

    // a.addAfter(666, 1062);
    a.print();
}