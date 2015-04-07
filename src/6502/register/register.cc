//The Register Unknown how many there are, believed to be 8?
//What is known: A, X, Y, Stack pointer, Program counter, status
//A = accumulator register.
// X & Y registers are genenral-purpose rgisters, they are called the index registers.
// These registers are ony byte in memory.
//X & Y registers are used like loops for instructions.
//*****************************************************//
//Special registers//
//Stack pointer(SP) - like the name says. lowest address is the top, 
// bottom is the highest address, adding decreases the pointer. Always keeps track. All memory addresses are two byte long but stack pointer isn't since all start with 01. Supports a 256 byte stack located between $0100 and $01FF.
//REG::SP
//{
 //whatever this thing does..
//}
//***Program Counter Reigster*****//
//(Two-byte)!!! register hat tells the computer what to do next.
//Jump instructions - used to direct memory location, changes the value of the PC to the next instructions. 
//Can also be modified by branch, subroutine call, or return from SR/interrupt.
//REG::PC
//{
 //Whatever this thing does?
//}

//***STATUS register****//
//treated as 8 separarte bits.(one byte) Seven bits are used as flags or indicators. 
// 0 is off and 1 is on or set for that flag. 
//-----data movement or opeations flags-----//
// zero flag - shows whether the result is zero.
// sign flag - results negative flags reflects the 8th bit of the result.
//----- indicate something about the result of an operations.///
// carry flag -shows whether an airthmetic operation needed to carray or borrow outside of the result bye.
// overflow flag - reflects the seventh bit of the result.(like the sign flag)
//------ flags used in processing interrupts-----////
//interrupt disable flag- tells the microporcessor whether it's all righ to process an interrupt immediately.
// break flag - shows whether an interrupt is caus3ed by an external event or by progam command.
//!!!!final flag!!!!!!///
//decimal flag - tells the microprocessor whether it is doing binary or decimal arithmetic.
//REG::STATUS
//{
 //flags here?
//}
#include "r6502.h"
 
reg6502::reg6502()
{
	for (int x = 0; x < 8; x++)
		this -> reset();
}

void reg6502::clear()
{
	for (int x = 0; x < 8; x++)
		this -> reset();
}
//void reg6502::reset(char flags)
//{
// this -> myandgate.set(flags);
//}
//void reg6502::set(char flags)
//{
//  this -> mynorgate.seta(flags);
//}


