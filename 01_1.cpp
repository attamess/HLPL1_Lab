#include "std_lib_facilities.h"
int square(int a)
{
  return a*a;
}
int main()
{
/*
int i = 0;
while(i < 100)
 {
   cout << i << '\t' << i*i<<'\n';
   i++;
 }
 */


/*
for (int i=0;i<100;i++)
 cout<<i<<'\t'<<i*i<<'\n';
 */

 for(int i=0;i<100;i++)
    cout<<i<<'\t'<<square(i)<<'\n';
return 0;
}
