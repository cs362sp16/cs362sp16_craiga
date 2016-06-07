#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mutator(char sourceFile[], char newFile[], int targetChar){
   int trackrInt=0;
   char ch;
   FILE *target;
   FILE *source;
   source = fopen(sourceFile, "r");
   target = fopen(newFile, "w");
   while( ( ch = fgetc(source) ) != EOF ){
         trackrInt++;
         if(trackrInt==targetChar){
            ch=48;
            fputc(ch,target);
         }
         fputc(ch, target);
         
   }
   fclose(target);
   fclose(source);
   return 0;
}


int scanner(char sourceFile[]){
FILE *source;
char ch;
int targetChar=0;
int mutantCount=97;
char newFile[20]="dominion";
char postFile[20]="dominion";
   source = fopen(sourceFile, "r");
   while( ( ch = fgetc(source) ) != EOF ){
      targetChar++;
      if (isdigit(ch)&&((rand()%10)==5)){
         printf("char count: %d\n",targetChar);
         strcpy(newFile,postFile);
         char targetCharArr[3];
         targetCharArr[0]=mutantCount;
         targetCharArr[1]='.';
         targetCharArr[2]='c';
         
         strcat(newFile,targetCharArr);
         mutator(sourceFile,newFile, targetChar);
         mutantCount++;
      }
      if(mutantCount>122)
      {
         fclose(source);
         return 0;
      }
   }
   fclose(source);
   return 0;
} 


int main()
{
   srand((int)time(NULL));
   char sourceFile[20]="dominion.c";
   scanner(sourceFile);
   return 0;
}