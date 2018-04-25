#ifndef TEST_HH
#define TEST_HH
#include <ctime>
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <iomanip>
#include "sort_scal.hh"
#include "sort_szybko.hh"
#include "sort_kop.hh"

using namespace std;

template <typename T>
ostream& operator<<(ostream& out,vector<vector<T>> tab)
{
  for(int i=0;i < int(tab.size());i++)
    {
      for(int j=0;j < int(tab[i].size());j++)
	{
	  out << tab[i][j] << endl;
	}
      out << "-----------------------" << endl;
    }
  return out;
}


template <typename T>
T odwroc_tab(T tab)
{
  T tmp_tab = tab;
  int k = 0;
  for (int i=0; i < int(tab.size()); i++)
    {
      k = int(tab[i].size()) - 1;
      for (int j=0; j< int(tab[i].size());j++)
        {
	  tmp_tab[i][j] = tab [i][k];
	  k--;
        }
    }
  return tmp_tab;
}

template <typename T>
double count_time_of_sorting(T &tab,string jaki_sort)
{

  auto start = chrono::high_resolution_clock::now();

  for(int i=0;i < int(tab.size());i++)
    {
      if(jaki_sort == "sort_szybko")
        {
	  sort_szybko(tab[i],0,int(tab[i].size()));
        }
      else if(jaki_sort == "sort_kopiec")
        {
	  sort_kop(tab[i],0,int(tab[i].size()));
        }
      else if(jaki_sort == "sort_scal")
        {
	  sort_scal(tab[i],0,int(tab[i].size()));
        }
    }

  auto finish = chrono::high_resolution_clock::now();

  chrono::duration<double> elapsed = finish - start;

  return elapsed.count();

}
void wypelnij_tab(vector <vector <int>> &tab, int wyp)
{
  for(int i=0;i < int(tab.size());i++)
    {
      for(int j=wyp;j < int(tab[i].size());j++)
	{
	  tab[i][j] = rand() % 10000;
	}
      for(int j=0;j < wyp;j++)
	{
	  tab[i][j] = rand() % 10000;
	}
      sort_szybko(tab[i],0,wyp);
    }
}
void test(int liczba_tablic, int liczba_elem_tablic)
{
  vector <vector <int>> tab1(liczba_tablic, vector<int> (liczba_elem_tablic));
  vector <vector <int>> tab2(liczba_tablic, vector<int> (liczba_elem_tablic));
  vector <vector <int>> tab3(liczba_tablic, vector<int> (liczba_elem_tablic));

  //Dla wszystkich elementow losowych
  int wyp = 0;
  cout<< "Test dla "<<liczba_tablic<<" tablic, ktore zawieraja "<< liczba_elem_tablic<<" elementow"<<endl;
  cout<<endl<<"[--------]";
    
  wypelnij_tab(tab1,wyp);
  tab2=tab1;
  tab3=tab1;

  double time_rand_tab_szybko=count_time_of_sorting(tab1,"sort_szybko");

  double time_rand_tab_kop=count_time_of_sorting(tab2,"sort_kopiec");

  double time_rand_tab_scal=count_time_of_sorting(tab3,"sort_scal");
  cout<<endl<<"[+-------]";
  //Dla 25% elementow losowych
  
  wyp = (0.25*liczba_elem_tablic);

  wypelnij_tab(tab1,wyp);
  tab2=tab1;
  tab3=tab1;

  double time_25_tab_szybko=count_time_of_sorting(tab1,"sort_szybko");

  double time_25_tab_kop=count_time_of_sorting(tab2,"sort_kopiec");

  double time_25_tab_scal=count_time_of_sorting(tab3,"sort_scal");
  cout<<endl<<"[++------]";
  //Dla 50% elementow losowych
  
  wyp = int (0.5*liczba_elem_tablic);

  wypelnij_tab(tab1,wyp);
  tab2=tab1;
  tab3=tab1;

  double time_50_tab_szybko=count_time_of_sorting(tab1,"sort_szybko");

  double time_50_tab_kop=count_time_of_sorting(tab2,"sort_kopiec");

  double time_50_tab_scal=count_time_of_sorting(tab3,"sort_scal");
  cout<<endl<<"[+++-----]";
  //Dla 75% elementow losowych
  
  wyp = int (0.75*liczba_elem_tablic);

  wypelnij_tab(tab1,wyp);
  tab2=tab1;
  tab3=tab1;

  double time_75_tab_szybko=count_time_of_sorting(tab1,"sort_szybko");

  double time_75_tab_kop=count_time_of_sorting(tab2,"sort_kopiec");

  double time_75_tab_scal=count_time_of_sorting(tab3,"sort_scal");
  cout<<endl<<"[++++----]";
  //Dla 95% elementow losowych
  
  wyp = int (0.95*liczba_elem_tablic);

  wypelnij_tab(tab1,wyp);
  tab2=tab1;
  tab3=tab1;

  double time_95_tab_szybko=count_time_of_sorting(tab1,"sort_szybko");

  double time_95_tab_kop=count_time_of_sorting(tab2,"sort_kopiec");

  double time_95_tab_scal=count_time_of_sorting(tab3,"sort_scal");
  cout<<endl<<"[+++++---]";
  //Dla 99% elementow losowych
  
  wyp = int (0.99*liczba_elem_tablic); 

  wypelnij_tab(tab1,wyp);
  tab2=tab1;
  tab3=tab1;

  double time_99_tab_szybko=count_time_of_sorting(tab1,"sort_szybko");

  double time_99_tab_kop=count_time_of_sorting(tab2,"sort_kopiec");

  double time_99_tab_scal=count_time_of_sorting(tab3,"sort_scal");
  cout<<endl<<"[++++++--]";
  //Dla 99,7% elementow losowych
  
  wyp = int (0.997*liczba_elem_tablic);

  wypelnij_tab(tab1,wyp);
  tab2=tab1;
  tab3=tab1;

  double time_997_tab_szybko=count_time_of_sorting(tab1,"sort_szybko");

  double time_997_tab_kop=count_time_of_sorting(tab2,"sort_kopiec");

  double time_997_tab_scal=count_time_of_sorting(tab3,"sort_scal");
  cout<<endl<<"[+++++++-]";
  //Dla posortowanych i odwroconych elementow

  odwroc_tab(tab1);
  tab2=tab1;
  tab3=tab1;

  double time_rev_tab_szybko=count_time_of_sorting(tab1,"sort_szybko");

  double time_rev_tab_kop=count_time_of_sorting(tab2,"sort_kopiec");

  double time_rev_tab_scal=count_time_of_sorting(tab3,"sort_scal");
  cout<<endl<<"[++++++++]"<<endl;
  
  cout << "Wszystkie losowe:  " <<"   "<< fixed << setprecision(4) << time_rand_tab_szybko <<"  "<<fixed << setprecision(4)<< time_rand_tab_kop << " "<<fixed << setprecision(4)<< time_rand_tab_scal<< endl;
  cout << "25% posortowane:   " <<"   "<< fixed << setprecision(4) << time_25_tab_szybko <<"  "<<fixed << setprecision(4)<< time_25_tab_kop << " "<<fixed << setprecision(4)<< time_25_tab_scal<< endl;
  cout << "50% posortowane:   " <<"   "<< fixed << setprecision(4) << time_50_tab_szybko <<"  "<<fixed << setprecision(4)<< time_50_tab_kop << " "<<fixed << setprecision(4)<< time_50_tab_scal<< endl;
  cout << "75% posortowane:   " <<"   "<< fixed << setprecision(4) << time_75_tab_szybko <<"  "<<fixed << setprecision(4)<< time_75_tab_kop << " "<<fixed << setprecision(4)<< time_75_tab_scal<< endl;
  cout << "95% posortowane:   " <<"   "<< fixed << setprecision(4) << time_95_tab_szybko <<"  "<<fixed << setprecision(4)<< time_95_tab_kop << " "<<fixed << setprecision(4)<< time_95_tab_scal<< endl;
  cout << "99% posortowane:   " <<"   "<< fixed << setprecision(4) << time_99_tab_szybko <<"  "<<fixed << setprecision(4)<< time_99_tab_kop << " "<<fixed << setprecision(4)<< time_99_tab_scal<< endl;
  cout << "99,7% posortowane: " <<"   "<< fixed << setprecision(4) << time_997_tab_szybko <<"  "<<fixed << setprecision(4)<< time_997_tab_kop << " "<<fixed << setprecision(4)<< time_997_tab_scal<< endl;
  cout << "Odwrócone:         " <<"   "<< fixed << setprecision(4) << time_rev_tab_szybko <<"  "<<fixed << setprecision(4)<< time_rev_tab_kop << " "<<fixed << setprecision(4)<< time_rev_tab_scal<< endl;

}




#endif // TEST_H

