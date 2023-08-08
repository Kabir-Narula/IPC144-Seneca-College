/*<assessment example name: Workshop- #4(part -1)
Authenticity Declartion:
I Declare this submission is the result of my own work and has not been
shared with any other student or third party provider. This submitted
piece of work is enitrely of my own creation*/



#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
int i, numberOfIterations; 
char loopType; 
    
    printf("+----------------------+\nLoop application STARTED\n+----------------------+\n\n");
  do 
{
    printf("D = do/while | W = while | F = for | Q = quit\n"); 
    printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
    scanf(" %c%d", &loopType, &numberOfIterations); 
      if (loopType == 'Q') 
{
      if (numberOfIterations != 0) 
{
    printf("ERROR: To quit, the number of iterations should be 0!\n\n");
}
}
      else if (loopType == 'D' || loopType == 'W' || loopType == 'F') 
{
      if (numberOfIterations < 3 || numberOfIterations > 20) 
{
      printf("ERROR: The number of iterations must be between 3-20 inclusive!\n\n");
}
      else 
{
      if (loopType == 'D') 
{
          i = 0; 
      printf("DO-WHILE: "); 
  do
{
      printf("%c", loopType); 
          i++; 
} while (i < numberOfIterations); 
}
      else if (loopType == 'W') 
{
          i = 0; 
      printf("WHILE   : "); 
  while (i < numberOfIterations)
                    {
      printf("%c", loopType); 
          i++; 
}
}
      else 
{
      printf("FOR     : "); 
      for (i = 0; i < numberOfIterations; i++) 
{
      printf("%c", loopType); 
 }
}
      printf("\n\n"); 
}
}
      else 
{
      printf("ERROR: Invalid entered value(s)!\n\n"); 
}
} while (!(loopType == 'Q' && numberOfIterations == 0)); 
      printf("\n+--------------------+\n");
      printf("Loop application ENDED\n");
      printf("+--------------------+\n");
    return 0;
}
