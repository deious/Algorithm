#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long f[21];
bool check[21];

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0);

   int n, problem;
   cin >> n >> problem;

   vector<int> a(n);
   f[0] = 1;

   for (int i = 1; i < 21; i++) f[i] = f[i - 1] * i;

   if (problem == 1)
   {
      long long k;
      cin >> k;

      for (int i = 0; i < n; i++)
      {
         for (int j = 1; j <= n; j++)
         {
            if (check[j]) continue;

            if (f[n - i - 1] < k) k -= f[n - i - 1];
            else
            {
               a[i] = j;
               check[j] = true;
               break;
            }
         }
      }

      for (int i = 0; i < n; i++) cout << a[i] << " ";
   }
   else
   {
      for (int i = 0; i < n; i++) cin >> a[i];

      long long ans = 0;

      for (int i = 0; i < n; i++)
      {
         for (int j = 1; j < a[i]; j++)
         {
            if (check[j] == false) ans += f[n - i - 1];
         }
         check[a[i]] = true;
      }

      cout << ans + 1 << "\n";
   }

   return 0;
}