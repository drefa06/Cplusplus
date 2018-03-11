#def des cible particulieres
.PHONY: clean, realclean

#desactivation regles implicites
.SUFFIXES:

#variables
CXX = g++
DEBUG = yes
EXEC = app1

ifeq ($(DEBUG),yes)
	CXXFLAGS = -g -W -Wall
else
	CXXFLAGS =
endif

# all conditionnel
all : $(EXEC)
ifeq (($DEBUG),yes)
	@echo "Génération en mode Debug"
else
	@echo "Génération en mode Release"
endif
 
app1: main.o fabrice2.o
	$(CXX) $^ -o $(EXEC)
 
 
#main.o: fabrice2.hpp
 
%.o: %.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

clean:
	rm -rf *.o rm -rf *.bak

realclean: clean
	rm -rf app1
