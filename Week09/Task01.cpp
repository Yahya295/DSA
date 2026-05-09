#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node* next;
    node* prev;

    node(int d)
    {
        data = d;
        next = NULL;
        prev = NULL;
    }
};

class list
{
public:
    node* head;
    node* tail;

    list()
    {
        head = NULL;
        tail = NULL;
    }
    void insend(int d)
    {
        node* n = new node(d);

        if (head == NULL)
        {
            head = tail = n;
            return;
        }

        tail->next = n;
        n->prev = tail;
        tail = n;
    }
    void insstart(int d)
    {
        node* n = new node(d);

        if (head == NULL)
        {
            head = tail = n;
            return;
        }

        n->next = head;
        head->prev = n;
        head = n;
    }
    void inspos(int d, int p)
    {
        if (p <= 1)
        {
            insstart(d);
            return;
        }

        node* t = head;
        int c = 1;

        while (t != NULL && c < p - 1)
        {
            t = t->next;
            c++;
        }
        if (t == NULL || t == tail)
        {
            insend(d);
            return;
        }

        node* n = new node(d);

        n->next = t->next;
        n->prev = t;

        t->next->prev = n;
        t->next = n;
    }
    void delval(int v)
    {
        if (head == NULL)
        {
            cout << "list is empty\n";
            return;
        }

        node* t = head;

        while (t != NULL && t->data != v)
        {
            t = t->next;
        }

        if (t == NULL)
        {
            cout << "value not found\n";
            return;
        }
        if (t == head)
        {
            head = head->next;

            if (head != NULL)
            {
                head->prev = NULL;
            }
            else
            {
                tail = NULL;
            }

            delete t;
            return;
        }

        if (t == tail)
        {
            tail = tail->prev;
            tail->next = NULL;

            delete t;
            return;
        }

        t->prev->next = t->next;
        t->next->prev = t->prev;

        delete t;
    }
    void showf()
    {
        if (head == NULL)
        {
            cout << "list is empty\n";
            return;
        }

        node* t = head;

        cout << "forward: ";

        while (t != NULL)
        {
            cout << t->data << " ";
            t = t->next;
        }

        cout << endl;
    }
    void showr()
    {
        if (tail == NULL)
        {
            cout << "list is empty\n";
            return;
        }

        node* t = tail;

        cout << "reverse: ";

        while (t != NULL)
        {
            cout << t->data << " ";
            t = t->prev;
        }

        cout << endl;
    }
};

int main()
{
    list ob;

    ob.insend(67);
    ob.insend(76);
    ob.insend(99);
    cout<<"\n";
    ob.showf();
    ob.insstart(69);
    cout << "\n";
    ob.showf();
    ob.inspos(7, 2);
    cout << "\n";
    ob.showf();
    cout << "\n";
    ob.showf();
    cout << "\n";
    ob.showr();
    ob.delval(77);
    cout << "\n";
    ob.showf();
    ob.delval(79);
    cout << "\n";
    ob.showf();
    ob.delval(76);
    cout <<"\n";
    ob.showf();

    return 0;
}