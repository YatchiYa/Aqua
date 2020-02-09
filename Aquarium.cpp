
#include "Aquarium.h"
#include "Poisson.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

void Aquarium::setnbTour(int n) {
	this->m_nbtour = n;
}


Aquarium::Aquarium() {
	this->m_nbtour = 0;
	this->m_poissons = std::vector<Poisson>();
	this->m_algues = std::vector<Algue>();
	this->r = rand();
}

Aquarium::~Aquarium() {
	this->m_nbtour = 1;
	this->m_poissons = std::vector<Poisson>();
	this->m_algues = std::vector<Algue>();
	this->r = rand();
}

void Aquarium::addPoisson(Poisson p) {
	this->m_poissons.push_back(p);
}

void Aquarium::addAlgues(Algue a) {
	this->m_algues.push_back(a);
}

vector<Poisson>Aquarium::getPoisson()
{
	return this->m_poissons;
}

vector<Algue>Aquarium::getAlgues()
{
	return this->m_algues;
}

Poisson& Aquarium::getPoissonElt(int p) {
	return this->m_poissons[p];
}
Algue& Aquarium::getAlgueElt(int a) {
	return this->m_algues[a];
}

void Aquarium::erasePoisson(Poisson p, int i) {
	this->m_poissons.erase(this->m_poissons.begin() + i);
}

void Aquarium::eraseAlgue(Algue a, int i) {
	this->m_algues.erase(this->m_algues.begin() + i);
}




void Aquarium::displayContent() {

	ofstream flux;

	int status = remove("rapport.txt");
	if (status != 0)
		return;
	flux.open("rapport.txt", ios::app);
	if (flux) {
		flux << "=======    Rapport de l'aquarium: "  << "=========\n" << std::endl;

		std::cout << "\033[33m" << "=========    Tour " << m_nbtour << " ============ " << "\033[0m"  << std::endl;
		flux << "=========    Tour " << m_nbtour << " ============ " << std::endl;
		std::cout 
			<< "*nombre de possions disponible : " << m_poissons.size() << std::endl
			<< "*nombre d'algues disponible: " << m_algues.size() << std::endl << std::endl;

		flux << "-> MES POISSONS-----" << std::endl;
		std::cout << "\033[35m"  << "-> MES POISSONS " << "\033[0m" << std::endl << std::endl;
		std::cout << "{ " << std::endl;

		for (auto& i : this->m_poissons)
		{
			std::cout << "\033[36m" << " Nom : " << "\033[0m" << i.getNom() << ", "
				<< "\033[36m" << " Sexe : " << "\033[0m" << i.getSexe() << ", "
				<< "\033[36m" << " Race : " << "\033[0m" << i.getRace() << ", "
				<< "\033[36m" << " HP : " << "\033[0m" << i.getHealthPoints() << ", "
				<< "\033[36m" << " Age : " << "\033[0m" << i.getAge() << " ans" << "." << std::endl;
			//penser au Health Points
			flux << i.getNom() << ", "
				<< i.getSexe() << ", "
				<< i.getRace() << ", "
				<< i.getHealthPoints() << ", "
				<< i.getAge() << " ans" << "." << std::endl;
		}
		std::cout << "}" << std::endl << std::endl;

		std::cout << "\033[35m" << "-> MES ALGUES " << "\033[0m" << std::endl << std::endl;
		flux << "-> ALGUES-----" << std::endl;

		std::cout << "{ " << std::endl;
		for (int i = 0; i<this->m_algues.size(); i++)
		{
			std::cout << "\033[36m" << "Algue ID : "  << "\033[0m" << i + 1 << "\033[36m" << " hp : " << "\033[0m" << m_algues[i].getHealthPoints() << "\033[36m" << " Age : " << "\033[0m" << m_algues[i].getAge() << " ans" << "." << std::endl;
			flux << 1 << " algues " << m_algues[i].getHealthPoints() << ", " << m_algues[i].getAge() << " ans" << "." << std::endl;
		}
		std::cout << "}" << std::endl;

	}
	else {
		std::cout << "impossible d'ecrire dans le fichier" << std::endl;
	}
	//flux.close();
}


void Aquarium::computerTour() {
	this->m_nbtour += 1;

	if (!m_poissons.empty()) {

		for (int p = 0; p < this->m_poissons.size(); p++)
		{
			this->traitementPoisson(p);

		}
		std::cout << endl;
	}
	if (!this->m_algues.empty()) {
		for (int a = 0; a < this->m_algues.size(); a++)
		{
			this->traitementAlgue(a);

		}
		std::cout << endl;
		Aquarium::displayContent();
	}

}

void Aquarium::traitementAlgue(int a) {
	this->getAlgueElt(a).setAge(this->getAlgueElt(a).getAge() + 1);
	if (this->getAlgueElt(a).isAlive()) {
		this->getAlgueElt(a).setHealthPoints(this->getAlgueElt(a).getHealthPoints() + 1);

		if (this->getAlgueElt(a).getHealthPoints() >= 10) {

			Algue baby = this->getAlgueElt(a).makeBaby();
			std::cout << "\033[31m" << "[New baby algue added]" << "\033[0m" << std::endl;
			//this->addAlgues(baby);
			this->add<Algue>(baby, this->m_algues);

		}

	}
	else {
		this->eraseAlgue(this->getAlgueElt(a), a);
		//a--;
	}
}

void Aquarium::traitementPoisson(int p) {
	if (this->getPoissonElt(p).isAlive()) {
		this->getPoissonElt(p).takeDammage(1);
		this->getPoissonElt(p).setAge(this->getPoissonElt(p).getAge() + 1);


		if (this->getPoissonElt(p).getHealthPoints() < 5) {
			int j = -1;

			if (this->getPoissonElt(p).getType() == "Carnivore") {
				j = r % this->m_poissons.size();

				if (j != p && !(this->getPoissonElt(j).getRace() == this->getPoissonElt(p).getRace())) {
					this->getPoissonElt(p).manger();
					this->getPoissonElt(j).takeDammage(4);
				}
			}

			if (this->getPoissonElt(p).getType() == "Herbivore") {
				if (!this->m_algues.empty()) {
					j = r % this->m_algues.size();
				}
				this->getPoissonElt(p).manger();
				this->getAlgueElt(j).takeDammage(2);
			}
		}
		else {
			int j = r % this->m_poissons.size();
			
			if ((this->getPoissonElt(p).getRace() == this->getPoissonElt(j).getRace()) &&
				!(this->getPoissonElt(p).getSexe() == this->getPoissonElt(j).getSexe()) &&
				this->getPoissonElt(p).getAge() != 1 && this->getPoissonElt(j).getAge() != 1) {
				
				Poisson baby = this->getPoissonElt(p).makeBaby();

				

				//this->addPoisson(baby);
				this->add<Poisson>(baby, this->m_poissons);
			}
		}
	}
	else {
		this->erasePoisson(this->getPoissonElt(p), p);
	}
}


template<typename T>
void Aquarium::add(T t, vector<T>& v) {
	v.push_back(t);
}
