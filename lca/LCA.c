#include "LCA.h"

void CriaFuncionarioId(Funcionario* funcionario) {
  int i;
  int soma;
  int m;
  int id;
  soma = 0;
  m = strlen(funcionario->nome);
  for (i = 0; i < m; i++) {
    soma += funcionario->nome[i];
  }
  soma += funcionario->cargo;
  id = soma % n;
  while (ids_disponiveis[id] == 0) {
    id = (id + 1) % n;
  }
  ids_disponiveis[id] = 0;
  funcionario->id = id;
}

void CriaFuncionario(int idx, Funcionario* funcionario) {
  printf("Digite o nome:\n");
  scanf(" %[^\n]s", funcionario->nome);

  printf("Digite o cargo:\n");
  scanf(" %u", &funcionario->cargo);

  CriaFuncionarioId(funcionario);

  printf("=====================================================\n");
  printf("O id de %s e': %d\n", funcionario->nome, funcionario->id);
  printf("=====================================================\n");
  map_id_to_idx[funcionario->id] = idx;
}

void ImprimeFuncionario(Funcionario funcionario) {

  printf("==============================\n");
  printf("Nome: %s\n", funcionario.nome);
  printf("Cargo: %d\n", funcionario.cargo);
  printf("==============================\n");
}

int LCA(int id_a, int id_b) {
  int i;
  int* caminho;
  caminho = malloc(n * sizeof(int));
  for (i = 0; i < n; i++) {
    caminho[i] = 0;
  }
  while (id_a != -1) {
    caminho[id_a] = 1;
    id_a = superior[id_a];
  }
  while (id_b != -1) {
    if (caminho[id_b] == 1) return id_b;
    id_b = superior[id_b];
  }
  return -1;
}
