# TP1 - Calculadora
## Introdução
Este programa foi desenvolvido durante um trabalho de estruturas de dados na UFMG. O problema proposto foi implementar um programa que recebe como argumento um arquivo de texto com uma ou mais expressões numéricas, que podem estar na notação infixa ou posfixa. O programa então deve ser capaz de validar a expressão recebida e armazená-la numa estrutura de dados apropriada, capaz de realizar conversões de uma notação para outra e solucionar a equação.

## Instruções para compilação e execução

O programa requer os arquivos de entrada na pasta bin.

Basta escrever no terminal “make all” que será compilado o programa e gerado os arquivos .o na pasta “obj” e um executável na pasta “bin”. Caso deseje testar entradas diferentes das que já estão lá, é necessário adicionar um arquivo de entrada na pasta bin e adicionar o comando de execução no Makefile no modelo:

$(EXE) $(BIN)/entrada

Sendo que:
1- $(EXE) é o executável
2- $(BIN) é o endereço da pasta bin
3- “entrada” é o nome do arquivo de texto fornecido

Para limpeza dos arquivos objetos e do .run, basta escrever “make clean” no terminal.
