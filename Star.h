Star.h 
#ifndef Star_Planet
	#define Star_Planet
	#include "Planet.h"
	#include "List.h"
	#include "Vector.h"
	
	class Starvector{
	private:
		unsigned int curr_p;
	public:
		Vector *planets;
		Starvector();
		~Starvector();
	  long addPlanet();
		bool removePlanet(long);
		Planet * getPlanet(long);
		void orbit();
		void printStarInfo();
		unsigned int getCurrentNumPlanets()
	};
	
	class Starlist{
	public:
		List *star_list;
		Starlist();
		~Starlist();
		long addPlanet();
		bool removePlanet(long);
		Planet * getPlanet(long);
		void orbit();
		void printStarInfo();
		unsigned int getCurrentNumPlanets();
	};
	
	#endif
