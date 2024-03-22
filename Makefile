# Compilador y opciones
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
LDFLAGS =

# Carpetas
SRCDIR = src
INCDIR = include
BINDIR = bin

# Archivos
SOURCES := $(wildcard $(SRCDIR)/*.cpp)
OBJECTS := $(patsubst $(SRCDIR)/%.cpp,$(BINDIR)/%.o,$(SOURCES))
EXECUTABLE = $(BINDIR)/programa

# Reglas de compilación
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(LDFLAGS) -o $@ $^

$(BINDIR)/%.o: $(SRCDIR)/%.cc
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c -o $@ $<

# Eliminar archivos intermedios
.PHONY: clean
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

