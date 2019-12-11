#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
int sp = 0;
double val[MAXVAL];
int getop(char []);
void push(double);
void printtop();
double pop(void);
int main()
{
  int type;
  double op2, op1, v;
  int p1, p2,var;
  char s[MAXOP],variable[26];
  while ((type = getop(s)) != EOF)
  {
    switch (type)
    {
      case NUMBER:
            push (atof(s));
            break;
      case '+':
            push (pop() + pop());
            break;
      case '*':
            push(pop() * pop());
            break;
      case '-':
            op2 = pop();
            push (pop() - op2);
            break;
      case '/':
            op2 = pop();
            if (op2 != 0.0)
            push (pop() / op2);
            else
            printf ("error : zero divisor\n");
            break;
      case '%':
            p2 = pop();
            p1 = pop();
            if (p2 != 0.0)
            push (p1 - (p1/p2) * p2);
            else
            printf ("error : zero divisor\n");
            break;
      case '\n':
           v = pop();
           printf ("\t%.8g\n", v);
           break;
      case 'v' :
           push(v);
           break;
      case 'p':
           printtop();
           break;
      case 'c':
           sp = 0;
           break;
      case 'd':
           op2 = pop();
           push(op2);
           push(op2);
           break;
      case 's':
           op1 = pop();
           op2 = pop();
           push(op1);
           push(op2);
           break;
      case 'i':
           push(sin (pop()));
           break;
      case 'e':
           push (exp(pop()));
           break;
      case '=':
           pop();
           if(var >= 'A' && var <= 'Z')
              variable[var-'A']=pop();
           break;
      case '^':
           op2 = pop();
           op1 = pop();
           push (pow (op1, op2));
           break;
      default:
           if(type >= 'A' && type <= 'Z')
             push(variable[type -'A']);
           else
             printf("error: unknown command %s\n",s);
           break;
        }
        var = type;
    }
    return 0;
}
#define MAXVAL 100
double val[MAXVAL];
void push(double f)
{
  if (sp < MAXVAL)
     val[sp++] = f;
  else
    printf ("error : stack full, can't push %g\n", f);
}
double pop(void)
{
  if (sp > 0)
    return val[--sp];
  else
  {
    printf ("error : stack empty");
    return 0.0;
  }
}
void printtop()
{
  if (sp > 0)
        printf ("%.8g\n", val[--sp]);
  else
        printf ("error: stack empty\n");
}
#include<ctype.h>
int getch(void);
void ungetch(int);
int getop(char s[])
{
  int i, c;
  while ((s[0] = c = getch()) == ' ' || c == '\t')
   ;
  s[1] = '\0';
  if (!isdigit(c) && c != '.' && c != '-')
   return c;
   i = 0;
   if (c == '-')
       if (isdigit(c = getch()) || c == '.')
        s[++i] = c;
        else
        {
          if (c != EOF)
           ungetch(c);
           return '-';
        }
  if (isdigit(c))
    while (isdigit(s[++i] = c = getch()))
       ;
  if (c == '.')
    while (isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';
  if (c != EOF)
     ungetch(c);
     return NUMBER;
}
#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;
int getch(void)
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c)
{
  if (bufp >= BUFSIZE)
    printf ("ungetch : too many characters\n");
  else
   buf[bufp++] = c;
}
