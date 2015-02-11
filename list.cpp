#include "list.h"
#include <time.h>  
using namespace std;


// Constructor por defecto
template<typename T>
Median<T>::Median()
{
	m_num_nodes = 0;
    m_head = NULL; // toma los elementos
	n_head = NULL; // toma el numero de veces que se repite cada elemento
}


// Eliminar todos los nodos
template<typename T>
void Median<T>::del_all()
{
    m_head->delete_all();
    m_head = 0;
}

//chequear que  elemento
template<typename T>
bool Median<T>::checkOld(T element)
{
	
	Node<T> *temp_m = m_head;
    Node<T> *temp_n = n_head;
	if (temp_m)
	{
		while (temp_m)
		{
			if (element == temp_m->data)
			{
				temp_n->data++;
				m_num_nodes++;
				temp_m = temp_m->next;
				temp_n = temp_n->next;
				//cout << "elemento repetido: " << element <<" no se crea nuevo nodo. Numero elementos " << m_num_nodes<< endl;
				return true;
			}
			
			temp_m = temp_m->next;
			temp_n = temp_n->next;
		}
	}
	return false;
}



// Introducir nuevo elemento
template<typename T>
void Median<T>::addNew(T element)
{
	//cout << " checkold vale: "<< Median<T>::checkOld(element) << endl;
	bool antiguo = Median<T>::checkOld(element);
	if (!antiguo)
	{
		Node<T> *new_node_m = new Node<T> (element);
		Node<T> *new_node_n = new Node<T> (1);
		Node<T> *temp_m = m_head;
		Node<T> *temp_n = n_head;
		if (!m_head) {
			m_head = new_node_m;
			n_head = new_node_n;
		} else {
			new_node_m->next = m_head;
			new_node_n->next = n_head;
			m_head = new_node_m;
			n_head = new_node_n;

			while (temp_m) {
				temp_m = temp_m->next;
				temp_n = temp_n->next;
			}
		}
		m_num_nodes++;
		//cout << "elemento nuevo a~adido: "<< element <<" y numero elementos " << m_num_nodes << endl;
	}
}
// numero total de elementos
template<typename T>
void Median<T>::calculatePos(T num_nodos)
{
	Node<T> *temp_n = n_head;
	Node<T> *temp_m = m_head;
	int result;
	int sumAcum = 0;
	// calculamos el valor para la posicion num_nodos
	while ((sumAcum<num_nodos ) && (temp_n))
	{
		result = temp_m->data;
		sumAcum = sumAcum + (int) temp_n->data;
		temp_n = temp_n->next;
		temp_m = temp_m->next;
	}
	cout << "valor en la posicion " << num_nodos << " es " << result << endl; 
}

// calcula la media
template<typename T>
void Median<T>::calculateMedian()
{
	/*int result[2];
	Median<T>::calculateLength( m_num_nodes , result );*/
	cout << "Lista sin ordenar" << endl;
	Median<T>::print();
	Median<T>::sort();
	cout << "Lista ordenada" << endl;
	Median<T>::print();
	/* Para listas con número par de elementos esta función toma el 
	elemento que se encuentra en la mitad menos uno */
	Median<T>::calculatePos( m_num_nodes/2 );
	/* Si para listas con un numero par de elementos
	queremos coger el que está en la mitad más uno se utilizaría el 
	código que está a continuación */
/*	
	if (m_num_nodes%2)
	{
		Median<T>::calculatePos( m_num_nodes/2 +1);
	}else
	{
		Median<T>::calculatePos( m_num_nodes/2 );
	}
*/
}

// Ordenar de manera ascendente
template<typename T>
void Median<T>::sort()
{
    T temp_data_m;
	T temp_data_n;

    Node<T> *aux_node_m = m_head;
	Node<T> *aux_node_n = n_head;

    Node<T> *temp_m = aux_node_m;
	Node<T> *temp_n = aux_node_n;
 
    while (aux_node_m) {
        temp_m = aux_node_m;
		temp_n = aux_node_n;
 
        while (temp_m->next) {
            temp_m = temp_m->next;
			temp_n = temp_n->next;
 
            if (aux_node_m->data > temp_m->data) {
                temp_data_m = aux_node_m->data;
				temp_data_n = aux_node_n->data;
                aux_node_m->data = temp_m->data;
				aux_node_n->data = temp_n->data;
                temp_m->data = temp_data_m;
				temp_n->data = temp_data_n;
            }
        }
 
        aux_node_m = aux_node_m->next;
		aux_node_n = aux_node_n->next;
    }
}

// Imprimir la Lista
template<typename T>
void Median<T>::print()
{
    Node<T> *temp_m  = m_head;
	Node<T> *temp_n = n_head;
    if (!m_head)
	{
        cout << "La Lista esta vacia en print" << endl;
    } else {
		cout<<"element -> #elements" <<endl;
        while (temp_m) {
            temp_m->print();temp_n->print();cout<<endl;
            if (!temp_m->next) cout << "NULL";
                temp_m = temp_m->next;
				temp_n = temp_n->next;
        }
  }
  cout << endl << endl;
}


template<typename T>
Median<T>::~Median() {}






///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////




// Constructor por defecto
template<typename T>
List<T>::List()
{
    m_num_nodes = 0;
    m_head = NULL;
}
 
// Insertar al inicio
template<typename T>
void List<T>::add_head(T data_)
{
    Node<T> *new_node = new Node<T> (data_);
    Node<T> *temp = m_head;
 
    if (!m_head) {
        m_head = new_node;
    } else {
        new_node->next = m_head;
        m_head = new_node;
 
        while (temp) {
            temp = temp->next;
        }
    }
    m_num_nodes++;
}
 
// Insertar al final
template<typename T>
void List<T>::add_end(T data_)
{
    Node<T> *new_node = new Node<T> (data_);
    Node<T> *temp = m_head;
 
    if (!m_head) {
        m_head = new_node;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    m_num_nodes++;
}
 
// Insertar de manera ordenada
template<typename T>
void List<T>::add_sort(T data_)
{
    Node<T> *new_node = new Node<T> (data_);
    Node<T> *temp = m_head;
 
    if (!m_head) {
        m_head = new_node;
    } else {
        if (m_head->data > data_) {
            new_node->next = m_head;
            m_head = new_node;
        } else {
            while ((temp->next != NULL) && (temp->next->data < data_)) {
                temp = temp->next;
            }
            new_node->next = temp->next;
            temp->next = new_node;
        }
    }
    m_num_nodes++;
}

// Eliminar todos los nodos
template<typename T>
void List<T>::del_all()
{
    m_head->delete_all();
    m_head = 0;
}
 
// Eliminar por data del nodo
template<typename T>
void List<T>::del_by_data(T data_)
{
 
	int pos=List<T>::search(data_);
	List<T>::del_by_position(pos);

}
 
// Eliminar por posición del nodo
template<typename T>
void List<T>::del_by_position(T pos)
{
    Node<T> *temp = m_head;
    Node<T> *temp1 = temp->next;
 
    if (pos < 1 || pos > m_num_nodes) {
        cout << "Fuera de rango " << endl;
    } else if (pos == 1) {
        m_head = temp->next;
    } else {
        for (int i = 2; i <= pos; i++) {
            if (i == pos) {
                Node<T> *aux_node = temp1;
                temp->next = temp1->next;
                delete aux_node;
                m_num_nodes--;
            }
            temp = temp->next;
            temp1 = temp1->next;
        }
    }
}
 
// Llenar la Lista por teclado
template<typename T>
void List<T>::fill_by_user(T dim)
{
    T ele;
    for (int i = 0; i < dim; i++) {
        cout << "Ingresa el elemento " << i + 1 << endl;
        cin >> ele;
        add_end(ele);
    }
}
 
// Llenar la Lista aleatoriamente para enteros
template<typename T>
void List<T>::fill_random(T dim)
{
    srand(time(NULL));
    for (int i = 0; i < dim; i++) {
        add_end(rand() % 100);
    }
}

// Invertir la lista
template<typename T>
void List<T>::invert()
{
    Node<T> *prev = NULL;
    Node<T> *next = NULL;
    Node<T> *temp = m_head;
 
    while (temp) {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    m_head = prev;
}

// Imprimir la Lista
template<typename T>
void List<T>::print()
{
    Node<T> *temp = m_head;
    if (!m_head) {
        cout << "La Lista esta vacia " << endl;
    } else {
        while (temp) {
            temp->print();
            if (!temp->next) cout << "NULL";
                temp = temp->next;
        }
  }
  cout << endl << endl;
}
 
// Buscar el dato de un nodo
template<typename T>
int List<T>::search(T data_)
{
    Node<T> *temp = m_head;
    int cont = 1;
    int cont2 = 0;
 
    while (temp) {
        if (temp->data == data_) {
            cout << "El dato se encuentra en la posicion: " << cont << endl;
            cont2++;
			return cont;
        }
        temp = temp->next;
        cont++;
    }
 
    if (cont2 == 0) {
        cout << "No existe el dato " << endl;
    }
    cout << endl << endl;
}
 
// Ordenar de manera ascendente
template<typename T>
void List<T>::sort()
{
    T temp_data;
    Node<T> *aux_node = m_head;
    Node<T> *temp = aux_node;
 
    while (aux_node) {
        temp = aux_node;
 
        while (temp->next) {
            temp = temp->next;
 
            if (aux_node->data > temp->data) {
                temp_data = aux_node->data;
                aux_node->data = temp->data;
                temp->data = temp_data;
            }
        }
 
        aux_node = aux_node->next;
    }
}

// calcula el minimo
template<typename T>
void List<T>::minimum()
{
	Node<T> *temp = m_head;
	if (!m_head) 
	{
        cout << "La Lista esta vacia " << endl;
    } else
	{
	List<T>::sort();
	cout << "El valor minimo es: " << endl;
	temp->print(); cout << endl;
	}
}
 
template<typename T>
List<T>::~List() {}
