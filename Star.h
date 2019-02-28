#ifndef STAR_H
#define STAR_H

#include "Planet.h"
#include "Vector.h"
#include "List.h"

class Starvector{
	public:
        Vector planets;
        Starvector();
        ~Starvector();
        long addPlanet();
        bool removePlanet(int planetID);
        Planet * getPlanet(int planetID);
        void orbit();
        void printStarInfo();
        unsigned int getCurrentNumPlanets();
        //you may add any additional methodas you may need.
};

class Starlist{
public:
        List *list;
        Starlist();
        ~Starlist();
        List star_list;
        long addPlanet();
        bool removePlanet(long);
        Planet * getPlanet(long);
        void orbit();
        void printStarInfo();
        unsigned int getCurrentNumPlanets();
};

#endif