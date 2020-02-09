#pragma once

#include <string>
#include <iostream>
#define DEF_ETREVIVANT

#ifndef _ETREVIVANT_HPP
#define _ETREVIVANT_HPP


class Etrevivant
{
public:

	Etrevivant(int age);
	Etrevivant();
	int getAge();
	void setAge(int age);
	int getHealthPoints();
	void setHealthPoints(int heathPoints);
	void takeDammage(int dammage);
	bool isAlive();



private:
	int m_healthPoints;
	int m_age;
};


#endif