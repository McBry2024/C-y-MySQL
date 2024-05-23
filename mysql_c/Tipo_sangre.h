#pragma once
#include <iostream>
using namespace std;
class Tipo_sangre
{
	// atributos
protected:
	string tipos_sangre;

	//constructor
protected:
	Tipo_sangre() {
	}

	Tipo_sangre(string tsa) {
		tipos_sangre = tsa;
	}
};

