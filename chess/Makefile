# -----------------------------------------------------------------------------
# Generic Variables 
# -----------------------------------------------------------------------------
CC = g++
GTKMM = gtkmm-2.4
SIGC = sigc++-2.0
LIBGLADE = libglademm-2.4

FLAGS = -I$(INC_FOLDER) -I$(LIB_INC) -I$(GAME_INC_FOLDER) -I$(VIEW_INC_FOLDER) -Wall -g -fPIC

#CFLAGS are the -I values needed to compile files using the GTKMM, SIGC, and
#LIBGLADE libraries
CFLAGS = `pkg-config $(GTKMM) $(SIGC) $(LIBGLADE) --cflags`  -I$(IMAGES_FOLDER)

#LIBS are the paths to the static libraries for GTKMM, SIGC, and LIBGLADE needed
#for linking
LIBS = `pkg-config $(GTKMM) $(SIGC) $(LIBGLADE) --libs` -L/usr/X11/lib

#LIB_FLAGS D_LOG_DOMAIN is used by g_log in the ChessGui library to seperate logging messages from the library
# from logging messages from the students code
#IMPORTANT: You must add a compiler option here for the library to be dynamic
LIB_FLAGS = -DG_LOG_DOMAIN=\"ChessGui\" -fPIC

LIB_SRC = utils/src
LIB_OBJ = utils/obj
LIB_INC = utils/inc
UTIL_OBJ_FILES = $(LIB_OBJ)/CommandRunner.o \
	$(LIB_OBJ)/FileInputStream.o $(LIB_OBJ)/FileSystem.o $(LIB_OBJ)/HTMLToken.o $(LIB_OBJ)/HTMLTokenizer.o \
	$(LIB_OBJ)/HTTPInputStream.o $(LIB_OBJ)/StringUtil.o $(LIB_OBJ)/URLInputStream.o 
LIB_FILE = lib/libcs240utils.a


# -----------------------------------------------------------------------------
# Folder Variables
# -----------------------------------------------------------------------------
VIEW_FOLDER = view
VIEW_INC_FOLDER = $(VIEW_FOLDER)/inc
VIEW_SRC_FOLDER = $(VIEW_FOLDER)/src
VIEW_OBJ_FOLDER = $(VIEW_FOLDER)/obj
IMAGES_FOLDER = $(VIEW_FOLDER)/images

CONTROLLER_FOLDER = controller
SRC_FOLDER = $(CONTROLLER_FOLDER)/src
INC_FOLDER = $(CONTROLLER_FOLDER)/inc
OBJ_FOLDER = $(CONTROLLER_FOLDER)/obj

GAME_FOLDER = game
GAME_SRC_FOLDER = $(GAME_FOLDER)/src
GAME_INC_FOLDER = $(GAME_FOLDER)/inc
GAME_OBJ_FOLDER = $(GAME_FOLDER)/obj


BIN_FOLDER = bin

# -----------------------------------------------------------------------------
# File Name Variables
# -----------------------------------------------------------------------------
#change this to a dynamic library name
LIBRARY= $(VIEW_FOLDER)/cs240.a
EXE_NAME = $(BIN_FOLDER)/chess

LIB_OBJ_FILES = $(VIEW_OBJ_FOLDER)/Chess.o $(VIEW_OBJ_FOLDER)/ChessGui.o \
		$(VIEW_OBJ_FOLDER)/ChessGuiBoard.o $(VIEW_OBJ_FOLDER)/ChessGuiBoardCell.o \
		$(VIEW_OBJ_FOLDER)/ChessGuiImages.o $(VIEW_OBJ_FOLDER)/SelectDialog.o
		
EXE_OBJ_FILES = $(OBJ_FOLDER)/main.o $(GAME_OBJ_FOLDER)/ChessPiece.o \
		$(GAME_OBJ_FOLDER)/Bishop.o $(GAME_OBJ_FOLDER)/Rook.o $(GAME_OBJ_FOLDER)/Queen.o \
		$(GAME_OBJ_FOLDER)/King.o $(GAME_OBJ_FOLDER)/Pawn.o $(GAME_OBJ_FOLDER)/Knight.o \
		$(GAME_OBJ_FOLDER)/Square.o $(GAME_OBJ_FOLDER)/GameBoard.o $(GAME_OBJ_FOLDER)/BoardPosition.o \
		$(OBJ_FOLDER)/ChessPlayer.o $(OBJ_FOLDER)/HumanPlayer.o $(OBJ_FOLDER)/CompPlayer.o \
		$(OBJ_FOLDER)/Controller.o $(GAME_OBJ_FOLDER)/Move.o $(GAME_OBJ_FOLDER)/MoveHistory.o \
		$(OBJ_FOLDER)/SaveLoadGame.o
		
CHESSPIECE_FILES = $(GAME_SRC_FOLDER)/Pawn.cpp $(GAME_INC_FOLDER)/Pawn.h \
	$(GAME_SRC_FOLDER)/Queen.cpp $(GAME_INC_FOLDER)/Queen.h $(GAME_SRC_FOLDER)/Rook.cpp  \
	$(GAME_INC_FOLDER)/Rook.h $(GAME_SRC_FOLDER)/Knight.cpp $(GAME_INC_FOLDER)/Knight.h \
	$(GAME_SRC_FOLDER)/King.cpp $(GAME_INC_FOLDER)/King.h $(GAME_SRC_FOLDER)/Bishop.cpp \
	$(GAME_INC_FOLDER)/Bishop.h 


# -----------------------------------------------------------------------------
# Command Variables
# -----------------------------------------------------------------------------
bin : $(EXE_NAME)

run : $(EXE_NAME)
	./$(EXE_NAME)
	
runhh : $(EXE_NAME)
	./$(EXE_NAME) 1
	
runhc : $(EXE_NAME)
	./$(EXE_NAME) 2
	
runch : $(EXE_NAME)
	./$(EXE_NAME) 3
  	
runcc : $(EXE_NAME)
	./$(EXE_NAME) 4
	
memtest: $(EXE_NAME)
	valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --suppressions=chess.supp $(EXE_NAME)
	
debug : $(EXE_NAME)
	gdb $(EXE_NAME)
	
lib : $(LIBRARY) $(LIB_FILE)

clean: 
	-rm -f $(EXE_NAME)
	-rm -f $(EXE_OBJ_FILES)
	-rm -f $(SRC_FOLDER)/*~ $(INC_FOLDER)/*~
	-rm -f lib/*
	-rm -f $(LIB_OBJ)/*
	-rm -f $(LIBRARY) $(LIB_OBJ_FILES)
	-rm -f $(VIEW_SRC_FOLDER)/*~ $(VIEW_INC_FOLDER)/*~

# -----------------------------------------------------------------------------
# File Construction
# -----------------------------------------------------------------------------
$(EXE_NAME): $(EXE_OBJ_FILES)  $(LIBRARY)  $(LIB_FILE)
	$(CC) $(FLAGS) $(CFLAGS) $(LIBS) -o $(EXE_NAME) $(EXE_OBJ_FILES)  $(LIBRARY) $(LIB_FILE)
	
$(OBJ_FOLDER)/main.o: $(SRC_FOLDER)/main.cpp $(SRC_FOLDER)/Controller.cpp $(INC_FOLDER)/Controller.h
	$(CC) -c $(FLAGS) $(CFLAGS) -o $(OBJ_FOLDER)/main.o $(SRC_FOLDER)/main.cpp
	
	
# Students: Place your makefile commands here

$(OBJ_FOLDER)/Controller.o: $(SRC_FOLDER)/Controller.cpp $(INC_FOLDER)/Controller.h $(INC_FOLDER)/ChessController.h $(INC_FOLDER)/ChessPlayer.h $(SRC_FOLDER)/HumanPlayer.cpp $(INC_FOLDER)/HumanPlayer.h $(SRC_FOLDER)/CompPlayer.cpp $(INC_FOLDER)/CompPlayer.h $(VIEW_INC_FOLDER)/ChessView.h $(GAME_SRC_FOLDER)/GameBoard.cpp $(GAME_INC_FOLDER)/GameBoard.h
	$(CC) -c $(FLAGS) $(CFLAGS) -o $(OBJ_FOLDER)/Controller.o $(SRC_FOLDER)/Controller.cpp

$(OBJ_FOLDER)/ChessPlayer.o: $(SRC_FOLDER)/ChessPlayer.cpp $(INC_FOLDER)/ChessPlayer.h $(GAME_SRC_FOLDER)/GameBoard.cpp $(GAME_INC_FOLDER)/GameBoard.h
	$(CC) -c $(FLAGS) $(CFLAGS) -o $(OBJ_FOLDER)/ChessPlayer.o $(SRC_FOLDER)/ChessPlayer.cpp

$(OBJ_FOLDER)/HumanPlayer.o: $(SRC_FOLDER)/HumanPlayer.cpp $(INC_FOLDER)/HumanPlayer.h $(INC_FOLDER)/ChessPlayer.h $(GAME_SRC_FOLDER)/GameBoard.cpp $(GAME_INC_FOLDER)/GameBoard.h
	$(CC) -c $(FLAGS) $(CFLAGS) -o $(OBJ_FOLDER)/HumanPlayer.o $(SRC_FOLDER)/HumanPlayer.cpp	

$(OBJ_FOLDER)/CompPlayer.o: $(SRC_FOLDER)/CompPlayer.cpp $(INC_FOLDER)/CompPlayer.h $(INC_FOLDER)/ChessPlayer.h $(GAME_SRC_FOLDER)/GameBoard.cpp $(GAME_INC_FOLDER)/GameBoard.h
	$(CC) -c $(FLAGS) $(CFLAGS) -o $(OBJ_FOLDER)/CompPlayer.o $(SRC_FOLDER)/CompPlayer.cpp	

$(OBJ_FOLDER)/SaveLoadGame.o: $(SRC_FOLDER)/SaveLoadGame.cpp $(INC_FOLDER)/SaveLoadGame.h 
	$(CC) -c $(FLAGS) $(CFLAGS) -o $(OBJ_FOLDER)/SaveLoadGame.o $(SRC_FOLDER)/SaveLoadGame.cpp

$(GAME_OBJ_FOLDER)/ChessPiece.o: $(GAME_SRC_FOLDER)/ChessPiece.cpp $(GAME_INC_FOLDER)/ChessPiece.h $(GAME_INC_FOLDER)/GameBoard.h $(GAME_INC_FOLDER)/GameInfo.h
	$(CC) -c $(FLAGS) $(CFLAGS) -o $(GAME_OBJ_FOLDER)/ChessPiece.o $(GAME_SRC_FOLDER)/ChessPiece.cpp

$(GAME_OBJ_FOLDER)/BoardPosition.o: $(GAME_SRC_FOLDER)/BoardPosition.cpp $(GAME_INC_FOLDER)/BoardPosition.h 
	$(CC) -c $(FLAGS) $(CFLAGS) -o $(GAME_OBJ_FOLDER)/BoardPosition.o $(GAME_SRC_FOLDER)/BoardPosition.cpp

$(GAME_OBJ_FOLDER)/Move.o: $(GAME_SRC_FOLDER)/Move.cpp $(GAME_INC_FOLDER)/Move.h 
	$(CC) -c $(FLAGS) $(CFLAGS) -o $(GAME_OBJ_FOLDER)/Move.o $(GAME_SRC_FOLDER)/Move.cpp

$(GAME_OBJ_FOLDER)/MoveHistory.o: $(GAME_SRC_FOLDER)/MoveHistory.cpp $(GAME_INC_FOLDER)/MoveHistory.h $(GAME_SRC_FOLDER)/Move.cpp $(GAME_INC_FOLDER)/Move.h 
	$(CC) -c $(FLAGS) $(CFLAGS) -o $(GAME_OBJ_FOLDER)/MoveHistory.o $(GAME_SRC_FOLDER)/MoveHistory.cpp

$(GAME_OBJ_FOLDER)/Bishop.o: $(GAME_SRC_FOLDER)/Bishop.cpp $(GAME_INC_FOLDER)/Bishop.h $(GAME_INC_FOLDER)/GameBoard.h $(GAME_INC_FOLDER)/GameInfo.h $(GAME_INC_FOLDER)/Square.h
	$(CC) -c $(FLAGS) $(CFLAGS) -o $(GAME_OBJ_FOLDER)/Bishop.o $(GAME_SRC_FOLDER)/Bishop.cpp

$(GAME_OBJ_FOLDER)/King.o: $(GAME_SRC_FOLDER)/King.cpp $(GAME_INC_FOLDER)/King.h $(GAME_INC_FOLDER)/GameBoard.h $(GAME_INC_FOLDER)/GameInfo.h $(GAME_INC_FOLDER)/Square.h
	$(CC) -c $(FLAGS) $(CFLAGS) -o $(GAME_OBJ_FOLDER)/King.o $(GAME_SRC_FOLDER)/King.cpp

$(GAME_OBJ_FOLDER)/Knight.o: $(GAME_SRC_FOLDER)/Knight.cpp $(GAME_INC_FOLDER)/Knight.h $(GAME_INC_FOLDER)/GameBoard.h $(GAME_INC_FOLDER)/GameInfo.h $(GAME_INC_FOLDER)/Square.h
	$(CC) -c $(FLAGS) $(CFLAGS) -o $(GAME_OBJ_FOLDER)/Knight.o $(GAME_SRC_FOLDER)/Knight.cpp

$(GAME_OBJ_FOLDER)/Pawn.o: $(GAME_SRC_FOLDER)/Pawn.cpp $(GAME_INC_FOLDER)/Pawn.h $(GAME_INC_FOLDER)/GameBoard.h $(GAME_INC_FOLDER)/GameInfo.h $(GAME_INC_FOLDER)/Square.h
	$(CC) -c $(FLAGS) $(CFLAGS) -o $(GAME_OBJ_FOLDER)/Pawn.o $(GAME_SRC_FOLDER)/Pawn.cpp

$(GAME_OBJ_FOLDER)/Queen.o: $(GAME_SRC_FOLDER)/Queen.cpp $(GAME_INC_FOLDER)/Queen.h $(GAME_INC_FOLDER)/GameBoard.h $(GAME_INC_FOLDER)/GameInfo.h $(GAME_INC_FOLDER)/Square.h
	$(CC) -c $(FLAGS) $(CFLAGS) -o $(GAME_OBJ_FOLDER)/Queen.o $(GAME_SRC_FOLDER)/Queen.cpp

$(GAME_OBJ_FOLDER)/Rook.o: $(GAME_SRC_FOLDER)/Rook.cpp $(GAME_INC_FOLDER)/Rook.h $(GAME_INC_FOLDER)/GameBoard.h $(GAME_INC_FOLDER)/GameInfo.h $(GAME_INC_FOLDER)/Square.h
	$(CC) -c $(FLAGS) $(CFLAGS) -o $(GAME_OBJ_FOLDER)/Rook.o $(GAME_SRC_FOLDER)/Rook.cpp
	
$(GAME_OBJ_FOLDER)/Square.o: $(GAME_SRC_FOLDER)/Square.cpp $(GAME_INC_FOLDER)/Square.h $(GAME_INC_FOLDER)/ChessPiece.h $(CHESSPIECE_FILES)
	$(CC) -c $(FLAGS) $(CFLAGS) -o $(GAME_OBJ_FOLDER)/Square.o $(GAME_SRC_FOLDER)/Square.cpp

$(GAME_OBJ_FOLDER)/GameBoard.o: $(GAME_SRC_FOLDER)/GameBoard.cpp $(GAME_INC_FOLDER)/GameBoard.h $(GAME_SRC_FOLDER)/ChessPiece.cpp $(GAME_INC_FOLDER)/ChessPiece.h $(GAME_SRC_FOLDER)/Square.cpp $(GAME_INC_FOLDER)/Square.h 
	$(CC) -c $(FLAGS) $(CFLAGS) -o $(GAME_OBJ_FOLDER)/GameBoard.o $(GAME_SRC_FOLDER)/GameBoard.cpp	



# Students: Place your makefile commands here
	

# -----------------------------------------------------------------------------
# Library Construction
# -----------------------------------------------------------------------------



# CS 240 UTILS 
# -----------------------------------------------------------------------------

	
$(LIB_FILE) : $(UTIL_OBJ_FILES)
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
	


#This is currently a STATIC library, you must change it to a DYNAMIC library
#You must also add a compiler option to the variable LIB_FLAGS in order for the library to be dynamic
$(LIBRARY): $(LIB_OBJ_FILES) 
	ar rcs $(LIBRARY) $(LIB_OBJ_FILES)

	
########DO NOT DELETE###########################################################################################3
#Below is some Makefile Magic to compile the libraries, you do not need to
#understand or alter it.  If you would like to, look up the Make manual online, it's very comprehensive	
LIBSOURCES = $(foreach file, $(shell ls $(VIEW_SRC_FOLDER)/*.cpp), $(basename $(notdir $(file))))

$(VIEW_OBJ_FOLDER)/%.o : $(VIEW_SRC_FOLDER)/%.cpp $(VIEW_INC_FOLDER)/Inline.h
	$(CC) $(FLAGS) $(LIB_FLAGS) $(CFLAGS) -c -o $@ $< 

  #The following is part of what lets us include Images within the binary. It currently only loads the default
  #"Image not found" icon that we use

INLINE_IMAGES = $(shell ls $(IMAGES_FOLDER)/* )
INLINE_IMAGE_PAIRS =$(foreach file, $(INLINE_IMAGES), $(basename $(notdir $(file)) $(file).* ))	
view/inc/Inline.h: $(INLINE_IMAGES)
	@echo "Updating Images"
	gdk-pixbuf-csource --raw --build-list $(INLINE_IMAGE_PAIRS) > $(VIEW_INC_FOLDER)/Inline.h

