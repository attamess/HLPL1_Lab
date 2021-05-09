#include "std_lib_facilities.h"

//4
//function to print array (size = 10)
 print_array10(ostream& os, int* a) {
   for(int i=0; i<10; ++i)
     os << a[i] << ' ';
    os << endl;
 }

//7
//function to print arrays (size = n)
print_array(ostream& os, int* a, int n) {
  for (int i = 0; i<n; ++i)
    os << a[i] << ' ';
  os << endl;
}

//10
void print_vector(ostream& os, vector<int> v) {
  for(int i = 0; i<v.size(); ++i)
    os << v[i] << ' ';
}


int main()
try {
//1
//allocate an array of 10 ints
  int* a = new int[10];
  for(int i = 0; i<10; ++i)
    a[i]=i;
cout << "Question - 2" << endl;
  for(int i=0; i<10; ++i) //2 print values of array
    cout << a[i] << ' ';
//  print_array10(cout, a); //4
  cout << endl;
//3 deallocate array
  delete[] a;

//5
cout << "\nQuestion - 5" << endl;
  int* b = new int[10];
  for(int i = 0; i<10; ++i)
    b[i] = 100 + i;
  print_array10(cout, b); //4
  delete[] b;

//6
cout << "\nQuestion - 6" << endl;
int* c = new int[11];
for(int i = 0; i<11; ++i)
  c[i] = 100+i;
print_array(cout, c, 11); //7
delete[] c;

//8
cout << "\nQuestion - 8" <<endl;
int* d = new int[20];
for(int i = 0; i<20; ++i)
  d[i] = 100 + i;
print_array(cout, d, 20);
delete[] d;

//10
cout << "\nQuestion - 10" << endl;
vector<int> v5;
for(int i = 0; i<10; ++i) {
  v5.push_back(100+i);
};
print_vector(cout, v5);
cout << endl;

vector<int> v6;
for(int i = 0; i<11; ++i) {
  v6.push_back(100+i);
};
print_vector(cout, v6);
cout << endl;

vector<int> v8;
for(int i = 0; i<20; ++i) {
  v8.push_back(100+i);
};
print_vector(cout, v8);
cout << endl;

//Second Part
cout << "\n---Second part---" << endl;
//1
int s1 = 7;
int* p1 = &s1;
//2
cout << "\nQuestion - 2" << endl;
cout << "p1: " << p1 << endl;
cout << "*p1: " << *p1 << endl;
//3
int* p2 = new int[7];
for(int i = 0; i<7; ++i)
  p2[i] = pow(2,i);
//4
cout << "\nQuestion - 4" << endl;
print_array(cout, p2, 7);

//5
int* p3 = p2;
//6
p2 = p1;
//7
p2 = p3;

//8
cout << "\nQuestion - 8" << endl;
cout << "p1: " << p1 << endl;
cout << "*p1: " << *p1 << endl;
cout << "p2: " << p2 << endl;
cout << "*p2:" << *p2 << endl;
//9
delete[] p2;
//10
p1 = new int[10];
for(int i = 0; i<10; ++i) {
  p1[i] = pow(2,i);
};
//11
p2 = new int[10];
//12
cout << "\nQuestion - 12" << endl;
for(int i = 0; i<10; ++i)
  p2[i] = p1[i];
print_array(cout, p2, 10);
//13
cout << "\nQuestion - 13" << endl;
vector<int> vec1;
for(int i = 0; i<10; ++i)
  vec1.push_back(pow(2,i));
vector<int> vec2;
for(int i = 0; i<vec1.size(); ++i)
  vec2.push_back(vec1[i]);
print_vector(cout,vec2);

  return 0;
}
catch (exception& e) {
  cerr << e.what() << endl;
}
