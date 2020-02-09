
#include <iostream>
#include <fstream>
#include <string>
#include "utilites.h"
#include "Aquarium.h"
#include "Etrevivant.h"
#include "Poisson.h"
#include "Algue.h"

int main(void)
{
	Aquarium aqua;
	aqua = Aquarium();

	std::cout << "			  __________			\n" <<
		"			 < Aquarium !>			 \n" <<
		"			  ----------				\n" <<
		"              \\ \n" <<
		"               \\ \n" <<
		"		.---. \n" <<
		"	       | o_o |\n"<<
		"               | :_/ |\n"<<
		"	       //   \ \\ \n"<<
       "              (|     | )\n"<<
		"              /'\_   _/`\\ \n"<<
		"              \\_) = (__/ \n" << endl;


	update_data(aqua);			// lecture des donner sur le fichier


	aqua.displayContent();		// afficher l'ensemble de tes donnée a l'etat initial


	std::string rep1;
	do {

		std::cout << "Do you want to add fishes or sea weeds ? Y/N (Q to exit after next tour)" << std::endl;
		std::cin >> rep1;
		if (rep1 == "Y") {
			std::string rep2;
			do
			{
				std::cout << "Which one : fishes or sea weeds ? F/S" << std::endl;
				std::cin >> rep2;
			} while (rep2 != "F" && rep2 != "S");

			if (rep2 == ("F"))
			{
				std::string name;
				std::string sex;
				std::string race;
				int age = -1;
				std::cout << "How many ?" << std::endl;
				int nb;
				std::cin >> nb;
				for (int j = 0; j < nb; j++)
				{

					std::cout << "What name do you want to give to the fish ?" << std::endl;
					std::cin >> name;

					std::cout << "What sex is it ? M/F" << std::endl;
					std::cin >> sex;

					std::cout << "What is its race ? " << std::endl;
					std::cout << " Merou / Carpe / Bar /Sole / Thon / Poisson-clown " << std::endl;
					std::cin >> race;

					do {
						std::cout << "What is its age ?" << std::endl;
						std::cin >> age;
					} while (age < 0 || age >= 99999);

					std::cout << "age" << age << std::endl;
					Poisson p = Poisson(name, sex, race, age);
					aqua.addPoisson(p);
				}
			}
			else if (rep2 == "S")
			{
				std::cout << "How many ?" << std::endl;
				int nb;
				std::cin >> nb;

				for (int j = 0; j < nb; j++)
				{
					std::cout << "How old ?" << std::endl;
					int age;
					std::cin >> age;
					if (age != NULL) {
						Algue a = Algue(age);
						aqua.addAlgues(a);
					}
					else {
						Algue a = Algue();
						aqua.addAlgues(a);
					}

				}
			}
		}
		aqua.computerTour();
	} while (rep1 != "Q");

	return (0);
}

