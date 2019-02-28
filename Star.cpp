#include "Star.h"
	#include <iostream>
	
	//STARVECTOR
	Starvector::Starvector() {
		this->planets = new Vector();
		this->curr_p =0;
	}

	Starvector::~Starvector() {
		delete(this->planets);
	}
	long Starvector::addPlanet() {
		this->planets->insert(this->curr_p,new Planet(std::rand()%3001));
		Planet *x =this->planets->read(this->curr_p);
		this->curr_p++;
		return x->getID();
	}

	bool Starvector::removePlanet(int planetID) {
		bool retval = false;
		for(unsigned int i = 0; i < this->planets->size(); i++) {
			if(this->planets->read(i) == NULL);
			else if (this->planets->read(i)->getID() ==planetID ){
				this->planets->remove(i);
				retval = true;
			}
		}
		return retval;
	}

	Planet * Starvector::getPlanet(int planetID) {
		Planet *retVal;
		retVal = NULL;
		for(unsigned int i = 0; i < this->planets->size(); i++) {
			if(this->planets->read(i)->getID() == planetID) {
				retVal = this->planets->read(i);
			}
		}
		return retVal;
	}

	void Starvector::orbit() {
		for(unsigned int i = 0; i < this->planets->size(); i++) {
			if (this->planets->read(i)!= NULL){
				this->planets->read(i)->orbit();
			}
		}
	}

	void Starvector::printStarInfo() {
		std::cout << "This star currently has " <<this->curr_p << " planets." << endl;
		for(unsigned int i = 0; i < this->planets->size(); i++) {
			if(this->planets->read(i) != NULL){
			std::cout << "Planet " << this->planets->read(i)->getType() << this->planets->read(i)->getID() << " is " << this->planets->read(i)->getDistance() << " miles away at position " << this->planets->read(i)->getPos() << " around the star." << std::endl;
			}
		}
	}

	unsigned int Starvector::getCurrentNumPlanets() {
		return this->curr_p;
	}

	//STARLIST
	Starlist::Starlist(){
		this->star_list = new List();
	}
	
	Starlist::~Starlist(){
		delete (star_list);
	}
	
	long Starlist::addPlanet(){
		unsigned int idx_plan = 0;
		Planet * x = new Planet(std::rand()%3001);
		star_list->insert(idx_plan, x);
		Planet * j = star_list->read(idx_plan);
		return j->getID();
	}
	
	bool Starlist::removePlanet(long id){
		Planet * newp;
		for(unsigned int x = 0; x <star_list->size(); x++){
			newp = star_list->read(x);
			if (newp->getID() != id){
				return false;
			}
			else{
				star_list->remove(x);
				return true;
			}
		}
	}
	
	Planet * Starlist::getPlanet(long id){
		Planet * newp;
		for(unsigned int x = 0; x < star_list->size(); x++){
			newp =star_list->read(x);
			if (newp->getID() == id){
				return newp;
			}
		}
		return NULL;
	}
	
	void Starlist::orbit(){
		Planet * newp;
		unsigned int x = 0; 
		while(x < star_list->size()){
			newp = star_list->read(x);
			newp->orbit();
			x++;
		}
	}
	
	void Starlist::printStarInfo(){
		std::cout << "This star is currently holding " << star_list->size() << " planets." << std::endl;
		std::cout << "Planets:" << std::endl;
		for(unsigned int x = 0; x < star_list->size(); x++){
			if (star_list->read(x) != NULL){
				std::cout << "	Planet is  " << star_list->read(x)->getType() << star_list->read(x)->getID() << " is " << star_list->read(x)->getDistance() << " miles away at position " << star_list->read(x)->getPos() << " around the star."<< std::endl;
			}
		}
	}
	
	unsigned int Starlist::getCurrentNumPlanets(){
		return star_list->size();
	}