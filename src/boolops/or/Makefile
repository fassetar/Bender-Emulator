CXX = g++ $(CXXFLAGS) $(INC) 
CXXFLAGS = -Wall
INC = -I ../../include/
SRC = or.cc 
OBJ = $(SRC:.cc=.o)
all: $(SRC) $(OBJ)
debug: CXX += -DDEBUG -g
debug: DEBUG = debug
debug: $(SRC) $(OBJ)

.cc.o:
ifneq ($(MAKECMDGOALS),debug)
	@printf "[B]   %-20s ... " "$<"
	@$(CXX) -c $< && echo "OK" || echo "FAIL"
else
	$(CXX) -c $<
endif


clean:
	rm -f *.o $(OBJ) core

