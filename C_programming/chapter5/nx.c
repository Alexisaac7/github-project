#include<stdio.h>
#include<string.h>
#define MAXLINE 1000

int getlines(char line[], int max);
int main(int argc, char *argv[])
{
  char line[MAXLINE];
  long lineno = 0;
  int c, except = 0, number = 0, found = 0;
  while (--argc > 0 && (*++argv)[0] == '-')
     while (c = *++argv[0])
      switch(c)
       {
         case 'x' :
            except = 1;
            break;
         case 'n' :
            number = 1;
            break;
         default :
            printf ("find : Illegal option %c\n", c);
            argc = 0;
            found = -1;
            break;
       }
   if (argc != 1)
      printf ("Usage : find -x -n pattern\n");
   else
     while (getlines(line, MAXLINE) > 0)
      {
        lineno++;
        if ((strstr(line, *argv) != NULL) != except)
          {
            if (number)
              printf ("%ld:", lineno);
             printf ("%s", line);
             found++;
          }
      }
    return found;
}
int getlines(char line[], int max)
{
  int c, i;
  for (i = 0; (c = getchar()) != EOF && c != '\n'; i++)
   line[i] = c;
   if (c == '\n')
     line[i++] = c;
     line[i] = '\0';
    return i;
}
