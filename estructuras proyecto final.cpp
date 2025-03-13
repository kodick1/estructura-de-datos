#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
struct nodo {
	int dato;
	nodo* siguiente;
	nodo *anterior ;
	nodo *izq;
	nodo *der;
	nodo *padre;
} *primero, *ultimo,*aux;

void menu();
nodo *crearNodo(int,nodo*);
void insertarNodo(nodo *&,int,nodo*);
void mostrarlista ();
void mostrarlistaarboles();
void inOrden(nodo*);
void preOrden(nodo*);
void posOrden(nodo*);


void unsolohijo(nodo*,nodo*);

void mostrardato(nodo*);
nodo* minimoizq(nodo*);
nodo *lista=NULL;
nodo*arbol=NULL;


int main()
{
menu ();
getch();	
return 0;		
}

void menu()
{
int opc,dato;
do{
	
	cout<<"Daniel Armero 20161578352"<<endl<<"\t .MENU \n" << "INGRESE QUE OPCION DESEA " <<endl;
	cout<<"1 . Cargar lista hasta que el usuario ya no quiera agregar mas datos = " << endl;
	cout<<"2 . Mostrar los 3 tipos de arboles = "<<endl;
	cout<<"3 . Salir = "<< endl ;
    cin>>opc;
	 
	 
	 switch(opc)
	 {
	 	case 1: 
	 do{
	 		
        cout<<"digite un numero :"<<endl;
        cout<<"para dejar de ingresar datos ingresar 0"<<endl;
        cin>>dato;
        insertarNodo(arbol,dato,NULL);
	 	}while(dato!=0);
	    break;
	 	
	 	
	 	case 2:
	 		
	 	cout<<"mostrar los 3 tipos de arboles : "<<endl;
	    mostrarlistaarboles();
	 	system("pause");
	 	break;
	
	 		
	 	system("pause");
	 	break;
	 		
	 	case 3:
	 	cout<<" salir ";
	 
	 	system("pause");
	 	break;
	 		
	 	
 getch();
 break ;
 
	 		 system("pause");
	 		 break ;
	 }	
	 system("cls");
}	while(opc !=5);		

}

nodo*crearNodo(int n,nodo*padre){
	
	nodo*nuevo=new nodo();
	nuevo->dato=n;
	nuevo->der=NULL;
	nuevo->izq=NULL;
	nuevo->padre=padre;
	 if(primero==NULL){
	      primero = nuevo ;
	      primero->siguiente = NULL;
	      primero->anterior=NULL;
	      ultimo=primero;
	      }else{
	      ultimo->siguiente=nuevo;
	      nuevo->siguiente=NULL;
	      nuevo->anterior=ultimo;
	      ultimo=nuevo;
	      }
	return nuevo ;
}

void insertarNodo(nodo*&arbol,int n,nodo*padre )
{
     
    if(arbol==NULL){
    cout<< "ingrese el dato : " ;	
    nodo*nuevo = crearNodo(n,padre);
    arbol=nuevo;
	}else{
		
		int valorRaiz = arbol->dato;
		if(n<valorRaiz){
			insertarNodo(arbol->izq,n,arbol);
		}
		else{
			insertarNodo(arbol->der,n,arbol);
		}
	
	}


	}



void mostrarlistaarboles()
{
	int opc ;
	do{
		cout<<"quie tipo de arbol quiere ver  ?"<<endl;
		cout<<"1. IN-ORDEN : "<<endl;
		cout<<"2. PRE-ORDEN : " <<endl;
		cout<<"3. POS-ORDEN : "<<endl;
		cout<<"4. salir: "<<endl; 
		cin >>opc;
		switch(opc)
	    {
	    	
	 	case 1: 
        cout<<"IN-ORDEN :"<<endl;
        inOrden(arbol) ;
	 	system("pause");
	 	break;
	 	
	 	
	 	case 2 :
	 	cout<< " PRE-ORDEN  : "<<endl;
	 	preOrden(arbol);
	 	system("pause")	;
	 	break ;
	 	
	 	
	 	case 3 :
	 	cout<< " POS-ORDEN  : "<<endl;
	 	posOrden(arbol);
	 	system("pause")	;
	 	break ;
	 	
	 	
	 	case 4:
	 	cout<<" SALIR ";
	 
	 	system("pause");
        getch();
        break ;
 
	 		 system("pause");
	 		 break ;
	 }	
	 system("cls");
}	while(opc !=4);		
	 	
	
}



void inOrden(nodo *arbol)
     {
     if(arbol==NULL){ 
     return;   
     }else{
    inOrden(arbol->izq);
     cout<<"->"<<arbol->dato<<endl;
    inOrden(arbol->der);
 }
 }
void preOrden(nodo*arbol)
{
	if(arbol==NULL){
	return;
	}else{
		cout<<"->"<<arbol->dato<<endl;
		preOrden(arbol->izq);
		preOrden(arbol->der);
	}
}
void posOrden(nodo*arbol)
{
	if(arbol==NULL){
	return;
    }else{
    posOrden(arbol->izq);
    posOrden(arbol->der);
    cout<<"->"<<arbol->dato<<endl;
}	
}
void mostrardato(nodo*arbol )
{
	int buscar=0;
	bool encontrado=false;
	cout <<"ingrese dato a buscar ";
	cin>>buscar;
	while(arbol!=NULL){
		if (arbol->dato=buscar){
			cout<<"se encontro el dato ->"<<buscar<<endl;
			encontrado=true;
			break;
		}
	
	}if(!encontrado){
		cout<<"nodo no encontrado";
	}
	
		
}



	
