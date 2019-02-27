#include "Star.h"
	#include <iostream>
	
	//STARVECTOR
	Starvector::Starvector() {
		planets = Vector();
	}

	Starvector::~Starvector() {
		planets.Vector::~Vector();
	}
	long Starvector::addPlanet() {
		planets.Vector::insert(Starvector::getCurrentNumPlanets(), new Planet(0));
		return planets.Vector::read(Starvector::getCurrentNumPlanets()-1)->Planet::getID();
	}

	bool Starvector::removePlanet(int planetID) {
		for(int i = 0; i < Starvector::getCurrentNumPlanets(); i++) {
			if(planets.Vector::read(i)->Planet::getID() == planetID) {
				planets.Vector::remove(i);
				return true;
			}
		}
		return false;
	}

	Planet * Starvector::getPlanet(int planetID) {
		for(int i = 0; i < Starvector::getCurrentNumPlanets(); i++) {
			if(planets.Vector::read(i)->Planet::getID() == planetID) {
				return planets.Vector::read(i);
			}
		}
		return NULL;
	}

	void Starvector::orbit() {
		for(int i = 0; i < Starvector::getCurrentNumPlanets(); i++) {
			planets.Vector::read(i)->Planet::orbit();
		}
	}

	void Starvector::printStarInfo() {
		cout << "This star currently has " << Starvector::getCurrentNumPlanets() << " planets." << endl;
		for(int i = 0; i < Starvector::getCurrentNumPlanets(); i++) {
			cout << "Planet " << planets.Vector::read(i)->Planet::getType() << i << " is " << planets.Vector::read(i)->Planet::getDistance() << " miles away at position " << planets.Vector::read(i)->Planet::getPos() << " around the star." << endl;
		}
	}

	unsigned int Starvector::getCurrentNumPlanets() {
		return planets.Vector::size();
	}

	//STARLIST
	Starlist::Starlist(){
		this->list = new List();
	}
	
	Starlist::~Starlist(){
		delete (list);
	}
	
	long Starlist::addPlanet(){
		unsigned int idx_plan = 0;
		Planet * x = new Planet(std::rand()%3001);
		list->insert(idx_plan, x);
		Planet * j = list->read(idx_plan);
		return j->getID();
	}
	
	bool Starlist::removePlanet(long id){
		Planet * newp;
		for(unsigned int x = 0; x < list->size(); x++){
			newp = list->read(x);
			if (newp->getID() != id){
				return false;
			}
			else{
				list->remove(x);
				return true;
			}
		}
	}
	
	Planet * Starlist::getPlanet(long id){
		Planet * newp;
		for(unsigned int x = 0; x < list->size(); x++){
			newp = list->read(x);
			if (newp->getID() == id){
				return newp;
			}
		}
		return NULL;
	}
	
	void Starlist::orbit(){
		Planet * newp;
		unsigned int x = 0; 
		while(x < list->size()){
			newp = list->read(x);
			newp->orbit();
			x++;
		}
	}
	
	void Starlist::printStarInfo(){
		std::cout << "This star is currently holding " << list->size() << " planets." << std::endl;
		std::cout << "Planets:" << std::endl;
		for(unsigned int x = 0; x < list->size(); x++){
			if (list->read(x) != NULL){
				std::cout << "	Planet is  " << list->read(x)->getType() << list->read(x)->getID() << " is " << list->read(x)->getDistance() << " miles away at position " << list->read(x)->getPos() << " around the star."<< std::endl;
			}
		}
	}
	
	unsigned int Starlist::getCurrentNumPlanets(){
		return list->size();
	}