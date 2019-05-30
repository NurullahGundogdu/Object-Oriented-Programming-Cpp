#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

using namespace std;

double calculate(char a[100]);

int main() {
	
	char object[100], nam[100], nam2[100];
	double cost;
	
	cout<<"Define the object:"<<endl;						//kullanicidan nesnenin ismi istenir
	cin.getline(object,100);
	
	sscanf(object,"%s",nam);								//eger girilen isimde bosluk var ise bosluklar silinir
	strcpy(nam2,nam);										//nesnenin adinin kaybolmamasi icin baska bir arraya kopylnir 
	
	cost=calculate(nam);									//calculate fonksiyonu cagirilir
	cout<<"Total cost of "<<nam2<<" is "<<cost<<endl;		//toplam fiyat yazdirilir
}

double calculate(char a[100]){
	
	int i, indexNum=0, coefficient;
	double cost, total_cost=0;
	char piece_name[100];
	bool star=false;
		
	cout<<"What is "<<a<<"?:"<<endl;						//kullanicidan nensnenin tanimi istenir
	cin.getline(a,100);
	
	for(i=0; i<100; i++){									//girdide * var ise yerine bosluk yazdirilir
        if(a[i]=='*'){
        	a[i]=' ';										//ve yýlýz sayisi tutulur
            star=true;
        }
    }    
    if(star==false){										//eger girdide yildiz yok ise girdi fiyatdýr 
    	cost=atof(a);										//fiyat geri dondurulur
    	return cost;  	
	}
	for(i=0; i<100; i++){
        if(a[i]=='+'){                						//girdide birden fazla malzeme var mi diye bakýlýr 
            a[i]=' ';										//var ise yerine bosluk koyulur
            sscanf(&a[indexNum],"%d %s",&coefficient,piece_name);		//kat sayi ve malzeme ayrilir
            cost=calculate(piece_name);						//fonksiyon tekrar cagirilir
            cost*=coefficient;								//fiyat ile kat sayi carpilir fiyat toplam fiyata eklenir
            total_cost+=cost;
            indexNum=i;
        }		
	}
	sscanf(&a[indexNum],"%d %s",&coefficient,piece_name);	//kat sayi ve malzeme ayrilir
	cost=calculate(piece_name);								//fonksiyon tekrar cagirilir
	cost*=coefficient;										//fiyat ile kat sayi carpilir fiyat toplam fiyata eklenir
    total_cost+=cost;
		
	return total_cost;										//toplam fiyat dondurulur
}
