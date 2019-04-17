#include <iostream>
#include <string>
//Zahlen in Römische Zahlen

int main()
{
	std::string roman;
	int integer;
	int piece;
	bool neunhundert = true;
	bool zehner = true;
	bool einer = true;
	bool vierhundert = true;

	std::cout << "Plese type in an integer" << std::endl;
	std::cin >> integer;

	if ((integer > 9999) || (integer <= 0)) {
		std::cout << std::endl << "Invalid Integer";
	}
	else {
		if (integer >= 1000) {						//berechnet 1000er --> M 
			piece = (integer / 1000);
			for (int i = 1; i <= piece; i++) {
				std::cout << "M";
			}
			integer %= 1000;
		}
		if (integer >= 500) {						//berechnet 500er --> D
			if ((integer >= 900) && (integer <= 999)) {			// wenn die zahl 900 enthält schreibe CM und setze neunhundert auf false
				std::cout << "CM";
				neunhundert = false;
				vierhundert = false;
			}
			else {
				piece = (integer / 500);						//rechnet integer durch 500 um zu wissen wie viele pieces benötigt werden
				for (int i = 1; i <= piece; i++) {
					std::cout << "D";
				}
			}
			integer %= 500;
		}
		if ((integer >= 100)) {													//berechnet 100er --> C aber nur wenn keine 900
			if ((integer >= 400) && (integer <= 499) && (vierhundert)) {							//bei 400 -- CD und neunhundert auf false	
				std::cout << "CD";
				neunhundert = false;
			}
			else if (neunhundert) {
				piece = (integer / 100);
				for (int i = 1; i <= piece; i++) {
					std::cout << "C";
				}
			}
			integer %= 100;
		}
		if (integer >= 50) {												//berechnet 50er --> L
			if ((integer >= 90) && (integer <= 99)) {						 //bei 90 -- XC
				std::cout << "XC";
				zehner = false;
			}
			else if (zehner)
			{
				piece = (integer / 50);
				for (int i = 1; i <= piece; i++) {
					std::cout << "L";
				}
			}
			integer %= 50;
		}
		if ((integer >= 10) && (zehner)) {						//berechnet 10er --> X wenn 10er false
			if ((integer >= 40) && (integer <= 49)) {			//bei 40 -- XL zehner auf false 
				std::cout << "XL";
				zehner = false;
			}
			else if (zehner) {
				piece = (integer / 10);								//wenn 10er true mache hier weiter
				for (int i = 1; i <= piece; i++) {
					std::cout << "X";
				}
			}
			integer %= 10;
		}
	if (integer % 10 >= 5) {									//berechnet 5er --> V
		if (integer == 9) {
			std::cout << "IX";
			einer = false;
		}
		else if (einer) {
			piece = (integer / 5);
			for (int i = 1; i <= piece; i++) {
				std::cout << "V";
			}
		}
		integer %= 5;
	}
}
	if ((integer % 5 >= 1) && (einer)) {							//berechnet 1er --> I
		if (integer == 4)
		{
			std::cout << "IV";
			einer = false;
		}
		else if(einer){
	piece = (integer / 1);
	for (int i = 1; i <= piece; i++) {
		std::cout << "I";
	}
	}
	integer %= 1;
	}
	return 0;
}