#include <iostream>
#include <string>//Sis�llytet��n string kirjasto
using namespace std;
string enimi, snimi, kokonimi;//Alustetaan string tyyppiset muuttujat
int main() {
	cout << "Anna etunimi: ";//Pyydet��n etunimi
	cin >> enimi;
	cout << "Anna sukunimi: ";//Pyydet��n sukunimi
	cin >> snimi;
	kokonimi = enimi + " " + snimi;//Yhdistet��n etunimi ja sukunimi, ja lis�t��n v�liin v�lily�nti
	cout << "Nimesi oli: " << kokonimi << endl;//Tulostetaan koko nimi
	return 0;
}