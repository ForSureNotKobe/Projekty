#include<iostream>
#include<cstdlib>
#include <fstream>


#include"kolejka.hh"

using namespace std;
main()
{
    int wybor;
	queue kolejka;
	do
    {
        cout<<"Kolejka priorytetowa"<<endl;
        cout<<"1. Wyswietl kolejke"<<endl;
        cout<<"2. Dodaj element do kolejki"<<endl;
        cout<<"3. Usun pierwszy element"<<endl;
        cout<<"4. Sortuj przez wstawianie"<<endl;
        cout<<"5. Sortuj przez wybor"<<endl;
        cout<<"6. Wyczysc terminal"<<endl;
        cout<<"7. Zakoncz program"<< endl;
        cin>>wybor;
        switch (wybor)
        {
            break;
		case 1:
            {
                cout <<"Element : priorytet"<<endl<<endl;
                kolejka.display();
                cout << "\n";
                break;
            }
		case 2:
            {
                int elem, prio;
                cout << "Podaj element i jego priorytet"<<endl;
                cin >> elem;
                cin >> prio;
                kolejka.push(elem,prio);
                break;
            }
		case 3:
            {
                kolejka.pop();
                cout << "Usunieto pierwszy element z kolejki!" << endl;
                break;
            }
		case 7:
            {
                cout << "Koniec dzialania programu!"<<endl;
                break;
            }
        case 5:
            {
                kolejka.sortuj(kolejka);
                cout<<"Wykonano sortowanie przez wybor!"<<endl;
                break;
            }
        case 4:
            {
                kolejka.sortujwstaw(kolejka);
                cout<<"Wykonano sortowanie przez wstawianie!"<<endl;
                break;
            }
        case 6:
            {
                cout<<system("CLS");
                break;
            }

        }
	} while (wybor != 7);
}
