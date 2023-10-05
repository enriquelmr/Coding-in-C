#include<stdio.h>

struct Point
{
   int x, y;
};

int main()
{
   struct Point p1 = {1, 2};

   // p2 is a pointer to structure p1
   struct Point *p2 = &p1;
   int a=10,b=15,*ab,*bb;

   ab=&a;
   bb=&b;
   *ab=2;
   *bb=3;
   // Accessing structure members using structure pointer
   printf("%d %d \n", (*p2).x, p2->
   y);

   return 0;
}
