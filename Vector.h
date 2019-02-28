
#ifndef VECTOR_H
#define VECTOR_H

#include "Planet.h"

class Vector{
	private:
		int length;
		Planet ** planets;
	public:
         Vector();
        ~Vector();
        void insert(int index, Planet *p);
        Planet *read(int index);
        bool remove(int index);
        unsigned size();
};

#endif