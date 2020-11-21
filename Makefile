################################################################################
## Fichero «Makefile» para los programas de la práctica 5:
## «datos-pruebas», «contar-usos» y «usos-por-usuario»
################################################################################

################################################################################
## Declaracion de variables del fichero «Makefile»

## DIRECTORIOS
SOURCE_DIR = src
BUILD_DIR = build
BIN_DIR = bin

VPATH = $(SOURCE_DIR) 

## COMPILADOR Y OPCIONES DE COMPILACIÓN:
CXX = g++
CXXFLAGS = -g -Wall -Wextra #-I$(JUEGO_VIDA_DIR)


## FICHEROS OBJETO (RESULTADOS INTERMEDIOS DE COMPILACIÓN):
JUEGO_VIDA_OBJECTS = $(addprefix $(BUILD_DIR)/, juego-vida-main.o juego-vida.o)
JUEGO_VIDA_TEST_OBJECTS = $(addprefix $(BUILD_DIR)/, juego-vida-test.o juego-vida.o)
BMP_OBJECTS = $(addprefix $(BUILD_DIR)/, imagen-bmp.o imagen-bmp-main.o )

################################################################################
## Reglas del fichero «Makefile»

complejos: $(SOURCE_DIR)/complejos.cpp | $(BIN_DIR)
	$(CXX) -g $(SOURCE_DIR)/complejos.cpp -o $(BIN_DIR)/$@

juego-vida: $(JUEGO_VIDA_OBJECTS) | $(BIN_DIR)
	$(CXX) -g $(JUEGO_VIDA_OBJECTS) -o $(BIN_DIR)/$@ 

juego-vida-test: $(JUEGO_VIDA_TEST_OBJECTS) | $(BIN_DIR)
	$(CXX) -g $(JUEGO_VIDA_TEST_OBJECTS) -o $(BIN_DIR)/$@ 

bmp: $(BMP_OBJECTS) | $(BIN_DIR)
	$(CXX) -g $(BMP_OBJECTS) -o $(BIN_DIR)/$@ 

$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@  

$(BUILD_DIR)/juego-vida-main.o: juego-vida.hpp
$(BUILD_DIR)/juego-vida.o: juego-vida.hpp
$(BUILD_DIR)/imagen-bmp.o: imagen-bmp.hpp
$(BUILD_DIR)/imagen-bmp-main.o: imagen-bmp.hpp

$(BIN_DIR):
	mkdir $(BIN_DIR)

$(BUILD_DIR):
	mkdir $(BUILD_DIR)
