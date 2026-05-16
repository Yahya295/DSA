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
    void show(node* t)
    {
        if (t == NULL)
        {
            return;
        }
        cout << t->data << " ";
        show(t->next);
    }
    void insbeg(int d)
    {
        node* nn = new node(d);

        nn->next = head;
        head = nn;

        cout << "after insert at beginning: ";
        show(head);
        cout << endl;
    }
    void insend(int d)
    {
        node* nn = new node(d);

        if (head == NULL)
        {
            head = nn;
        }
        else
        {
            end2(head, nn);
        }
        cout << "after insert at end: ";
        show(head);
        cout << endl;
    }

    void end2(node* t, node* nn)
    {
        if (t->next == NULL)
        {
            t->next = nn;
            return;
        }
        end2(t->next, nn);
    }
    void inspos(int d, int p)
    {
        if (p <= 1)
        {
            insbeg(d);
            return;
        }
        pos2(head, d, p, 1);
        cout << "after insert at position: ";
        show(head);
        cout << endl;
    }
    void pos2(node* t, int d, int p, int c)
    {
        if (t == NULL)
        {
            cout << "invalid position\n";
            return;
        }

        if (c == p - 1)
        {
            node* nn = new node(d);

            nn->next = t->next;
            t->next = nn;
            return;
        }

        pos2(t->next, d, p, c + 1);
    }
    void delval(int v)
    {
        if (head == NULL)
        {
            cout << "list is empty\n";
            return;
        }
        head = dval(head, v);

        cout << "after delete by value: ";
        show(head);
        cout << endl;
    }
    node* dval(node* t, int v)
    {
        if (t == NULL)
        {
            return NULL;
        }
        if (t->data == v)
        {
            node* temp = t->next;
            delete t;
            return temp;
        }
        t->next = dval(t->next, v);
        return t;
    }
    void delpos(int p)
    {
        if (head == NULL)
        {
            cout << "list is empty\n";
            return;
        }

        head = dpos(head, p, 1);

        cout << "after delete by position: ";
        show(head);
        cout << endl;
    }
    node* dpos(node* t, int p, int c)
    {
        if (t == NULL)
        {
            cout << "invalid position\n";
            return NULL;
        }

        if (c == p)
        {
            node* temp = t->next;
            delete t;
            return temp;
        }

        t->next = dpos(t->next, p, c + 1);
        return t;
    }
    int search(node* t, int v, int c)
    {
        if (t == NULL)
        {
            return -1;
        }
        if (t->data == v)
        {
            return c;
        }

        return search(t->next, v, c + 1);
    }
};
int main()
{
    list ob;
    ob.insbeg(10);
    ob.insbeg(5);
    ob.insend(20);
    ob.insend(30);
    ob.inspos(15, 3);
    ob.delval(20);
    ob.delpos(2);
    cout << "list: ";
    ob.show(ob.head);
    cout << endl;
    int p = ob.search(ob.head, 30, 1);
    if (p == -1)
    {
        cout << "not found\n";
    }
    else
    {
        cout << "found at: " << p << endl;
    }
    return 0;

}