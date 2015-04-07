CXX = g++ $(CXXFLAGS) $(INC) $(LIBS)
AR = ar
CXXFLAGS = -Wall
INC = -I ../../include 
LIBS = 
SRC = ADC.cc AND.cc ASL.cc BCC.cc BCS.cc BEQ.cc BIT.cc BMI.cc BNE.cc BPL.cc BRK.cc BVS.cc CLC.cc CLD.cc CLI.cc CLV.cc CMP.cc CPX.cc CPY.cc CPY.cc DEC.cc DEX.cc DEY.cc EOR.cc INC.cc INX.cc INY.cc JMP.cc JRS.cc LDX.cc LDY.cc LSR.cc NOR.cc ORA.cc PHA.cc PHP.cc PLA.cc PLP.cc ROL.cc ROR.cc RTI.cc RTS.cc SBC.cc SEC.cc SED.cc SEI.cc STA.cc STX.cc STY.cc TAX.cc TAY.cc TSX.cc TXA.cc TXS.cc TYA.cc ../../lib/libboolops.a ../../lib/libflipflops.a
OBJ = $(SRC:.cc=.o)
BIN = ../../lib/libopcodes.a
all: $(SRC) $(BIN) 

debug: CXX += -DDEBUG -g
debug: DEBUG = debug
debug: $(SRC) $(BIN)


$(BIN): $(OBJ)
ifneq ($(MAKECMDGOALS),debug)
	@printf "[AR]  %-20s ... " "$(BIN)"
	@$(AR) rcs $(BIN) $(OBJ) && echo "SUCCESS" || echo "FAIL"
else
	$(AR) rcs $(BIN) $(OBJ)
endif


.cc.o:
ifneq ($(MAKECMDGOALS),debug)
	@printf "[B]   %-20s ... " "$<"
	@$(CXX) -c $< && echo "OK" || echo "FAIL"
else
	$(CXX) -c $<
endif

clean:
	rm -f *.o $(BIN) core

default: $(BIN)
