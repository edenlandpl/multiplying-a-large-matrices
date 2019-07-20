#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
// natywna wersja - bez zmian ~4000 sek

/*dekompozycja()
{
    // PODZIAL GLOWNYCH MACIERZY NA CWIARTKI

}

}*/
int main(int argc, char** argv)
{
    clock_t start = clock();
	int i,j,k, liczba, zakres=3000; // zakres macierzy podaj -1, bo liczy od 0
	float ** mac01 = new float * [zakres];
	float ** mac02 = new float * [zakres];
	float ** mac03 = new float * [zakres];
	for(i=0;i<zakres;i++)
    {
        mac01[i] = new float [zakres];
        mac02[i] = new float [zakres];
        mac03[i] = new float [zakres];
    }
cout << "Losowo zapisywane macierze" << endl;
	//int mac01[zakres][zakres];
	//int mac02[zakres][zakres];
	//int mac03[zakres][zakres];
		for(i=0;i<zakres;i++)
		{
			for(j=0;j<zakres;j++)
				{
					//mac01[i][j]=( (rand() / (float)RAND_MAX * 3) );
					//mac02[i][j]=( (rand() / (float)RAND_MAX * 3) );
                    mac01[i][j]=1;
					mac02[i][j]=1;
				}
		}

cout << "Mnozenie" << endl;
clock_t czas_start = clock();
	for(i=0;i<zakres;i++)
		{
			for(j=0;j<zakres;j++)
				{
					mac03[i][j]=0;
					for(k=0;k<zakres;k++)
					{
					 mac03[i][j] += mac01[i][k] * mac02[k][j];
					}
				}
		}
		clock_t czas_stop = clock();
		cout<< czas_stop - czas_start <<endl;
	fstream plik;
plik.open( "macierz.txt", ios::in |ios::out|  ios::trunc );
cout << "Zapis do pliku" << endl;
if( plik.good() == true ){
    cout << "Uzyskano dostep do pliku!" << endl;
    //tu operacje na pliku
    for(i=0;i<zakres;i++)
		{
			for(j=0;j<zakres;j++)
				{
				//cout << mac03[i][j]<< " "; // wysiwetlanie na ekranie
				plik << mac03[i][j]<< " " << ", ";
            	//plik.flush();
				}//cout << "Miejsce 04" << endl;
			plik << endl;
		//	cout << endl; // nowa linia
		}//cout << "Miejsce 05" << endl;
   //  plik.clear(); // czyszczenie pliku
} else cout << "Dostep do pliku zostal zabroniony!" << endl;

	 // plik.clear();
		//cout << endl;
//cout << "Miejsce 06" << endl;
		plik.close();
		cout << "Zapisane w pliku" << endl;
// zapis do pliku i/o
// pomiar czasu
// dekompozycja - niekoniecznie/**/
	return 0;
}
