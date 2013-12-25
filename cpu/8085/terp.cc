#include "register.h"
#include "alu.h"
#include "terp.h"
#include <cmath>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

/*Rough coverage for start of interpreter.
numeric codes need , be converted , HEX.
Cases are going , need , be nested for transference , translator.
Going , need three string inputs into the interpreter one for the command and two for the bytes or hex addresses , be attached , the command.
Data Transfer group covered, but not fleshed or fully defined.*/

void TERP::run(string progFile);
{
	int hold;
	instruction="0";
	ifstream assIn;
	ofstream assOut;
	assIn.open(progFile.c_str());
	assOut.open("8085Output.dat");
	while (!assIn.eof)
	{
		if (instruction == "0")
		assIn >> instruction;
		assIn >> temp;
		if (temp == '%')
		{
			assIn >> first;
			assIn >> second;
			assIn >> temp;
			data1=Convert(first, second);
			if (temp == '%')
			{
				assIn >> third;
				assIn >> fourth;
				data2=Convert(first, second);
			}
		}
		else if (temp != '\0')
		{
			param1=temp;
			assIn >> temp;
			if (temp == '%')
			{
				assIn >> first;
				assIn >> second;
				data1=Convert(first, second);
			}
			else if (temp != '\0')
				param2=temp;
		}
		Execute();
		instruction="0";
	}
}

G8SR TERP::Convert(char wun, char tew)
{
	G8SR valu;
	int core, temp;
	wun=static_cast<int>(first);
	if (temp < 58 )
		core=(temp-48)*8;
	else if (temp < 71 )
		core=(temp-55)*8;
	else if (temp < 103)
		core=(temp-87)*8;
	tew=static_cast<int>(second);
	if (temp <58)
		core=core+(temp-48);
	else if (temp<71)
		core=core+(temp-55);
	else if (temp<103)
		core=core+(temp-87);
	for (int i=8; i>0; i++)
	{
		int place=pow(2, i-1);
		if (core-place>0)
		{
			core=core-place;
			valu.set(true, i);
		}
	}
	valu.clockTick();
return valu;
}

void TERP::Execute()  //Nowhere near completed::
{
/*Completed MOV, LDAX, STAX, XCHG, MVI, LXI, LDA, STA, LHLD, SHLD, ADD 
*/
//Data Transfer Group
	if (instruction == "MOV") /*moves content of register SSS , register DDD*/
	{
		switch (param1)
		{
		case 'A':
		case 'a':
			switch (param2)
			{
			case 'B':
			case 'b':
				cpu.i0x78();//B to A 01111000
				break;
			case 'C':
			case 'c':
				cpu.i0x79();//C to A 01111001
				break;
			case 'D':
			case 'd':
				cpu.i0x7A();//D to A 01111010
				break;
			case 'E':
			case 'e':
				cpu.i0x7B();//E to A 01111011
				break;
			case 'H':
			case 'h':
				cpu.i0x7C();//H to A 01111100
				break;
			case 'L':
			case 'l':
				cpu.i0x7D();//L to A 01111101
				break;
			case 'M':
			case 'm':
				cpu.i0x7E();//memory to A 01111110
				break;
			default:
				//ERROR Fool!
				break;
			}
			break;
		case 'B':
		case 'b':
			switch (param2)
			{
			case 'A':
			case 'a':
				cpu.i0x47();//A to B 01000111
				break;
			case 'C':
			case 'c':
				cpu.i0x41();//C to B 01000001
				break;
			case 'D':
			case 'd':
				cpu.i0x42();//D to B 01000010
				break;
			case 'E':
			case 'e':
				cpu.i0x43();//E to B 01000011
				break;
			case 'H':
			case 'h':
				cpu.i0x44();//H to B 01000100
				break;
			case 'L':
			case 'l':
				cpu.i0x45();//L to B 01000101
				break;
			case 'M':
			case 'm':
				cpu.i0x46();//memory to B 01000110
				break;
			default:
				//ERROR Fool!
				break;
			}
			break;
		case 'C':
		case 'c':
			switch (param2)
			{
			case 'A':
			case 'a':
				cpu.i0x4F();//A to C 01001111
				break;
			case 'B':
			case 'b':
				cpu.i0x48();//B to C 01001000
				break;
			case 'D':
			case 'd':
				cpu.i0x4A();//D to C 01001010
				break;
			case 'E':
			case 'e':
				cpu.i0x4B();//E to C 01001011
				break;
			case 'H':
			case 'h':
				cpu.i0x4C();//H to C 01001100
				break;
			case 'L':
			case 'l':
				cpu.i0x4D();//L to C 01001101
				break;
			case 'M':
			case 'm':
				cpu.i0x4E();//memory to C 01001110
				break;
			default:
			}
			break;
		case 'D':
		case 'd':
			switch (param2)
			{
			case 'A':
			case 'a':
				cpu.i0x57();//A to D 01010111
				break;
			case 'B':
			case 'b':
				cpu.i0x50();//B to D 01010000
				break;
			case 'C':
			case 'c':
				cpu.i0x51();//C to D 01010001
				break;
			case 'E':
			case 'e':
				cpu.i0x53();//E to D 01010011
				break;
			case 'H':
			case 'h':
				cpu.i0x54();//H to D 01010100
				break;
			case 'L':
			case 'l':
				cpu.i0x55();//L to D 01010101
				break;
			case 'M':
			case 'm':
				cpu.i0x56();//memory to D 01010110
				break;
			default:
			}
			break;
		case 'E':
		case 'e':
			switch (param2)
			{
			case 'A':
			case 'a':
				cpu.i0x5F();//A to E 01011111
				break;
			case 'B':
			case 'b':
				cpu.i0x58();//B to E 01011000
				break;
			case 'C':
			case 'c':
				cpu.i0x59();//C to E 01011001
				break;
			case 'D':
			case 'd':
				cpu.i0x5A();//D to E 01011010
				break;
			case 'H':
			case 'h':
				cpu i0x5C();//H to E 01011100
				break;
			case 'L':
			case 'l':
				cpu.i0x5D();//L to E 01011101
				break;
			case 'M':
			case 'm':
				cpu.i0x5E();//memory to E 01011110
				break;
			default:
			}
			break;
		case 'H':
		case 'h':
			switch (param2)
			{
			case 'A':
			case 'a':
				cpu.i0x67();//A to H 01100111
				break;
			case 'B':
			case 'b':
				cpu.i0x60();//B to H 01100000
				break;
			case 'C':
			case 'c':
				cpu.i0x61();//C to H 01100001
				break;
			case 'D':
			case 'd':
				cpu.i0x62();//D to H 01100010
				break;
			case 'E':
			case 'e':
				cpu.i0x63();//E to H 01100011
				break;
			case 'L':
			case 'l':
				cpu.i0x65();//L to H 01100101
				break;
			default:
			}
			break;
		case 'L':
		case 'l':
			switch (param2)
			{
			case 'A':
			case 'a':
				cpu.i0x6F();//A to L 01101111
				break;
			case 'B':
			case 'b':
				cpu.i0x68();//B to L 01101000
				break;
			case 'C':
			case 'c':
				cpu.i0x69();//C to L 01101001
				break;
			case 'D':
			case 'd':
				cpu.i0x6A();//D to L 01101010
				break;
			case 'E':
			case 'e':
				cpu.i0x6B();//E to L 01101011
				break;
			case 'H':
			case 'h':
				cpu.i0x6C();//H to L 01101100
				break;
			default:
				break;
			}
			break;
		case 'M':
		case 'm':
			switch (param2)
			{
			case 'A':
			case 'a':
				cpu.i0x77();//A to memory  01110111
				break;
			case 'B':
			case 'b':
				cpu.i0x70();//B to memory 01110000
				break;
			case 'C':
			case 'c':
				cpu.i0x71();//C to memory 01110001
				break;
			case 'D':
			case 'd':
				cpu.i0x72();//D to memory 01110010
				break;
			case 'E':
			case 'e':
				cpu.i0x73();//E to memory 01110011
				break;
			default:
				break;
			}
			break;
		}
	else if (instruction == "LDAX")//move content at memory location of memory pair RP , register A.
	{
		switch (param1)
		{
		case 'B':
			cpu.i0x0A;//memory at B-C address to A. 00001010
			break;
		case 'D':
			cpu.i0x1A;//memory at D-E address to A. 00011010
			break;
		default:
		}
		break;
	}
	else if (instruction == "STAX")//contents of register A moved , memory address located in RP.
	{
		switch (param1)
		{
		case 'B':
		case 'B-C':
			cpu.i0x02;//A to memory at B-C address.  00000010
			break;
		case 'D':
		case 'D-E':
			cpu.i0x12;//A to memory at D-E address.  00010010
			break;
		default:
		}
	}
	else if (instruction == "XCHG")/*contents of H-L swaped with contents of D-E.*/
		cpu.i0xEB;//  11101011
	else if (instruction == "MVI")
	{
		switch (param1)
		{
		case 'A':
		case 'a':
			cpu.i0x3E(data1);// move data1 to A. 00111110
			break;
		case 'B':
		case 'b':
			cpu.i0x06(data1);//move data1 to B 00000110
			break;
		case 'C':
		case 'c':
			cpu.i0x0E(data1);//move data1 to C 00001110
			break;
		case 'D':
		case 'd':
			cpu.i0x16(data1);//move data1 to D 00010110
			break;
		case 'E':
		case 'e':
			cpu.i0x1E(data1);//move data1 to E 00011110
			break;
		case 'H':
		case 'h':
			cpu.i0x26(data1);//move data1 to H 00100110
			break;
		case 'L':
		case 'l':
			cpu.i0x2E(data1);//move data1 to L 00101110
			break;
		case 'M':
		case 'm':
			cpu.i0x36(data1);//move data1 to memory at address in H-L 00110110
		default:
			break;
		}
	}
//three bytes.
	else if (instruction == "LXI") /*byte 3 in high order register, byte two in low order register of RP.*/
	{
		switch (param1)
		{
		case 'B':
			cpu.i0x01(data1, data2);//data2 in B, data1 in C. 00000001
			break;
		case 'D':
			cpu.i0x11(data1, data2);//data2 in D, data1 in E.  00010001
			break;
		case 'H':
			cpu.i0x21(data1, data2);//data2 in H, data1 in L.  00100001
			break;
		default:
			break;
		}
	}
	else if (instruction == "LDA")//content in memory location with address in byte 2 and 3 moved , register A.
		cpu.i0x3A(data1, data2);//content of memory at address in data1, data2 to A.  00111010
	else if (instruction == "STA")//move accumulator content , memory address in bytes 2 and 3.
		cpu.i0x32(data1, data2);//  00110010
	else if (instruction == "LHLD") /*move content of memory location at byte 2 and 3 , register L.  content of succeeding memory address , register H.*/
		cpu.i0x2A(data1, data2);// 00101010
	else if (instruction == "SHLD")/*L stored in memory address of byte 3 then 2, H sotred in the next address.  H and L stored direct.*/
		cpu.i0x22(data1, data2);//  00100010
	//Arithmetic Group.
	else if (instruction == "ADD") //Add register.
	{
		switch (param1)
		{
		case 'B':
		case 'b':
			cpu.i0x80;//A=B+A  10000000
			break;
		case 'C':
		case 'c':
			cpu.i0x81;//A=C+A  10000001
			break;
		case 'D':
		case 'd':
			cpu.i0x82;//A=D+A  10000010
			break;
		case 'E':
		case 'e':
			cpu.i0x83;//A=E+A  10000011
			break;
		case 'H':
		case 'h':
			cpu.i0x84;//A=H+A  10000100
			break;
		case 'L':
		case 'l':
			cpu.i0x85;//A=L+A  10000101
			break;
		case 'M':
		case 'm':
			cpu.i0x86;//A=A+(memory at H-L)  10000110
			break;
		default:
			break;
		}
	}
	else if (instruction=="ADI") //Add immediate.
		cpu.i0xA6(data1);//A=A+data1  11000110
	else if (instruction=="ADC") //Add register with carry.
	{
		switch (param1)
		{
		case 'B':
		case 'b':
			cpu.i0x88();//A=B+A with carry 10001000.
			break;
		case 'C':
		case 'c':
			cpu.i0x89();//A=C+A with carry 10001001.
			break;
		case 'D':
		case 'd':
			cpu.i0x8A();//A=D+A with carry 10001010.
			break;
		case 'E':
		case 'e':
			cpu.i0x8B();//A=E+A with carry 10001011.
			break;
		case 'H':
		case 'h':
			cpu.i0x8C();//A=H+A with carry 10001100.
			break;
		case 'L':
		case 'l':
			cpu.i0x8D();//A=L+A with carry 10001101.
			break;
		case 'M':
		case 'm':
			cpu.i0x8E();//A=A+mem@H-L with carry 10001110.
			break;
		default:
			break;
		}
	}
	else if (instruction == "ACI") //Add immediate with carry.
		cpu.i0xCE(data);//add data with carry 11001110.
	else if (instruction == "SUB") //subtract register.
	{
		switch (param1)
		{
		case 'B':
		case 'b':
			cpu.i0x90();//A=A-B 10010000.
			break;
		case 'C':
		case 'c':
			cpu.i0x91();//A=A-C 10010001.
			break;
		case 'D':
		case 'd':
			cpu.i0x92();//A=A-D 10010010.
			break;
		case 'E':
		case 'e':
			cpu.i0x93();//A=A-E 10010011.
			break;
		case 'H':
		case 'h':
			cpu.i0x94();//A=A-H 10010100.
			break;
		case 'L':
		case 'l':
			cpu.i0x95();//A=A-L 10010101.
			break;
		case 'M';
		case 'm';
			cpu.i0x96();//A=A-mem@H-L 10010110.
			break;
		default:
			break;
		}
	}
	else if (instruction == "SUI") //Subtract immediate data.
		cpu.i0xD6(data1);//A=A-data 11010110
	else if (instruction == "SBB") //subtract register with borrow.
	{
		switch (param1)
		{
		case 'B':
		case 'b':
			cpu.i0x98();//A=A-B with borrow 10011000.
			break;
		case 'C':
		case 'c':
			cpu.i0x99();//A=A-C with borrow 10011001.
			break;
		case 'D':
		case 'd':
			cpu.i0x9A();//A=A-D with borrow 10011010.
			break;
		case 'E':
		case 'e':
			cpu.i0x9B();//A=A-E with borrow 10011011.
			break;
		case 'H':
		case 'h':
			cpu.i0x9C();//A=A-H with borrow 10011100.
			break;
		case 'L':
		case 'l':
			cpu.i0x9D();//A=A-L with borrow 10011101.
			break;
		case 'M':
		case 'm':
			cpu.i0x9E();//A=A-mem@H-L with borrow 10011110.
			break;
		default:
			break;
		}
	}
	else if (instruction == "SBI") //Subtract immediate data with borrow/
		cpu.i0xDE(data1);//A=A-data with borrow 11011110
	else if (instruction == "INR") //increment register.
	{
		switch (param1)
		{
		case 'A':
		case 'a':
			cpu.i0x3C();//A 00111100
			break;
		case 'B':
		case 'b':
			cpu.i0x04();//B 00000100
			break;
		case 'C':
		case 'c':
			cpu.i0x0C();//C 00001100
			break;
		case 'D':
		case 'd':
			cpu.i0x14();//D  00010100
			break;
		case 'E':
		case 'e':
			cpu.i0x1C();//E  00011100
			break;
		case 'H':
		case 'h':
			cpu.i0x24();//H 00100100
			break;
		case 'L':
		case 'l':
			cpu.i0x2C();//L 00101100
			break;
		case 'M':
		case 'm':
			cpu.i0x34;//memory 00110100
		default:
			break;
		}
	}
	else if (instruction == "DCR") //decrement register.
	{
		switch (param1)
		{
		case 'A':
		case 'a':
			cpu.i0x3D();//decriment A 00111101.
			break;
		case 'B':
		case 'b':
			cpu.i0x05();//decriment B 00000101.
			break;
		case 'C':
		case 'c':
			cpu.i0x0D();//decriment C 00001101.
			break;
		case 'D':
		case 'd':
			cpu.i0x15();//decriment D 00010101.
			break;
		case 'E':
		case 'e':
			cpu.i0x1D();//decriment E 00011101.
			break;
		case 'H':
		case 'h':
			cpu.i0x25();//decriment H 00100101.
			break;
		case 'L':
		case 'l':
			cpu.i0x2D();//decriment L 00101101.
			break;
		case 'M':
		case 'm':
			cpu.i0x35();//decriment memory at HL 00110101.
			break;
		default:
			break;
		}
	}
	else if (instruction == "INX") //increment register pair.
	{
		switch (param1)
		{
		case 'B':
		case 'b':
			cpu.i0x03();//incriment B-C 00000011.
			break;
		case 'D':
		case 'd':
			cpu.i0x13();//incriment D-E 00010011.
			break;
		case 'H':
		case 'h':
			cpu.i0x23();//incriment H-L 00100011.
			break;
		default:
			cpu.i0x33();//incriment SP 00110011.
			break;
		}
	}
	else if ( instruction == "DCX") //Decrement register pair.
	{
		switch (param1)
		{
		case 'B':
		case 'b':
			cpu.i0x0B();//decriment B-C 00001011.
			break;
		case 'D':
		case 'd':
			cpu.i0x1B();//decriment D-E 00011011.
			break;
		case 'H':
		case 'h':
			cpu.i0x2B();//decriment H-L 00101011.
			break;
		default:
			cpu.i0x3B();//decriment SP 00111011.
			break;
		}
	}
	else if (instruction == "DAD") //add register pair , H-L
	{
		switch (param1)
		{
		case 'B':
		case 'b':
			cpu.i0x09();
			break;
		case 'D':
		case 'd':
			cpu.i0x19();
			break;
		default:
			break;
		}
	}
	else if (instruction == "DAA") //Decimal adjust accumulator.
		cpu.i0x27();
	//Logical Group.
	else if (instruction == "ANA") //AND register
	{
		switch (param1)
		{
		case 'B'://AND B+A 10100000
		case 'b':
			cpu.i0xA0();
			break;
		case 'C'://AND C+A 10100001
		case 'c':
			cpu.i0xA1();
			break;
		case 'D'://AND D+A 10100010
		case 'd':
			cpu.i0xA2();
			break;
		case 'E'://AND E+A 10100011
		case 'e':
			cpu.i0xA3();
			break;
		case 'H'://AND H+A 10100100
		case 'h':
			cpu.i0xA4();
			break;
		case 'L'://AND L+A 10100101
		case 'l':
			cpu.i0xA5();
			break;
		case 'M'://AND Memory+A 10100110
		case 'm':
			cpu.i0xA6();
			break;
		default:
			break;
		}
	}
	else if (instruction == "ANI") //And immediate
		cpu.i0xE6(data1);//AND 2nd byte and register 11100110
	else if (instruction == "XRA") //XOR register
	{
		switch (param1)
		{
		case 'B':
		case 'b':
			cpu.i0xA8(); //XOR B+A i0xA8
			break;
		case 'C':
		case 'c':
			cpu.i0xA9(); //XOR C+A i0xA9
			break;
		case 'D':
		case 'd':
			cpu.i0xAA(); //XOR D+A i0xAA
			break;
		case 'E':
		case 'e':
			cpu.i0xAB(); //XOR E+A i0xAB
			break;
		case 'H':
		case 'h':
			cpu.i0xAC(); //XOR H+A i0xAC
			break;
		case 'L':
		case 'l':
			cpu.i0xAD(); //XOR L+A i0xAD
			break;
		case 'M':
		case 'm':
			cpu.i0xAE(); //XOR Memory+A i0xAE
			break;
		default:
			break;
		}
	}
	else if (instruction == "XRI") //XOR immediate
		cpu.i0xEE(data1);//XOR 2nd byte+A 11101110
	else if (instruction =="ORA") //OR register
	{
		switch (param1)
		{
		case 'B':
		case 'b':
			cpu.i0xB0(); //OR B+A i0xB0
			break;
		case 'C':
		case 'c':
			cpu.i0xB1(); //OR C+A i0xB1
			break;
		case 'D':
		case 'd':
			cpu.i0xB2(); //OR D+A i0xB2
			break;
		case 'E':
		case 'e':
			cpu.i0xB3(); //OR E+A i0xB3
			break;
		case 'H':
		case 'h':
			cpu.i0xB4(); //OR H+A i0xB4
			break;
		case 'L':
		case 'l':
			cpu.i0xB5(); //OR L+A i0xB5
			break;
		case 'M':
		case 'm':
			cpu.i0xB6(); //OR Memory+A i0xB6
		default:
			break;
		}
	}
	else if (instruction == "ORI") //OR immediate
		cpu.i0xF6(data1); //OR 2nd byte+A 11110110
	else if (instruction == "CMP") //Compare register
	{
		switch (param1)
		{
		case 'B':
		case 'b':
			cpu.i0xB8();//A-B i0xB8
			break;
		case 'C':
		case 'c':
			cpu.i0xB9();//A-C i0xB9
			break;
		case 'D':
		case 'd':
			cpu.i0xBA();//A-D i0xBA
			break;
		case 'E':
		case 'e':
			cpu.i90xBB();//A-E i0xBB
			break;
		case 'H':
		case 'h':
			cpu.i0xBC();//A-H i0xBC
			break;
		case 'L':
		case 'l':
			cpu.i0xBD(); //A-L i0xBD
			break;
		case 'M':
		case 'm':
			cpu.i0xBE(); //A-Memory i0xBE
		default:
			break;
		}
	}
	else if (instruction == "CPI") //compare immediate
		cpu.i0xFE(data); //A-2nd byte 11111110
	else if (instruction == "RLC") //Rotate left
		cpu.i0x07(); //Rotate A left (low order and CY set , high order) i0x07
	else if (instruction == "RRC") //Rotate right
		cpu.i0x0F();//Rotate A right (high order and CY , low order) i0x0F
	else if (instruction == "RAL") //Rotate left through carry
		cpu.i0x17(); //Rotate A left through carry i0x17
	else if (instruction =="RAR") //Rotate right through carry.
		cpu.i0x1F(); //Rotate right through carry i0x1F
	else if (instruction == "CMA") //Complement accumulator
		cpu.i0x2F(); //A complimented i0x2F
	else if (instruction == "CMC") //Complement carry.
		cpu.i0x3F(); // CY flag is complemented i0x3F
	else if (instruction =="STC") //Set Carry
		cpu.i0x37(); //Set CY , 1 i0x37
//Branch Group:
	else if (instruction == "JMP") //Jump
		cpu.i0xC3(data, data2);//11000011.
	else if (instruction =="JNZ") //Jump Not Zero
		cpu.i0xC2();//11000010
	else if (instruction == "JZ") //Jump Zero
		cpu.i0xCA();//11001010
	else if (instruction =="JNC") //Jump No Carry
		cpu.i0xD2();//11010010
	else if (instruction =="JC") //Jump Carry
		cpu.i0xDA();//11011010
	else if (instruction =="JPO") //Jump Parity Odd
		cpu.i0xE2();//11100010
	else if (instruction =="JPE") //Jump Parity Even
		cpu.i0xEA();//11101010
	else if (instruction =="JP") //Jump Plus
		cpu.i0xF2();//11110010
	else if (instruction =="JM") //Jump Minus
		cpu.i0xFA();//11111010
	else if (instruction =="CALL") //Call
		cpu.i0xCD(data1, data2);
	else if (instruction =="CNZ")
		cpu.i0xC4();//11000100
	else if (instruction == "CZ")
		cpu.i0xCC();//11001100
	else if (instruction == "CNC")
		cpu.i0xD4();//11010100
	else if (instruction == "CC")
		cpu.i0xDC();//11011100
	else if (instruction == "CPO")
		cpu.i0xE4();//11100100
	else if (instruction == "CPE")
		cpu.i0xEC();//11101100
	else if (instruction =="CP")
		cpu.i0xF4();//11110100
	else if (instruction =="CM")
		cpu.i0xFC();//11111100
	else if (instruction == "RET")
		cpu.i0xC9();//return
}
