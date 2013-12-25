#include "alu.h"
#include <cstdio>

const unsigned char signAndMask = 0x7f;     //to clear or reset the sign flag
const unsigned char signOrMask = 0x80;      //to set the sign flag
const unsigned char zeroAndMask = 0xbf;     //to clear or reset the zero flag
const unsigned char zeroOrMask = 0x40;      //to set the zero flag
const unsigned char auxcarryAndMask = 0xef; //to clear or reset the aux carry flag
const unsigned char auxcarryOrMask = 0x10;  //to set the aux carry flag
const unsigned char parityAndMask = 0xfb;   //to clear or reset the parity flag
const unsigned char parityOrMask = 0x04;    //to set the parity flag
const unsigned char carryAndMask = 0xfe;    //to clear or reset the carry flag
const unsigned char carryOrMask = 0x01;     //to set the carry flag

ALU::ALU()
{
	 flags = 0x00;
}

ALU::~ALU()
{
}

void ALU::setTempReg(unsigned char tempregister)
{
	 tempreg = tempregister;
}

void ALU::setAccumu(unsigned char accum)
{
	A = accum;
}

void ALU::setInstruction(unsigned char instruction)
{
	instructreg = instruction;
}

unsigned char ALU::getDataBus()
{
	return(databusout);
}

void ALU::setCarryFlag()
{
	flags = flags | carryOrMask;
}

void ALU::resetCarryFlag()
{
	flags = flags & carryAndMask;
}

void ALU::setZeroFlag()
{
        flags = flags | zeroOrMask;
}

void ALU::resetZeroFlag()
{
        flags = flags & zeroAndMask;
}

void ALU::setSignFlag()
{
	flags = flags | signOrMask;
}

void ALU::resetSignFlag()
{
	flags = flags & signAndMask;
}

void ALU::setParityFlag()
{
	flags = flags | parityOrMask;
}

void ALU::resetParityFlag()
{
	flags = flags & parityAndMask;
}

void ALU::setAuxCarryFlag()
{
	flags = flags | auxcarryOrMask;
}

void ALU::resetAuxCarryFlag()
{
	flags = flags & auxcarryAndMask;
}

unsigned char ALU::getAccumulator()
{
	return(A);
}

unsigned char ALU::getFlags()
{
	return(flags);
}

unsigned char ALU::getZeroFlag()
{
	unsigned char flag;
	if(flags & 0x40) flag = 0x01;
	else flag = 0x00;
	return (flag);
}

unsigned char ALU::getCarryFlag()
{
        unsigned char flag;
        if(flags & 0x01) flag = 0x01;
        else flag = 0x00;
        return (flag);

}

unsigned char ALU:: getSignFlag()
{
        unsigned char flag;
        if(flags & 0x80) flag = 0x01;
        else flag = 0x00;
        return (flag);
}

unsigned char ALU::getParityFlag()
{
        unsigned char flag;
        if(flags & 0x04) flag = 0x01;
        else flag = 0x00;
        return (flag);
}

unsigned char ALU::getAuxCarryFlag()
{
        unsigned char flag;
        if(flags & 0x10) flag = 0x01;
        else flag = 0x00;
        return (flag);
}

void ALU::add()
{
	doAddAuxFlag(A,tempreg);
	if (doAddCarryFlag(A, tempreg)) setCarryFlag();
	else resetCarryFlag();
	A = doAdd(A, tempreg);
	doZeroFlag(A);
	doSignFlag(A);
	doParityFlag(A);
}


void ALU::subtract()
{
	unsigned char temp = twosComplement(tempreg);
        doAddAuxFlag(A,temp);
        if (doAddCarryFlag(A, temp)) resetCarryFlag();
        else setCarryFlag();
        A = doAdd(A, temp);
        doZeroFlag(A);
        doSignFlag(A);
        doParityFlag(A); 
}

void ALU::setcarry()
{
	setCarryFlag();
}

void ALU::complementA()
{
	A = ~A;
}

void ALU::complementCarry()
{
	if(getCarryFlag()) resetCarryFlag();
	else setCarryFlag();
}

void ALU::andd()
{  
	A = A & tempreg;
	doSignFlag(A);
	doZeroFlag(A);
	doParityFlag(A);
	resetCarryFlag();
	setAuxCarryFlag();	 
}

void ALU::orr()
{
        A = A | tempreg;
        doSignFlag(A);
        doZeroFlag(A);
        doParityFlag(A);
        resetCarryFlag();
        resetAuxCarryFlag();
}

void ALU::xorr()
{
        A = A ^ tempreg;
        doSignFlag(A);
        doZeroFlag(A);
        doParityFlag(A);
        resetCarryFlag();
        resetAuxCarryFlag();
}

void ALU::decrementSource()
{
	//only applies to A within the ALU  class
        //unsigned char tTempReg = A & 0x0f;
        unsigned char tA = A & 0x0f;
        tA = tA + (~0x01 + 0x01);
        if (tA & 0x10) setAuxCarryFlag();
        else resetAuxCarryFlag();
        A = A + (~0x01 + 0x01);
	doSignFlag(A);
        doZeroFlag(A);
        doParityFlag(A);
}

void ALU::incrementSource()
{
	//only applies to A within the ALU  class
        unsigned char tA = A & 0x0f;
        tA = tA + 0x01;
        if (tA & 0x10) setAuxCarryFlag();
        else resetAuxCarryFlag();
        A = A + 0x01;
        doSignFlag(A);
        doZeroFlag(A);
        doParityFlag(A);
}

void ALU::rotateARight()
{
	unsigned char tA = 0x00;
	if(0x01 & A)
	{
		tA = 0x80;
		setCarryFlag();
	}
	else resetCarryFlag();
	A = A >> 1;
	A = A | tA;
}

void ALU::rotateALeft()
{
        unsigned char tA = 0x00;
        if(0x80 & A)
	{
		tA = 0x01;
		setCarryFlag();
	}
	else resetCarryFlag();
        A = A << 1;
        A = A | tA;
}

void ALU::rotateARightThroughCarry()
{
        unsigned char tA = 0x00;
	if(getCarryFlag()) tA = 0x01;
	if(0x01 & A) 
        {
                setCarryFlag();
        }
        else resetCarryFlag();
        A = A >> 1;
	A = A | tA;
}

void ALU::rotateALeftThroughCarry()
{
        unsigned char tA = 0x00;
	if(getCarryFlag()) tA = 0x01;
        if(0x80 & A)
        {
                setCarryFlag();
        }
        else resetCarryFlag();
        A = A << 1;
	A = A | tA;
}

void ALU::compareWithAccumulator()
{
        unsigned char temp = twosComplement(tempreg);
	unsigned temp2 = A;
        doAddAuxFlag(temp2,temp);
        if (doAddCarryFlag(temp2, temp)) resetCarryFlag();
        else setCarryFlag();
        temp2 = doAdd(temp2, temp);
        doZeroFlag(temp2);
        doSignFlag(temp2);
        doParityFlag(temp2);
}

void ALU::doZeroFlag(unsigned char A)
{
	if(A == 0x00) setZeroFlag();
	else resetZeroFlag();
}

void ALU::doSignFlag(unsigned char A)
{
        if (A & 0x80) setSignFlag();
        else resetSignFlag();
}

void ALU::doParityFlag(unsigned char A)
{
        unsigned char accumParity = 0;
        unsigned char tempAccum = A;
        for (unsigned char i = 0; i <= 7; i++)
        {
                accumParity += (tempAccum & 0x01);
                tempAccum = tempAccum >> 0x01;
	}
        if((accumParity % 2) == 0) setParityFlag();
	else resetParityFlag();
}

void ALU::doAddAuxFlag(unsigned char A, unsigned char B)
{
	A = A & 0x0f;
	B = B & 0x0f;
	//unsigned char sum;
	//unsigned char carry;
	//do
	//{
	//	sum = A ^ B;
	//	carry = A & B;
	//	carry = carry << 1;
	//	A = sum;
	//	B = carry;
	//}
	//while(carry != 0);
	//if(sum & 0x10) setAuxCarryFlag();
	if(doAdd(A, B) & 0x10) setAuxCarryFlag();
	else resetAuxCarryFlag();
}

unsigned char ALU::doAddCarryFlag(unsigned short A, unsigned short B)
{
	unsigned short sum;
	unsigned short carry;
	do
	{
		sum = A ^ B;
		carry = A & B;
		carry = carry << 1;
		A = sum;
		B = carry;
		
	}
	while(carry != 0);
	unsigned char temp;
	if (sum & 0x100) temp = 0x01;
	else temp = 0x00;
	return(temp);
}



unsigned char ALU::twosComplement(unsigned char A)
{
	A = ~A;
	unsigned char B = 1;
	//unsigned char sum;
	//unsigned char carry;
	//do
	//{
	//	sum = A ^ B;
	//	carry = A & B;
	//	carry = carry << 1;
	//	A = sum;
	//	B = carry;
	//}
	//while(carry != 0);
	//return(sum);
	return(doAdd(A, B));
}

unsigned char ALU::doAdd (unsigned char A, unsigned char B)
{
	unsigned char sum;
	unsigned char carry;
	do
	{
		sum = A ^ B;
		carry = A & B;
		carry = carry << 1;
		A = sum;
		B = carry;
	}
	while (carry != 0);
	return(sum);
}

void ALU::doOp()
{
	switch (instructreg)
	{
		case 0x00:	// NOP operation, do nothing
			break;
		case 0x01:	//LXI B, 16-bit
			break;
		case 0x02:	//STX B
			break;
		case 0x03:	//INX B
			break;
		case 0x04:	//INR B
                        break;
		case 0x05:	//DCR B
                        break;
		case 0x06:	//MVI B, 8-Bit
			break;
		case 0x07:	//RLC
			rotateALeft();
			break;
		case 0x0f:	//RRC
			rotateARight();
			break;
		case 0x11:	//LXI B, 16-Bit
			break;
		case 0x17:	//RAL
			rotateALeftThroughCarry();
			break;
		case 0x1f:	//RAR
			rotateARightThroughCarry();
			break;
		case 0x21:	//LXI H, 16-Bit
			break;
		case 0x2f:	//CMA
			complementA();
			break;
		case 0x31:	//LXI SP, 16-Bit
			break;
		case 0x37:	//STC
			setcarry();
			break;
		case 0x3c:
			incrementSource();
			break;
		case 0x3d:	//DCR
			//alu class only affects A
			decrementSource();
			break;
		case 0x3f:
			complementCarry();
			break;
		case 0x40:	//MOV B, B
			break;
                case 0x41:	//MOV B, C
                        break;
                case 0x42:	//MOV B, D
                        break;
                case 0x43:	//MOV B, E
                        break;
                case 0x44:	//MOV B, H
                        break;
                case 0x45:	//MOV B, L
                        break;
                case 0x46:	//MOV B, M
                        break;
                case 0x47:	//MOV B, A
                        break;
                case 0x48:	//MOV C, B
                        break;
                case 0x49:	//MOV C, C
                        break;
                case 0x4a:	//MOV C, D
                        break;
                case 0x4b:	//MOV C, E
                        break;
                case 0x4c:	//MOV C, H
                        break;
                case 0x4d:	//MOV C, L
                        break;
                case 0x4e:	//MOV C, M
                        break;
                case 0x4f:	//MOV C, A
                        break;
		case 0x50:	//MOV D, B
			break;
		case 0x51:	//MOV D, C
			break;
		case 0x52:	//MOV D, D
			break;
		case 0x53:	//MOV D, E
			break;
		case 0x54:	//MOV D, H
			break;
		case 0x55:	//MOV D, L
			break;
		case 0x56:	//MOV D, M
			break;
		case 0x57:	//MOV D, A
			break;
		case 0x58:	//MOV E, B
			break;
		case 0x59:	//MOV E, C
			break;
		case 0x5a:	//MOV E, D
			break;
		case 0x5b:	//MOV E, E
			break;
		case 0x5c:	//MOV E, H
			break;
		case 0x5d:	//MOV E, L
			break;
		case 0x5e:	//MOV E, M
			break;
		case 0x5f:	//MOV E, A
			break;
		case 0x60:	//MOV H, B
			break;
		case 0x61:	//MOV H, C
                        break;
		case 0x62:	//MOV H, D
                        break;
		case 0x63:	//MOV H, E
                        break;
		case 0x64:	//MOV H, H
                        break;
		case 0x65:	//MOV H, L
                        break;
		case 0x66:	//MOV H, M
                        break;
		case 0x67:	//MOV H, A
                        break;
		case 0x68:	//MOV L, B
                        break;
		case 0x69:	//MOV L, C
                        break;
		case 0x6a:	//MOV L, D
                        break;
		case 0x6b:	//MOV L, E
                        break;
		case 0x6c:	//MOV L, H
                        break;
		case 0x6d:	//MOV L, L
                        break;
		case 0x6e:	//MOV L, M
                        break;
		case 0x6f:	//MOV L, A
			break;
		case 0x78:	//MOV A, B
                        break;
                case 0x79:	//MOV A, C
                        break;
                case 0x7a:	//MOV A, D
                        break;
                case 0x7b:	//MOV A, E
                        break;
                case 0x7c:	//MOV A, H
                        break;
                case 0x7d:	//MOV A, L
                        break;
                case 0x7e:	//MOV A, M
                        break;
                case 0x7f:	//MOV A, A
                        break;
		case 0x80:	//ADD B
		case 0x81:	//ADD C
		case 0x82:	//ADD D
		case 0x83:	//ADD E
		case 0x84:	//ADD H
		case 0x85:	//ADD L
		case 0x86:	//ADD M
		case 0x87:	//ADD A
			add();
			break;
		case 0x88:	//ADC B
			break;
		case 0x89:	//ADC C
			break;
		case 0x8a:	//ADC D
			break;
		case 0x8b:	//ADC E
			break;
		case 0x8c:	//ADC H
			break;
		case 0x8d:	//ADC L
			break;
		case 0x8e:	//ADC M
			break;
		case 0x8f:	//ADC A
			break;
		case 0x90:	//SUB B
                case 0x91:	//SUB C 
                case 0x92:      //SUB D
                case 0x93:      //SUB E
                case 0x94:      //SUB H
                case 0x95:      //SUB L
                case 0x96:      //SUB M
                case 0x97:      //SUB A
			subtract();
			break;
		case 0xa0:	//ANA B
		case 0xa1:	//ANA C
		case 0xa2:	//ANA D
		case 0xa3:	//ANA E
		case 0xa4:	//ANA H
		case 0xa5:	//ANA L
		case 0xa6:	//ANA M
		case 0xa7:	//ANA A
			andd();
			break;
		case 0xa8:	//XRA B
		case 0xa9:	//XRA C
		case 0xaa:	//XRA D
		case 0xab:	//XRA E
		case 0xac:	//XRA H
		case 0xad:	//XRA L
		case 0xae:	//XRA M
		case 0xaf:	//XRA A
			xorr();
			break;
		case 0xb0:	//ORA B
		case 0xb1:      //ORA C
		case 0xb2:      //ORA D
		case 0xb3:      //ORA E
		case 0xb4:	//ORA H
		case 0xb5:      //ORA L
		case 0xb6:      //ORA M
		case 0xb7:      //ORA A
			orr();
			break;
		case 0xb8:	//CMP B
		case 0xb9:	//CMP C
		case 0xba:	//CMP D
		case 0xbb:	//CMP E
		case 0xbc:	//CMP H
		case 0xbd:	//CMP L
		case 0xbe:	//CMP M
		case 0xbf:	//CMP A
			compareWithAccumulator();
                        break;
		case 0xc6:	//ADI 8-bit
			add();
			break;
		case 0xcd:	//CALL 16-bit
			break;
		case 0xce:	//ACI 8-bit
			break;
		case 0xd6:	//SUB 8-bit
			subtract();
			break;
		case 0xdc:	//CC 16-bit
			break;
		case 0xe6:	//ANI 8-bit
			andd();
			break;
		case 0xee:
			xorr();
			break;
		case 0xf6:
			orr();
			break;
		case 0xfc:	//CM 16-bit
			break;
		case 0xfe:
			compareWithAccumulator();
			break;
		default:
			printf("Error %x is not an 8085 instruction\n", instructreg);
	}
}
