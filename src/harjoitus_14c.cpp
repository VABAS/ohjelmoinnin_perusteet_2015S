#include <iostream>
using namespace std;
char merkkijono[100], etuperin[100], takaperin[100];
char tyhja[1];
int main() {
	cout << "Anna merkkijono: ";
	cin.get(merkkijono, 100);
	int i = 0;//Laskuri
	while (merkkijono[i]!=tyhja[0]) {//Ajetaan merkkijono merkkijonoon etuperin ja lasketaan pituus
		etuperin[i] = merkkijono[i];
		i++;
	}
	i--;//Vähennetään arvoa yhdellä koska viimeinen merkki on tyhjä
	int i2 = 0;//Laskuri2
	while (i >= 0) {//Ajetaan merkkijono merkkijonoon takaperin nurinpäin
		takaperin[i2] = etuperin[i];
		i--;
		i2++;
	}
	if (!strcmp(etuperin,takaperin)) cout << "Sana on palindromi!" << endl;//Verrataan merkkijonoja etuperin ja takaperin funktiolla strcmp
	else cout << "Sana ei ole palindromi" << endl;
	return 0;
}