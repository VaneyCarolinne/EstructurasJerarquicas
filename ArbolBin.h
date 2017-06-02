#ifndef ArbolB_h
#define ArbolB_h
#include "NodoB.h"
#include <list>
#include <queue>
using std::list;
using std::queue;
/********************************************************/
/*******************************************************/
/***********Definición de la Clase Árbol Binario*******/
/*************Autora: Vanessa Cruz********************/
/****************************************************/
/***************************************************/
template<class T>
class ArbolB
{
		//atributos:
		protected:
			NodoB<T>* nodoRaiz;
		//metodos:
		private:
			//Recorridos:
			void PostOrden(NodoB<T>* arbn);
			void PreOrden(NodoB<T>* arbn);
			void Cargar_Postorden(NodoB<T> *p,list<T> &procesar);
			void Cargar_Inorden(NodoB<T> *p,list<T> &procesar);
			void Cargar_Preorden(NodoB<T> *p,list<T> &procesar);
			//Metodos de Modificacion:
			void vaciar(NodoB<T> *p);
			NodoB<T>* copiar(NodoB<T> *p);
			NodoB<T>* CrearPre(list<T> &Pre, list<T> &In);
			void Invertir(NodoB<T>* p);
			void Altura(NodoB<T> *p, int &alt);	
			void Obt_anchura(int &niv,int i,queue<NodoB<T>* > c);
			int Diametro(NodoB<T> *p, int &maxa);
			void Movil(NodoB<T> *p, bool &band);
			void Completo(NodoB<T> *p, bool &band);
			bool Son_Iguales(NodoB<T> *x, NodoB<T> *y);
			void es_menor(NodoB<T> *p, NodoB<T> *x, bool &band);
		public:
			//Constructores:
			ArbolB<T>():nodoRaiz(NULL){}
			ArbolB(const ArbolB<T> &a);
			ArbolB(T e, ArbolB<T> &A1, ArbolB<T> &A2);
			void ConstruirPre(list<T> &Pre, list<T> &In){nodoRaiz=CrearPre(Pre,In);}
			void ConstruirPost(list<T> &Post, list<T> &In);	
			//Metodos de Inspección:
			bool esNulo(){return(nodoRaiz==NULL);}
			T raiz(){return(nodoRaiz->obt_elemento());}
			ArbolB<T> hijoIzq();
			ArbolB<T> hijoDer();
			int Altura();
			bool esHoja(){return(nodoRaiz->Obt_izq()==NULL&&nodoRaiz->Obt_der()==NULL);}
			int anchura(int i);
			int gordura();
			int Diametro();
			bool Es_movil();
			bool Es_Completo();
			bool Es_lleno();
			bool es_menor(ArbolB<T> &b2);
			//Metodos de Modificacion:
			void copiar(ArbolB<T> &A){nodoRaiz=copiar(A.nodoRaiz);}	
			void vaciar();
			void Invertir(){Invertir(nodoRaiz);}
			//Recorridos:
			void PostOrden(){PostOrden(nodoRaiz);}
			void PreOrden(){PreOrden(nodoRaiz);}
			void InOrden();
			void Niveles();
			list<T> Cargar_inorden();
			list<T> Cargar_preorden();
			list<T> Cargar_postorden();
			list<T> Cargar_Niveles();
			//Sobrecarga de operadores:
			void operator=(ArbolB<T> &a);
			bool operator==(const ArbolB<T> &a);
			//Destructor: 
			~ArbolB();
};
/******************************************/
/********Constructores de la Clase:*******/
/*****************************************/
template <class T>
ArbolB<T>::ArbolB(const ArbolB<T> &a)
{		
	*this=a;
}
template <class T>
ArbolB<T>::ArbolB(T e, ArbolB<T> &A1, ArbolB<T> &A2){
	nodoRaiz=new NodoB<T>(e,copiar(A1.nodoRaiz),copiar(A2.nodoRaiz));	
}
/*****************************/
/**********Recorridos:********/
/*****************************/
template <class T>
void ArbolB<T>::PostOrden(NodoB<T>* arbn)
{
		list<T> h;
		h=Cargar_postorden();
		while(!h.empty())
		{
			cout << h.front() << " ";
			h.pop_front();	
		}
		cout << endl;
}
template <class T>
void ArbolB<T>::PreOrden(NodoB<T>* arbn)
{
		list<T> h;
		h=Cargar_preorden();
		while(!h.empty())
		{
			cout << h.front() << " ";
			h.pop_front();	
		}
		cout << endl;
}
template <class T>
void ArbolB<T>::InOrden()
{
	list<T> h;
		h=Cargar_inorden();
		while(!h.empty())
		{
			cout << h.front() << " ";
			h.pop_front();	
		}
		cout << endl;
}
template <class T>
list<T> ArbolB<T>::Cargar_preorden(){
	list<T> nuevo;
	Cargar_Preorden(nodoRaiz,nuevo);
	return nuevo;
}

template <class T>
void ArbolB<T>::Cargar_Postorden(NodoB<T> *p,list<T> &procesar){
	if(p!=NULL){
		Cargar_Postorden(p->Obt_izq(),procesar);
		Cargar_Postorden(p->Obt_der(),procesar);
		procesar.push_back(p->obt_elemento());
	}
}

template <class T>
list<T> ArbolB<T>::Cargar_inorden(){
	list<T> nuevo;
	Cargar_Inorden(nodoRaiz,nuevo);
	return nuevo;
}

template <class T>
void ArbolB<T>::Cargar_Inorden(NodoB<T> *p,list<T> &procesar){
	
	if(p!=NULL){
		Cargar_Inorden(p->Obt_izq(),procesar);
		procesar.push_back(p->obt_elemento());
		Cargar_Inorden(p->Obt_der(),procesar);
	}
}

template <class T>
list<T> ArbolB<T>::Cargar_postorden(){
	list<T> nuevo;
	Cargar_Postorden(nodoRaiz,nuevo);
	return nuevo;
}

template <class T>
void ArbolB<T>::Cargar_Preorden(NodoB<T> *p,list<T> &procesar){
	
	if(p!=NULL){
		procesar.push_back(p->obt_elemento());
		Cargar_Preorden(p->Obt_izq(),procesar);
		Cargar_Preorden(p->Obt_der(),procesar);
	}
}
template <class T>
list<T> ArbolB<T>::Cargar_Niveles()
{
		NodoB<T> *p;
		queue< NodoB<T>* > C;
		list<T> procesar;
		
		if(nodoRaiz!=NULL)
		{
			p=nodoRaiz;
			procesar.push_back(p->obt_elemento());
			if(p->Obt_izq()!=NULL)
				C.push(p->Obt_izq());
			if(p->Obt_der()!=NULL)
				C.push(p->Obt_der());
			while(!C.empty())
			{
				procesar.push_back(C.front()->obt_elemento());
				p=C.front();
				C.pop();
				if(p->Obt_izq()!=NULL)
					C.push(p->Obt_izq());
				if(p->Obt_der()!=NULL)
					C.push(p->Obt_der());	
			}		
		}
		return(procesar);		
}
template <class T>
void ArbolB<T>::Niveles()
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
template <class T>
int ArbolB<T>::gordura()
{
		int max=-1;
		int i;
		
		for(i=0;i<=Altura();i++)
		{
			if(max<anchura(i))
			{
				max=anchura(i);	
			}	
		}
		return(max);
}
template <class T>
void ArbolB<T>::Obt_anchura(int &niv,int i,queue<NodoB<T>* > c){
	queue<NodoB<T> *> aux;
	int cont=0;
	
	while(!c.empty()){
		if(c.front()->Obt_izq()!=NULL){
			aux.push(c.front()->Obt_izq());
		}
		if(c.front()->Obt_der()!=NULL){
			aux.push(c.front()->Obt_der());
		}
		c.pop();
		cont++;
	}
	
	if(niv==i){
		if(cont!=0){
			niv=cont;
		}
		else{
			niv=0;
		}
	}
	else{
		Obt_anchura(niv,i+1,aux);
	}
}
template <class T>
int ArbolB<T>::anchura(int i){
	queue<NodoB<T> *> c;
	
	if(nodoRaiz!=NULL){
		c.push(nodoRaiz);
		Obt_anchura(i,0,c);
	}
	else{
		i=-1;
	}
	
	return i;
}
/*****************************/
/***Métodos de Inspección:****/
/*****************************/
template <class T>
int ArbolB<T>::Diametro(NodoB<T> *p, int &maximo)
{
	int maxd=0,maxi=0,submaxi, submaxd,subDiametro,maxDiametro;
	if(p==NULL)
	{
		maximo=0;
		return maximo;	
	}else{
		submaxi=Diametro(p->Obt_izq(),maxi);
		submaxd=Diametro(p->Obt_der(),maxd);
		subDiametro=maxi+maxd+1;
		maximo=max(maxi,maxd)+1;
		maxDiametro=max(submaxd,submaxi);
		return(max(subDiametro,maxDiametro)-1);
	}
}
template <class T>
int ArbolB<T>::Diametro()
{
	int maxa=0,d;
	d=Diametro(nodoRaiz,maxa);
	return(d);	
}
template <class T>
ArbolB<T> ArbolB<T>::hijoIzq()
{
	ArbolB<T> hijo;
	
	if(nodoRaiz!=NULL)
	{
			hijo.nodoRaiz=copiar(nodoRaiz->Obt_izq());
	}else
	{
			hijo.nodoRaiz=NULL;
	}
	return(hijo);
	
}
template <class T>
ArbolB<T> ArbolB<T>::hijoDer()
{
	ArbolB<T> hijo;
	
	if(nodoRaiz!=NULL)
	{
			hijo.nodoRaiz=copiar(nodoRaiz->Obt_der());
	}else
	{
			hijo.nodoRaiz=NULL;
	}
	return(hijo);
	
}
template <class T>
void ArbolB<T>::Altura(NodoB<T> *p, int &alt)
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
			Altura(p->Obt_der(),ad);
			alt=max(ai,ad)+1;
		}	
	}
}
template <class T>
bool ArbolB<T>::Son_Iguales(NodoB<T> *x, NodoB<T> *y)
{
	if(x!=NULL&&y!=NULL)
	{
		return((x->obt_elemento()==y->obt_elemento())&&Son_Iguales(x->Obt_izq(),y->Obt_izq())&&Son_Iguales(x->Obt_der(),y->Obt_der()));	
	}else{
		if(x==NULL&&y==NULL)
		{
			return(true);	
		}else{
			return(false);	
		}	
	}	
}
template <class T>
int ArbolB<T>::Altura()
{
    int alt=0;
   	Altura(nodoRaiz,alt);
	return(alt);
}
template<class T>
void ArbolB<T>::Movil(NodoB<T> *p, bool &band)
{
	if(p!=NULL)
	{
		Movil(p->Obt_izq(),band);
		Movil(p->Obt_der(),band);
		if((p->Obt_izq()!=NULL&&p->Obt_der()!=NULL&&p->Obt_izq()->obt_elemento()+p->Obt_der()->obt_elemento()!=p->obt_elemento())||(p->Obt_izq()==NULL&&p->Obt_der()!=NULL&&p->Obt_der()->obt_elemento()!=p->obt_elemento())||(p->Obt_der()==NULL&&p->Obt_izq()!=NULL&&p->Obt_izq()->obt_elemento()!=p->obt_elemento()))
			band=false;		
	}	
}
template <class T>
void ArbolB<T>::Completo(NodoB<T> *p, bool &band)
{
	if(p->Obt_izq()!=NULL&&p->Obt_der()!=NULL)//SI no es hoja
	{
		Completo(p->Obt_izq(),band);
		Completo(p->Obt_der(),band);		
	}else{
	  if((p->Obt_izq()!=NULL&&p->Obt_der()==NULL)||(p->Obt_der()!=NULL&&p->Obt_izq()==NULL))
	  {
		   band=false;
	  }
	}		
}
template <class T>
bool ArbolB<T>::Es_Completo()
{
	bool band=true;
	
	Completo(nodoRaiz,band);
	return(band);	
}
template <class T>
bool ArbolB<T>::Es_movil()
{
	bool band=true;
	Movil(nodoRaiz,band);
	return(band);	
}
template <class T>
bool ArbolB<T>::Es_lleno()
{
	if(Es_Completo()&&(2*anchura(Altura()-1))==(anchura(Altura())))
	{
		return(true);	
	}else{
		return(false);	
	}	
}
template<class T>
bool ArbolB<T>::es_menor(ArbolB<T> &b2)
{
	NodoB<T> *p,*x;
	bool band=true;
	p=nodoRaiz;
	x=b2.nodoRaiz;
	es_menor(p,x,band);
	return(band);
}
template <class T>
void ArbolB<T>::es_menor(NodoB<T> *p, NodoB<T> *x, bool &band)
{
	if(band)
	{
		if(p!=NULL&&x!=NULL){
			if(p->obt_elemento()<x->obt_elemento())
			{
				es_menor(p->Obt_izq(),x->Obt_izq(),band);
				es_menor(p->Obt_der(),x->Obt_der(),band);	
			}else{
				band=false;	
			}
		}else{
				if(p!=NULL&&x==NULL)
					band=false;
		}		
	}	
}
/*****************************/
/****Métodos Modificadores:***/
/*****************************/
template <class T>
NodoB<T>* ArbolB<T>::CrearPre(list<T> &Pre, list<T> &In)
{
		list<T> sub;
		T elem;
		if(!In.empty())
		{
				while(Pre.front()!=In.front())
				{
					sub.push_back(In.front());	
					In.pop_front();
				}
				In.pop_front();
				elem=Pre.front();
				Pre.pop_front();
				return(new NodoB<T>(elem,CrearPre(Pre,sub),CrearPre(Pre,In)));
		}else
		{
				return(NULL);
		}
}
template <class T>
void ArbolB<T>::ConstruirPost(list<T> &Post, list<T> &In)	
{
		Post.reverse();
		In.reverse();
		ConstruirPre(Post,In);
		Invertir(nodoRaiz);
}
template <class T>
void ArbolB<T>::Invertir(NodoB<T>* p)
{
		NodoB<T> *izq,*der,*nuevo;
		
	if(p!=NULL){	
		nuevo=p;
		der=p->Obt_izq();
		izq=p->Obt_der();
		nuevo->modificarIzquierdo(izq);
		nuevo->modificarDerecho(der);
		Invertir(nuevo->Obt_izq());
		Invertir(nuevo->Obt_der());
	}	
}
template <class T>
void ArbolB<T>::vaciar()
{
	vaciar(nodoRaiz);
}
template <class T>
void ArbolB<T>::vaciar(NodoB<T> *p)
{
  if(p!=NULL){
		vaciar(p->Obt_izq());
		vaciar(p->Obt_der());
		delete(p);
		p=NULL;
  }	
}
template<class T>
NodoB<T>* ArbolB<T>::copiar(NodoB<T> *p)
{
	if(p!=NULL)
	{
			return(new NodoB<T>(p->obt_elemento(),copiar(p->Obt_izq()),copiar(p->Obt_der())));
	}else{
			return(NULL);
	}
}
/*****************************/
/**Sobrecarga de Operadores:**/
/*****************************/
template <class T>
void ArbolB<T>::operator=(ArbolB<T> &a)
{	
	if(this!=&a){
		this->copiar(a);
	}	
}
template <class T>
bool ArbolB<T>:: operator==(const ArbolB<T> &a)
{
	NodoB<T> *aux1=nodoRaiz,*aux2=a.nodoRaiz;
	return(Son_Iguales(aux1,aux2));
}
/*********************************/
/**Único Destructor de la Clase:**/
/*********************************/		
template <class T>
ArbolB<T>::~ArbolB()
{
	vaciar();
}

#endif
