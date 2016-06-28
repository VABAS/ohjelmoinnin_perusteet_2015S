#include "maarittelyt.h"
int randomi(int c) {//randomi(yläraja)
	c--;//Vähennetään laskurin arvoa yhdellä koska taulukon viimeinen indeksi on sitä yhden pienempi
	return (rand() % c);
}
int vertaa(rivi r1, rivi r2) {//vertaa(arvattu,kokeiltava)
	string varit_r1[4]={
						r1.vari1,
						r1.vari2,
						r1.vari3,
						r1.vari4
						};
	string varit_r2[4]={
						r2.vari1,
						r2.vari2,
						r2.vari3,
						r2.vari4
						};
	int molemmat=0;
	int oop=0;
	int ovp=0;
	bool loytynyt[4]={0,0,0,0};
	for(int i=0;i<4;i++){
		if(varit_r1[i]==varit_r2[i]){
			molemmat+=5;
			oop++;
			if(loytynyt[i]) molemmat--;
			else loytynyt[i]=true;
		}
		else{
			for(int ii=0;ii<4;ii++){
				if(ii!=i && !loytynyt[ii] && varit_r1[i]==varit_r2[ii]){
					molemmat++;
					loytynyt[ii]=true;
				}
			}
		}
	}
	return molemmat;
}
