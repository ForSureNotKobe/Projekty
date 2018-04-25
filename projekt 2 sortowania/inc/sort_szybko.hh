#ifndef SORT_SZYBKO_HH
#define SORT_SZYBKO_HH

#include <iostream>
#include <cstring>
#include <ctime>

using namespace std;


template <typename T>
void sort_szybko(T &tab, int elem_L, int elem_P)
        {
            int i, j, piw;

            i = (elem_L + elem_P) / 2;
            piw = tab[i]; tab[i] = tab[elem_P];
            for(j = i = elem_L; i < elem_P; i++)
            if(tab[i] < piw)
            {
                swap(tab[i], tab[j]);
                j++;
            }
            tab[elem_P] = tab[j]; tab[j] = piw;
            if(elem_L < j - 1)  sort_szybko(tab, elem_L, j - 1);
                if(j + 1 < elem_P) sort_szybko(tab, j + 1, elem_P);
        }

#endif // SORT_SZYBKO_H

