#include <iostream>
using namespace std;
int main() {
	int luku;
	cout << "Anna luku valilta 1-9: ";//Pyydet��n luku
	cin >> luku;
	if (luku>0 && luku<10) {//Tarkastetaan ett� luku on halutulla v�lill�
		int i = 0;//Laskurimuuttuja i
		while (i < luku+1) {//Py�ritet��n silmukkaa niin pitk��n kun laskuri i on pienempi kuin annettu luku ja viimeisen kerran kun se on yht�suuri
			cout << endl;
			int i2 = 0;//Laskurimuuttuja i2
			while (i2 < i) {//Tulostetaan muuttujan i arvo sen arvon m��r� kertoja
				cout << i;
				i2++;
			}
			i++;//Lis�t��n laskurin i arvoa yhdell�
		}
		cout << endl;
	}
	else cout << "Luku ei kelpaa!";//Jos luku ei ole halutulla v�lill� lopetetaab ja tulostetaan virheilmoitus
	return 0;
}