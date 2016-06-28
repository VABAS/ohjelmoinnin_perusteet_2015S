#include <iostream>
using namespace std;
int nopeudet[5];
int nopeus;
int main() {
	while (true) {
		cout << "Anna nopeus: ";
		cin >> nopeus;//Pyydetään uusi nopeus
		if (nopeus < 0) {//Lopetetaan jos nopeus on negatiivinen
			cout << " => loppu" << endl;
			break;
		}
		for (int i=3;i >= 0;i--) {//Siirretään taulukon arvoja yhdellä eteenpäin
			nopeudet[i + 1] = nopeudet[i];
		}
		nopeudet[0]=nopeus;//Laitetaan ensimmäinen arvo kuten syötetty
		int yhteensa = 0;
		for (int i = 0;i < 5;i++) {//Lasketaan paljonko nopeudet on yhteenlaskettuna
			yhteensa += nopeudet[i];
		}
		cout << " => " << yhteensa / 5 << " km/h" << endl;//Tulostetaan keskiarvo
	}
	return 0;
}