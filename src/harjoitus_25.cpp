#include <iostream>	//Perus io-operaatiot
#include <fstream>	//Tiedoston k�sittely
#include <string>	//String-kirjasto
using namespace std;
struct henkilo {//Henkil�rekisteritietue
	string etunimi;
	float koulumatka;
	int hatunkoko;
};
henkilo *henkilot = new henkilo[1];
int montako = 0;
int valikko(void) {//Valikkofunktio
	cout << "0 Lopeta" << endl << "1 Lisaa henkilo" << endl << "2 Nayta henkilo" << endl << "3 Nayta kaikki henkilot" << endl << "4 Poista henkilon tiedot" << endl << "Valitse toiminto: ";
	int valinta;
	cin >> valinta;
	return valinta;
}
void TulostaHenkilo(henkilo kuka) {//Henkil�ntulostusfunktio
	cout << kuka.etunimi << " jonka koulumatka on " << kuka.koulumatka << " ja hatun koko on " << kuka.hatunkoko << endl;
}
void TulostaKaikkiHenkilot(henkilo tiedot[10], int lkm) {//Kaikkien henkil�iden tulostusfunktio
	if (lkm > 0) {//Jos taulukossa ei ole tietoja, tulostetaan vain varoitus. Muutoin tulostetaan kaikki tiedot
		for (int i = 0;i < lkm;i++) {
			cout << "[" << (i + 1) << "]";//Tulostetaan j�rjesysnumero
			TulostaHenkilo(tiedot[i]);//Tulostetaan yksitt�inen henkil�
		}
	}
	else cout << "Ei tietoja" << endl;
}
void LisaaHenkilo(henkilo tiedot, int *lkm) {//Henkil�n lis�ysfunktio
	henkilot[*lkm] = tiedot;//Lis�t��n taulukon per�lle uusi tietue
	*lkm = *lkm + 1;//Lis�t��n kokonaism��r�� yhdell�
}
void PoistaHenkilo(int jarjn, int *lkm) {
	int i = jarjn;//^^
	while (i < 10) {//K�yd��n taulukkoa l�pi poistettavasta eteenp�in
		henkilot[i - 1] = henkilot[i];//Siirret��n soluja taaksep�in
		i++;
	}
	*lkm = *lkm - 1;//V�hennet��n m��r�� yhdell�
}
int main() {
	cout << "Kuinka suuren tietueen haluat luoda? (max 10): ";
	int koko;
	cin >> koko;
	delete[] henkilot;
	henkilot = new henkilo[koko];
	while (true) {
		int valinta = valikko();
		if (valinta == 0) break;//Poistutaan jos valinta on nolla
		else if (valinta == 1) {//Jos valinta on yksi
			if (montako >= koko)
				cout << "Ei voida lisata. Enimmaismaara(" << koko << ") on tayttynyt." << endl;//Jos taulussa on jo kymmenen tietuetta annetaan virheilmoitus
			else {
				henkilo uusi;//Luodaan uusi henkil� ja kysell��n sen tiedot
				cout << "Anna etunimi: ";
				cin >> uusi.etunimi;
				cout << "Anna koulumatka: ";
				cin >> uusi.koulumatka;
				cout << "Anna hatun koko: ";
				cin >> uusi.hatunkoko;
				LisaaHenkilo(uusi, &montako);//Lis�t��n uusi henkil� tauluun
				cout << "Henkilo lisatty" << endl;;
			}
		}
		else if (valinta == 2) {//Jos valinta on kaksi
			int jarjn;
			cout << "Anna tulostettavan henkilon jarjestysnumero: ";
			cin >> jarjn;
			if (jarjn >= 1 && jarjn <= montako) {
				henkilo tulostettava = henkilot[jarjn - 1];
				TulostaHenkilo(tulostettava);
			}
			else cout << "Virheellinen jarjestysnumero" << endl;
		}
		else if (valinta == 3)//Jos valinta on kolme tulostetaan kaikki henkil�t
			TulostaKaikkiHenkilot(henkilot, montako);
		else if (valinta == 4) {//Jos valinta on nelj�
			int jarjn;
			cout << "Anna poistettavan henkilon jarjestysnumero: ";//Kysyt��n j�rjestysnumero
			cin >> jarjn;//<-----------------------------------------^
			if (jarjn >= 1 && jarjn <= montako) PoistaHenkilo(jarjn, &montako);
			else cout << "Virheellinen jarjestysnumero" << endl;
		}
		else cout << "Anna toiminto 1-4" << endl;
	}
	return 0;
}