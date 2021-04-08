#include "std_lib_facilities.h"
//Exercise 2
int swap_v(int a, int b)
{ int temp; temp = a; a = b; b = temp; }

int swap_r(int& a, int& b)
{ int temp; temp = a; a = b; b = temp; }

/*int swap_cr(const int& a, const int& b) //Assignment of read only reference
{ int temp; temp = a; a = b; b = temp; } */

int main()
{
int x = 7;
int y =9;
cout << x << ' '<<y <<endl;
swap_r(x,y); // replace ? by v, r, or cr
cout << x << ' '<<y <<endl;
//swap_r(7,9);
cout << x << ' '<<y <<endl;
const int cx = 7;
const int cy = 9;
//swap_r(cx,cy);
cout << x << ' '<<y <<endl;
//swap_r(7.7,9.9);
cout << x << ' '<<y <<endl;
double dx = 7.7;
double dy = 9.9;
//swap_r(dx,dy);
cout << x << ' '<<y <<endl;
//swap_r(7.7,9.9);
cout << x << ' '<<y <<endl;

}
