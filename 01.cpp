#include "std_lib_facilities.h"
int main()
{
/* int age = 12;
char c='a';
double d=12.5;
cout<< "Age: " << age <<'\n';
cout<<"D:"<<d<<'\n';
string name = "Saga";
cout << name <<'\n';
string surname;
cin>>surname;
string full_name = surname + ' ' + name;
cout <<full_name; */
constexpr double cm_per_inch = 2.54; //or const
double length = 1;
char unit = 0;
cout << "Please enter a length followed by a unit (c or i):\n";
cin >> length >> unit;
if (unit=='c')
    cout << length << " cm = " << length/cm_per_inch << " inch\n";
else
    if (unit=='i')
      cout<<length<<" inch = "<<length * cm_per_inch <<" cm\n";
else
      cout << "Invalid unit!";

return 0;
}
