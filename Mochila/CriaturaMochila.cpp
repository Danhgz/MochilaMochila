#include "CriaturaMochila.h"
#include <iostream>
#include <ctime>
using namespace std;

CriaturaMochila::CriaturaMochila(){
	piedrasEnMochila = 0;
	pesoActual = 0;
	vectorPrecio = 0;
	vectorPeso = 0;
	precioActual = 0;
	
}

CriaturaMochila::CriaturaMochila(int cantPiedras,double *vectorPrecio,double *vectorPeso){
	srand(time(0)); // no se si sirve bien 
	tamanoMochila = cantPiedras;
	vectorPeso = new double[tamanoMochila];
	vectorPrecio = new double[tamanoMochila];
	for (int i = 0; i < tamanoMochila; i++)
	{
		this->vectorPeso[i] = vectorPeso[i];
		this->vectorPrecio[i] = vectorPeso[i];
	}
	piedrasEnMochila = new int[tamanoMochila];
	for(int i = 0; i < tamanoMochila; ++i ){
		piedrasEnMochila[i] = rand()%2; 
	}
}

CriaturaMochila::CriaturaMochila(int * piedra, int tamano, double *vectorPrecio, double *vectorPeso) {
	tamanoMochila = tamano;
	vectorPeso = new double[tamanoMochila];
	vectorPrecio = new double[tamanoMochila];
	for (int i = 0; i < tamanoMochila; i++)
	{
		this->vectorPeso[i] = vectorPeso[i];
		this->vectorPrecio[i] = vectorPeso[i];
	}
	piedrasEnMochila = new int[tamanoMochila];
	for (int i = 0; i < tamanoMochila; ++i) {
		piedrasEnMochila[i] = piedra[i];
	}
	calcularPesoYPrecio();

}

CriaturaMochila::CriaturaMochila(const CriaturaMochila & otra) {
	this->tamanoMochila = otra.tamanoMochila;
	for (int i = 0; i < tamanoMochila; i++)
	{
		this->vectorPeso[i] = otra.vectorPeso[i];
		this->vectorPrecio[i] = otra.vectorPeso[i];
	}
	this->piedrasEnMochila = new int[this->tamanoMochila];
	for (int i = 0; i < this->tamanoMochila; ++i) {
		this->piedrasEnMochila[i] = otra.piedrasEnMochila[i];
	}
}
	
int CriaturaMochila::hayPiedra(int pos){
	return piedrasEnMochila[pos] == 1;
} //ver si una piedra esta en el vector  y recibe la posicion como param
	
	
// Recibe: Un puntero a una criatura para cruzarla con la actual
// Efectua: Retorna un vector terminado en 0 con los hijos
Criatura ** CriaturaMochila::cruzar( Criatura * ptr){
	Criatura * * hijo = 0;

	if (ptr) {
		CriaturaMochila * mochilaPtr = dynamic_cast<CriaturaMochila *>(ptr);
		hijo = new Criatura *[3]; 
		int **vistima = new int*[2]; 
		for (int i = 0; i < 2; i++)
			vistima[i] = new int[tamanoMochila];

		for (int i = 0; i < tamanoMochila; ++i){
			vistima[i%2][i] = this->piedrasEnMochila[i];
			vistima[(i+1)%2][i] = mochilaPtr->piedrasEnMochila[i];
		}
		hijo[0] = new CriaturaMochila(vistima[0],tamanoMochila,vectorPrecio,vectorPeso);
		hijo[1] = new CriaturaMochila(vistima[1], tamanoMochila, vectorPrecio, vectorPeso);
		hijo[2] = 0; // El ultimo puntero es nulo
	}
	return hijo;
}
	  
Criatura * CriaturaMochila::inverso(){
	CriaturaMochila * mochilaInversa = new CriaturaMochila();
	for(int i = 0; i < tamanoMochila; ++i){
		mochilaInversa->piedrasEnMochila[i] = !piedrasEnMochila[i];
	}
	return mochilaInversa; 
}	  
	  
void CriaturaMochila::mutar(){
	srand(time(0));
	int muta;
	for(int i = 0; i < tamanoMochila; ++i){
		muta = rand() % 10;
		piedrasEnMochila[i] = (muta == 0)? !piedrasEnMochila[i] : piedrasEnMochila[i];
	}
}
	  
ostream& CriaturaMochila::imprimir(ostream& salida){
	salida << "Piedras en la mochila: "<<endl;
	for (int i = 0; i < tamanoMochila; i++) {
		if (piedrasEnMochila[i] == 1) {
			salida << "Piedra numero: " << i << ", peso:  " << vectorPeso[i] << " , valor: " << vectorPrecio[i] << endl;
		}
	}
	salida << "Peso Total: " << pesoActual << endl;
	salida << "Precio Total: " << precioActual << endl;

	return salida;
}
	  
Criatura * CriaturaMochila::clonar(){
	Criatura  * clonMochila = new CriaturaMochila(*this);
	return clonMochila;
}
	 
int CriaturaMochila::operator==(Criatura * otro){
	int igual = 1;
	CriaturaMochila * mochilaPtr = dynamic_cast<CriaturaMochila *>(otro);
	for (int i = 0; i < tamanoMochila && igual==1; i++) {
		if (piedrasEnMochila[i] != mochilaPtr->piedrasEnMochila[i]) {
			igual = 0;
		}
	}
	return igual;
}

void	CriaturaMochila::calcularPesoYPrecio() {
	pesoActual = 0;
	precioActual = 0;
	for (int i = 0; i < tamanoMochila; i++) {
		pesoActual += piedrasEnMochila[i] * vectorPeso[i];
		precioActual += piedrasEnMochila[i] * vectorPrecio[i];
	}
}

int CriaturaMochila::getPrecio() {
	return precioActual;
}

int CriaturaMochila::getPeso() {
	return pesoActual;
}

int* CriaturaMochila::getPiedras() {
	return piedrasEnMochila;
}
