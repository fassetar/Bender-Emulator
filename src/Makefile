# Makefile for CPU project
CXX = g++ $(CFLAGS) $(OPTS) $(INC)
INC = -I include/
CFLAGS = -Wall 
LIBS = 
OPTS =
DEBUG = 
OBJ = main.o 
LIBRARIES = 
COMPONENTS = libboolops libflipflops
BIN = cpu  

default: help

debug: CXX += -DDEBUG -g
debug: DEBUG = debug
debug: $(BIN)

cpu: $(COMPONENTS) $(LIBRARIES) $(OBJ)
	@echo "*****************************************************"
	@echo "*** Building $(BIN)"
	@echo "*****************************************************"
	$(CXX) $(CFLAGS) -o $(BIN) $(OBJ) $(LIBS)
	@echo

components-debug: CXX += -DDEBUG -g
components-debug: DEBUG = debug
components-debug: $(COMPONENTS)

components: $(COMPONENTS)

libboolops-debug: CXX += -DDEBUG -g
libboolops-debug: DEBUG = debug
libboolops-debug: boolops

libboolops:
	@echo "******************************************"
	@echo "*** Building compent: boolops.a ***"
	@echo "******************************************"
	@cd ./boolops; make 
	@echo

libflipflops-debug: CXX += -DDEBUG -g
libflipflops-debug: DEBUG = debug
libflipflops-debug: ffnand

libflipflops:
	@echo "******************************************"
	@echo "*** Building compent: boolops/flipflops.a ***"
	@echo "******************************************"
	@cd ./flipflop/; make $(DEBUG)
	@echo

help:
	@echo
	@echo "*************************[ CPU Project ]********************************"
	@echo "** CSCS 2650 Computer Organization               Spring 2011 Semester **"
	@echo "** APIs/Documentation:          http://lab46.corning-cc.edu/notes/asm **"
	@echo "**                                                                    **"
	@echo "** This is the Makefile to handle many of the clerical tasks of the   **"
	@echo "** code. Please use one of the available options listed:              **"
	@echo "**                                                                    **"
	@echo "** make cpu                 - build CPU simulator binary              **"
	@echo "** make debug               - build CPU simulator binary w/ debugging **"
	@echo "** make components          - build component classes                 **"
	@echo "** make components-debug    - build component classes w/ debugging    **"
	@echo "** make components-help     - information on specific component build **"
	@echo "**                                                                    **"
	@echo "** make clean               - clean; remove all objects/compiled code **"
	@echo "** make help                - this information                        **"
	@echo "************************************************************************"
	@echo

components-help:
	@echo
	@echo "*************************[ CPU Project ]********************************"
	@echo "** CSCS 2650 Computer Organization               Spring 2011 Semester **"
	@echo "** APIs/Documentation:          http://lab46.corning-cc.edu/notes/asm **"
	@echo "**                                                                    **"
	@echo "** This is the Makefile to handle many of the clerical tasks of the   **"
	@echo "** code. Please use one of the available options listed:              **"
	@echo "**                                                                    **"
	@echo "** make components          - build component classes                 **"
	@echo "** make components-debug    - build component classes w/ debugging    **"
	@echo "** make components-help     - this information                        **"
	@echo "**                                                                    **"
	@echo "** make and                 - build AND class (and test app)          **"
	@echo "** make and-debug           - build AND class (and test app) w/ debug **"
	@echo "** make or                  - build OR class (and test app)           **"
	@echo "** make or-debug            - build OR class (and test app) w/ debug  **"
	@echo "** make not                 - build NOT class (and test app)          **"
	@echo "** make not-debug           - build NOT class (and test app) w/ debug **"
	@echo "**                                                                    **"
	@echo "** make clean               - clean; remove all objects/compiled code **"
	@echo "** make help                - this information                        **"
	@echo "************************************************************************"
	@echo

clean:
	rm -f *.o $(BIN) core
	@cd ./boolops; make clean
	@cd ./flipflop/ffnor; make clean
	@cd ./flipflop/ffxnor; make clean
	@cd ./flipflop/g8sr; make clean
	@cd ./flipflop/ffnand; make clean
