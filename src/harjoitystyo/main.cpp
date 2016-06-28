#include "maarittelyt.h"

int main() {
	srand(time(NULL));
	const int varimaara = 9;	//V„rien m„„r„. Jos lis„„t tai v„henn„t v„rej„ muuta t„m„ vastaamaan
								//Huomaa, ett„ ensimm„inen on aina "tyh"!
	string varit[varimaara] = {
								"tyh",//Tyhj„
								"Pun",//Punainen
								"Sin",//Sininen
								"Vih",//Vihre„
								"Kel",//Keltainen
								"Val",//Valkoinen
								"Vio",//Violetti(SiniPunainen)
								"Tur",//Turkoosi(SiniVihre„)
								"SiP",//SiniPunainen
	};
	cout << "K„ytett„viss„ olevat olevat v„rit ovat ";//Kerrotaan k„ytt„j„ll„ mit„ v„rej„ on k„yt”ss„
	for (int i = 0;i < varimaara;i++) {//K„yd„„n v„ritaulukko l„pi
		if (i == (varimaara - 1)) cout << "ja ";//Jos seuraava on viimeinen tulostetaan ensin 'ja'
		cout << varit[i] << " ";
	}
	cout << endl;
	vector<rivi> rivit;//Luodaan vectori, t„st„ eteenp„in kutsutaan sit„ taulukoksi
	char tyhjatk;
	int alku;
	while (true) {//Kysyt„„n onko tyhj„t k„yt”ss„ ja vaaditaan kelvollinen vastaus
		cout << "Onko tyhj„t paikat k„ytoss„?(K/e) ";
		cin >> tyhjatk;
		if (tyhjatk == 'K' || tyhjatk == 'k') {
			alku = 0;
			break;
		}
		else if (tyhjatk == 'E' || tyhjatk == 'e') {
			alku = 1;
			break;
		}
		else cout << "Vastaa K/e!" << endl;
	}
	//K„yd„„n jokainen yhdistelm„ l„pi joita siis on varimaara^4 jos tyhj„t on k„yt”ss„ ja (varimaara-1)^4 jos ei
	//alku-muuttuja on 0 jos tyhj„t ovat k„yt”ss„ ja 1 jos ei ja kertoo mist„ kohtaa v„ritaulukkoa l„hdet„„n liikkeelle silmukoissa
	for (int i1 = alku;i1 < varimaara;i1++) {
		for (int i2 = alku;i2 < varimaara;i2++) {
			for (int i3 = alku;i3 < varimaara;i3++) {
				for (int i4 = alku;i4 < varimaara;i4++) {
					rivit.push_back({varit[i1],varit[i2],varit[i3],varit[i4]});//Ty”nnet„„n uusi rivi taulukon per„lle
				}
			}
		}
	}
	int arvaukset=0;//Arvauslaskuri
	while (true) {//P„„silmukka
		int riveja_jaljella = rivit.size();//Kysyt„„n j„ljell„olevien ratkaisujen m„„r„ joka kierroksen alussa ja tallennetaan sek„ ilmoitetaan se k„ytt„j„lle
		cout << "Mahdollisuuksia j„ljell„ " << riveja_jaljella << " kappaletta" << endl;
		if(riveja_jaljella == 1){//Jos on vaan yksi j„ljell„ niin sen on oltava oikein
			cout<<"Oikea vastaus on "<<rivit[0].vari1<< " "<<rivit[0].vari2<< " "<<rivit[0].vari3<< " "<<rivit[0].vari4<<endl;
			cout << "Arvasin " << arvaukset << " kertaa" << endl;//Kerrotaan monesko arvaus oli
			break;//Poistutaan p„„silmukasta
		}
		else if (riveja_jaljella <= 0) {//Jos rivej„ ei ole j„ljell„ k„ytt„j„ on huijannut (oli se sitten vahingossa tai tahallaan...)
			cout << "Mik„„n ratkaisu ei ollut oikein :(" << endl;
			break;
		}
		int randomi_i = randomi(riveja_jaljella);//Arvotaan seuraava arvaus
		arvaukset++;//Lis„t„„n arvaus laskuria yhdell„
		cout << "Arvaan " << rivit[randomi_i].vari1 << " " << rivit[randomi_i].vari2 << " " << rivit[randomi_i].vari3 << " " << rivit[randomi_i].vari4 << endl;
		int oop = -1;//Oikein oikealla paikalla
		int ovp = -1;//Oikein v„„r„ll„ paikalla
		while (true) {//Kysyt„„n mitenk„ arvaus onnistui
			cout << "Montako on oikein ja oikealla paikalla? ";
			cin >> oop;
			cout << "Montako on oikein ja v„„r„ll„ paikalla? ";
			cin >> ovp;
			if (oop >= 0 && oop <= 4 && ovp >= 0 && ovp <= 4 && oop + ovp <= 4) break;
			else cout << "Luvut eiv„t kelpaa! Huomaa ett„ molempien lukujen ja niiden summan on oltava v„lilt„ 0-4" << endl;
		}
		if(oop==4){//Jos kaikki on oikein, niin arvaus on osunut oikein. Kerrotaan asiasta
			cout<<"Arvasin siis oikein, rivi oli " << rivit[randomi_i].vari1 << " " << rivit[randomi_i].vari2 << " " << rivit[randomi_i].vari3 << " " << rivit[randomi_i].vari4 << endl;
			cout << "Arvasin " << arvaukset << " kertaa" << endl;//Kerrotaan monesko arvaus oli
			break;
		}
		else{
			/*Pieni selitys lienee paikallaan seuraavasta:
			 	 Muuttuja (int)kombo kertoo miten onnistunut arvaus oli
			 	 >>Jokainen oikea v„ri oikealla paikalla lis„„ arvoa viidell„
			 	 >>Jokainen oikea v„ri v„„r„ll„ paikalla lis„„ arvoa yhdell„
			 	 T„m„ arvo lasketaan arvatusta rivist„ ja sit„ verrataan jokaisen j„ljell„ olevan rivin vastaavaan arvoon joka lasketaan vertaa() funktiossa
			 	 Jos arvot eiv„t ole samat rivi ei voi olla oikein ja se poistetaan taulukosta
			*/
			int kombo=oop*5+ovp;
			rivi arvattu_rivi=rivit[randomi_i];		//Tallenetaan arvattu rivi muuttujaan
			rivit.erase(rivit.begin()+randomi_i);	//ja poistetaan sen rivi, koska se ei ainakaan ole oikein
			riveja_jaljella--;
			for (int i = 0;i < riveja_jaljella;/**/){//K„yd„„n kaikki j„ljell„ olevat rivit l„pi ja verrataan arvattuun
				int vertaus=vertaa(arvattu_rivi,rivit[i]);
				if(kombo!=vertaus){//Jos rivi ei voi olla oikein poistetaan se taulukosta
					rivit.erase(rivit.begin()+i);
					riveja_jaljella--;
				}
				else i++;//Muutoin lis„t„„n rivin arvoa yhdell„
			}
		}
	}
	return 0;
}
