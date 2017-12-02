#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Indica quais são os cargos na empresa.
enum cargos {
  PRESIDENTE = 1,
  DIRETOR = 2,
  GERENTE = 3,
  ANALISTA = 4,
  ENGENHEIRO = 5,
};

typedef struct {
  // Id do funcionário criado automaticamente a partir de um hash
  // do nome e cargo.
  int id;
  // Nome do funcionário.
  char nome[100];
  // Qual é o cargo do superior.
  enum cargos cargo;
  // Indica qual é o id do superior.
  int id_superior;
} Funcionario;

// Indica quantos funcionários tem na empresa.
int n;
// Indica quais são os ids disponíveis.
int* ids_disponiveis;
// Mapeia o id para o indice no vetor de funcionarios.
int* map_id_to_idx;
// Vetor indicando quem e' o superior de cada um.
int* superior;

void CriaFuncionario(int idx, Funcionario* funcionario);
void ImprimeFuncionario(Funcionario* funcionario);
// Dado o indice de dois funcionarios, calcula o LCA deles.
int LCA(int id_a, int id_b);
