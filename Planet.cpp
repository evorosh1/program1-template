#include "Planet.h"
#include <iostream>
	Planet::Planet(int dis){
		this->id = (long)this;
		this->distance = dis;
		this->position = std::rand()%360;
		int num = std::rand()%3;
		if (num == 0) this->type = 'h';
		if (num == 1) this->type = 'r';
		if (num == 2) this->type = 'g';
	}
	
	int Planet::orbit(){
		this->position = this->position+ 1;
		if (this->position > 359){
			this->position = 0;
		}
		return this->position;
	}
