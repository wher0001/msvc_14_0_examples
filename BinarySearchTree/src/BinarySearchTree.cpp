#include <stdexcept>
#include <string>
#include <iostream>

class Node
{
public:
    Node(int value, Node* left, Node* right)
    {
        this->value = value;
        this->left = left;
        this->right = right;
    }

    int getValue() const
    {
        return value;
    }

    Node* getLeft() const
    {
        return left;
    }

    Node* getRight() const
    {
        return right;
    }

private:
    int value;
    Node* left;
    Node* right;
};

class BinarySearchTree
{
public:
    static bool contains(const Node& root, int value) {
        if(value == NULL)
            return false;
        if(root.getValue() == value)
            return true;
        if(root.getValue() > value)
            return contains(*(root.getLeft()), value);
        else
            return contains(*(root.getRight()), value);
    }
};

#ifndef RunTests
int main()
{
    Node n1(3, NULL, NULL);
    Node n3(4, NULL, NULL);
    Node n2(2, &n1, &n3);

    std::cout << BinarySearchTree::contains(n2, 3);
}
#endif