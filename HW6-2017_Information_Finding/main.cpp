#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <sstream>
#include<string.h>
using namespace std;

class music{
    public:
        music();                            //constructor
        void print_file();                  //islem sonuclarini dosyaya yazdiricak fonksiyon
        int find_str(string arr, string barr);  //search islemini yapan fonksiyon
        vector<int> sort_str(string arr);       //sort islemini yapan fonksiyon
        vector<string> sentence;
        vector<string> title;
        vector<string> artist;                  //dosyadaki bilgileri tutan vectorler
        vector<string> genre;
        vector<string> year;
        vector<int> exe;            //dublicate ve missing olanlari tutan vector
        vector<int> axa;
        int numm;                          //unique sayisini tutan degisken
    private:
};

class book{
    public:
        book();                             //constructor
        void print_file();              //islem sonuclarini dosyaya yazdiricak fonksiyon
        int find_str(string arr, string barr);      //search islemini yapan fonksiyon
        vector<int> sort_str(string arr);       //sort islemini yapan fonksiyon
        vector<string> sentence;
        vector<string> title;
        vector<string> authers;             //dosyadaki bilgileri tutan vectorler
        vector<string> tags;
        vector<string> year;
        vector<int> exe;                //dublicate ve missing olanlari tutan vector
        vector<int> axa;
        int numm;                       //unique sayisini tutan degisken
    private:
};

class movie{
    public:
        movie();                    //constructor
        void print_file();          //islem sonuclarini dosyaya yazdiricak fonksiyon
        int find_str(string arr, string barr);   //search islemini yapan fonksiyon
        vector<int> sort_str(string arr);   //sort islemini yapan fonksiyon
        vector<string> sentence;
        vector<string> title;
        vector<string> director;
        vector<string> starring;        //dosyadaki bilgileri tutan vectorler
        vector<string> genre;
        vector<string> year;
        vector<int> exe;                        //dublicate ve missing olanlari tutan vector
        vector<int> axa;
        int numm;       //unique sayisini tutan degisken
    private:
};
class missing:public exception{
    public: string miss(){              //eksik field exceptioni
                return "Exception: missing field";
            };
};
class duplicate:public exception{           //dublicate durumu exceptioni
    public: string dup(){
                return "Exception: duplicate entry";
            };
};
class wrong:public exception{           //hatali aama exceptioni
    public: string wro(){
                return "Exception: command is wrong";
            };
};
class execpt{
    public: int exxe(int num){
                if(num==1)
                    throw missing();
                if(num==2)
                    throw duplicate();
                if(num==3)
                    throw wrong();
                return 0;
            }
};

movie::movie(){
    int a;
    string temp,temp2,temp3=" ";
    ifstream file;
    file.open("data.txt");
    if(!file.is_open()){
        cout<<"Error opening file"<<endl;    //dosya acilip acilmama kotrolu yapilir
        return ;
    }
    getline (file, temp);           //dosyadan bilgiler satir satir okunur
    while(!file.eof()){
        getline (file, temp);
        sentence.push_back(temp);
        a=0;
        for(size_t i=0; i<temp.length(); i++){
            if(temp[i]=='"'){                   // " gordukce bolunurler
                for(size_t j=i+1; j<temp.length(); j++){
                    if(temp[i+1]=='"'){
                        temp2=" ";
                        break;
                    }
                    if(temp[j]=='"'){           //eger tirnaklarin arasinda bilgi yoksa bos atanir
                         break;
                    }else
                        temp2.push_back(temp[j]);
                }
                if(a==0){
                    title.push_back(temp2);             //okuma sirasina gore bilgile gerekli vektorlere eklenir
                }else if(a==2){
                    director.push_back(temp2);
                }else if(a==4){
                    year.push_back(temp2);
                }else if(a==6){
                    genre.push_back(temp2);
                }else if(a==8){
                    starring.push_back(temp2);
                }
                a++;
                temp2.clear();
            }
        }
        if(a==10){
            exe.push_back(0);           //egere missing field varf ise exe vektorunde belirtilir
        }else
            exe.push_back(1);
    }
    for(size_t i=0; i<title.size(); i++)
        for(size_t j=0; j<title[i].length(); j++)
            if(title[i][0]==' ' || title[i][0]=='\t')
                title[i].erase(title[i].begin()+0);
    for(size_t i=0; i<director.size(); i++)
        for(size_t j=0; j<director[i].length(); j++)
            if((director[i][0]==' ' || director[i][0]=='\t'))
                director[i].erase(director[i].begin()+0);
    for(size_t i=0; i<year.size(); i++)
        for(size_t j=0; j<year[i].length(); j++)            //eger tirnaklar arasi bosluk var ise bosluklar silinir
            if((year[i][0]==' ' || year[i][0]=='\t'))
                year[i].erase(year[i].begin()+0);
    for(size_t i=0; i<title.size(); i++)
        for(size_t j=0; j<title[i].length(); j++)
            if(genre[i][0]==' ' || genre[i][0]=='\t')
                genre[i].erase(genre[i].begin()+0);
    for(size_t i=0; i<starring.size(); i++)
        for(size_t j=0; j<starring[i].length(); j++)
            if(starring[i][0]==' ' || starring[i][0]=='\t')
                starring[i].erase(starring[i].begin()+0);
    numm=0;
    for(size_t i=0; i<exe.size(); i++)
        for(size_t j=i+1; j<exe.size(); j++){
            if(title[i]==title[j])              //dublicate olan satir sayisi hesaplanr
                numm++;
            if(title[i]==title[j] && exe[j]!=1)
                exe[j]=2;
        }
    file.close();
}

book::book(){

    int a;
    string temp,temp2;
    ifstream file;
    file.open("data.txt");
    if(!file.is_open()){
        cout<<"Error opening file"<<endl;    //dosya acilip acilmama kotrolu yapilir
        return ;
    }
    getline (file, temp);
    while(!file.eof()){                 //dosyadan bilgiler satir satir okunur
        getline (file, temp);
        sentence.push_back(temp);
        a=0;
        for(size_t i=0; i<temp.length(); i++){
            if(temp[i]=='"'){           // " gordukce bolunurler
                for(size_t j=i+1; j<temp.length(); j++){
                    if(temp[i+1]=='"'){
                        temp2=" ";
                        break;
                    }
                    if(temp[j]=='"'){       //eger tirnaklarin arasinda bilgi yoksa bos atanir
                         break;
                    }else
                        temp2.push_back(temp[j]);
                }
                if(a==0){
                    title.push_back(temp2);         //okuma sirasina gore bilgile gerekli vektorlere eklenir
                }else if(a==2){
                    authers.push_back(temp2);
                }else if(a==4){
                    year.push_back(temp2);
                }else if(a==6)
                    tags.push_back(temp2);
                a++;
                temp2.clear();
            }
        }
        if(a==8){                       //egere missing field varf ise exe vektorunde belirtilir
            exe.push_back(0);
        }else
            exe.push_back(1);
    }
    for(size_t i=0; i<title.size(); i++)
        for(size_t j=0; j<title[i].length(); j++)
            if(title[i][0]==' ' || title[i][0]=='\t')
                title[i].erase(title[i].begin()+0);
    for(size_t i=0; i<authers.size(); i++)
        for(size_t j=0; j<authers[i].length(); j++)
            if(authers[i][0]==' ' || authers[i][0]=='\t')
                authers[i].erase(authers[i].begin()+0);
    for(size_t i=0; i<year.size(); i++)
        for(size_t j=0; j<year[i].length(); j++)            //eger tirnaklar arasi bosluk var ise bosluklar silinir
            if(year[i][0]==' ' || year[i][0]=='\t')
                year[i].erase(year[i].begin()+0);
    for(size_t i=0; i<tags.size(); i++)
        for(size_t j=0; j<tags[i].length(); j++)
            if(tags[i][0]==' ' || tags[i][0]=='\t')
                tags[i].erase(tags[i].begin()+0);
    numm=0;
    for(size_t i=0; i<exe.size(); i++)
        for(size_t j=i+1; j<exe.size(); j++){
            if(title[i]==title[j])          //dublicate olan satir sayisi hesaplanr
                numm++;
            if(title[i]==title[j] && exe[j]!=1)
                exe[j]=2;
        }
    file.close();
}

music::music(){

    int a=0;
    string temp,temp2;
    ifstream file;
    file.open("data.txt");
    if(!file.is_open()){
        cout<<"Error opening file"<<endl;    //dosya acilip acilmama kotrolu yapilir
        return ;
    }
    getline (file, temp);
    while(!file.eof()){
        getline (file, temp);       //dosyadan bilgiler satir satir okunur
        sentence.push_back(temp);
        a=0;
        for(size_t i=0; i<temp.length(); i++){
            if(temp[i]=='"'){       // " gordukce bolunurler
                for(size_t j=i+1; j<temp.length(); j++){
                    if(temp[i+1]=='"'){
                        temp2=" ";
                        break;
                    }
                    if(temp[j]=='"'){           //eger tirnaklarin arasinda bilgi yoksa bos atanir
                         break;
                    }else
                        temp2.push_back(temp[j]);
                }
                if(a==0){
                    title.push_back(temp2);
                }else if(a==2){
                    artist.push_back(temp2);
                }else if(a==4){                 //okuma sirasina gore bilgile gerekli vektorlere eklenir
                    year.push_back(temp2);
                }else if(a==6)
                    genre.push_back(temp2);
                a++;
                temp2.clear();
            }
        }
        if(a==8){
            exe.push_back(0);
        }else                   //egere missing field varf ise exe vektorunde belirtilir
            exe.push_back(1);
    }
    for(size_t i=0; i<title.size(); i++)
        for(size_t j=0; j<title[i].length(); j++)
            if(title[i][0]==' ' || title[i][0]=='\t')
                title[i].erase(title[i].begin()+0);
    for(size_t i=0; i<artist.size(); i++)
        for(size_t j=0; j<artist[i].length(); j++)
            if(artist[i][0]==' ' || artist[i][0]=='\t')
                artist[i].erase(artist[i].begin()+0);
    for(size_t i=0; i<year.size(); i++)
        for(size_t j=0; j<year[i].length(); j++)            //eger tirnaklar arasi bosluk var ise bosluklar silinir
            if(year[i][0]==' ' || year[i][0]=='\t')
                year[i].erase(year[i].begin()+0);
    for(size_t i=0; i<genre.size(); i++)
        for(size_t j=0; j<genre[i].length(); j++)
            if(genre[i][0]==' ' || genre[i][0]=='\t')
                genre[i].erase(genre[i].begin()+0);
    numm=0;
    for(size_t i=0; i<exe.size(); i++)
        for(size_t j=i+1; j<exe.size(); j++){
            if(title[i]==title[j])
                numm++;                     //dublicate olan satir sayisi hesaplanr
            if(title[i]==title[j] && exe[j]!=1)
                exe[j]=2;
        }
    file.close();
}

void music::print_file(){
    execpt d,p;
    int a,num;
    vector<int> barr;
    string temp,temp2,temp3,temp4,temp5;
    ofstream file1;
    file1.open("output.txt");
    file1 << "Catalog Read: music"<<endl;           //output dosyasi acilir
    for(size_t i=0; i<title.size(); i++){
        try{
            d.exxe(exe[i]);
        }catch(duplicate a){                //exception durumuna gore bilgiler dosyaya yazdirlir
            file1<<a.dup()<<endl;
            file1<<sentence[i]<<endl;
        }catch(missing b){
            file1<<b.miss()<<endl;
            file1<<sentence[i]<<endl;
        }
    }
    file1<<title.size()-numm<<" unique entries"<<endl;          //hesaplanan unique sayisi yazdirilir

    ifstream file;
    file.open("commands.txt");
    if(!file.is_open()){
        cout<<"Error opening file"<<endl;    //dosya acilip acilmama kotrolu yapilir
        return ;
    }
    while(!file.eof()){
       file>>temp;
       if(temp=="search"){              //commands dosyasi okunur search ve sort durumuna gore fsakli okunur
            getline (file, temp2);
            a=0;
            for(size_t i=0; i<temp2.length(); i++){
                if(temp2[i]=='"'){                          //" li ayirma islemi burda da uygulanir
                    for(size_t j=i+1; j<temp2.length(); j++){
                        if(temp2[j]=='"'){
                             break;
                        }else
                            temp5.push_back(temp2[j]);
                    }
                    if(a==0){
                        temp3=temp5;
                    }else if(a==2){
                        temp4=temp5;
                    }
                    a++;
                    temp5.clear();
                }
            }
            num=find_str(temp3,temp4);      //aranmak istenen kelime ve hangi fielde aranacagi fonksiyona yolanir
            if(num==-1){
                 try{
                    p.exxe(3);          //gelen sonuca gore ya exception yapilir ya dabulunan satir yazdirilir
                }catch(duplicate a){
                }catch(missing b){
                }catch(wrong c ){
                    file1<<c.wro()<<endl;
                    file1<<temp<<""<<temp2<<endl;
                }
            }else{
                file1<<temp<<""<<temp2<<endl;
                file1<<sentence[num]<<endl;
            }

       }else if(temp=="sort"){
           getline(file, temp2);            //sort islemi okunmasi yapilir
            for(size_t i=0; i<temp2.length(); i++){
                if(temp2[i]=='"'){
                    for(size_t j=i+1; j<temp2.length(); j++){
                        if(temp2[j]=='"'){
                             break;
                        }else
                            temp5.push_back(temp2[j]);
                    }
                }
            }
            file1<<temp<<temp2<<endl;   //neye gore sort edilicek is o fonksiyona yollanir
            barr=sort_str(temp5);
            for(size_t i=0; i<barr.size(); i++)
                if(barr[i]>=0 && axa[i]==1)
                     file1<<sentence[barr[i]]<<endl;      //gelen sonuca gore cilgiler sort edilir
            for(size_t i=0; i<barr.size(); i++)
                if(barr[i]>=0 && axa[i]==0)
                    file1<<sentence[barr[i]]<<endl;      //gelen sonuca gore cilgiler sort edilir
       }
    }
    file.close();           //dosyalar kapatilir
    file1.close();

}
void book::print_file(){
    execpt d,p;
    int a,num;
    vector<int> barr;
    string temp,temp2,temp3,temp4,temp5;
    ofstream file1;
    file1.open("output.txt");
    file1 << "Catalog Read: book"<<endl;

    for(size_t i=0; i<title.size(); i++){
        try{
            d.exxe(exe[i]);
        }catch(duplicate a){
            file1<<a.dup()<<endl;       //exception durumuna gore bilgiler dosyaya yazdirlir
            file1<<sentence[i]<<endl;
        }catch(missing b){
            file1<<b.miss()<<endl;
            file1<<sentence[i]<<endl;
        }
    }
    file1<<title.size()-numm<<" unique entries"<<endl;      //hesaplanan unique sayisi yazdirilir
    ifstream file;
    file.open("commands.txt");
    if(!file.is_open()){
        cout<<"Error opening file"<<endl;    //dosya acilip acilmama kotrolu yapilir
        return ;
    }
    while(!file.eof()){
        file>>temp;
        if(temp=="search"){         //commands dosyasi okunur search ve sort durumuna gore fsakli okunur
            getline (file, temp2);
            a=0;
            for(size_t i=0; i<temp2.length(); i++){
                if(temp2[i]=='"'){
                    for(size_t j=i+1; j<temp2.length(); j++){       //" li ayirma islemi burda da uygulanir
                        if(temp2[j]=='"'){
                             break;
                        }else
                            temp5.push_back(temp2[j]);
                    }
                    if(a==0){
                        temp3=temp5;
                    }else if(a==2){
                        temp4=temp5;
                    }
                    a++;
                    temp5.clear();
                }
            }
            num=find_str(temp3,temp4);      //aranmak istenen kelime ve hangi fielde aranacagi fonksiyona yolanir
            if(num==-1){
                 try{
                    p.exxe(3);      //gelen sonuca gore ya exception yapilir ya dabulunan satir yazdirilir
                }catch(duplicate a){
                }catch(missing b){
                }catch(wrong c ){
                    file1<<c.wro()<<endl;
                    file1<<temp<<""<<temp2<<endl;
                }
            }else{
                file1<<temp<<""<<temp2<<endl;
                file1<<sentence[num]<<endl;
            }
        }else if(temp=="sort"){
            getline(file, temp2);           //sort islemi okunmasi yapilir
            for(size_t i=0; i<temp2.length(); i++){
                if(temp2[i]=='"'){
                    for(size_t j=i+1; j<temp2.length(); j++){
                        if(temp2[j]=='"'){
                             break;
                        }else
                            temp5.push_back(temp2[j]);
                    }
                }
            }
            file1<<temp<<temp2<<endl;       //neye gore sort edilicek is o fonksiyona yollanir
            barr=sort_str(temp5);
            for(size_t i=0; i<barr.size(); i++)
                if(barr[i]>=0 && axa[i]==1)
                     file1<<sentence[barr[i]]<<endl;      //gelen sonuca gore cilgiler sort edilir
            for(size_t i=0; i<barr.size(); i++)
                if(barr[i]>=0 && axa[i]==0)
                    file1<<sentence[barr[i]]<<endl;      //gelen sonuca gore cilgiler sort edilir
        }
    }
    file.close();       //dosyalar kapatilir
    file1.close();
}
void movie::print_file(){
    execpt d,p;
    int a,num;
    vector<int> barr;
    string temp,temp2,temp3,temp4,temp5;
    ofstream file1;
    file1.open("output.txt");
    file1 << "Catalog Read: movie"<<endl;

    for(size_t i=0; i<title.size(); i++){
        try{
            d.exxe(exe[i]);
        }catch(duplicate a){        //exception durumuna gore bilgiler dosyaya yazdirlir
            file1<<a.dup()<<endl;
            file1<<sentence[i]<<endl;
        }catch(missing b){
            file1<<b.miss()<<endl;
            file1<<sentence[i]<<endl;
        }
    }
    file1<<title.size()-numm<<" unique entries"<<endl;                    //hesaplanan unique sayisi yazdirilir

    ifstream file;
    file.open("commands.txt");
    if(!file.is_open()){
        cout<<"Error opening file"<<endl;    //dosya acilip acilmama kotrolu yapilir
        return ;
    }
    while(!file.eof()){
        file>>temp;
        if(temp=="search"){
            getline (file, temp2);       //commands dosyasi okunur search ve sort durumuna gore fsakli okunur
            a=0;
            for(size_t i=0; i<temp2.length(); i++){
                if(temp2[i]=='"'){
                    for(size_t j=i+1; j<temp2.length(); j++){
                        if(temp2[j]=='"'){
                             break;              //" li ayirma islemi burda da uygulanir
                        }else
                            temp5.push_back(temp2[j]);
                    }
                    if(a==0){
                        temp3=temp5;
                    }else if(a==2){
                        temp4=temp5;
                    }
                    a++;
                    temp5.clear();
                }
            }
            num=find_str(temp3,temp4);      //aranmak istenen kelime ve hangi fielde aranacagi fonksiyona yolanir

            if(num==-1){
                 try{
                    p.exxe(3);
                }catch(duplicate a){
                }catch(missing b){          //gelen sonuca gore ya exception yapilir ya dabulunan satir yazdirilir
                }catch(wrong c ){
                    file1<<c.wro()<<endl;
                    file1<<temp<<""<<temp2<<endl;
                }
            }else{
                file1<<temp<<""<<temp2<<endl;
                file1<<sentence[num]<<endl;
            }

        }else if(temp=="sort"){
            getline(file, temp2);
            for(size_t i=0; i<temp2.length(); i++){         //sort islemi okunmasi yapilir
                if(temp2[i]=='"'){
                    for(size_t j=i+1; j<temp2.length(); j++){
                        if(temp2[j]=='"'){
                             break;
                        }else
                            temp5.push_back(temp2[j]);
                    }
                }
            }
            file1<<temp<<temp2<<endl;
            barr=sort_str(temp5);           //neye gore sort edilicek is o fonksiyona yollanir
            for(size_t i=0; i<barr.size(); i++)
                if(barr[i]>=0 && axa[i]==1)
                     file1<<sentence[barr[i]]<<endl;      //gelen sonuca gore cilgiler sort edilir
            for(size_t i=0; i<barr.size(); i++)
                if(barr[i]>=0 && axa[i]==0)
                    file1<<sentence[barr[i]]<<endl;      //gelen sonuca gore cilgiler sort edilir
        }
    }
    file.close();
    file1.close();               //dosyalar kapatilir
}
int book::find_str(string arr, string barr){
    int i=0;

    if(barr=="title"){
        vector<string>::iterator a;                    // ITERATOR TANIMLANDI
        for(a = title.begin(); a != title.end(); a++){
            if(title[i].find(arr)<=title[i].length() && title[i].find(arr)>=0 && exe[i]!=1)
                return i;
             i++;
        }                                   //fonksiyona gelen field adina gore iflere girer
    }else if(barr=="authors"){
        vector<string>::iterator a;                    // ITERATOR TANIMLANDI
        for(a = authers.begin(); a != authers.end(); a++){
            if(authers[i].find(arr)<=authers[i].length() && authers[i].find(arr)>=0 && exe[i]!=1)
                return i;
            i++;
        }                                               //ve uygun oldugu durumda kelime aranir
    }else if(barr=="tags"){
        vector<string>::iterator a;                    // ITERATOR TANIMLANDI
        for(a = tags.begin(); a != tags.end(); a++){
            if(tags[i].find(arr)<=tags[i].length() && tags[i].find(arr)>=0 && exe[i]!=1)
                return i;
             i++;
        }                                   //bulunana kelimenin sirasi retrun edlilr
    }else if(barr=="year"){
        vector<string>::iterator a;                    // ITERATOR TANIMLANDI
        for(a = year.begin(); a != year.end(); a++){
            if(year[i].find(arr)<=year[i].length() && year[i].find(arr)>=0 && exe[i]!=1)
                return i;
             i++;
        }
    }
    return -1;
}
int music::find_str(string arr, string barr){
    int i=0;
    if(barr=="title"){
        vector<string>::iterator a;                    // ITERATOR TANIMLANDI
        for(a = title.begin(); a != title.end(); a++){
            if(title[i].find(arr)<=title[i].length() && title[i].find(arr)>=0 && exe[i]!=1)
                return i;
             i++;                            //fonksiyona gelen field adina gore iflere girer
        }
    }else if(barr=="genre"){
        vector<string>::iterator a;                    // ITERATOR TANIMLANDI
        for(a = genre.begin(); a != genre.end(); a++){
            if(genre[i].find(arr)<=genre[i].length() && genre[i].find(arr)>=0 && exe[i]!=1)
                return i;
            i++;
        }
    }else if(barr=="artists"){
        vector<string>::iterator a;                    // ITERATOR TANIMLANDI
        for(a = artist.begin(); a != artist.end(); a++){
            if(artist[i].find(arr)<=artist[i].length() && artist[i].find(arr)>=0 && exe[i]!=1)
                return i;
             i++;                //ve uygun oldugu durumda kelime aranir
        }
    }else if(barr=="year"){
        vector<string>::iterator a;                    // ITERATOR TANIMLANDI
        for(a = year.begin(); a != year.end(); a++){
            if(year[i].find(arr)<=year[i].length() && year[i].find(arr)>=0 && exe[i]!=1)
                return i;
             i++;
        }                       //bulunana kelimenin sirasi retrun edlilr
    }
    return -1;
}
int movie::find_str(string arr, string barr){
    int i=0;
    if(barr=="title"){
        vector<string>::iterator a;                    // ITERATOR TANIMLANDI
        for(a = title.begin(); a != title.end(); a++){
            if(title[i].find(arr)<=title[i].length() && title[i].find(arr)>=0 && exe[i]!=1)
                return i;
             i++;
        }
    }else if(barr=="genre"){
        vector<string>::iterator a;                    // ITERATOR TANIMLANDI
        for(a = genre.begin(); a != genre.end(); a++){
            if(genre[i].find(arr)<=genre[i].length() && genre[i].find(arr)>=0 && exe[i]!=1)
                return i;
            i++;                                //fonksiyona gelen field adina gore iflere girer
        }
    }else if(barr=="director"){
        vector<string>::iterator a;                    // ITERATOR TANIMLANDI
        for(a = director.begin(); a != director.end(); a++){
            if(director[i].find(arr)<=director[i].length() && director[i].find(arr)>=0 && exe[i]!=1)
                return i;
             i++;                                   //ve uygun oldugu durumda kelime aranir
        }
    }else if(barr=="year"){
        vector<string>::iterator a;                    // ITERATOR TANIMLANDI
        for(a = year.begin(); a != year.end(); a++){
            if(year[i].find(arr)<=year[i].length() && year[i].find(arr)>=0 && exe[i]!=1)
                return i;
             i++;
        }
    }else if(barr=="starring"){
        vector<string>::iterator a;                    // ITERATOR TANIMLANDI
        for(a = starring.begin(); a != starring.end(); a++){
            if(starring[i].find(arr)<=starring[i].length() && starring[i].find(arr)>=0 && exe[i]!=1)
                return i;
             i++;
        }
    }                                   //bulunana kelimenin sirasi retrun edlilr
    return -1;
}

vector<int> book::sort_str(string arr){

    vector<int> barr2;
    vector<string> barr3;
    int temp2,temp3;
    string t;
    if(arr=="year"){
        for(size_t i=0; i<year.size(); i++)
            barr3.push_back(year[i]);
    }else if(arr=="title"){
        for(size_t i=0; i<title.size(); i++)
            barr3.push_back(title[i]);              //eger diger fieldlerde ise vectore o fielflar atanir
    }else if(arr=="authors"){
        for(size_t i=0; i<authers.size(); i++)
            barr3.push_back(authers[i]);
    }else if(arr=="tags"){
        for(size_t i=0; i<tags.size(); i++)
            barr3.push_back(tags[i]);
    }
    for(size_t i=0; i<barr3.size(); i++)
         if(exe[i]==1 || exe[i]==2){
            barr2.push_back(-1);
            axa.push_back(0);
        }else if(barr3[i]==""){
            barr2.push_back(i);         //hepsi kelimeden olustugu icin ayni sort iselmi yapilir
            axa.push_back(0);
        }else{
            barr2.push_back(i);
            axa.push_back(1);
        }
     for (size_t i=1; i<barr3.size(); i++)
        for (size_t j=1; j<barr3.size(); j++)
            if (strcmp(barr3[j - 1].c_str(), barr3[j].c_str()) > 0){
                t=barr3[j - 1];
                barr3[j - 1]=barr3[j];              //buyuk kucuklugu kontrol edlir ve siralanmis vektor dodurulur
                barr3[j]=t;
                temp2=barr2[j-1];
                barr2[j-1]=barr2[j];
                barr2[j]=temp2;
                temp3=axa[j-1];
                axa[j-1]=axa[j];
                axa[j]=temp3;
            }
    return barr2;
}
vector<int> music::sort_str(string arr){
    vector<int> barr2;
    vector<string> barr3;
    int temp2,temp3;
    string t;
    if(arr=="year"){
        for(size_t i=0; i<year.size(); i++)                //sort islemi icin field kendi ifine girer
            barr3.push_back(year[i]);
    }else if(arr=="title"){
        for(size_t i=0; i<title.size(); i++)
            barr3.push_back(title[i]);
    }else if(arr=="artists"){                           //eger diger fieldlerde ise vectore o fielflar atanir
        for(size_t i=0; i<artist.size(); i++)
            barr3.push_back(artist[i]);
    }else if(arr=="genre"){
        for(size_t i=0; i<genre.size(); i++)
            barr3.push_back(genre[i]);
    }
    for(size_t i=0; i<barr3.size(); i++)
         if(exe[i]==1 || exe[i]==2){
            barr2.push_back(-1);
            axa.push_back(0);
        }else if(barr3[i]==""){
            barr2.push_back(i);         //hepsi kelimeden olustugu icin ayni sort iselmi yapilir
            axa.push_back(0);
        }else{
            barr2.push_back(i);
            axa.push_back(1);
        }
     for (size_t i=1; i<barr3.size(); i++)
        for (size_t j=1; j<barr3.size(); j++)
            if (strcmp(barr3[j - 1].c_str(), barr3[j].c_str()) > 0){
                t=barr3[j - 1];
                barr3[j - 1]=barr3[j];
                barr3[j]=t;                                 //buyuk kucuklugu kontrol edlir ve siralanmis vektor dodurulur
                temp2=barr2[j-1];
                barr2[j-1]=barr2[j];
                barr2[j]=temp2;
                temp3=axa[j-1];
                axa[j-1]=axa[j];
                axa[j]=temp3;
            }
    return barr2;
}
vector<int> movie::sort_str(string arr){

    vector<int> barr2;
    vector<string> barr3;
    int temp2,temp3;
    string t;
    if(arr=="title"){
        for(size_t i=0; i<title.size(); i++)
            barr3.push_back(title[i]);
    }else if(arr=="year"){
        for(size_t i=0; i<year.size(); i++)
            barr3.push_back(year[i]);
    }else if(arr=="director"){                  //eger diger fieldlerde ise vectore o fielflar atanir
        for(size_t i=0; i<director.size(); i++)
            barr3.push_back(director[i]);
    }else if(arr=="starring"){
        for(size_t i=0; i<starring.size(); i++)
            barr3.push_back(starring[i]);
    }else if(arr=="genre"){
        for(size_t i=0; i<genre.size(); i++)
            barr3.push_back(genre[i]);                           //hepsi kelimeden olustugu icin ayni sort iselmi yapilir
    }
    for(size_t i=0; i<barr3.size(); i++)
        if(exe[i]==1 || exe[i]==2){
            barr2.push_back(-1);
            axa.push_back(0);
        }else if(barr3[i]==""){
            barr2.push_back(i);
            axa.push_back(0);
        }else{
            barr2.push_back(i);
            axa.push_back(1);
        }
     for (size_t i=1; i<barr3.size(); i++)
        for (size_t j=1; j<barr3.size(); j++)
            if (strcmp(barr3[j - 1].c_str(), barr3[j].c_str()) > 0){
                t=barr3[j - 1];
                barr3[j - 1]=barr3[j];
                barr3[j]=t;                                     //buyuk kucuklugu kontrol edlir ve siralanmis vektor dodurulur
                temp2=barr2[j-1];
                barr2[j-1]=barr2[j];
                barr2[j]=temp2;
                temp3=axa[j-1];
                axa[j-1]=axa[j];
                axa[j]=temp3;
            }
    return barr2;
}
int main(){

    string temp;
    ifstream file;
    file.open("data.txt");
    if(!file.is_open()){
        cout<<"Error opening file"<<endl;    //dosya acilip acilmama kotrolu yapilir
        return 0;
    }
    file>>temp;                     //data dosyasinin ilk satiri okunur
    file.close();

    if(temp=="book"){
        book BOOK;                  //ve okunan bilgiye gore dogru class turunden consructur cagirilir ve bilgiler clasa yazdiilir
        BOOK.print_file();
    }else if(temp=="music"){        //ve diger islemlerin de gerceklesmesi icin classin icnde bulunan print fonksiyonu cauirilir veriler doysaya yazdirlir
        music MUSIC;
        MUSIC.print_file();
    }else if(temp=="movie"){
        movie MOVIE;
        MOVIE.print_file();
    }
    return 0;
}
