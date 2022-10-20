#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){

	int filemode = 0;
	int ideanb = 0;
	FILE *fp;

	char* Camera[7] = {"FP", "VR", "TP", "2D", "3D", "Top-Down", "AR"};
	char* Control[9] = {"Gatcha", "RPG", "OpenWorld", "Startegy", "Realiste", "Rythm", "Stealth", "Eduational", "hasard"};
	char* Character[9] = {"Esponnage", "Trains", "Financial", "Pirates", "Archeology", "Animals", "Aviation", "espace", "far west"};

	if (argc > 3){
		printf("wtf are you doing ?");
		return 1;
	}

	if (argv[1]){
		if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0){
					printf("\n__Random Idea Generator__\n\nArguments : \n\n-h, --help : shows help\n-f, --file <filename> : output ideas to file instead of stdout\n");
					return 0;
				}
		
			if (strcmp(argv[1], "--file") == 0 || strcmp(argv[1], "-f") == 0){
				filemode = 1;
				if(!argv[2]){
					printf("no name ? :(\n");
					return 3;
				}
				if (strlen(argv[2]) >= 255 || strlen(argv[2]) <= 0) {
				    printf("filename invalid: %s\n", argv[2]);
				    return 2;
				}
				printf("Running in file mode...\nCreating file %s\n", argv[2]);
				fp = fopen(argv[2], "w");
				
			}
	}

	
	int i;
	int j;
	int k;
	for(i = 0; i < sizeof(Camera) / sizeof(*Camera); i++){
		for(j = 0; j < sizeof(Control) / sizeof(*Control); j++){
				for(k = 0; k < sizeof(Character) / sizeof(*Character); k++){
						if (filemode){
							fprintf(fp, "%s %s %s\n", Camera[i], Control[j], Character[k]);
						} else {
							printf("%s %s %s\n", Camera[i], Control[j], Character[k]);
						}
						ideanb++;
					}
			}
		
	}

	
	if (filemode){
		printf("%i ideas written\n", ideanb);
		fclose(fp);
	} else {
		printf("%i ideas generated\n", ideanb);		
	}
	return 0;
}
