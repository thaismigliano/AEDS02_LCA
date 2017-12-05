#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Valor usado para indicar o superior de um funcionario.
#define NINGUEM -1

#define OCUPADO 0
#define DISPONIVEL 1

#define NAO_ESTA_NO_CAMINHO 0
#define ESTA_NO_CAMINHO 1

// Indica quais s�o os cargos na empresa.
enum cargos {
  PRESIDENTE = 1,
  DIRETOR = 2,
  GERENTE = 3,
  ANALISTA = 4,
  ENGENHEIRO = 5,
};

typedef struct {
  // Id do funcion�rio criado automaticamente a partir de um hash
  // do nome e cargo.
  int id;
  // Nome do funcion�rio.
  char nome[100];
  // Qual � o cargo do superior.
  enum cargos cargo;
  // Indica qual � o id do superior.
  int id_superior;
} Funcionario;

// Indica quantos funcion�rios tem na empresa.
int n;
// Indica quais sao os ids dispon�veis. Inicialmente, todos os valores
// sao 1.
int* ids_disponiveis;
// Mapeia o id para o indice no vetor de funcionarios.
int* map_id_to_idx;
// Vetor indicando quem e' o superior de cada funcionario.
int* superior;

void CriaFuncionario(int idx, Funcionario* funcionario);
void ImprimeFuncionario(Funcionario funcionario);
// Dado o indice de dois funcionarios, calcula o LCA deles.
int LCA(int id_a, int id_b);
