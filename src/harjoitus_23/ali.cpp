#include <iostream>
#include "maarittely.h"
using namespace std;
static int valikko(void) {//Valikkofunktio
	cout << "0 Lopeta" << endl << "1 Lisaa henkilo" << endl << "2 Nayta kaikki henkilot" << endl;
	int valinta;
	cin >> valinta;
	return valinta;
}
static void TulostaHenkilo(henkilo kuka) {//Henkil�ntulostusfunktio
	cout << kuka.etunimi << " jonka koulumatka on " << kuka.koulumatka << " ja hatun koko on " << kuka.hatunkoko << endl;
}
static void TulostaKaikkiHenkilot(henkilo tiedot[10], int lkm) {//Kaikkien henkil�iden tulostusfunktio
	if (lkm > 0) {//Jos taulukossa ei ole tietoja, tulostetaan vain varoitus. Muutoin tulostetaan kaikki tiedot
		for (int i = 0;i < lkm;i++) {
			TulostaHenkilo(tiedot[i]);//Tulostetaan yksitt�inen henkil�
		}
	}
	else cout << "Ei tietoja" << endl;;
}
static void LisaaHenkilo(henkilo tiedot, int *lkm) {//Henkil�n lis�ysfunktio
	henkilot[montako] = tiedot;//Lis�t��n taulukon per�lle uusi tietue
	*lkm = *lkm + 1;//Lis�t��n kokonaism��r�� yhdell�
}