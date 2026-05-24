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
    // recursive function to find minimum value
    node* findMin(node* curr)
    {
        while (curr != NULL && curr->LTree != NULL)
        {
            curr = curr->LTree;
        }

        return curr;
    }

    // recursive function to find maximum value
    node* findMax(node* curr)
    {
        while (curr != NULL && curr->RTree != NULL)
        {
            curr = curr->RTree;
        }

        return curr;
    }
};

int main()
{
    BST obj;
    obj.create();

    cout << "\nInorder Traversal:\n";
    obj.inorder(obj.root);

    node* minNode = obj.findMin(obj.root);
    node* maxNode = obj.findMax(obj.root);

    if (minNode != NULL)
    {
        cout << "Minimum value in BST: " << minNode->data << endl;
    }
    if (maxNode != NULL)
    {
        cout << "Maximum value in BST: " << maxNode->data << endl;
    }

    return 0;
}
