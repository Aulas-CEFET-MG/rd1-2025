# Agenda Telefônica em C 📞

 > Atualizado em 19/11/2025

Este é um projeto didático de uma aplicação de **Agenda Telefônica** via linha de comando (CLI). O objetivo é demonstrar conceitos fundamentais da linguagem C, incluindo manipulação de arquivos, alocação dinâmica de memória e modularização de código.

## Funcionalidades

O sistema é um **CRUD** completo (Create, Read, Update, Delete) com as seguintes características:

- **Adicionar Contato:** Nome, DDD e Telefone.
- **Listar Todos:** Exibe os contatos em formato de tabela.
- **Busca:**
  - Por **Nome** (busca parcial/substring).
  - Por **DDD** (filtro exato).
- **Atualizar e Remover:** Edição e exclusão de contatos existentes.
- **Persistência Automática:** Os dados são salvos em disco (`agenda.tsv`) **imediatamente** após qualquer alteração (inserção, edição ou remoção), garantindo que nada seja perdido em caso de fechamento abrupto.
- **Banco de Dados:** Utiliza arquivo texto no formato **TSV** (Tab-Separated Values).

## Estrutura do Projeto

O código foi modularizado para facilitar a manutenção e o estudo:

| Arquivo | Função |
| :--- | :--- |
| `Main.c` | **Interface:** Contém o menu principal e o fluxo de interação com o usuário. |
| `Agenda.c` | **Implementação:** Contém a lógica "pesada" (regras de negócio, acesso a dados, lógica do vetor). |
| `Agenda.h` | **Cabeçalho:** O "contrato" do módulo. Contém a definição da `struct`, constantes e protótipos das funções. |
| `agenda.tsv` | **Dados:** Arquivo gerado automaticamente onde os contatos são armazenados. |

## Conceitos Abordados

Este projeto serve como exemplo prático para:

1.  **Structs:** Agrupamento de dados heterogêneos (Nome `char[]`, DDD `int`).
2.  **Ponteiros e Alocação Dinâmica:** Uso de `malloc`, `realloc` e `free` para criar um vetor que cresce conforme a necessidade (sem tamanho fixo).
3.  **Manipulação de Arquivos (`FILE*`):** Leitura e escrita com `fscanf` e `fprintf`.
4.  **Modularização:** Separação entre Interface (`.h`), Implementação (`.c`) e Aplicação (`main.c`).
5.  **Lógica de Algoritmos:** Remoção de itens em vetores (shift left) e busca linear.

---

## Como Compilar e Executar?

Como o projeto possui múltiplos arquivos (`Main.c` e `Agenda.c`), você **não pode** compilar apenas um deles isoladamente. É necessário "linkar" todos os arquivos.

### Pré-requisitos
Você precisa ter um compilador C instalado (GCC).
- **Windows:** MinGW.
- **Linux/Mac:** GCC (geralmente já instalado ou via `build-essential`).

### Opção 1: Via Terminal (Recomendado)

Esta é a forma mais universal e funciona em qualquer sistema operacional.

1. Abra o terminal (ou Prompt de Comando) na pasta do projeto.
2. Digite o comando abaixo para compilar todos os arquivos `.c` juntos:

   ```bash
   gcc Main.c Agenda.c -o Agenda.exe
   ```

> *(Nota: O flag -o Agenda define o nome do executável final)*


3. Para rodar o programa:

   - **No Windows:**

        .\Agenda.exe

   - **No Linux/Mac:**

        ./Agenda

### Opção 2: No VS Code (Visual Studio Code)

Se você usa o VS Code, evite usar o botão "Play" (Code Runner) se ele não estiver configurado para múltiplos arquivos, pois ele tentará rodar apenas o arquivo aberto na tela.

**Passo a passo seguro:**

1. Abra a pasta do projeto no VS Code (`File` > `Open Folder`).
2. Abra o **Terminal Integrado** (Menu `Terminal` > `New Terminal`).
3. Utilize o mesmo comando da Opção 1 no terminal que abriu na parte inferior da tela:

        gcc *.c -o agenda.exe
        .\agenda.exe

> *(O comando `*.c` pega automaticamente todos os arquivos C da pasta)*

---

## Solução de Problemas Comuns

**Erro 1: `undefined reference to 'adicionarContato'`**
> **Causa:** Você tentou compilar apenas o arquivo `Main.c`. O compilador não sabe onde estão as funções.
> **Solução:** Compile os dois arquivos juntos: `gcc Main.c Agenda.c -o Agenda`.

**Erro 2: `undefined reference to 'WinMain'` ou `'main'`**
> **Causa:** Você tentou compilar apenas o arquivo `Agenda.c`. Este arquivo não tem o ponto de partida (`Main`).
> **Solução:** Nunca compile o `Agenda.c` sozinho. Compile o conjunto.

**Erro 3: O programa pula o nome ao digitar**
> **Causa:** O `scanf` anterior deixou um "Enter" (`\n`) no buffer do teclado.
> **Solução:** O código utiliza a função `limparBuffer()` para corrigir isso. Não remova essas chamadas após os `scanf`.

---

## Exemplo de Uso

Ao iniciar, o programa verificará se existe o arquivo `agenda.tsv`. Se não existir, criará uma nova base.

    =================================
          AGENDA TELEFONICA (C)      
    =================================
    Contatos na memoria: 0
    ---------------------------------
    1. Adicionar Contato
    2. Listar Todos
    ...
    Escolha: 1
    
    --- Novo Contato ---
    Nome: Maria Silva
    DDD (apenas numeros): 11
    Telefone: 99999-8888
    Contato adicionado com sucesso!
    (Dados salvos no arquivo automaticamente)

**Bons estudos!**