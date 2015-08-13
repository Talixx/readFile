#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readFile.h"

int main{
	FILE *meta;
		char *arqmeta = "meta.dat";//Metadata file's name
		int qt_fields, i=0;
		meta = fopen(arqmeta,"rb");
		if(meta == NULL){
			printf("Error opening file!\n");
			return 0;
		}

		//take how many fields are especified in the metada
		fread(&qt_fields,sizeof(int),1,meta);
		Field fld[qt_fields];

		//get the attributes' names and the relevant informations(type,size) each field
		while(i<qt_fields){
			char c;
			int j=0;
			while((c=fgetc(meta))!='\0'){
				fld[i].name[j++]=c;
			}
			fld[i].name[j++]=c;
			fld[i].type = fgetc(meta);
			fread(&fld[i].len,sizeof(int),1,meta);
			i++;
		}
		i=0;
