#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

//checks if there is a / in the path
char* checkSlash(char* directory){
	int size = strlen(directory);
	if(directory[size-1]!='/'){
		directory[size]='/';
		directory[size+1] = '\0';
	}

	return directory;
}


int main(int argc, char*argv[]){
	//makes sure a directory is entered.
	if(argc<2){
		fprintf(stderr, "please enter a directory.\n");
		exit(1);
	}
	/*taken from thegeekstuff.com/2012/06/c-directory/ to
	learn how to read from a directory */

	char directory[200];
	char nextdir[100];
	memset(directory,0,sizeof(directory));
	//copy the path set by argv[1] and get the length of that string
	strcpy(directory,argv[1]);
	int dl = strlen(directory);
//	printf("%s\n", directory);
	//open the directory stream
	//directory is type 4, .txt is type 8.
	//store a total sum
	double sum = 0.0;
	DIR *dp = NULL;
	//check if directory is a valid directory
	if((dp= opendir(directory))==NULL){
		printf("%s is not a directory\n", argv[1]);
	}else{
		//dirent struct for directory stream
		struct dirent *dptr = NULL;
		dptr = readdir(dp);

		while(1==1){
//		printf("%s is of type %d\n", dptr->d_name, dptr->d_type);
		//check if the file starts with data and ends with .txt
		if(dptr->d_type ==8 && strncmp(dptr->d_name,"data",4)==0 && strcmp(strrchr(dptr->d_name, '\0')-4, ".txt")==0){
			//read the file and add the numbers
//			printf("%s is a file we are looking for\n", dptr->d_name);
			checkSlash(directory);
			char* name = strcat(directory, dptr->d_name);
			FILE *fp = fopen(name, "r");
			char buff[150];
			int c = fscanf(fp, "%s", buff);
//	printf("check\n");
			while(c!= EOF){
				sum+= atof(buff);
				c=fscanf(fp, "%s", buff);
//				printf("\nsum=%.12f\n", sum);

			}
			fclose(fp);
			directory[dl]='\0';
		}
		//check if dptr is pointing to a directory that is not . or .. and if so, store it in a char*, concat with the current directory and keep reading.

		if(dptr->d_type == 4 && strcmp(dptr->d_name, ".")!=0 && strcmp(dptr->d_name, "..")!=0){
			strcpy(nextdir, dptr->d_name);
//			printf("nextdir=%s\n", nextdir);

		}
		//if the readdir is null, start a new stream with the subdirectory if it is valid and continue.
		//break if not meaning it had read all the subdirectories
		if((dptr=readdir(dp)) == NULL){
//			printf("end of directory stream\n");
			if(nextdir != NULL){
				closedir(dp);
				checkSlash(directory);
				strcat(directory, nextdir);
				dl = strlen(directory);
//				printf("%s\n",directory);
				if((dp = opendir(directory))!=NULL){
					checkSlash(directory);
					nextdir == NULL;
					dptr = readdir(dp);
					continue;
				}else{
					break;
				}
			}
		}


		}
	}
	//print out the total sum of the numbers in the directory stream
	printf("\nsum=%.12f\n", sum);
	closedir(dp);
	return 0;
}
