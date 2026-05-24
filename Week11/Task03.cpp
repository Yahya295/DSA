#include <iostream>
using namespace std;


                        // is code ka reference theory ki slides se lia gya ha 

class node
{
public:
    node* LTree, * RTree;
    int data;
};

class BST
{
public:
    node* root;

    BST()
    {
        root = NULL;
    }

    void create()       // creating node
    {
        node* p;
        int value, c = 0;

        while (c < 5)       // total nodes
        {
            if (root == NULL)   // if tree is empty then insert a new node and make left and right subtree null
            {
                root = new node;
                cout << "enter value of root node\n";
                cin >> root->data;
                root->RTree = NULL;
                root->LTree = NULL;
                c++;
            }
            else            // if tree isnt null, then it finds empty left or right child position and places the value there
            {
                p = root;
                cout << "enter value of node\n";
                cin >> value;

                while (true)
                {
                    if (value < p->data)
                    {
                        if (p->LTree == NULL)
                        {
                            p->LTree = new node;
                            p = p->LTree;
                            p->data = value;
                            p->LTree = NULL;
                            p->RTree = NULL;
                            cout << "value entered in left\n";
                            break;
                        }
                        else
                        {
                            p = p->LTree;
                        }
                    }
                    else if (value >= p->data)
                    {
                        if (p->RTree == NULL)
                        {
                            p->RTree = new node;
                            p = p->RTree;
                            p->data = value;
                            p->LTree = NULL;
                            p->RTree = NULL;
                            cout << "value entered in right\n";
                            break;
                        }
                        else
                        {
                            p = p->RTree;
                        }
                    }
                }

                c++;
            }
        }
    }
    void inorder(node* p)
    {
        if (p != NULL)
        {
            inorder(p->LTree);          // visit left subtree 
            cout << p->data << endl;    // visit root 
            inorder(p->RTree);          // visit right subtree
        }
    }

    bool search(node* p, int value)
    {
        if (p == NULL)          // if root is null then it means tree is empty, so the value cant be found
        {
            return false;
        }            
        if (p->data == value)   // root matches the value, return true
        {
            return true;
        }
        else if (value < p->data)   // search left tree for value using recursion
        {            
            return search(p->LTree, value);
        }
        else                        // search right tree for value using recursion
        {
            return search(p->RTree, value);
        }
    }
};

int main()
{
    BST obj;
    obj.create();

    cout << "\nInorder Traversal:\n";
    obj.inorder(obj.root);

    // Search value
    int searchVal;
    cout << "\n\nEnter value to search: ";
    cin >> searchVal;

    if (obj.search(obj.root, searchVal))
    {
        cout << searchVal << " found in BST.\n";
    }
    else
    {
        cout << searchVal << " not found in BST.\n";
    }

    return 0;
}
