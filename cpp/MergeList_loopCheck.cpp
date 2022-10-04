#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
    int data;
    node *next;
} *first = NULL, *second = NULL, *third = NULL;

void create1(int arr1[], int n)
{
    node *last, *t;
    first = new node;
    first->data = arr1[0];
    last = first;
    last->next = NULL;

    for (int i = 1; i < n; i++)
    {
        t = new node;
        last->next = t;
        t->data = arr1[i];
        last = t;
        last->next = NULL;
    }
}

void create2(int arr2[], int m)
{
    node *last, *t;
    second = new node;
    second->data = arr2[0];
    last = second;
    last->next = NULL;

    for (int i = 1; i < m; i++)
    {
        t = new node;
        last->next = t;
        t->data = arr2[i];
        last = t;
        last->next = NULL;
    }
}

void display(node *p)
{
    while (p)
    {
        cout << p->data << "->";
        p = p->next;
    }
    cout << endl;
}

void concate(node *p, node *q)
{
    third = first;
    while (p->next)
        p = p->next;
    p->next = q;
}

void merge(node *p, node *q)
{
    node *last;
    if (p->data < q->data)
    {
        third = last = p;
        p = p->next;
        third->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        third->next = NULL;
    }
    while (p && q)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if (p)
    {
        last->next = p;
    }
    if (q)
    {
        last->next = q;
    }
}
void create_loop(node *p)
{
    node *q;
    q = p->next->next->next->next->next;
    p = p->next->next;
    q->next = p;
}

int LoopCheck(node *t)
{
    node *q, *p;
    p = q = first;
    do
    {
        p = p->next;
        q = q->next;
        q = q ? q->next : q;

    } while (p && q && p != q);
    if (p == q)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

int main()
{
    int n, m, *arr1, *arr2;

    cout << "Enter no. of elements for array 1 :" << endl;
    cin >> n;
    arr1 = new int[n];
    cout << "Enter elements of 1st array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    cout << "Enter no. of elements for array 2: " << endl;
    cin >> m;
    arr2 = new int[m];
    cout << "Enter elements of 2nd array" << endl;
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }

    create1(arr1, n);
    cout << "First list" << endl;
    display(first);
    cout << "Second list" << endl;
    create2(arr2, m);
    display(second);
    // concate(first, second);
    // display(third);
    cout << "After merging both lists" << endl;
    merge(first, second);
    cout << "Third list" << endl;
    display(third);
    // create_loop(third);
    // cout << LoopCheck(third);
    return 0;
}
