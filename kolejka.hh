#ifndef KOLEJKA_HH
#define KOLEJKA_HH
#include<iostream>
#include<cstdlib>

using namespace std;

//Typ elementow kolejki priorytetowej
struct list {

  list *next;
  int prio;
  int elem;
};


class queue
{
    list *head;                          //wskaznik na poczatek kolejki
    list *tail;                          //wskaznik na koniec kolejki

public:
    queue();                            //konstruktor kolejki
    ~queue();                           //dekonstruktor kolejki
    bool empty();                       //sprawdza czy kolejka jest pusta
    int front();                        //zwraca poczatek kolejki
    int frontprio();                    //zwraca priotytet pierwszego elementu kolejki
    void push(int elem, int prio);      //dodaje element do kolejki
    void pop();                         //usuwa pierwszy element z kolejki
    void display();                     //wyswietla elementy kolejki
    void pushsort(int elem, int prio);  //sortuje kolejke wg priorytetu przez wstawianie
    list* Rhead() //dostep do glowy
    {
        return head;
    }

    list* Rtail() // dostep do ogona
    {
        return tail;
    }

    //zwraca pierwszy element kolejki i usuwa go
    list* frontpop()
    {
        list *p;
        if(head==NULL)
        {
            cout<<"Kolejka pusta! :("<<endl;
        }
        else
        {
            p=head;
            this->pop();
            return p;
        }
    }

    //wyszukuje element o najwieszszym priorytecie
    list* findMax()
    {
        list* p, *pmax;
        pmax=head;
        if(head)
    {
        for(p=head->next;p;p=p->next)
        {
            if(p->prio>pmax->prio)
            {
                pmax=p;
            }
        }
    }
        return pmax;
    }

    // usuwa konkrety element z listy
    void remove(list* e)
    {
        list* p;
        if(head==e)
        {
            p=head;
            if(p)
            {
                head=p->next;
                delete p;
            }
        }
        else
        {
            p=head;
            while(p->next!=e)
            {
                p=p->next;
            }
            p->next=e->next;
            delete e;
        }
    }

    //sortowanie przez wybor
    void sortuj(queue &kolejka)
    {
        queue P;
        list*e=new list;
        while(!kolejka.empty())
        {
            e->next = NULL;
            e->elem = kolejka.front();
            e->prio = kolejka.frontprio();
            kolejka.frontpop();
            P.push(e->elem,e->prio);
        }
        while(!P.empty())
        {
            e=P.findMax();
            kolejka.push(e->elem,e->prio);
            P.remove(e);
        }
    }

    //sortowanie przez wstawianie
    void sortujwstaw(queue &kolejka)
    {
        queue P;
        list*e=new list;
        while(!kolejka.empty())
        {
            e->next = NULL;
            e->elem = kolejka.front();
            e->prio = kolejka.frontprio();
            kolejka.frontpop();
            P.pushsort(e->elem,e->prio);
        }
        while(!P.empty())
        {
            e->next = NULL;
            e->elem = P.front();
            e->prio = P.frontprio();
            kolejka.push(e->elem,e->prio);
            P.pop();
        }
    }
};

#endif
