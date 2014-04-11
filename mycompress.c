#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int linelength=1024;
FILE* input;
FILE* output;

/**
 * @brief sets the input and output according to read from stdin and write to Stdin.comp
 */
void readfromstdin();

/**
 * @brief prints help message
 */
void printhelp();

/**
 * @brief sets the input and output according to read from a file and write to file.comp
 */
void readfromfile(char* filename);

/**
 * @brief compresses input and writes to output.
 */
void compress();

int main(int argc, char * argv[])
{
    
    //If first argument is help -> print help
    if(argv[1]!=NULL){
        if(strcmp(argv[1],"--help")==0){
            printhelp();
            return(EXIT_FAILURE);
        }
    
        //mycompress with given input file(s) 
        if(argc>=2){
            
            for(int i=1;i<argc;i++){
                readfromfile(argv[i]);
                compress();
                return EXIT_SUCCESS;
            }
            
        }
    }

    
    //If no argument is given read from stdin
    if(argc==1){
        readfromstdin();
        compress();
        return EXIT_SUCCESS;
        }
    
    
    
    return EXIT_FAILURE;
}

void readfromfile(char* filename){
    
    char filenamecomp[100]=""; //100 chars max. filename size incl. .comp
    strcpy(filenamecomp,filename);
    strcat(filenamecomp,".comp");
    input=fopen(filename,"r");
    output=fopen(filenamecomp,"w");
    
   
}

void readfromstdin(){
    
    input = stdin;
    output = fopen("Stdin.comp", "w");
    
    printf("\nWritten to Stdin.comp\n");
}

void printhelp(){
    
    printf("\n usage: mycompress [filename1] [filename2] ...\n");
    
}

void compress(){
    
    if(input != NULL && output != NULL){
        
        char activechar;
        char priorchar;
        
        int totalcharcounter=0;
        int samecharcounter=1;
        
        while((activechar=fgetc(input)) != EOF ) {
            if(totalcharcounter>0){
                
                if(activechar==priorchar){samecharcounter++;}else{
                    fprintf(output,"%c%i",priorchar,samecharcounter);
                    
                    priorchar=activechar;
                    samecharcounter=1;
                }
                
                
            
            }else{priorchar=activechar;}
            totalcharcounter++;
        }
        
        
        
    }
}



