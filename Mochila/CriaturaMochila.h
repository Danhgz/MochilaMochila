#ifndef CRIATURA_MOCHILA
#define CRIATURA_MOCHILA
#include "Criatura.h"
#include "AmbienteMochila.h"
class CriaturaMochila : public Criatura {
	friend class AmbienteMochila;
	private:
		int * piedrasEnMochila; //para hacer el vector con las piedras que tiene mochila y las que no tiene
		int tamanoMochila;
		double pesoActual;
		double *vectorPrecio;
		double *vectorPeso;
		double precioActual;

	public: 
		CriaturaMochila();
		CriaturaMochila(int,double *,double *);
		CriaturaMochila(int *, int, double *, double *);
		CriaturaMochila(const CriaturaMochila &);  
		int hayPiedra(int); //ver si una piedra esta en el vector  y recibe la posicion como param
		  // Recibe: Un puntero a una criatura para cruzarla con la actual
		  // Efectua: Retorna un vector terminado en 0 con los hijos
		Criatura ** cruzar( Criatura * ptr);
		Criatura * inverso();	  
		void mutar();
		ostream& imprimir(ostream&);
		Criatura * clonar();	 
		int operator==(Criatura *);
		void calcularPesoYPrecio();
		int getPrecio();
		int getPeso();
		int* getPiedras();
};
#endif
