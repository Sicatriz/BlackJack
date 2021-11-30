/*
* [Pas deze hoofding aan]
* Author(s): Gilissen Koen & Swinkels Wout
* Date: 1/11/2021
* Description: Start code voor blackjack spel
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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
void printIntro(void);

int main(void)
{
	srand(time(NULL));

	//DEMO Code voor testen van kaarten
  printIntro();
	for(int i = 0; i < AANTAL_DEMO_KAARTEN; i++)
	{
		geefKaart();
	}
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
  int a=0;
	char invoerGebruiker[10] = "";
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
