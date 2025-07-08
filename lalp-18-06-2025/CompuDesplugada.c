#include <stdio.h> // Inclui a biblioteca padrão de entrada e saída para printf e scanf

int main() { // Função principal onde a execução do programa começa
    int numeroDigitado;          // Variável para armazenar o número lido do usuário
    int somaAtual = 0;           // Variável para acumular a soma dos números positivos
    int numerosPositivosLidos = 0; // Contador de números positivos válidos
    int errosConsecutivos = 0;   // Contador de erros (números negativos) consecutivos
    int tentativas = 0;          // Contador para simular as 10 leituras válidas (equivalente ao loop)

    printf("Bem-vindo ao simulador de leitura de dados!\n");
    printf("Digite 10 numeros inteiros. Regras:\n");
    printf("  - Numeros negativos sao ignorados.\n");
    printf("  - 3 erros consecutivos encerram o programa.\n");
    printf("  - O programa para se a soma de 5 numeros positivos atingir 50 ou mais.\n\n");

    // Loop principal para simular a leitura de até 10 números ou até que uma condição de parada seja atingida
    while (tentativas < 10) {
        printf("Tentativa %d - Digite um numero: ", tentativas + 1);
        scanf("%d", &numeroDigitado); // Lê o número digitado pelo usuário

        // Verifica se o número é negativo
        if (numeroDigitado < 0) {
            errosConsecutivos++; // Incrementa o contador de erros consecutivos
            printf("Numero negativo detectado. Erros consecutivos: %d\n", errosConsecutivos);

            // Verifica se o limite de erros consecutivos foi atingido
            if (errosConsecutivos >= 3) {
                printf("\n--- ERRO: 3 numeros negativos consecutivos! Sistema encerrado por seguranca. ---\n");
                // Exibe a soma e quantidade de números positivos lidos até o momento da interrupção
                printf("Soma final: %d\n", somaAtual);
                printf("Numeros positivos lidos: %d\n", numerosPositivosLidos);
                break; // Sai do loop imediatamente (uso do break)
            }
            continue; // Ignora o restante do código dentro do loop para este número e passa para a próxima iteração (uso do continue)
        }

        // Se o número não for negativo, reseta o contador de erros consecutivos
        errosConsecutivos = 0;

        // Se o número for positivo, processa
        somaAtual += numeroDigitado;        // Adiciona o número à soma
        numerosPositivosLidos++;            // Incrementa o contador de números positivos válidos

        printf("Numero valido. Soma atual: %d. Numeros positivos lidos: %d\n", somaAtual, numerosPositivosLidos);

        // Verifica se a meta de soma foi atingida
        if (numerosPositivosLidos >= 5 && somaAtual >= 50) {
            printf("\n--- META ATINGIDA: Soma de %d numeros positivos >= 50! ---\n", numerosPositivosLidos);
            printf("Soma final: %d\n", somaAtual);
            printf("Numeros positivos lidos para atingir a meta: %d\n", numerosPositivosLidos);
            break; // Sai do loop imediatamente (uso do break)
        }
        
        tentativas++; // Incrementa a contagem de tentativas válidas (independentemente de ser positivo ou negativo ignorado pelo continue)
    }

    // Mensagem final caso o loop termine sem atingir as condições de break
    if (tentativas >= 10 && errosConsecutivos < 3 && !(numerosPositivosLidos >= 5 && somaAtual >= 50)) {
        printf("\n--- FIM: Foram lidos 10 numeros. ---\n");
        printf("Soma final: %d\n", somaAtual);
        printf("Numeros positivos lidos: %d\n", numerosPositivosLidos);
    }

    return 0; // Indica que o programa foi executado com sucesso
}