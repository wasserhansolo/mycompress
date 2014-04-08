#include <stdio.h>
#include <string.h>

int linelength=1024;
FILE* input;
FILE* output;

void readfromstdin();
void printhelp();
void readfromfile(char* filename);

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
            }
            
        }
    }

    
    //If no argument is given read from stdin
    if(argc==1){
        readfromstdin();
        }
    
    
    
    return 0;
}

void readfromfile(char* filename){
    printf("filename %s",filename);
    char* filenamecomp=strcat(filename,".comp");
    input=fopen(filename,"r");
    output=fopen(filenamecomp,"w");
}

void readfromstdin(){
    
    input = stdin;
    output = fopen("Stdin.comp", "w");
}

void printhelp(){
    
    printf("\n\n usage: mycompress [filename1] [filename2] ...\n");
    
}
