#ifndef NodoB_h
#define NodoB_h
#include <iostream>
using namespace std;
template<class T>// un tipo de dato generico 
class NodoB
{
	private:
		T elemento; //elemento generico 
		NodoB<T> *hiz, *hder;//apuntador a nodo generico
	public:	
		//Constructores					
		NodoB():hiz(NULL),hder(NULL){}//Sin parametros
		NodoB(T e):hiz(NULL),hder(NULL),elemento(e){}//Con parametro
		NodoB(T e, NodoB<T>* hijo, NodoB<T>* hermano):hiz(hijo),hder(hermano),elemento(e){}//Con parametro
		//Métodos de modificación
		void modificarElemento(T e){elemento=e;}
		void modificarDerecho(NodoB<T>* hermano){hder=hermano;}
		void modificarIzquierdo(NodoB<T>* hijo){hiz=hijo;}
		//Métodos de Inspección
		NodoB<T>* Obt_der()const{return(hder);}
		NodoB<T>* Obt_izq()const{return(hiz);}
		T obt_elemento()const{return(elemento);}
};

#endif

