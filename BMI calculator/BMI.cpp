#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main(){
  cout << "Podaj wage (kg): ";
  float masa;
  cin >> masa;
  if(masa < 0) masa= masa*(-1);
  cout << "Podaj wzrost (cm): ";
  float wzrost;
  cin >> wzrost;
  if(wzrost < 0) wzrost= wzrost*(-1);
  wzrost = wzrost/100; //zamiana z cm na m
  float BMI;
  BMI = masa/pow(wzrost,2);

  if(BMI < 18.5) {
    cout << "Za niskie BMI!\n";
  } else if (BMI > 25) {
    cout << "Za wysokie BMI!\n";
  } else {
    cout << "Prawidlowe BMI :)\n";
  }
  cout << "BMI wynosi: " << BMI;
  
  return 0;
}

