#include<stdio..h>
#include<stdlib.h>

#define s 100

int stk[s],
int tos = -1;

int empty(void)
{
    if(tos==-1)
        return 1;
    else
        return 0;

}

int full()
{
    if (tos==s-1)
        return 1;
    else
        return 0;
}


void push(int x)
{
    if(!full())
    {
        ++tos;
        stk[tos]= x;
    }
    else 
    {
    exit(0);

    }
}
int pp(void)
{
    if(!empty())
    {
        return stk[tos--];
    }
    else
    {
        exit(0);
    }
}
int peep (void)
{
    if(!empty())
    {
        return stk[tos];
    }
    else
    {
        exit(0);
    }
}
int main()
{
    int n,num,x;
    char ch;

    while(1)
    {
        printf("\n1. Push\n2. Pop\n3. Peep\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&n);

        switch(n)
        {
            case 1:
                printf("Enter the number to be pushed: ");
                scanf("%d",&num);
                push(num);
                break;
            case 2:
                x=pp();
                printf("Popped element is: %d",x);
                break;
            case 3:
                x=peep();
                printf("Top element is: %d",x);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice");
        }
    }
}
printf("want to continue (y/n): ");
        scanf(" %c",&ch);
        if(ch=='n') 
            break;
    }
    return 0;
}