#include <iostream>
using namespace std;
char mjono1[18], mjono2[18];//Merkkijono, 17 merkki�(18-1)
char tyhja[1];
int main() {
	cout << "Anna enintaan 17 merkkinen merkkijono: ";
	cin >> mjono1;
	int i = 17;//Laskurin alkuarvo on 17
	int i2 = 0;
	while (i >= 0) {//Py�ritet��n silmukkaa niin pitk��n kuin laskuri i on suurempi tai yht�suuri kuin 0
		if(!(mjono1[i]==tyhja[0])){//Tarkastetaan ettei merkki ole olematon
			mjono2[i2] = mjono1[i];//Ty�nnet��n laskurin arvoa vastaava arvo merkkitaulukosta mjono merkkijonoon mjono2
			i2++;
		}
		i--;//V�hennet��n laskurin arvoa yhdell�
	}
	cout << mjono2 << endl;//k��nnetyn merkkijonon tulostus ja rivinvaihto selkeyden takaamiseksi
	return 0;
}