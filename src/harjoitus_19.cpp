#include <iostream>
using namespace std;
int nopeudet[5];
int nopeus;
int main() {
	while (true) {
		cout << "Anna nopeus: ";
		cin >> nopeus;//Pyydet��n uusi nopeus
		if (nopeus < 0) {//Lopetetaan jos nopeus on negatiivinen
			cout << " => loppu" << endl;
			break;
		}
		for (int i=3;i >= 0;i--) {//Siirret��n taulukon arvoja yhdell� eteenp�in
			nopeudet[i + 1] = nopeudet[i];
		}
		nopeudet[0]=nopeus;//Laitetaan ensimm�inen arvo kuten sy�tetty
		int yhteensa = 0;
		for (int i = 0;i < 5;i++) {//Lasketaan paljonko nopeudet on yhteenlaskettuna
			yhteensa += nopeudet[i];
		}
		cout << " => " << yhteensa / 5 << " km/h" << endl;//Tulostetaan keskiarvo
	}
	return 0;
}