#include <stdio.h>
#include <stdlib.h>

int mmp,hhp,YYp,MMp,DDp; //input partenza 
int mma,hha,YYa,MMa,DDa; //input arrivo

//controllo input
int Minuto(){
	int mm;
	scanf("%d",&mm);
	while(mm <0 || mm>59){
		printf("Minuto sbagliato\n");
		scanf("%d",&mm);
	}
	return mm;
}
int Ora(){
	int hh;
	scanf("%d",&hh);
	while(hh<0 || hh>23){
		printf("ora sbagliata\n");
		scanf("%d",&hh);
	}
	return hh;
}
int Anno(){
	int YY;
	scanf("%d",&YY);
	while(YY<1888 || YY>2100){
		printf("anno sbagliato\n");
		scanf("%d",&YY);
	}
	return YY;
}
int Mese(){
	int MM;
	scanf("%d",&MM);
    while(MM<1 || MM >12){
    	printf("Questo mese non esiste\n");
    	scanf("%d",&MM);
	}
	return MM;
}
int Giorno(int MM,int YY){
	int DD;
	scanf("%d",&DD);
	if(MM ==4 || MM==6 || MM == 9 || MM == 11){
    	while(DD<0 || DD>30){
    		printf("Questo giorno non esiste in questo mese\n");
    		scanf("%d",&DD);
		}	
	}else if(MM==2){
		if(YY % 4 == 0 && YY % 400 != 0){
			while(DD<0 || DD>28){
				printf("Questo giorno non esiste in questo mese\n");
    			scanf("%d",&DD);
			}
		}else {
			while(DD<0 || DD > 29 ){
				printf("Questo giorno non esiste in questo mese\n");
    			scanf("%d",&DD);	
			}
		}
	}else{
		while(DD<0 || DD>31){
			printf("Questo giorno non esiste in questo mese\n");
	    	scanf("%d",&DD);
		} 
	}
	return DD;
}
//controllo conto
int GiornoBisestile(int anno){
	if(anno % 4 == 0 && anno % 400 != 0)
		return 1; //vero 
	else
		return 0; //falso	
}
int CalcoloGiorno(int anno,int mese){
	int giorni[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //giorni presenti nei mesi
	if(GiornoBisestile(anno) && mese ==2)
		return 29; //se è febbraio ed è bisestile sarà sicuramente 29
	else
		return giorni[mese]; //prendo il giorno direttamente dal mese
}
int main(int argc, char *argv[]) {
	
	//partenza
	
	printf("inserisci minuto\n");
	mmp = Minuto();
	printf("inserisci ora\n");
	hhp = Ora();
	printf("inserisci anno\n");
	YYp= Anno();
	printf("inserisci mese\n");
	MMp= Mese();
	printf("inserisci giorno\n");
	DDp = Giorno(MMp,YYp);
	
	//arrivo
	
	printf("inserisci minuto\n");
	mma = Minuto();
	printf("inserisci ora\n");
	hha = Ora();
	printf("inserisci anno\n");
	YYa= Anno();
	printf("inserisci mese\n");
	MMa= Mese();
	printf("inserisci giorno\n");
	DDa = Giorno(MMa,YYa);
	
	//calcolo
	
	int anno = YYa - YYp;
    int mese = MMa- MMp;
    int giorno = DDa - DDp;
    int ora = hha - hhp;
    int minuto = mma - mmp;
    
    //controllo andando indietro
    
    if(minuto<0){
    	minuto +=60;
    	ora--;
	}
	if(ora<0){
		ora+=24;
		giorno--;
	}
	if(giorno<0){
		giorno+= CalcoloGiorno(anno,mese);
		mese--;
	}
	if(mese<0){
		mese+=12;
		anno--;
	}
	
	//stampa finale
	
	printf("Hai viaggiato nel tempo per %d anni %d mesi %d giorni %d ore %d minuti ", anno,mese,giorno,ora,minuto);
	
	return 0;
}
