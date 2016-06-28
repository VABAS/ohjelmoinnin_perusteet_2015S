#include <iostream>
using namespace std;
int main() {
	float pos, neg;//float tyyppiset muuttujat joihin tallennetaan lukujen m‰‰r‰
	int luku;
	pos = 0;
	neg = 0;
	while (true) {//Kysyt‰‰n lukuja kunnes k‰ytt‰j‰ syˆtt‰‰ nollan
		cout << "Anna luku: ";
		cin >> luku;
		if (luku > 0) pos++;//Jos positiivinen lis‰‰ muuttujan pos arvoa yhdell‰
		else if (luku < 0) neg++;//Jos negatiivinen lis‰‰ muuttujan neg arvoa yhdell‰
		else break;//Muutoin(luku==0) poistu silmukasta
	}
	float yhteensa = neg + pos;//Lasketaan kokonaism‰‰r‰
	float negpr = neg / yhteensa * 100;//Negatiiviset prosenttina
	float pospr = pos / yhteensa * 100;//Positiiviset prosenttina

	//Tulostetaan yhteenveto
	cout << endl << "Syotit kokonaislukuja seuraavasti:" << endl;
	cout << "----------------------------------" << endl;
	cout << "Negatiiviset: " << neg << " kpl " << negpr << "%" << endl;
	cout << "Positiiviset: " << pos << " kpl " << pospr << "%" << endl;
	cout << "Yhteensa: " << yhteensa << " kpl " << ((yhteensa / yhteensa) * 100) << "%" << endl;
	return 0;//Main palauttaa nollan kertoakseen j‰rjestelm‰lle lopettaneensa ilman virheit‰
}