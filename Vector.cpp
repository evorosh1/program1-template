#include "Planet.h"
#include "Vector.h"
#include <iostream>
	
Vector::Vector() {
	this->length = 0
	this->planets = NULL;
}

Vector::~Vector() {
	for(int i = 0; i < this->length; i++) {
		delete(this->planets[i]);
	}
	delete[] (this->planets);
}

void Vector::insert(int index, Planet *p) {
	Planet** plants;
	int x = 0;
	if(index > this->lenght) {
		plants = new Planet *[index+1];
		for(int i = 0; i <= index; i++) {
			if (i < this->length)plants[i] = (this->planets)[i];			
			else if (i==index) planets[i] = p;
			else plants[i] = NULL;
		}
		
		this->length = this->length+1;
		if(index>this->length) this->length = index
		this->length = this->length+1;
		delete[] (this->planets);
		this->planets = plants
		return;
	}

	plants = new Planet *[this->length+1];
	for(int i = 0; i < this->lenght+1; i++) {
		if(i != index) {

			plants[i] = (this->planets)[x];
			x++;
		}
		else {
		 plants[i] = p;
		}
	}
	this->length++;
	delete[](this->planets);
	this->planets=plants
	return;
}

Planet * Vector::read(int index) {
	if(index >= this->length) return NULL;
	for(int x = 0; x<this->length;x++){
		if(x == index)
			return(this->planets)[x]:
		}
	return NULL;
}

bool Vector::remove(int index) {
	bool remv =false;
	int x =0;
	if(index >= this->length) return false;
	if(this->planets == NULL)return false;
	Planet** temp;

	temp = new Planet *[(this->length)-1];
	for(int i = 0; i < this->length; i++) {
		if(i != index) {
		temp[x] = (this->planets)[i];
		x++
		}
		else {
		delete(this->planets[i]);
		remv=true;
		}
	}
	this->length--;
	delete(this->planets);
	this->planets = temp;
	return true;
}

unsigned Vector::size() {
	return this->length;
}