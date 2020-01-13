#include <stdio.h>


int tourPlayer(int pvM,int pvJ,int pmJ){
	int choix;

	printf("Vous avez %d PV et %d PM, \nLe monstre a %d PV",pvJ,pmJ,pvM );
	printf("Que voulez vous faire ? \nAttaque:1 Defence:2 Competence:3\n");
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
		if (pmJ>=7)
		{
			return choix;	

		}
		else{
			printf("vous n'avez pas assez de PM !\n");
			tourPlayer(pvM,pvJ,pmJ);
		}
	}

}


int tourMonstre(int pvM,int pvJ){

}

int poison(){

}

int main(void)
{
	int defOn = 0;
	int tour;
	int pvMonstre = 50, pvJoueur = 50;
	int pmJoueur = 10;
	
	while(pvJoueur>0 || pvMonstre>0){
		defOn = 0;
		tour = tourPlayer(pvMonstre, pvJoueur, pmJoueur);
		//printf("%d\n",tour);

		if (tour == 1)
		{
			pvMonstre -= 4;
			printf("Vous attaquez le monstre il perd 4PV, il lui reste %dPV\n",pvMonstre );
		}
		if (tour == 2)
		{
			defOn = 1;
			printf("vous vous defendez ! vous reduisez vos degats de 75% !\n");
		}
		if (tour == 3)
		{
			pmJoueur -=7;
			pvMonstre -= 10;
			printf("Vous lancez une boule de feu ! \n Vous perdez 7PM ! il vous reste %dPM\n Elle inflige 10 points de degats au Montre !\n il lui reste %dPV\n",pmJoueur,pvMonstre);
		}

		tourMonstre(pvMonstre, pvJoueur);
	}

	
	return 0;
}