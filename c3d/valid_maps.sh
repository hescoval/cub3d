#!/bin/bash

# Nome do programa
NAME="cub3d"

# Diretório dos mapas
MAP_DIR="maps/valid"

# Cores
GREEN='\033[1;32m'
RED='\033[5;31m'
NC='\033[0m'

# Verifica se o diretório de mapas existe
if [ ! -d "$MAP_DIR" ]; then
  echo "Diretório $MAP_DIR não encontrado!"
  exit 1
fi

# Itera sobre todos os arquivos .cub no diretório de mapas
for map in "$MAP_DIR"/*.cub; do
  if [ -f "$map" ]; then
    echo "Executando Valgrind no mapa: $map"
    valgrind_output=$(mktemp) # Cria um arquivo temporário para armazenar a saída do Valgrind
    valgrind --leak-check=full ./$NAME "$map" &> "$valgrind_output" # Redireciona a saída do Valgrind para o arquivo temporário
    if grep -q "All heap blocks were freed -- no leaks are possible" "$valgrind_output"; then
      echo -e "${GREEN}All the mallocs were freed for: $map${NC}"
    else
      echo -e "${RED}There were memory leaks on the: $map${NC}"
    fi
    rm "$valgrind_output" # Remove o arquivo temporário
  fi
done