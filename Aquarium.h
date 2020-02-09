#pragma once

#define DEF_AQUARIUM

using namespace std;

#include <string>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include "Etrevivant.h"
#include "Poisson.h"
#include "Algue.h"

#ifndef _AQUARIUM_HPP
#define _AQUARIUM_HPP

class Aquarium
{
private:
	vector<Poisson> m_poissons;
	vector<Algue> m_algues;
	int m_nbtour;
	int r;

public:
	Aquarium();
	~Aquarium();
	void setnbTour(int n);
	void addPoisson(Poisson p);
	void addAlgues(Algue a);
	vector<Poisson>getPoisson();
	vector<Algue>getAlgues();
	void erasePoisson(Poisson p, int i);
	void eraseAlgue(Algue a, int i);
	Poisson& getPoissonElt(int p);
	Algue& getAlgueElt(int a);
	void displayContent();
	void computerTour();

	template<typename T> void add(T t, std::vector<T>& v);
	void traitementAlgue(int a);
	void traitementPoisson(int p);

};




#endif