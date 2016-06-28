#include <iostream>
using namespace std;
int l1, l2, valinta;//Alustetaan int muuttujat luku1 luku2 ja valinta
bool loop1 = true;//Alustetaan silmukkaa 1 k‰ynniss‰ pit‰v‰ bool muuttuja ja annetaan arvoksi true
bool loop2;//Alustetaan silmukkaa 2 k‰ynniss‰pit‰v‰ bool muuttuja
int valikko() {
	//Tulostetaan valikko
	cout << "VALIKKO" << endl << "0. Lopetus" << endl << "1. Summa" << endl << "2. Erotus" << endl << "3. Tulo" << endl << "4. Osamaara" << endl << "5 .Jakojaannos" << endl << "6. Syota uudet luvut laskemista varten";
	cin >> valinta;//Kysyt‰‰n mit‰ tehd‰‰n
	if (valinta == 0) {//Pys‰ytet‰‰n silmukat
		loop1 = false;
		loop2 = false;
	}
	else if (valinta == 1) cout << endl << (l1 + l2) << endl;	//Summa
	else if (valinta == 2) cout << endl << (l1 - l2) << endl;	//Erotus
	else if (valinta == 3) cout << endl << (l1*l2) << endl;		//Tulo
	else if (valinta == 4) cout << endl << (l1 / l2) << endl;	//Osam‰‰r‰
	else if (valinta == 5) cout << endl << (l1%l2) << endl;		//Jakoj‰‰nnˆs
	else if (valinta == 6) {
		loop2 = false;											//Pys‰ytet‰‰n silmukka2
	}
	return 0;//Funktion t‰ytyy palauttaa jotain joten t‰m‰ palauttaa arvon nolla
}
int main() {
	while (loop1) {
		cout << "Anna luku: ";			//Pyydet‰‰n luku1
		cin >> l1;						//Talletetaan se muuttujaan l1
		cout << "Anna toinen luku: ";	//Pyydet‰‰n luku2
		cin >> l2;						//Talletetaan se muuttujaan l2
		valikko();
		if (valinta == 0) loop1 = false;//Pys‰ytet‰‰n ohjelma jos k‰ytt‰j‰ niin haluaa
		else {
			loop2 = true;//Pistet‰‰n silmukka2 pyˆrim‰‰n
			while (loop2) {
				valikko();
			}
		}
	}
	return 0;
}