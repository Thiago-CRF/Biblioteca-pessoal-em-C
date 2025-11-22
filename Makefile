# nome do executavel final
TARGET = biblioteca

# compilador
CC = gcc

# flags de compilação
CFLAGS = -Wall -Wextra -Iinclude

# diretórios
SRC_DIR = src
OBJ_DIR = obj

# lista dos arquivos .c em /src
SRC = $(wildcard $(SRC_DIR)/*.c)

# gera os .obj correspondentes dentro de /obj
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# regra padrão (executa primeiro)
all: $(TARGET)

# regra para gerar o executavel
$(TARGET): $(OBJ)
	@echo "ligando objetos e criando executavel..."
	$(CC) $(OBJ) -o $(TARGET)

# regra para compilar cada .c em .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "compilando $<..."
	$(CC) $(CFLAGS) -c $< -o $@

# cria diretório obj se não existir
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

#limpa os arquivos compilados
clean:
	@echo "limpando a compilacao..."
	rm -rf $(OBJ_DIR) $(TARGET)

# executa o programa
run: all
	./$(TARGET)
