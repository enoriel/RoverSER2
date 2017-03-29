#include "SCI.H"

static unsigned char SCI_Recieve(void){
	while(SCI1S1_RDRF==0){
	}
	return SCID;
}

static void SCI_Transmit(unsigned char data){
	while(TC == 0){
	}
	SCID = data;
}

/* Initiation pour 25,165824Mhz */
extern void SCI_Init(void){
	SCIBDL = 0xA4;	// On configure le BR pour un baudrate à 6900 et une fréquence de bus de 25,165824Mhz
	SCI1C1_M = 0;	// Trame constitué de: 1bit start, 8 bits données, 1 bit stop
	SCI1C2_TE = 1;
	SCI1C2_RE = 1;
	SCI1C2_TCIE = 0;
}


extern void Func_Update(unsigned char data){
	donnee.V = 1;
	donnee = data;
	donnee.V = 0;
	SCI_Transmit(donnee);
}

static void SCI_Reception(){ // Place les données reçu dans "donnee"
	if(buffer != 0){		// Vérifie qu'il n'y a pas de valeur déjà présente dans le buffer
		donnee = buffer;
		buffer = 0;			// RaZ du buffer
	}
	else {
		switch(donnee.V){
			case 0:
				donnee = SCI_Recieve();	// On récupère la trame si l'écriture est possible
				break;
			
			case 1:
				buffer = SCI_Recieve(); // On place la tram dans un buffer si l'écriture sur donnee est bloqué (lecture ou modification de variable en cours)
				break;
			
			case default:
				donnee = SCI_Recieve();	// Cas par défaut : On récupère la trame si l'écriture est possible
				break;
		}
	}
}