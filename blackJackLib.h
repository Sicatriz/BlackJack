/*
* Author(s): Benjie Van Limbergen & Miguel Nunez
* Date: 6/12/2021
* Description: *** Blackjack spel *** taak C-programeren 1EAIC 2021-2022
*/

#ifndef _BLACKJACKLIB_H_
#define _BLACKJACKLIB_H_

#include "blackJackLib.h"

/*
* Omschrijving: trekt 1 enkele nieuwe kaart
* @param:   puntTotaal = totaalwaarde in hand van speler of house
* @param: punt = de waarde van de kaart
* @return:  puntTotaal
*/
int newCard(int puntTotaal);

/*
* Omschrijving: trekt de 2 startkaarten
* @param:   puntTotaal = totaalwaarde in hand van speler of house
* @param: punt = de waarde van de kaart
* @return:  puntTotaal
*/
int deelStartKaarten(int puntTotaal);

/*
* Omschrijving: controle en bepaling waarde van Aas; indien mogelijk waarde 11, anders 1
* @param:   puntTotaal = totaalwaarde in hand van speler of house
* @param: punt = de waarde van de kaart
* @return:  punt
*/
int waardeAas(int punt, int puntTotaal);

/*
* Omschrijving: trekt een randomkaart uit het boek
* @param:   kaart = een random getal tussen 1 en 13
* @param: score = de waarde die de kaart heeft, uitgezonderd voor Aas waarbij de waarde finaal bepaald zal worden in waardeAas()
* @return:  score
*/
int geefKaart();

/*
* Omschrijving: loot een random getal tussen 1 en 13 (+1)
* @param:   getal = 1 tot 10 zijn de cijfers, 11 = boer, 12 = dame, 13 = heer
* @return:  getal
*/
int randomKaart();

/*
* Omschrijving: waarde en grafische weergave van de kaarten
* @param:   a = de kaartwaarde : Aas is 1 maar kan 11 worden via waardeAas(), 2 tot 10 zijn de cijfers, 11 = boer, 12 = dame, 13 = heer
* @return:  a
*/
int kaart1();

/*
* Omschrijving: waarde en grafische weergave van de kaarten
* @param:   a = de kaartwaarde : Aas is 1 maar kan 11 worden via waardeAas(), 2 tot 10 zijn de cijfers, 11 = boer, 12 = dame, 13 = heer
* @return:  a
*/
int kaart2();

/*
* Omschrijving: waarde en grafische weergave van de kaarten
* @param:   a = de kaartwaarde : Aas is 1 maar kan 11 worden via waardeAas(), 2 tot 10 zijn de cijfers, 11 = boer, 12 = dame, 13 = heer
* @return:  a
*/
int kaart3();

/*
* Omschrijving: waarde en grafische weergave van de kaarten
* @param:   a = de kaartwaarde : Aas is 1 maar kan 11 worden via waardeAas(), 2 tot 10 zijn de cijfers, 11 = boer, 12 = dame, 13 = heer
* @return:  a
*/
int kaart4();

/*
* Omschrijving: waarde en grafische weergave van de kaarten
* @param:   a = de kaartwaarde : Aas is 1 maar kan 11 worden via waardeAas(), 2 tot 10 zijn de cijfers, 11 = boer, 12 = dame, 13 = heer
* @return:  a
*/
int kaart5();

/*
* Omschrijving: waarde en grafische weergave van de kaarten
* @param:   a = de kaartwaarde : Aas is 1 maar kan 11 worden via waardeAas(), 2 tot 10 zijn de cijfers, 11 = boer, 12 = dame, 13 = heer
* @return:  a
*/
int kaart6();

/*
* Omschrijving: waarde en grafische weergave van de kaarten
* @param:   a = de kaartwaarde : Aas is 1 maar kan 11 worden via waardeAas(), 2 tot 10 zijn de cijfers, 11 = boer, 12 = dame, 13 = heer
* @return:  a
*/
int kaart7();

/*
* Omschrijving: waarde en grafische weergave van de kaarten
* @param:   a = de kaartwaarde : Aas is 1 maar kan 11 worden via waardeAas(), 2 tot 10 zijn de cijfers, 11 = boer, 12 = dame, 13 = heer
* @return:  a
*/
int kaart8();

/*
* Omschrijving: waarde en grafische weergave van de kaarten
* @param:   a = de kaartwaarde : Aas is 1 maar kan 11 worden via waardeAas(), 2 tot 10 zijn de cijfers, 11 = boer, 12 = dame, 13 = heer
* @return:  a
*/
int kaart9();

/*
* Omschrijving: waarde en grafische weergave van de kaarten
* @param:   a = de kaartwaarde : Aas is 1 maar kan 11 worden via waardeAas(), 2 tot 10 zijn de cijfers, 11 = boer, 12 = dame, 13 = heer
* @return:  a
*/
int kaart10();

/*
* Omschrijving: waarde en grafische weergave van de kaarten
* @param:   a = de kaartwaarde : Aas is 1 maar kan 11 worden via waardeAas(), 2 tot 10 zijn de cijfers, 11 = boer, 12 = dame, 13 = heer
* @return:  a
*/
int kaart11();

/*
* Omschrijving: waarde en grafische weergave van de kaarten
* @param:   a = de kaartwaarde : Aas is 1 maar kan 11 worden via waardeAas(), 2 tot 10 zijn de cijfers, 11 = boer, 12 = dame, 13 = heer
* @return:  a
*/
int kaart12();

/*
* Omschrijving: waarde en grafische weergave van de kaarten
* @param:   a = de kaartwaarde : Aas is 1 maar kan 11 worden via waardeAas(), 2 tot 10 zijn de cijfers, 11 = boer, 12 = dame, 13 = heer
* @return:  a
*/
int kaart13();

/*
* Omschrijving: Verwelkomingsscherm met een korte omschrijving van de spelregels.
* @param:   printf()
* @return:  geen
*/
void printIntro(void);

#endif