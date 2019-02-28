
#include "Planet.h"
#include "Vector.h"
#include <iostream>
	
Vector::Vector() {
	this->planets = new Planet *[0];
	this->length = 0;
}

Vector::~Vector() {
	for(int i = 0; i < length; i++) {
		delete planets[i];
		planets[i] = NULL;
	}
	delete[] planets;
	planets = NULL;
}

void Vector::insert(int index, Planet *p) {
	Planet** temp = planets;
	if(index >= size()) {
		planets = new Planet *[index+1];
		for(int i = 0; i < size(); i++) {
			planets[i] = temp[i];
		}
		planets[index] = p;
		this->length = index+1;
		delete[] temp;
		return;
	}

	planets = new Planet *[size()+1];
	for(int i = 0; i < size()+1; i++) {
		if(i < index) planets[i] = temp[i];
		else if(i > index) planets[i] = temp[i-1];
		else planets[i] = p;
	}
	delete[] temp;
	this->length++;
	return;
}

Planet * Vector::read(int index) {
	if(index >= size()) return NULL;
	return planets[index];
}

bool Vector::remove(int index) {
	Planet** temp = planets;
	if(index >= size()) return false;

	planets = new Planet *[size()-1];
	for(int i = 0; i < size(); i++) {
		if(i < index) planets[i] = temp[i];
		else if(i > index) planets[i-1] = temp[i];
	}
	//delete temp[index];
	delete[] temp;
	this->length--;
	return true;
}

unsigned Vector::size() {
	return this->length;
}
