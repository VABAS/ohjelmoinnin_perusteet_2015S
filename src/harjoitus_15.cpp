#include <iostream>
using namespace std;
char etunimet[40],sukunimi[20],osoite[20];
int knumero,postinumero;
float koulumatka;
int main() {
	cout << "Anna (kaikki) etunimesi: ";//Pyydet��n etunimi
	cin.get(etunimet,40);
	cout << "Anna kengannumero: ";//Pyydet��n keng�nnumero
	cin >> knumero;
	cin.get();
	cout << "Anna sukunimi: ";//Pyydet��n sukunimi
	cin.get(sukunimi,20);
	cout << "Anna koulumatka: ";//Pyydet��n koulumatka
	cin >> koulumatka;
	cin.get();
	cout << "Anna osoitteesi: ";//Pyydet��n osoite
	cin.get(osoite,20);
	cout << "Anna postinumero: ";//Pyydet��n postinumero
	cin >> postinumero;
	//Tulostetaan lopputulokset
	cout << endl << sukunimi << " " << etunimet << endl << osoite << endl << postinumero << endl << knumero << " ja " << koulumatka << endl;
	return 0;
}