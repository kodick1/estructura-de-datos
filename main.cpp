#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <string.h>

using namespace std;
//////Clase de producto////////////////////////////////////////////////////////////////////////////////
class Producto{
	private:
		int id;
		char nombreP[30];
		int valor,valor1,valor2;
	
	public:
		Producto *sig;
		Producto();
		void crearProducto( int id, char* nombre, int valor,int valor1, int valor2);
		void mostarProducto();
		int getValor();
		int getValor1();
		int getValor2();
		int getId();
		char* getNombre();
};

Producto::Producto()
{
	this->id=0;
	this->valor=0;
    this->valor1=0;
	this->valor2=0;  
 	this->sig=NULL;
}

char* Producto::getNombre()
{
	return this->nombreP;
}

int Producto::getValor()
{
	return valor;
}
int Producto::getValor1()
{
	return valor1;
}
int Producto::getValor2()
{
	return valor2;
}

int Producto::getId()
{
	return id;
}

void Producto::crearProducto( int id, char* nombre, int valor, int valor1, int valor2 ){
	this->id = id;
	this->valor= valor;
	this->valor1= valor1;
	this->valor2= valor2;
	strcpy(this->nombreP,nombre);
}

void Producto::mostarProducto(){
	cout<<endl<<this->id<<". "<<this->nombreP<<", $"<<this->valor<<this->valor1<<this->valor2<<endl;
}
///// Fin clase producto//////////////////////////////////////////////////////////////////////////



///////inicio clase lista simple////////////////////////////////////////////////////////////////////
class ListaSimple{
	public:
		Producto *lista;
		ListaSimple();
		void insertarNodo( Producto *&nuevo );
		void mostrarLista();
		
		void buscarNodo( int id );
		void mostrarValorLista();
		void buscarNombre( char* );
		
};

ListaSimple::ListaSimple(){
	this->lista = NULL;
}

void ListaSimple::buscarNombre( char *nombre )
{
	
	nombre = strupr(nombre);
	
	Producto *aux1 = lista;
	bool bandera =false;
	if( lista == NULL )
    {
		cout<<"\n Lista vacia "<<endl;
    }else{
	
	  while( aux1 != NULL )
	  {
		 if( strcoll(strupr(aux1->getNombre()), nombre) == 0 )
		 {
			 aux1->mostarProducto();
			 bandera = true;
			 break;
		 }
		 aux1= aux1->sig;
	  }
	  if( bandera == false )
	  {
		cout<<"\nEl producto no fue encontrado "<<endl;
	  }
   }
}

void ListaSimple::insertarNodo( Producto*& nuevo){
	if( lista==NULL ){
		this->lista = nuevo; 
		cout<<"se creo cabeza de lista"<<endl;
	}else{
		Producto* aux1= this->lista;
		
		while(aux1->sig != NULL ){
			aux1=aux1->sig;
		}
		aux1->sig = nuevo;
	}
	
}

void ListaSimple::mostrarLista(){
	Producto *aux1 = this->lista;//cpy cabeza de lisata
	
	if( this->lista !=NULL ){
		lista->mostarProducto();
		while( aux1->sig != NULL ){
			aux1 = aux1->sig;
			
			aux1->mostarProducto();
		} 
	}else{
		cout<<"la lista no existe"<<endl;
	}
	
}

void ListaSimple::mostrarValorLista()
{
	Producto *aux1 = lista;
	int suma=0, prom=0;
	
	if( lista == NULL )
	{
		cout<<"\n Lista vacia "<<endl;
	}else{
	   
	   while( aux1 != NULL )
	   {
	      suma = suma + aux1->getValor();
	      suma= suma + aux1->getValor1();
		  suma= suma + aux1->getValor2();
		  aux1 = aux1->sig;
	   }
	   prom=suma/3;
	   cout<<"\n\n"<<prom<<endl;
    }
}

void ListaSimple::buscarNodo( int id )
{
	Producto *aux1 = lista;
	bool bandera =false;
	
	if( lista == NULL )
	{
		cout<<"\n Lista vacia "<<endl;
	}else{
	   while( aux1 != NULL )
	   {
	      if( aux1->getId() == id )
		  {
			 aux1->mostarProducto();
			 bandera = true;
			 break;
		  }
		aux1= aux1->sig;
	   }
	
	   if( bandera == false )
	   {
		cout<<"\nEl producto no fue encontrado "<<endl;
	   }
   }
	
}
////////fin de clase lista simple///////////////////////////////////////////////////////////////////

int main(){
	int id=0, opc=0, valor,valor1,valor2; 
	char nombre[30];
	ListaSimple *obj_listSimple = new ListaSimple();
	
	do{
		system("cls");
		cout<<"HOLA MUNDO LISTA SIMPLE POO"<<endl<<endl;
		cout<<"(1).Ingresar la materia\n(2). Mostar materias de la lista"
		     "\n(3).buscar materia en la lista\n(5).calcular"
		     " el promedio de la materia\n(6).buscar un nombre lista\n(9).salir"<<endl;
		cout<<"digite la opcion deseada: ";
		cin>>opc;
		system("cls");     
		system("pause");
		
		switch(opc){
			case 1:{
				cout<<"Ingrese su materia"<<endl;
				id+=1;
				char nombre[30];
				int valor,valor1,valor2;
				cout<<"digite el nombre de la materia"<<endl;
				cin>>nombre;
				cout<<endl<<"digite la 1 notas de la materia: ";
				cin>>valor;
				cout<<endl<<"digite la 2 notas de la materia: ";
				cin>>valor1;
				cout<<endl<<"digite la 3 notas de la materia: ";
				cin>>valor2;
				Producto *nuevo = new Producto();
				nuevo->crearProducto(id,nombre,valor,valor1,valor2);
				obj_listSimple->insertarNodo(nuevo);
				cout<<endl;
				break;
		    }
			case 2:{
			
				cout<<"Mostar lista: "<<endl;
			    obj_listSimple->mostrarLista();
			    cout<<endl;
				break;
			}
			case 3:{
				int opcP;
				cout<<"buscar producto: "<<endl;
				cout<<" ingrese id: ";
				cin>>opcP;
				obj_listSimple->buscarNodo(opcP);
				break;
			}
		
			case 5:{
				cout<<"promedio total de notas"<<endl;
				obj_listSimple->mostrarValorLista();
				break;
			}
			case 6:{
				char nombre[30];
				cout<<"buscar nombre: "<<endl;
				cout<<" ingrese nombre: ";
				cin>>nombre;
				obj_listSimple->buscarNombre(nombre);
				break;
			}
		
					
		}
		system("pause");
		
	}while( opc!=9);
	
	return 0;
}

// clase curso (provadas= id.c, nombre.c, nota) funciones get y set. construxtor. public curso *sig curso *atras.
//Clase list2Enlace public curso *lista_d insertar nodo(curso *&nuevo) y mmostrar lista(); int promedioCursos()      int nota alta(); int nota baja();  0>=nota<=10;  
