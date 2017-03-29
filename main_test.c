#include <stdio.h>
#include "SCI.c"

/* --------------- Programme de test
Protocol de test des erreurs de reception (perturbation des ondes)
- Distance: 100m
- Protocole: envoit du même octet en continue sur un premier module (Carte Eval#2) et reception sur le second module (Carte Eval #2) puis comparaison entre l'octet reçu et l'octet de référence. Deux variables (error et count):
														-> Error : initialisation à 0, incrémentation de 1 à chaque erreur détecté
														-> Count: Implémentation à chaque octet reçu
*/
void main(){
	
	MCU_Init();
	SCI_Init();
	
}