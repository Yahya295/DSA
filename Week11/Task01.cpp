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
    void preorder(node* p)
    {
        if (p != NULL)
        {
            cout << p->data << endl;   // visit root
            preorder(p->LTree);        // visit left subtree
            preorder(p->RTree);        // visit right subtree
        }
    }

    void postorder(node* p)
    {
        if (p != NULL)
        {
            postorder(p->LTree);       // visit left subtree
            postorder(p->RTree);       // visit right subtree
            cout << p->data << endl;   // visit root
        }
    }

};

int main()
{
    BST obj;
    obj.create();

    cout << "\nInorder Traversal:\n";
    obj.inorder(obj.root);

    cout << "\nPreorder Traversal:\n";
    obj.preorder(obj.root);

    cout << "\nPostorder Traversal:\n";
    obj.postorder(obj.root);

    return 0;
}
