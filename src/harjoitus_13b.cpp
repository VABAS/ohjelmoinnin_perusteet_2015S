#include <iostream>
#include <string>//Sisällytetään string kirjasto
using namespace std;
string enimi, snimi, kokonimi;//Alustetaan string tyyppiset muuttujat
int main() {
	cout << "Anna etunimi: ";//Pyydetään etunimi
	cin >> enimi;
	cout << "Anna sukunimi: ";//Pyydetään sukunimi
	cin >> snimi;
	kokonimi = enimi + " " + snimi;//Yhdistetään etunimi ja sukunimi, ja lisätään väliin välilyönti
	cout << "Nimesi oli: " << kokonimi << endl;//Tulostetaan koko nimi
	return 0;
}