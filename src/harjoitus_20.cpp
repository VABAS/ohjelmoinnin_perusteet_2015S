#include <iostream>
using namespace std;
int nopeus;
int nopeudet[5];
int* osotin = &nopeudet[0];
int main() {
	while (true) {
		cout << "Anna nopeus: ";
		cin >> nopeus;//Pyydet��n uusi nopeus
		if (nopeus < 0) {//Lopetetaan jos nopeus on negatiivinen
			cout << " => loppu" << endl;
			break;
		}
		for (int i = 3;i >= 0;i--) {//Siirret��n taulukon arvoja yhdell� eteenp�in
			osotin[i + 1] = osotin[i];
		}
		osotin[0] = nopeus;//Laitetaan ensimm�inen arvo kuten sy�tetty
		int yhteensa = 0;
		for (int i = 0;i < 5;i++) {//Lasketaan paljonko nopeudet on yhteenlaskettuna
			yhteensa += osotin[i];
		}
		cout << " => " << yhteensa / 5 << " km/h" << endl;//Tulostetaan keskiarvo
	}
	return 0;
}