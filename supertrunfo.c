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

int main() {
    struct Carta carta1, carta2;
    int opcao;

    printf("=== SUPER TRUNFO - NIVEL AVENTUREIRO ===\n\n");

    // Cadastro da Carta 1
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

    printf("\n--- Carta 1 cadastrada com sucesso! ---\n\n");

    // Cadastro da Carta 2
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

    printf("\n--- Carta 2 cadastrada com sucesso! ---\n\n");

    // Exibe as cartas cadastradas
    printf("=== CARTA 1 ===\n");
    printf("Estado: %s\n", carta1.estado);
    printf("Codigo: %s\n", carta1.codigo);
    printf("Cidade: %s\n", carta1.nomeCidade);
    printf("Populacao: %d\n", carta1.populacao);
    printf("Area: %.2f km²\n", carta1.area);
    printf("PIB: %.2f bilhoes\n", carta1.pib);
    printf("Pontos turisticos: %d\n", carta1.pontosTuristicos);
    printf("Densidade populacional: %.2f hab/km²\n", carta1.densidadePopulacional);

    printf("\n=== CARTA 2 ===\n");
    printf("Estado: %s\n", carta2.estado);
    printf("Codigo: %s\n", carta2.codigo);
    printf("Cidade: %s\n", carta2.nomeCidade);
    printf("Populacao: %d\n", carta2.populacao);
    printf("Area: %.2f km²\n", carta2.area);
    printf("PIB: %.2f bilhoes\n", carta2.pib);
    printf("Pontos turisticos: %d\n", carta2.pontosTuristicos);
    printf("Densidade populacional: %.2f hab/km²\n", carta2.densidadePopulacional);

    // Menu interativo
    printf("\n=== MENU DE COMPARACAO ===\n");
    printf("Escolha o atributo para comparar:\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Populacional\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    printf("\n=== RESULTADO DA COMPARACAO ===\n");

    switch (opcao) {
        case 1: // População
            printf("Comparando Populacao:\n");
            printf("%s: %d habitantes\n", carta1.nomeCidade, carta1.populacao);
            printf("%s: %d habitantes\n", carta2.nomeCidade, carta2.populacao);

            if (carta1.populacao > carta2.populacao)
                printf("Vencedor: %s (maior populacao)\n", carta1.nomeCidade);
            else if (carta1.populacao < carta2.populacao)
                printf("Vencedor: %s (maior populacao)\n", carta2.nomeCidade);
            else
                printf("Empate!\n");
            break;

        case 2: // Área
            printf("Comparando Area:\n");
            printf("%s: %.2f km²\n", carta1.nomeCidade, carta1.area);
            printf("%s: %.2f km²\n", carta2.nomeCidade, carta2.area);

            if (carta1.area > carta2.area)
                printf("Vencedor: %s (maior area)\n", carta1.nomeCidade);
            else if (carta1.area < carta2.area)
                printf("Vencedor: %s (maior area)\n", carta2.nomeCidade);
            else
                printf("Empate!\n");
            break;

        case 3: // PIB
            printf("Comparando PIB:\n");
            printf("%s: %.2f bilhoes\n", carta1.nomeCidade, carta1.pib);
            printf("%s: %.2f bilhoes\n", carta2.nomeCidade, carta2.pib);

            if (carta1.pib > carta2.pib)
                printf("Vencedor: %s (maior PIB)\n", carta1.nomeCidade);
            else if (carta1.pib < carta2.pib)
                printf("Vencedor: %s (maior PIB)\n", carta2.nomeCidade);
            else
                printf("Empate!\n");
            break;

        case 4: // Pontos turísticos
            printf("Comparando Pontos Turisticos:\n");
            printf("%s: %d pontos\n", carta1.nomeCidade, carta1.pontosTuristicos);
            printf("%s: %d pontos\n", carta2.nomeCidade, carta2.pontosTuristicos);

            if (carta1.pontosTuristicos > carta2.pontosTuristicos)
                printf("Vencedor: %s (mais pontos turisticos)\n", carta1.nomeCidade);
            else if (carta1.pontosTuristicos < carta2.pontosTuristicos)
                printf("Vencedor: %s (mais pontos turisticos)\n", carta2.nomeCidade);
            else
                printf("Empate!\n");
            break;

        case 5: // Densidade populacional (menor vence)
            printf("Comparando Densidade Populacional:\n");
            printf("%s: %.2f hab/km²\n", carta1.nomeCidade, carta1.densidadePopulacional);
            printf("%s: %.2f hab/km²\n", carta2.nomeCidade, carta2.densidadePopulacional);

            if (carta1.densidadePopulacional < carta2.densidadePopulacional)
                printf("Vencedor: %s (menor densidade populacional)\n", carta1.nomeCidade);
            else if (carta1.densidadePopulacional > carta2.densidadePopulacional)
                printf("Vencedor: %s (menor densidade populacional)\n", carta2.nomeCidade);
            else
                printf("Empate!\n");
            break;

        default:
            printf("Opcao invalida! Tente novamente.\n");
            break;
    }

    printf("\n=== FIM DO JOGO ===\n");
    return 0;
}