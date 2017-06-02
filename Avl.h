#ifndef AVL_h
#define AVL_h
#include "ArbolBin.h"
/********************************************************/
/*******************************************************/
/***Definición de la Clase Árbol de Busqueda Binaria***/
/*****************Balanceado (AVL)*********************/
/*************Autora: Vanessa Cruz********************/
/****************************************************/
/***************************************************/
template <class T>
class AVL: public ArbolBB<T>{
	private:
		//Rotaciones
		NodoB<T>* RSD(NodoB<T>* p);//Rotación Simple a la Derecha
		NodoB<T>* RSI(NodoB<T>* p);//Rotación Simple a la Izquierda
		NodoB<T>* RDDI(NodoB<T>* p);//Rotación doble derecha-izquierda
		NodoB<T>* RDID(NodoB<T>* p);//Rotación doble Izquierda-derecha
		//Métodos de Inspección:
		void es_AVL(NodoB<T>* p, bool &band, int &alt);
	public:
		//Constructores:
		AVL<T>(){this->nodoRaiz=NULL;}
		//Métodos de Modificación:
		void insertar_AVL(T elem);
		//Métodos de Inspección:
		int es_AVL();
		//Destructor:
		~AVL<T>(){this->vaciar();}
};
/*****************************/
/*********Rotaciones:*********/
/*****************************/
template<class T>
NodoB<T>* AVL<T>::RSD(NodoB<T>* p)
{
		NodoB<T> *nuevo;
		nuevo=p;
		p=p->Obt_izq();
		nuevo->modificarIzquierdo(p->Obt_der());
		p->modificarDerecho(nuevo);
		return(nuevo);
}
template<class T>
NodoB<T>* AVL<T>::RSI(NodoB<T>* p)
{
		NodoB<T> *nuevo;
		
		nuevo=p;
		p=p->Obt_der();
		nuevo->modificarDerecho(p->Obt_der());
		p->modificarIzquierdo(nuevo);
		return(p);
}
template<class T>
NodoB<T>* AVL<T>::RDDI(NodoB<T>* p)
{
		p->modificarIzquierdo(RSI(p->Obt_izq()));
		return(RSD(p));
}
template<class T>
NodoB<T>* AVL<T>::RDID(NodoB<T>* p)
{
		p->modificarDerecho(RSD(p->Obt_der()));
		return(RSI(p));
}
#endif
