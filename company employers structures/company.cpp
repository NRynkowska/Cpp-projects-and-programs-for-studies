#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <conio.h>
using namespace std;

struct Pracownicy{
  struct Dane_os{
    string imie;
    string nazwisko;
    long pesel;
  };
  Dane_os dane_os;

  float srednie_wynagrodzenie;
};

int licznik = 0;
char wybor;

int main(){
  Pracownicy firma[10];


    while (1){

      cout<<endl;
      cout << "MENU GLOWNE" << endl;
      cout << "-----------------" << endl;
      cout << "1. Dodaj nowego pracownika" << endl;
      cout << "2. Wyswietl pracownikow" << endl;
      cout << "3. Pokaz srednia wynagrodzen firmy" << endl;
      cout << "4. Koniec programu" << endl;
  
      cout << endl;
      wybor=getch();
  
      switch(wybor)
      {
      case '1':
            cout << "Podaj imie: " << endl;
            cin >> firma[licznik].dane_os.imie;
            cout << "Podaj nazwisko: " << endl;
            cin >> firma[licznik].dane_os.nazwisko;
            cout << "Podaj nr pesel: " << endl;
            cin >> firma[licznik].dane_os.pesel;
            cout << "Podaj srednie wynagrodzenie: " << endl;
            cin >> firma[licznik].srednie_wynagrodzenie;
            licznik++;
      break;
  
      case '2':
              if (licznik==0)
              {
                cout << "Nie ma pracownikow." << endl; 
              }else{
                for(int i=0; i<licznik; i++){
                  cout << "Imie: " << firma[i].dane_os.imie << endl;
                  cout << "Nazwisko: " << firma[i].dane_os.nazwisko << endl;
                  cout << "Pesel: " << firma[i].dane_os.pesel << endl;
                  cout << "Srednie wynagrodzenie: " << firma[i].srednie_wynagrodzenie << endl << endl;
                  
                }
              }
              
      break;
  
      case '3':{
              float suma = 0;
              float srednia = 0;
              if (licznik == 0)
              {
                cout << "Nie ma pracownikow." << endl;
              }else{
              for(int i=0; i<licznik; i++){
                suma = suma + firma[i].srednie_wynagrodzenie;
              }
              srednia = suma/licznik;
              cout << "srednie wynagrodzenie firmy wynosi: " << srednia << endl;
              }
              
              
              
      break;}

      case '4':
              exit(0);
      break;
  
      default: cout<<"Nie ma takiej opcji w menu!";
      }
    }
    getchar();getchar();
    system("cls");


 
  return 0;


}
