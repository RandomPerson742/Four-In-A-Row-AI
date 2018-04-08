#include <stdio.h>
#include <stdlib.h>
//----------------------AI za tri poteze
char mreza[5][5]={{'.','.','.','.','.'},{'.','.','.','.','.'},{'.','.','.','.','.'},{'.','.','.','.','.'},{'.','.','.','.','.'}};

int mrezaAI[5][5];

int v,s;
int znak, stolp, zmaga;
char n;
int st[]={0,0,0,0,0};	//za polnjenje stolpcev

void izpis();
int vpisPoteze(int igralec);
void vpisMreza(int igralec);
int preveriVse(int igralec);
int preveriZmago(int igralec);

int main() {
	int ig=1, vpisano;
		printf("Pozdravljeni v igri 4 v vrsto!\n1. igralec je 'x', 2. pa 'o'.\n");
	izpis();
		do {
			
			 vpisano=vpisPoteze(ig);
			if(vpisano>=0 && vpisano<5) {
				vpisMreza(vpisano);
				vpisano = preveriZmago(ig);
				if(ig==1) ig=2; else if(ig==2) ig=1;
			}

		} while(vpisano!=-1);
		//printf("%c", mreza[3][0]);
		printf("konec\n");
return 0;
}

int vpisPoteze(int igralec) {
	if(igralec ==1){
		n='x';
	} else if(igralec ==2) {
		n='o';
	}
		printf(" %d. igralec vpiši: ", igralec);
		scanf("%d", &stolp);
		stolp--;
if(stolp==-1) return -1;	//če narobe vpišeš
if(stolp>4) return 6;
	return stolp;
}
void vpisMreza(int stolpec){

	int stp=st[stolpec];
		if(stolp<=4 && stolp>=0 && stp<5) {
			mreza[stp][stolpec]=n;
			st[stolpec]++;
			izpis();
		}
}

int preveriZmago(int igralec) {
zmaga = preveriVse(igralec);
	if(zmaga) {
		printf("(tip %d) Zmagovalec je %d. igralec, bravo!!\n", zmaga, igralec);
		return -1;
	}
return 1;
}

void izpis(void) {
int i,j;
for(i=1; i<6; i++) {printf(" %d", i); }
printf("\n");
	for(i=4; i>-1; i--){
		for(j=0;j< 5; j++) {
			printf(" %c", mreza[i][j]);		//i=vrstice, j=stolpci
		}
	 printf("\n");
	}
}

int preveriVse(int igralec) {		//vrne 1)vertkalno, 2)horizontalno, 3)diagonalno levo, 4)diagonalno desno
	int stevec=0, x,y;	//x=j, y=i;  VERTIKALA
	for(x=0; x<5; x++){
		for(y=0; y<4; y++){
			if(mreza[y][x] != '.'){
				if(mreza[y][x]==mreza[y+1][x]) {stevec++;}
				else if(mreza[y][x]!=mreza[y+1][x]) {stevec=0;}
			}
		 if(stevec>=3) return 1;
		}
		stevec=0;
	}
for(y=0; y<5; y++){		//HORIZONTALA
		for(x=1; x<5; x++){
			if(mreza[y][x] != '.') {
				if(mreza[y][x]==mreza[y][x-1]) {stevec++;}
				else if(mreza[y][x]!=mreza[y][x-1]) {stevec=0;}
			}
		 if(stevec>=3) {return 2;}
		}
		stevec=0;
	}
	int nula=2;		//DIAGONALA LEVA
for(s=0; s<2; s++) {
for(v=0; v<nula; v++) {
		for(y=(2-v-s), x=(1+s); y<5; y++, x++){
			if(mreza[y][x] != '.') { 
				if(mreza[y][x]==mreza[y-1][x-1]) {stevec++;}
				else if(mreza[y][x]!=mreza[y-1][x-1]) {stevec=0;}
			} 
		 if(stevec>=3) {return 3;}
		}
		stevec=0;
  }nula=1;
 }
	nula=2;		//DIAGONALA DESNA
for(s=0; s<2; s++) {
for(v=0; v<nula; v++) {
		for(y=(2-v-s), x=(3-s); y<5; y++, x--){
			if(mreza[y][x] != '.') {
				if(mreza[y][x]==mreza[y-1][x+1]) {stevec++;}
				else if(mreza[y][x]!=mreza[y-1][x+1]) {stevec=0;}
			} 
		 if(stevec>=3) {return 4;}
		}
		stevec=0;
  }nula=1;
 }
return 0;
}
