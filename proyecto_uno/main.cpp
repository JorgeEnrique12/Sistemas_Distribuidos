#include <iostream>
#include <iomanip>
using namespace std;
// class declaration section
class Date
{
  private:
    long yyyymmdd;
  public:
    Date(long = 20120704L);
    Date(int , int , int );   
    void showDate();  
};

Date::Date(int mm, int dd, int yyyy)
{
  yyyymmdd = yyyy * 10000.0 + mm * 100.0 + dd;

}

Date::Date(long ymd)
{
    yyyymmdd = ymd;
}
void Date::showDate()
{
  cout << "The date is ";
  cout << yyyymmdd << endl;
  return;
}
int main()
{
  Date a, b(4,1,1998), c(20090515L); // declare three objects
  a.showDate();           // display object a's values
  b.showDate();           // display object b's values
  c.showDate();           // display object c's values
  return 0;
}