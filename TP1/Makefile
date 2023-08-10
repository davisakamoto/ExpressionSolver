CC = g++
CFLAGS = -Wall -g -c -I$(INC)
LIBS = -lm

SRC = src
OBJ = obj
INC = include
BIN = bin

OBJS = $(OBJ)/main.o $(OBJ)/item.o $(OBJ)/no.o $(OBJ)/pilha.o $(OBJ)/arvore.o
HDRS = $(INC)/item.hpp $(INC)/no.hpp $(INC)/pilha.hpp $(INC)/arvore.hpp

EXE = $(BIN)/main

all:  $(EXE)
	$(EXE) $(BIN)/entradas.txt
	$(EXE) $(BIN)/entdouble.s1.n5.i.in
	$(EXE) $(BIN)/entdouble.s2.n5.p.in
	$(EXE) $(BIN)/entdouble.s3.n5.i.in
	$(EXE) $(BIN)/entdouble.s4.n5.p.in
	$(EXE) $(BIN)/entdouble.s5.n5.i.in
	$(EXE) $(BIN)/entdouble.s6.n5.p.in
	$(EXE) $(BIN)/entdouble.s7.n5.i.in
	$(EXE) $(BIN)/entdouble.s8.n5.p.in

$(BIN)/main: $(OBJS)
	$(CC) -pg -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp 

$(OBJ)/item.o: $(HDRS) $(SRC)/item.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/item.o $(SRC)/item.cpp 

$(OBJ)/no.o: $(HDRS) $(SRC)/no.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/no.o $(SRC)/no.cpp

$(OBJ)/pilha.o: $(HDRS) $(SRC)/pilha.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/pilha.o $(SRC)/pilha.cpp

$(OBJ)/arvore.o: $(HDRS) $(SRC)/arvore.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/arvore.o $(SRC)/arvore.cpp
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out

run: all 