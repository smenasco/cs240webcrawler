####------Webcrawler's Makefile---------####ci

BIN_FILE = bin/webcrawler

SRC_FILES= src/main.cpp

INC_FILES= inc/main.h

OBJ_FILES=obj/main.o 

LIB_SRC = utils/src
LIB_OBJ = utils/obj
LIB_INC = utils/include
LIB_OBJ_FILES = $(LIB_OBJ)/CommandRunner.o \
$(LIB_OBJ)/FileInputStream.o $(LIB_OBJ)/FileSystem.o $(LIB_OBJ)/HTMLToken.o $(LIB_OBJ)/HTMLTokenizer.o \
$(LIB_OBJ)/HTTPInputStream.o $(LIB_OBJ)/StringUtil.o $(LIB_OBJ)/URLInputStream.o 
LIB_FILE = lib/libcs240utils.a


#########-------BUILD THE Webcrawler Executable--------#########

bin: $(BIN_FILE)

$(BIN_FILE) : lib $(OBJ_FILES) $(LIB_FILE) 
	g++ -g -o $(BIN_FILE) $(OBJ_FILES) $(LIB_FILE)
	chmod ugo+x $(BIN_FILE)

obj/main.o : $(SRC_FILES) $(INC_FILES)
	g++ -g -c -o obj/main.o src/main.cpp -I inc -I $(LIB_INC)

run: bin
	@bin/webcrawler


##########---------BUILD THE TESTDRIVER-------------############

test : testdriver
	@bin/testdriver
testdriver : bin/testdriver

bin/testdriver : lib $(LIB_FILE) obj/testdriver.o
	g++ -g  -o bin/testdriver -I inc obj/testdriver.o $(LIB_FILE)
	chmod ugo+x bin/testdriver

obj/testdriver.o : src/testdriver.cpp inc/testdriver.h
	g++ -g  -c -o obj/testdriver.o -I inc -I $(LIB_INC) src/testdriver.cpp


#########-------BUILD THE LIBRARY FROM CS240 UTILS--------#########

lib : $(LIB_FILE)
	
$(LIB_FILE) : $(LIB_OBJ_FILES)
	ar r lib/libcs240utils.a $(LIB_OBJ)/*.o

$(LIB_OBJ)/CommandRunner.o : $(LIB_SRC)/CommandRunner.cpp $(LIB_INC)/CS240Exception.h $(LIB_INC)/StringUtil.h $(LIB_INC)/CommandRunner.h
	g++ -g  -c -o $(LIB_OBJ)/CommandRunner.o -I $(LIB_INC) $(LIB_SRC)/CommandRunner.cpp

$(LIB_OBJ)/FileInputStream.o : $(LIB_SRC)/FileInputStream.cpp $(LIB_INC)/CS240Exception.h $(LIB_INC)/FileInputStream.h
	g++ -g  -c -o $(LIB_OBJ)/FileInputStream.o -I $(LIB_INC) $(LIB_SRC)/FileInputStream.cpp
	 
$(LIB_OBJ)/FileSystem.o : $(LIB_SRC)/FileSystem.cpp $(LIB_INC)/CS240Exception.h $(LIB_INC)/FileSystem.h $(LIB_INC)/UnitTest.h
	g++ -g  -c -o $(LIB_OBJ)/FileSystem.o -I $(LIB_INC) $(LIB_SRC)/FileSystem.cpp
  
$(LIB_OBJ)/HTMLToken.o : $(LIB_SRC)/HTMLToken.cpp $(LIB_INC)/HTMLToken.h
	g++ -g  -c -o $(LIB_OBJ)/HTMLToken.o -I $(LIB_INC) $(LIB_SRC)/HTMLToken.cpp

$(LIB_OBJ)/HTMLTokenizer.o : $(LIB_SRC)/HTMLTokenizer.cpp $(LIB_INC)/HTMLTokenizer.h
	g++ -g  -c -o $(LIB_OBJ)/HTMLTokenizer.o -I $(LIB_INC) $(LIB_SRC)/HTMLTokenizer.cpp	 

$(LIB_OBJ)/HTTPInputStream.o : $(LIB_SRC)/HTTPInputStream.cpp $(LIB_INC)/CS240Exception.h $(LIB_INC)/StringUtil.h $(LIB_INC)/HTTPInputStream.h
	g++ -g  -c -o $(LIB_OBJ)/HTTPInputStream.o -I $(LIB_INC) $(LIB_SRC)/HTTPInputStream.cpp

$(LIB_OBJ)/StringUtil.o : $(LIB_SRC)/StringUtil.cpp $(LIB_INC)/StringUtil.h
	g++ -g  -c -o $(LIB_OBJ)/StringUtil.o -I $(LIB_INC) $(LIB_SRC)/StringUtil.cpp	 
	
$(LIB_OBJ)/URLInputStream.o : $(LIB_SRC)/URLInputStream.cpp $(LIB_INC)/URLInputStream.h $(LIB_INC)/StringUtil.h $(LIB_INC)/CS240Exception.h $(LIB_INC)/HTTPInputStream.h $(LIB_INC)/FileInputStream.h
	g++ -g  -c -o $(LIB_OBJ)/URLInputStream.o -I $(LIB_INC) $(LIB_SRC)/URLInputStream.cpp	
	
#########---------------Delete the Junx-----------------#########

clean: 
	- echo "Removing Generated Files"
	- rm -f $(LIB_OBJ)/*
	- rm -f bin/*
	- rm -f obj/*
	- rm -f lib/*