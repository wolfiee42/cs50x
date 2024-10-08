// #include <cs50.h>
// #include <stdio.h>

// unfurnished
// int main(void)
// {
//     int coin = 0;
//     int change = get_int("How much you owe? \n");
//     if (change < 0)
//     {
//         change = get_int("How much you owe? \n");
//     }
//     else
//     {

//         int quater = change / 25;
//         coin += quater;
//         int left1 = change % 25;

//         int dime = left1 / 10;
//         coin += dime;
//         int left2 = left1 % 10;

//         int nickels = left2 / 5;
//         coin += nickels;
//         int left3 = left2 % 5;

//         int penni = left3 / 1;
//         coin += penni;

//         printf("%i \n", coin);
//     }
// }

// optimized
#include <cs50.h>
#include <stdio.h>

int calculate_quaters(int cents);
int calculate_dime(int cents);
int calculate_nickles(int cents);
int calculate_penni(int cents);

int main(void)
{
    int cents;
    do
    {
        cents = get_int("Change owed: ");
    } while (cents < 0);

    // quarter
    int quarters = calculate_quaters(cents);
    cents = cents - (quarters * 25);

    // dime
    int dimes = 0;
    if (cents > 0)
    {
        dimes = calculate_dime(cents);
        cents = cents - (dimes * 10);
    }

    // nickles
    int nickles = 0;
    if (cents > 0)
    {
        nickles = calculate_nickles(cents);
        cents = cents - (nickles * 5);
    }

    // penni
    int penni = 0;
    if (cents > 0)
    {
        penni = calculate_penni(cents);
        cents = cents - (penni * 1);
    }

    int ammoutOfCoins = (quarters + dimes + nickles + penni);
    printf("%i\n", ammoutOfCoins);
}

int calculate_quaters(int cents)
{
    int quarters = 0;
    while (cents >= 25)
    {
        quarters++;
        cents -= 25;
    }
    return quarters;
}

int calculate_dime(int cents)
{
    int dimes = 0;
    while (cents >= 10)
    {
        dimes++;
        cents -= 10;
    }
    return dimes;
}

int calculate_nickles(int cents)
{
    int nickles = 0;
    while (cents >= 5)
    {
        nickles++;
        cents -= 5;
    }
    return nickles;
}

int calculate_penni(int cents)
{
    int penni = 0;
    while (cents >= 1)
    {
        penni++;
        cents -= 1;
    }
    return penni;
}
