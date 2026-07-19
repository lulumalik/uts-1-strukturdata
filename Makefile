# Makefile - Sistem Klinik E-Health (Struktur Data & Algoritma UTS)
CXX = g++
CC = gcc
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude -Ithird_party/sqlite
CFLAGS = -O2 -Ithird_party/sqlite
SRC = src/main.cpp src/array.cpp src/linkedlist.cpp src/queue.cpp src/stack.cpp src/tree.cpp src/graph.cpp src/database.cpp src/sortsearch.cpp
SQLITE_OBJ = bin/sqlite3.o
TARGET = bin/e-health-klinik

.PHONY: all run clean

all: $(TARGET)

$(SQLITE_OBJ): third_party/sqlite/sqlite3.c
	@if not exist bin mkdir bin
	$(CC) -c $(CFLAGS) third_party/sqlite/sqlite3.c -o $(SQLITE_OBJ)

$(TARGET): $(SRC) $(SQLITE_OBJ) include/database.h
	@if not exist bin mkdir bin
	$(CXX) $(CXXFLAGS) $(SRC) $(SQLITE_OBJ) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	@if exist bin rmdir /s /q bin
