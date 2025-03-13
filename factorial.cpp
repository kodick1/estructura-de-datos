#include <iostream>
using namespace std;
//se usa la libreria para imprimir y escanear

int fxFactorial(int);//creamos la función retornando un valor entero

int main() {	//hacemos la función principal
int num,factorial;
cout<<"ingresa un numero para calcular su Factorial : ";
cin>>num;
//factorial=fxFactorial(num);
cout<<"el factorial de  "<<num<<"  es ;  "<<fxFactorial(num);//se imprime el numero factorial llamando 
//la función que retorna un valor
system("pause");
	return 0;
}
//proceso de la función 
int fxFactorial(int num){
if(num<0)//se compara que el numero no sea menor a 0
return 0;
if(num>1)//se valida que el numero sea mayor que 0
return num*fxFactorial(num-1)//se toma el numero 
; 
}
