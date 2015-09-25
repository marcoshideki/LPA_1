#include <stdio.h>
#include <stdlib.h>

int* closestPair(int *vet, int tam); // exec 1
int* elementUniqueness(int *vet, int tam); // exec 2
int frequencyDistribution(int *vet, int tam); // exec 3
void ordenaVetor(int *vet, int esquerdo, int direito);

int main(int argc, char *argv[])
{
  int tam, i;
  printf("Forneca o tamanho do vetor ");
  scanf("%d", &tam);
  int vet[tam], * par, * unico, maiorFrequencia;
  
  for (i=0;i<tam;i++){
      printf("Forneca o valor da %d posicao ", i+1);
      scanf("%d", &vet[i]);
  }
  
  ordenaVetor(vet, 0, tam-1);

  par = closestPair(vet, tam);  // exec 1
  /*printf("\n");
  for (i=0;i<2;i++){
      printf("%d  ",par[i]);
  }*/
  
  unico = elementUniqueness(vet, tam); // exec 2
  /*printf("\n");
  for (i=0;i<tam;i++){
      printf("%d  ",unico[i]);
  }*/
  
  maiorFrequencia = frequencyDistribution(vet, tam); //exec 3    
  //printf("%d",maiorFrequencia);
  
  system("PAUSE");	
  return 0;
}

int* elementUniqueness(int *vet, int tam){ // exec 2
     int i, j, aux = 0;
     for(i=0;i<tam;i++){
         if(vet[i] == vet [i+1])
             aux++;                   
     }
     int * unico = (int *) malloc ((tam-aux) * sizeof(int));
     for(i = 0, j = 0; i < tam ; i++, j++){
         unico[j] = vet[i];
         if(vet[i] == vet [i+1]){
             i++;
         }                   
     }
     return unico;
}


int * closestPair(int vet[], int tam){ // exec 1
     int i, dif;
     int * par = (int*) malloc(2 * sizeof(int));
     if(tam > 1){
       dif = abs(vet[1] - vet[0]);
       par[0] = vet[0];
       par[1] = vet[1];
       for(i=1;i<tam-1;i++){
          if(abs(vet[i+1]-vet[i]) < dif){
            dif = abs(vet[i+1]-vet[i]);
            par[0] = vet[i];
            par[1] = vet[i+1];
          }            
       }
     } else { 
        par[0] = vet[0];
        par[1] = '0';
     }
     
     return par;
}


int frequencyDistribution(int *vet, int tam){ // exec 3
    int i, j, maior, posicao;
    int * asd = (int *) malloc(tam * sizeof(int));
    for(i = 0 ; i < tam ; i++)
       asd[i] = 0;
    
    for(i = 0 , j == 1; i < tam ; j++){
          if(vet[i] == vet[j]){
            asd[i]++;
          } else {
            i = j;
          }     
    }
    
    maior = asd[0];
    posicao  = 0;
    for(i = 1 ; i < tam ; i++){
          if(asd[i] > maior){
                posicao = i;    
          }      
    }
    
    return vet[posicao];
}

void ordenaVetor(int *vet, int esquerda, int direita) { 
    int i, j, x, y;
     
    i = esquerda;
    j = direita;
    x = vet[(esquerda + direita) / 2];
     
    while(i <= j) {
        while(vet[i] < x && i < direita) {
            i++;
        }
        while(vet[j] > x && j > esquerda) {
            j--;
        }
        if(i <= j) {
            y = vet[i];
            vet[i] = vet[j];
            vet[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > esquerda) {
        ordenaVetor(vet, esquerda, j);
    }
    if(i < direita) {
        ordenaVetor(vet, i, direita);
    }

}
