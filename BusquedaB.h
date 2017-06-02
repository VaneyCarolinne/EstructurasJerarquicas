#ifndef BusquedaB_h
#define BusquedaB_h
#include "ArbolBin.h"
/********************************************************/
/*******************************************************/
/***Definición de la Clase Árbol de Busqueda Binaria***/
/*************Autora: Vanessa Cruz********************/
/****************************************************/
/***************************************************/
template <class T>
class ArbolBB: public ArbolB<T>{

		protected:
			NodoB<T>* BuscarNodo(T elem);
			void InsertarNodo(NodoB<T>* p, T elem);
			void EliminarNodo(T elem);
			T BuscarMenor(NodoB<T>* p);
		public:
			//Constructores
			ArbolBB<T>(){this->nodoRaiz=NULL;}
			ArbolBB<T>(T elem){this->nodoRaiz=new NodoB<T>(elem,NULL,NULL);}
			//Métodos de Inspección:
			bool Buscar(T elem);
			//Métodos Modificadores:
			void Insertar(T elem);
			void Eliminar(T elem);
			//Destructor:
			~ArbolBB();
};
/*****************************/
/***Métodos de Inspección:****/
/*****************************/
template <class T>
NodoB<T>* ArbolBB<T>::BuscarNodo(T elem)
{
		NodoB<T> *actual;
		
		actual=this->nodoRaiz;
		while(actual!=NULL&&actual->obt_elemento()!=elem)
		{
			if(elem<actual->obt_elemento())
			{
					actual=actual->Obt_izq();
			}else
			{
					actual=actual->Obt_der();
			}
		
		}
		return(actual);
}
template <class T>
bool ArbolBB<T>::Buscar(T elem)
{
	NodoB<T> *aux;
	
	aux=this->BuscarNodo(elem);
	return(aux!=NULL);
}
/*****************************/
/****Métodos Modificadores:***/
/*****************************/
template <class T>
void ArbolBB<T>::InsertarNodo(NodoB<T> *p, T elem)
{
		NodoB<T> *aux=NULL;
		
		if(p==NULL)
		{
				this->nodoRaiz=new NodoB<T>(elem);
		}else{
			if(elem<p->obt_elemento())
			{
				if(p->Obt_izq()==NULL){
					aux=new NodoB<T>(elem);
					p->modificarIzquierdo(aux);
				}else{
					InsertarNodo(p->Obt_izq(),elem);	
				}
			}else{
				if(p->Obt_der()==NULL)
				{
					aux=new NodoB<T>(elem);
					p->modificarDerecho(aux);	
				}else{
					 InsertarNodo(p->Obt_der(),elem);	
				}	
			}	
		}
}
template<class T>
void ArbolBB<T>::Insertar(T elem)
{
	this->InsertarNodo(this->nodoRaiz,elem);	
}
template <class T>
void ArbolBB<T>::Eliminar(T elem)
{
	if(this->nodoRaiz!=NULL)
	{
		EliminarNodo(elem);	
	}else{
	   cerr << "El Arbol esta vacio" << endl;
	}
}
template<class T>
void ArbolBB<T>::EliminarNodo(T elem){
	T min;
	NodoB<T> *ant, *act;
	
	act=this->nodoRaiz; 
	//Guardando los apuntadores anteriores hasta
	//que consiga el elemento
	while(act!=NULL && elem!=act->obt_elemento())
	{
		if(elem<act->obt_elemento())
		{
				ant=act;
				act=act->Obt_izq();
		}else{
				ant=act;
				act=act->Obt_der();
		}	
	}	
	if(act!=NULL){
		if(act->esHoja())
		{//eliminacion Directa
			if(ant->Obt_der()!=NULL && ant->Obt_der()->obt_elemento()==elem)
			{//eliminacion en caso de que tenga un solo hijo también
				ant->modificarDerecho(NULL);	
			}else{
				ant->modificarIzquierdo(NULL);	
			}
			delete(act);
		}else{
			if(act->Obt_der()!=NULL)
			{//el nodo tiene 2 hijos, busca el nodo con menor valor 
				//por la derecha
				min=BuscarMenor(act->Obt_der());	
			}else{
				min=act->Obt_izq()->obt_elemento();	
			}
			EliminarNodo(min);//vuelve a llamar la función para la eliminación
			//en donde encuentre el nodo
			act->modificarElemento(min);	
		}	
		
	}
} 
template <class T>
T ArbolBB<T>::BuscarMenor(NodoB<T>* p)
{
	if(p->Obt_izq()!=NULL)
	{
		while(p->Obt_izq()!=NULL)
		{
			p=p->Obt_izq();	
		}
		return(p->obt_elemento());	
	}else{
		return(p->obt_elemento());
	}	
}
/*********************************/
/**Único Destructor de la Clase:**/
/*********************************/	
template<class T>
ArbolBB<T>::~ArbolBB()
{
	this->vaciar();	
}
#endif
