CXX = g++ $(CXXFLAGS) $(INC) $(LIBS)
AR = ar
CXXFLAGS = -Wall
INC = -I ../include/
LIBS =
SRC = register/register.cc ../flipflop/g8sr/g8sr.cc memory/mem256kB.cc arithmeticlogicunit/alu.cc ../boolops/not/not.cc ../flipflop/ffnor/ffnor.cc ../boolops/and/and.cc ../boolops/nor/nor.cc terp.cc 8085.exe.cc
OBJ = $(SRC:.cc=.o)
BIN = 8085.exe
all: $(SRC) $(BIN)

debug: CXX += -DDEBUG -g
debug: DEBUG = debug
debug: $(SRC) $(BIN)

$(BIN): $(OBJ)
ifneq ($(MAKECMDGOALS),debug)
	@printf "[CC]  %-20s ... " "$(BIN)"
	@$(CXX) -o $(BIN) $(OBJ) && echo "SUCCESS" || echo "FAIL"
else
	$(CXX) -o $(BIN) $(OBJ)
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
