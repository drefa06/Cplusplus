#def des cible particulieres
.PHONY: clean, realclean

#desactivation regles implicites
.SUFFIXES:

#variables
CXX = g++
DEBUG = yes
EXEC = app2

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
 
app2: main.o 
	$(CXX) $^ -o $(EXEC)
 
main.o: main.cpp

%.o: %.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

clean:
	rm -rf *.o rm -rf *.bak

realclean: clean
	rm -rf app1
