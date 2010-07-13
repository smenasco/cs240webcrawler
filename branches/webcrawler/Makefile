####------Webcrawler's Makefile---------####ci

BIN_FILE = bin/webcrawler

SRC_FILES= src/main.cpp src/WebCrawler.cpp src/URL.cpp src/URLFilter.cpp src/OccurrenceSet.cpp src/WordIndex.cpp src/PageIndex.cpp src/URLQueue.cpp src/StopWords.cpp src/XMLGenerator.cpp src/HTMLParser.cpp

INC_FILES= inc/main.h inc/WebCrawler.h inc/URL.h inc/URLFilter.h inc/OccurrenceSet.h inc/WordIndex.h inc/PageIndex.h inc/URLQueue.h inc/StopWords.h inc/XMLGenerator.h inc/HTMLParser.h

OBJ_FILES= obj/main.o obj/WebCrawler.o obj/URL.o obj/URLFilter.o obj/OccurrenceSet.o obj/WordIndex.o obj/PageIndex.o obj/URLQueue.o obj/StopWords.o obj/XMLGenerator.o obj/HTMLParser.o

LIB_SRC = utils/src
LIB_OBJ = utils/obj
LIB_INC = utils/include
LIB_OBJ_FILES = $(LIB_OBJ)/CommandRunner.o \
$(LIB_OBJ)/FileInputStream.o $(LIB_OBJ)/FileSystem.o $(LIB_OBJ)/HTMLToken.o $(LIB_OBJ)/HTMLTokenizer.o \
$(LIB_OBJ)/HTTPInputStream.o $(LIB_OBJ)/StringUtil.o $(LIB_OBJ)/URLInputStream.o 
LIB_FILE = lib/libcs240utils.a


all: bin test


#########-------BUILD THE Webcrawler Executable--------#########

bin: $(BIN_FILE)

$(BIN_FILE) : lib $(OBJ_FILES) $(LIB_FILE) 
	g++ -Wall -g -o $(BIN_FILE) $(OBJ_FILES) $(LIB_FILE)
	chmod ugo+x $(BIN_FILE)

obj/main.o : $(SRC_FILES) $(INC_FILES)
	g++ -Wall -g -c -o obj/main.o src/main.cpp -I inc -I $(LIB_INC)

run: bin
	@bin/webcrawler


##########---------BUILD THE TESTDRIVER-------------############

test : testdriver
	@bin/testdriver
testdriver : bin/testdriver

bin/testdriver : lib $(LIB_FILE) obj/testdriver.o $(OBJ_FILES)
	g++ -Wall -g  -o bin/testdriver -I inc obj/testdriver.o $(LIB_FILE)
	chmod ugo+x bin/testdriver

obj/testdriver.o : src/testdriver.cpp inc/testdriver.h $(INC_FILES)
	g++ -Wall -g  -c -o obj/testdriver.o -I inc -I $(LIB_INC) src/testdriver.cpp
	
##########---------BUILD THE SOURCE FILES############	

obj/URLFilter.o : src/URLFilter.cpp inc/URLFilter.h inc/URL.h
	g++ -Wall -g  -c -o obj/URLFilter.o -I inc -I $(LIB_INC) src/URLFilter.cpp
	
obj/WebCrawler.o : src/WebCrawler.cpp inc/WebCrawler.h inc/URL.h
	g++ -Wall -g  -c -o obj/WebCrawler.o -I inc -I $(LIB_INC) src/WebCrawler.cpp
	
obj/URL.o : src/URL.cpp inc/URL.h
	g++ -Wall -g  -c -o obj/URL.o -I inc -I $(LIB_INC) src/URL.cpp
	
obj/OccurrenceSet.o : src/OccurrenceSet.cpp inc/OccurrenceSet.h
	g++ -Wall -g  -c -o obj/OccurrenceSet.o -I inc -I $(LIB_INC) src/OccurrenceSet.cpp

obj/WordIndex.o : src/WordIndex.cpp inc/WordIndex.h inc/OccurrenceSet.h
	g++ -Wall -g  -c -o obj/WordIndex.o -I inc -I $(LIB_INC) src/WordIndex.cpp
	
obj/PageIndex.o : src/PageIndex.cpp inc/PageIndex.h 
	g++ -Wall -g  -c -o obj/PageIndex.o -I inc -I $(LIB_INC) src/PageIndex.cpp
	
obj/URLQueue.o : src/URLQueue.cpp inc/URLQueue.h 
	g++ -Wall -g  -c -o obj/URLQueue.o -I inc -I $(LIB_INC) src/URLQueue.cpp

obj/StopWords.o : src/StopWords.cpp inc/StopWords.h 
	g++ -Wall -g  -c -o obj/StopWords.o -I inc -I $(LIB_INC) src/StopWords.cpp	
	
obj/XMLGenerator.o : src/XMLGenerator.cpp inc/XMLGenerator.h $(LIB_INC)/StringUtil.h inc/URL.h inc/PageIndex.h inc/WordIndex.h
	g++ -Wall -g  -c -o obj/XMLGenerator.o -I inc -I $(LIB_INC) src/XMLGenerator.cpp	
	
obj/HTMLParser.o : src/HTMLParser.cpp inc/HTMLParser.h $(LIB_INC)/HTMLTokenizer.h
	g++ -Wall -g  -c -o obj/HTMLParser.o -I inc -I $(LIB_INC) src/HTMLParser.cpp

#########-------BUILD THE LIBRARY FROM CS240 UTILS--------#########

lib : $(LIB_FILE)
	
$(LIB_FILE) : $(LIB_OBJ_FILES)
	ar r lib/libcs240utils.a $(LIB_OBJ)/*.o

$(LIB_OBJ)/CommandRunner.o : $(LIB_SRC)/CommandRunner.cpp $(LIB_INC)/CS240Exception.h $(LIB_INC)/StringUtil.h $(LIB_INC)/CommandRunner.h
	g++ -Wall -g  -c -o $(LIB_OBJ)/CommandRunner.o -I $(LIB_INC) $(LIB_SRC)/CommandRunner.cpp

$(LIB_OBJ)/FileInputStream.o : $(LIB_SRC)/FileInputStream.cpp $(LIB_INC)/CS240Exception.h $(LIB_INC)/FileInputStream.h
	g++ -Wall -g  -c -o $(LIB_OBJ)/FileInputStream.o -I $(LIB_INC) $(LIB_SRC)/FileInputStream.cpp
	 
$(LIB_OBJ)/FileSystem.o : $(LIB_SRC)/FileSystem.cpp $(LIB_INC)/CS240Exception.h $(LIB_INC)/FileSystem.h $(LIB_INC)/UnitTest.h
	g++ -Wall -g  -c -o $(LIB_OBJ)/FileSystem.o -I $(LIB_INC) $(LIB_SRC)/FileSystem.cpp
  
$(LIB_OBJ)/HTMLToken.o : $(LIB_SRC)/HTMLToken.cpp $(LIB_INC)/HTMLToken.h
	g++ -Wall -g  -c -o $(LIB_OBJ)/HTMLToken.o -I $(LIB_INC) $(LIB_SRC)/HTMLToken.cpp

$(LIB_OBJ)/HTMLTokenizer.o : $(LIB_SRC)/HTMLTokenizer.cpp $(LIB_INC)/HTMLTokenizer.h
	g++ -Wall -g  -c -o $(LIB_OBJ)/HTMLTokenizer.o -I $(LIB_INC) $(LIB_SRC)/HTMLTokenizer.cpp	 

$(LIB_OBJ)/HTTPInputStream.o : $(LIB_SRC)/HTTPInputStream.cpp $(LIB_INC)/CS240Exception.h $(LIB_INC)/StringUtil.h $(LIB_INC)/HTTPInputStream.h
	g++ -Wall -g  -c -o $(LIB_OBJ)/HTTPInputStream.o -I $(LIB_INC) $(LIB_SRC)/HTTPInputStream.cpp

$(LIB_OBJ)/StringUtil.o : $(LIB_SRC)/StringUtil.cpp $(LIB_INC)/StringUtil.h
	g++ -Wall -g  -c -o $(LIB_OBJ)/StringUtil.o -I $(LIB_INC) $(LIB_SRC)/StringUtil.cpp	 
	
$(LIB_OBJ)/URLInputStream.o : $(LIB_SRC)/URLInputStream.cpp $(LIB_INC)/URLInputStream.h $(LIB_INC)/StringUtil.h $(LIB_INC)/CS240Exception.h $(LIB_INC)/HTTPInputStream.h $(LIB_INC)/FileInputStream.h
	g++ -Wall -g  -c -o $(LIB_OBJ)/URLInputStream.o -I $(LIB_INC) $(LIB_SRC)/URLInputStream.cpp	
	
#########---------------Delete the Junx-----------------#########

clean: 
	- @echo "Removing Generated Files"
	- rm -f $(LIB_OBJ)/*
	- rm -f bin/*
	- rm -f obj/*
	- rm -f lib/*
	- @rm -rf build