/*
* Author(s): Benjie Van Limbergen & Miguel Nunez
* Date: 6/12/2021
* Description: *** Blackjack spel *** taak C-programeren 1EAIC 2021-2022
*/

#include "blackJackLib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

// DECLARATIE FUNCTIES:

int newCard();
int deelStartKaarten();
int waardeAas();
int geefKaart();
int randomKaart();
int kaart1();
int kaart2();
int kaart3();
int kaart4();
int kaart5();
int kaart6();
int kaart7();
int kaart8();
int kaart9();
int kaart10();
int kaart11();
int kaart12();
int kaart13();
void printIntro(void);

/*
* Omschrijving: trekt 1 enkele nieuwe kaart
* @param:   puntTotaal = totaalwaarde in hand van speler of house
* @param: punt = de waarde van de kaart
* @return:  puntTotaal
*/
int newCard(int puntTotaal)
{
int punt = 0;
		punt = geefKaart();
        if (punt == 1)  {
            punt = waardeAas(punt, puntTotaal);}      
        //printf("Kaartwaarde: %d \n", punt);
        puntTotaal = puntTotaal + punt;
        // printf("puntTotaal = %d\n", puntTotaal); 
    return puntTotaal;
}

/*
* Omschrijving: trekt de 2 startkaarten
* @param:   puntTotaal = totaalwaarde in hand van speler of house
* @param: punt = de waarde van de kaart
* @return:  puntTotaal
*/
int deelStartKaarten(int puntTotaal)
{
int punt = 0;
    for(int i = 0; i < 2; i++)
	{
		punt = geefKaart();
        if (punt == 1)  {
            punt = waardeAas(punt, puntTotaal);}      
      //  printf("Kaartwaarde: %d \n", punt);
        puntTotaal = puntTotaal + punt;
      //  printf("puntTotaal = %d\n", puntTotaal);
	}
    return puntTotaal;
}

/*
* Omschrijving: controle en bepaling waarde van Aas; indien mogelijk waarde 11, anders 1
* @param:   puntTotaal = totaalwaarde in hand van speler of house
* @param: punt = de waarde van de kaart
* @return:  punt
*/
int waardeAas(int punt, int puntTotaal)
{
    if (puntTotaal <11) {
        punt = 11;}
    else {
        punt = 1;}
    return punt;    
}

/*
* Omschrijving: trekt een randomkaart uit het boek
* @param:   kaart = een random getal tussen 1 en 13
* @param: score = de waarde die de kaart heeft, uitgezonderd voor Aas waarbij de waarde finaal bepaald zal worden in waardeAas()
* @return:  score
*/
int geefKaart()
{
	int kaart = randomKaart();
	int score = 0;
    	switch (kaart)
    	{
	        case 1:
	            score = kaart1();
	            break;
	        case 2:
	            score = kaart2();
	            break;
	        case 3:
	            score = kaart3();
	            break;
	        case 4:
	            score = kaart4();
	            break;
	        case 5:
	            score = kaart5();
	            break;
	        case 6:
	            score = kaart6();
	            break;
	        case 7:
	            score = kaart7();
	            break;
	        case 8:
	            score = kaart8();
	            break;
	        case 9:
	            score = kaart9();
	            break;
	        case 10:
	            score = kaart10();
	            break;
	        case 11:
	            score = kaart11();
	            break;
	        case 12:
	            score = kaart12();
	            break;
	        case 13:
	            score = kaart13();
	            break;
	        default:
	            score = 0;
	            printf("Woops something went horribly wrong ... ");
	        break;
	    }
	return score;
}

/*
* Omschrijving: loot een random getal tussen 1 en 13 (+1)
* @param:   getal = 1 tot 10 zijn de cijfers, 11 = boer, 12 = dame, 13 = heer
* @return:  getal
*/
int randomKaart()
{
	int getal = (rand() % 13) +1;
	return getal;
}

/*
* Omschrijving: waarde en grafische weergave van de kaarten
* @param:   a = de kaartwaarde : Aas is 1 maar kan 11 worden via waardeAas(), 2 tot 10 zijn de cijfers, 11 = boer, 12 = dame, 13 = heer
* @return:  a
*/
int kaart1()
{
  int a=1;
  printf("    _________ \n");
  printf("   |A        |\n");
  printf("   |+   *    |\n");
  printf("   |    !    |\n");
  printf("   |  *-+-*  |\n");
  printf("   |    |    |\n");
  printf("   |   ~~~  +|\n");
  printf("   |        V|\n");
  printf("    ~~~~~~~~~ \n");
  return a;
}

/*
* Omschrijving: waarde en grafische weergave van de kaarten
* @param:   a = de kaartwaarde : Aas is 1 maar kan 11 worden via waardeAas(), 2 tot 10 zijn de cijfers, 11 = boer, 12 = dame, 13 = heer
* @return:  a
*/
int kaart2()
{
	int a=2;
	printf("    _________ \n");
	printf("   |2        |\n");
	printf("   |+        |\n");
	printf("   |    +    |\n");
	printf("   |         |\n");
	printf("   |    +    |\n");
	printf("   |        +|\n");
	printf("   |        Z|\n");
	printf("    ~~~~~~~~~ \n");
	return a;
}

/*
* Omschrijving: waarde en grafische weergave van de kaarten
* @param:   a = de kaartwaarde : Aas is 1 maar kan 11 worden via waardeAas(), 2 tot 10 zijn de cijfers, 11 = boer, 12 = dame, 13 = heer
* @return:  a
*/
int kaart3()
{
	int a=3;
	printf("    _________ \n");
	printf("   |3        |\n");
	printf("   |+   +    |\n");
	printf("   |         |\n");
	printf("   |    +    |\n");
	printf("   |         |\n");
	printf("   |    +   +|\n");
	printf("   |        E|\n");
	printf("    ~~~~~~~~~ \n");
	return a;
}

/*
* Omschrijving: waarde en grafische weergave van de kaarten
* @param:   a = de kaartwaarde : Aas is 1 maar kan 11 worden via waardeAas(), 2 tot 10 zijn de cijfers, 11 = boer, 12 = dame, 13 = heer
* @return:  a
*/
int kaart4()
{
	int a=4;
	printf("    _________ \n");
	printf("   |4        |\n");
	printf("   |+        |\n");
	printf("   |  +   +  |\n");
	printf("   |         |\n");
	printf("   |  +   +  |\n");
	printf("   |        +|\n");
	printf("   |        b|\n");
	printf("    ~~~~~~~~~ \n");
	return a;
}

/*
* Omschrijving: waarde en grafische weergave van de kaarten
* @param:   a = de kaartwaarde : Aas is 1 maar kan 11 worden via waardeAas(), 2 tot 10 zijn de cijfers, 11 = boer, 12 = dame, 13 = heer
* @return:  a
*/
int kaart5()
{
	int a=5;
	printf("    _________ \n");
	printf("   |5        |\n");
	printf("   |+        |\n");
	printf("   |  +   +  |\n");
	printf("   |    +    |\n");
	printf("   |  +   +  |\n");
	printf("   |        +|\n");
	printf("   |        S|\n");
	printf("    ~~~~~~~~~ \n");
	return a;
}

/*
* Omschrijving: waarde en grafische weergave van de kaarten
* @param:   a = de kaartwaarde : Aas is 1 maar kan 11 worden via waardeAas(), 2 tot 10 zijn de cijfers, 11 = boer, 12 = dame, 13 = heer
* @return:  a
*/
int kaart6()
{
	int a=6;
	printf("    _________ \n");
	printf("   |6        |\n");
	printf("   |+ +   +  |\n");
	printf("   |         |\n");
	printf("   |  +   +  |\n");
	printf("   |         |\n");
	printf("   |  +   + +|\n");
	printf("   |        9|\n");
	printf("    ~~~~~~~~~ \n");
	return a;
}

/*
* Omschrijving: waarde en grafische weergave van de kaarten
* @param:   a = de kaartwaarde : Aas is 1 maar kan 11 worden via waardeAas(), 2 tot 10 zijn de cijfers, 11 = boer, 12 = dame, 13 = heer
* @return:  a
*/
int kaart7()
{
	int a=7;
	printf("    _________ \n");
	printf("   |7        |\n");
	printf("   |+ +   +  |\n");
	printf("   |    +    |\n");
	printf("   |  +   +  |\n");
	printf("   |         |\n");
	printf("   |  +   + +|\n");
	printf("   |        L|\n");
	printf("    ~~~~~~~~~ \n");
	return a;
}

/*
* Omschrijving: waarde en grafische weergave van de kaarten
* @param:   a = de kaartwaarde : Aas is 1 maar kan 11 worden via waardeAas(), 2 tot 10 zijn de cijfers, 11 = boer, 12 = dame, 13 = heer
* @return:  a
*/
int kaart8()
{
	int a=8;
	printf("    _________ \n");
	printf("   |8 +   +  |\n");
	printf("   |+        |\n");
	printf("   |  +   +  |\n");
	printf("   |         |\n");
	printf("   |  +   +  |\n");
	printf("   |        +|\n");
	printf("   |  +   + 8|\n");
	printf("    ~~~~~~~~~ \n");
	return a;
}

/*
* Omschrijving: waarde en grafische weergave van de kaarten
* @param:   a = de kaartwaarde : Aas is 1 maar kan 11 worden via waardeAas(), 2 tot 10 zijn de cijfers, 11 = boer, 12 = dame, 13 = heer
* @return:  a
*/
int kaart9()
{
	int a=9;
	printf("    _________ \n");
	printf("   |9 +   +  |\n");
	printf("   |+        |\n");
	printf("   |  +   +  |\n");
	printf("   |    +    |\n");
	printf("   |  +   +  |\n");
	printf("   |        +|\n");
	printf("   |  +   + 6|\n");
	printf("    ~~~~~~~~~ \n");
	return a;
}

/*
* Omschrijving: waarde en grafische weergave van de kaarten
* @param:   a = de kaartwaarde : Aas is 1 maar kan 11 worden via waardeAas(), 2 tot 10 zijn de cijfers, 11 = boer, 12 = dame, 13 = heer
* @return:  a
*/
int kaart10()
{
	int a=10;
	printf("    _________ \n");
	printf("   |10+   +  |\n");
	printf("   |+   +    |\n");
	printf("   |  +   +  |\n");
	printf("   |         |\n");
	printf("   |  +   +  |\n");
	printf("   |    +   +|\n");
	printf("   |  +   +0l|\n");
	printf("    ~~~~~~~~~ \n");
	return a;
}

/*
* Omschrijving: waarde en grafische weergave van de kaarten
* @param:   a = de kaartwaarde : Aas is 1 maar kan 11 worden via waardeAas(), 2 tot 10 zijn de cijfers, 11 = boer, 12 = dame, 13 = heer
* @return:  a
*/
int kaart11()
{
	int a=10;
	printf("    _________ \n");
	printf("   |J /~~|_  |\n");
	printf("   |+ | o`,  |\n");
	printf("   |  | -|   |\n");
	printf("   | =~)+(_= |\n");
	printf("   |   |- |  |\n");
	printf("   |  `.o | +|\n");
	printf("   |  ~|__/ P|\n");
	printf("    ~~~~~~~~~ \n");
	return a;
}

/*
* Omschrijving: waarde en grafische weergave van de kaarten
* @param:   a = de kaartwaarde : Aas is 1 maar kan 11 worden via waardeAas(), 2 tot 10 zijn de cijfers, 11 = boer, 12 = dame, 13 = heer
* @return:  a
*/
int kaart12()
{
	int a=10;
	printf("    _________ \n");
	printf("   |Q |~~~|  |\n");
	printf("   |+ /o,o\\  |\n");
	printf("   |  \\_-_/  |\n");
	printf("   | _-~+_-~ |\n");
	printf("   |  /~-~\\  |\n");
	printf("   |  \\o`o/ +|\n");
	printf("   |  |___| Q|\n");
	printf("    ~~~~~~~~~ \n");
	return a;
}

/*
* Omschrijving: waarde en grafische weergave van de kaarten
* @param:   a = de kaartwaarde : Aas is 1 maar kan 11 worden via waardeAas(), 2 tot 10 zijn de cijfers, 11 = boer, 12 = dame, 13 = heer
* @return:  a
*/
int kaart13()
{
	int a=10;
	printf("    _________ \n");
	printf("   |K |/|\\|  |\n");
	printf("   |+ /o,o\\  |\n");
	printf("   |  \\_-_/  |\n");
	printf("   | ~-_-~-_ |\n");
	printf("   |  /~-~\\  |\n");
	printf("   |  \\o`o/ +|\n");
	printf("   |  |\\|/| X|\n");
	printf("    ~~~~~~~~~ \n");
	return a;
}

/*
* Omschrijving: Verwelkomingsscherm met een korte omschrijving van de spelregels.
* @param:   printf()
* @return:  geen
*/
void printIntro(void)
{
	printf(" _    _ _____ _     _____ ________  __ _____\n");
	printf("| |  | |  ___| |   /  __ \\  _  |  \\/  |  ___|\n");
	printf("| |  | | |__ | |   | /  \\/ | | | .  . |  |__\n");
	printf("| |/\\| |  __|| |   | |   | | | | |\\/| |   __|\n");
	printf("\\  /\\  / |___| |___| \\__/\\ \\_/ / |  | |  |___\n");
	printf(" \\/  \\/\\____/\\_____/\\____/\\___/\\_|  |_/\\____/\n\n\n");

	printf(" _____\n");
	printf("|_   _|\n");
	printf("  | | ___\n");
	printf("  | |/ _ \\\n");
	printf("  | | (_) |\n");
	printf("  \\_/\\___/\n\n\n");

	printf("______ _       ___  _____  _   __   ___  ___  _____  _   __\n");
	printf("| ___ \\ |     / _ \\/  __ \\| | / /  |_  |/ _ \\/  __ \\| | / /\n");
	printf("| |_/ / |    / /_\\ \\ /  \\/| |/ /     | / /_\\ \\ /  \\/| |/ / \n");
	printf("| ___ \\ |    |  _  | |    |    \\     | |  _  | |    |    \\ \n");
	printf("| |_/ / |____| | | | \\__/\\| |\\  \\/\\__/ / | | | \\__/\\| |\\  \\\n");
	printf("\\____/\\_____/\\_| |_/\\____/\\_| \\_/\\____/\\_| |_/\\____/\\_| \\_/\n");

	printf("  \n");
    printf("  Dit is een variant van BlackJack. Je speelt tegen de computer (het huis).\n");
    printf("  Het is de bedoeling om 21, of 'BlackJack', te halen.\n");
    printf("  Als niemand BlackJack heeft wint diegene met de hoogste kaarten.\n");
    printf("  Maar wees niet overmoedig! Boven de 21 verlies je je inzet.\n");
    printf("  Bij gelijkspel wint het huis.\n");
    printf("  Is it your lucky day?? Have fun!\n");

}