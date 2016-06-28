#include "ali.cpp"
int main() {
	while (true) {
		int valinta = valikko();
		if (valinta == 0) break;
		else if (valinta == 1) {
			if (montako >= 10) cout << "Ei voida lisata. Enimmaismaara(10) on tayttynyt." << endl;//Jos taulussa on jo kymmenen tietuetta annetaan virheilmoitus
			else {
				henkilo uusi;//Luodaan uusi henkilö ja kysellään sen tiedot
				cout << "Anna etunimi: ";
				cin >> uusi.etunimi;
				cout << "Anna koulumatka: ";
				cin >> uusi.koulumatka;
				cout << "Anna hatun koko: ";
				cin >> uusi.hatunkoko;
				LisaaHenkilo(uusi, &montako);//Lisätään uusi henkilö tauluun
				cout << "Henkilo lisatty" << endl;;
			}
		}
		else if (valinta == 2) TulostaKaikkiHenkilot(henkilot, montako);
	}
	return 0;
}