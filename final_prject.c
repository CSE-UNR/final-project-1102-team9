//Authors:Nathan Lock, Andrew Smith, Diego Reyes Ortiz
//Final Group Project MadLibs
//Date: 10 December 2024





#include <stdio.h>
#define STRING_CAP 100
#define MAD1 "madlib1.txt"
#define RMAX 30
#define CMAX 50


void get_adjective(char []);
void get_noun(char []);
void get_verb(char []);
int readFile(FILE* fp, char[RMAX][CMAX]);
void remove_newline(char str[]);

int main(){


FILE* mad1, *mad2;

char content[RMAX][CMAX];
char contentWithInput[RMAX][CMAX];
char adjective[STRING_CAP];
char noun[STRING_CAP];
char verb[STRING_CAP];


mad1 = fopen(MAD1,"r");

if(mad1 == NULL){
	printf("Unable to open madlib1\n");
return 0;
}

int totalLines = readFile(mad1, content);
fclose(mad1);



for(int i = 0; i < totalLines; i++){
	int j = 0;
	 if (content[i][0] == 'A'){
		get_adjective(adjective);
		for (int j = 0; adjective[j] != '\0' && j < STRING_CAP - 1;j++){
		
			contentWithInput[i][j] = adjective[j];
		}
	 	
	 }
	 else if (content[i][0]== 'N'){
	 		get_noun( noun);
	 		for (int j = 0; noun[j] != '\0'&& j < STRING_CAP - 1 ;j++){
				contentWithInput[i][j] = noun[j];
		}
	 	
	 	contentWithInput[i][j] = '\0';
	 }
	 else if(content[i][0]=='V'){
	 		get_verb( verb);
	 			for (int j = 0; verb[j] != '\0' && j < STRING_CAP - 1; j++){
					contentWithInput[i][j] = verb[j];
		}
	 	contentWithInput[i][j] = '\0';
	 }
	 else{
	 
	 	for (int j = 0; j != '\0' ;j++){
		 	if (content[i][j] != '\n'){
			contentWithInput[i][j] = content[i][j];
			}
		 	contentWithInput[i][j] = '\0';
	 }
	 	
	 
	}



}

for(int i = 0; i < totalLines; i++){
 printf("%s", contentWithInput[i]);
}



return 0;
}


void get_adjective(char adjective[]){
printf("Please enter an adjective:");
fgets(adjective, STRING_CAP, stdin);
remove_newline(adjective);
}


void get_noun(char noun[]){

printf("Please enter a noun:");
fgets(noun, STRING_CAP, stdin);
remove_newline(noun);
}


void get_verb(char verb[]){

printf("Please enter a verb:");
fgets(verb, STRING_CAP, stdin);
remove_newline(verb);
}


int readFile(FILE* fp, char content[RMAX][CMAX]){

	int line = 0;
	while(fgets(content[line], CMAX, fp)){
	line++;

}
return line;
}


void remove_newline(char str[]) {
  int i = 0;
    while (str[i] != '\0') {
        i++;
    }
  
    if (i > 0 && str[i - 1] == '\n') {
        str[i - 1] = '\0';
    }
    }


