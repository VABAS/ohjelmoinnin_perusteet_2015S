/*
	Minulla oli alunperinkin t‰ss‰ ohjelmassa k‰ytetty aliohjelmaa "valikko".
	Lis‰sin kuitenkin t‰ss‰ teht‰v‰ss‰ halutut aliohjelmat viel‰ nyt.
*/
#include <iostream>
using namespace std;
int l1, l2, valinta;//Alustetaan int muuttujat luku1 luku2 ja valinta
bool loop1 = true;//Alustetaan silmukkaa 1 k‰ynniss‰ pit‰v‰ bool muuttuja ja annetaan arvoksi true
bool loop2;//Alustetaan silmukkaa 2 k‰ynniss‰pit‰v‰ bool muuttuja
double summa(float luku1, int luku2) {//Summafuntkio
	return luku1 + luku2;
}
int KysyValinta(void) {
	return valinta;
}
int valikko() {
	//Tulostetaan valikko
	cout << "VALIKKO" << endl << "0. Lopetus" << endl << "1. Summa" << endl << "2. Erotus" << endl << "3. Tulo" << endl << "4. Osamaara" << endl << "5 .Jakojaannos" << endl << "6. Syota uudet luvut laskemista varten";
	cin >> valinta;//Kysyt‰‰n mit‰ tehd‰‰n
	if (KysyValinta() == 0) {//Pys‰ytet‰‰n silmukat
		loop1 = false;
		loop2 = false;
	}
	else if (KysyValinta() == 1) cout << endl << summa(l1, l2) << endl;	//Summa
	else if (KysyValinta() == 2) cout << endl << (l1 - l2) << endl;		//Erotus
	else if (KysyValinta() == 3) cout << endl << (l1*l2) << endl;			//Tulo
	else if (KysyValinta() == 4) cout << endl << (l1 / l2) << endl;		//Osam‰‰r‰
	else if (KysyValinta() == 5) cout << endl << (l1%l2) << endl;			//Jakoj‰‰nnˆs
	else if (KysyValinta() == 6) {										//Jos valinta on kuusi
		loop2 = false;												//Pys‰ytet‰‰n silmukka2
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
		if (KysyValinta() == 0) loop1 = false;//Pys‰ytet‰‰n ohjelma jos k‰ytt‰j‰ niin haluaa
		else {
			loop2 = true;//Pistet‰‰n silmukka2 pyˆrim‰‰n
			while (loop2) {
				valikko();
			}
		}
	}
	return 0;
}