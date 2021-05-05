#include "std_lib_facilities.h"

    //1
vector<int> gv; //global vector
//initialized:
void gv_init()
{
  for(int i = 0; i < 10; ++i)
    gv.push_back(pow(2,i));
}

void print_vector(vector<int> v)
{
  for(int i = 0; i<v.size(); ++i)
    cout << v[i] << ' ';
  cout << endl;
}

    //2-3
int f(vector<int> arg_vec)
{
//3.a
vector<int> lv(arg_vec.size()); //local vector
//3.b
lv = gv; //copy values
//3.c
print_vector(lv);

//3.d
vector<int> lv2;
//initialize:
lv2 = arg_vec;
//3.e
print_vector(lv2);
}


    //4
int main()
{
gv_init(); //1

//4.a
f(gv);

//4.b
vector<int> vv;
//initialize
vv.push_back(1);
for(int i = 1; i < 10; ++i)
  vv.push_back(vv[i-1] * (i+1));
//4.c
f(vv);

return 0;
}
