#include "std_lib_facilities.h"

         //Version 1 - Chapter 9.4.1
namespace Version1 {
struct Date {
  int y;
  int m;
  int d;
};



ostream& operator<<(ostream& os, const Date& date)
{
  return  os << date.y << ". "
             << date.m << ". "
             << date.d << "\n";
}

void init_day(Date& dd, int y, int m, int d) {
if (y < 0) error("Invalid year");
 if (m > 12 || m < 0) error("Invalid month");
  if (d > 31 || d < 0) error("Invalid day");
dd.y = y;
dd.m = m;
dd.d = d;
}

void add_day(Date& dd, int n) {
  init_day(dd, dd.y, dd.m, dd.d);
  dd.d+=n;
  if(dd.d>31) {
    ++dd.m;
    dd.d -= 31;
  }
  if (dd.m>12) { ++dd.y; dd.m -=12; }
};
}

void version1() {
  using namespace Version1;
  cout << "Version 1 - Chapter 9.4.1" <<endl;
  Date today;
  init_day(today, 1978, 6, 25);
  cout << "Today: "<<today << endl;
  Date tomorrow;
  tomorrow = today;
  add_day(tomorrow, 1);
  cout << "Tomorrow: "<< tomorrow << endl;
  Date check;
  init_day(check, 2005, 12, 31);
  add_day(check, 3);
  cout << check << endl;
}

        //Version 2 - Chapter 9.4.2
namespace Version2 {
struct Date {
  int y, m, d;
  Date(int y, int m, int d)
    :y(y), m(m), d(d)
   {
     if (y < 0) error("Invalid year");
      if (m < 0 || m > 12) error("Invalid month");
       if (d < 0 || d > 31) error("Invalid day");
     y = y;
     m = m;
     d = d;
   };

  void add_day(int n) {
    d+=n;
    if(d>31) {
      ++m;
      d -= 31;
    }
    if (m>12) { ++y; m-=12; }
    }
};


ostream& operator<<(ostream& os, const Date& date) {
  return  os << date.y << ". "
             << date.m << ". "
             << date.d << "\n";
};
}

void version2() {
  using namespace Version2;
  cout<<"Version 2 - Chapter 9.4.2\n";
  Date today {1978, 6, 25};
  cout << "Today: "<< today << endl;
  Date tomorrow = today;
  tomorrow.add_day(1);
  cout << "Tomorrow: "<<tomorrow << endl;
  Date check {2005, 12, 31};
  check.add_day(3);
  cout << check << endl;
}

        //Version 3 - Chapter 9.4.3
namespace Version3 {
class Date {
  int y, m, d;
public:
  Date(int y, int m, int d)
    :y(y), m(m), d(d)
   {
     if (y < 0) error("Invalid year");
      if (m < 0 || m > 12) error("Invalid month");
       if (d < 0 || d > 31) error("Invalid day");
     y = y;
     m = m;
     d = d;
   };

  void add_day(int n) {
    d+=n;
    if(d>31) {
      ++m;
      d -= 31;
    }
    if (m>12) { ++y; m-=12; }
  };

  int month() { return m; }
  int day() { return d; }
  int year() { return y; }
};


ostream& operator<<(ostream& os, Date& date) {
  return  os << date.year() << ". "
             << date.month() << ". "
             << date.day() << "\n";
};
}

void version3() {
  using namespace Version3;
  cout << "Version 3 - Chapter 9.4.3\n";
  Date today {1978, 6, 25};
  cout << "Today: "<< today << endl;
  cout << "Month: " << today.month() << endl;
  Date tomorrow = today;
  tomorrow.add_day(1);
  cout << "Tomorrow: "<< tomorrow << endl;
  Date check {2005, 12, 31};
  check.add_day(3);
  cout << check << endl;
}

        //Version 4 - Chapter 9.7.1
namespace Version4 {

  vector<string> months {
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
  };
  enum class Month {
    jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
  };
  Month operator++(Month& m){
    m = (m == Month::dec) ? Month::jan : Month(int(m)+1);
    return m;
  }

  class Date {
  public:
    Date(int y, Month m, int d)
    : y(y), m(m), d(d)
    {
      if (y < 0) error("Invalid year");
       if (m < Month::jan || m > Month::dec) error("Invalid month");
        if (d < 0 || d > 31) error("Invalid day");
    }

    void add_day(int n) {
      d+=n;
      if(d>31) {
        ++m;
        d -= 31;
        if (m==Month::jan)
         { ++y; }
    }
    };
    int day() const { return d; }
    Month month() const { return m; }
    int year() const { return y; }
  private:
    int y;
    Month m;
    int d;
  };


  ostream& operator<<(ostream& os, Month m) {
    return  os << months[int(m)];
  }
  ostream& operator<<(ostream& os, Date& date) {
    return  os << date.year() << " "
               << date.month() << ", "
               << date.day() << "\n";
}

}

void version4() {
  using namespace Version4;
  cout << "Version 4 - Chapter 9.7.1" << endl;
  Date today {1978, Month::jun, 25};
  cout << "Today: "<< today << endl;
  cout << "Month: " << today.month() << endl;
  Date tomorrow = today;
  tomorrow.add_day(1);
  cout << "Tomorrow: "<< tomorrow << endl;
  Date check {2005, Month::dec, 31};
  check.add_day(3);
  cout << check << endl;
}

        //Version 5 - Chapter 9.7.4
namespace Version5 {

  vector<string> months {
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
  };
  enum class Month {
    jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
  };
  Month operator++(Month& m){
    m = (m == Month::dec) ? Month::jan : Month(int(m)+1);
    return m;
  }


  class Date {
  public:
    Date() : y(2001), m(Month::jan), d(1) {}
    Date(int y, Month m, int d)
    : y(y), m(m), d(d)
    {
      if (y < 0) error("Invalid year");
       if (m < Month::jan || m > Month::dec) error("Invalid month");
        if (d < 0 || d > 31) error("Invalid day");
    }
    void add_day(int n);
    void add_month(int n);
    void add_year(int n);
    int day() const { return d; }
    Month month() const { return m; }
    int year() const { return y; }
  private:
    int y;
    Month m;
    int d;
  };

  void Date::add_day(int n) {
    d+=n;
    if(d>31) {
      ++m;
      d -= 31;
      if (m==Month::jan)
       { ++y; }
  }
  };


  void Date::add_year(int n) {
    y+=n;
  };

  ostream& operator<<(ostream& os, Month m) {
    return  os << months[int(m)];
  }
  ostream& operator<<(ostream& os, Date& date) {
    return  os << date.year() << " "
               << date.month() << ", "
               << date.day() << "\n";
}

}

void version5() {
  using namespace Version5;
  cout << "Version 5 - Chapter 9.7.4" << endl;;
  Date d_default;
  cout << "Default date: " << d_default << endl;
  Date today {1978, Month::jun, 25};
  cout << "Today:" << today << endl;
  cout << "Month: " << today.month() << endl;
  Date tomorrow = today;
  tomorrow.add_day(1);
  cout << "Tomorrow: " << tomorrow << endl;
  Date next_year = today;
  next_year.add_year(1);
  cout << "Next year: " << next_year << endl;
  Date check {2005, Month::dec, -31};
  check.add_day(3);
  cout << check << endl;
}

int main()
try {
  version1();       //Chapter 9.4.1
  version2();       //Chapter 9.4.2
  version3();       //Chapter 9.4.3
  version4();       //Chapter 9.7.1
  version5();       //Chapter 9.7.4



  return 0;
} catch (exception& e) {
  cerr << e.what() << endl;
  return 1;
}
