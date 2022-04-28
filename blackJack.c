/*
* Author(s): Benjie Van Limbergen & Miguel Nunez
* Date: 6/12/2021
* Description: *** Blackjack spel *** taak C-programeren 1EAIC 2021-2022
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "blackJackLib.h"


// Declaratie finite State Machine
typedef enum
{
	Start_State,
	Stack_State,
	Start_Kaarten_Speler_State,
    Start_Kaarten_House_State,
    Nieuwe_Kaart_S_State,
    Nieuwe_Kaart_H_State,
	Punten_State,
    Reset_Point_State,
    BlackJack_Test_State,
    Winst_State,
    Verlies_State,
    New_Game_State
}fsmState;

int main(void)
{
fsmState nextState = Start_State;
char voorNaam[20];
int kpSpeler = 0;   //kaart punten totaal van de speler
int kpHouse = 0;    //kaart punten totaal van het huis
short actief = 2;   //actief: 0 = spelerbeurt, 1 = Housebeurt
int stack = 100;    //start stack begin spel
int inzet = 101;    //startwaarde inzet voor correct verloop whileloop
short startHand = 0;    //starthand: 0 = eender welke andere hand, 1 = eerste ronde waarin 2 kaarten gedeeld worden
char hit = 'x';     //Y of N nieuwe kaart variabele
char newGame = 'x'; //Y of N nieuw spel variabele

    while (1)
    {
        switch (nextState)
        {
            //startscherm spel
        case Start_State:
            srand(time(NULL));      //randomize 
            system("cls");
            printIntro();                           //Welkomstscherm & speluitleg.
	        printf("\nGeef uw voornaam in: \n");
	        gets(voorNaam);                         //naam speler opslaan.
			system("cls");
            nextState = Stack_State;                //ga naar inzet bepaling
            break;
        case Stack_State:                           // controle stack en vraag inzet van de speler
                while (inzet > stack || inzet < 1)
                {
                    printf("Dag %s, \n", voorNaam);
                    printf("U hebt nu %d euro.\nBij winst krijgt u 1,5 keer je inzet.\n\n", stack);
			        printf("Hoeveel euro wilt U voor dit spel inzetten? \n(Minimum 1 en maximum %d euro.)\n", stack);
	                scanf( "%d", &inzet);
                }                   
			stack = stack - inzet;                  //verrekend de inzet
			system("cls");
		    printf("          * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
            printf("          %s, uw inzet is %d euro. Succes met het spel!\n", voorNaam, inzet);
            printf("          * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
            nextState = Start_Kaarten_Speler_State; //ga naar startkaarten speler
            break;
        case Start_Kaarten_Speler_State:            // Startkaarten speler trekken
            printf("KAARTEN %s :\n", voorNaam);
            kpSpeler = deelStartKaarten(kpSpeler);  
            actief = 0;                             //beurt speler
            startHand = 1;                          //eerste ronde van het spel
            nextState = BlackJack_Test_State;       //controle op 21
            break;
        case Start_Kaarten_House_State:             // startkaarten huis trekken
            printf("\nKAARTEN HOUSE :\n");
            kpHouse = deelStartKaarten(kpHouse);
            actief = 1;                             //beurt huis
            startHand = 0;                          // EINDE eerste ronde van het spel
            nextState = BlackJack_Test_State;       //controle op 21
            break;
        case Nieuwe_Kaart_S_State:                  // 1 kaart  speler trekken
            startHand = 0;
            actief = 0;
            while(getchar() != '\n');
            while ((hit !='y') && (hit !='n'))
			{
			printf("\nWenst U een nieuwe kaart? Y of N\n ");
            
            hit = getchar();
            hit = tolower(hit);	
			}
            if (hit == 'y')
            {
                printf("KAART %s :\n", voorNaam);
                kpSpeler = newCard(kpSpeler);
                hit = 'x';
                nextState = BlackJack_Test_State;
                break;
            }
            else
            {
                nextState = Nieuwe_Kaart_H_State;
                break;
            }
            break;
        case Nieuwe_Kaart_H_State:                 // 1 kaart  speler trekken
            startHand = 0;
            actief = 1;

            if (kpHouse <17)
            {
                printf("\nKAART HOUSE :\n");
                kpHouse = newCard(kpHouse);
                nextState = BlackJack_Test_State;
                break;
            }
            else
            {
                printf("          * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
                printf("          * * * * * * * * * Het huis stopt! * * * * * * * * *\n");
                printf("          * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");

                nextState = Punten_State;
                break;
            }
            break;
        case Punten_State:                      // toont stand kaarten & controleert / verwijst naar volgende state
		    printf("          * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
            printf("          * * * * * * * SPELER %d vs HOUSE %d * * * * * * * *\n", kpSpeler, kpHouse);
            printf("          * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
            if (kpSpeler > 21)
            {
                nextState = Verlies_State;
                break;
            }
            else if (kpHouse > 21)
            {
                nextState = Winst_State;
                break;
            }
            else
            {    
                if (hit == 'n')
                {
                    if (kpHouse < 22 && kpHouse > 16)
                    {
                        if (kpSpeler > kpHouse)
                        {
                            nextState = Winst_State;
                            break;
                        }
                        else
                        {
                            nextState = Verlies_State;
                            break;
                        }    
                    }
                    else
                    {
                        nextState = Nieuwe_Kaart_H_State;
                        break;
                    }    
                }
                else
                {
                    nextState = Nieuwe_Kaart_S_State;
                    break;
                }        
            }   
            break;
        case Reset_Point_State:             //reset waardes voor nieuw spel, houd wel stack bij
            kpSpeler = 0;
            kpHouse = 0;
            //actief: 0 = spelerbeurt, 1 = Housebeurt
            actief = 2;
            inzet = stack +1;
            //starthand: 0 = eender welke andere hand, 1 = eerste ronde waarin 2 kaarten gedeeld worden
            startHand = 0;
            hit = 'x';
            newGame = 'x';
            nextState = Stack_State;
            break;
        case BlackJack_Test_State:      //test of iemand blackjack heeft
            if (startHand == 1)
            {
                switch (actief)
                {
                case 0:
                    if (kpSpeler == 21)
                    {
                        printf("          * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
                        printf("          * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
                        printf("          * * * * * * Het %s heeft BLACKJACK! * * * * * * *\n", voorNaam);
                        printf("          * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
                        printf("          * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
                        nextState = Winst_State;
                        break;
                    }
                     else
                    {
                        nextState = Start_Kaarten_House_State;
                        break;
                    }                    
                    break;
                case 1:
                    if (kpHouse == 21)
                    {
		                printf("          * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
                        printf("          * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
                        printf("          * * * * * * Het huis heeft BLACKJACK! * * * * * * *\n");
                        printf("          * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
                        printf("          * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
                        nextState = Verlies_State;
                        break;
                    }
                    else
                    {
                        nextState = Nieuwe_Kaart_S_State;
                        break;
                    }
                    break;                
                default:
                    break;
                }
            }
            else
            {
                switch (actief)
                {
                case 0:
                    if (kpSpeler == 21)
                    {
                        nextState = Winst_State;
                        break;
                    }
                     else
                    {
                        nextState = Nieuwe_Kaart_H_State;
                        break;
                    }                    
                    break;
                case 1:
                    if (kpHouse == 21)
                    {
		                printf("          * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
                        printf("          * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
                        printf("          * * * * * * Het huis heeft BLACKJACK! * * * * * * *\n");
                        printf("          * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
                        printf("          * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
                        nextState = Verlies_State;
                        break;
                    }
                    else
                    {
                        nextState = Punten_State;
                        break;
                    }
                    break;                
                default:
                    break;
                }
            }
            break;
        case Winst_State:       // print in geval van winst en toont saldo
            printf("          * * * * * * * * U heeft GEWONNEN !!!* * * * * * * *\n\n");
            stack = stack + inzet + (inzet * 1.5);
            printf("Uw nieuw speelsaldo is %d euro\n", stack);
            nextState = New_Game_State;
            break;
        case Verlies_State:     // print in geval van verlies en toont saldo
            printf("          * * * * * * * * U heeft VERLOREN !!!* * * * * * * *\n\n");
            printf("Uw speelsaldo is %d euro.\n", stack);
            if (stack <=0)
            {
                printf("          \n\n\n          * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
                printf("          * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
                printf("          * * Helaas! Zonder geld kan je niet verder spelen.* *\n");
                printf("          * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
                printf("          * * Bedankt voor het spelen, tot de volgende keer!* *\n");
                printf("          * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
                printf("          * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
                printf("          * * * * * * * * * * * * * Benjie & Miguel productions\n\n");
                _Exit(0);
                break;
            }
            else
            {
                nextState = New_Game_State;
                break;
            }
        case New_Game_State:            //start nieuw spel
            while(getchar() != '\n');            // zorgt dat '\n' uit buffer gaat
            while ((newGame !='y') && (newGame !='n'))
			{
			printf("Wil U nog een ronde spelen met dit saldo? Y of N \n ");
            newGame = getchar();
            newGame = tolower(newGame);	
			}
            if (newGame == 'y')
            {   
                nextState = Reset_Point_State;
                break;
            }
            else
            {
                system("cls");
                printf("          \n\n\n\n          * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
                printf("          * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
                printf("          * * | ===============================================|* *\n");
                printf("          * * | Bedankt voor het spelen, tot de volgende keer! |* *\n");
                printf("          * * | ===============================================|* *\n");
                printf("          * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
                printf("          * * * * * * * * * * * * * * * Benjie & Miguel productions\n");
                _Exit(0);
                break;
            }   
            break;
        default:
            break;
        }
    }
}

