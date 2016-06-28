#include <iostream>
using namespace std;
char mjono[17];//Merkkijono, 17 merkkiä
int main() {
	cout << "Anna enintaan 17 merkkinen merkkijono: ";
	cin >> mjono;
	int i = 16;//Laskurin alkuarvo on 16
	while (i>=0) {//Pyöritetään silmukkaa niin pitkään kuin laskuri i on suurempi tai yhtäsuuri kuin 0
		cout << mjono[i];//Tulostetaan laskurin arvoa vastaava arvo merkkitaulukosta mjono
		i--;//Vähennetään laskurin arvoa yhdellä
	}
	cout << endl;//Rivinvaihto selkeyden takaamiseksi
	return 0;
}