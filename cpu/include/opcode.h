#ifndef _OPCODE_H
#define _OPCODE_H
//*****NOTES_6502_opcode****//
/*-For following instruction hex codes there is no info.
/LO-BYTE 0x03, 0x07 0x0F ***/
//HI-BYTE  
#include "r6502.h"
void ins0x00();
void ins0x01();
void ins0x02();
void ins0x03();
void ins0x04();
void ins0x05();
void ins0x06();
void ins0x07();
void ins0x08();
void ins0x09();
void ins0x0A();
void ins0x0B();
void ins0x0C();
void ins0x0D();
void ins0x0E();
void ins0x0F();
void ins0x10();
void ins0x11();
void ins0x12();
void ins0x13();
void ins0x14();
void ins0x15();
void ins0x16();
void ins0x17();
void ins0x18();
void ins0x19();
void ins0x1A();
void ins0x1B();
void ins0x1C();
void ins0x1D();
void ins0x1E();
void ins0x1F();
void ins0x20();
void ins0x21();
void ins0x22();
void ins0x23();
void ins0x24();
void ins0x25();
void ins0x26();
void ins0x27();
void ins0x28();
void ins0x29();
void ins0x2A();
void ins0x2B();
void ins0x2C();
void ins0x2D();
void ins0x2E();
void ins0x2F();
void ins0x30();
void ins0x31();
void ins0x32();
void ins0x33();
void ins0x34();
void ins0x35();
void ins0x36();
void ins0x37();
void ins0x38();
void ins0x39();
void ins0x3A();
void ins0x3B();
void ins0x3C();
void ins0x3D();
void ins0x3E();
void ins0x3F();
void ins0x40();
void ins0x41();
void ins0x42();
void ins0x43();
void ins0x44();
void ins0x45();
void ins0x46();
void ins0x47();
void ins0x48();
void ins0x49();
void ins0x4A();
void ins0x4B();
void ins0x4C();
void ins0x4D();
void ins0x4E();
void ins0x4F();
void ins0x50();
void ins0x51();
void ins0x52();
void ins0x53();
void ins0x54();
void ins0x55();
void ins0x56();
void ins0x57();
void ins0x58();
void ins0x59();
void ins0x5A();
void ins0x5B();
void ins0x5C();
void ins0x5D();
void ins0x5E();
void ins0x5F();
void ins0x60();
void ins0x61();
void ins0x62();
void ins0x63();
void ins0x64();
void ins0x65();
void ins0x66();
void ins0x67();
void ins0x68();
void ins0x69();
void ins0x6A();
void ins0x6B();
void ins0x6C();
void ins0x6D();
void ins0x6E();
void ins0x6F();
void ins0x70();
void ins0x71();
void ins0x72();
void ins0x73();
void ins0x74();
void ins0x75();
void ins0x76();
void ins0x77();
void ins0x78();
void ins0x79();
void ins0x7A();
void ins0x7B();
void ins0x7C();
void ins0x7D();
void ins0x7E();
void ins0x7F();
void ins0x80();
void ins0x81();
void ins0x82();
void ins0x83();
void ins0x84();
void ins0x85();
void ins0x86();
void ins0x87();
void ins0x88();
void ins0x89();
void ins0x8A();
void ins0x8B();
void ins0x8C();
void ins0x8D();
void ins0x8E();
void ins0x8F();
void ins0x90();
void ins0x91();
void ins0x92();
void ins0x93();
void ins0x94();
void ins0x95();
void ins0x96();
void ins0x97();
void ins0x98();
void ins0x99();
void ins0x9A();
void ins0x9B();
void ins0x9C();
void ins0x9D();
void ins0x9E();
void ins0x9F();
void ins0xA0();
void ins0xA1();
void ins0xA2();
void ins0xA3();
void ins0xA4();
void ins0xA5();
void ins0xA6();
void ins0xA7();
void ins0xA8();
void ins0xA9();
void ins0xAA();
void ins0xAB();
void ins0xAC();
void ins0xAD();
void ins0xAE();
void ins0xAF();
//ADC /.... add with carry 
//AND //.... and (with accumulator) 
//ASL //.... arithmetic shift left 
//BCC //.... branch on carry clear 
//BCS //.... branch on carry set 
//BEQ //.... branch on equal (zero set) 
//BIT //.... bit test 
//BMI //.... branch on minus (negative set) 
//BNE //.... branch on not equal (zero clear) 
//BPL //.... branch on plus (negative clear) 
//BRK //.... interrupt 
//BVC //.... branch on overflow clear 
//BVS //.... branch on overflow set 
//CLC //.... clear carry 
//CLD //.... clear decimal 
//CLI //.... clear interrupt disable 
//CLV //.... clear overflow 
//CMP //.... compare (with accumulator) 
//CPX //.... compare with X 
//CPY //.... compare with Y 
//DEC //.... decrement 
//DEX //.... decrement X 
//DEY //.... decrement Y 
//EOR //.... exclusive or (with accumulator) 
//INC //.... increment 
//INX //.... increment X 
//INY //.... increment Y 
//JMP //.... jump 
//JSR //.... jump subroutine 
//LDA //.... load accumulator 
//LDY //.... load X 
//LDY //.... load Y 
//LSR //.... logical shift right 
//NOP //.... no operation 
//ORA //.... or with accumulator 
//PHA //.... push accumulator 
//PHP //.... push processor status (SR) 
//PLA //.... pull accumulator 
//PLP //.... pull processor status (SR) 
//ROL //.... rotate left 
//ROR //.... rotate right 
//RTI //.... return from interrupt 
//RTS //.... return from subroutine 
//SBC //.... subtract with carry 
//SEC //.... set carry 
//SED //.... set decimal 
//SEI //.... set interrupt disable 
//STA //.... store accumulator 
//STX //.... store X 
//STY //.... store Y 
//TAX //.... transfer accumulator to X 
//TAY //.... transfer accumulator to Y 
//TSX //.... transfer stack pointer to X 
//TXA //.... transfer X to accumulator 
//TXS //.... transfer X to stack pointer 
//TYA //.... transfer Y to accumulator 
#endif
