#include <iostream>
using namespace std;
char mjono[17];//Merkkijono, 17 merkki�
int main() {
	cout << "Anna enintaan 17 merkkinen merkkijono: ";
	cin >> mjono;
	int i = 16;//Laskurin alkuarvo on 16
	while (i>=0) {//Py�ritet��n silmukkaa niin pitk��n kuin laskuri i on suurempi tai yht�suuri kuin 0
		cout << mjono[i];//Tulostetaan laskurin arvoa vastaava arvo merkkitaulukosta mjono
		i--;//V�hennet��n laskurin arvoa yhdell�
	}
	cout << endl;//Rivinvaihto selkeyden takaamiseksi
	return 0;
}