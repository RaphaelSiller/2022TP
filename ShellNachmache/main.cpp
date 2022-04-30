#include <stdio.h>
#include <iostream>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

int main() {
	bool wantsToStay = true;
	do {
		cout << "AwesomeUser@AwesomePC:~/AwesomeDirectory ";
		string arguments[10];
		int i = 0;

		while (i <10 && cin >> arguments[i] && arguments[i].compare("|") != 0)
			i++;
		
		
		for (int i = 0; i < 10; i++) {
			cout << arguments[i];
			cout << endl;
		}
		
		if (arguments[0].compare("exit")) {
			wantsToStay = false;
		} else {
			//Eingabe Erfolgreich
			int PID = fork();
			//Wenn Kindprozess, fuehre Befehl aus, ansonsten warte bis Kindprozess tot ist und mache naechsten Befehl
			if (PID > 0) {
				//String -> charArray
				char fileName[20];
				char argChar[10][20];
				for (int j = 0; j < arguments[0].length(); j++){
					fileName[i] = arguments[0][i];
				}

				for (i = 0; i < 10; i++) {
					for (int j = 0; j < 20; j++) {
						argChar[i][j] = arguments[i][j];
					}
				}
				
				
				string test[10];
				execlp(fileName, argChar[]);
			} else {
				wait(PID);
			}
			

		}

	} while(wantsToStay);


	return 0;
}