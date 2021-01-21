#include <stdio.h>

const char *months[12] = {"Jan", "Fev", "Mar", "Abr", "Mai", "Jun", "Jul", "Ago", "Set", "Out", "Nov", "Dez"};

void showResult(double usagePerMonth[12], double rainPerMonth[12], double reservoirCapacity)
{
    int i = 0;
    double reservoirVolume = 0;

    /// para cada mês
    for (i = 0; i < 12; ++i)
    {
        /// calcula volume do reservatório
        reservoirVolume += rainPerMonth[i] - usagePerMonth[i];

        /// printa mês atual
        printf("%s - ", months[i]);
        /// se estiver vazio
        if (reservoirVolume <= 0)
        {
            printf("Reservatorio vazio!\n");
            reservoirVolume = 0;
        } /// se estiver cheio
        else if (reservoirVolume >= reservoirCapacity)
        {
            printf("Reservatorio cheio! (%.0lf mm)\n", reservoirCapacity);
            reservoirVolume = reservoirCapacity;
        } /// se estiver normal
        else
        {
            printf(" %.0lf mm\n", reservoirVolume);
        }
    }
}

int main(void)
{
    /// define e inicializa variáveis
    int i;
    double reservoirCapacity = 0.0, reservoirVolume = 0.0;
    double currentUsage = 0.0, currentRain = 0.0;
    double usagePerMonth[12] = {0.0}, rainPerMonth[12] = {0.0}; /// inicializa todos campos com 0.0

    printf("Insira a capacidade do reservatorio (mm): ");
    scanf("%lf", &reservoirCapacity);

    /// para cada mês
    for (i = 0; i < 12; ++i)
    {
        /// pede quantidade gasta
        printf("Insira a quantidade gasta de %s (mm): ", months[i]);
        scanf("%lf", &currentUsage);

        /// pede quantidade de chuva
        printf("Insira a quantidade de chuva de %s (mm): ", months[i]);
        scanf("%lf", &currentRain);

        /// salva valores
        usagePerMonth[i] = currentUsage;
        rainPerMonth[i] = currentRain;
    }

    /// mostra resultado na tela
    showResult(usagePerMonth, rainPerMonth, reservoirCapacity);

    return 0;
}