#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int linelength=1024;
FILE* input;
FILE* output;

void readfromstdin();
void printhelp();
void readfromfile(char* filename);
void compress();

int main(int argc, char * argv[])
{
    
    //If first argument is help -> print help
    if(argv[1]!=NULL){
        if(strcmp(argv[1],"--help")==0){
            printhelp();}
    
        //mycompress with given input file(s) 
        if(argc>=2){
            
            for(int i=1;i<argc;i++){
                printf("test %i",i);
                printf("test %s",argv[i]);
                readfromfile(argv[i]);
                compress();
            }
            
        }
    }

    
    //If no argument is given read from stdin
    if(argc==1){
        readfromstdin();
        compress();
        }
    
    
    
    return 0;
}

void readfromfile(char* filename){
    
    char filenamecomp[100]=""; //100 chars max. filename size incl. .comp
    strcpy(filenamecomp,filename);
    strcat(filenamecomp,".comp");
    input=fopen(filename,"r");
    output=fopen(filenamecomp,"w");
    
    printf("filename %s",filename);
    printf("filenamecomp %s",filenamecomp);
}

void readfromstdin(){
    
    input = stdin;
    output = fopen("Stdin.comp", "w");
}

void printhelp(){
    
    printf("\n\n usage: mycompress [filename1] [filename2] ...\n");
    
}

void compress(){
    
    if(input != NULL && output != NULL){
        
        char activechar;
        char priorchar;
        
        int totalcharcounter=0;
        int samecharcounter=1;
        
        while((activechar=fgetc(input)) != EOF ) {
            printf("\nchar %c",activechar);
            if(totalcharcounter>0){
                printf("activechar:%c priorchar:%c",activechar,priorchar);
                
                if(activechar==priorchar){samecharcounter++;}else{
                    printf("\n!!!!activechar:%c samecharcounter:%i",activechar,samecharcounter);
                    fprintf(output,"%c%i",priorchar,samecharcounter);
                    
                    priorchar=activechar;
                    samecharcounter=1;
                }
                
                
            
            }else{priorchar=activechar;}
            totalcharcounter++;
        }
        
        
        
    }
}



