#include <iostream>
using namespace std;
struct henkilo {//Henkilörekisteritietue
	char etunimi[20];
	float koulumatka;
	int hatunkoko;
}henkilot[10];
int montako = 0;
int valikko(void) {//Valikkofunktio
	cout << "0 Lopeta" << endl << "1 Lisaa henkilo" << endl << "2 Nayta kaikki henkilot" << endl;
	int valinta;
	cin >> valinta;
	return valinta;
}
void TulostaHenkilo(henkilo kuka) {//Henkilöntulostusfunktio
	cout << kuka.etunimi << " jonka koulumatka on " << kuka.koulumatka << " ja hatun koko on " << kuka.hatunkoko << endl;
}
void TulostaKaikkiHenkilot(henkilo tiedot[10], int lkm) {//Kaikkien henkilöiden tulostusfunktio
	if (lkm > 0) {//Jos taulukossa ei ole tietoja, tulostetaan vain varoitus. Muutoin tulostetaan kaikki tiedot
		for (int i = 0;i < lkm;i++) {
			TulostaHenkilo(tiedot[i]);//Tulostetaan yksittäinen henkilö
		}
	}
	else cout << "Ei tietoja" << endl;;
}
void LisaaHenkilo(henkilo tiedot, int *lkm) {//Henkilön lisäysfunktio
	henkilot[montako] = tiedot;//Lisätään taulukon perälle uusi tietue
	*lkm=*lkm+1;//Lisätään kokonaismäärää yhdellä
}
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