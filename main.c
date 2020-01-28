#include <stdio.h>
#include <stdlib.h> 
#include <time.h>


int genRandoms(int lower, int upper,int count){ 
    int i; 
    for (i = 0; i < count; i++) { 
        int num = (rand() % 
           (upper - lower + 1)) + lower; 
        return num; 
    } 
} 

void clrscr(){
    system("@cls||clear");
}


//-------------------------------------TOUR DU JOUEUR----------------------------------------------------------
int tourPlayer(int pvMonstre,int pvJoueur,int pmJoueur){
	int choix;
	

	printf("Vous avez %d PV et %d PM, \nLe monstre a %d PV\n",pvJoueur,pmJoueur,pvMonstre );
	printf("Que voulez vous faire ? \nAttaque:1 Defence:2 Competence:3 Antidote:4\n");
	scanf("%d",&choix);
	if (choix == 1)
	{
		return choix;
	}
	if (choix == 2)
	{
		return choix;
	}
	if (choix == 3)
	{
		if (pmJoueur>=7)
		{
			return choix;	

		}
		else{
			printf("vous n'avez pas assez de PM !\n");
			tourPlayer(pvMonstre,pvJoueur,pmJoueur);
		}
	}
	if (choix == 4)
	{
		return choix;
	}

}

//-------------------------------------TOUR DU MONSTRE----------------------------------------------------------
int tourMonstre(int pvMonstre,int pvJoueur,int lower, int upper,int count){
	int choix;
	printf("Tour du monstre!\n");
	choix = genRandoms(lower, upper, count);
	return choix;

}

int poison(){
}


//-------------------------------------FONCTION MAIN------------------------------------------------------
int main(int pvJoueur,int pvMonstre, int pmJoueur)
{
//-------------------------------------VARIABLES----------------------------------------------------------

	int classe;
	int choix;
	int lower = 1, upper = 3, count = 1;
	int game = 1;
	int defOn = 0;
	int tour;
	int tourM;
	pvMonstre = 50; 
	pvJoueur;
	pmJoueur;
	int defOnM = 0;
	int bleedL = 0;
	srand(time(0));
	int nombreDeMonstres = 0;
	int furtiv = 1;

//---------------------------------CHOIX DE LA CLASSE-----------------------------------------------------

	printf("Quelle classe souhaitez-vous ? \nPaladin:1 Sorcier:2 Voleur:3 Ranger:4\n");
	scanf("%d",&classe);

	if (classe == 1){ // Paladin
		pvJoueur = 130;
		pmJoueur = 50;
		printf("Vous avez choisi la classe Paladin\n");
	}

	if (classe == 2){ // Sorcier
		pvJoueur = 100;
		pmJoueur = 80;
		printf("Vous avez choisi la classe Sorcier\n");
	}

	if (classe == 3){ // Voleur
		pvJoueur = 120;
		pmJoueur = 60;
		printf("Vous avez choisi la classe Voleur\n");
	}

	if (classe == 4){ // Ranger
		pvJoueur = 130;
		pmJoueur = 50;
		printf("Vous avez choisi la classe Ranger\n");
	}
	

//---------------------------NOMBRE DE MONSTRES A COMBATTRE-----------------------------------------------


	printf("Combien de monstres voulez vous combattre ?\n");
	scanf("%d",&nombreDeMonstres);
	
	while(nombreDeMonstres>0){
		while(pvJoueur>0 && pvMonstre>0){
			defOn = 0;
			pmJoueur++;
			tour = tourPlayer(pvMonstre, pvJoueur, pmJoueur);
			printf("%d\n",bleedL);

//----------------------------------EMPOISONNEMENT--------------------------------------------------------
			if (bleedL > 0) 
			{
				pvJoueur = pvJoueur - bleedL;
				printf("Vous etes empoisonnez, vous perdez %dPV\n Il vous reste %d PV\n",bleedL, pvJoueur );
			}
//-------------------------------------ATTAQUE------------------------------------------------------------
			if (tour == 1)
			{
				if (defOnM == 1)
				{
					clrscr();
					pvMonstre --;
					printf("Vous attaquez le monstre il perd 1PV, il lui reste %dPV\n",pvMonstre );
					
				}
				else{
					clrscr();
					pvMonstre -= 4;
					printf("Vous attaquez le monstre il perd 4PV, il lui reste %dPV\n",pvMonstre );	
					
				}
				if (classe == 3){
					if (furtiv == 0)
					{
						pvJoueur = pvJoueur;
					}
					
				}
				
			}

//-------------------------------------DEFENSE------------------------------------------------------------
			if (tour == 2)
			{
				clrscr();
				defOn = 1;
				printf("vous vous defendez ! vous reduisez vos degats de 75% !\n");
				
			}
//--------------------------------------SORT--------------------------------------------------------------
			if (tour == 3)
			{
				//---PALADIN---
				if (classe == 1){
					clrscr();
					pmJoueur  -= 20;
					pvMonstre -= 0;
					pvJoueur  += 30;
					if (pvJoueur>=100){
					pvJoueur = 130;
					printf("Vos PV sont au maximum !");
					}
					else{	
						printf("Vous lancez Lumiere divine ! \n Vous perdez 20PM ! il vous reste %dPM\n Elle vous soigne de 30 points de vie !\n il vous reste %dPV\n",pmJoueur,pvJoueur);
					}		
				}

				//---SORCIER---
				if (classe == 2){
					clrscr();
					pmJoueur -=30;
					pvMonstre -= 10;
					printf("Vous lancez une boule de feu ! \n Vous perdez 30PM ! il vous reste %dPM\n Elle inflige 10 points de degats au Monstre !\n il lui reste %dPV\n",pmJoueur,pvMonstre);
				}



				//---VOLEUR---
				if (classe == 3){
					clrscr();
					pmJoueur -=15;
					pvMonstre -= 0;
					printf("Vous lancez Furtivité ! \n Vous perdez 15PM ! il vous reste %dPM\n Vous esquiverez la prochaine attaque !\n il lui reste %dPV\n",pmJoueur,pvJoueur);
					furtiv = 1;
				}


				//---RANGER---
				if (classe == 4){
					clrscr();
					pmJoueur -=10;
					pvMonstre -= 12;
					printf("Vous tirez la flèche de feu ! \n Vous perdez 10PM ! il vous reste %dPM\n Elle inflige 12 points de degats au Monstre !\n il lui reste %dPV\n",pmJoueur,pvMonstre);
				}
			}
	
//------------------------------------ANTIDOTE------------------------------------------------------------
			if (tour == 4)
			{
				clrscr();
				bleedL = 0;
				printf("vous n'etes plus empoisonne!\n" );
			}

//--------------------------------TOUR DU MONSTRE---------------------------------------------------------
			printf("\n");
			defOnM = 0;
			if (pvMonstre>0)
			{
				tourM = tourMonstre(pvMonstre, pvJoueur,lower, upper, count);
				if (tourM == 1){
					
					if (furtiv == 1){
						furtiv=0;
						}
					else{	
						if (defOn == 1)
					{
						pvJoueur--;
						printf("Le monstre vous attaque !, grace a votre defense vous perdez 1PV\nIl vous reste %dPV\n",pvJoueur);
					}
						pvJoueur-=4;
						printf("Le monstre vous attaque !\nVous perdez 4PV !\nIl vous reste %dPV\n",pvJoueur);
					}
					
				}
				if (tourM == 2)
				{
					defOnM = 1;
					printf("Le monstre se defend ! il reduit ses degats de 75% !\n");
				}
				if (tourM == 3)
				{
					bleedL++;
					printf("Le monstre vous empoisonne !, Vous devez vous guerir ou vous perdrez %d par tour !\n",bleedL );
				}
				printf("\n");

			}
				
		}
	nombreDeMonstres = nombreDeMonstres-1;
	pvJoueur = pvJoueur + 40;
	printf("Vous vous soignez de 40 pv\n");
	pvMonstre = 50;	
	}	
	return 0;
	}