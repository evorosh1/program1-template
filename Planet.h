#ifndef Planet_x
#define Planet_x
	
	class Planet{
	private:
		long id;
		int position;
		int distance;
		char type;
	public:
		Planet(int);
	  	int orbit();
		long getID() {return this->id;}
	  	int getDistance() {return this->distance;}
	  	int getPos() {return this->position;}
		char getType() {return this->type;}
	};
	
#endif
