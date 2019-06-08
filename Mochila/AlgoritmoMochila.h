#ifndef ALGORITMO_MOCHILA
#define ALGORITMO_MOCHILA
#include "Poblacion.h"
#include "Algoritmo.h"
#include<ctime>
#define PROBABILIDAD_MUTUACION 15
class AlgoritmoMochila : public Algoritmo {

public:
	AlgoritmoMochila();
	Poblacion * evolucionar(Poblacion *);
};

#endif
