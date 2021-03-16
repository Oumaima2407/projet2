#include<stdio.h>
#include<string.h>
typedef struct {
	char id[50];
	char mdp[50];
}utilisateur;


int login(char id[50], char mdp[50], int nbu, utilisateur u[300])
	{
		int i,m;
		int r=1;
	for(i=0;i<nbu&&r==1;i++)
	{
	    if(strcmp(id,u[i].id)==0)
		{r=0;
			if(strcmp(mdp,u[i].mdp)==0)
			{
				m=0;
				if(i==0)
				{
					m=3;
				}
			}
			else
			{
				m=1;
			}
		}
		else
		{
			m=2;
		}
	}
	return m;	
}


int ajout_utilisateur(char id[50], char mdp[50], int nbu, utilisateur u[300])
{
	int n=1;
	int i,a;
	
	for(i=0;i<nbu;i++)
	{
		if(strcmp(id,u[i].id)==0)
		{
			n=0;
		}
	}
	
	if(n==1)
	{	
		a=0;
	    do
		{
			u[nbu].id[a]=id[a];
			a++;
		}while(id[a]!='\0');
		u[nbu].id[a]=id[a];
		
		a=0;
		do
		{
			u[nbu].mdp[a]=mdp[a];
			a++;
		}while(mdp[a]!='\0');
		u[nbu].mdp[a]=mdp[a];
	}
	
	return n;
	
	
}

int modification_mdp_par_admin(char id[50], char mdp[50], int nbu, utilisateur u[300])
{
	int i,a;
	int r=1;
	for(i=0;i<nbu&&r==1;i++)
	{
		if(strcmp(id,u[i].id)==0)
		{
			r=0;
			a=0;
		do
		{
			u[i].mdp[a]=mdp[a];
			a++;
		}while(mdp[a]!='\0');
		u[i].mdp[a]=mdp[a];
		
	    }
	}
	return r;
}

void affich_utilisateur(int nbu, utilisateur u[300])
{
	int i;
	for(i=0;i<nbu;i++)
	{
		printf("-Utilisateur %d-->%s  \n",i+1,u[i].id);
	}	
}

int mdp(char id[50], char mdp[50],char nvmdp[50], int nbu, utilisateur u[300])
{
	
	int i,o,a;
	int r=1;
	for(i=0;i<nbu&&r==1;i++)
	{
	    if(strcmp(id,u[i].id)==0)
		{r=0;
			if(strcmp(mdp,u[i].mdp)==0)
			{
				o=3;
				a=0;
		        do
	      	    {
			      u[i].mdp[a]=nvmdp[a];
			      a++;
	        	}while(nvmdp[a]!='\0');
		        u[i].mdp[a]=nvmdp[a];
			}
			else
			{
				o=1;
			}
		}
		else
		{
			o=2;
		}
	}
	return o;	
	
	
}

main()
{
	utilisateur u[300],testu;
	int nbutilisateur=0;
	char idtest[50],mdptest[50];
	char idajout[50],mdpajout[50];
	char idmd[50],mdpmd[50],nvmdp[50];
	int m,n,r,o,i,choix,sortie;
	int boucle=0;
	i=1;
	
	
	printf("-Donner un identifiant a l'admin: ");
	scanf("%s",u[0].id);
	printf("-Choisir un mot de passe (n'oublier pas votre mdp): ");
	scanf("%s",u[0].mdp);
	
	
	do{
	
	printf("\n-Entrer votre identifiant: ");
	fflush(stdin);
	gets(idtest);
	printf("-Entrer votre mot de passe: ");
	gets(mdptest);
	m=login(idtest,mdptest,i,u);
	if(m==2)
	{
		printf("!!Votre identifiant est incorrect!!\n");
	}
	else if(m==1)
	{
		printf("!!Votre mot de passe est incorrect!!\n");
	}
	else if(m==0)
	{
		printf("*Vous etes connecte avec succes* (utilisateur)\n\n");
		do{sortie=1;
		printf("\n");
		printf("-Vouler vous :\n");
		printf("\t 1--- Afficher la liste des utilisateurs?\n");
		printf("\t 2--- Changer votre mot de passe?\n");
		printf("\t 3--- Vous deconnecter?\n");
		printf("-Entrer votre choix: ");
		scanf("%d",&choix);
		printf("\n");
		
		
		switch(choix){
			case 1:{
				printf("**********Affichage de liste des utilisateurs**********\n\n");
				affich_utilisateur(i,u);
	
				break;
			}
			case 2:{
				printf("**********Changement de votre mot de passe**********\n\n");
				printf("-Veuillez entrer votre identifiant: ");
				fflush(stdin);
				gets(idmd);
				printf("-Veuillez entre votre mot de passe: ");
				gets(mdpmd);
				printf("-Veuillez entre le nouveau mot de passe: ");
				gets(nvmdp);
				o=mdp(idmd,mdpmd,nvmdp,i,u);
				if(o==2)
	            {
	           	printf("!!Votre identifiant est incorrect!!\n");
	            }
	             else if(o==1)
	            {
		        printf("!!Votre mot de passe est incorrect!!\n");
	            }
	            else if(o==3)
	            {
	            	printf("*Changement de mdp avec succes*\n");
				}
				
				
				break;
			}
			case 3:{
				sortie=0;
				printf("!!Vous vous etes deconnecter!!\n");
				
				break;
			}
			
			
			
		}
		
		}while(sortie!=0);
		
		
		
		
		
	}
	else if(m==3)
	{
		printf("*Vous etes connecter avec succes* (admin)\n\n");
		do{sortie=1;
		printf("\n");
		printf("-Vouler vous :\n");
		printf("\t 1--- Ajouter un utilisateur?\n");
		printf("\t 2--- Changer le mot de passe d'un utilisateur?\n");
		printf("\t 3--- Afficher la liste des utilisateurs?\n");
		printf("\t 4--- Changer votre mot de passe?\n");
		printf("\t 5--- Vous deconnecter?\n");
		printf("-Entrer votre choix: ");
		scanf("%d",&choix);
		printf("\n");
		
		
		switch(choix)
		{
			case 1: {
				printf("**********Ajouter un utilisateur**********\n\n");
				printf("-Veuillez choisir un identifiant pour le nouvel utilisateur: ");
				fflush(stdin);
				gets(idajout);
				printf("-Veuillez choisir un mot de passe pour le nouvel utilisateur: ");
				gets(mdpajout);
				n=ajout_utilisateur(idajout,mdpajout,i,u);
				if(n==0)
				{
					printf("!!!Cet identifiant existe deja!!!\n");
				}
				else if (n==1)
				{
					printf("*Utilisateur ajouter avec succes*\n");
					i++;
				}
				break;
			}
			
			case 2:{
				printf("**********Changer le mot de passe d'un utilisateur**********\n\n");
				printf("-Veuillez entrer l'identifiant de l'utilisateur dont vous souhaitez changer le mdp: ");
				fflush(stdin);
				gets(idmd);
				printf("-Veuillez entre le nouveau mot de passe: ");
				gets(nvmdp);
				r=modification_mdp_par_admin(idmd,nvmdp,i,u);
				if(r==1)
				{
					printf("!!!Cet identifiant n'existe pas!!!\n");
				}
				else
				{
					printf("*Mot de passe changer avec succes*\n");
				}

				break;
			}
			case 3:{
				printf("**********Affichage de liste des utilisateurs**********\n\n");
				affich_utilisateur(i,u);	
				break;
			}
			case 4:{
				printf("**********Changement de votre mot de passe**********\n\n");
				printf("-Veuillez entrer votre identifiant: ");
				fflush(stdin);
				gets(idmd);
				printf("-Veuillez entre votre mot de passe: ");
				gets(mdpmd);
				printf("-Veuillez entre le nouveau mot de passe: ");
				gets(nvmdp);
				o=mdp(idmd,mdpmd,nvmdp,i,u);
				if(o==2)
	            {
	           	printf("!!Votre identifiant est incorrect!!\n");
	            }
	             else if(o==1)
	            {
		        printf("!!Votre mot de passe est incorrect!!\n");
	            }
	            else if(o==3)
	            {
	            	printf("*Changement de mdp avec succes*\n");
				}
				
				
				break;
			}
			case 5:{
				sortie=0;
				printf("!!Vous vous etes deconnecter!!\n");
				
				break;
			}
			
			
		}
		
		
	}while(sortie!=0);
	}
	}while(boucle==0);
	
}
