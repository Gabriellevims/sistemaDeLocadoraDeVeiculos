#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF); 

}

// usem essa função para limparBuffer, pesquise quando usar ele ou 
// fgets(livros[i].nome, sizeof(livros[i].nome), stdin); livros[i].nome[strcspn(livros[i].nome, "\n")] = '\0'; para limpar de string

struct Veiculo {
    int codigo;
    char modelo[40];
    char marca[40];
    int ano;
    float valorDiaria; 
    int situacao;      
};

struct Cliente {
    int codigo;
    char nome[50];
    char telefone[15];
};

typedef struct Veiculo *pVeiculo;
typedef struct Cliente *pCliente;

pVeiculo alocarVeiculos(int quantidadeVeiculos);
pCliente alocarClientes(int quantidadeClientes);
void desalocarMemoria(pCliente listaClientes, pVeiculo frotaVeiculos);

void cadastrarVeiculo(pVeiculo frotaVeiculos, int quantidadeVeiculos);
void consultarVeiculo(pVeiculo frotaVeiculos, int quantidadeVeiculos);
void cadastrarCliente(pCliente listaClientes, int quantidadeClientes);
void listarVeiculos(pVeiculo frotaVeiculos, int quantidadeVeiculos);
void realizarLocacao(pVeiculo frotaVeiculos, int quantidadeVeiculos, pCliente listaClientes, int quantidadeClientes);
float calcularLocacao(float valorDiaria, int quantidadeDias); 
void devolverVeiculo(pVeiculo frotaVeiculos, int quantidadeVeiculos);


int main() {
    pVeiculo frotaVeiculos = NULL;
    pCliente listaClientes = NULL;
    
    int quantidadeVeiculos = 0;
    int quantidadeClientes = 0;
    int opcaoMenu = -1;

    do {
        printf("\n--- MENU DO SISTEMA DE LOCADORA ---\n");
        printf("1 - Cadastrar Veiculo\n");
        printf("2 - Consultar Veiculo\n");
        printf("3 - Cadastrar Cliente\n");
        printf("4 - Listar Veiculos\n");
        printf("5 - Realizar Locacao\n");
        printf("6 - Calcular Locacao\n"); // dexei ai so para fazer teste isolado qualquer coisa
        printf("7 - Devolver Veiculo\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcaoMenu);
        limparBuffer(); // Limpando o buffer

        switch (opcaoMenu) {
            case 1:
                if (frotaVeiculos != NULL) {
                    printf("\nOs dados antigos dos veiculos serão PERDIDOS ao realizar uma nova inserção de dados!\n");
                    free(frotaVeiculos); 
                }
                printf("Quantos veiculos deseja cadastrar? ");
                scanf("%d", &quantidadeVeiculos);
                limparBuffer(); // Limpando o buffer 
                
                frotaVeiculos = alocarVeiculos(quantidadeVeiculos);
                printf("Criado com sucesso no armazenamento para %d veiculo(s).\n", quantidadeVeiculos); // podem remover isso aqui, é mais visual para a gente saber que seu certo 
                
                // cadastrarVeiculo(frotaVeiculos, quantidadeVeiculos);
                break;

            case 2:
                // consultarVeiculo(frotaVeiculos, quantidadeVeiculos);
                break;

            case 3:
                if (listaClientes != NULL) {
                    printf("\nOs dados antigos dos clientes serao PERDIDOS ao realizar uma nova inserção de dados!\n");
                    free(listaClientes);
                }
                printf("Quantos clientes deseja cadastrar? ");
                scanf("%d", &quantidadeClientes);
                limparBuffer(); // Limpando o buffer
                
                listaClientes = alocarClientes(quantidadeClientes);
                printf("Criado com sucesso no armazenamento para %d cliente(s).\n", quantidadeClientes); // podem remover isso aqui, é mais visual para a gente saber que seu certo 
                
                // cadastrarCliente(listaClientes, quantidadeClientes);
                break;

            case 4:
                // listarVeiculos(frotaVeiculos, quantidadeVeiculos);
                break;

            case 5:
                // realizarLocacao(frotaVeiculos, quantidadeVeiculos, listaClientes, quantidadeClientes);
                break;
                
            case 6:
                // case para teste de calcularLocacao
                break;

            case 7:
                // devolverVeiculo(frotaVeiculos, quantidadeVeiculos);
                break;

            case 0:
                printf("\nSaindo do sistema e limpando o armazenamento\n");
                break;

            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while (opcaoMenu != 0);

    desalocarMemoria(listaClientes, frotaVeiculos);

    return 0;
}

pVeiculo alocarVeiculos(int quantidadeVeiculos) {
    pVeiculo v = (pVeiculo) malloc(quantidadeVeiculos * sizeof(struct Veiculo));
    if (v == NULL) {
        printf("\nFalha ao alocar memoria para veiculos!\n");
        exit(1);
    }
    return v;
}

pCliente alocarClientes(int quantidadeClientes) {
    pCliente c = (pCliente) malloc(quantidadeClientes * sizeof(struct Cliente));
    if (c == NULL) {
        printf("\nFalha ao alocar memoria para clientes!\n");
        exit(1);
    }
    return c;
}

void desalocarMemoria(pCliente listaClientes, pVeiculo frotaVeiculos) {
    if (listaClientes != NULL) {
        free(listaClientes);
    }
    if (frotaVeiculos != NULL) {
        free(frotaVeiculos);
    }
}


void cadastrarVeiculo(pVeiculo frotaVeiculos, int quantidadeVeiculos) {
    
}

void consultarVeiculo(pVeiculo frotaVeiculos, int quantidadeVeiculos) {
    
}

void cadastrarCliente(pCliente listaClientes, int quantidadeClientes) {
    
}

void listarVeiculos(pVeiculo frotaVeiculos, int quantidadeVeiculos) {
    
}

void realizarLocacao(pVeiculo frotaVeiculos, int quantidadeVeiculos, pCliente listaClientes, int quantidadeClientes) {
    //chamar calcularLocacao() aqui 
}

float calcularLocacao(float valorDiaria, int quantidadeDias) {
    
    return 0.0; 
}

void devolverVeiculo(pVeiculo frotaVeiculos, int quantidadeVeiculos) {
    
}
