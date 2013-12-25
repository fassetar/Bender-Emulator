#include "and.h"
#include "g8sr.h"
#include "register.h"
#include "not.h"
#include "alu.h"

REG::REG()
{
	for (int i=0; i<7; i++)
		rgstr[i].reset();
}

int REG::regConv(char regNam)
{
	switch (regNam)
	{
	case 'a':
	case 'A':
		return(0);
	case 'b':
	case 'B':
		return(1);
	case 'c':
	case 'C':
		return(2);
	case 'd':
	case 'D':
		return(3);
	case 'e':
	case 'E':
		return(4);
	case 'h':
	case 'H':
		return(5);
	case 'l':
	case 'L':
		return(6);
	default:
/*Debugging error code.*/ cout << endl << "Illegal Register Name:" << regNam << " Defaulting to accumulator!";
		return(0);
	}
}

void REG::clear()
{
	for (int i=0; i<7; i++)
	{
		rgstr[i].reset();
	}
}

void REG::clear(char regX)
{
	AND ferANDing;
	int regNum;
	bool hold;
	const bool ANDIN=false;
	regNum=regConv(regX);
	for (int i=1; i<=8; i++)
	{
		ferANDing.set(rgstr[regNum].getQ(i), ANDIN);
		hold=ferANDing.get();
		rgstr[regNum].set(hold, i);
	}
	rgstr[regNum].clockTick();	
}

void REG::clear(char regX, char regY)
{
	AND forANDing;
	int regNum;
	bool hold;
	const bool ANDIN=false;
	regNum=regConv(regX);
	for (int i=1; i<=8; i++)
	{
		forANDing.set(rgstr[regNum].getQ(i), ANDIN);
		hold=forANDing.get();
		rgstr[regNum].set(hold, i);
	}
	rgstr[regNum].clockTick();
	regNum=regConv(regY);
	for (int i=1; i<=8; i++)
	{
		forANDing.set(rgstr[regNum].getQ(i), ANDIN);
		hold=forANDing.get();
		rgstr[regNum].set(hold, i);
	}
	rgstr[regNum].clockTick();
}

void REG::set(char regZ, G8SR in)
{
	int regNum;
	regNum=regConv(regZ);
	rgstr[regNum]=in;
}

void REG::set(char reg1, G8SR in1, char reg2, G8SR in2)
{
	int regNum;
	regNum=regConv(reg1);
	rgstr[regNum]=in1;
	regNum=regConv(reg2);
	rgstr[regNum]=in2;
}

G8SR REG::get(char regO)
{
	int regNum;
	regNum=regConv(regO);
return (rgstr[regNum]);
}

void REG::get(char reg1, G8SR& out1, char reg2, G8SR& out2)
{
	int regNum;
	regNum=regConv(reg1);
	out1=rgstr[regNum];
	regNum=regConv(reg2);
	out2=rgstr[regNum];
}

bool REG::shift(char reg, bool bit)
{
	//Bit 8 output, bit 1 through 7 shift right Bit 1=bit.
	int regNum;
	bool tmpHold, out;
	regNum=regConv(reg);
	out=rgstr[regNum].getQ(8);
	for (int i=7; i>=1; i--)
	{
		tmpHold=rgstr[regNum].getQ(i);
		rgstr[regNum].set(tmpHold, (i+1));
	}
	rgstr[regNum].set(bit, 1);
	rgstr[regNum].clockTick();
return(out);
}

bool REG::rotate(char reg, bool bit)
{
	//Bit 1 output, bit 8 through 2 shift right, Bit 8=bit
	int regNum;
	bool tmpHold, out;
	regNum=regConv(reg);
	out=rgstr[regNum].getQ(1);
	for (int i=2; i<=8; i++)
	{
		tmpHold=rgstr[regNum].getQ(i);
		rgstr[regNum].set(tmpHold, (i-1));
	}
	rgstr[regNum].set(bit, 8);
	rgstr[regNum].clockTick();
return(out);
}

void REG::negate(char reg)
{
	NOT neg;
	int regNum;
	bool tmpHold;
	regNum=regConv(reg);
	for (int i=1; i<=8; i++)
	{
		tmpHold=rgstr[regNum].getQ(i);
		neg.set(tmpHold);
		tmpHold=neg.get();
		rgstr[regNum].set(tmpHold, i);
	}
	rgstr[regNum].clockTick();
}

void REG::move(char r1, char r2)
{
	int regNum1, regNum2;
	bool hold;
	regNum2=regConv(r1);
	regNum1=regConv(r2);
	for (int i=1; i<=8; i++)
	{
		hold=rgstr[regNum1].getQ(i);
		rgstr[regNum2].set(hold, i);
	}
	rgstr[regNum2].clockTick();
}

//<<<<<<< .mine
void REG::ANAR(char r1) 
{
	int regX;
	regX=regConv(r1);
	for (int i = 1; i <= 8; i++) 
	{
	        if ((rgstr[regX].getQ(i) == true) && (rgstr[0].getQ(i) == true)) 
			rgstr[0].set(true, i);	        
		else rgstr[0].set(false, i);
	}
}
//=======

void REG::ANAM()
{  
	G8SR hL; 
	
	hL = memory.getMem(rgstr[6] & rgstr[7]);  
        
	for (int i = 1; i <= 8; i++) 
	    { 
	     hL.getQ(i) & rgstr[0].getQ(i); 
	     rgstr[0].set; 
	    } 

}


void REG::ANI() 
{
 


}

void REG::XRAr(char r1) 
{ 	
	int regX;

	for (int i = 1; i <= 8; i++) 
	     rgstr[0].set(i, (rgstr[regX].getQ(i) ^ rgstr[0].getQ(i))); 
}

void REG::XRAm() 
{
	G8SR hL; 

	hl = memory.getMem(rgstr[6] & rgstr[7]); 

	for (int i = 1; i <= 8; i++) 
	    {
	     hl.getQ(i) ^ rgstr[0].getQ(i);
	     rgstr[0].set;
	    } 
} 











void REG::move(char r1, G8SR mo)
{
	int reg;
	reg=regConv(r1);
	rgstr[reg]=mo;
}

void REG::move(char dest, G8SR mAdd1, G8SR mAdd2)
{
	int ddd;
	ddd=regConv(dest);
	rgstr[ddd]=memory.getMem(mAdd1, mAdd2);
}

void REG::move(G8SR madd1, G8SR madd2, char source)
{
	int sss;
	sss=regConv(source);
	memory.putMem(madd1, madd2, rgstr[sss]);
}

void REG::moveL(char ddd, char high, char low)
{
	int reg, hi, lo;
	reg=regConv(ddd);
	hi=regConv(high);
	lo=regConv(low);
	rgstr[reg]=memory.getMem(rgstr[hi], rgstr[lo]);
}

void REG::moveS(char rIn, char h, char l)
{
	int reg, hi, lo;
	reg=regConv(rIn);
	hi=regConv(h);
	lo=regConv(l);
	memory.putMem(rgstr[hi], rgstr[lo], rgstr[reg]);
}

void REG::move(G8SR data)
{
	int regH, regL;
	regH=regConv('H');
	regL=regConv('L');
	memory.putMem(rgstr[regH], rgstr[regL], data);
}

void REG::move(char r1h, char r2h, char r1l, char r2l)
{
	G8SR temp1, temp2;
	int rh1, rh2, rl1, rl2;
	rl1=regConv(r1l);
	rl2=regConv(r2l);
	rh1=regConv(r1h);
	rh2=regConv(r2h);
	temp1=rgstr[rh2];
	temp2=rgstr[rl2];
	move(r1h, r2h);
	move(r1l, r2l);
	rgstr[rh1]=temp1;
	rgstr[rl1]=temp2;
}
	
//public finctions, hex instructions.
//MOV r1, r2
void REG::i0x47()//A to B
{
	char r1='A';
	char r2='B';
	move (r1, r2);
}

void REG::i0x4F()//A to C
{
	char r1='A';
	char r2='C';
	move(r1, r2);
}

void REG::i0x57()//A to D
{
	char r1='A';
	char r2='D';
	move(r1, r2);
}

void REG::i0x5F()//A to E
{
	char r1='A';
	char r2='E';
	move(r1, r2);
}

void REG::i0x67()//A to H
{
	char r1='A';
	char r2='H';
	move(r1, r2);
}

void REG::i0x6F()//A to L
{
	char r1='A';
	char r2='L';
	move(r1, r2);
}

void REG::i0x78()//B to A
{
	char r1='B';
	char r2='A';
	move(r1, r2);
}

void REG::i0x48()//B to C
{
	char r1='B';
	char r2='C';
	move(r1, r2);
}

void REG::i0x50()//B-D
{
	char r1='B';
	char r2='E';
	move(r1, r2);
}

void REG::i0x58()//B-E
{
	char r1='B';
	char r2='E';
	move(r1, r2);
}

void REG::i0x60()//B-H
{
	char r1='B';
	char r2='H';
	move(r1, r2);
}

void REG::i0x68()//B-L
{
	char r1='B';
	char r2='L';
	move(r1, r2);
}

void REG::i0x79()//C-A
        {
	char r1='C';
	char r2='A';
	move(r1, r2);
}

void REG::i0x41()//C-B
{
	char r1='C';
	char r2='B';
	move(r1, r2);
}

void REG::i0x51()//C-D
{
	char r1='C';
	char r2='D';
	move(r1, r2);
}

void REG::i0x59()//C-E
{
	char r1='C';
	char r2='E';
	move(r1, r2);
}

void REG::i0x61()//C-H
{
	char r1='C';
	char r2='H';
	move(r1, r2);
}

void REG::i0x69()//C-L
{
	char r1='C';
	char r2='L';
	move(r1, r2);
}

void REG::i0x7A()//D-A
{
	char r1='D';
	char r2='A';
	move(r1, r2);
}

void REG::i0x42()//D-B
{
	char r1='D';
	char r2='B';
	move(r1, r2);
}

void REG::i0x4A()//D-C
{
	char r1='D';
	char r2='C';
	move(r1, r2);
}

void REG::i0x5A()//D-E
{
	char r1='D';
	char r2='E';
	move(r1, r2);
}

void REG::i0x62()//D-H
{
	char r1='D';
	char r2='H';
	move(r1, r2);
}

void REG::i0x6A()//D-L
{
	char r1='D';
	char r2='L';
	move(r1, r2);
}

void REG::i0x7B()//E-A
{
	char r1='E';
	char r2='A';
	move(r1, r2);
}

void REG::i0x43()//E-B
{
	char r1='E';
	char r2='B';
	move(r1, r2);
}

void REG::i0x4B()//E-C
{
	char r1='E';
	char r2='C';
	move(r1, r2);
}

void REG::i0x53()//E-D
{
	char r1='E';
	char r2='D';
	move(r1, r2);
}

void REG::i0x63()//E-H
{
	char r1='E';
	char r2='H';
	move(r1, r2);
}

void REG::i0x6B()//E-L
{
	char r1='E';
	char r2='L';
	move(r1, r2);
}

void REG::i0x7C()//H-A
{
	char r1='H';
	char r2='A';
	move(r1, r2);
}

void REG::i0x44()//H-B
{
	char r1='H';
	char r2='B';
	move(r1, r2);
}

void REG::i0x4C()//H-C
{
	char r1='H';
	char r2='C';
	move(r1, r2);
}

void REG::i0x54()//H-D
{
	char r1='H';
	char r2='D';
	move(r1, r2);
}

void REG::i0x5C()//H-E
{
	char r1='H';
	char r2='E';
	move(r1, r2);
}

void REG::i0x6C()//H-L
{
	char r1='H';
	char r2='L';
	move(r1, r2);
}

void REG::i0x7D()//L-A
{
	char r1='L';
	char r2='A';
	move(r1, r2);
}

void REG::i0x45()//L-B
{
	char r1='L';
	char r2='B';
	move(r1, r2);
}

void REG::i0x4D()//L-C
{
	char r1='L';
	char r2='C';
	move(r1, r2);
}

void REG::i0x55()//L-D
{
	char r1='L';
	char r2='D';
	move(r1, r2);
}

void REG::i0x5D()//L-E
{
	char r1='L';
	char r2='E';
	move(r1, r2);
}

void REG::i0x65()//L-H
{
	char r1='L';
	char r2='H';
	move(r1, r2);
}

//MOV r, M
void REG::i0x7E()
{
	char r1='A';
	G8SR memoryLoc, add1, add2;
	add1=get('H');
	add2=get('L');
	memoryLoc=memory.getMem(add1, add2);
	move(r1, memoryLoc);
}

void REG::i0x46()
{
                 char r1='B';
                 G8SR memoryLoc, add1, add2;
                 add1=get('H');
                 add2=get('L');
                 memoryLoc=memory.getMem(add1, add2);
                 move(r1, memoryLoc);
}

void REG::i0x4E()
{
                 char r1='C';
                 G8SR memoryLoc, add1, add2;
                 add1=get('H');
                 add2=get('L');
                 memoryLoc=memory.getMem(add1, add2);
                 move(r1, memoryLoc);
}

void REG::i0x56()
{
                 char r1='C';
                 G8SR memoryLoc, add1, add2;
                 add1=get('H');
                 add2=get('L');
                 memoryLoc=memory.getMem(add1, add2);
                 move(r1, memoryLoc);
}

void REG::i0x5E()
{
     char r1='D';
     G8SR memoryLoc, add1, add2;
     add1=get('H');
     add2=get('L');
     memoryLoc=memory.getMem(add1, add2);
     move(r1, memoryLoc);
}

//MOV M, r
void REG::i0x77()
{
	char r='A';
	char hig='H';
	char low='L';
	moveL(r, hig, low);
}

void REG::i0x70()
{
	char r='B';
	char hig='H';
	char low='L';
	moveL(r, hig, low);
}

void REG::i0x71()
{
	char r='C';
	char hig='H';
	char low='L';
	moveL(r, hig, low);
}

void REG::i0x72()
{
	char r='D';
	char hig='H';
	char low='L';
	moveL(r, hig, low);
}

void REG::i0x73()
{
	char r='E';
	char hig='H';
	char low='L';
	moveL(r, hig, low);
}

//MVI r, data
void REG::i0x3E(G8SR data)
{
	char reg='A';
	move(reg, data);
}

void REG::i0x06(G8SR data)
{
	char reg='B';
	move(reg, data);
}

void REG::i0xE0(G8SR data)
{
	char reg='C';
	move(reg, data);
}

void REG::i0x16(G8SR data)
{
	char reg='D';
	move(reg, data);
}

void REG::i0x1E(G8SR data)
{
	char reg='E';
	move(reg, data);
}

void REG::i0x26(G8SR data)
{
	char reg='H';
	move(reg, data);
}

void REG::i0x2E(G8SR data)
{
	char reg='L';
	move(reg, data);
}

//MVI M, data
void REG::i0x36(G8SR data)
{
	move(data);
}
//LXI rp, data
void REG::i0x01(G8SR dataHi, G8SR dataLo)
{
	char hi='B';
	char lo='C';
	move(hi, dataHi);
	move(lo, dataLo);
}

void REG::i0x11(G8SR dataHi, G8SR dataLo)
{
	char hi='D';
	char lo='E';
	move(hi, dataHi);
	move(lo, dataLo);
}

void REG::i0x21(G8SR dataHi, G8SR dataLo)
{
	char hi='H';
	char lo='L';
	move(hi, dataHi);
	move(lo, dataLo);
}
//LDA addr
void REG::i0x3A(G8SR add1, G8SR add2)
{
	char accum='A';
	move(accum, add1, add2);
}
//STA addr
void REG::i0x32(G8SR add1, G8SR add2)
{
	char accum='A';
	move(add1, add2, accum);
	
}
//LHLD addr
void REG::i0x2A(G8SR add1, G8SR add2)
{
	char low='L';
	char high='H';
	move(low, add1, add2);
//	add2=add2+1;//This needs to be changed. add2 needs to be incremented 1 HERE.
	move(high, add1, add2);

}
//SHLD addr
void REG::i0x22(G8SR add1, G8SR add2)
{
	char low='L';
	char high='H';
	move(add1, add2, low);
//	add2=add2+1;//This needs to be changed.  add2 needs to be incrimented 1 HERE.
	move(add1, add2, high);
}
//LDAX rp
void REG::i0x0A()//Loc:B-C to A
{
	char accum='A';
	char one='B';
	char two='C';
	moveL(accum, one, two);
}

void REG::i0x1A()//Loc:D-E to A
{
	char accum='A';
	char one='D';
	char two='E';
	moveL(accum, one, two);
}

//STAX rp
void REG::i0x02()//A to Loc:B-C
{
	char accum='A';
	char one='B';
	char two='C';
	moveS(accum, one, two);
}

void REG::i0x12()//A to Loc:D-E
{
	char accum='A';
	char one='D';
	char two='E';
	moveS(accum, one, two);
}

//XCHG
void REG::i0xEB()
{
	char rp1h='H';
	char rp1l='L';
	char rp2h='D';
	char rp2l='E';
	move(rp1h, rp2h, rp1l, rp2l);
}	
// Arithmetic Group of Instructions goes here...
void REG::i0x80()//A=A+B
{
}

void REG::i0x81()//A=A+C
{
}

void REG::i0x82()//A=A+D
{
}

void REG::i0x83()//A=A+E
{
}

void REG::i0x84()//A=A+H
{
}

void REG::i0x85()//A=A+L
{
}

void REG::i0x86()//A=A+M
{
}

void REG::i0xA6(G8SR data)//A=A+data
{
}

void REG::i0x88()//A=A+B CY
{
}

void REG::i0x89()//A=A+C CY
{
}

void REG::i0x8A()//A=A+D CY
{
}

void REG::i0x8B()//A=A+E CY
{
}

void REG::i0x8C()//A=A+H CY
{
}

void REG::i0x8D()//A=A+L CY
{
}

void REG::i0x8E()//A=A+M CY
{
}

void REG::i0xCE(G8SR data)//A=A+data CY
{
}

void REG::i0x90()//A=A-B
{
}

void REG::i0x91()//A=A-C
{
}

void REG::i0x92()//A=A-D
{
}

void REG::i0x93()//A=A-E
{
}

void REG::i0x94()//A=A-H
{
}

void REG::i0x95()//A=A-L
{
}

void REG::i0x96()//A=A-M
{
}

void REG::i0xD6(G8SR data)//A=A-data
{
}

void REG::i0x98()//A=A-B Borrow
{
}

void REG::i0x99()//A=A-C Borrow
{
}

void REG::i0x9A()//A=A-D Borrow
{
}

void REG::i0x9B()//A=A-E Borrow
{
}

void REG::i0x9C()//A=A-H Borrow
{
}

void REG::i0x9D()//A=A-L Borrow
{
}

void REG::i0x9E()//A=A-M Borrow
{
}

void REG::i0xDE(G8SR data)//A=A-data Borrow
{
}

void REG::i0x3C()//incriment A
{
}

void REG::i0x04()//incriment B
{
}

void REG::i0x0C()//incriment C
{
}

void REG::i0x14()//incriment D
{
}

void REG::i0x1C()//incriment E
{
}

void REG::i0x24()//incriment H
{
}

void REG::i0x2C()//incriment L
{
}

void REG::i0x34()//incriment M
{
}

void REG::i0x3D()//decriment A
{
}

void REG::i0x05()//decriment B
{
}

void REG::i0x0D()//decriment C
{
}

void REG::i0x15()//decriment D
{
}

void REG::i0x1D()//decriment E
{
}

void REG::i0x25()//decriment H
{
}

void REG::i0x2D()//decriment L
{
}

void REG::i0x35()//decriment M
{
}

void REG::i0x03()//incriment B-C pair
{
}

void REG::i0x13()//incriment D-E pair
{
}

void REG::i0x23()//incriment H-L pair
{
}

void REG::i0x33()//incriment SP
{
}

void REG::i0x0B()//decriment B-C pair
{
}

void REG::i0x1B()//decriemtn D-E pair
{
}

void REG::i0x2B()//decriment H-L pair
{
}

void REG::i0x3B()//decriment SP
{
}

void REG::i0x09()//B-C + H-L
{
}

void REG::i0x19()//D-E + H-L
{
}

void REG::i0x27()//decimal adjust A
{
}

// Logical Group instructions go here...
void REG::i0xA0()//A AND B
{
}

void REG::i0xA1()//A AND C
{
}

void REG::i0xA2()//A AND D
{
}

void REG::i0xA3()//A AND E
{
}

void REG::i0xA4()//A AND H
{
}

void REG::i0xA5()//A AND L
{
}

void REG::i0xA6()//A AND M
{
}

void REG::i0xE6(G8SR data)//A AND data
{
}

void REG::i0xA8()//A XOR B
{
}

void REG::i0xA9()//A XOR C
{
}

void REG::i0xAA()//A XOR D
{
}

void REG::i0xAB()//A XOR E
{
}

void REG::i0xAC()//A XOR H
{
}

void REG::i0xAD()//A XOR L
{
}

void REG::i0xAE()//A XOR M
{
}

void REG::i0xEE(G8SR data)//A XOR data
{
}

void REG::i0xB0()//A OR B
{
}

void REG::i0xB1()//A OR C
{
}

void REG::i0xB2()//A OR D
{
}

void REG::i0xB3()//A OR E
{
}

void REG::i0xB4()//A OR H
{
}

void REG::i0xB5()//A OR L
{
}

void REG::i0xB6()//A OR M
{
}

void REG::i0xF6(G8SR data)//A OR data
{
}

void REG::i0xB8()//compare A B
{
}

void REG::i0xB9()//compare A C
{
}

void REG::i0xBA()//compare A D
{
}

void REG::i0xBB()//comapre A E
{
}

void REG::i0xBC()//compare A H
{
}

void REG::i0xBD()//compare A L
{
}

void REG::i0xBE()//comapre A M
{
}

void REG::i0xFE(G8SR data)//compare A data
{
}

void REG::i0x07()//Rotate A left
{
}

void REG::i0x0F()//Rotate A right
{
}

void REG::i0x17()//Rotate A left CY
{
}

void REG::i0x1F()//Rotate A right CY
{
}

void REG::i0x2F()//compliment A
{
}

void REG::i0x3F()//compliment CY
{
}

void REG::i0x37()//set CY
{
}

/* Branch group instructions go here...
*/
/* Stack, I/O and Machine Control Group instructions go here...
*/

