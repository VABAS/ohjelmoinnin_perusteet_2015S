#include <iostream>
using namespace std;
int nopeus;
int nopeudet[5];
int* osotin = &nopeudet[0];
int main() {
	while (true) {
		cout << "Anna nopeus: ";
		cin >> nopeus;//Pyydetään uusi nopeus
		if (nopeus < 0) {//Lopetetaan jos nopeus on negatiivinen
			cout << " => loppu" << endl;
			break;
		}
		for (int i = 3;i >= 0;i--) {//Siirretään taulukon arvoja yhdellä eteenpäin
			osotin[i + 1] = osotin[i];
		}
		osotin[0] = nopeus;//Laitetaan ensimmäinen arvo kuten syötetty
		int yhteensa = 0;
		for (int i = 0;i < 5;i++) {//Lasketaan paljonko nopeudet on yhteenlaskettuna
			yhteensa += osotin[i];
		}
		cout << " => " << yhteensa / 5 << " km/h" << endl;//Tulostetaan keskiarvo
	}
	return 0;
}