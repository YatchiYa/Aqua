#pragma once
//#ifndef DEF_POISSON
#define DEF_ALGUE
#include <string>
#include <iostream>
#include "EtreVivant.h"

#ifndef _ALGUE_HPP
#define _ALGUE_HPP


class Algue :
	public Etrevivant
{
public:
	Algue() :Etrevivant()
	{};
	Algue(int age) :Etrevivant(age)
	{};
	Algue makeBaby();
	bool operator==(Algue a);

};


#endif