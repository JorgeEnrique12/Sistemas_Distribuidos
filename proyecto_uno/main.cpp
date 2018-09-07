
#include <iostream>
#include <cmath>
#include<sys/types.h>
#include<unistd.h>
using namespace std;

class Customer {

  private:
    int gallons;
    int arrival_time;
    int grade;
    static int totalgalons87;
    static int totalgalons93;
    static int totalgalons97;
  public:
    Customer(int g = 1,int a = 1,int r = 1) : gallons(g), arrival_time(a),grade(r) {} 
    int getGalons();
    int getTime();
    void printData();
    int getTotalGallons87();
    int getTotalGallons93();
    int getTotalGallons97();
    void increaseGallons();
};
int Customer::totalgalons87 = 0;
int Customer::totalgalons93 = 0;
int Customer::totalgalons97 = 0;

void Customer::increaseGallons(){
  
  if (grade == 87) {
    totalgalons87 = totalgalons87 + gallons;
  }
  
  if (grade == 93) {
    totalgalons93 = totalgalons93 + gallons;
  }
  
  if (grade == 97) {
    totalgalons97 = totalgalons97 + gallons;
  }
}

int Customer::getTotalGallons87(){
  return totalgalons87;
}
int Customer::getTotalGallons93(){
  return totalgalons93;
}
int Customer::getTotalGallons97(){
  return totalgalons87;
}

void Customer::printData(){
  cout << "Time: " << arrival_time << " minutes" << endl;
  cout << "Gallons: " << gallons << endl;
  cout << "Grades: " << grade << endl;
}

int main()
{
  srand(getpid());
  Customer a;
  int grades[3] = {87,93,97};

  for(int i = 0; i < 10; i++){
    Customer c(rand() % 13 + 3,rand() % 15 + 1,grades[rand() % 3]);
    c.increaseGallons();
    c.printData();
  }
  cout << "Total Gallons 87 Octanes: " << a.getTotalGallons87() << endl;
  cout << "Total Gallons 93 Octanes: " << a.getTotalGallons93() << endl;
  cout << "Total Gallons 97 Octanes: " << a.getTotalGallons97() << endl;
  return 0;
}
