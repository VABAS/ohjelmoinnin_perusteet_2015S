#include <iostream>
using namespace std;
char enimi[15], snimi[15], kokonimi[31];//Alustetaam char muuttujat enimi ja snimi joiden maksimi pituus on 15 ja kokonimi joka on 15+15+1=31
int main() {
	cout << "Anna etunimesi: ";//Pyyde‰‰n etunimi
	cin >> enimi;
	cout << "Anna sukunimesi: ";//Pyydet‰‰n sukunimi
	cin >> snimi;
	strcat_s(kokonimi, enimi);//Lis‰t‰‰n kokonimi muuttujaan muuttujan enimi arvo
	strcat_s(kokonimi, " ");//Lis‰t‰‰n kokonimi muuttujaan v‰lilyˆnti
	strcat_s(kokonimi, snimi);//Lis‰t‰‰n kokonimi muuttujaan muuttujan snimi arvo
	cout << "Nimesi oli: " << kokonimi << endl;//Tulostetaan kokonimi
	return 0;
}