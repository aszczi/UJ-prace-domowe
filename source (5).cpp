// Joanna Szewczyk
#include <iostream>


int main() {

    float liczba_gierek;

    float liczba_gier = 0;
    float liczba_punktow = 0;
    float liczba_gier_a = 0;
    float liczba_gier_b = 0;
    float liczba_gier_c = 0;
    float liczba_gier_d = 0;
    float remisy_a = 0;
    float remisy_b = 0;
    float remisy_c = 0;
    float remisy_d = 0;
    float  liczba_punktow_a = 0;
    float  liczba_punktow_b = 0;
    float  liczba_punktow_c = 0;
    float  liczba_punktow_d = 0;

    char ch1;
    char ch2;
    unsigned int ch3;
    char ch4;
    char ch5;
    unsigned int ch6;

    int i = 0;

std::cin >> liczba_gierek;

    while (i < liczba_gierek) {
        i++;
        std::cin >> ch1;
        std::cin >> ch2;
        std::cin >> ch3;
        std::cin >> ch4;
        std::cin >> ch5;
        std::cin >> ch6;
   

        if (ch1 == 'a') {
            liczba_gier_a++;
        }
        else if (ch1 == 'b') {
            liczba_gier_b++;
        }
        else if (ch1 == 'c') {
            liczba_gier_c++;
        }
        else if (ch1 == 'd') {
            liczba_gier_d++;
        }
        if (ch4 == 'a') {
            liczba_gier_a++;
        }
        else if (ch4 == 'b') {
            liczba_gier_b++;
        }
        else if (ch4 == 'c') {
            liczba_gier_c++;
        }
        else if (ch4 == 'd') {
            liczba_gier_d++;
        }
       
            if (ch2 == ch5 && ch3 == ch6) {  // remisy

                    if (ch1 == 'a') {
                         remisy_a++;                        
                    }
                        else if (ch1 == 'b') {
                            remisy_b++;                     
                        }
                        else if (ch1 == 'c') {
                            remisy_c++;                      
                        }
                        else  if (ch1 == 'd') {
                            remisy_d++;
                        }
                    if (ch4 == 'a') {
                        remisy_a++;                      
                    }
                        else  if (ch4 == 'b') {
                            remisy_b++;                       
                        }
                        else  if (ch4 == 'c') {
                            remisy_c++;                     
                        }
                        else if (ch4 == 'd') {
                            remisy_d++;                      
                        }

            }
                else  if (ch2 == ch5 && ch3 > ch6) {
                    if (ch1 == 'a') {
                        liczba_punktow_a++;
                    }
                    else if (ch1 == 'b') {
                        liczba_punktow_b++;
                    }
                    else if (ch1 == 'c') {
                        liczba_punktow_c++;
                    }
                    else if (ch1 == 'd') {
                        liczba_punktow_d++;
                    }
                   
                }
               
                     else if (ch2 == ch5 && ch3 < ch6) {

                        if (ch4 == 'a') {
                        liczba_punktow_a++;
                        }
                        else if (ch4 == 'b') {
                            liczba_punktow_b++;
                        }
                        else if (ch4 == 'c') {
                            liczba_punktow_c++;
                        }
                        else if (ch4 == 'd') {
                            liczba_punktow_d++;
                        }
                  }  //koniec remisow
    
            else  if (ch2 != ch5)
            {
                if (ch2 == 'J' && (ch5 == 'P' || ch5 == 'S')) {
                    liczba_punktow++;
                }

                else if (ch2 == 'K' && (ch5 == 'J' || ch5 == 'N')) {
                    liczba_punktow++;
                }

                else  if (ch2 == 'N' && (ch5 == 'J' || ch5 == 'P')) {
                    liczba_punktow++;
                }

                else if (ch2 == 'P' && (ch5 == 'K' || ch5 == 'S')) {
                    liczba_punktow++;
                }

                else if (ch2 == 'S' && (ch5 == 'K' || ch5 == 'N')) {
                    liczba_punktow++;
                }

                if (ch1 == 'a') {  
                    liczba_punktow_a += liczba_punktow;
                }
                else  if (ch1 == 'b') {                  
                    liczba_punktow_b += liczba_punktow;
                }
                else  if (ch1 == 'c') {
                    liczba_punktow_c += liczba_punktow;
                }
                else  if (ch1 == 'd') {                   
                    liczba_punktow_d += liczba_punktow;
                }
                ///////////////////////////////////////////////////////////////
                liczba_punktow = 0;

                if (ch5 == 'J' && (ch2 == 'P' || ch2 == 'S')) {
                    liczba_punktow++;
                }

                else if (ch5 == 'K' && (ch2 == 'J' || ch2 == 'N')) {
                    liczba_punktow++;
                }

                else  if (ch5 == 'N' && (ch2 == 'J' || ch2 == 'P')) {
                    liczba_punktow++;
                }

                else if (ch5 == 'P' && (ch2 == 'K' || ch2 == 'S')) {
                    liczba_punktow++;
                }

                else if (ch5 == 'S' && (ch2 == 'K' || ch2 == 'N')) {
                    liczba_punktow++;
                }

                if (ch4 == 'a') {
                   
                    liczba_punktow_a += liczba_punktow;
                }
                else   if (ch4 == 'b') {
                
                    liczba_punktow_b += liczba_punktow;
                }
                else  if (ch4 == 'c') {
                    
                    liczba_punktow_c += liczba_punktow;
                }
                else   if (ch4 == 'd') {
                    
                    liczba_punktow_d += liczba_punktow;
                }
            }
            liczba_punktow = 0;
    }


    if (liczba_gier_a != 0) {
        std::cout << "gracz a" << std::endl;

        if ((liczba_punktow_a) != 0) {
            std::cout << "    wygrane: " << ((liczba_punktow_a) / liczba_gier_a) * 100 << "%"
                << std::endl;
        }
        if (remisy_a != 0) {
            std::cout << "    remisy: " << remisy_a / liczba_gier_a * 100 << "%"
                << std::endl;
        }
        if ((liczba_gier_a - liczba_punktow_a - remisy_a) != 0) {
            std::cout << "    przegrane: " << (liczba_gier_a - liczba_punktow_a - remisy_a) / liczba_gier_a * 100 << "%"
                << std::endl;
        }
        std::cout << std::endl;
    }

    if (liczba_gier_b != 0) {
        std::cout << "gracz b" << std::endl;

        if ((liczba_punktow_b) != 0) {
            std::cout << "    wygrane: " << ((liczba_punktow_b) / liczba_gier_b) * 100 << "%"
                << std::endl;
        }
        if (remisy_b != 0) {
            std::cout << "    remisy: " << remisy_b / liczba_gier_b * 100 << "%"
                << std::endl;
        }
        if ((liczba_gier_b - liczba_punktow_b - remisy_b) != 0) {
            std::cout << "    przegrane: " << (liczba_gier_b - liczba_punktow_b - remisy_b) / liczba_gier_b * 100 << "%"
                << std::endl;
        }
        std::cout << std::endl;
    }

    if (liczba_gier_c != 0) {
        std::cout << "gracz c" << std::endl;

        if ((liczba_punktow_c) != 0) {
            std::cout << "    wygrane: " << ((liczba_punktow_c) / liczba_gier_c) * 100 << "%"
                << std::endl;
        }
        if (remisy_c != 0) {
            std::cout << "    remisy: " << remisy_c / liczba_gier_c * 100 << "%"
                << std::endl;
        }
        if ((liczba_gier_c - liczba_punktow_c - remisy_c) != 0) {
            std::cout << "    przegrane: " << (liczba_gier_c - liczba_punktow_c - remisy_c) / liczba_gier_c * 100 << "%"
                << std::endl;
        }
        std::cout << std::endl;
    }

    if (liczba_gier_d != 0) {
        std::cout << "gracz d" << std::endl;

        if (liczba_punktow_d != 0) {
            std::cout << "    wygrane: " << ((liczba_punktow_d) / liczba_gier_d) * 100 << "%"
                << std::endl;
        }
        if (remisy_d != 0) {
            std::cout << "    remisy: " << remisy_d / liczba_gier_d * 100 << "%"
                << std::endl;
        }
        if ((liczba_gier_d - liczba_punktow_d - remisy_d) != 0) {
            std::cout << "    przegrane: " << (liczba_gier_d - liczba_punktow_d - remisy_d) / liczba_gier_d * 100 << "%"
                << std::endl;
        }
    }
    return 0;
}

