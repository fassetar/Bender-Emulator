# Makefile for Backgammon project
CXX = g++ $(CFLAGS) $(OPTS) $(INC)
AR = ar
INC = -I ../include/
CFLAGS = -Wall 
#################### LIKE THIS
LIBS = and/and.o or/or.o not/not.o nor/nor.o xor/xor.o nand/nand.o hadder/hadder.o fadder/fadder.o
OPTS =
DEBUG = 
OBJ = 
BIN = ../lib/libboolops.a
LIBRARIES = liband libor libnot libnor libxor libxnor libnand libhadder libfadder
default: $(LIBRARIES) $(BIN)

$(BIN): $(LIBRARIES)
ifneq ($(MAKECMDGOALS),debug)
	@printf "[AR]  %-20s ... " "$(BIN)"
	@$(AR) -rcs $(BIN) $(LIBS) && echo "SUCCESS" || echo "FAIL"
else
	$(AR) -rcs $(BIN) $(OBJ)
endif
# THIS IS TERRIBLE...
#	@cd ../lib;rm -f lib*.a




libmenu-debug: CXX += -DDEBUG -g
libmenu-debug: DEBUG = debug
libmenu-debug: liband

liband:
	@echo "**************************************"
	@echo "*** Building library: lib/and.o *****"
	@echo "***************************************"
	@cd ./and; make $(DEBUG)
	@echo
libor:
	@echo "**************************************"
	@echo "*** Building library: lib/or.o   *****"
	@echo "***************************************"
	@cd ./or; make $(DEBUG)
	@echo
libnot:
	@echo "**************************************"
	@echo "*** Building library: lib/not.o *****"
	@echo "***************************************"
	@cd ./not; make $(DEBUG)
	@echo
libnor:
	@echo "**************************************"
	@echo "*** Building library: lib/nor.o *****"
	@echo "***************************************"
	@cd ./nor; make $(DEBUG)
	@echo
libnand:
	@echo "**************************************"
	@echo "*** Building library: lib/nand.o *****"
	@echo "***************************************"
	@cd ./nand; make $(DEBUG)
	@echo
libxor:
	@echo "**************************************"
	@echo "*** Building library: lib/xor.o  *****"
	@echo "***************************************"
	@cd ./xor; make $(DEBUG)
	@echo
libxnor:
	@echo "**************************************"
	@echo "*** Building library: lib/xnor.o *****"
	@echo "***************************************"
	@cd ./xnor; make $(DEBUG)
	@echo
libhadder:
	@echo "***************************************"
	@echo "*** Building library: lib/hadder.o*****"
	@echo "***************************************"
	@cd ./hadder; make $(DEBUG)
	@echo
libfadder:
	@echo "***************************************"
	@echo "*** Building library: lib/fadder.o*****"
	@echo "***************************************"
	@cd ./fadder; make $(DEBUG)
	@echo

clean:
	rm -f *.o $(BIN) core
	@cd ./and; make clean
	@cd ./fadder; make clean
	@cd ./hadder; make clean
	@cd ./nand; make clean
	@cd ./nor; make clean
	@cd ./not; make clean
	@cd ./or; make clean
	@cd ./xnor; make clean
	@cd ./xor; make clean
	
help:
	@echo
	@echo "*************************[ CPU Project/Boolops]*************************"
	@echo "** This is the Makefile to handle boolen operation libraries archives **"
	@echo "** code. Please use one of the available options listed:              **"
	@echo "**                                                                    **"
	@echo "** make and                                                           **"
	@echo "** make                      - build backgammon binary with debugging **"
	@echo "** make test                - build data structure class test apps    **"
	@echo "** make test-debug          - build test apps with debugging symbols  **"
	@echo "** make libs                - build all data structure libraries      **"
	@echo "** make libs-debug          - build all libraries with debug symbols  **"
	@echo "** make libs-help           - information on specific library builds  **"
	@echo "**                                                                    **"
	@echo "** make clean               - clean; remove all objects/compiled code **"
	@echo "** make help                - this information                        **"
	@echo "************************************************************************"
