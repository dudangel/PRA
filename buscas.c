#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define VALIDO 1
#define INVALIDO 0

//testes e comparações??

void init_vetor(int *vetor, int tam){
    int i, j;
    int status;
    srand(time(NULL)); 

    printf("Preenchendo o vetor...\n");
    for(i = 0; i < tam; i++){
        do{
            vetor[i] = rand() % 200; //Gera valores entre 0 e 199, ou seja, tem 50% de chance do valor estar no vetor
            status = VALIDO;
            for(j = 0; j < i; j++){
                if(vetor[i] == vetor[j]){
                    status = INVALIDO;
                }
            }
        }while(status == INVALIDO);

    }
}

int busca_seq(int chave, int *vetor, int tam){
    int i;
    int cont_comparacao = 0;
    int cont_teste = 0;
    int cont_atribuicao =0;
    
    for(i = 0; i <= tam; i++){
        cont_atribuicao++;
        cont_comparacao++; //É teste ou compração ???!!!!!
        if(vetor[i] == chave){ 
            printf("Comparação: %d, Teste: %d, Atribuição: %d\n", cont_comparacao, cont_teste, cont_atribuicao);
            return i;
        }
    }
    
    printf("Comparação: %d, Teste: %d, Atribuição: %d\n", cont_comparacao, cont_teste, cont_atribuicao);

    return -1;
}


int busca_seq_sentinela(int chave, int *vetor, int tam){
    int i = 0;
    int n;
    int cont_comparacao = 0;
    int cont_teste = 0;
    int cont_atribuicao =0;
    vetor[tam] = chave; //Utima posição do vetor possui o sentinela
    cont_atribuicao++;

    while(vetor[i] != chave){
        cont_comparacao++;
        i++;
        cont_atribuicao++;
    }

    cont_comparacao++;
    if(i < n){
        printf("Comparação: %d, Teste: %d, Atribuição: %d\n", cont_comparacao, cont_teste, cont_atribuicao);
        return i;
    } 

    printf("Comparação: %d, Teste: %d, Atribuição: %d\n", cont_comparacao, cont_teste, cont_atribuicao);

    return -1;
}

//Caracteristica do bubble: Dois laços de repetição alinhados
int bubble(int *vetor, int tam){
    int i, j;
    int aux = 0;

    for(i = 0; i < tam; i++){
        for(j = i + 1; j < tam; j++){
            if(vetor[j] < vetor[i]){
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }      
        }
    }
}

int pesquisa_bin(int chave, int *vetor, int tam){
    int i, meio, ini, fim;
    ini = 0;
    fim = tam - 1;

    int cont_comparacao = 0;
    int cont_teste = 0;
    int cont_atribuicao = 2;

    //Ordena o vetor
    bubble(vetor, tam);

    //printa o vetor ordenado
    for(i = 0; i < tam; i++){
        printf("%d\n", vetor[i]);
    }
    printf("\n");

    while(ini <= fim){
        cont_comparacao++;
        meio = (fim + ini) / 2;
        cont_atribuicao++;

        cont_comparacao++;
        if(vetor[meio] == chave){
            printf("Comparação: %d, Teste: %d, Atribuição: %d\n", cont_comparacao, cont_teste, cont_atribuicao);
            return meio;
        }

        cont_comparacao++;
        if(chave > vetor[meio]){
            ini = meio + 1;
            cont_atribuicao++;
        }

        cont_comparacao++;
        if(chave < vetor[meio]){
            fim = meio - 1;
            cont_atribuicao++;
        }

    }

    printf("Comparação: %d, Teste: %d, Atribuição: %d\n", cont_comparacao, cont_teste, cont_atribuicao);

    return -1;
}

int busca_interpolacao(int chave, int *vetor, int tam){
    int init = 0;
    int mid;
    int end = tam - 1;

    int cont_comparacao = 0;
    int cont_teste = 0;
    int cont_atribuicao = 2;

     //Ordena o vetor
    bubble(vetor, tam);

    while(init <= end){
        cont_comparacao++;
        //Igual a busca binaria, porem usa essa equação de meio, de forma a otimizar o processo caso o vetor já esteja ordenado
        mid = init + ((end - init) * (chave - vetor[init])) / (vetor[end] - vetor[init]);
        cont_atribuicao++;

        cont_comparacao++;
        if(chave < vetor[mid]){
            end = mid - 1;
            cont_atribuicao++;
        }else{ 
            cont_comparacao++;
            if(chave > vetor[mid]){
                init = mid + 1;
                cont_atribuicao++;
            }else{
                printf("Comparação: %d, Teste: %d, Atribuição: %d\n", cont_comparacao, cont_teste, cont_atribuicao);
                return mid;
            }
        }
    }

    printf("Comparação: %d, Teste: %d, Atribuição: %d\n", cont_comparacao, cont_teste, cont_atribuicao);

    return -1;
}

int main(){
    int i;
    int tam;
    int chave;
    int pos;
    int *vetor;
    int option = 0;
    int cont_teste = 0;
    while(option != 5){
        cont_teste++;
        printf("/***********************/ \n");
        srand(time(NULL));

        tam = 1 + (rand() % (100)); 
        printf("Tamanho do vetor: %d\n", tam);

        vetor = malloc(sizeof (int) * tam);

        init_vetor(vetor, tam);

        for(i = 0; i < tam; i++){
            printf("%d\n", vetor[i]);
        }

        printf("Chave que deseja buscar:");
        scanf("%d", &chave);

        printf("Escolha uma opção: \n");
        printf("1 - Busca sequencial \n");
        printf("2 - Busca sequencial com sentinela \n");
        printf("3 - Busca binária \n");
        printf("4 - Busca por interpolação \n");
        printf("5 - Sair\n");
        printf("\n");

        scanf("%d", &option);

        switch (option){
        case 1:
            /* Busca sequencial */
            pos = busca_seq(chave, vetor, tam);

            if(pos != -1){
                printf("Sucesso! Chave na posição %d\n", pos + 1);
            }else{
                printf("Nada foi encontrado!\n");
            }

            break;

        case 2:
            /* Busca sequencial com sentinela */
            pos = busca_seq_sentinela(chave, vetor, tam);  

            if(pos != -1){
                printf("Sucesso! Chave na posição %d\n", pos + 1);
            }else{
                printf("Nada foi encontrado!\n");
            }  

            break;

        case 3:
            /* Busca binária */
            pos = pesquisa_bin(chave, vetor, tam);

            if(pos != -1){
                printf("Sucesso! Chave na posição %d\n", pos + 1);
            }else{
                printf("Nada foi encontrado!\n");
            } 

            break;

        case 4:
            /* Busca por interpolação */
            pos = busca_interpolacao(chave, vetor, tam);

            if(pos != -1){
                printf("Sucesso! Chave na posição %d\n", pos + 1);
            }else{
                printf("Nada foi encontrado!\n");
            } 

            break;
        
        case 5:
            printf("Nro de testes: %d\n", cont_teste-1);
            break;

        default:
            printf("Entrada inválida!\n");
            break;
        }
        
        free(vetor);  
    }

    return 0;
}