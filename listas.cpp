#include <iostream>

#include "list.h"
#include "list.cpp"

 
using namespace std;
 
int main()
{
    List<int> list_1;
	Median<int> median_1;


    int ele;
    int dim;
    int pos;
    string file_with_list;
 
    cout << "Dimension de la lista: " << endl;
    cin >> dim;
 
    list_1.fill_random(dim);
 
    cout << "Su lista es:" << endl;
    list_1.print();
 
    cout << "Agrega un elemento por la cabecera: " << endl;
    cin >> ele;
    list_1.add_head(ele);
    list_1.print();
 
    cout << "La lista invertida es: " << endl;
    list_1.invert();
    list_1.print();
 
    cout << "La lista ordenada es: " << endl;
    list_1.sort();
    list_1.print();
 
    cout << "Agrega un elemento. Sera insertado ordenadamente: " << endl;
    cin >> ele;
    list_1.add_sort(ele);
    list_1.print();
 
    cout << "Busca un elemento: " << endl;
    cin >> ele;
    list_1.search(ele);
 
    cout << "Elimina un elemento por dato: " << endl;
    cin >> ele;
    list_1.del_by_data(ele);
    list_1.print();
 
    cout << "Elimina un elemento por posicion: " << endl;
    cin >> pos;
    list_1.del_by_position(pos);
    list_1.print();
	
	cout << "el minimimo vale: " << endl;
	list_1.minimum();


    list_1.del_all();
    list_1.print();

	cout << "Ahora trabajamos con la mediana, generaremos una" <<endl
		 << "serie de valores aleatorios entre 0 y 1" <<endl<<endl;
	if (system("pause")){system("sleep 5");}

	int k;
	for (k=1;k<1000;k++)
	{
	median_1.addNew(rand() % 2);
	}

	cout<< "Se calcula la mediana para la siguiente lista:" << endl <<endl;
	median_1.calculateMedian();
	if (system("pause")){system("sleep 5");}
	cout << "La clase permite tambien calcular el valor en otras posiciones, ejemplo:"<<endl;
	median_1.calculatePos(727);
	median_1.del_all();
	cout<<endl;

	cout << "Ahora generaremos una serie de valores aleatorios" <<endl
		 << "entre 0 y 30 y calcularemos la media" <<endl<<endl;
	if (system("pause")){system("sleep 5");}


	Median<int> median_2;
	for (k=1;k<1000;k++)
	{
	median_2.addNew(rand() % 30);
	}

	cout<< endl << "Se calcula la mediana para la siguiente lista:" << endl << endl;
	median_2.calculateMedian();
	if (system("pause")){system("sleep 5");}
	cout <<endl<< "La clase permite tambien calcular el valor en otras posiciones, ejemplo:"<< endl << endl;
	median_2.calculatePos(350);

	median_2.del_all();
	if (system("pause")){system("sleep 5");}


    return 0;

}
