#include "Poisson.h"


string Poisson::getNom() {
	return this->m_name;
}

string Poisson::getRace() {
	return this->m_race;
}

string Poisson::getSexe() {
	return this->m_sex;
}

string  Poisson::getType() {

	return this->m_type;
}
void Poisson::setSex(string sex) {
	this->m_sex = sex;
}

void Poisson::setRace(string race) {
	this->m_race = race;
}
void Poisson::setNom(string name) {
	this->m_name = name;
}


string Poisson::affectType(string race) {
	if (race == "Merou" || race == "Thon" || race == "PoissonClown") {
		return "Carnivore";
	}
	if (race == "Bar" || race == "Sole" || race == "Carpe") {
		return "Herbivore";
	}
}



void Poisson::manger() {

	if (this->getType() == "Carnivore") {
		std::cout << "\033[32m" << "  [Un poisson de type carnivore a manger un poisson] " << "\033[0m" << std::endl;
		this->setHealthPoints(this->getHealthPoints() + 5);
	}
	else if (this->getType() == "Herbivore") {
		std::cout << "\033[32m" << "  [Un poisson de type herbivore a manger une algue] " << "\033[0m" << std::endl;
		this->setHealthPoints(this->getHealthPoints() + 3);
	}
}

Poisson Poisson::makeBaby() {
	int sexInt = r % 2;

	//EtreVivant* baby(0);
	Poisson	poissonBaby = Poisson(this->getNom(), "Indefined", this->getRace(), 0);
	if (sexInt == 0) {
		poissonBaby.setSex("M");
	}
	else if (sexInt == 1) {
		poissonBaby.setSex("F");
	}
		std::cout << "\033[32m" << "[Fish Baby is born  {" << "\033[0m";
		std::cout << "\033[32m" << "Nom : " << this->getNom() << " Sexe : " << this->getSexe() << "}]" << "\033[0m" << std::endl;
	return  poissonBaby;
}

bool Poisson::operator==(Poisson p) {
	if ((p.getNom() == this->getNom()) &&
		(p.getRace() == this->getRace()) &&
		(p.getType() == this->getType()) &&
		(p.getSexe() == this->getSexe()) &&
		(p.getAge() == this->getAge()) &&
		(p.getHealthPoints() == this->getHealthPoints())) {
		return true;
	}
	else {
		return false;
	}
}
