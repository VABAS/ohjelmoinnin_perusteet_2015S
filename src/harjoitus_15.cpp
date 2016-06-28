#include <iostream>
using namespace std;
char etunimet[40],sukunimi[20],osoite[20];
int knumero,postinumero;
float koulumatka;
int main() {
	cout << "Anna (kaikki) etunimesi: ";//Pyydetään etunimi
	cin.get(etunimet,40);
	cout << "Anna kengannumero: ";//Pyydetään kengännumero
	cin >> knumero;
	cin.get();
	cout << "Anna sukunimi: ";//Pyydetään sukunimi
	cin.get(sukunimi,20);
	cout << "Anna koulumatka: ";//Pyydetään koulumatka
	cin >> koulumatka;
	cin.get();
	cout << "Anna osoitteesi: ";//Pyydetään osoite
	cin.get(osoite,20);
	cout << "Anna postinumero: ";//Pyydetään postinumero
	cin >> postinumero;
	//Tulostetaan lopputulokset
	cout << endl << sukunimi << " " << etunimet << endl << osoite << endl << postinumero << endl << knumero << " ja " << koulumatka << endl;
	return 0;
}