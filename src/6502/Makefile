CXX = g++ $(CXXFLAGS) $(INC) 
AR = ar
CXXFLAGS = -Wall
INC = -I ../include
LIBS += -L../lib -lopcodes -lr6502 -lflipflops -lboolops
SRC = interpreter.cc 
OBJ = $(SRC:.cc=.o)
BIN = Binder
START = liba
default: $(START) $(BIN)

debug: CXX += -DDEBUG -g
debug: DEBUG = debug
debug: $(SRC) $(BIN) 
liba:
	@cd ../boolops; make
	@cd ../flipflop; make
	@cd ./register; make
	@cd ./opcodes; make
Binder: $(OBJ)
	@echo "******************************************"
	@echo "***         Building BENDER            ***"
	@echo "******************************************"
	@echo "           QR                             "
	@echo "          @t(@                            "
	@echo "           @R                             "
	@echo "           @S                             "
	@echo "           RSQ                            "
	@echo "           @K@                            "
	@echo "           $KQ7                           "
	@echo "           RSQ@                           "
	@echo "         @%GC(7Q/                         "
	@echo "       @@K%C6QKCCC6@                      "
	@echo "     (@%CC3%C3CC%CCCC6Q                   "
	@echo "    GCCC%C3CC66CCCsCCC@                   "
	@echo "   sQ3C6CCCC%CCC3CCCCC%C7                 "
	@echo "   @6%CCCCCOC6CsCCC66O%s@                 "
	@echo "   GsCCC36CC6CC6%%CC%CC%@                 "
	@echo "   GC36C3s%CCCCsCC%C%C%CsG                "
	@echo "   sCCC666CCCCC6%CC%CCsRG%@7              "
	@echo "   C6%C63CRQGC3C77%7(t((t((7Q^            "
	@echo "   sC3CC@C((t((7QGK@@@@@@$1113Q           "
	@echo "   S6CCO((t((@%/%O@@@@@@O(//R@@sC         "
	@echo "   QsCC6st(%@        CG       @@s@        "
	@echo "   @OCCC%((%R/C   @   RC   @  @@7@        "
	@echo "   @OO3s@(((@/       (R/     @@R(         "
	@echo "   @s3CCCQC(t%%GQRQQQQGCGC((7R            "
	@echo "   GGCCCsCCCG36SGQKSSSGsss                "
	@echo "   Gs6C6CCCCCCCCCCs6CC6CC3                "
	@echo "   /@CCC3Cs3GSQQQQQRGQS@@Q                "
	@echo "    @3%C@@(@///%///(((((                  "
	@echo "    @CCOR/(@(O%O%%((((((                  "
	@echo "    GCCs@%(@///%////(((C                  "
	@echo "    CCCCG@(@%%CQ%%%%O(/C                  "
	@echo "    sC3C%CCGGQQQQQGGG6CCC@                "
	@echo "  @((%@Q3CC3%C3CC%CCCCsQC((Q7             "
	@echo " !Qt((t((7%QRR@QK@QQQG37((t((7@           "
	@echo "%3((t(((((((t((t((t((t(tt((t(t((t@        "
	@echo "%7t((t((t((((tt((((((((t(tt(t((t(((CC     "
	@echo "********Intel this MX?THRF&KR!!!!*********"
	 

	$(CXX) $(CFLAGS) -o $(BIN) $(OBJ) $(LIBS)
	@echo

clean:
	rm -f *.o $(BIN) core
	@cd ../boolops; make clean
	@cd  ../flipflop; make clean
	@cd ./opcodes; make clean
	@cd ./register; make clean

