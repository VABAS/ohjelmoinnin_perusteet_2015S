#include <iostream>
using namespace std;
struct ht {//Tietue m‰‰rittely. M‰‰ritell‰‰n mit‰ ja mink‰ tyyppist‰ tietoa se voi sis‰lt‰‰
	char etunimi[21], sukunimi[21], osoite[21], postinumero[6];
	float koulumatka;
	int knumero;
};
int main() {
	//Luodaan uusia tietueita jotka ovat edell‰ m‰‰ritellyn tyyppisi‰
	ht mina;
	ht muu = { "Mikko","Mallikas","Nollakatu 0","00000",70,39 };
	ht muu2 = { "Maukka","Mikkola","Erkinpolku 77","12000",12.23,45 };
	cout << "Anna etunimesi: ";//Pyydet‰‰n etunimi
	cin.get(mina.etunimi, 20);
	cin.get();
	cout << "Anna sukunimesi: ";//Pyydet‰‰n sukunimi
	cin.get(mina.sukunimi, 20);
	cin.get();
	cout << "Anna koulumatkasi: ";//Pyydet‰‰n koulumatka
	cin >> mina.koulumatka;
	cin.get();
	cout << "Anna osoitteesi: ";//Pyydet‰‰n osoite
	cin.get(mina.osoite, 20);
	cin.get();
	cout << "Anna postinumerosi: ";//Pyydet‰‰n postinumero
	cin.get(mina.postinumero, 6);
	cin.get();
	cout << "Anna kengannumero: ";//Pyydet‰‰n keng‰nnumero
	cin >> mina.knumero;
	//Tulostetaan lopputulokset
	if (mina.koulumatka > muu.koulumatka && mina.koulumatka > muu2.koulumatka) {//Jos oma koulumatka on suurin
		cout << endl << "Nimi: " << mina.etunimi << " " << mina.sukunimi << endl << "Osoite: " << mina.osoite << ", " << mina.postinumero << endl << "Koulumatka: " << mina.koulumatka << endl << "Kengannumero: " << mina.knumero << endl;
		if (muu.koulumatka > muu2.koulumatka) {//Jos muu koulumatka on suurempi kuin muu2 koulumatka
			cout << endl << "Nimi: " << muu.etunimi << " " << muu.sukunimi << endl << "Osoite: " << muu.osoite << ", " << muu.postinumero << endl << "Koulumatka: " << muu.koulumatka << endl << "Kengannumero: " << muu.knumero << endl;
			cout << endl << "Nimi: " << muu2.etunimi << " " << muu2.sukunimi << endl << "Osoite: " << muu2.osoite << ", " << muu2.postinumero << endl << "Koulumatka: " << muu2.koulumatka << endl << "Kengannumero: " << muu2.knumero << endl;
		}
		else {//Jos muu2 koulumatka on suurempi kuin muu koulumatka
			cout << endl << "Nimi: " << muu2.etunimi << " " << muu2.sukunimi << endl << "Osoite: " << muu2.osoite << ", " << muu2.postinumero << endl << "Koulumatka: " << muu2.koulumatka << endl << "Kengannumero: " << muu2.knumero << endl;
			cout << endl << "Nimi: " << muu.etunimi << " " << muu.sukunimi << endl << "Osoite: " << muu.osoite << ", " << muu.postinumero << endl << "Koulumatka: " << muu.koulumatka << endl << "Kengannumero: " << muu.knumero << endl;
		}
	}
	else if (mina.koulumatka > muu.koulumatka) {//Jos oma koulumatka on suurempi kuin muu koulumatka ja pienempi kuin muu2 koulumatka
		cout << endl << "Nimi: " << muu2.etunimi << " " << muu2.sukunimi << endl << "Osoite: " << muu2.osoite << ", " << muu2.postinumero << endl << "Koulumatka: " << muu2.koulumatka << endl << "Kengannumero: " << muu2.knumero << endl;
		cout << endl << "Nimi: " << mina.etunimi << " " << mina.sukunimi << endl << "Osoite: " << mina.osoite << ", " << mina.postinumero << endl << "Koulumatka: " << mina.koulumatka << endl << "Kengannumero: " << mina.knumero << endl;
		cout << endl << "Nimi: " << muu.etunimi << " " << muu.sukunimi << endl << "Osoite: " << muu.osoite << ", " << muu.postinumero << endl << "Koulumatka: " << muu.koulumatka << endl << "Kengannumero: " << muu.knumero << endl;
	}
	else if (mina.koulumatka > muu2.koulumatka) {//Jos oma koulumatka on suurempi kuin muu2 koulumatka ja pienempi kuin muu koulumatka
		cout << endl << "Nimi: " << muu.etunimi << " " << muu.sukunimi << endl << "Osoite: " << muu.osoite << ", " << muu.postinumero << endl << "Koulumatka: " << muu.koulumatka << endl << "Kengannumero: " << muu.knumero << endl;
		cout << endl << "Nimi: " << mina.etunimi << " " << mina.sukunimi << endl << "Osoite: " << mina.osoite << ", " << mina.postinumero << endl << "Koulumatka: " << mina.koulumatka << endl << "Kengannumero: " << mina.knumero << endl;
		cout << endl << "Nimi: " << muu2.etunimi << " " << muu2.sukunimi << endl << "Osoite: " << muu2.osoite << ", " << muu2.postinumero << endl << "Koulumatka: " << muu2.koulumatka << endl << "Kengannumero: " << muu2.knumero << endl;
	}
	else {//Jos oma koulumatka on pienin
		if (muu.koulumatka > muu2.koulumatka) {//Jos muu koulumatka on suurin
			cout << endl << "Nimi: " << muu.etunimi << " " << muu.sukunimi << endl << "Osoite: " << muu.osoite << ", " << muu.postinumero << endl << "Koulumatka: " << muu.koulumatka << endl << "Kengannumero: " << muu.knumero << endl;
			cout << endl << "Nimi: " << muu2.etunimi << " " << muu2.sukunimi << endl << "Osoite: " << muu2.osoite << ", " << muu2.postinumero << endl << "Koulumatka: " << muu2.koulumatka << endl << "Kengannumero: " << muu2.knumero << endl;
			cout << endl << "Nimi: " << mina.etunimi << " " << mina.sukunimi << endl << "Osoite: " << mina.osoite << ", " << mina.postinumero << endl << "Koulumatka: " << mina.koulumatka << endl << "Kengannumero: " << mina.knumero << endl;
		}
		else {//Jos muu2 koulumatka on suurin
			cout << endl << "Nimi: " << muu2.etunimi << " " << muu2.sukunimi << endl << "Osoite: " << muu2.osoite << ", " << muu2.postinumero << endl << "Koulumatka: " << muu2.koulumatka << endl << "Kengannumero: " << muu2.knumero << endl;
			cout << endl << "Nimi: " << muu.etunimi << " " << muu.sukunimi << endl << "Osoite: " << muu.osoite << ", " << muu.postinumero << endl << "Koulumatka: " << muu.koulumatka << endl << "Kengannumero: " << muu.knumero << endl;
			cout << endl << "Nimi: " << mina.etunimi << " " << mina.sukunimi << endl << "Osoite: " << mina.osoite << ", " << mina.postinumero << endl << "Koulumatka: " << mina.koulumatka << endl << "Kengannumero: " << mina.knumero << endl;
		}
	}
	return 0;
}