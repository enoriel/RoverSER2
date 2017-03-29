#ifndef _SCI_H
#define _SCI_H
#endifndef

#ifdef _SCI_H
extern struct Trame{	// Structure de la trame
	unsigned char En : 1;	// Déplacement
	unsigned char T0 : 1;	// Direction(0)
	unsigned char T1 : 1;	// Direction (1)
	unsigned char T2 : 1;	// Direction (2)
	unsigned char W0 : 1;	// Rotation (0)
	unsigned char W1 : 1;	// Rotation (1)
	unsigned char M : 1;	// Rotation (2)
	unsigned char V : 1;	// Autorisation écriture/lecture = 0, pas de lecture/écriture
};

extern struct Trame donnee;		// Déclare un champ de bit utilisable dans tout le programme; Utiliser pour récupéré et mettre à jour les variables de déplacement
extern unsigned char batterie;	// Variable accessible dans tout le programme; contient la dernière valeur de la batterie du rover
extern unsigned char buffer = 0;	// Buffer: contient la dernière valeur reçu lorsque donnee est 

static unsigned char SCI_Recieve(void); // Prototype de la fonction de réception SCI_Recieve
void SCI_Init(void); // Prototype de la fonction d'initiation des paramètres de la SCI (9600 8N1)
void SCI_Transmit(void);	// Prototype de la fonction de transmition

#endif 