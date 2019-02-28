#include "Planet.h"
#include <iostream>

using namespace std;

Planet::Planet(int distance){
	this->distance = distance;
    this->pos = rand() % 360;
    int random = rand() % 3;
    if(random == 0) this->type = 'g';
    else if(random == 1) this->type = 'h';
    else this->type = 'r';
}

int Planet::orbit() {
	if(this->pos == 359) {
		this->pos = 0;
	} else this->pos++;
	return this->pos;
}