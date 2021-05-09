#include "std_lib_facilities.h"

/*template<typename T, int N>
struct array {

  using value_type = T;
  using iterator = T*; //T type pointer
  using const_iterator = const T*; //const T type pointer
  using size_type = unsigned int;

  T elem[N];

  iterator begin() { return elem; }
  const iterator begin() const { return elem; }
  iterator end() { return elem+N; }
  const iterator end() const { return elem+N; }

  T& operator[](int n) { return elem[n]; }
  const T& operator[](int n) const { return elem[n]; }

  T* data() { return elem; }
  const T* data() const { return elem; }
};*/


//6
template<typename Iter1, typename Iter2>
//f1 - begin copying from where (orig)
//e1 - end copying where (orig)
//f2 - where to put copy (copy)
Iter2 my_copy(Iter1 f1, Iter1 e1, Iter2 f2)
{
  while(f1!=e1)
  {
    *f2 = *f1;
    ++f1;
    ++f2;
  }
  return f2;
}

template<typename C> void printout(const C& c)
{
  for(const auto& x : c)
    cout << x << ' ';
  cout << endl;
}


int main()
{

  const int size = 10;

//1
  array<int,size> a;
  for(int i = 0; i < size; ++i)
    a[i] = i;
  //list<int>::iterator iter = l.begin();
  cout << "Array:" << endl;
  printout(a);

//2
  vector<int> v;
  for(int i = 0; i < size; ++i)
    v.push_back(i);
  cout << "Vector:" << endl;
  printout(v);

//3
  list<int> l;
  for(int i = 0; i < size; ++i)
    l.push_back(i);
  //list<int>::iterator iter = l.begin(); //declare the iterator
  //begin returns the first elem of the container
  cout << "List:" << endl;
  printout(l);

//4
  cout << "\nQuestion - 4" << endl;
  array<int, size> a2 = a;
  cout << "Array copy:" << endl;
  printout(a2);
  vector<int> v2 = v;
  cout << "Vector copy:" << endl;
  printout(v2);
  list<int> l2 = l;
  cout << "List copy:" << endl;
  printout(l2);

//5
  cout << "\nQuestion - 5" << endl;
  for(int i = 0; i<size; ++i)
    a[i] = i+2;
  cout << "Array: (+2)" << endl;
  printout(a);

  for(int i = 0; i<size; ++i)
    v[i] = i+3;
  cout << "Vector (+3):" << endl;
  printout(v);

  for(list<int>::iterator p = l.begin(); p!=l.end(); ++p)
    *p += 5;
  cout << "List (+5):" << endl;
  printout(l);

//7
  cout << "\nQuestion - 7" << endl;
  //vector iterator
  vector<int>::iterator v_it = my_copy(a.begin(), a.end(), v.begin());
  cout << "Vector copied from array: " << endl;
  printout(v);
  //array iterator
  array<int,size>::iterator a_it = copy(l.begin(),l.end(),a.begin());
  cout << "Array copied from list: " << endl;
  printout(a);

//8
  cout << "\nQuestion - 8" << endl;
  v_it = find(v.begin(), v.end(), 3);
  if(v_it != v.end())
    cout << "Vector contains the value 3 and its index is " << v_it-v.begin() << endl;
  list<int>::iterator l_it = find(l.begin(), l.end(), 27);
  if (l_it != l.end())
  { int index = 0;
    for(list<int>::iterator iter = l.begin(); iter != l_it; ++iter)
      ++index;
    cout << "List contains the value 27 and its position is " << index << endl;
  }
  else
    cout << "27 was not found in the list." << endl;


  return 0;
}
