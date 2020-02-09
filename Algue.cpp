#include "Algue.h"

Algue Algue::makeBaby() {

	this->setHealthPoints(this->getHealthPoints() / 2);
	Algue baby = Algue();
	baby.setHealthPoints(this->getHealthPoints());
	return baby;

}
bool Algue::operator==(Algue a) {
	if ((a.getAge() == this->getAge()) &&
		(a.getHealthPoints() == this->getHealthPoints())) {
		return true;
	}
	else {
		return false;
	}
}