#include <iostream>
#include "opg1.cpp"
using namespace std;

int main() {
  Circle circle(5);

  double area = circle.get_area();
  cout << "Arealet er lik " << area << " cm^2" <<  endl;

  double circumference = circle.get_circumference();
  cout << "Omkretsen er lik " << circumference << " cm" << endl;
}