#ifndef _ALU_H
#define _ALU_H
class ALU
{
	public:
		ALU();
		void setTempReg(unsigned char tempregister);
		void setInstruction(unsigned char instruction);
		void setAccumu(unsigned char accum);
		unsigned char getDataBus();
		void doOp();
		unsigned char getAccumulator();
		unsigned char getFlags();
		unsigned char getZeroFlag();
		unsigned char getCarryFlag();
		unsigned char getSignFlag();
		unsigned char getParityFlag();
		unsigned char getAuxCarryFlag();
		~ALU();
	private:
		unsigned char A;           //accumulator
                unsigned char tempreg;     //temporary register
                unsigned char instructreg; //instruction register
 		unsigned char databusout;  //databus out
		//flags
		//D7 = S
		//D6 = Z
		//D5
		//D4 = AC
		//D3
		//D2 = P
		//D1
		//D0 = CY
		unsigned char flags;           //the flag register
		//functions
		void add();
		void subtract();
		void complementA();
		void complementCarry();
		void andd();
		void orr();
		void xorr();
		void decrementSource();
		void incrementSource();
		void rotateARight();
		void rotateALeft();
		void rotateARightThroughCarry();
		void rotateALeftThroughCarry();
		void compareWithAccumulator();
		void setcarry();
		void setCarryFlag();
		void resetCarryFlag();
		void setZeroFlag();
		void resetZeroFlag();
		void setSignFlag();
		void resetSignFlag();
		void setParityFlag();
		void resetParityFlag();
		void setAuxCarryFlag();
		void resetAuxCarryFlag();
		void doZeroFlag(unsigned char A);
		void doSignFlag(unsigned char A);
		void doParityFlag(unsigned char A);

		void doAddAuxFlag(unsigned char A, unsigned char B);
		unsigned char doAddCarryFlag(unsigned short A, unsigned short B);
		unsigned char twosComplement(unsigned char A);
		unsigned char doAdd(unsigned char A, unsigned char B);
};
#endif
