#include <iostream>
#include <vector>
using namespace std;

int main ()
{
    int ILOSCkrawedzie;
    int ILOSCpunkty;
    cin >> ILOSCkrawedzie >> ILOSCpunkty;
    int punkt1, punkt2;
    vector<int> tablicaPoloczen[ILOSCpunkty];
    for (int i = 0; i < ILOSCkrawedzie; i++)
    {
        cin >> punkt1 >> punkt2;
        tablicaPoloczen[punkt1-1].push_back(punkt2);
        tablicaPoloczen[punkt2-1].push_back(punkt1);
    }
    int Odleglosc[ILOSCpunkty];
    for (int i = 0; i < ILOSCpunkty; i++)
    {
        Odleglosc[i]=-1;
    }
    Odleglosc[0] = 0;
    vector<int> Kolejka;
    Kolejka.push_back(1);
    while (Kolejka.size()>0)
    {
        Kolejka[0]-1;
        for (int i = 0; i < tablicaPoloczen[Kolejka[0]-1].size(); i++)
        {
            if(Odleglosc[Kolejka[0]-1] > -1)
            {
                cout << tablicaPoloczen[Kolejka[0]-1][i];
                Kolejka.push_back(tablicaPoloczen[Kolejka[0]-1][i]);
                Odleglosc[Kolejka[0]] = Odleglosc[Kolejka[0]-1]+1;
            }
        }
        Kolejka.erase(Kolejka.begin());
    }
    
}