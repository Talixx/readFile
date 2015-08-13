

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[20];
	char type;
	int len;
	char keyType;
	char ob;
}Field;

int main(){
	readMeta();
}

int readData(int qt_fields,Field *fld){
	FILE *data;
	char *arqdata = "data.dat";
	data = fopen(arqdata,"rb");
	int i,j;
	if(data == NULL){
		printf("Error opening file!\n");	
		return 0;
	}

	for(i=0;i<qt_fields;i++){
		printf("%-18s",fld[i].name);		
	} 
	printf("\n");
	for(j=0;j<qt_fields;j++){
		printf("+");
		for(i=0;i<16;i++){
			printf("-");		
		} 
	}
	printf("\n");

	char C[100];
	double D;
	int N;

	

	do{
		printf("\n");
		for(i=0;i<=qt_fields;i++){
			if(!fread(C,1,1,data)) break;
				fseek(data,-1,SEEK_CUR);
			if(fld[i].type == 'C'){
				fread(&C,sizeof(char)*fld[i].len,1,data);
				printf("%-18s",C);

			}
			if(fld[i].type == 'D'){
				fread(&D,sizeof(double),1,data);
				printf("%-18.2lf",D);

			}
			if(fld[i].type == 'N'){
				fread(&N,sizeof(int),1,data);
				printf("%-18d",N);

			}
		}
	}while(!feof(data));

	printf("\n");


 
}

int readMeta(){
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
	printf("fields: %d \n",qt_fields);

	while(i<qt_fields){
		char c;
		int j=0;
		while((c=fgetc(meta))!='\0'){
			fld[i].name[j++]=c;

		}

		fld[i].name[j++]=c;
		fread(&fld[i].type,sizeof(char),1,meta);
		fread(&fld[i].len,sizeof(int),1,meta);
		fread(&fld[i].keyType,sizeof(char),1,meta);
		fread(&fld[i].ob,sizeof(char),1,meta);

		i++;
	}
	readData(qt_fields,fld);

	fclose(meta);		
	return 0;
}
