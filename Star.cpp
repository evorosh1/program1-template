#include "Star.h"
	#include <iostream>
	
		
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
				star_list->remove(x);
				return true;
			}
		}
	}
	
	Planet * Starlist::getPlanet(long id){
		Planet * newp;
		for(unsigned int x = 0; x < star_list->size(); x++){
			newp = star_list->read(x);
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
