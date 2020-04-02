# Makefile for linked lists

CXX = g++
CXXFLAGS = -Wall -pedantic --std=c++11 -g



tests.exe: tests.cpp main.h
	$(CXX) $(CXXFLAGS) $< -o $@

# disable built-in rules
.SUFFIXES:

