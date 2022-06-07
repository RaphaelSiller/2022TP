#include<stdio.h>
#include<string.h>
#include<strings.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(void) {
	int nArguments = 10; //maximale Anzahl der Argumente
	char input[64];
	char command[nArguments][64]; //Der Befehle
	do {
		//Arrays zuruechsetzen
		memset(input, 0, sizeof(input));
		for (int i = 0; i < nArguments; i++)
			memset(command[i], 0, sizeof(command[i]));

		//Simulieren des working directorys
		char path[256];
		if(getcwd(path, sizeof(path)) != NULL)
			printf("%s$ ", path);
		else
			printf("Du hast ziemlich viele Ordner, richtig?");

		//Eingabe
		fgets(input, sizeof(input), stdin);
		//Sortieren der Eingabe in commands
		int indexInput = 0;
		int nActualArguments = 0; //Gibt die Anzahl der eingegeben Argumente wieder an
		for (int i = 0; i < nArguments; i++) {
			int indexCommand = 0;
			while (input[indexInput] != ' ' && input[indexInput] != '\n') { // Einordnen bis ein Argument aufhoert
				command[i][indexCommand++] = input[indexInput++];
			}
			
			if (input[indexInput] == ' ') { //Wenn Argument folgt
				indexInput++;
				nActualArguments++;
			} else {
				if(input[indexInput] == '\n') { //Wenn kein Argument folgt
				
				i = nArguments;
				nActualArguments++;			
				}
			}
		}
		if(strncasecmp(command[0],"cd",2)==0){ //Da cd sich nicht nur auf den Kindprozess, sondern auch auf den Elternprozess auswirken soll
			if(chdir(command[1])==-1){
				printf("Fehler beim Wechsel in ein Verzeichnis\n");
			}
		}else if(strncasecmp(command[0],"quit",4)!=0){ //Wenn Benutzer nicht beenden moechte
			fflush(stdout);
			int PPID = fork();
			char *commandPnt[nArguments+1];
			switch (PPID)
			{
			case -1: //Fehlerfall
				printf("Etwas ist beim erstellen eines Kindprozesses schiefgegangen\n");
				fflush(stdout);
				exit(-1);
				break;
			
			case 0: //Kindprozess, zustaendig, den Befehl auszufuehren
				if (nActualArguments > 0) { //Unterteilung ob Argumente uebergeben werden oder nicht
					//Befehle werden in eine fuer exec passende Syntax gewandelt; Zeigerarray, welcher mit NULL aufhoert
					for (int i = 0; i < nActualArguments; i++) {
						commandPnt[i] = command[i];
					}
					commandPnt[nActualArguments] = NULL;
					
					//Aufruf des Befehls mit execvp
					if(execvp(command[0],commandPnt)==-1) {
						printf("Etwas ist beim aufruf des Befehls schiefgegangen(mit Argumente)\n");
						exit(-1);
					}
				} else {
					if(execlp(command[0],command[0],NULL)==-1) {
							printf("Etwas ist beim aufruf des Befehls schiefgegangen(ohne Argumente)\n");
							exit(0);
					}
				}
				break;

			default: //Elternprozess wartet auf Tod des Kindes, lebt dann weiter
				wait(NULL);
				break;
			}
		}
	} while (strncasecmp(command[0],"quit",4)!=0);
	
}