

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
			/*fld[i].name[j++]=c;
			fld[i].type = fgetc(meta);
			fread(&fld[i].len,sizeof(int),1,meta);
			fld[i].keyType= fgetc(meta);
			fld[i].ob = fgetc(meta);*/

			printf("Name:%s \n Type: %c \n Len: %d \n keyType: %c \n ob: %d \n",fld[i].name,fld[i].type,fld[i].len,fld[i].keyType,fld[i].ob);
			i++;
		}

		i=0;

		return 0;
}
