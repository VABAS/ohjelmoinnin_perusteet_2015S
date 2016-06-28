#include <iostream>
using namespace std;
struct ht {//Tietue m‰‰rittely. M‰‰ritell‰‰n mit‰ ja mink‰ tyyppist‰ tietoa se sis‰lt‰‰
	char etunimi[21],sukunimi[21],osoite[21],postinumero[6];
	float koulumatka;
	int knumero;
}henkilotiedot;//Luodaan uusi tietue joka on edell‰ m‰‰ritellyn tyyppinen
int main() {
	cout << "Anna etunimesi: ";//Pyydet‰‰n etunimi
	cin.get(henkilotiedot.etunimi,20);
	cin.get();
	cout << "Anna sukunimesi: ";//Pyydet‰‰n sukunimi
	cin.get(henkilotiedot.sukunimi, 20);
	cin.get();
	cout << "Anna koulumatkasi: ";//Pyydet‰‰n koulumatka
	cin >> henkilotiedot.koulumatka;
	cin.get();
	cout << "Anna osoitteesi: ";//Pyydet‰‰n osoite
	cin.get(henkilotiedot.osoite, 20);
	cin.get();
	cout << "Anna postinumerosi: ";//Pyydet‰‰n postinumero
	cin.get(henkilotiedot.postinumero, 5);
	cin.get();
	cout << "Anna kengannumero: ";//Pyydet‰‰n keng‰nnumero
	cin >> henkilotiedot.knumero;
	//Tulostetaan lopputulokset
	cout << endl << "Nimi: " << henkilotiedot.etunimi << " " << henkilotiedot.sukunimi << endl << "Osoite: " << henkilotiedot.osoite << ", " << henkilotiedot.postinumero << endl << "Koulumatka: " << henkilotiedot.koulumatka << endl << "Kengannumero: " << henkilotiedot.knumero << endl;
	return 0;
}