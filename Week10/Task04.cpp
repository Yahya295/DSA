#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node* next;

    node(int d)
    {
        data = d;
        next = NULL;
    }
};
class list
{
public:
    node* head;

    list()
    {
        head = NULL;
    }
    void add(int d)
    {
        node* nn = new node(d);

        if (head == NULL)
        {
            head = nn;
            return;
        }

        add2(head, nn);
    }
    void add2(node* t, node* nn)
    {
        if (t->next == NULL)
        {
            t->next = nn;
            return;
        }

        add2(t->next, nn);
    }
    void displaylist(node* t)
    {
        if (t == NULL)
        {
            return;
        }
        cout << t->data << " ";

        displaylist(t->next);
    }
};
int main()
{
    list ob;
    ob.add(67);
    ob.add(76);
    ob.add(77);
    ob.add(99);
    ob.add(420);
    ob.add(69);
    cout << "list:\n";
    ob.displaylist(ob.head);
    return 0;

}