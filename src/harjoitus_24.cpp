/*
	Ohjelma k�ytt�� tallennustiedostona db.txt nimist� tiedostoa joka sijaitsee ohjelman suoritushakemistossa
	Tiedoston formaatti on seuraava:
		etunimi|koulumatka|hatunkoko\netunimi|koulumatka|hatunkoko\netunimi|koulumatka|hatunkoko jne...
	-> Yksitt�iset henkil�t erotetaan rivinvaihdoilla
	--> Henkil�iden tiedot erotetaan pystyviivalla ja ovat j�rjestyksess� etunimi koulumatka hatunkoko
	(Palautuskansio sis�lt�� my�s demo db.txt tiedoston jossa on muutama henkil�tieto)
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct henkilo {//Henkil�rekisteritietue
	string etunimi;
	float koulumatka;
	int hatunkoko;
}henkilot[10];
int montako = 0;
int valikko(void) {//Valikkofunktio
	cout << "0 Lopeta" << endl << "1 Lisaa henkilo" << endl << "2 Nayta henkilo" << endl << "3 Nayta kaikki henkilot" << endl << "4 Poista henkilon tiedot" << endl << "5 Tallenna tiedot tiedostoon" << endl << "6 Lue tiedot tiedostosta" << endl << "Valitse toiminto: ";
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
	henkilot[montako] = tiedot;//Lis�t��n taulukon per�lle uusi tietue
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
	while (true) {
		int valinta = valikko();
		if (valinta == 0) break;//Poistutaan jos valinta on nolla
		else if (valinta == 1) {//Jos valinta on yksi
			if (montako >= 10)
				cout << "Ei voida lisata. Enimmaismaara(10) on tayttynyt." << endl;//Jos taulussa on jo kymmenen tietuetta annetaan virheilmoitus
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
		else if (valinta == 5) {//Jos valinta on viisi
			if (montako > 0) {		//Jos taulukossa ei ole tietoja, tulostetaan vain varoitus.
				ofstream tiedosto;	//muutoin avataan tiedosto
				tiedosto.open("db.txt");//Avataan tiedosto
				for (int i = 0;i < montako;i++) {//Kirjoitetaan tiedot tiedostoon formaatin mukaisesti
					tiedosto << henkilot[i].etunimi << "|" << henkilot[i].koulumatka << "|" << henkilot[i].hatunkoko << "\n";
				}
				tiedosto.close();//Suljetaan tiedosto
			}
			else cout << "Ei tietoja" << endl;
		}
		else if (valinta == 6) {//Jos valinta on kuusi
			string rivi;
			ifstream tiedosto;
			tiedosto.open("db.txt");//Avataan tiedosto
			if (tiedosto.is_open()) {//Jos tiedosto on auki
				int i = montako;//muuttuja i kertoo miss� kohtaa henkil�tietotaulua ollaan menossa
				while (getline(tiedosto, rivi)) {//Niin pitk��n kun getlinella on jotain luettavaa
					if (i >= 10) {//Lopetetaan lukeminen jos maksimim��r� on saavutettu ja annetaan virheilmoitus sek� kerrotaan paljonko ehdittiin ottaa muistiin
						cout << "Tietojen maksimimaara saavutettu! Kirjoitettiin " << (i - montako) << " tietoa muistiin" << endl;
						break;
					}
					henkilo tmp_henkilo;//Tehd��n v�liaikainen henkil�tietue
					char erottimet[] = "|";//Tietueen tietojen erottimena toimii pystyviiva
					int l = 0;//Muuttuja l kertoo miss� kohdassa rivi� ollaan menossa
					while (rivi[l] != erottimet[0]) {//Luetaan etunime� kunnes kohdataan erotin
						tmp_henkilo.etunimi += rivi[l];
						l++;//Lis�t��n paikkaa yhdell� joka kierroksella
					}
					l++;//Hyp�t��n erottimen yli
					string tmp_koulumatka;//V�liaikainen koulumatka-muuttuja
					while (rivi[l] != erottimet[0]) {//Luetaan koulumatkaa kunnes kohdataan erotin
						tmp_koulumatka += rivi[l];
						l++;//Lis�t��n paikkaa yhdell� joka kierroksella
					}
					tmp_henkilo.koulumatka = stof(tmp_koulumatka);//Muunnetaan koulumatka floatiksi ja tallennetaan v�liaikais-tietueeseen
					l++;
					string tmp_hatunkoko;//V�liaikainen hatunkoko-muuttuja
					while (rivi[l] != 0) {//Luetaan hatunkokoa kunnes kohdataan erotin
						tmp_hatunkoko += rivi[l];
						l++;
					}
					tmp_henkilo.hatunkoko = stoi(tmp_hatunkoko);//Muunnetaan hatunkoko intiksi ja tallennetaan v�liaikais-tietueeseen
					henkilot[i] = tmp_henkilo;//Siirret��n v�liaikaishenkil� henkil�tietotaulukkoon
					i++;
				}
				montako = i;
			}
			else {
				cout << "Tiedostoa db.txt ei ole olemassa!" << endl;//Tulostetaan varoitus jos tiedostoa ei l�ydy
				tiedosto.close();//Ja suljetaan tiedosto
			}
		}
		else cout << "Anna toiminto 1-6" << endl;
	}
	return 0;
}