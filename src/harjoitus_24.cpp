/*
	Ohjelma käyttää tallennustiedostona db.txt nimistä tiedostoa joka sijaitsee ohjelman suoritushakemistossa
	Tiedoston formaatti on seuraava:
		etunimi|koulumatka|hatunkoko\netunimi|koulumatka|hatunkoko\netunimi|koulumatka|hatunkoko jne...
	-> Yksittäiset henkilöt erotetaan rivinvaihdoilla
	--> Henkilöiden tiedot erotetaan pystyviivalla ja ovat järjestyksessä etunimi koulumatka hatunkoko
	(Palautuskansio sisältää myös demo db.txt tiedoston jossa on muutama henkilötieto)
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct henkilo {//Henkilörekisteritietue
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
void TulostaHenkilo(henkilo kuka) {//Henkilöntulostusfunktio
	cout << kuka.etunimi << " jonka koulumatka on " << kuka.koulumatka << " ja hatun koko on " << kuka.hatunkoko << endl;
}
void TulostaKaikkiHenkilot(henkilo tiedot[10], int lkm) {//Kaikkien henkilöiden tulostusfunktio
	if (lkm > 0) {//Jos taulukossa ei ole tietoja, tulostetaan vain varoitus. Muutoin tulostetaan kaikki tiedot
		for (int i = 0;i < lkm;i++) {
			cout << "[" << (i + 1) << "]";//Tulostetaan järjesysnumero
			TulostaHenkilo(tiedot[i]);//Tulostetaan yksittäinen henkilö
		}
	}
	else cout << "Ei tietoja" << endl;
}
void LisaaHenkilo(henkilo tiedot, int *lkm) {//Henkilön lisäysfunktio
	henkilot[montako] = tiedot;//Lisätään taulukon perälle uusi tietue
	*lkm = *lkm + 1;//Lisätään kokonaismäärää yhdellä
}
void PoistaHenkilo(int jarjn, int *lkm) {
	int i = jarjn;//^^
	while (i < 10) {//Käydään taulukkoa läpi poistettavasta eteenpäin
		henkilot[i - 1] = henkilot[i];//Siirretään soluja taaksepäin
		i++;
	}
	*lkm = *lkm - 1;//Vähennetään määrää yhdellä

}
int main() {
	while (true) {
		int valinta = valikko();
		if (valinta == 0) break;//Poistutaan jos valinta on nolla
		else if (valinta == 1) {//Jos valinta on yksi
			if (montako >= 10)
				cout << "Ei voida lisata. Enimmaismaara(10) on tayttynyt." << endl;//Jos taulussa on jo kymmenen tietuetta annetaan virheilmoitus
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
		else if (valinta == 3)//Jos valinta on kolme tulostetaan kaikki henkilöt
			TulostaKaikkiHenkilot(henkilot, montako);
		else if (valinta == 4) {//Jos valinta on neljä
			int jarjn;
			cout << "Anna poistettavan henkilon jarjestysnumero: ";//Kysytään järjestysnumero
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
				int i = montako;//muuttuja i kertoo missä kohtaa henkilötietotaulua ollaan menossa
				while (getline(tiedosto, rivi)) {//Niin pitkään kun getlinella on jotain luettavaa
					if (i >= 10) {//Lopetetaan lukeminen jos maksimimäärä on saavutettu ja annetaan virheilmoitus sekä kerrotaan paljonko ehdittiin ottaa muistiin
						cout << "Tietojen maksimimaara saavutettu! Kirjoitettiin " << (i - montako) << " tietoa muistiin" << endl;
						break;
					}
					henkilo tmp_henkilo;//Tehdään väliaikainen henkilötietue
					char erottimet[] = "|";//Tietueen tietojen erottimena toimii pystyviiva
					int l = 0;//Muuttuja l kertoo missä kohdassa riviä ollaan menossa
					while (rivi[l] != erottimet[0]) {//Luetaan etunimeä kunnes kohdataan erotin
						tmp_henkilo.etunimi += rivi[l];
						l++;//Lisätään paikkaa yhdellä joka kierroksella
					}
					l++;//Hypätään erottimen yli
					string tmp_koulumatka;//Väliaikainen koulumatka-muuttuja
					while (rivi[l] != erottimet[0]) {//Luetaan koulumatkaa kunnes kohdataan erotin
						tmp_koulumatka += rivi[l];
						l++;//Lisätään paikkaa yhdellä joka kierroksella
					}
					tmp_henkilo.koulumatka = stof(tmp_koulumatka);//Muunnetaan koulumatka floatiksi ja tallennetaan väliaikais-tietueeseen
					l++;
					string tmp_hatunkoko;//Väliaikainen hatunkoko-muuttuja
					while (rivi[l] != 0) {//Luetaan hatunkokoa kunnes kohdataan erotin
						tmp_hatunkoko += rivi[l];
						l++;
					}
					tmp_henkilo.hatunkoko = stoi(tmp_hatunkoko);//Muunnetaan hatunkoko intiksi ja tallennetaan väliaikais-tietueeseen
					henkilot[i] = tmp_henkilo;//Siirretään väliaikaishenkilö henkilötietotaulukkoon
					i++;
				}
				montako = i;
			}
			else {
				cout << "Tiedostoa db.txt ei ole olemassa!" << endl;//Tulostetaan varoitus jos tiedostoa ei löydy
				tiedosto.close();//Ja suljetaan tiedosto
			}
		}
		else cout << "Anna toiminto 1-6" << endl;
	}
	return 0;
}