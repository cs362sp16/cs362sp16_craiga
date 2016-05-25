#include<stdio.h>

int main() {
   FILE *fp1, *fp2;
   
   char fileName1[40] ="playdominion.txt"; 
   fp1 = fopen(fileName1, "r");

   char fileName2[40]="playnewdominion.txt";
   fp2 = fopen(fileName2, "r");
   
   int expected, actual;
   expected = getc(fp1);
   actual = getc(fp2);
   while ((expected != EOF) && (actual != EOF) && (expected == actual)) {
      expected = getc(fp1);
      actual = getc(fp2);
   }
   if (expected == actual)
      printf("dominion outputs match PASS\n");
   else if (expected != actual)
      printf("dominion outputs do not match FAIL \n");
   fclose(fp1);
   fclose(fp2);
   return (0);
}