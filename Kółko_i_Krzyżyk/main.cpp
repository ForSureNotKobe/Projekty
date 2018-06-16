#include <iostream>
#include <stdlib.h>
#include "kik.hh"

using namespace std;

int main()
{
  int ile;
  int roz;
  char start;
  system("clear");

  cout<<"Podaj jakich wymiarów ma być plansza? X:X podaj X --> ";
  cin>>roz;
  cout<<endl<<"Podaj jaka jest wymagana liczba znakow w rzedzie do wygrania? --> ";
  cin>>ile;
  cout<<endl<<"Pola planszy są numerowane poziomami od lewej do prawej, zaczynając u góry.";
  cout<<endl<<"Dostępne numery planszy przy podanych rozmiarach to 1 - "<<roz*roz<<endl;
  KiK dane (roz, ile);
  cout<<endl<<"Aby rozpocząć wpisz T, aby anulować wpisz dowolny znak różny od T --> ";
  cin>>start;
  if((start=='T')||(start=='t'))
    dane.Gra();
}