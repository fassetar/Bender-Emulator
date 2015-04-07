#ifndef _RGSTR_H
#define _RGSTR_H
#include "g8sr.h"
#include "ffnor.h"
#include "and.h"
#include "mem256kB.h"
//8085 has 7 8-bit registers named A, B, C, D, E, H, and L.  A is the 8-bit accumulator and the other 6 can be used individually or as 3 16-bit register pairs. (BC, DE, HL)  HA is occasionally used as a 16 bit accumulator.
class REG
{
	private:
		G8SR rgstr[7];
//		FFNOR flag[5];
		MEM memory;
//Do we want an array of flags, or would it be better to do individually named latches for flags?

		FFNOR parity;
		FFNOR zero;
		FFNOR carry;
		FFNOR axuCarry;
		FFNOR sign;

		void negate(char);
		void And(char);
		int regConv(char regNam);
		void clear();
		void clear(char regX);
		void clear(char regX, char regY);
		void set(char regZ, G8SR in);
		void set(char reg1, G8SR in1, char reg2, G8SR in2);
		G8SR get(char regO);
		void get(char reg1, G8SR& out1, char reg2, G8SR& out2);
		bool shift(char reg, bool bit);	//add bit to right of set register and shift. return bit that falls off the end.
		bool rotate(char reg, bool bit); //shift bits left 1, add incoming bit to the right of the byte bits, and output the pushed bit from the left.
		bool getData(char reg1, char reg2);//Get data from Memory address stored in registers.
		bool getData(G8SR reg1, G8SR reg2);//Get data from Memory address indicated by 2 byte address.
		void putData(char reg1, char reg2, G8SR data);//Put data in Memory at address stored in 2 registers.
//Here begins the specific private functions to be used by incoming hex instructions.
		void move(char r1, char r2);
		void move(char r, G8SR mo);
		void move(char r, G8SR a, G8SR b);
		void move(char n, char o, char p, char q);
		void move(G8SR dat);
		void moveS(char r, char h, char l);
		void moveL(char r, char h, char l);
		void move(G8SR, G8SR, char);
		void ANAM(char);	
	public:
		REG();
		//MOV r, r
		void i0x47();
		void i0x4F();
		void i0x57();
		void i0x5F();
		void i0x67();
		void i0x6F();
		void i0x78();
		void i0x48();
		void i0x50();
		void i0x58();
		void i0x60();
		void i0x68();
		void i0x79();
		void i0x41();
		void i0x51();
		void i0x59();
		void i0x61();
		void i0x69();
		void i0x7A();
		void i0x42();
		void i0x4A();
		void i0x5A();
		void i0x62();
		void i0x6A();
		void i0x7B();
		void i0x43();
		void i0x4B();
		void i0x53();
		void i0x63();
		void i0x6B();
		void i0x7C();
		void i0x44();
		void i0x4C();
		void i0x54();
		void i0x5C();
		void i0x6C();
		void i0x7D();
		void i0x45();
		void i0x4D();
		void i0x55();
		void i0x5D();
		void i0x65();
		//MOV r, M
		void i0x7E();
		void i0x46();
		void i0x4E();
		void i0x56();
		void i0x5E();
		//MOV M, r
		void i0x77();
		void i0x70();
		void i0x71();
		void i0x72();
		void i0x73();
		//MVI r, data
		void i0x3E(G8SR data);
		void i0x06(G8SR data);
		void i0xE0(G8SR data);
		void i0x16(G8SR data);
		void i0x1E(G8SR data);
		void i0x26(G8SR data);
		void i0x2E(G8SR data);
		//MVI M, data
		void i0x36(G8SR data);
		//LXI rp, data 16
		void i0x01(G8SR lowData, G8SR highData);
		void i0x11(G8SR lowData, G8SR highData);
		void i0x21(G8SR lowData, G8SR highData);
		//LDA addr
		void i0x3A(G8SR lowAddr, G8SR highAddr);
		//STA addr
		void i0x32(G8SR lowAddr, G8SR highAddr);
		//LHLD addr
		void i0x2A(G8SR add1, G8SR add2);
		//SHLD addr
		void i0x22(G8SR add1, G8SR add2);
		//LDAX rp
		void i0x0A();
		void i0x1A();
		//STAX rp
		void i0x02();
		void i0x12();
		//XCHG
		void i0xEB();
//Arithmetic Group
		void i0x80();
		void i0x81();
		void i0x82();
		void i0x83();
		void i0x84();
		void i0x85();
		void i0x86();
		void i0xA6(G8SR data);
		void i0x88();
		void i0x89();
		void i0x8A();
		void i0x8B();
		void i0x8C();
		void i0x8D();
		void i0x8E();
		void i0xCE(G8SR data);
		void i0x90();
		void i0x91();
		void i0x92();
		void i0x93();
		void i0x94();
		void i0x95();
		void i0x96();
		void i0xD6(G8SR data);
		void i0x98();
		void i0x99();
		void i0x9A();
		void i0x9B();
		void i0x9C();
		void i0x9D();
		void i0x9E();
		void i0xDE(G8SR data);
//Incriment
		void i0x3C();
		void i0x04();
		void i0x0C();
		void i0x14();
		void i0x1C();
		void i0x24();
		void i0x2C();
		void i0x34();
		void i0x3D();
//Decriment
		void i0x05();
		void i0x0D();
		void i0x15();
		void i0x1D();
		void i0x25();
		void i0x2D();
		void i0x35();
//Incriment pair.
		void i0x03();
		void i0x13();
		void i0x23();
		void i0x33();
//Decriment pair
		void i0x0B();
		void i0x1B();
		void i0x2B();
		void i0x3B();
//Add pair
		void i0x09();
		void i0x19();
		void i0x27();
//Decimal adjust A
		void i0x27();
//Logical Group

//Branch Group

//Stack I/O Group and Machine Controls.

};
#endif
