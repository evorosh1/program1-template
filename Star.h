Star.h 
#ifndef Star_Planet
	#define Star_Planet
	#include "Planet.h"
	#include "List.h"
	#include "Vector.h"
	
	class Starvector{
	private:
		unsigned int current_p;
	public:
		Vector *vect;
		Starvector();
		~Starvector();
	  long addPlanet();
		bool removePlanet(long);
		Planet * getPlanet(long);
		void orbit();
		void printStarInfo();
		unsigned int getCurrentNumPlanets(){return this->current_p;}
	};
	
	class Starlist{
	public:
		List *list;
		Starlist();
		~Starlist();
		long addPlanet();
		bool removePlanet(long);
		Planet * getPlanet(long);
		void orbit();
		void printStarInfo();
		unsigned int getCurrentNumPlanets();
	};

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
};
	
	#endif
