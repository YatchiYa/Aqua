#pragma once
//#ifndef DEF_POISSON
#define DEF_POISSON

#include <string>
#include <iostream>
#include <stdlib.h>
#include "Etrevivant.h"
using namespace std;

#ifndef _POISSON_HPP
#define _POISSON_HPP

class Poisson :
	public Etrevivant
{

private:
	string m_name;
	string m_sex;
	string m_race;
	string m_type;
	int r;

public:
	Poisson(string name, string sexe, string race) :Etrevivant()
	{
		this->m_name = name;
		this->m_sex = sexe;
		this->m_race = race;
		if (race == "Merou" || race == "Thon" || race == "PoissonClown") {
			this->m_type = "Carnivore";
		}
		if (race == "Bar" || race == "Sole" || race == "Carpe") {
			this->m_type = "Herbivore";
		}
	};
	Poisson(string name, string sexe, string race, int age) :Etrevivant(age)
	{
		this->m_name = name;
		this->m_sex = sexe;
		this->m_race = race;
		if (race == "Merou" || race == "Thon" || race == "PoissonClown") {
			this->m_type = "Carnivore";
		}
		if (race == "Bar" || race == "Sole" || race == "Carpe") {
			this->m_type = "Herbivore";
		}
	};
	string getNom();
	void setNom(string name);
	string getRace();
	void setRace(string race);
	string getSexe();
	void setSex(string sex);
	string getType();
	string affectType(string race);

	void manger();
	Poisson makeBaby();

	bool operator==(Poisson p);

};


#endif