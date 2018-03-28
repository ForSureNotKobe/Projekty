#include "kolejka.hh"

using namespace std;

queue::queue()
{
    head=tail=NULL;
}

queue::~queue()
{
    while (head!=NULL) pop();
}

bool queue::empty()
{
    return !head;
}


int queue::front()
{
    if(head==NULL)
    {
        cout<<"Kolejka pusta!"<<endl;
    }
    else
    {
        return head->elem;
    }
}

//zwraca priorytet pierwszego elementu kolejki
int queue::frontprio()
{
    if(head==NULL)
    {
        cout<<"Kolejka pusta!"<<endl;
    }
    else
    {
        return head->prio;
    }
}

//umieszcza element w kolejce
void queue::push(int elem, int prio)
{
    list * p=new list;
    p->next = NULL;
    p->elem = elem;
    p->prio = prio;
    if(tail!=NULL)
    {
      tail->next=p;
      tail=p;
    }
    else
    {
      head=p;
      tail=p;
    }
}

//usuwa pierwszy element z kolejki
void queue::pop()
{
    if(head)
    {
        list* p=head;
        head=head->next;
        if(!head) tail=NULL;
        delete p;
    }
}


//wyswietla kolejke
void queue::display()
{
    list *p=new list;
    p=head;
    if(head==NULL)
    {
        cout<<"Kolejka pusta!"<<endl;
    }
    else
    {
        while(p!=NULL)
        {
            cout<< p->elem;
            cout<<":"<<" ";
            cout<< p->prio <<endl;
            p=p->next;
        }
    }
}

//sortowanie przez wstawianie
void queue::pushsort(int elem, int prio)
{
    list *p,*r;
    p= new list;
    p->next = NULL;
    p->prio = prio;
    p->elem = elem;
    if(!head)
    {
        head = tail = p;
    }
    else
        if(head->prio < prio)
        {
            p->next=head;
            head=p;
        }
        else
        {
            r=head;
            while((r->next) && (r->next->prio >= prio))
            {
                r = r->next;
            }
            p->next = r->next;
            r->next = p;
            if(!p->next) tail = p;
        }
}
