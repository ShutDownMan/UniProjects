#include <stdio.h>

/// Tabela de items e preços
const char *itemNames[7] = {"Cachorro-quente", "X-salada", "X-bacon ", "Misto   ", "Salada  ", "Agua    ", "Refrigerante"};
const double itemPrices[7] = {5.00, 8.79, 9.99, 6.89, 4.80, 3.49, 4.99};

int newItemMenu()
{
    int i, choice = 0;

    /// Menu para o usuário
    for (i = 1; i <= 7; ++i)
        printf("(%d) - %s\n", i, itemNames[i - 1]);
    printf("Insira o numero do item: ");
    scanf(" %d", &choice);

    /// se a escolha está fora do intervalo [1, 7], retorna 0
    if (choice < 1 || choice > 7)
        return 0;

    /// retorna escolha do usuário
    return choice;
}

int askItemMenuQuant()
{
    int quant = 0;

    /// pede quantidade para o usuário
    printf("insira a quantidade de items: ");
    scanf(" %d", &quant);

    /// se quantidade é número negativo
    if (quant < 0)
    {
        /// pede para inserir novamente
        printf("Quantidade invalida!");
        printf("insira novamente a quantidade de items: ");
        scanf(" %d", &quant);
    }

    /// retorna quantidade de items
    return quant;
}

int userCheckout(int userCart[7])
{
    int i;
    double balance = 0.0;

    /// printa cabeçalho
    printf("Item\tProduto\t\tQuantidade\n");
    for (i = 1; i <= 7; ++i)
    {
        /// se quantidade do item atual for diferente de 0
        if (userCart[i - 1])
        {
            /// printa cada produto linha por linha: item - nome - quantidade
            printf("%d\t%s\t%d\n", i, itemNames[i - 1], userCart[i - 1]);
        }
        /// calcula total: preço * quant
        balance += itemPrices[i - 1] * userCart[i - 1];
    }
    printf("Valor da compra: R$ %.2lf\n", balance);
}

int main(void)
{
    /// Variáveis utilizadas
    int userCart[7] = {0}; /// iniciliza todos campos com 0
    int itemMenuChoice = 0, itemMenuQuant = 0;

    /// enquanto item escolhido não for 0
    while (itemMenuChoice = newItemMenu())
    {
        /// pergunta quantidade
        itemMenuQuant = askItemMenuQuant();
        /// salva quantidade no carrinho
        userCart[itemMenuChoice - 1] += itemMenuQuant;
    }

    /// mostra resultado do programa
    userCheckout(userCart);

    return 0;
}