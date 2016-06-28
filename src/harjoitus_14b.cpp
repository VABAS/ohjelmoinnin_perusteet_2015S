#include <iostream>
using namespace std;
char mjono1[18], mjono2[18];//Merkkijono, 17 merkkiä(18-1)
char tyhja[1];
int main() {
	cout << "Anna enintaan 17 merkkinen merkkijono: ";
	cin >> mjono1;
	int i = 17;//Laskurin alkuarvo on 17
	int i2 = 0;
	while (i >= 0) {//Pyöritetään silmukkaa niin pitkään kuin laskuri i on suurempi tai yhtäsuuri kuin 0
		if(!(mjono1[i]==tyhja[0])){//Tarkastetaan ettei merkki ole olematon
			mjono2[i2] = mjono1[i];//Työnnetään laskurin arvoa vastaava arvo merkkitaulukosta mjono merkkijonoon mjono2
			i2++;
		}
		i--;//Vähennetään laskurin arvoa yhdellä
	}
	cout << mjono2 << endl;//käännetyn merkkijonon tulostus ja rivinvaihto selkeyden takaamiseksi
	return 0;
}