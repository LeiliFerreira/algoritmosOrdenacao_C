#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

void mergesort(int *vetor, int n);
void sort(int *vetor, int *c, int i, int f);
void merge(int *vetor, int *c, int i, int m, int f);

void medeTempoExecucao() {
  clock_t tempo;
  tempo = clock();
  tempo = clock() - tempo;
  printf("\n\nO tempo de execução do programa foi de %f milissegundos.\n", ((float)tempo)/CLOCKS_PER_SEC);
}
 
void gerarVetor(int *vetor) {
  int i = 0;
  for(i = 0; i < 1000; i++) {
vetor[i] = rand()%10000;
}
}

void selectSort(int *vetor) {
  int i;
  int j;
  int aux;

    for(i = 0; i < 1000; i++) {
    vetor[i] = vetor[i] + 1;

}

for(i = 0; i < 1000; i++) {
for (j = i+ 1; j < 1000; j++) {
if(vetor[i] > vetor[j]) {
aux = vetor[i];
vetor[i] = vetor[j];
vetor[j] = aux;
}
}
}
  printf("\nVetor ordenado com o algoritmo Select Sort:  \n\n");
for(i = 0; i < 1000; i++) {
printf("%d ", vetor[i]);
}

  medeTempoExecucao();
 
}

void insertSort(int *vetor) {
 
  int i = 0;
  int j = 0;
  int num_atual;

  for(i = 1; i < 1000; i++)
   {
    num_atual = vetor[i];
    j = i - 1;
       
    while((j >= 0) && (num_atual < vetor[j]))
    {
      vetor[j+1] = vetor[j];
      j--;
    }
    vetor[j+1] = num_atual;
   }

    printf("\nVetor ordenado com o algoritmo Insert Sort: \n\n");
 
    for(i = 0; i < 1000; i++)
        printf("%d ", vetor[i]);

  medeTempoExecucao();
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
 
void heapify(int *vetor, int n, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;
 
  if (left < n && vetor[left] > vetor[largest])
  largest = left;
 
  if (right < n && vetor[right] > vetor[largest])
  largest = right;
 
  if (largest != i) {
    swap(&vetor[i], &vetor[largest]);
    heapify(vetor, n, largest);
    }
  }

void heapSort(int *vetor, int n) {

  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(vetor, n, i);
 
  for (int i = n - 1; i >= 0; i--) {
    swap(&vetor[0], &vetor[i]);
 
  heapify(vetor, i, 0);
}

  printf("\nVetor ordenado com o algoritmo Heap Sort:\n\n ");
 
  for (int i = 0; i < n; ++i)
      printf("%d ", vetor[i]);
      printf("\n");
 
  medeTempoExecucao();
 
}

void mergesort(int *vetor, int n) {
  int i;
 
  int *c = malloc(sizeof(int) * n);
  sort(vetor, c, 0, n - 1);

  printf("\nVetor ordenado com o algoritmo Merge Sort:\n\n ");
 
  for (i = 0; i < 1000; i++) printf("%d ", vetor[i]);

  free(c);

  medeTempoExecucao();

 
}

void sort(int *vetor, int *c, int i, int f) {
  if (i >= f) return;

  int m = (i + f) / 2;

  sort(vetor, c, i, m);
  sort(vetor, c, m + 1, f);

  if (vetor[m] <= vetor[m + 1]) return;

  merge(vetor, c, i, m, f);
}

void merge(int *vetor, int *c, int i, int m, int f) {
  int z,
      iv = i, ic = m + 1;

  for (z = i; z <= f; z++) c[z] = vetor[z];

  z = i;

  while (iv <= m && ic <= f) {

    if (c[iv] <= c[ic]) vetor[z++] = c[iv++];
    else vetor[z++] = c[ic++];
  }

  while (iv <= m) vetor[z++] = c[iv++];

  while (ic <= f) vetor[z++] = c[ic++];
}

int particiona_random(int *vetor, int inicio, int fim) {
int indice_pivo = (rand() % (fim - inicio + 1)) + inicio;
troca(vetor, indice_pivo, fim);
return particiona(vetor, inicio, fim);
}

int troca(int *vetor, int i, int j) {
int aux = vetor[i];
vetor[i] = vetor[j];
vetor[j] = aux;
}

int particiona(int *vetor, int inicio, int fim) {
int pivo, indice_pivo, i;

pivo = vetor[fim];
indice_pivo = inicio;

for(i = inicio; i < fim; i++) {
if(vetor[i] <= pivo){
troca(vetor, i, indice_pivo);
indice_pivo++;
}
}

troca(vetor, indice_pivo, fim);
return indice_pivo;
}

void quicksort(int *vetor, int inicio, int fim) {
if(inicio < fim) {
int indice_pivo = particiona_random(vetor, inicio, fim);
quicksort(vetor, inicio, indice_pivo - 1);
quicksort(vetor, indice_pivo + 1, fim);

    }
 
}


int main() {
  setlocale(LC_ALL,"Portuguese");

srand(time(NULL));
  int vetor[1000];
  gerarVetor(vetor);

  int n = sizeof(vetor) / sizeof(vetor[0]);

  int tam_vet = sizeof(vetor) / sizeof(int);


int i;

  int opcaoUsuario;
  int voltarMenu;


  printf("\n--------------MENU---------------\n");
  printf("| 1 - Select Sort                |\n");
  printf("| 2 - Insert Sort                |\n");
  printf("| 3 - Merge Sort                 |\n");
  printf("| 4 - Heap Sort                  |\n");
  printf("| 5 - Quick Sort                 |\n");
  printf("| 6 - Sair                       |\n");
  printf("---------------------------------");
  printf("\n\nUm vetor com 1000 números aleatórios entre 0 e 10000 foi gerado,escolha uma das opções acima para ordená-lo: ");
  scanf("%d", &opcaoUsuario);

  switch(opcaoUsuario) {
   
    case 1:
      selectSort(vetor);
     
      printf("\nDigite 0 para voltar ao menu: ");
      scanf("%d", &voltarMenu);

      while(voltarMenu != 0) {
        printf("\nOpção Inválida!");
        printf("\n\nDigite 0 para voltar ao menu: ");
        scanf("%d", &voltarMenu);
        }
    if(voltarMenu == 0) {
          return main();
      }  
      break;

    case 2:
      insertSort(vetor);

      printf("\n\nDigite 0 para voltar ao menu: ");
      scanf("%d", &voltarMenu);

      while(voltarMenu != 0) {
        printf("\nOpção Inválida!");
        printf("\n\nDigite 0 para voltar ao menu: ");
        scanf("%d", &voltarMenu);
        }
    if(voltarMenu == 0) {
          return main();
      }  
      break;

    case 3:
      mergesort(vetor, 1000);

      printf("\nDigite 0 para voltar ao menu: ");
      scanf("%d", &voltarMenu);

      while(voltarMenu != 0) {
        printf("\nOpção Inválida!");
        printf("\n\nDigite 0 para voltar ao menu: ");
        scanf("%d", &voltarMenu);
        }
    if(voltarMenu == 0) {
          return main();
      }  
      break;

    case 4:
      heapSort(vetor, n);

      printf("\nDigite 0 para voltar ao menu: ");
      scanf("%d", &voltarMenu);

      while(voltarMenu != 0) {
        printf("\nOpção Inválida!");
        printf("\n\nDigite 0 para voltar ao menu: ");
        scanf("%d", &voltarMenu);
        }
    if(voltarMenu == 0) {
          return main();
      }  
     
      break;
   
    case 5:
      quicksort(&vetor, 0, tam_vet - 1); // chamada do
     
      printf("\nVetor ordenado com o algoritmo Quick Sort: \n\n");
      for(i = 0; i < tam_vet; i++){
        printf("%d ", vetor[i]);
      }
      printf("\n");
      medeTempoExecucao();

      printf("\nDigite 0 para voltar ao menu: ");
      scanf("%d", &voltarMenu);

      while(voltarMenu != 0) {
        printf("\nOpção Inválida!");
        printf("\n\nDigite 0 para voltar ao menu: ");
        scanf("%d", &voltarMenu);
        }
    if(voltarMenu == 0) {
          return main();
      }  
      break;
   
    case 6:
      printf("\nVOCÊ SAIU!");
      break;
   
    default:
      printf("\nOpção inválida!\n");
      return main();
     
  }
}
