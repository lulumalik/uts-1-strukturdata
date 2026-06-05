# Makefile - Sistem Klinik E-Health (Struktur Data & Algoritma UTS)
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude
SRC = src/main.cpp src/array.cpp src/linkedlist.cpp src/queue.cpp src/stack.cpp src/tree.cpp
TARGET = bin/e-health-klinik

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(SRC)
	@if not exist bin mkdir bin
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	@if exist bin rmdir /s /q bin
