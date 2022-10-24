#include <iostream>

using namespace std;

template <typename T>
class LinkedList
{

    class Node
    {
    public:
        T data;
        Node *next;
    };
    Node *head = new Node();

public:
    LinkedList(T data)
    {
        head->data = data;
    }
    void push(T data)
    {

        Node *temp = head;

        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        Node *newNode = new Node();
        newNode->data = data;
        temp->next = newNode;
    }
    void print()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    void pop()
    {
        Node *temp = head;

        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
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
    void addBefore(T data, T compare)
    {
        Node *newNode = new Node();
        newNode->data = data;
        if (head->data == compare)
        {
            newNode->next = head;
            head = newNode;
        }
        Node *temp = head;
        while (temp->next->data != compare)
        {

            temp = temp->next;
        }

        Node *temp2 = temp->next;
        temp->next = newNode;
        newNode->next = temp2;
    }
};

int main()
{
    LinkedList<int> a = LinkedList<int>(10);
    a.push(102);
    a.push(103);
    a.push(104);
    a.push(105);
    a.push(1062);

    a.addBefore(666, 10);

    a.print();
}