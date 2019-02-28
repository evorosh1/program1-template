#ifndef PLANET_H
#define PLANET_H

#include <iostream>
class Planet{
	private:
		int pos;
		int distance;
		char type;
	public:
		int getPos() {return pos;}
		Planet(int);
        int orbit();
		long getID() {return (long)this;}
        int getDistance() {return this->distance;}
        char getType() {return this->type;}
		//you may add any additional methods you may need.
};

#endif