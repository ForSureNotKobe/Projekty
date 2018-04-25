#ifndef SORT_SCAL_HH
#define SORT_SCAL_HH

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;


template <typename T>
void sort_scal(vector<T> &tab, T elem_L, T elem_P)
{
  if (elem_L >= elem_P) return;

  int piw = (elem_L + elem_P)/2;

  sort_scal(tab, elem_L, piw);
  sort_scal(tab, piw + 1, elem_P);

  vector<T> tmp(elem_P - elem_L + 1);

  int i = elem_L, j = piw + 1, k = 0;

  while (i < piw+1 && j < elem_P+1)
    {
      if (tab[i] <= tab[j])
        {
	  tmp[k] = tab[i];
	  i++;
        }
      else
        {
	  tmp[k] = tab[j];
	  j++;
        }
      k++;
    }

  if (i >= piw+1)
    {
      while (j < elem_P+1)
        {
	  tmp[k] = tab[j];
	  j++;
	  k++;
        }
    }
  else
    {
      while (i < piw+1)
        {
	  tmp[k] = tab[i];
	  i++;
	  k++;
        }
    }

  k = 0;
  for (i = elem_L; i < elem_P+1; i++)
    {
      tab[i] = tmp[k];
      k++;
    }
}
#endif // SORT_SCAL_HH

