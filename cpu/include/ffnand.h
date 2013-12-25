#ifndef _FFNAND_H
#define _FFNAND_H
#include "nand.h"

class FFNAND
{
	public:
		FFNAND();
                void reset();
		void setSet(bool);
                void setRset(bool);
                bool getQ0();
                bool getQ1();
                void get(bool&, bool&);
	private:
		bool st;
		bool rset;
		bool q0;
		bool q1;
		NAND setNAND;
		NAND rsetNAND;
};
#endif
