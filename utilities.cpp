#include "utilites.h"


string copy_tab(string str)
{
	char tmp[15];
	int i = 0, j = 0;

	while (str[i] != ' ' && str[i] != '\0')
	{
		if (str[i] != ',')
		{
			tmp[j] = str[i];
			j++;
		}
		i++;
	}
	tmp[j] = '\0';
	return(tmp);
}

void    fill_Poisson(string str, Aquarium &Aqua)
{
	string name, race, sexe;
	string age_buffer, hp_buffer;
	int age, hp;


	name = copy_tab(str);
	str = str.substr(name.length() + 2, str.length());  // tu trime la chaine de caractere pour la faire avancer jusaq'au nouveau mot
	sexe = copy_tab(str);
	str = str.substr(sexe.length() + 2, str.length());  // tu trime la chaine de caractere pour la faire avancer jusaq'au nouveau mot
	race = copy_tab(str);
	str = str.substr(race.length() + 2, str.length()); // tu trime la chaine de caractere pour la faire avancer jusaq'au nouveau mot
	hp_buffer = copy_tab(str);                         // on recupere la chaine de caractere
	hp = stoi(hp_buffer);                             // convert to int
	str = str.substr(hp_buffer.length() + 2, str.length());
	age_buffer = copy_tab(str);
	age = stoi(age_buffer);


	// new poisson
	Poisson new_poisson = Poisson(name, sexe, race, age);
	new_poisson.setHealthPoints(hp);
	Aqua.addPoisson(new_poisson);

	
}

void    fill_algues(string str, Aquarium &Aqua)
{
	string nb_alges_buffer, age_buffer, hp_buffer;
	int nb_algues, age, hp;
	string algues = "algues";
	

	nb_alges_buffer = copy_tab(str);        // on recupere la chaine de caractere
	nb_algues = stoi(nb_alges_buffer);
	str = str.substr(nb_alges_buffer.length() + algues.length() + 2, str.length());  // tu trime la chaine de caractere pour la faire avancer jusaq'au nouveau mot

	hp_buffer = copy_tab(str);
	hp = stoi(hp_buffer);
	str = str.substr(hp_buffer.length() + 2, str.length());
	age_buffer = copy_tab(str);        // on recupere la chaine de caractere
	age = stoi(age_buffer);                             // convert to int

	while (nb_algues > 0)
	{
		Algue new_algue = Algue(age);
		new_algue.setHealthPoints(hp);
		Aqua.addAlgues(new_algue);
		nb_algues--;
	}

}



void update_data(Aquarium &Aqua)
{
	ifstream MyFile("rapport.txt");

	if (MyFile)
	{
		string line;

		while (getline(MyFile, line)) //Tant qu'on n'est pas à la fin, on lit
		{
			if (line[0] >= '0' && line[0] <= '9')
				fill_algues(line, Aqua);
			else if ((line[0] >= 'A' && line[0] <= 'Z') || (line[0] >= 'a' && line[0] <= 'z'))
				fill_Poisson(line, Aqua);
			else if (line[0] == '=')		// pour recuperer le nombre de tour 
			{
				int i = 0;
				while (line[i] == '=' || line[i] == ' ')
					i++;
				if (line[i] == 'T')
				{
					i++;
					while (line[i] >= 'a' && line[i] <= 'z')
						i++;
					i++;
					line = line.substr(i, line.length());
					string nbt_buff;
					int nbt;

					nbt_buff = copy_tab(line);        // on recupere la chaine de caractere
					nbt = stoi(nbt_buff);                             // convert to int
					Aqua.setnbTour(nbt);
				}
			}

		}
		cout << "\033[36m" << " Info : " << "\033[0m";
		cout << "\033[32m" << " [File loaded with success]\n \n" << "\033[0m" << endl;

	}
	else
	{
		cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
	}
}
