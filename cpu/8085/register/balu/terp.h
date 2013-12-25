#ifndef _TERP_H
#define _TERP_H
#include "register.h"
#include "alu.h"
#include "g8sr.h"
#include <string>
#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;

class TERP
{
	private:
		string instruction, rawHex;
		char temp, param1, param2, first, second;
		G8SR data1, data2;//8bst objects for use in immediate, addresses, 2 and 3 byte instructions.
		void Execute();//selection and call instruction from cpu-reg.
		G8SR Convert();//make to convert from raw hex to 8bit G8SR object.
	public:
		void run(string progName);
}
#endif
