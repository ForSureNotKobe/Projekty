#include <iostream>
#include <stdlib.h>
#include "kik.hh"

#define INF 2147483647

using namespace std;

bool KiK::Remis(bool echo)
{
  int i;
  
  for(i=1; i<roz*roz+1; i++)
    if(plansza[i]==' ')
      return false;
  if(echo==false)
  {
    system("clear");
    Plansza();
    cout<<endl<<"Gra zakonczyla sie remisem!"<<endl;
  }
  return true;
}

bool KiK::Wygrana(char gracz, bool echo)
{
  bool sprawdz;
  int i, k, j, licz=0;

  sprawdz = false;
  for(k=0; k<roz; k++) 
  {
    for(i=k*roz+1; i<k*roz+roz-prog+2;i++)
    {
      for(j=0; j<prog;j++)
      {
        if(plansza[i+j]==gracz)
          licz++;
      }
      if(licz==prog)
        sprawdz=true;
      else
        licz=0;
    }
  }

  if(sprawdz==false)
  {
    for(i=1; i<roz*(roz-prog+1)+1; i++)
    {
      for(j=0; j<prog; j++)
      {
        if(plansza[i+j*roz]==gracz)
          licz++;
      }
      if(licz==prog)
        sprawdz=true;
      else
        licz=0;
    }
  }

  if(sprawdz==false)
  {
    for(k=0; k<roz-prog+1;k++)
    {
      for(i=k*roz+prog; i<k*roz+roz+1; i++)
      {
        for(j=0; j<prog; j++)
        {
          if(plansza[i+j*roz-j]==gracz)
            licz++;
        }
        if(licz==prog)
          sprawdz=true;
        else
          licz=0;
      }
    }
  }
  
  if(sprawdz==false)
  {
    for(k=0; k<roz-prog+1;k++)
    {
      for(i=k*roz+1; i<k*roz+roz-prog+2;i++)
      {
        for(j=0; j<prog; j++)
        {
          if(plansza[i+roz*j+j]==gracz)
            licz++;
        }
        if(licz==prog)
          sprawdz=true;
        else
          licz=0;      
      }
    }
  }

  if(sprawdz==true)
  {
    if(echo==false)
    {
      system("clear");
      Plansza();
      cout<<endl<<"Gre wygrywa "<<gracz<<"!"<<endl<<endl;
    }
    return true;
  }
  return false;
}

int KiK::MiniMaxAB(char gracz, int alfa, int beta)
{
  int i, inf, x, pom;

  if(Wygrana(gracz, true))
  {
    if(gracz=='X')
      return 1;
    else
      return -1;
  }

  if(Remis(true))
    return 0;
  if(gracz=='X')
    gracz='O';
  else
    gracz='X';

  
  if(gracz=='X')
  {
    inf=-INF;
    for(i=1; i<roz*roz+1;i++)
    {
      if(plansza[i]==' ')
      {
        plansza[i]=gracz;
        pom=max(inf, alfa);
        x=MiniMaxAB(gracz, pom, beta);
        plansza[i]=' ';
        if(x>=beta)
          return x;
        inf=max(inf, x);
      }
    }
  }
  else
  {
    inf=INF;
    for(i=1; i<roz*roz+1;i++)
    {
      if(plansza[i]==' ')
      {
        plansza[i]=gracz;
        pom=min(inf, beta);
        x=MiniMaxAB(gracz, alfa, pom);
        plansza[i]=' ';
        if(x<=alfa)
          return x;
        inf=min(inf,x);
      }
    }
  }
  return inf;
}

int KiK::Przeciwnik()
{
  int ruch, i, wynik;
  int max;
  max=-10;
  
  for(i = 1; i < roz*roz+1; i++)
  {
    if(plansza[i] == ' ')
    {
      plansza[i] = 'X';
      wynik=MiniMaxAB('X', -INF, INF);
      plansza[i] = ' ';
      if(wynik > max)
      {
        max = wynik;
        ruch = i;
      }
    }
  }
  return ruch;
}

KiK::KiK(int rozm, int ile)
{
  int i;
  
  roz=rozm;
  prog=ile;

  plansza=new char[roz*roz+1];
  for(i=0; i<roz*roz+1; i++)
    plansza[i]=' ';
}

void KiK::Plansza()
{
  cout<<"Witaj w grze 'Kolko i Krzyzyk'"<<endl<<endl;
  cout<<"Gracz    --> O"<<endl;
  cout<<"Komputer --> X"<<endl;
  cout<<"-------------------------------"<<endl;
  if(prog>0)
    cout<<"Liczba znakow w rzedzie potrzebna do wygranej wynosi --> "<<prog<<"\n\n\n";
  for(int i=1; i<=roz*roz; i++)
  {        
    cout<<" "<<plansza[i]<<" ";
    if(i % roz)
      cout<<"|";
    else if (i!= roz*roz && i!=0)
    {
      cout<<endl;
      for(int j=0; j<roz; j++)
      cout<<"----";
      cout<<endl;
    }
    else
      cout<<endl<<endl;  
  }    
}

void KiK::Ruch(char &gracz)
{
  int ruch;
  system("clear");
  Plansza();
  if(gracz == 'O')
  {
    cout << "\nRuch: ";
    cin >> ruch;
  }
  else
  {
    ruch = Przeciwnik();
  }
  
  if((ruch >= 1) && (ruch < roz*roz+1) && (plansza[ruch] == ' '))
    plansza[ruch] = gracz;
  gracz = (gracz == 'O') ? 'X' : 'O';
}

void KiK::NowaPlansza()
{
  int i;
  for (i=0; i<roz*roz+1; i++)
    plansza[i]=' ';
}

void KiK::Gra()
{
  char wybor;
  char gracz;

  do 
  {
    gracz='O';
    NowaPlansza();
    while(!Wygrana('X', false) && !Wygrana('O', false) && !Remis(false))
      Ruch(gracz);
   
    cout<<"Czy chcesz zagrać jeszcze raz? Aby zrestartować grę wpisz T --> ";
    cin>>wybor;
   
  } while((wybor=='T')||(wybor=='t'));
}