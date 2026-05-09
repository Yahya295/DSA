#include <iostream>
using namespace std;

class node
{
public:
    int id;
    int score;

    node* next;

    node(int i, int s)
    {
        id = i;
        score = s;
        next = NULL;
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

    void add(int i, int s)
    {
        node* nn = new node(i, s);

        if (head == NULL)
        {
            head = tail = cur = nn;
            nn->next = head;
            return;
        }

        tail->next = nn;
        nn->next = head;
        tail = nn;
    }

    void show()
    {
        if (head == NULL)
        {
            cout << "no players\n";
            return;
        }

        node* t = head;

        cout << "\nplayers:\n";

        do
        {
            cout << "player id: " << t->id << endl;
            cout << "score: " << t->score << endl;

            t = t->next;

        } while (t != head);
    }

    void turn()
    {
        if (cur == NULL)
        {
            cout << "no players\n";
            return;
        }

        cout << "\ncurrent turn: player " << cur->id << endl;

        cur = cur->next;
    }

    void skip()
    {
        if (cur == NULL)
        {
            cout << "no players\n";
            return;
        }

        cout << "\nplayer " << cur->id << " skipped\n";
        cur = cur->next;
        cout << "next player " << cur->id << endl;
        cur = cur->next;
    }
    void del(int i)
    {
        if (head == NULL)
        {
            cout << "no players\n";
            return;
        }
        node* t = head;
        node* p = tail;
        do
        {
            if (t->id == i)
            {
                break;
            }

            p = t;
            t = t->next;

        } while (t != head);
        if (t->id != i)
        {
            cout << "player not found\n";
            return;
        }
        if (head == tail && t == head)
        {
            delete t;
            head = tail = cur = NULL;

            cout << "all players removed\n";
            return;
        }
        if (t == head)
        {
            head = head->next;
            tail->next = head;
        }
        else if (t == tail)
        {
            tail = p;
            tail->next = head;
        }
        else
        {
            p->next = t->next;
        }
        if (cur == t)
        {
            cur = t->next;
        }
        delete t;
        cout << "player removed\n";
        if (head == tail)
        {
            cout << "\nwinner "<<head->id << endl;
        }
    }
};

int main()
{
    list ob;
    ob.add(1, 50);
    ob.add(2, 70);
    ob.add(3, 40);
    ob.add(4, 90);
    ob.show();
    ob.turn();
    ob.turn();
    ob.skip();
    ob.del(2);
    cout << "\nafter removing player:\n";
    ob.show();
    ob.del(3);
    ob.del(4);
    return 0;
}