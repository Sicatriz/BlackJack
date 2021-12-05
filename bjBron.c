/*
* Author(s): Benjie Vanlimbergen & Miguel Nunez
* Date: 6/12/2021
* Description: Start code voor blackjack spel
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include<conio.h>

#define AANTAL_DEMO_KAARTEN 3

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
int waardeAas();
int stack();
int restart();
int winst();
int verlies();
int nieuw();
void printIntro(void);

char voorNaam[20] = "player";
// deling van eerste hand
//int speler = geefKaart();
int kaartPuntSpeler = 0;
int kaartPuntHouse = 0;
int kaartPunt = 0;
int totaalSpeler = 0;
int totaalHouse = 0;
int aceSpeler = 0;
int aceHouse = 0;
double credits = 10;
double inzet = 0;
char actief = 'S';
char new = 'x';
char hit = 'x';
char stand = 'x';

int main(void)
{
	srand(time(NULL));

	//Welkomstscherm & speluitleg
  printIntro();

	//naam speler opslaan.
	printf("Geef uw voornaam in: \n");
	scanf("%s", &voorNaam);

	//print het aantal beschikbare credits, vraagt naar gewenste inzet en verrekend deze.
	stack();

	startGame:
	// delen van eerste 2 spelerskaarten.
	for(int i = 0; i < 2; i++)
		{
			// Speler actief en krijgt kaarten.
			actief = 'S';
			kaartPunt = geefKaart();

			// waardebepaling indien de SPELER een AAS trekt.
			if (kaartPunt == 1) {
				kaartPunt = waardeAas();
			}

			// scoreberekening spelershand na startkaarten.
			kaartPuntSpeler = kaartPunt;
			printf("KPS %d\n",kaartPuntSpeler );
			kaartPunt = 0;
			totaalSpeler = kaartPuntSpeler + totaalSpeler;
		}

	// print de handscore van de speler.
	printf("\nU heeft nu %d punten in de hand\n\n", totaalSpeler);

	// indien de speler meteen een BLACKJACK getrokken heeft en de ronde wint.
	if (totaalSpeler == 21) {
			printf("U heeft een BLACKJACK en heeft %.2f credits GEWONNEN\n", inzet + (inzet*1.5));

			// verreken de inzet en totaal credits.
			credits = credits + inzet + (inzet*1.5);

			// print stand credits en vraagt naar nieuw spel of stoppen.
			nieuw();
			if (new == 'y') {
			restart();
			goto startGame;
			}  else {
			goto end;
			}

	}

	// delen eerste 2 kaarten HOUSE.
	for(int i = 0; i < 2; i++)
		{
			// HOUSE actief en krijgt kaarten.
			actief = 'H';
			kaartPunt = geefKaart();

			// waardebepaling indien de HOUSE een AAS trekt.
			if (kaartPunt == 1) {
				kaartPunt = waardeAas();
			}
			// scoreberekening HOUSEhand na startkaarten.
			kaartPuntHouse = kaartPunt;
			printf("KPH %d\n",kaartPuntHouse );
			kaartPunt = 0;
			totaalHouse = kaartPuntHouse + totaalHouse;

		}
		// print de handscore van HOUSE.
		printf("\nHet huis heeft nu %d punten in de hand\n", totaalHouse);

	// indien HOUSE meteen een BLACKJACK getrokken heeft (speler niet) en HOUSE wint de ronde.
	if (totaalHouse == 21) {
			printf("Het Huis heeft een BLACKJACK! ");
			// print stand credits en vraagt naar nieuw spel of stoppen.
			verlies();
			// print stand credits en vraagt naar nieuw spel of stoppen.
			nieuw();
			if (new == 'y') {
				restart();
				goto startGame;
			}  else {
				goto end;
			}
	}

	// wilt de speler nog een kaart bij.
	do {
    printf("Wenst U een nieuw kaart te hitten? Y of N ");
		scanf(" %c", &hit);
		} while (hit != 'y' && hit != 'n');

			if (hit == 'n') {
				stand == 'y';
			}

	// y == speler wilt een kaart bij.
	do {
		if (hit == 'y') {

			//KAART SPELER
			// Speler actief en krijgt kaarten.
			actief = 'S';
			kaartPunt = geefKaart();

			// waardebepaling indien de SPELER een AAS trekt.
			if (kaartPunt == 1) {
				kaartPunt = waardeAas();
			}

			// scoreberekening spelershand na startkaarten.
			kaartPuntSpeler = kaartPunt;
			kaartPunt = 0;
			totaalSpeler = kaartPuntSpeler + totaalSpeler;

			// print de handscore van de speler.
			printf("\nU heeft nu %d punten in de hand\n\n", totaalSpeler);

			// ----------------

			if (totaalHouse > 17 && totaalHouse < 22) {
				printf("Vanaf 17 punten stopt het huis.\n" );
			} else {
				//KAART HOUSE
				// HOUSE actief en krijgt kaarten.
				actief = 'H';
				kaartPunt = geefKaart();

				// waardebepaling indien de HOUSE een AAS trekt.
				if (kaartPunt == 1) {
					kaartPunt = waardeAas();
				}
				// scoreberekening HOUSEhand na startkaarten.
				kaartPuntHouse = kaartPunt;
				kaartPunt = 0;
				totaalHouse = kaartPuntHouse + totaalHouse;
			}
			// print de handscore van HOUSE.
			printf("\nHet huis heeft nu %d punten in de hand\n", totaalHouse);

		} else {
			/* code */
		}




	} while(stand != 'y');









		end:
		printf("nog verder af te werken\n");
}

//Nieuw spel Y/N
int nieuw()
{
	printf("Uw huidig saldo bedraagd %.2lf credits ", credits );
	do {
		printf("Wenst U een nieuwe ronde te spelen? Y of N ");
		scanf(" %c", &new);
	} while (new != 'y' && new != 'n');
	scanf("%s", &new );
}

//Feedback WINST
int winst()
{


}

//Feedback VERLOREN
int verlies()
{
	printf("U heeft VERLOREN!\n");
}

// reset waardes voor een nieuw spel.
int restart()
{
		kaartPuntSpeler = 0;
		kaartPuntHouse = 0;
		kaartPunt = 0;
		totaalSpeler = 0;
		totaalHouse = 0;
		aceSpeler = 0;
		aceHouse = 0;
		new = 'x';
		hit = 'x';
		stand = 'x';

		return 0;
}

// vraagt de inzet van de speler, deze mag niet groter zijn dan de credits noch kleiner dan 0.
int stack()
{
	while (inzet <= 0 || inzet > credits) {
		printf("\nDag %s,\n\nU start met 10 credits.\nHoeveel credits wilt u inzetten voor dit spel?\n\n", voorNaam );
		scanf("%lf", &inzet );
		break;
	}
	credits = credits - inzet;
	printf("Nieuw saldo: %.2lf credits\n\n", credits);

	return 0;
}

// bepaalt de waarde van de aas.
int waardeAas(kaartPunt)
{
	if (actief == 'S') {
		if (aceSpeler == 0 && totaalSpeler <11) {
			kaartPunt = 11;
			aceSpeler = 1;
		} else if (aceSpeler == 0 && totaalSpeler >10) {
			kaartPunt = 1;
			aceSpeler = 1;
		} else if (aceSpeler == 1 && totaalSpeler < 11) {
			kaartPunt = 11;	} else {
			kaartPunt == 1;}
	}	else if (actief == 'H') {
		if (aceHouse == 0 && totaalHouse <11) {
			kaartPunt = 11;
			aceHouse = 1;
		} else if (aceHouse == 0 && totaalHouse >10) {
			kaartPunt = 1;
			aceHouse = 1;
		} else if (aceHouse == 1 && totaalHouse < 11) {
			kaartPunt = 11;	} else {
			kaartPunt == 1;}
	}
	return kaartPunt;
}

// bepalen welke kaart gedeeld zal worden.
int geefKaart(kaartPunt)
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

//pseudo randomize kaarten.
int randomKaart()
{
	int getal = (rand() % 13) +1;
	return getal;
}

// grafische weergave kaarten en return waarde.
int kaart1(score)
{
  int a=1;
	int i;

//	waarde AAS zal automatisch aangepast worden om een zo goed mogelijke hand te bekomen, zowel voor speler als HOUSE.
  printf(" _________ \n");
  printf("|A        |\n");
  printf("|+   *    |\n");
  printf("|    !    |\n");
  printf("|  *-+-*  |\n");
  printf("|    |    |\n");
  printf("|   ~~~  +|\n");
  printf("|        V|\n");
  printf(" ~~~~~~~~~ \n");

  return a;
}

int kaart2(score)
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

int kaart3(score)
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

int kaart4(score)
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

int kaart5(score)
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

int kaart6(score)
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

int kaart7(score)
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

int kaart8(score)
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

int kaart9(score)
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

int kaart10(score)
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
int kaart11(score)
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

int kaart12(score)
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

int kaart13(score)
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

// Introductie spel.
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
