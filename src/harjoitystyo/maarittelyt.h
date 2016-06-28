#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;
struct rivi {
	string vari1, vari2, vari3, vari4;
};
int randomi(int);//Palauttaa randomin numeron väliltä 0-int
int vertaa(rivi, rivi);//Verrataan kahta riviä ja palautetaan yhtenäisyys