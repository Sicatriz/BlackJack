/*
* [Pas deze hoofding aan]
* Author(s): Benjie Vanlimbergen & Miguel Nunez
* Date: 6/12/2021
* Description: *** Blackjack spel *** taak C-programeren 1EAIC 2021-2022
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

int geefKaart();
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
int randomKaart();
void printIntro(void);
int deelStartKaarten();
int waardeAas();
int blackJack();
int kaartBij();
int kaartBijHouse();
int deelNieuweKaart();
void gewonnen();
void verloren();
int checkHandWaarde();

int main(void)
{

char voorNaam[20];
int kpSpeler = 0;
int kpHouse = 0;
// actief 0 = neutraal, actief 1 = SPELER, actief 2 = HOUSE
int actief = 0;
char hit = 'x';
char result = 'x';
int giveMe = 2;

	srand(time(NULL));

	//Welkomstscherm & speluitleg.
    system("cls");
    printIntro();

    //naam speler opslaan.
	printf("\nGeef uw voornaam in: \n");
	gets(voorNaam);
    system("cls");
//    printf("Dag %s , succes met het spel!.\n\n Uw starthand is : \n\n", voorNaam);

    //speler krijgt starthand en print punten.
    printf("* * * * * * * * * * * *\nKaarten %s\n* * * * * * * * * * * *\n", voorNaam);
    kpSpeler = deelStartKaarten(kpSpeler);
//    printf("\nHandwaarde SPELER = %d\n", kpSpeler);
        

    //House krijgt starthand en print punten.
    printf("\n* * * * * * * * * * * *\nKaarten HOUSE\n* * * * * * * * * * * *\n");
    kpHouse = deelStartKaarten(kpHouse);
//    printf("\nHandwaarde HOUSE = %d\n", kpHouse);
        
    printf("\nSPELER %d vs HOUSE %d\n", kpSpeler, kpHouse);

        //controle op Blackjacks
        if (kpSpeler == 21)
        {
            actief = 1;
            actief = blackJack(actief);
            return 0;
        }
        else if (kpHouse == 21)
        {
            actief = 2;
            actief = blackJack(actief);
            printf("actief = %d\n", actief);
            return 0;
        }
                
    //kaart bijvragen of niet. (giveMe 0 = N ||  giveMe 1 = Y)
    while (hit != 'y' && hit != 'n')
    {
	    printf("Wenst U een nieuw kaart te hitten? Y of N \n");
	    scanf("%c", &hit);
        result = tolower(hit);
            if (result == 'y')
            {
               giveMe = 1; 
            }
            else
            {
                giveMe = 0;
            }   

        kpSpeler = kpSpeler + kaartBij(kpSpeler, giveMe);
        printf("\nHandwaarde SPELER = %d\n", kpSpeler);

            if (kpHouse <17)
        {
            kpHouse = kpHouse + kaartBijHouse(kpHouse, giveMe);
//        printf("\nHandwaarde HOUSE = %d\n", kpHouse);
        } else if (kpHouse < 22)
        {
            printf("\nHOUSE past met %d\n", kpHouse);
        }   
 
        checkHandWaarde(kpSpeler, kpHouse);
	}


        

}

//controle op waarden in hand tussen speler & House
int checkHandWaarde(int kpSpeler, int kpHouse)
{
    if (kpSpeler > kpHouse && kpSpeler < 22 && kpHouse > 16)
    {
        gewonnen();
        return 0;
    }
    else if (kpSpeler <22 && kpHouse > 21)
    {
        printf("\n*** HOUSE is BUST *** || ");
        gewonnen();
        return 0;
    }
    else if (kpSpeler > 21)
    {
        printf("\nU bent BUST ... !!! ");
        verloren();
        return 0;
    }
    else
    {
        printf("\nSPELER %d vs HOUSE %d\n", kpSpeler, kpHouse);
    }
    
    return 0;
}
//kaart bij HOUSE
int kaartBijHouse(int puntTotaal)
{
    if (puntTotaal < 18)
    {
        puntTotaal = deelNieuweKaart();
    }
    else if (puntTotaal > 21)
    {
        printf("*** HOUSE is BUST *** || ");
        gewonnen();
    } else
    {
        printf("HOUSE PAST \n");
    }
     
    return puntTotaal;
}

//kaart bijvragen
int kaartBij(int puntTotaal, int giveMe)
{
    if (giveMe == 1)
    {
       puntTotaal = deelNieuweKaart();   
    }
    else if (giveMe == 0)
    {
        //code verder schrijven
    }
    else
    {
        printf("U heeft een ongeldig karakter ingegeven.");
    }  
    return puntTotaal;
}

//Hand maakt blackjack
int blackJack(int actief)
{
    switch (actief)
    {
    case 1:
        printf("*** BLACKJACK !!! *** || ");
        gewonnen();
        break;

    case 2:
        printf("HOUSE heeft BLACKJACK ... ");
        verloren();
        break;
    
    default:
        printf("Er is geen actieve speler ...");
        break;
    }

    return 0;
}

//tekst bij winst
void gewonnen()
{
    printf("U heeft GEWONNEN !!!\n");
}

//tekst bij verlies
void verloren()
{
    printf("U heeft VERLOREN... !!!\n");
}

// deel nieuwe kaart
int deelNieuweKaart()
{
int punt = 0;
int puntTotaal = 0;	

	punt = geefKaart();

    if (punt == 1)  {
        punt = waardeAas(punt, puntTotaal);}      

    printf("waarde kaart: %d \n", punt);
    puntTotaal = puntTotaal + punt;

    return puntTotaal;
}

// deelt startkaarten
int deelStartKaarten(int puntTotaal)
{
int punt = 0;
    for(int i = 0; i < 2; i++)
	{
		punt = geefKaart();

        if (punt == 1)  {
            punt = waardeAas(punt, puntTotaal);}      

//        printf("waarde kaart: %d \n", punt);
        puntTotaal = puntTotaal + punt;
	}
    return puntTotaal;
}

// Waardecontrole AAS (1 of 11 punten)
int waardeAas(int punt, int puntTotaal)
{
    if (puntTotaal <11) {
        punt = 11;}
    else {
        punt = 1;}

    return punt;    
}

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

int randomKaart()
{
	int getal = (rand() % 13) +1;
	return getal;
}

int kaart1()
{
  int a=1;
//	char invoerGebruiker[10] = "";
  printf(" _________ \n");
  printf("|A        |\n");
  printf("|+   *    |\n");
  printf("|    !    |\n");
  printf("|  *-+-*  |\n");
  printf("|    |    |\n");
  printf("|   ~~~  +|\n");
  printf("|        V|\n");
  printf(" ~~~~~~~~~ \n");

	// a moet 11 of 1 worden a.d.h.v. user input
  return a;
}

int kaart2()
{
	int a=2;
	printf(" _________ \n");
	printf("|2        |\n");
	printf("|+        |\n");
	printf("|    +    |\n");
	printf("|         |\n");
	printf("|    +    |\n");
	printf("|        +|\n");
	printf("|        Z|\n");
	printf(" ~~~~~~~~~ \n");
	return a;
}

int kaart3()
{
	int a=3;
	printf(" _________ \n");
	printf("|3        |\n");
	printf("|+   +    |\n");
	printf("|         |\n");
	printf("|    +    |\n");
	printf("|         |\n");
	printf("|    +   +|\n");
	printf("|        E|\n");
	printf(" ~~~~~~~~~ \n");
	return a;
}

int kaart4()
{
	int a=4;
	printf(" _________ \n");
	printf("|4        |\n");
	printf("|+        |\n");
	printf("|  +   +  |\n");
	printf("|         |\n");
	printf("|  +   +  |\n");
	printf("|        +|\n");
	printf("|        b|\n");
	printf(" ~~~~~~~~~ \n");
	return a;
}

int kaart5()
{
	int a=5;
	printf(" _________ \n");
	printf("|5        |\n");
	printf("|+        |\n");
	printf("|  +   +  |\n");
	printf("|    +    |\n");
	printf("|  +   +  |\n");
	printf("|        +|\n");
	printf("|        S|\n");
	printf(" ~~~~~~~~~ \n");
	return a;
}

int kaart6()
{
	int a=6;
	printf(" _________ \n");
	printf("|6        |\n");
	printf("|+ +   +  |\n");
	printf("|         |\n");
	printf("|  +   +  |\n");
	printf("|         |\n");
	printf("|  +   + +|\n");
	printf("|        9|\n");
	printf(" ~~~~~~~~~ \n");
	return a;
}

int kaart7()
{
	int a=7;
	printf(" _________ \n");
	printf("|7        |\n");
	printf("|+ +   +  |\n");
	printf("|    +    |\n");
	printf("|  +   +  |\n");
	printf("|         |\n");
	printf("|  +   + +|\n");
	printf("|        L|\n");
	printf(" ~~~~~~~~~ \n");
	return a;
}

int kaart8()
{
	int a=8;
	printf(" _________ \n");
	printf("|8 +   +  |\n");
	printf("|+        |\n");
	printf("|  +   +  |\n");
	printf("|         |\n");
	printf("|  +   +  |\n");
	printf("|        +|\n");
	printf("|  +   + 8|\n");
	printf(" ~~~~~~~~~ \n");
	return a;
}

int kaart9()
{
	int a=9;
	printf(" _________ \n");
	printf("|9 +   +  |\n");
	printf("|+        |\n");
	printf("|  +   +  |\n");
	printf("|    +    |\n");
	printf("|  +   +  |\n");
	printf("|        +|\n");
	printf("|  +   + 6|\n");
	printf(" ~~~~~~~~~ \n");
	return a;
}

int kaart10()
{
	int a=10;
	printf(" _________ \n");
	printf("|10+   +  |\n");
	printf("|+   +    |\n");
	printf("|  +   +  |\n");
	printf("|         |\n");
	printf("|  +   +  |\n");
	printf("|    +   +|\n");
	printf("|  +   +0l|\n");
	printf(" ~~~~~~~~~ \n");
	return a;
}

int kaart11()
{
	int a=10;
	printf(" _________ \n");
	printf("|J /~~|_  |\n");
	printf("|+ | o`,  |\n");
	printf("|  | -|   |\n");
	printf("| =~)+(_= |\n");
	printf("|   |- |  |\n");
	printf("|  `.o | +|\n");
	printf("|  ~|__/ P|\n");
	printf(" ~~~~~~~~~ \n");
	return a;
}

int kaart12()
{
	int a=10;
	printf(" _________ \n");
	printf("|Q |~~~|  |\n");
	printf("|+ /o,o\\  |\n");
	printf("|  \\_-_/  |\n");
	printf("| _-~+_-~ |\n");
	printf("|  /~-~\\  |\n");
	printf("|  \\o`o/ +|\n");
	printf("|  |___| Q|\n");
	printf(" ~~~~~~~~~ \n");
	return a;
}

int kaart13()
{
	int a=10;
	printf(" _________ \n");
	printf("|K |/|\\|  |\n");
	printf("|+ /o,o\\  |\n");
	printf("|  \\_-_/  |\n");
	printf("| ~-_-~-_ |\n");
	printf("|  /~-~\\  |\n");
	printf("|  \\o`o/ +|\n");
	printf("|  |\\|/| X|\n");
	printf(" ~~~~~~~~~ \n");
	return a;
}

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

	printf("<< Uitleg voeg je hier toe\n");
}