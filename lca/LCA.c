#include "LCA.h"

// Funcao hash que mapeia o nome + cargo de um funcionario para um
// id de 0 a n - 1, caso este id ja tenha sido ocupado, busca o proximo
// id disponivel.
void CriaFuncionarioId(Funcionario* funcionario) {
  int i;
  int soma;
  int m;
  int id;
  soma = 0;
  m = strlen(funcionario->nome);
  // Considera-se a soma das letras do nome usando o valor da tabela ASCII.
  for (i = 0; i < m; i++) {
    soma += funcionario->nome[i];
  }
  // Soma o valor do cargo e pega o resto por n.
  soma += funcionario->cargo;
  id = soma % n;
  // Se esse id ja estiver ocupado, busca o proximo id disponivel. Desta
  // forma garantimos um hash perfeito.
  while (ids_disponiveis[id] == OCUPADO) {
    id = (id + 1) % n;
  }
  // Marca este novo id como ocupado e seta o id do funcionario.
  ids_disponiveis[id] = OCUPADO;
  funcionario->id = id;
}

// Le os dados de um funcionario da posicao idx.
void CriaFuncionario(int idx, Funcionario* funcionario) {
  printf("Digite o nome:\n");
  scanf(" %[^\n]s", funcionario->nome);

  printf("Digite o cargo:\n");
  scanf(" %u", &funcionario->cargo);

  CriaFuncionarioId(funcionario);

  printf("=====================================================\n");
  printf("O id de %s e': %d\n", funcionario->nome, funcionario->id);
  printf("=====================================================\n");
  // Alimenta o map de id para idx.
  map_id_to_idx[funcionario->id] = idx;
}

void ImprimeFuncionario(Funcionario funcionario) {
  printf("==============================\n");
  printf("Nome: %s\n", funcionario.nome);
  printf("Cargo: %d\n", funcionario.cargo);
  printf("==============================\n");
}

// Complexidade O(N) de espaco e de tempo.
int LCA(int id_a, int id_b) {
  int i;
  // Um vetor que indica se o funcionario de id i esta no caminho de id_a
  // ate' a raiz ou nao.
  int* caminho;
  caminho = malloc(n * sizeof(int));
  for (i = 0; i < n; i++) {
    caminho[i] = NAO_ESTA_NO_CAMINHO;
  }
  // Enquanto nao chegar na raiz, preenche o caminho
  while (id_a != NINGUEM) {
    caminho[id_a] = ESTA_NO_CAMINHO;
    id_a = superior[id_a];
  }
  // Agora, repetindo a mesma ideia para o id_b, assim que acharmos
  // um elemento que esta no caminho, este sera' o LCA.
  while (id_b != NINGUEM) {
    if (caminho[id_b] == ESTA_NO_CAMINHO) return id_b;
    id_b = superior[id_b];
  }
  // Se nao achar nada, o que indica um erro, retornamos NINGUEM.
  return NINGUEM;
}
