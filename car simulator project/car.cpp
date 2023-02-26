#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <conio.h>
#include <stdlib.h>
#include <cctype>
using namespace std;

float predkosc;
int obroty;
int podskok;
int bieg;
int stan;
char wybor;
int kod_bledu;

void menu_poczatkowe(){
    system("cls"); // czyszczenie terminala
    if (kod_bledu == 1){ 
        cout << "Za duza predkosc, po obnizeniu biegu. Silnik zgasl." << endl;
    }else if(kod_bledu == 2){
        cout << "Probujesz ruszyc na za wysokim biegu. Silnik zgasl." << endl;
    }else if (kod_bledu == 3){
        cout << "Samochod zaczal sie dusic. Za wysoki bieg dla tej predkosci. Silnik zgasl." << endl;
    }
    
    kod_bledu = 0;
    cout << "---- Witaj w samochodzie. Silnik wylaczony. ----" << endl << endl;
    cout << "Nacisnij SHIFT+E, aby przytrzymac sprzeglo i uruchomic silnik" << endl;
    cout << "Nacisnij dowolny inny przycisk zeby wysiasc" << endl;
    wybor=getch();
    switch (wybor)
    {
    case 'E':
        cout << "Uruchomiles silnik" << endl;
        stan = 1;
        break;
    
    default:
        cout << "Wysiadles z pojazdu, idz pieszo!" << endl;
        exit(0);
        break;
    }
    
}

void wyswietl_dane(){
    system("cls");
    if (kod_bledu == 4)
    {
        cout << "Przyspieszyles z wcisnietym sprzeglem, obroty chwilowo podskoczyly" << endl;
    }   
    
    cout << "Predkosc: " << predkosc << endl;
    cout << "Obroty: " << obroty << endl;
    cout << "Bieg: " << bieg << endl << endl;

    if (kod_bledu == 4){
        obroty = podskok;
        kod_bledu = 0;
    }

    if (kod_bledu == 5){
        cout << "Za wysokie obroty, zmien bieg!" << endl;
        kod_bledu = 0;
    }

    if (kod_bledu == 6){
        cout << "Osiagnieto predkosc maksymalna!" << endl;
        kod_bledu = 0;
    }
    
}

void menu(){
    cout << "W:\t\tNacisnij W, zeby jechac." << endl;
    cout << "SHIFT+A:\tNacisnij SHIFT+A, zeby przytrzymac sprzeglo i zmienic bieg na wyzszy." << endl;
    cout << "SHIFT+D:\tNacisnij SHIFT+D, zeby przytrzmac sprzeglo i zmienic bieg na nizszy." << endl;
    cout << "S:\t\tNacisnij S, zeby zwolnic." << endl;
    cout << "E:\t\tNacisnij E, zeby zgasic silnik." << endl;
    wybor=getch();
    switch (wybor){
        case 'w':
            if (obroty > 5500 && bieg != 5)
            {
                cout << "Zepsules silnik. Samochod nie nadaje sie do jazdy." << endl;
                getchar();getchar();
                exit(0);
                
            }else if (obroty == 5500 && bieg == 5){
                kod_bledu = 6;
            }
            else if (bieg == 0)
            {
            // jesli na luzie to nic sie nie dzieje    
            }else if (predkosc == 0 && bieg != 1){
                kod_bledu = 2;
                stan = 0;
            }else if (obroty > 3500 && bieg <5){
                kod_bledu = 5;
                predkosc++;
                obroty = obroty + 50;}
            else{
                predkosc++;
                obroty = obroty + 50;
            };

        break;

        case 'W':
            podskok = obroty; // obroty zapisywane do zmiennej tymczasowej
            obroty = 4000; // chwilowy podskok obrotow
            kod_bledu = 4;
        break;
        
        case 'A':
            if (bieg < 5)
            {
                bieg++;
                if (bieg != 1 && predkosc != 0){ // jesli zwiekszamy bieg przy predkosci roznej od zera i biegu roznym od 1 obroty spadaja
                obroty = obroty - 1000; 
                }
                if(obroty < 1000 && bieg > 1 && predkosc != 0){ // Za wysoki bieg dla tej predkosci. Silnik zgasl
                    kod_bledu = 3;
                    obroty = 0;
                    predkosc = 0;
                    stan = 0;
                }
            }                        
        break;

        case 'D':
            if (bieg > 0){
                if (predkosc != 0 && bieg > 1){ // w trakcie jazdy nie mozna wrzucic na luz 
                bieg--;
                obroty = obroty + 1000;
                }else if (predkosc == 0 && bieg != 0 ){
                bieg --;
                }
                if(obroty > 4500){
                    kod_bledu = 1;
                    obroty = 0;
                    predkosc = 0;
                    stan = 0;
                }
            
            }
            
            
        break;
        case 's': case 'S':
            if(predkosc != 0){
            predkosc--;
            obroty = obroty - 50;
            }
        break;

        case 'e': case 'E':
            stan = 0;
        break;

        default:
        break;

    }
}

int main(){

    menu_poczatkowe(); // wyswietlenie menu poczatkowego 
    predkosc = 0;
    bieg = 0;
    obroty = 0;
    while (1) // wykonuje sie caly czas
    {
        if (stan == 1 ) // gdy jest wlaczony silnik
        {
            wyswietl_dane();
            menu();
        }
        else{
            menu_poczatkowe();
        }
        
    };
    
    getchar();getchar();
    system("cls");

    return 0;
}
