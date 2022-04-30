#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

int main(int argc, char *argv[]) {
	int PID;
	int sleepK = 0;
	int sleepE = 0;
	
	//Ermittlung der Sleepzeit
	for (int i = 0; ('0' <= argv[1][i] && argv[1][i] <= '9'); i++) {
		sleepK = sleepK * 10 + argv[1][i] - '0';
	}
	for (int i = 0; ('0' <= argv[2][i] && argv[2][i] <= '9'); i++) {
		sleepE = sleepE * 10 + argv[2][i] - '0';
	}

	printf("sleepK = %i\nsleepE = %i\nBin Kindlos\n", sleepK, sleepE);
	PID = fork();
	
	//Elternprozess
	if(PID > 0) {
		sleep(sleepE);
	} else {
		sleep(sleepK);
		execlp("cat", "cat", "./main.c");
		printf("Kindpr - PID %i - PPID %i", getpid(), getppid());
	}
	return 0;
}
