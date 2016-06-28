#include <iostream>
using namespace std;
struct koira {
	char nimi[20];
	int ika;
}koirat[5];
int main() {
	for (int count = 0;count < 5;count++) {//Kysyt‰‰n koirien tietoja kunnes niit‰ on kysytty viisi kertaa
		cout << "Anna koiran #" << count+1 << " nimi: ";
		cin.get(koirat[count].nimi,20);
		cout << "Anna koiran #" << count+1 << " ika: ";
		cin >> koirat[count].ika;
		cin.get();
	}
	for (int count = 0;count < 5;count++) {//K‰yd‰‰n taulukko l‰pi
		for (int count2 = 0;count2 < 5;count2++) {
			if (koirat[count].ika>koirat[count2].ika) {//Vaihdetaan koirien paikkaa jos endimm‰inen on pienempi kuin j‰lkimm‰inen
				koira temp;//Tehd‰‰n v‰liaikais "koira"
				temp.ika = koirat[count].ika;
				strcpy_s(temp.nimi, koirat[count].nimi);
				koirat[count].ika = koirat[count2].ika;
				strcpy_s(koirat[count].nimi, koirat[count2].nimi);
				koirat[count2].ika = temp.ika;
				strcpy_s(koirat[count2].nimi, temp.nimi);
			}
		}
	}
	for (int count = 0;count < 5;count++) cout << koirat[count].nimi << " on " << koirat[count].ika << " vuotta vanha" << endl;//Tulostetaan koirien tiedot
	return 0;
}