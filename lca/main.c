#include "LCA.h"

int main() {
  int i;
  int id_a, id_b;
  // Guarda o id do LCA entre id_a e id_b.
  int id_lca;
  // Numero de consultas a serem realizadas
  int num_consultas;
  // Um vetor de funcionarios.
  Funcionario* funcionarios;

  printf("Insira o numero de funcionarios na empresa:\n");
  scanf(" %d", &n);

  // Reserva o espaco necessário.
  ids_disponiveis = malloc(n * sizeof(int));
  map_id_to_idx = malloc(n * sizeof(int));
  superior = malloc(n * sizeof(int));
  for (i = 0; i < n; i++) {
    ids_disponiveis[i] = DISPONIVEL;
    superior[i] = NINGUEM;
  }
  funcionarios = malloc(n * sizeof(Funcionario));

  printf("Insira o dado dos %d funcionarios:\n", n);
  for (i = 0; i < n; i++) {
    CriaFuncionario(i, &funcionarios[i]);
  }

  printf("Insira as %d relacoes entre os funcionarios.", n - 1);
  printf("Indicando um id do subordinado e o id do superior dessa pessoa:\n");
  for (i = 0; i < n - 1; i++) {
    scanf("%d %d", &id_a, &id_b);
    // map_id_to_idx[id_a] ira resgatar qual e' a posicao do id_a no
    // vetor de funcionarios para podermos entao setar o valor do superior dele.
    funcionarios[map_id_to_idx[id_a]].id_superior = id_b;
    // Indica que o superior de id_a e' id_b.
    superior[id_a] = id_b;
  }

  printf("Digite quantas consultas deseja fazer:\n");
  scanf("%d", &num_consultas);
  for (i = 0; i < num_consultas; i++) {
    printf("\nDigite o id dos dois funcionarios:");
    scanf("%d %d", &id_a, &id_b);
    id_lca = LCA(id_a, id_b);
    if (id_lca == NINGUEM) {
      printf("ERRO!\n");
    } else {
      ImprimeFuncionario(funcionarios[map_id_to_idx[id_lca]]);
    }
  }
  return 0;
}
