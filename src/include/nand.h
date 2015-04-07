#ifndef _NAND_H
#define _NAND_H

#include "and.h"
#include "not.h"

class NAND
{
	public:
		NAND();

		void reset();
		void set(bool);
		void set(bool, bool);
		bool get();

	private:
		bool input1;
		bool input2;
		AND myAndGate;
		NOT myNotGate;
};

#endif
