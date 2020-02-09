#include "Etrevivant.h"
#include <iostream>
#include <string>
#include <iostream>
//using namespace std;

Etrevivant::Etrevivant(int age) {
	this->m_age = age;
	this->m_healthPoints = 10;
}
Etrevivant::Etrevivant() {
	this->m_age = 0;
	this->m_healthPoints = 10;
}


void Etrevivant::setAge(int age) {
	this->m_age = age;
}

int Etrevivant::getAge() {
	return this->m_age;
}

int Etrevivant::getHealthPoints() {
	return this->m_healthPoints;
}
void Etrevivant::setHealthPoints(int heathPoints) {
	this->m_healthPoints = heathPoints;
}
void Etrevivant::takeDammage(int dammage) {
	this->m_healthPoints = this->m_healthPoints - dammage;
}

bool Etrevivant::isAlive() {
	int pv = this->getHealthPoints();
	int age = this->getAge();
	if (pv < 0 || age >= 20) {
		return false;
	}
	else {
		return true;
	}
}