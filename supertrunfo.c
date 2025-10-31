#include <stdio.h>
#include <string.h>

// Estrutura que representa uma carta de cidade/país
struct Carta {
    char estado[50];
    char codigo[10];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
};

// Função para comparar um atributo específico
float obterValor(struct Carta carta, int atributo) {
    switch (atributo) {
        case 1: return carta.populacao;
        case 2: return carta.area;
        case 3: return carta.pib;
        case 4: return carta.pontosTuristicos;
        case 5: return carta.densidadePopulacional;
        default: return 0;
    }
}

// Função para exibir o nome do atributo
const char* nomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "Populacao";
        case 2: return "Area";
        case 3: return "PIB";
        case 4: return "Pontos Turisticos";
        case 5: return "Densidade Populacional";
        default: return "Desconhecido";
    }
}

int main() {
    struct Carta carta1, carta2;
    int atributo1, atributo2;

    printf("=== SUPER TRUNFO - NIVEL MESTRE ===\n\n");

    // Cadastro da primeira carta
    printf("Cadastro da primeira carta:\n");
    printf("Estado: ");
    scanf(" %[^\n]", carta1.estado);
    printf("Codigo da carta: ");
    scanf(" %[^\n]", carta1.codigo);
    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta1.nomeCidade);
    printf("Populacao: ");
    scanf("%d", &carta1.populacao);
    printf("Area (em km²): ");
    scanf("%f", &carta1.area);
    printf("PIB (em bilhoes): ");
    scanf("%f", &carta1.pib);
    printf("Numero de pontos turisticos: ");
    scanf("%d", &carta1.pontosTuristicos);
    carta1.densidadePopulacional = carta1.populacao / carta1.area;

    printf("\n--- Carta 1 cadastrada! ---\n\n");

    // Cadastro da segunda carta
    printf("Cadastro da segunda carta:\n");
    printf("Estado: ");
    scanf(" %[^\n]", carta2.estado);
    printf("Codigo da carta: ");
    scanf(" %[^\n]", carta2.codigo);
    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta2.nomeCidade);
    printf("Populacao: ");
    scanf("%d", &carta2.populacao);
    printf("Area (em km²): ");
    scanf("%f", &carta2.area);
    printf("PIB (em bilhoes): ");
    scanf("%f", &carta2.pib);
    printf("Numero de pontos turisticos: ");
    scanf("%d", &carta2.pontosTuristicos);
    carta2.densidadePopulacional = carta2.populacao / carta2.area;

    printf("\n--- Carta 2 cadastrada! ---\n\n");

    // Exibir cartas cadastradas resumidamente
    printf("=== CARTAS CADASTRADAS ===\n");
    printf("Carta 1: %s (%s)\n", carta1.nomeCidade, carta1.codigo);
    printf("Carta 2: %s (%s)\n\n", carta2.nomeCidade, carta2.codigo);

    // Primeiro menu de atributos
    printf("Escolha o PRIMEIRO atributo para comparar:\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Populacional\n");
    printf("Opcao: ");
    scanf("%d", &atributo1);

    if (atributo1 < 1 || atributo1 > 5) {
        printf("\nOpcao invalida! Encerrando programa.\n");
        return 0;
    }

    // Segundo menu (dinâmico)
    printf("\nEscolha o SEGUNDO atributo (diferente do primeiro):\n");
    for (int i = 1; i <= 5; i++) {
        if (i != atributo1)
            printf("%d - %s\n", i, nomeAtributo(i));
    }
    printf("Opcao: ");
    scanf("%d", &atributo2);

    if (atributo2 < 1 || atributo2 > 5 || atributo2 == atributo1) {
        printf("\nOpcao invalida! Os atributos devem ser diferentes.\n");
        return 0;
    }

    // Comparação dos dois atributos
    float valor1A = obterValor(carta1, atributo1);
    float valor2A = obterValor(carta2, atributo1);
    float valor1B = obterValor(carta1, atributo2);
    float valor2B = obterValor(carta2, atributo2);

    printf("\n=== COMPARACAO FINAL ===\n");
    printf("Atributos escolhidos: %s e %s\n", nomeAtributo(atributo1), nomeAtributo(atributo2));
    printf("\n%-25s | %-12s | %-12s\n", "Atributo", carta1.nomeCidade, carta2.nomeCidade);
    printf("------------------------------------------------------\n");
    printf("%-25s | %-12.2f | %-12.2f\n", nomeAtributo(atributo1), valor1A, valor2A);
    printf("%-25s | %-12.2f | %-12.2f\n", nomeAtributo(atributo2), valor1B, valor2B);

    // Aplicar regras especiais
    // Para densidade populacional, menor valor vence
    float pontos1 = 0, pontos2 = 0;

    // Primeiro atributo
    if (atributo1 == 5) {
        pontos1 += (valor1A < valor2A) ? 1 : (valor1A > valor2A) ? 0 : 0.5;
        pontos2 += (valor2A < valor1A) ? 1 : (valor2A > valor1A) ? 0 : 0.5;
    } else {
        pontos1 += (valor1A > valor2A) ? 1 : (valor1A < valor2A) ? 0 : 0.5;
        pontos2 += (valor2A > valor1A) ? 1 : (valor2A < valor1A) ? 0 : 0.5;
    }

    // Segundo atributo
    if (atributo2 == 5) {
        pontos1 += (valor1B < valor2B) ? 1 : (valor1B > valor2B) ? 0 : 0.5;
        pontos2 += (valor2B < valor1B) ? 1 : (valor2B > valor1B) ? 0 : 0.5;
    } else {
        pontos1 += (valor1B > valor2B) ? 1 : (valor1B < valor2B) ? 0 : 0.5;
        pontos2 += (valor2B > valor1B) ? 1 : (valor2B < valor1B) ? 0 : 0.5;
    }

    // Cálculo das somas dos atributos
    float soma1 = valor1A + valor1B;
    float soma2 = valor2A + valor2B;

    printf("\nSoma dos atributos:\n");
    printf("%s: %.2f\n", carta1.nomeCidade, soma1);
    printf("%s: %.2f\n", carta2.nomeCidade, soma2);

    // Resultado final com operador ternário
    printf("\n=== RESULTADO FINAL ===\n");
    if (soma1 == soma2)
        printf("Empate!\n");
    else
        printf("Vencedor: %s\n", (soma1 > soma2) ? carta1.nomeCidade : carta2.nomeCidade);

    printf("\n=== FIM DO JOGO ===\n");

    return 0;
}
