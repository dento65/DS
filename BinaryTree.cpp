
#include <iostream>

using namespace std;

template <typename T>
class BinaryTree
{
public:
    class node
    {
    public:
        node(T data) : data(data), left(nullptr), right(nullptr) {}
        T data;
        node *left;
        node *right;
    };

    node *Root;
    int count = 10;

    BinaryTree(T root)
    {
        node *newNode = new node(root);
        this->Root = newNode;
    }

private:
    void insertUtil(T data, node *root)
    {

        if (data > root->data)
        {
            if (root->right != nullptr)
            {
                insertUtil(data, root->right);
            }
            else
                root->right = new node(data);
        }
        else
        {
            if (root->left != nullptr)
            {
                insertUtil(data, root->left);
            }
            else
                root->left = new node(data);
        }
    }
    void print2DUtil(node *root, int space)
    {

        if (root == NULL)
            return;

        space += count;

        print2DUtil(root->right, space);

        cout << endl;
        for (int i = 10; i < space; i++)
            cout << "-";
        cout << root->data << endl;

        print2DUtil(root->left, space);
    }
    void removeUtil(T data, node *root)
    {
        cout << root->data << endl;
        if (root->right)
            if (root->left->data == data)
            {
                cout << "hello" << endl;
                delete root->left;
                root->left = nullptr;
                return;
            }
        if (root->right)
            if (root->right->data == data)
            {
                cout << "hello" << endl;

                delete root->right;
                root->right = nullptr;
                return;
            }

        if (root->left !=)
            removeUtil(data, root->right);
        if (root->right)
            removeUtil(data, root->left);
    }

public:
    void
    insert(T data)
    {
        insertUtil(data, Root);
    }
    void print2D()
    {
        print2DUtil(Root, 0);
    }

    void remove(T data)
    {
        removeUtil(data, Root);
    }
};

int main()
{

    BinaryTree<int> B = BinaryTree<int>(15);

    int a[] = {2, 20, 7, 1, 17, 12, 9, 5, 16, 55, 4, 30, 3, 40, 6, 32, 11, 25};
    for (int i = 0; i < 18; i++)
    {
        B.insert(a[i]);
    }
    B.remove(3);
    B.print2D();
    cout << B.Root->data << endl;
}
