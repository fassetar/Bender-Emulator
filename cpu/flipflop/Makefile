# Makefile for Backgammon project
CXX = g++ $(CFLAGS) $(OPTS) $(INC)
INC = -I ../include/
CFLAGS = -Wall 
OBJ =  ./ffnand/ffnand.o ./ffnor/ffnor.o ./g8sr/g8sr.o
OPTS =
AR = ar
DEBUG = debug
BIN = ../lib/libflipflops.a
LIBRARIES = libffnand libffnor libg8sr
default: $(LIBRARIES) $(BIN)

$(BIN): $(LIBRARIES)
ifneq ($(MAKECMDGOALS),debug)
	@printf "[AR]  %-20s ... " "$(BIN)"
	@$(AR) -rcs $(BIN) $(OBJ) && echo "SUCCESS" || echo "FAIL"
else
	@$(AR) -rcs $(BIN) $(OBJ) $(LIBS)
endif

libmenu-debug: CXX += -DDEBUG -g
libmenu-debug: DEBUG = debug
libmenu-debug: liband

libffnand:
	@echo "**************************************"
	@echo "*** Building library: lib/ffnand.a *****"
	@echo "***************************************"
	@cd ./ffnand; make $(DEBUG)
	@echo
libffnor:
	@echo "**************************************"
	@echo "*** Building library: lib/ffnor.a *****"
	@echo "***************************************"
	@cd ./ffnor; make $(DEBUG)
	@echo
libg8sr:
	@echo "**************************************"
	@echo "*** Building library: lib/g8sr.a *****"
	@echo "***************************************"
	@cd ./g8sr; make $(DEBUG)
	@echo



clean:
	rm -f *.o $(BIN) core
	@cd ./ffnand; make clean
	@cd ./ffnor; make clean
	@cd ./g8sr; make clean
	@cd ../lib; rm lib*.a

	
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
