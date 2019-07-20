#include <stdio.h>
#include <ctime>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <fstream>

using namespace std;
std::fstream plik;

	int a, b, c, i, j;
	clock_t start, stop;
	float czas;


int main() {

	srand(time(NULL));
	
	cout << "Podaj wielkosc macierzy kwadratowej: ";
	cin >> i;
	j=i*i;
	int *array1 = new int[j];
	int *array2 = new int[j];
	int *array3 = new int[j];
	
	
	for (a=0; a<j; a++)
	{
		array1[a]=3;
	}
	for (a=0; a<j; a++)
	{
		array2[a]=2;
	}
	

	start=clock();
	
	for (a=0; a<i; a++){	
		for(b=0; b<i; b++){
			array3[a*i+b]=0;
				for(c=0; c<i; c++){
				array3[a*i+b]=array3[a*i+b]+array1[a*i+c]*array2[c*i+b];
			}
		}
	}
			stop=clock();
		
			czas=(double)(stop-start)/CLOCKS_PER_SEC;
			cout<<"Czas mnozenia "<< czas << "s."<< endl;


plik.open( "mnozeniemacierzy.txt", std::ios::in | std::ios::out );
if( plik.good() == true )
{
    for (a=0; a<i; a++){	
		for(b=0; b<i; b++){
			cout << array3[a, b];
			}
		}
	}
 else 

cout << "Brak dostêpu do pliku!";





	delete [] array1;
	delete [] array2;
	delete [] array3;
	
	system("pause");
	return 0;
}
