#ifndef _AMBIENTE_MOCHILA
#define _AMBIENTE_MOCHILA
#include "Ambiente.h"
#include "Poblacion.h"
#include "CriaturaMochila.h"
#include <fstream>
class AmbienteMochila: public Ambiente {
	friend class CriaturaMochila;
	private:
		ifstream lector;
		int cantidadPiedras;
		double pesoMochila;
		double *vectorPrecio;
		double *vectorPeso;
		double precioTotal;
		double pesoMaximo;
	public:
		void leerTxtAmbiente();
		AmbienteMochila();
		~AmbienteMochila();
		double evaluar(Criatura *);
		Poblacion * crearPoblacionInicial();
};

#endif
