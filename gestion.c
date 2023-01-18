#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    int J;
    int M;
    int A;
} date;
typedef struct{
    int mle;
    char nomcomplet[50];
    char filiere[80];
    float moyenne;
    date DN;
} etudiant;
etudiant etd;
FILE* fichier;
FILE* fichMAJ;



etudiant* remplissage(){
    int n;
    printf("donner le nombre d'etudiants  :");
    scanf("%d",&n);
    etudiant* etd ;
    etd= calloc(n,sizeof(etudiant));
    fichier=fopen("gestiondeclasse.txt","w");
    for(int i =0;i<n;i++){
    printf("mat: ");
    scanf("%d",&etd[i].mle);
    fflush(stdin);
    printf("nom: ");
    gets(etd[i].nomcomplet);
    printf("filiere: ");
    scanf("%s",etd[i].filiere);
    printf("moyenne: ");
    fflush(stdin);
    scanf("%f",&etd[i].moyenne);
    printf("jr : ");
    scanf("%d",&etd[i].DN.J);
    printf(" le M : ");
    scanf("%d",&etd[i].DN.M);
    printf(" l'année': ");
    scanf("%d",&etd[i].DN.A); 
    fwrite(&etd[i],sizeof(etudiant),1,fichier);
    }
    fprintf(fichier,"\n");
    return etd;
    fclose(fichier);
}
void affichage_etd(){
    fichier=fopen("gestiondeclasse.txt","r");
    while(fread(&etd,sizeof(etudiant),1,fichier)){
        printf("%d\t ",etd.mle);
        printf("%s\t",etd.nomcomplet);
        printf("%s\t", etd.filiere) ; 
        printf("%.2f\t",etd.moyenne); 
        printf("%d/%d/%d\t", etd.DN.J,etd.DN.M,etd.DN.A);
        printf("\n");
        }
    fclose(fichier);
}


void ajout(){
    int n;
    
    printf("donner le nombre d'etudiants  :");
    scanf("%d",&n);
    etudiant* etd = calloc(n,sizeof(etudiant));
    
    fichier=fopen("gestiondeclasse.txt","a");
    for(int i =0;i<n;i++){
    printf("donnez le mle de l'etudiant: ");
    scanf("%d",&etd[i].mle);
    fflush(stdin);
    printf("donnez le nom de l'etudiant: ");
    scanf("%s",etd[i].nomcomplet);
    printf("donnez la filière de l'etudiant: ");
    scanf("%s",etd[i].filiere);
    printf("donnez la moyenne de l'etudiant: ");
    scanf("%f",&etd[i].moyenne);
    printf("donner la date de naissance de l'etudiant comme suit:\n");
    printf(" le jour de naissance: ");
    scanf("%d",&etd[i].DN.J);
    printf(" le M de naissance: ");
    scanf("%d",&etd[i].DN.M);
    printf(" l'année de naissance: ");
    scanf("%d",&etd[i].DN.A); 
    getchar();
    fprintf(fichier," %d \t %s \t %s \t %f \t %d \t %d \t %d \n ", etd[i].mle,etd[i].nomcomplet,etd[i].filiere,etd[i].moyenne,etd[i].DN.J,etd[i].DN.M,etd[i].DN.A);
    fclose(fichier);
} fprintf(fichier,"\n");}



void  recherche(){
    etudiant etd;
    int rech;
    fichier=fopen("gestiondeclasse.txt","r");
    printf("donner le matricule de l'etudiant à chercher: ");
    scanf("%d",&rech);
    while(fread(&etd,sizeof(etudiant),1,fichier)){
        if(rech == etd.mle){
        printf("%d\t ",etd.mle);
        printf("%s\t",etd.nomcomplet);
        printf("%s\t", etd.filiere) ; 
        printf("%.2f\t",etd.moyenne); 
        printf("%d/%d/%d\t", etd.DN.J,etd.DN.M,etd.DN.A);}
}

    fclose(fichier);} 
void mise_ajr(){
    int rech,trv=0;
    etudiant etd;
    fichier=fopen("gestiondeclasse.txt","r");
    fichMAJ=fopen("MAJ.txt","w");
    printf("donner le matricule de l'etudiant à mettre à jour   :");
    scanf("%d",&rech);

    while(fread(&etd,sizeof(etudiant),1,fichier)){
        if(etd.mle==rech){
            trv=1;
        printf("donnez la nouvelle  moyenne de l'etudiant: ");
        scanf("%f",&etd.moyenne);
        }
        fwrite(&etd,sizeof(etudiant),1,fichMAJ);
    }

    fclose(fichier);
    fclose(fichMAJ);

    if(trv==1){
        fichMAJ=fopen("MAJ.txt","r");
        fichier=fopen("gestiondeclasse.txt","w");
        while(fread(&etd,sizeof(etudiant),1,fichMAJ)){
            fwrite(&etd,sizeof(etudiant),1,fichier);
        }
    fclose(fichier);
    fclose(fichMAJ);
    }else{
        printf(" le matricule saisi ne correspond à aucun l'etudiant");
    }
}


void suppression(){
    etudiant etdm;
    int rech,trv=0;
    fichier=fopen("gestiondeclasse.txt","r");
    fichMAJ=fopen("MAJ.txt","w");
    printf("donner le matricule de l'etudiant à supprimer  :");
    scanf("%d",&rech);

    while(fread(&etdm,sizeof(etudiant),1,fichier)){
        if(etdm.mle==rech){
            trv=1;
    }
        else fwrite(&etdm,sizeof(etudiant),1,fichMAJ);
    }
    fclose(fichier);
    fclose(fichMAJ);
    if(trv==1){
        fichMAJ=fopen("MAJ.txt","r");
        fichier=fopen("gestiondeclasse.txt","w");
        while(fread(&etdm,sizeof(etudiant),1,fichMAJ)){
            fwrite(&etdm,sizeof(etudiant),1,fichier);
        }
    fclose(fichier);
    fclose(fichMAJ);
}
    else{
        printf(" le matricule saisi ne correspond à aucun l'etudiant");
    }
}

int main(){
    int choix,rech;
    printf("\n 1 Remplire une base d'etudiants ");
    printf("\n 2 Affichage des etudiants par lignes");
    printf("\n 3 Affichage par ordre alphabetique des noms ");
    printf("\n 4 affichage par odre de merite  ");
    printf("\n 5 insertion de nouveau etudiants \n 6 Modification de la moyenne ");
    printf("\n 7 suppression des eleves \n 8 recherche \n");
    scanf("%d",&choix);
    switch (choix)
    {
    case 1: remplissage();
        break;
    case 2: affichage_etd();
        break;
    case 3: printf("choix pas encore fait ");
        break;
    case 4:printf("choix pas encore fait ");
        break;
    case 5: ajout();
        break;
    case 6:  mise_ajr();
        break;
    case 7: suppression();
        break;  
    case 8 :
            recherche();
        break;
    default: printf("ce choix est invalide");
        break;
    };}
