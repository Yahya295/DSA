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

    void insbeg(int d)
    {
        node* nn = new node(d);

        if (head == NULL)
        {
            head = tail = nn;
        }
        else
        {
            nn->next = head;
            head->prev = nn;
            head = nn;
        }

        showf(head);
        cout << endl;
    }

    void insend(int d)
    {
        node* nn = new node(d);

        if (head == NULL)
        {
            head = tail = nn;
        }
        else
        {
            end2(head, nn);
        }

        showf(head);
        cout << endl;
    }

    void end2(node* t, node* nn)
    {
        if (t->next == NULL)
        {
            t->next = nn;
            nn->prev = t;
            tail = nn;
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

        showf(head);
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
            nn->prev = t;

            if (t->next != NULL)
            {
                t->next->prev = nn;
            }
            else
            {
                tail = nn;
            }

            t->next = nn;
            return;
        }

        pos2(t->next, d, p, c + 1);
    }

    void delval(int v)
    {
        head = dval(head, v);

        showf(head);
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

            if (temp != NULL)
            {
                temp->prev = t->prev;
            }
            else
            {
                tail = t->prev;
            }

            delete t;
            return temp;
        }

        t->next = dval(t->next, v);

        return t;
    }

    void delpos(int p)
    {
        head = dpos(head, p, 1);

        showf(head);
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

            if (temp != NULL)
            {
                temp->prev = t->prev;
            }
            else
            {
                tail = t->prev;
            }

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
    void showf(node* t)
    {
        if (t == NULL)
        {
            return;
        }
        cout << t->data << " ";
        showf(t->next);
    }
    void showr(node* t)
    {
        if (t == NULL)
        {
            return;
        }
        cout << t->data << " ";
        showr(t->prev);
    }

    bool pal(node* l, node* r)
    {
        if (l == NULL || r == NULL)
        {
            return true;
        }
        if (l == r || l->prev == r)
        {
            return true;
        }
        if (l->data != r->data)
        {
            return false;
        }
        return pal(l->next, r->prev);
    }
};

int main()
{
    list ob;
    ob.insbeg(2);
    ob.insend(4);
    ob.insend(6);
    ob.insend(4);
    ob.insend(2);
    ob.inspos(8, 3);
    ob.delval(8);
    ob.delpos(2);
    cout << "forward: ";
    ob.showf(ob.head);
    cout << "\nreverse: ";
    ob.showr(ob.tail);
    int p = ob.search(ob.head, 6, 1);
    cout << "\nsearch position: " << p << endl;
    if (ob.pal(ob.head, ob.tail))
    {
        cout << "palindrome\n";
    }
    else
    {
        cout << "not palindrome\n";
    }
    return 0;
}