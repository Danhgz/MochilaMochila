#include "AmbienteMochila.h"
#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;
AmbienteMochila::AmbienteMochila() {
	cantidadPiedras = 0;
	 pesoMochila = 0;
	 * vectorPrecio = 0;
	 *vectorPeso = 0;
	 precioTotal = 0;
	 pesoMaximo = 0;
	this->setNombre("CriaturaMochila");
	this->setCantidadCriaturas(50); // ese parametro supongo que se pone cualquier numero que uno quiera
	lector.open("AmbientePiedras.txt");
}

void AmbienteMochila::leerTxtAmbiente() {
	string piedras = "";
	string peso = "";
	string precio = "";
	int flag = 0;
	int contador = 0;
	if(lector){
		while (!lector.eof()) {
			if (flag == 0){
				//para guardar la cantidad total de piedras que hay en el ambiente
				getline(lector, piedras);
				cantidadPiedras = atoi(piedras.data());
				vectorPrecio = new double[cantidadPiedras];
				vectorPeso = new double[cantidadPiedras];
				flag = 1;
			}
			else if (flag == 1) {
				//para guardar peso de la mochila
				getline(lector,peso);
				pesoMochila = atof(peso.data());
				flag = 2;
			}
			else if (flag == 2) {
				getline(lector, piedras);
				flag = 3;
			}
			else if(flag == 3){
				//Para guardar en el vector de peso los pesos 
					getline(lector,peso, ' ');
					vectorPeso[contador] = atof(peso.data());
					getline(lector,precio);
					vectorPrecio[contador] = atof(precio.data());
					contador++;
			}
		}		 
	}
	else{
		cerr<<"No hay archivo .txt"<<endl;
	}
	lector.close();
	//Hasta aqui llega la lectura del txt

	
	for (int i = 0; i < cantidadPiedras; ++i) {
		pesoMaximo += vectorPeso[i];
		precioTotal += vectorPrecio[i];
	}
	cout << "Cantidad piedras " << cantidadPiedras << endl;
	cout << "Peso mochila " << pesoMochila << endl;
	cout << "Precio total " << precioTotal << endl;
	cout << "Peso maximo " <<  pesoMaximo<< endl;
	
	for(int i = 0; i < cantidadPiedras; ++i){
		cout << "Piedra numero: "<< (i)<< ", peso:  " << vectorPeso[i] <<" , valor: " << vectorPrecio[i]<< endl;		
	}
	// delete[] vectorPeso;
	// delete[] vectorPrecio;
}

double AmbienteMochila::evaluar(Criatura * mochila){
	CriaturaMochila * mochilaPtr = dynamic_cast<CriaturaMochila *>(mochila);
	double apto = 0;
	apto = mochilaPtr->getPrecio() / precioTotal;
	double pesoApto = 0;
	pesoApto = mochilaPtr->getPeso() / pesoMaximo;
	(pesoApto > 1)? apto -= pesoApto:0;
	(apto < 0) ? apto=0 : 0;
	return apto;
}

Poblacion * AmbienteMochila::crearPoblacionInicial(){
	int contador = 0;
	Poblacion * inicial = new Poblacion();
	Poblacion::Iterador iter =inicial->begin();
	while (contador++ < cantidadCriaturas)
	{
		CriaturaMochila * criatura = new CriaturaMochila(cantidadPiedras, vectorPrecio, vectorPeso);
		inicial->insertar(iter, criatura);
		++iter;
	}
	return inicial;
}
AmbienteMochila::~AmbienteMochila() {
	vectorPeso ? delete[]vectorPeso;
	vectorPrecio ? delete[]vectorPrecio;
}