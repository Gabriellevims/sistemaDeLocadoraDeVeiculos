#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void limparBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

// usem essa função para limparBuffer, pesquise quando usar ele ou
// fgets(livros[i].nome, sizeof(livros[i].nome), stdin); livros[i].nome[strcspn(livros[i].nome, "\n")] = '\0'; para limpar de string

struct Veiculo
{
    int codigo;
    char modelo[40];
    char marca[40];
    int ano;
    float valorDiaria;
    int situacao;
};

struct Cliente
{
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

int main()
{
    pVeiculo frotaVeiculos = NULL;
    pCliente listaClientes = NULL;

    int quantidadeVeiculos = 0;
    int quantidadeClientes = 0;
    int opcaoMenu = -1;

    do
    {
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

        switch (opcaoMenu)
        {
        case 1:
            if (frotaVeiculos != NULL)
            {
                printf("\nOs dados antigos dos veiculos serão PERDIDOS ao realizar uma nova inserção de dados!\n");
                free(frotaVeiculos);
            }
            printf("Quantos veiculos deseja cadastrar? ");
            scanf("%d", &quantidadeVeiculos);
            limparBuffer(); // Limpando o buffer

            frotaVeiculos = alocarVeiculos(quantidadeVeiculos);

            cadastrarVeiculo(frotaVeiculos, quantidadeVeiculos);

            break;

        case 2:
            consultarVeiculo(frotaVeiculos, quantidadeVeiculos);
            break;

        case 3:
            if (listaClientes != NULL)
            {
                printf("\nOs dados antigos dos clientes serao PERDIDOS ao realizar uma nova inserção de dados!\n");
                free(listaClientes);
            }
            printf("Quantos clientes deseja cadastrar? ");
            scanf("%d", &quantidadeClientes);
            limparBuffer(); // Limpando o buffer

            listaClientes = alocarClientes(quantidadeClientes);
            printf("Criado com sucesso no armazenamento para %d cliente(s).\n", quantidadeClientes); // podem remover isso aqui, é mais visual para a gente saber que seu certo

            cadastrarCliente(listaClientes, quantidadeClientes);
            break;

        case 4:
            listarVeiculos(frotaVeiculos, quantidadeVeiculos);
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

pVeiculo alocarVeiculos(int quantidadeVeiculos)
{
    pVeiculo v = (pVeiculo)malloc(quantidadeVeiculos * sizeof(struct Veiculo));
    if (v == NULL)
    {
        printf("\nFalha ao alocar memoria para veiculos!\n");
        exit(1);
    }
    return v;
}

pCliente alocarClientes(int quantidadeClientes)
{
    pCliente c = (pCliente)malloc(quantidadeClientes * sizeof(struct Cliente));
    if (c == NULL)
    {
        printf("\nFalha ao alocar memoria para clientes!\n");
        exit(1);
    }
    return c;
}

void desalocarMemoria(pCliente listaClientes, pVeiculo frotaVeiculos)
{
    if (listaClientes != NULL)
    {
        free(listaClientes);
    }
    if (frotaVeiculos != NULL)
    {
        free(frotaVeiculos);
    }
}

void cadastrarVeiculo(pVeiculo frotaVeiculos, int quantidadeVeiculos)
{
    for (int i = 0; i < quantidadeVeiculos; i++)
    {
        printf("\nVeiculo %d:", i + 1);

        printf("\nCodigo do Veiculo: ");
        scanf("%d", &frotaVeiculos[i].codigo);
        limparBuffer();

        printf("Modelo: ");
        fgets(frotaVeiculos[i].modelo, sizeof(frotaVeiculos[i].modelo), stdin);
        frotaVeiculos[i].modelo[strcspn(frotaVeiculos[i].modelo, "\n")] = '\0';

        printf("Marca: ");
        fgets(frotaVeiculos[i].marca, sizeof(frotaVeiculos[i].marca), stdin);
        frotaVeiculos[i].marca[strcspn(frotaVeiculos[i].marca, "\n")] = '\0';

        printf("Ano de Fabricacao: ");
        scanf("%d", &frotaVeiculos[i].ano);
        limparBuffer();

        printf("Valor da Diaria: ");
        scanf("%f", &frotaVeiculos[i].valorDiaria);
        limparBuffer();

        frotaVeiculos[i].situacao = 0; // por padrão os veículos são cadastrados com situação 0 = não alocado
    }
}

void consultarVeiculo(pVeiculo frotaVeiculos, int quantidadeVeiculos)
{
    int opcaoConsultarVeiculos;
    int codigoVeiculoConsulta;
    char modeloVeiculoConsulta[50];
    int achado = 0; // variavel que representa se algum carro foi achado ou não na consulta

    printf("\nConsultar Veiculos\n");
    printf("1 - Consultar por codigo\n");
    printf("2 - Consultar por modelo\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcaoConsultarVeiculos);
    limparBuffer();

    switch (opcaoConsultarVeiculos)
    {
    case 1:
        printf("\nCodigo do Veículo:");
        scanf("%d", &codigoVeiculoConsulta);
        limparBuffer();

        for (int i = 0; i < quantidadeVeiculos; i++)
        {
            if (frotaVeiculos[i].codigo == codigoVeiculoConsulta)
            {

                printf("Codigo: %d\n", frotaVeiculos[i].codigo);
                printf("Modelo: %s\n", frotaVeiculos[i].modelo);
                printf("Marca: %s\n", frotaVeiculos[i].marca);
                printf("Ano: %d\n", frotaVeiculos[i].ano);
                printf("Valor da Diaria: %.2f\n", frotaVeiculos[i].valorDiaria);
                if (frotaVeiculos[i].situacao == 0)
                {
                    printf("Situação: Não Alocado\n");
                }
                else if (frotaVeiculos[i].situacao == 1)
                {
                    printf("Situação: Alocado\n");
                }

                achado = 1;
            }
        }

        if (achado == 0)
        {
            printf("Nenhum Veículo Achado\n");
        }

        printf("Aperte enter para fechar: ");
        scanf("%*c");
        break;

    case 2:
        printf("\nModelo:");
        fgets(modeloVeiculoConsulta, sizeof(modeloVeiculoConsulta), stdin);
        modeloVeiculoConsulta[strcspn(modeloVeiculoConsulta, "\n")] = '\0';

        printf("\n");

        for (int i = 0; i < quantidadeVeiculos; i++)
        {
            if ((strcmp(modeloVeiculoConsulta, frotaVeiculos[i].modelo)) == 0)
            {

                printf("Codigo: %d\n", frotaVeiculos[i].codigo);
                printf("Modelo: %s\n", frotaVeiculos[i].modelo);
                printf("Marca: %s\n", frotaVeiculos[i].marca);
                printf("Ano: %d\n", frotaVeiculos[i].ano);
                printf("Valor da Diaria: %.2f\n", frotaVeiculos[i].valorDiaria);
                if (frotaVeiculos[i].situacao == 0)
                {
                    printf("Situação: Não Alocado\n");
                }
                else if (frotaVeiculos[i].situacao == 1)
                {
                    printf("Situação: Alocado\n");
                }

                printf("\n");

                achado = 1;
            }
        }

        if (achado == 0)
        {
            printf("Nenhum Veículo Achado\n");
        }

        printf("Aperte enter para fechar: ");
        scanf("%*c");
        break;

    default:
        break;
    }
}

void cadastrarCliente(pCliente listaClientes, int quantidadeClientes)
{
    for (int i = 0; i < quantidadeClientes; i++)
    {
        printf("\nCliente %d:\n", i + 1);
        
        printf("Código do Cliente: ");
        scanf("%d", &listaClientes[i].codigo);
        limparBuffer();
        
        printf("Nome Completo: ");
        fgets(listaClientes[i].nome, sizeof(listaClientes[i].nome), stdin);
        listaClientes[i].nome[strcspn(listaClientes[i].nome, "\n")] = '\0';
        
        printf("Número de Telefone: ");
        fgets(listaClientes[i].telefone, sizeof(listaClientes[i].telefone), stdin);
        listaClientes[i].telefone[strcspn(listaClientes[i].telefone, "\n")] = '\0';
    }
    printf("Cliente(s) Cadastrado(s)!\n");
}

void listarVeiculos(pVeiculo frotaVeiculos, int quantidadeVeiculos)
{
    if (quantidadeVeiculos == 0 || frotaVeiculos == NULL)
    {
        printf("\nNenhum veículo cadastrado no sistema no momento.\n");
        return;
    }
    
    printf("\nLista de Veículos da Frota");
    
    for (int i = 0; i < quantidadeVeiculos; i++)
    {
        printf("\nVeiculo %d:\n", i + 1);
        printf("Codigo: %d\n", frotaVeiculos[i].codigo);
        printf("Modelo: %s\n", frotaVeiculos[i].modelo);
        printf("Marca: %s\n", frotaVeiculos[i].marca);
        printf("Ano: %d\n", frotaVeiculos[i].ano);
        printf("Valor da Diária: R$ %.2f\n", frotaVeiculos[i].valorDiaria);
        
        if (frotaVeiculos[i].situacao == 0)
        {
            printf("Situação: Disponível\n");
        }
        else if (frotaVeiculos[i].situacao)
        {
            printf("Situação: Alugado\n");
        }
    }
    
    printf("Aperte enter para fechar: ");
    getchar();
}

void realizarLocacao(pVeiculo frotaVeiculos, int quantidadeVeiculos, pCliente listaClientes, int quantidadeClientes)
{
    // chamar calcularLocacao() aqui
}

float calcularLocacao(float valorDiaria, int quantidadeDias)
{

    return 0.0;
}

void devolverVeiculo(pVeiculo frotaVeiculos, int quantidadeVeiculos)
{
    int codigoVeiculoConsultar, confirmacao = 0;
    int encontrado = 0; // Variável de controle para saber se achamos o carro
    if (frotaVeiculos != NULL && quantidadeVeiculos > 0)
    {
        printf("Digite o codigo do veiculo para devolver: ");
        scanf("%d", &codigoVeiculoConsultar);
        for (int i = 0; i < quantidadeVeiculos; i++)
        {
            if (frotaVeiculos[i].codigo == codigoVeiculoConsultar)
            {
                encontrado = 1;                     // Marcamos que o carro existe na lista
                if (frotaVeiculos[i].situacao == 1) // 1 = Alugado
                {
                    printf("Você irá devolver o carro do codigo: %i\nmodelo: %s\nmarca: %s\nAno: %i\nvalor da diaria: %.2f\n",
                           codigoVeiculoConsultar,
                           frotaVeiculos[i].modelo, // Usando 'i' corretamente
                           frotaVeiculos[i].marca,
                           frotaVeiculos[i].ano,
                           frotaVeiculos[i].valorDiaria);

                    printf("Você tem certeza da ação a ser feita?\nDigite 1 para SIM\nDigite 2 para NÃO\nOpcao: ");
                    scanf("%i", &confirmacao);
                    if (confirmacao == 1) // Agora checamos se ele realmente quer devolver
                    {
                        frotaVeiculos[i].situacao = 0; // 0 = Disponível
                        printf("O veiculo do codigo: %i, foi devolvido com sucesso!\n", codigoVeiculoConsultar);
                    }
                    else
                    {
                        printf("Devolucao cancelada.\n");
                    }
                }
                else
                {
                    printf("O veiculo do codigo: %i, está com situacão de não alugado.\n", codigoVeiculoConsultar);
                }
                break; // Achou o carro, não precisa continuar rodando o 'for'
            }
        }
        if (encontrado == 0)
        {
            printf("Nenhum veiculo com o codigo %i encontrado, tente novamente.\n", codigoVeiculoConsultar);
        }
    }
    else
    {
        printf("Não há veiculos cadastrados, utilize a opção 1 para o cadastro de veiculo.\n");
    }
}
