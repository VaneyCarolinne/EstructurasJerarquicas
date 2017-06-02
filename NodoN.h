#ifndef NodoN_h
#define NodoN_h
#include <iostream>
using namespace std;
template<class T>// un tipo de dato generico 
class NodoN
{
	private:
		T elemento; //elemento generico 
		NodoN<T> *hiz, *hder;//apuntador a nodo generico
	public:	
		//Constructores					
		NodoN():hiz(NULL),hder(NULL){}//Sin parametros
		NodoN(T e):hiz(NULL),hder(NULL),elemento(e){}//Con parametro
		NodoN(T e, NodoN<T>* hijo, NodoN<T>* hermano):hiz(hijo),hder(hermano),elemento(e){}//Con parametro
		//Métodos de modificación
		void modificarElemento(T e){elemento=e;}
		void modificarDerecho(NodoN<T>* hermano){hder=hermano;}
		void modificarIzquierdo(NodoN<T>* hijo){hiz=hijo;}
		//Métodos de Inspección
		NodoN<T>* Obt_der()const{return(hder);}
		NodoN<T>* Obt_izq()const{return(hiz);}
		T obt_elemento()const{return(elemento);}
};

#endif

