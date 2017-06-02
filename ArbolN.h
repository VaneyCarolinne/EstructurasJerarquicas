#ifndef ArbolN_h
#define ArbolN_h
#include "NodoN.h"
#include <cmath>
#include <list>
#include <queue>
using std::list;
using std::queue;
/********************************************************/
/*******************************************************/
/***********Definición de la Clase Árbol N-ario********/
/*************Autora: Vanessa Cruz********************/
/****************************************************/
/***************************************************/
template <class T>
class ArbolN
{	
		//atributos:
		private:
			NodoN<T> *nodoRaiz;
		//metodos:
		private:
			//Recorridos:
			void PostOrden(NodoN<T>* arbn);
			void PreOrden(NodoN<T>* arbn);
			void InOrden(NodoN<T>* arbn);
			void c_preorden(NodoN<T>* arbn, list<T> &l);
			void c_postorden(NodoN<T>* arbn, list<T> &l);
			void c_inorden(NodoN<T>* p, list<T> &l);
			//Metodos de Modificacion:
			void vaciar(NodoN<T> *p);
			NodoN<T>* copiar(NodoN<T> *p);
			//Metodos de Inspeccion:
			void ObtPeso(NodoN<T> *p, int &peso);
			void Altura(NodoN<T> *p, int &alt);
		public:								
			//Constructores:
			ArbolN<T>():nodoRaiz(NULL){}
			ArbolN(const ArbolN<T> &a);	
			ArbolN(T e);
			ArbolN(T e, list< ArbolN<T> > &A);
			//Metodos de Inspeccion:
			bool esNulo(){return(nodoRaiz==NULL);}
			T raiz(){return(nodoRaiz->obt_elemento());}
			list< ArbolN<T> > hijos();
			bool esHoja(){return(nodoRaiz->Obt_der()==NULL&&nodoRaiz->Obt_izq()==NULL);}
			int Obt_Peso();
			int Altura();
			//Recorridos:
			void PostOrden(){PostOrden(nodoRaiz);}
			void PreOrden(){PreOrden(nodoRaiz);}
			void InOrden(){InOrden(nodoRaiz);}
			void Niveles();
			list<T> r_preorden();
			list<T> r_inorden();
			list<T> r_postorden();
			list<T> Cargar_Niveles();
			//Metodos de Modificacion:
			void copiar(ArbolN &A){nodoRaiz=copiar(A.nodoRaiz);}
			void insertar(ArbolN<T> &A);
			void eliminar(int pos);
			void vaciar();
			//Sobrecarga de operadores:
			void operator=(const ArbolN<T> &a);
			//Destructor: 
			~ArbolN();
};
/******************************************/
/********Constructores de la Clase:*******/
/*****************************************/
template <class T>
ArbolN<T>::ArbolN(const ArbolN<T> &a)
{		
	*this=a;
}
template <class T>
ArbolN<T>::ArbolN(T e)
{
	nodoRaiz=new NodoN<T>(e,NULL,NULL);
}
template <class T>
ArbolN<T>::ArbolN(T e, list< ArbolN<T> > &l)
{
	NodoN<T> *aux;
	nodoRaiz=new NodoN<T>(e,NULL,NULL);
	if(!l.empty())
	{
			nodoRaiz->modificarIzquierdo(copiar(l.front().nodoRaiz));
			l.pop_front();
			aux=nodoRaiz->Obt_izq();
			while(!l.empty())
			{
					aux->modificarDerecho(copiar(l.front().nodoRaiz));
					l.pop_front();
					aux=aux->Obt_der();
			}
	}
	
}
/*****************************/
/**********Recorridos:********/ 
/*****************************/
template <class T>
void ArbolN<T>::PostOrden(NodoN<T>* arbn)
{
		if(arbn!=NULL)
		{
			PostOrden(arbn->Obt_izq());
			PostOrden(arbn->Obt_der());
			cout << arbn->obt_elemento()<< " ";
		}
}
template <class T>
void ArbolN<T>::c_postorden(NodoN<T>* arbn, list<T> &l)
{
		if(arbn!=NULL)
		{
			c_postorden(arbn->Obt_izq(),l);
			c_postorden(arbn->Obt_der(),l);
			l.push_back(arbn->obt_elemento());
		}
}
template <class T>
list<T> ArbolN<T>::r_postorden()
{
		list<T> l;
		c_postorden(nodoRaiz,l);
		return(l);
}
template <class T>
void ArbolN<T>::PreOrden(NodoN<T>* arbn)
{
		if(arbn!=NULL)
		{
			cout << arbn->obt_elemento()<< " ";
			PreOrden(arbn->Obt_izq());
			PreOrden(arbn->Obt_der());
		}
}
template <class T>
void ArbolN<T>::c_preorden(NodoN<T>* arbn, list<T> &l)
{
		if(arbn!=NULL)
		{
			l.push_back(arbn->obt_elemento());
			c_preorden(arbn->Obt_izq(),l);
			c_preorden(arbn->Obt_der(),l);
		}
}
template <class T>
list<T> ArbolN<T>::r_preorden()
{
		list<T> l;
		c_preorden(nodoRaiz,l);
		return(l);
}
template <class T>
void ArbolN<T>::InOrden(NodoN<T>* p)
{
	NodoN<T> *aux;
	if(p!=NULL)
	{
		InOrden(p->Obt_izq());
		cout << p->obt_elemento() << " ";
	  if(p->Obt_izq()!=NULL){
		aux=p->Obt_izq()->Obt_der();
		while(aux!=NULL)
		{
		    InOrden(aux);
			aux=aux->Obt_der();
		}
	  }	
	}
}
template <class T>
void ArbolN<T>::c_inorden(NodoN<T>* p, list<T> &l)
{
	NodoN<T> *aux;
	if(p!=NULL)
	{
		c_inorden(p->Obt_izq(),l);
		l.push_back(p->obt_elemento());
	  if(p->Obt_izq()!=NULL){
		aux=p->Obt_izq()->Obt_der();
		while(aux!=NULL)
		{
		    c_inorden(aux,l);
			aux=aux->Obt_der();
		}
	  }	
	}
}
template <class T>
list<T> ArbolN<T>::r_inorden()
{
		list<T> l;
		c_inorden(nodoRaiz,l);
		return(l);
}
template <class T>
list<T> ArbolN<T>::Cargar_Niveles()
{
		NodoN<T> *p,*x;
		queue< NodoN<T>* > C;
		list<T> procesar;
		list< NodoN<T>* > h;
		
		if(nodoRaiz!=NULL)
		{
			p=nodoRaiz;
			procesar.push_back(p->obt_elemento());
			if(p->Obt_izq()!=NULL){
				x=p->Obt_izq();	
				h.push_back(x);
			}
			while(x!=NULL)
			{
			  if(x->Obt_der()!=NULL)	
				h.push_back(x->Obt_der());
			  x=x->Obt_der();
			}
			
			while(!h.empty())
			{
				C.push(h.front());
				p=h.front();
				if(p->Obt_izq()!=NULL){
					x=p->Obt_izq();	
					h.push_back(x);
				}
				while(x!=NULL)
				{
				   if(x->Obt_der()!=NULL)		
					h.push_back(x->Obt_der());
				   x=x->Obt_der();
				}
				h.pop_front();		
			}
				
			while(!C.empty())
			{	
				procesar.push_back(C.front()->obt_elemento());
				C.pop();
			}	
		}
		return(procesar);		
}
template <class T>
void ArbolN<T>::Niveles()
{
	list<T> p;
	p=Cargar_Niveles();
	 while(!p.empty())
		{
			cout << p.front() << " ";
			p.pop_front();	
		}
		cout<<endl;
}		
/*****************************/
/***Métodos de Inspección:****/
/*****************************/
template <class T>
list< ArbolN<T> > ArbolN<T>::hijos()
{
	NodoN<T> *aux;
	ArbolN<T> A;
	list< ArbolN<T> > l;

	aux=nodoRaiz->Obt_izq();
	while(aux!=NULL)
	{
		A.nodoRaiz=aux;
		l.push_back(A);
		aux=nodoRaiz->Obt_der();
	}
	return(l);
}
template <class T>
void ArbolN<T>::ObtPeso(NodoN<T> *p, int &peso)
{
		if(p!=NULL)
		{
			peso++;
			ObtPeso(p->Obt_izq(),peso);
			ObtPeso(p->Obt_der(),peso);	
		}
}
template <class T>
int ArbolN<T>::Obt_Peso()
{
	int peso=0;
	ObtPeso(nodoRaiz,peso);
	return(peso);	
}
template <class T>
void ArbolN<T>::Altura(NodoN<T> *p, int &alt)
{
	int ai=0,ad=0;
	if(p==NULL)
	{
		alt=-1;
	}else{
		if(p->Obt_izq()==NULL&&p->Obt_der()==NULL)
		{
			alt=0;	
		}else{
			Altura(p->Obt_izq(),ai);
			while(p!=NULL)
			{
				if(p->Obt_der()!=NULL)
					Altura(p->Obt_der(),ad);
				p=p->Obt_der();	
			}	
			alt=max(ai,ad)+1;
		}	
	}
}
template <class T>
int ArbolN<T>::Altura()
{
    int alt;
    NodoN<T> *p;
    p=nodoRaiz;
    if(p==NULL)
    {
	  alt=-1;
	}else{
		if(p->Obt_izq()==NULL&&p->Obt_der()==NULL)
		{
			alt=0;	
		}else{
		   Altura(p->Obt_izq(),alt);
		   alt++;
		}	
	}
	return(alt);
}
/*****************************/
/****Métodos Modificadores:***/
/*****************************/
template <class T>
void ArbolN<T>::vaciar()
{
	vaciar(nodoRaiz);
	nodoRaiz=NULL;
}
template <class T>
void ArbolN<T>::vaciar(NodoN<T> *p)
{
  if(p!=NULL){
	    vaciar(p->Obt_izq());
		vaciar(p->Obt_der());
		p=NULL;
  }	
}
template <class T>
void ArbolN<T>::insertar(ArbolN<T> &A)
{
	NodoN<T> *nuevo;
	//Caso 1 
	if(nodoRaiz->Obt_izq()==NULL)
	{
		nodoRaiz->modificarIzquierdo((copiar(A.nodoRaiz)));
	}
	else{//Caso 2
		nuevo=nodoRaiz->Obt_izq();
		while(nuevo->Obt_der()!=NULL)
		{
				nuevo=nuevo->Obt_der();
		}
		nuevo->modificarDerecho((copiar(A.nodoRaiz)));
	}
}
template<class T>
void ArbolN<T>::eliminar(int pos)
{
	NodoN<T> *aux,*aux2;
	int i;
	
	if(nodoRaiz!=NULL&&pos!=0){
		if(pos==1){
			aux=nodoRaiz->Obt_izq();
			nodoRaiz->modificarIzquierdo(aux->Obt_der());
			aux->modificarDerecho(NULL);
			vaciar(aux);
		}else{
			aux=nodoRaiz->Obt_izq();
			for(i=2;i<=pos;i++)
			{
				aux2=aux;
				aux=aux->Obt_der();	
			}
		  if(aux!=NULL){	
			aux2->modificarDerecho(aux->Obt_der());
			aux->modificarDerecho(NULL);
			vaciar(aux);
		  }else{
				cerr << "Se intento eliminar un SubArbol Inexistente" <<endl;
		  }
		}
	 }else{
		 cerr << "Se intento eliminar un SubArbol Inexistente o el Arbol esta vacio" <<endl;
	  }	
}
template<class T>
NodoN<T>* ArbolN<T>::copiar(NodoN<T> *p)
{
	if(p!=NULL)
	{
			return(new NodoN<T>(p->obt_elemento(),copiar(p->Obt_izq()),copiar(p->Obt_der())));
	}else{
			return(NULL);
	}
}
/*****************************/
/**Sobrecarga de Operadores:**/
/*****************************/
template <class T>
void ArbolN<T>::operator=(const ArbolN<T> &a)
{	
	if(this!=&a){
		nodoRaiz=this->copiar(a.nodoRaiz);
	}	
}
/*********************************/
/**Único Destructor de la Clase:**/
/*********************************/		
template <class T>
ArbolN<T>::~ArbolN()
{
	vaciar();
}
#endif
