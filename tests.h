#ifndef TESTS_H
#define TESTS_H

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "lsd.h"
#include "kmp.h"
#include "germin.h"
#include "ordem.h"


/**
 * Teste para as funções inserir e imprimir
 * Utiliza o exemplo no protocolo, tal como maior parte destes testes
 */
void testInsertPrint();

/**
 * Teste para a função remover
 */
void testRemove();

/**
 * Teste para a ordenação por ordem alfabética
 */
void testLSDsort();

/**
 * Teste para a pesquisa de strings, importante para a funcionalidade principal
 */
void testKMP();

/**
 * Teste da funcionalidade principal, a germinação de strings
 */
void testGermin();

/**
 * Testar a escrita no ficheiro; normal e binário
 * inicializa uma matriz e escreve-a no ficheiro pela função writeStringsToFile()
 */
void testWriteToFile();

/**
 * Teste para ler as strings no ficheiro
 * Utiliza o teste anterior para escrever strings no ficheiro, depois lÊ-as e imprime-as na consola
 */
void testReadFromFile();

/**
 * Teste para a leitura do ficheiro binário
 */
void testReadFromBinaryFile();

/**
 * Teste da ordenação por tamanhos
 */
void ordemt();

/**
 * Teste da inserção das listas ligadas
 */
void testInsertNodeIntoList();

/**
 * Teste para inserir nós numa dada posição da lista ligada
 */
void testInsertNodeIntoPosition();

#endif //TESTS_H
