#ifndef HERO_H_
#define HERO_H_
#include "Person.h"

class Equiment {

};




class Hero : public Person {
private:
  //Bag bag;
public:
	void CheckUpdate();
	//Default constructor should random generate a hero 
	Hero();

	//Change the age and status of the heros
	void getOlder();

};


#endif
