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

        while (c < 3)       // total nodes
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
    node* searchNode(node* curr, int num)       // searching a node (reference from theory slides)
    {
        if (curr == NULL)
        {
            return NULL;
        }

        if (curr->data == num)
        {
            return curr;
        }
        else if (num < curr->data)
        {
            return searchNode(curr->LTree, num);
        }
        else
        {
            return searchNode(curr->RTree, num);
        }
    }

    node* getParent(node* curr, node* prev, int num)    // get parent node (reference from theory slides)
    {
        if (curr == NULL)
        {
            return NULL;
        }

        if (curr->data == num)
        {
            return prev;
        }
        else if (num < curr->data)
        {
            return getParent(curr->LTree, curr, num);
        }
        else
        {
            return getParent(curr->RTree, curr, num);
        }
    }

    node* findMin(node* curr)       // find min value node (reference from theory slides)
    {
        while (curr != NULL && curr->LTree != NULL)
        {
            curr = curr->LTree;
        }

        return curr;
    }

    void deleteNode(int num)        // delete a specific node (reference from theory slides)
    {
        node* temp = searchNode(root, num);

        if (temp == NULL)
        {
            cout << "Node not found\n";
            return;
        }

        node* parent = getParent(root, NULL, num);

        // Case 1: Node is leaf node
        if (temp->LTree == NULL && temp->RTree == NULL)
        {
            if (parent == NULL)
            {
                root = NULL;
            }
            else if (parent->LTree == temp)
            {
                parent->LTree = NULL;
            }
            else
            {
                parent->RTree = NULL;
            }

            delete temp;
            cout << "Leaf node deleted successfully\n";
        }

        // Case 2: Node has only right child
        else if (temp->LTree == NULL && temp->RTree != NULL)
        {
            if (parent == NULL)
            {
                root = temp->RTree;
            }
            else if (parent->LTree == temp)
            {
                parent->LTree = temp->RTree;
            }
            else
            {
                parent->RTree = temp->RTree;
            }

            delete temp;
            cout << "Node with only right child deleted successfully\n";
        }

        // Case 3: Node has only left child
        else if (temp->LTree != NULL && temp->RTree == NULL)
        {
            if (parent == NULL)
            {
                root = temp->LTree;
            }
            else if (parent->LTree == temp)
            {
                parent->LTree = temp->LTree;
            }
            else
            {
                parent->RTree = temp->LTree;
            }

            delete temp;
            cout << "Node with only left child deleted successfully\n";
        }

        // Case 4: Node has two children
        else
        {
            node* minNode = findMin(temp->RTree);
            int minValue = minNode->data;

            deleteNode(minValue);

            temp->data = minValue;

            cout << "Node with two children deleted successfully\n";
        }
    }

};

int main()
{
    BST obj;
    obj.create();

    cout << "\nInorder Traversal:\n";
    obj.inorder(obj.root);

    int delValue;
    cout << "\nEnter value you want to delete: ";
    cin >> delValue;

    obj.deleteNode(delValue);

    cout << "\nBST after deletion in inorder traversal\n";
    obj.inorder(obj.root);


    return 0;
}
