#include "1_5.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int p_01()
{
    int A = 3;// premier mutliple
    int B = 5;//second mutiple
    int C = 15;// multiple commun a soustraire car en double.
    int x = 0;// stock les 1000 premier multiple de 3
    int y = 0;// stock les 1000 premier multiple de 5
    int z = 0;// stock les 1000 premier multiple de 15
    int MAX = 1000;

    for(A = 3; A < MAX; A += 3)// initialise A à 3. Pour A < 1000, faire la valeur de A + 3 soit sa valeur initiale.
    {
        x += A;// ajouter la valeur de A à la variable x.
    }
    for(B = 5; B < MAX; B += 5)
    {
        y += B;
    }
    for(C = 15; C < MAX; C += 15)
    {
        z += C;
    }

    int nombreTotale = (x + y)- z;// nombre final à avoir
    printf("%d\n", nombreTotale);

    return nombreTotale;
};

int p_02()
{
    int sommePaires = 0;// variable qui permet de stocker la somme des nombres paires
    int B = 0;// variable qui va contenir le nombre à additionner au premier .
    int A = 1;// nombre de fibo
    while(A < 4000000)// tant que fibbo ne dépasse pas 4M
    {
        B = A - B;//soustraire B à A pour avoir le nombre suivant de la suite de fibbo
        A = A + B;// ajoute le nombre en cours plus le précédent qui accède au step suivant.
        if (A % 2 == 0)// si le modulo 2 de A est égal à 0 (si c'est paire en gros)
        {
            sommePaires += A;// alors la somme total des paires se voie ajouter A.
        }
    }
    printf("%d\n", sommePaires);

    return sommePaires;
};
int p_03()
{
    /*Les facteurs premiers de 13195 sont 5, 7, 13 et 29.
    Quel est le plus grand facteur premier du nombre 600851475143 ?*/

    int facteurPremier = 0;//sotck le nombre premier à trouver
    long int A = 2;//
    long int x = 2;
    long long int probleme = 600851475143; // donne une variable à ce nombre

    while (probleme % A != 0)// initialise A à 1. Tant que le nombre en cours(A) est inférieur au nombre de base faire A+1
    {
        A++;// faire A + 1 jusqu'a ce qu'on trouve un facteur de probleme.
    }
    x = A;// donne la valeur du facteur A à x
    if (A < sqrt(probleme))// si le facteur est inférieur au carré de 600851475143
    {
        while (A < sqrt(probleme))// tant que A est inférieur au carré de 600851475143
        {
            if (probleme % A == 0)// si le reste 600851475143 divisé par  A est 0 alors
            {
                 facteurPremier = A;// facteur premier prend A en valeur
            }
            A++;// sinon ajouter 1 à A tant qu'il sera inférieur au carré de 600851475143
        }
    }
    facteurPremier /= x;// on divise le plus grand diviseur de probleme par le plus petit qu'on aviat avant ('x')

    printf("%d\n", facteurPremier);// et affiche la division du plus grand facteur par le plus petit.

    return facteurPremier;
}
int p_04()
{
    /*Un nombre palindromique se lit de la même manière dans les deux sens.
    Le plus grand palindrome formé du produit de deux nombres à 2 chiffres est 9009 = 91 × 99.
    Trouver le plus grand palindrome formé du produit de deux nombres à 3 chiffres.*/
    int x = 100;// premier nombre a multiplier
    int y = 100;// second nombre a mutilpier
    int z = 1;// récupera la multiplication de x et z
    int palindrome = 0;// prendra en valeur le palindrome final.
    for (x = 100; x < 1000; x++)// tant que x est < à 1000 faire x + 1
    {
        for(y = 100; y<1000; y++)//tant que x est < à 1000 faire x + 1
        {
            z = x*y;// multiplie x par y
            if(p_04_1(z) && z > palindrome)// si la fonctione p_04_1 avec en valeur z à renvoyé un booleen de valeur VRAI et que z est sup à palindrome (0)
            {
                palindrome = z;//alors palindrome est égal à z
            }
        }
    }
    printf("%d\n", palindrome);

    return palindrome;
}
int p_04_1(int value)
{
    int haut = value/1000;// crée variable haut qui prend en valeur z/1000 soit value. exemple : haut = 681497/1000 = 681
    int bas = value%1000;// crée variable bas qui prend en valeur z%1000 soit value. exemple : bas = 681497%1000 = 497
    bas = bas/100 + (bas/10)%10*10 + bas%100%10*100;// toujours pour meme exemple soit bas = 497; 497/100 récupere le 4; (497/10)%10*10 = 90; 497%100%10*100 = 700;
    //soit 497 = 794
    return haut == bas;// puis renvoie TRUE si haut donc 681 est égal à bas soit 794 ce qui n'est pas le cas .
}
int p_05()
{
//2520 est le plus petit nombre qui peut être divisé par chacun des nombres de 1 à 10 sans aucun reste.

//Quel est le plus petit nombre positif divisible par tous les nombres de 1 à 20 ?

    int diviseur, compteur = 0;
    int ppcm = 21;//initialise a 21 car forcement plus grand que 20
    while (ppcm < 999999999)// tant que le ppcm est inf a un nombre géant, soit jusqu'au "break;"
    {
        compteur = 0;// on initialise le compteur a 0
        for(diviseur = 2; diviseur<21; diviseur++)// pour div = 2, la boucle ajoute 1 tant que div est inf à 21
        {
            if (ppcm % diviseur != 0)// si ppcm modulo div n'est pas égal a 0 soit n'est pas un multiple alors
            {
                compteur = 1;//compteur prend 1 en valeur et fin de la boucle.
                break;
            }
        }
        if (compteur == 0)//si compteur est toujours 0 alors n'a pas pris 1 en valeur DONC compteur à été divisé par tout les nombre de 2 à 20
        {
                printf("Number is %ld", ppcm);//alorson affiche le nombre
                break;// et on casse la boucle.
        }
        ppcm++;// on ajoute 1 au ppcm si div %diviseur !=0
    }
}
