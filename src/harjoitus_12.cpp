#include <iostream>
using namespace std;
int main() {
	int luku;
	cout << "Anna luku valilta 1-9: ";//Pyydetään luku
	cin >> luku;
	if (luku>0 && luku<10) {//Tarkastetaan että luku on halutulla välillä
		int i = 0;//Laskurimuuttuja i
		while (i < luku+1) {//Pyöritetään silmukkaa niin pitkään kun laskuri i on pienempi kuin annettu luku ja viimeisen kerran kun se on yhtäsuuri
			cout << endl;
			int i2 = 0;//Laskurimuuttuja i2
			while (i2 < i) {//Tulostetaan muuttujan i arvo sen arvon määrä kertoja
				cout << i;
				i2++;
			}
			i++;//Lisätään laskurin i arvoa yhdellä
		}
		cout << endl;
	}
	else cout << "Luku ei kelpaa!";//Jos luku ei ole halutulla välillä lopetetaab ja tulostetaan virheilmoitus
	return 0;
}