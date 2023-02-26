#include <iostream>
#include <string>
using namespace std;
int main(){
  cout << "Podaj dochod: ";
  double dochod;
  cin >> dochod;
  double podatek;
  if(dochod <= 85528){
    podatek = 0.18*dochod-556.02;
  }
  else if (dochod > 85528)
  {
    podatek = 14839.02+0.32*(dochod-85528);
  }
  cout << "Podatek wynosi: " << podatek;

  return 0;
}
