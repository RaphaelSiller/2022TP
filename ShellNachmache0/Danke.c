#include<stdio.h>
#include<string.h>
#include<strings.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
//Anzahl der objekte in arrays
#define ANZ 50

//Anzahl der möglichen befehle
#define ANZB 10
void main(void){
	//variable für die befehlszeile
    char befehlszeile[ANZ];
	char befehl[ANZB][ANZ];
	char pfad[ANZ*10];
	//variable zum speichern der anzahl an mit dem befehl übergebene argumente
	int anzarg;
	do{	
        //Alle arrays leeren und die variablenauf  null setzen
		memset(pfad,0,ANZ);
        memset(befehlszeile,0,ANZ);
		anzarg=0;
		for(int i=0;i<ANZB;i++){
				memset(befehl[i],0,ANZ);
		}
		//findet pfad und gibt in aus
		printf("\e[1m~%s> \e[m",getcwd(pfad,sizeof(pfad))); 
		//ließt die zeile ein
		fgets(befehlszeile,ANZ,stdin);
                
		//teil die befehlszeile in verschiedene befehle ein
		int k=0;
		anzarg++;
		for(int i=0;i<ANZB;i++){
			int j=0;
			while(befehlszeile[k]!=' '&&befehlszeile[k]!='\n'){
                        	befehl[i][j]=befehlszeile[k];
				j++;
				k++;
			}
			if(befehlszeile[k]==' '){
				k++;
				anzarg++;
			}else{
                                i=ANZB;
                        }
                }
		//Shell befehl cd
		if(strlen(befehl[0])==2&&strncasecmp(befehl[0],"cd",2)==0){
			if(chdir(befehl[1])==-1){
				printf("\e[1m\e[31mVerzeichnis %s konnte nicht gefunden werden.\e[0m\n",befehl[1]);
			}

		//Ausführung von Programmen
		}else if(strncasecmp(befehl[0],"quit",4)!=0&&strlen(befehl[0])!=0){
			//erstellen eines Kindprozesses
			int erg;
			erg=fork();
			switch(erg){
				case -1:
					printf("Etwas ist schiefgelaufen\n");
				case 0:
					//Ausführung mit argumenten
					if(anzarg>1){
					//argumente des befehls oder programmaufrufes werden inizialiesiert
						char *argumente[anzarg+1];
						for(int i=0;i<anzarg;i++) {
							argumente[i]=befehl[i];
						}
						argumente[anzarg]=NULL;

						//führt ein programm aus und gibt eventuelle Fehlermeldung
						if(execvp(befehl[0],argumente)==-1) {
							printf("\e[1m\e[31mFehler beim Versuch %s auszuführen.\e[0m\n",befehl[0]);
							exit(0);
						}
					}else{//Ausführung im falle keiner übergeben argumente und Fehlermeldung im Fall eines Fehlers
						if(execlp(befehl[0],befehl[0],NULL)==-1) {
							printf("\e[1m\e[31mFehler beim Versuch %s auszuführen.\e[0m\n",befehl[0]);
							exit(0);
						}
					}
			}

			//wartet auf das ende des Kindprozesses
			wait(NULL);
		}
	}while(strncasecmp(befehl[0],"quit",4)!=0);
}