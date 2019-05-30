/* This project has not been completed. */


#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#include <conio.h>
using namespace std;

typedef enum {
    user1='X',
    user2='Y'
}playertype;

class player{

        class nurullah{
        public:
           inline void setx_x(int a){this->x_x=a;}
           inline void setx_y(int a){this->x_y=a;}
           inline void sety_x(int a){this->y_x=a;}
           inline void sety_y(int a){this->y_y=a;}
           inline int getx_x(){return x_x;}
           inline int getx_y(){return x_y;}
           inline int gety_x(){return y_x;}
           inline int gety_y(){return y_y;}
        private:
            int x_x;
            int x_y;
            int y_x;
            int y_y;
        };
    public:
        player();
        inline int getWidht()const{return weight;}
        inline int getHeight()const{return height;}
        inline int getcardNumber()const{return cardNumber;}
        inline int getcardheight()const{return cardheight;}
        inline int getcardWeight()const{return cardWeight;}
        inline playertype gettype()const{return type;}
        void print_board();
        void print_card(playertype type);
        void print_to_card(int num, int area);
        void turn(int num, int degree, int way);
        void boardFill();
        void changeCard(int num, int num2);
        void users(int a, int b);
        int areas(int area,  vector<int> ar);
        int checkExit();

    private:
        char x_num;
        char y_num;
        int height;
        int weight;
        int cardNumber;
        int cardWeight;
        int cardheight;
        vector<string> board;
        vector< vector <string> >card;
        playertype type;
        nurullah ng;
};

int main(){
    int cardnum,degree,way,turn=1;
    int num, num2, say,a=0;
    int random, random2,area,exit;
    player eno;
    eno.boardFill();
    srand (time(NULL));
    random=rand()%5+1;      // X ve Y baslangic nokatalarinin random atanmasý icin sayi uretilir
    random2=rand()%5+1;

    eno.users(random,random2);          //degerler users fonksiyonuna yollanir
    vector<int> ar;
    do{
        a++;
        say=0;
        eno.print_board();                      //board yazdirilir
        if(turn%2==0){                          //kulanici siralarina gore oyun oynanir
            eno.print_card(user2);
            cout<<"User 2(Y)"<<endl;
        }else{
            eno.print_card(user1);
            cout<<"User 1(X)"<<endl;
        }
        while(1){
            cout<<"Choose an area(1-9)."<<endl;
            cin>>area;                                          // kullanicidan karti koymak icin konum alinir

            if((area<=9 && area>=1) && (eno.areas(area, ar)==0)){
                ar.push_back(area);
                break;
            }
        }
        while(1){
            cout<<"Choose a card"<<endl;
            cin>>cardnum;
            if(cardnum==1 || cardnum==2 || cardnum==3)
                break;                                                  //kullanici kullanicagi karti secer
            cout<<"Wrong choice try again!"<<endl;
        }
        say++;
        if(say==1)
            num=cardnum;
        else
            num2=cardnum;

        while(1){
            cout<<"If you want to turn your card, enter degree 90, 180 or 270. If you don't want enter 0."<<endl;
            cin>>degree;
            if(degree==90 || degree==180 || degree==270 || degree==0)
                break;                                  //kartini dondurmek isteyip istemedigi sorulur ve derecesi alinir
            cout<<"Wrong choice try again!"<<endl;
        }
        if(degree!=0){
            while(1){
                cout<<"If you want to turn left enter '1', turn right enter '2'"<<endl;
                cin>>way;                           //hangi yone dondurecegi sorulur
                if(way==1 || way==2)
                    break;
                cout<<"Wrong choice try again!"<<endl;
            }
            eno.turn(cardnum-1,degree,way);
        }
        if(turn%2==0)
            eno.print_to_card(cardnum+2,area);          //kullanicilarin kartlari yazdirilir
        else
            eno.print_to_card(cardnum-1,area);

/*
        exit=eno.checkExit();
        if(exit==1)         //bu bolumde oyunun bitme kontrolu yapiliyor ama bitmedigi icin acýk bulundurmadim
            break;
*/
        if(say==2){
            eno.changeCard(num, num2);      //kullanilan kartlar yerine  yenilei konulur
            say=0;
        }
        turn++;
        if(a==9)
            break;

    }while(1);

    return 0;
}

int player::checkExit(){

	if((ng.getx_x() == 0 || ng.getx_y() == 0 || ng.getx_x() == 19 || ng.getx_y() == 39) && (ng.gety_x() == 0 || ng.gety_y() == 0 || ng.gety_x() == 19 || ng.gety_y() == 39)){
		cout << "BERABERE" << endl;
		return 1;                           //oyunun berabere bitme kontrolu yaplir
	}
	if((ng.getx_x() == 0 || ng.getx_y() == 0 || ng.getx_x() == 19 || ng.getx_y() == 39)){
		cout << "Y KAZANDI" << endl;        //Y nin kazanma kontrolu
		return 1;
	}
	if((ng.gety_x() == 0 || ng.gety_y() == 0 || ng.gety_x() == 19 || ng.gety_y() == 39)){
		cout << "X KAZANDI" << endl;
		return 1;                            //X nin kazanma kontrolu
	}
	return 0;
}

void player::print_to_card(int num,int area){

    int x, y;
          if(area==1){
            x=1;
            y=2;
          }else if(area==2){
            x=1;
            y=14;
          }else if(area==3){
            x=1;
            y=26;
          }else if(area==4){
            x=7;
            y=2;
          }else if(area==5){
            x=7;
            y=14;
          }else if(area==6){
            x=7;
            y=26;
          }else if(area==7){
            x=13;                           //secilen bolgeye secilen kartlarin atamasi yapilir
            y=2;
          }else if(area==8){
            x=13;
            y=14;
          }else if(area==9){
            x=13;
            y=26;
          }
    for(int i=0; i<6; i++)
        for(int j=0; j<12; j++)
            board[x+i][y+j]=card[num][i][j];

}

 void player::changeCard(int num, int num2){

    vector<string> vec;
    vec.resize(6);

    for(int i=0; i<6; i++)
        vec[i].resize(12);
                                                    //kullanilan kartlar degistirilir
    for(int i=0; i<6; i++)
        for(int j=0; j<12; j++){
            vec[i][j]=card[num][i][j];
            card[num][i][j]=card[num2+2][i][j];
            card[num2+2][i][j]=vec[i][j];
        }
 }
int player::areas(int area,  vector<int> ar){

    for(int i=0; i<ar.size(); i++){
        if(area==ar[i])                     //secilen bolgenin 2. kez secilmeme kontrolu yapilir
            return 1;
    }
    return 0;
}
player::player(){

    this->weight = 40;
    this->height = 20;
    this->cardheight=6;
    this->cardNumber=6;
    this->cardWeight=12;

    board.resize(getHeight());
    for(int i=0; i< getHeight(); i++)               //board icin yer ayirilir
        board[i].resize(getWidht());

    card.resize(getcardNumber());
    for(int j=0; j<getcardNumber(); j++){
        card[j].resize(getcardheight());                  //kartlar icin yer ayirilir
        for(int i=0; i< getcardheight(); i++){
            card[j][i].resize(getcardWeight());
        }
    }
    for(int k=0; k<6; k++)
      for(int i=1; i<5; i++)
        for(int j=1;j<11; j++)
            card[k][i][j]=' ';
    for(int k=0; k<6; k++)
        for( int i=0; i<12; i++){                           //kartlarin ici doldurulur
            card[k][0][i]='.';
            card[k][5][i]='.';
        }
    for(int k=0; k<6; k++)
        for(int i=1; i<5; i++){
            card[k][i][0]=':';
            card[k][i][11]=':';
        }
    for(int k=0; k<6; k++){
        card[k][0][4]='1';
        card[k][0][7]='2';
        card[k][2][11]='3';
        card[k][3][11]='4';
        card[k][5][7]='5';
        card[k][5][4]='6';
        card[k][3][0]='7';
        card[k][2][0]='8';
    }
        card[0][1][4]='5';
        card[0][1][7]='6';
        card[0][2][4]='4';
        card[0][2][7]='7';
        card[0][3][4]='3';                          //1. kart
        card[0][3][7]='8';
        card[0][4][4]='2';
        card[0][4][7]='1';

        card[1][1][4]='8';
        card[1][1][7]='6';
        card[1][2][4]='1';
        card[1][2][7]='5';                           //2. kart
        card[1][3][4]='4';
        card[1][3][7]='7';
        card[1][4][4]='2';
        card[1][4][7]='3';

        card[2][1][4]='6';
        card[2][1][7]='5';
        card[2][2][4]='3';
        card[2][2][7]='8';
        card[2][3][4]='4';                           //3. kart
        card[2][3][7]='7';
        card[2][4][4]='1';
        card[2][4][7]='2';

        card[3][1][4]='7';
        card[3][1][7]='4';
        card[3][2][4]='6';
        card[3][2][7]='5';                           //4. kart
        card[3][3][4]='1';
        card[3][3][7]='2';
        card[3][4][4]='8';
        card[3][4][7]='3';

        card[4][1][4]='2';
        card[4][1][7]='1';
        card[4][2][4]='7';
        card[4][2][7]='4';
        card[4][3][4]='8';                       //5. kart
        card[4][3][7]='3';
        card[4][4][4]='5';
        card[4][4][7]='6';

        card[5][1][4]='3';
        card[5][1][7]='4';
        card[5][2][4]='6';
        card[5][2][7]='1';                       //6. kart
        card[5][3][4]='5';
        card[5][3][7]='2';
        card[5][4][4]='8';
        card[5][4][7]='7';

}
void player::users(int a, int b){
    if(a==1){
        board[0][6]='X';
        ng.setx_x(0);
        ng.setx_y(6);
    }else if(a==2){
        board[0][18]='X';
        ng.setx_x(0);
        ng.setx_y(18);
    }else if(a==3){
        board[3][39]='X';
        ng.setx_x(3);                       //atanan X in kordinatlari tutulur
        ng.setx_y(39);
    }else if(a==4){
        board[10][39]='X';
        ng.setx_x(10);
        ng.setx_y(39);
    }else if(a==5){
        board[16][0]='X';
        ng.setx_x(18);
        ng.setx_y(0);
    }

    if(b==1){
        ng.sety_x(10);
        ng.sety_y(0);
        board[10][0]='Y';
    }else if(b==2){
        ng.sety_x(15);                  //atanan Y in kordinatlari tutulur
        ng.sety_y(0);
        board[15][0]='Y';
    }else if(b==3){
        ng.sety_x(19);
        ng.sety_y(6);
        board[19][6]='Y';
    }else if(b==4){
        ng.sety_x(19);
        ng.sety_y(18);
        board[19][18]='Y';
    }else if(b==5){
        ng.sety_x(15);
        ng.sety_y(39);
        board[15][39]='Y';
    }
}
void player::print_board(){

    for(int i=0; i<20; i++){
        for(int j=0; j<40; j++)             //board yazdirilir
            cout<<""<<board[i][j];
        cout<<endl;
    }

}
void player::print_card(playertype type){

    int i,j,k;
    cout<<endl;
    if(type==user1){
        for(i=0; i<3; i++){
            for(j=0; j<6; j++){                                    //kullanici sirasina gore kartlar yazdirilir
                for(k=0;k<12; k++){
                    cout<<""<<card[i][j][k];
                }
                cout<<endl;
            }
            cout<<endl<<"CARD "<<i+1<<endl<<endl;
        }
    }else{
         for(i=3; i<6; i++){
            for(j=0; j<6; j++){
                for(k=0;k<12; k++)
                    cout<<""<<card[i][j][k];
                cout<<endl;
            }
            cout<<endl<<"CARD "<<i-2<<endl<<endl;
        }

    }
}


void player::turn(int num, int degree, int way){

    char temp,temp2;
    int i,j;
    if(way==1){
        if(degree==90){
            i=3;
        }else if(degree==180){
            i=2;
        }else
            i=1;
    }else{                                  //istenilen yone ve dereceye gore kartlar dondurulur
        if(degree==90){
            i=1;
        }else if(degree==180){
            i=2;
        }else
            i=3;
    }
    for(j=0; j<i; j++){
        temp=card[num][0][4];
        temp2=card[num][0][7];
        card[num][0][4]=card[num][3][0];
        card[num][0][7]=card[num][2][0];
        card[num][2][0]=card[num][5][4];
        card[num][3][0]=card[num][5][7];
        card[num][5][4]=card[num][3][11];
        card[num][5][7]=card[num][2][11];
        card[num][2][11]=temp;
        card[num][3][11]=temp2;

        temp=card[num][1][4];
        temp2=card[num][1][7];
        card[num][1][4]=card[num][3][4];
        card[num][1][7]=card[num][2][4];
        card[num][2][4]=card[num][4][4];
        card[num][3][4]=card[num][4][7];
        card[num][4][4]=card[num][3][7];
        card[num][4][7]=card[num][2][7];
        card[num][2][7]=temp;
        card[num][3][7]=temp2;
    }
}

void player::boardFill(){

   int i,j;

	for( i=1; i<getHeight(); i++){
        for(j=1; j<getWidht(); j++)
            board[i][j]=' ';
    }
    for(i=0; i<getWidht(); i++){
        board[0][i]='-';
        board[19][i]='-';                                   //boardun ici doldurulur
    }
    for(i=6; i<getWidht(); i+=12){
        board[0][i]='o';
        board[0][i+3]='o';
        board[19][i]='o';
    	board[19][i+3]='o';
	}
    for(i=1; i<getHeight()-1; i++){
        board[i][0]='|';
        board[i][39]='|';
    }
    for(i=3; i<getHeight(); i+=6){
        board[i][0]='o';
        board[i][39]='o';
        board[i+1][0]='o';
        board[i+1][39]='o';
    }
}
