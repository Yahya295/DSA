#include <iostream>
#include <string>
using namespace std;

class node
{
public:
    int id;
    string name;
    float dur;

    node* next;
    node* prev;

    node(int i, string n, float d)
    {
        id = i;
        name = n;
        dur = d;

        next = NULL;
        prev = NULL;
    }
};

class list
{
public:
    node* head;
    node* tail;
    node* cur;

    list()
    {
        head = NULL;
        tail = NULL;
        cur = NULL;
    }

    void add(int i, string n, float d)
    {
        node* nn = new node(i, n, d);

        if (head == NULL)
        {
            head = tail = cur = nn;
            return;
        }

        tail->next = nn;
        nn->prev = tail;
        tail = nn;
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "empty\n";
            return;
        }

        node* t=head;

        cout << "\nSong Playlist:\n";

        while (t!=NULL)
        {
            cout << "id: " << t->id << endl;
            cout << "name: " << t->name << endl;
            cout << "duration: " << t->dur << " min\n";
            t=t->next;
        }
    }

    void del(string n)
    {
        if (head == NULL)
        {
            cout << "empty\n";
            return;
        }

        node* t = head;

        while (t != NULL && t->name != n)
        {
            t = t->next;
        }

        if (t == NULL)
        {
            cout << "not found\n";
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

    void next()
    {
        if (cur == NULL)
        {
            cout<<"empty\n";
            return;
        }

        if (cur->next== NULL)
        {
            cout << "next is empty\n";
            return;
        }

        cur = cur->next;

        cout<<cur->name <<endl;
    }

    void prev()
    {
        if (cur == NULL)
        {
            cout<<"empty\n";
            return;
        }

        if (cur->prev == NULL)
        {
            return;
        }

        cur = cur->prev;

        cout<< cur->name << endl;
    }

    void rev()
    {
        if (head == NULL)
        {
            return;
        }

        node* t = head;
        node* temp = NULL;

        while (t != NULL)
        {
            temp = t->prev;
            t->prev = t->next;
            t->next = temp;

            t = t->prev;
        }

        temp = head;
        head = tail;
        tail = temp;
        cout << "reversed\n";
    }
};

int main()
{
    list ob;
    ob.add(1,"Nokia ringtone", 0.04);
    ob.add(2,"em superman",4.47);
    ob.add(3,"geo tou aise", 1.04);
    ob.add(4,"under bright lights", 3.48);
    ob.add(5,"ARY breaking news song", 6.7);
    ob.display();
    ob.next();
    ob.next();
    ob.prev();
    ob.del("em superman");
    cout << "\nafter deletion:\n";
    ob.display();
    ob.rev();
    cout << "\nafter reverse:\n";
    ob.display();
    return 0;
}