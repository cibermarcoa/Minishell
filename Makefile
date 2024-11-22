# Nombre del ejecutable
TARGET = minishell

# Archivos fuente
SRC = minishell.c

# Archivos de cabecera
HEADERS = parser.h

# Bibliotecas
LIBS = libparser.a

# Opciones del compilador
CFLAGS = -static

# Comando de compilación
CC = gcc

# Regla principal
all: $(TARGET)

# Compilación del ejecutable
$(TARGET): $(SRC) $(HEADERS) $(LIBS)
	$(CC) $(CFLAGS) $(SRC) $(LIBS) -o $(TARGET)

# Limpieza de archivos generados
clean:
	rm -f $(TARGET)

# Regla para remake
re: clean all
