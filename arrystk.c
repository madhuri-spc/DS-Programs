/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#define SIZE 10

struct intstk
{
     int stop;
     int stk[SIZE];
};

void pushstk(struct intstk *);
int popstk(struct intstk *);
void dispstk(struct intstk *);

int main()
{
    struct intstk s;
    s.stop = 0;
    int ch, x;
    do{
        printf("\n MENU");
        printf("\n 1. Push");
        printf("\n 2. Pop");
        printf("\n 3. Display");
        printf("\n 4. Exit");
        printf("\n Enter Choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : pushstk(&s);
                      break;
            case 2: x = popstk(&s);    
                    break;
            case 3: dispstk(&s);
                    break;
        } // switch ends
    } while (ch >=1 && ch <= 3);
    return 0;
}

void pushstk(struct intstk *s)
{
    int val;
    printf(" \n Enter a int to push :");
    scanf("%d",&val);
    
    if(s->stop == SIZE)
        printf("\n Stack overflow.. Cannot Push...");
    else
    {
       s->stk[s->stop] = val;
       s->stop++;
    }
}

void dispstk(struct intstk *s)
{
      int i;
      printf("\n Stack is :  ");
      for(i=0; i<s->stop; i++)
            printf("%d    ", s->stk[i]);
      printf(" TOP");
}
int popstk(struct intstk *s)
{
    int tmp = -1;
    if (s->stop == 0)
        printf("\nCannot Pop! Stack Underflow....");
    else
    {
        s->stop--;
        tmp = s->stk[s->stop];
        printf("\n Popped off %d....", tmp);
        s->stk[s->stop] = 0;
    }
    return tmp;
}