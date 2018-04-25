#ifndef SORT_KOP_HH
#define SORT_KOP_HH


template <typename T>
void Max(T &tab, int rozm, int index)
{
  int lewy = (index + 1) * 2 - 1;
  int prawy = (index + 1) * 2;
  int max = 0;

  if (lewy<rozm && tab[lewy]>tab[index])
    max = lewy;
  else
    max = index;

  if (prawy<rozm && tab[prawy]>tab[max])
    max = prawy;

  if (max != index)
    {
      swap(tab[index],tab[max]);

      Max(tab, rozm, max);
    }
}


template <typename T>
void sort_kop(T &tab, int lewy, int prawy) {
  int rozm = prawy - lewy;
  int rozm_kop = rozm;

  for (int p=(rozm_kop-1)/2;p>=0;p--)
    Max(tab, rozm_kop, p);

  for (int i=rozm-1;i>0;i--)
    {
      swap(tab[0],tab[i]);
      rozm_kop--;
      Max(tab, rozm_kop, 0);
    }
}

#endif // SORT_KOP_H

