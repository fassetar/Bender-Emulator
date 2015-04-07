#ifndef _R6502_H
#define _R6502_H

#include "g8sr.h"
#include "and.h"
#include "nor.h"
// STATUS register flags
#define NEGATIVE	8
#define OVERFLOW	7
#define RESERVED	6
#define BREAK		5
#define DECIMAL		4
#define INTERRUPT	3
#define	ZERO		2
#define CARRY		1
class reg6502 : public G8SR
{
	public:
		reg6502();
		void clear();
	private:
//		G8SR myReg[8];			
};

#endif
