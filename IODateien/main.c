#include <stdio.h>

int main(void) {
	//FILE *input;
	//input = fopen("input.txt", "r");
	FILE *output;
	output	= fopen("output.txt", "w");
	
	fprintf(output, "Hallo Welt");

	//fclose(input);
	fclose(output);
}
