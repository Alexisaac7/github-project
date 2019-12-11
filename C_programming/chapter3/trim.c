#include<stdio.h>
#include<string.h>
#define MAX 100
int trim(char s[]);
int main()
{
  int i, c;
  char s[MAX];
  for (i = 0; i <= MAX; i++)
  s[i] = 0;
  for (i = 0; (c = getchar()) != EOF; i++)
  s[i] = c;
  trim(s);
  printf ("%s\n", s);
  return 0;
}
int trim(char s[])
{
  int n;
  for (n = strlen(s)-1; n >= 0; n--)
    if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
    break;
  s[n+1] = '\0';
  return n;
}
