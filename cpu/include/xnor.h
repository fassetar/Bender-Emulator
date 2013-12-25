#ifndef _XNOR_H
#define _XNOR_H
#include "xor.h"
#include "not.h"
class XNOR
{
    public:
           XNOR() ;

           void set();
           void set(bool);
           void set(bool, bool);
           bool get();

    private:
           bool input1;
           bool input2;
	   XOR myXORGate;
           NOT myNotGate;
};             
#endif 
