#include "r6502.h"
#include<cstdio>
#include"fadder.h"
#include "opcode.h"
#include "g8sr.h"
// STATUS register flags
#define NEGATIVE	8
#define OVERFLOW	7
#define RESERVED	6
#define BREAK		5
#define DECIMAL		4
#define INTERRUPT	3
#define	ZERO		2
#define CARRY		1
reg6502 accum; //accumulator
reg6502 prgcnt; //program counter
reg6502 status; // status register
reg6502 indexx; //index x
reg6502 indexy; //index y
reg6502 stack; // stack register
int main()
{
	unsigned int instruction;
	printf("Enter a hex instruction: ");
	scanf("%hx", &instruction);

	switch(instruction)
	{
		case 0x18:
			ins0x18();
			break;

		case 0x29://AND - And with Accumulator - Flags Affected: N Z
		{
			ins0x29(); //A, status, immd
		}
			break;

		case 0x38://SEC - Set Carry
			status.set(true,CARRY);
			break;
		
		case 0x58://CLI - CLear Interrupt
			status.set(false,INTERRUPT);
			break;
		
		case 0x61://ADC (with Carry): Indirect, X -- Flags: N V Z C
			break;
		
		case 0x65://ADC (with Carry): Zero page
			break;
			
		case 0x69://ADC (with Carry): Immediate
			/*bool tmp = false;
			bool Asign = A.getQ(NEGATIVE);
			reg6502 value;
			int carry;

			for (int x = 0; x < 8; x++)
			{
				adder.set(A.getQ(x), value.getQ(x), carry);
				A.set(adder.getSum());
				carry = adder.getCarryOut();
				tmp = tmp | A.getQ(x);
			}

			if (tmp == true)
				status.set(false, ZERO);
			else
				status.set(true, ZERO);

			if (A.getQ(NEGATIVE) == true)
				status.set(true, NEGATIVE);
			else
				status.set(false, NEGATIVE);

			if (carry == true)
				status.set(true, CARRY);
			else
				status.set(false, CARRY);

			if (Asign == true && value.getQ(NEGATIVE) == true)
			{
				if (A.getQ(NEGATIVE) == true)
					status.set(false, OVERFLOW);
			}
			else if (Asign == false && value.getQ(NEGATIVE) == false)
			{
				if (A.getQ(NEGATIVE) == false)
					status.set(false, OVERFLOW);
			}
			else
				status.set(true, OVERFLOW);*/
			//ins0x69(); //A, status
			
			break;
		
		case 0x6D://ADC (with Carry): Absolute
		/*{
			reg6502 address;
			bool tmp = false;
			bool Asign = A.getQ(NEGATIVE);
			int carry;
		}*/
			break;
		
		case 0x71://ADC (with Carry): Indirect, Y
			break;
		
		case 0x75://ADC (with Carry): Zero page, X
			break;

		case 0x78://SEI (SEtInterrupt)
			status.set(true, INTERRUPT);

			break;

		case 0x79://ADC (with Carry): Absolute, Y
			break;
		
		case 0x7D://ADC (with Carry): Absolute, X
			break;	

		case 0xAA://TAX - Transfer A to X -- flags N, Z
		{
			bool tmp = false;
			for(int i=1; i<=8; i++)
			{
				indexx.set(accum.getQ(i), i);
				tmp = tmp | accum.getQ(i);
			}

			/* An obvious question one may have with TAX is- since I'm
			 * transferring A TO X, and A remains the same, why do I need
			 * to do status reg updates? This appears to be one of those
			 * "freebies" where by issuing this instruction you cause the
			 * CPU to check the accumulator, which can have a variety of
			 * uses in code.
			 */
			if (accum.getQ(NEGATIVE) == true)
				status.set(true,NEGATIVE);
			else
				status.set(false,NEGATIVE);

			/* Also, be sure our perspective on status register logic is
			 * correct. If I haven't made a mistake, the ZERO bit is set
			 * WHEN the accumulator IS ZERO. So if the Accumulator is 
			 * filled with false values, the ZERO bit is TRUE. Get it?
			 * Sort of backwards, but sometimes things work like this.
			 */
			if (tmp == true) // Accumulator is NOT zero, clear Z
				status.set(false,ZERO);
			else // Accumulator IS zero, set Z
				status.set(true,ZERO);
		}
			break;
			
		case 0xB8://CLV (CLear oVerflow)
			status.set(false,OVERFLOW);
				
			break;
			
		case 0xD8://CLD (CLear Decimal)
			status.set(false, DECIMAL);
				
			break;				

		case 0xF8://SED (SEt Decimal)
			status.set(true, DECIMAL);

			break;
	}

//ADC //.... add with carry 
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
//Logical Group.
	return(0);
}
