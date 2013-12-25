#ifndef _MEM256kB_H
#define _MEM256kB_H
#include "g8sr.h"
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

class MEM
{
	private:
		G8SR mem[256][256];
		int addGet(G8SR add);
		void address(int addr);
	public:
		MEM();
		G8SR getMem(G8SR bitAddr1, G8SR bitAddr2);
		void putMem(G8SR bitAdd1, G8SR bitAdd2, G8SR data);
		void putMem(int add1, int add2, G8SR data);
//		void putMem(string hexAdd, G8SR data);
		void memDump();
};
#endif
