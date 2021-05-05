#include "std_lib_facilities.h"

    //1
const int sz_ga = 10;
//global int array ga of 10 ints
int ga[sz_ga];
//initialized:
void g()
{
  for(int i = 0; i<10; ++i)
  ga[i] = pow(2,i);
}


void print_array(int a[], int sz)
{
  for(int i = 0; i<sz; ++i)
    cout << a[i] << ' ';
  cout << endl;
}


    //2-3
int f(int arg_arr[], int size)
{
//3.a local int array
int la[10];
//3.b
for(int i = 0; i<10; ++i)
  la[i] = ga[i];
//3.c
print_array(la, 10);

//3.d free-store array
int* p = new int[size];
//3.e
for(int i = 0; i<10; ++i)
  p[i] = arg_arr[i];
//3.f
print_array(p,10);
//3.g
delete[] p;
}


    //4
int main()
{
g(); //1

//4.a
f(ga,sz_ga);

//4.b
int aa[10];
aa[0] = 1;
for (int i = 1; i<10; ++i) {
  aa[i] = aa[i-1] * (i+1);
}

//4.c
f(aa,10);

return 0;
}
