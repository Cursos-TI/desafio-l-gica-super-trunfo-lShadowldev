#include <stdio.h>
#include <string.h>

struct Carta {
    char estado[50];
    char codigo[5];
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

    printf("===========================================\n");
    printf("        🏆 SUPER TRUNFO - PAISES 🏆        \n");
    printf("===========================================\n\n");

    // Cadastro da primeira carta
    printf("------ Cadastro da Carta 1 ------\n");
    printf("Estado: ");
    scanf(" %[^\n]", carta1.estado);
    printf("Codigo da Carta: ");
    scanf(" %[^\n]", carta1.codigo);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta1.nomeCidade);
    printf("Populacao: ");
    scanf("%d", &carta1.populacao);
    printf("Area (km²): ");
    scanf("%f", &carta1.area);
    printf("PIB (em bilhoes): ");
    scanf("%f", &carta1.pib);
    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &carta1.pontosTuristicos);

    // Cálculo automático da densidade populacional
    carta1.densidadePopulacional = carta1.populacao / carta1.area;

    printf("\n");

    // Cadastro da segunda carta
    printf("------ Cadastro da Carta 2 ------\n");
    printf("Estado: ");
    scanf(" %[^\n]", carta2.estado);
    printf("Codigo da Carta: ");
    scanf(" %[^\n]", carta2.codigo);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta2.nomeCidade);
    printf("Populacao: ");
    scanf("%d", &carta2.populacao);
    printf("Area (km²): ");
    scanf("%f", &carta2.area);
    printf("PIB (em bilhoes): ");
    scanf("%f", &carta2.pib);
    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &carta2.pontosTuristicos);

    carta2.densidadePopulacional = carta2.populacao / carta2.area;

    // Exibição das cartas cadastradas
    printf("\n===========================================\n");
    printf("           🃏 CARTAS CADASTRADAS 🃏        \n");
    printf("===========================================\n");

    printf("\nCarta 1 - %s (%s)\n", carta1.nomeCidade, carta1.estado);
    printf("-------------------------------------------\n");
    printf("Populacao: %d habitantes\n", carta1.populacao);
    printf("Area: %.2f km²\n", carta1.area);
    printf("PIB: %.2f bilhões\n", carta1.pib);
    printf("Pontos Turisticos: %d\n", carta1.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta1.densidadePopulacional);

    printf("\nCarta 2 - %s (%s)\n", carta2.nomeCidade, carta2.estado);
    printf("-------------------------------------------\n");
    printf("Populacao: %d habitantes\n", carta2.populacao);
    printf("Area: %.2f km²\n", carta2.area);
    printf("PIB: %.2f bilhões\n", carta2.pib);
    printf("Pontos Turisticos: %d\n", carta2.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta2.densidadePopulacional);

    // Escolha do atributo para comparação
    printf("\n===========================================\n");
    printf("   🔍 Escolha o atributo para comparacao   \n");
    printf("===========================================\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Populacional\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    printf("\n===========================================\n");
    printf("              🏁 RESULTADO 🏁              \n");
    printf("===========================================\n");

    switch (opcao) {
        case 1:
            if (carta1.populacao > carta2.populacao)
                printf("Carta 1 (%s) venceu! Maior populacao.\n", carta1.nomeCidade);
            else if (carta2.populacao > carta1.populacao)
                printf("Carta 2 (%s) venceu! Maior populacao.\n", carta2.nomeCidade);
            else
                printf("Empate!\n");
            break;

        case 2:
            if (carta1.area > carta2.area)
                printf("Carta 1 (%s) venceu! Maior area.\n", carta1.nomeCidade);
            else if (carta2.area > carta1.area)
                printf("Carta 2 (%s) venceu! Maior area.\n", carta2.nomeCidade);
            else
                printf("Empate!\n");
            break;

        case 3:
            if (carta1.pib > carta2.pib)
                printf("Carta 1 (%s) venceu! Maior PIB.\n", carta1.nomeCidade);
            else if (carta2.pib > carta1.pib)
                printf("Carta 2 (%s) venceu! Maior PIB.\n", carta2.nomeCidade);
            else
                printf("Empate!\n");
            break;

        case 4:
            if (carta1.pontosTuristicos > carta2.pontosTuristicos)
                printf("Carta 1 (%s) venceu! Mais pontos turisticos.\n", carta1.nomeCidade);
            else if (carta2.pontosTuristicos > carta1.pontosTuristicos)
                printf("Carta 2 (%s) venceu! Mais pontos turisticos.\n", carta2.nomeCidade);
            else
                printf("Empate!\n");
            break;

        case 5:
            if (carta1.densidadePopulacional < carta2.densidadePopulacional)
                printf("Carta 1 (%s) venceu! Menor densidade populacional.\n", carta1.nomeCidade);
            else if (carta2.densidadePopulacional < carta1.densidadePopulacional)
                printf("Carta 2 (%s) venceu! Menor densidade populacional.\n", carta2.nomeCidade);
            else
                printf("Empate!\n");
            break;

        default:
            printf("Opcao invalida!\n");
            break;
    }

    printf("===========================================\n");

    return 0;
}