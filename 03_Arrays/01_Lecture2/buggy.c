#include <stdio.h>

int main()
{

    for (int i = 0; i < 3; i++)
    {
        printf("#\n");
    }
    return 0;
}

void print_column(int height)
{
    for(int i = 0; i<= height ;i++){
        printf("#\n");
    } 
}