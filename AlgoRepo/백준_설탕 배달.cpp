#include <cstdio>

using namespace std;

int main()
{
   int n, answer = 0;
   scanf("%d", &n);

   while (1)
   {
      if (n % 5 == 0)
      {
         n -= 5;
         answer++;
      }
      else
      {
         n -= 3;
         answer++;
      }

      if (n == 0)
      {
         printf("%d", answer);
         break;
      }
      else if (n < 0)
      {
         printf("-1");
         break;
      }
   }

   return 0;
}