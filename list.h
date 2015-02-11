#ifndef LIST_H
#define LIST_H
 
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
 
#include "node.h"
#include "node.cpp"
 
using namespace std;

template <class T>

class Median
{
    public:
        Median();
        ~Median();
		
		void del_all();
		bool checkOld(T);
        void addNew(T);
		void calculatePos(T);
        void calculateMedian();
		void sort();
		void print();
 
    private:
        Node<T> *m_head; // lista de elementos introducidos con unicidad 
		Node<T> *n_head; // lista de numero de veces que aparece repetido el elemento
        int m_num_nodes; // numero de elementos introducidos
};


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



template <class T>
 
class List
{
    public:
        List();
        ~List();
 
        void add_head(T);
        void add_end(T);
        void add_sort(T);
        void del_all();
        void del_by_data(T);
        void del_by_position(T);
        void fill_by_user(T);
        void fill_random(T);
        void invert();
        void print();
        int search(T);
        void sort();
		void minimum();
 
    private:
        Node<T> *m_head;
        int m_num_nodes;
};
 
#endif // LIST_H

