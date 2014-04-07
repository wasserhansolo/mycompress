#include <stdio.h>
#include <string.h>

int linelength=1024;
FILE* input;
FILE* output;

void readfromstdin();
void printhelp();

int main(int argc, const char * argv[])
{
    
    //If first argument is help -> print help
    if(argv[1]!=NULL){
        if(strcmp(argv[1],"--help")==0){
            printhelp();}
    
        //mycompress with given input file(s) --wie schauts mit help aus ?
        if(argc>=2){
            
            for(int i=2;i<=argc;i++){
                printf("test %i",i);
            }
            
        }
    }

    
    //If no argument is given read from stdin
    if(argc==1){
        readfromstdin();
        }
    
    
    
    return 0;
}

void readfromstdin(){
    
    input = stdin;
    output = fopen("Stdin.comp", "w");
}

void printhelp(){
    
    printf("\n\n usage: mycompress [filename1] [filename2] ...\n");
    
}
