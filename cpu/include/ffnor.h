#ifndef _FFNOR_H
#define _FFNOR_H
#include "nor.h"

class FFNOR
{
	public:
		FFNOR();
		void reset();
		void setS(bool);
		void setR(bool);
		bool getQ();
		bool getQ1();
		void get(bool&, bool&);
	private:
		bool s;
		bool r;
		bool q;
		bool q1;
		NOR sNOR;
		NOR rNOR;
};
#endif		
