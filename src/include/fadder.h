#ifndef _FADDER_H
#define _FADDER_H

#include "hadder.h"
#include "or.h"

class FADDER: public HADDER 
{
	public:
		FADDER();
		void set(bool, bool, bool);
		bool getSum();
		bool getCarry();

	private: 
		HADDER ab;
		HADDER sc;
		OR cAdd;
		bool cOut;
		bool sOut; 
}; 

#endif 
