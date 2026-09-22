# Sistema de Gestão de Locadora de Veículos

**Integrantes:**
* Antônio Marcos Daniel Macêdo de Melo
* Antonio Marcos Matos de Almeida
* Gabriel Henrique Carvalho de Lima
* Gabriel Levi Mendes dos Santos
* Janeilson Paulino de Araujo

## 📄 Descrição do Sistema

Este projeto é um sistema desenvolvido em linguagem C para o gerenciamento de uma locadora de veículos. Operando inteiramente via terminal, o programa utiliza conceitos fundamentais e avançados de programação estruturada, como alocação dinâmica de memória (`malloc`, `free`), manipulação de ponteiros e estruturas (`structs`). Ele permite gerenciar temporariamente uma base de clientes e uma frota de veículos, otimizando o uso de memória ao alocar exatamente o espaço necessário no momento em que os cadastros são solicitados.

## ⚙️ Principais Funcionalidades

O sistema conta com um menu interativo que disponibiliza as seguintes operações baseadas no código:

* **Cadastrar Veículo:** Insere novos veículos na frota exigindo as informações de código, modelo, marca, ano de fabricação e valor da diária. *(Por padrão, todo novo veículo recebe a situação `0` - "Não Alocado / Disponível")*.
* **Consultar Veículo:** Permite a busca detalhada de um veículo específico na frota com duas opções de filtro: utilizando o código identificador numérico ou pesquisando pelo nome do modelo.
* **Cadastrar Cliente:** Registra novos clientes armazenando código, nome completo e número de telefone na base de dados temporária.
* **Listar Veículos:** Percorre a frota e exibe a relação de todos os veículos cadastrados e o status atual de cada um (Disponível ou Alugado).
* **Realizar Locação & Calcular Locação:** Estruturas-base (`realizarLocacao` e `calcularLocacao`) já criadas e referenciadas no menu, preparadas para receber a lógica de cálculo baseada nos dias de locação e valor da diária.
* **Devolver Veículo:** Busca um veículo pelo código, exibe os detalhes em tela para o usuário confirmar a ação e, caso confirmado, altera o status do veículo de volta para "Disponível".
* **Gerenciamento de Memória:** O sistema possui a função `desalocarMemoria`, que libera automaticamente toda a memória alocada dinamicamente das listas de clientes e veículos quando o usuário finaliza a execução escolhendo a opção de sair (`0`).

## 🚀 Instruções para compilar e executar

### Pré-requisitos

Para rodar este sistema, você precisará de um compilador C (como o GCC) instalado na sua máquina.

### Passos para compilação

1. Salve o código-fonte em um arquivo chamado `main.c`.
2. Abra o terminal (PowerShell) na pasta onde o arquivo foi salvo.
3. Compile o código utilizando o comando:

```bash
gcc main.c -o locadora 
```

4. Após a compilação, execute o programa gerado inserindo o seguinte comando no terminal:

```bash
.\locadora.exe
```
