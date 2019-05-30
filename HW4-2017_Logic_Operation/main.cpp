#include <iostream>
#include <fstream>
#include<string.h>
#include <stdlib.h>

using namespace std;

class gates{
       protected:
        int input_1;            //input degiskenleri
        int input_2;
    public:
        gates *gate;        //kapilarin bilgilerini tutan class
        gates *outputs;         //outputlarin bilgilerini tutan calss
        gates *inputs;           //inputlarin bilgilerini tutan calss
        gates(string circuitFileName);      //islem constructori
        gates();
        ~gates(){}
        gates(int a, int b){        //input consructuru
            input_1=a;
            input_2=b;}
        int evaluate(gates *a,gates *b,gates *c,string str);        //polymorfism fonksiyonu
        virtual int operation(){return 0;}
        inline string getinputFilename(){return inputfile;}
        inline void setinputFilename(string a){this->inputfile = a;}
        inline string getcircuitFilename(){return circuitfile;}
        inline void setcircuitFilename(string a){this->circuitfile = a;}
        inline string getinputname(){return inputName;}
        inline void setinputname(string a){this->inputName = a;}
        inline string getgatename(){return gateName;}
        inline void setgatename(string a){this->gateName = a;}
        inline string getgatename1(){return gateName1;}
        inline void setgatename1(string a){this->gateName1 = a;}
        inline string getgatename2(){return gateName2;}
        inline void setgatename2(string a){this->gateName2 = a;}
        inline string getgatename3(){return gateName3;}
        inline void setgatename3(string a){this->gateName3 = a;}
        inline string getinput1(){return input1;}
        inline void setinput1(string a){this->input1 = a;}
        inline string getinput2(){return input2;}
        inline void setoutputName(string a){this->outputName = a;}
        inline string getoutputName(){return outputName;}
        inline void setinput2(string a){this->input2 = a;}
        inline int gettype(){return type;}
        inline void settype(int a){this->type = a;}
        inline int getoutput(){return output;}
        inline void setoutput(int a){this->output = a;}
        inline int getoutput1(){return output1;}
        inline void setoutput1(int a){this->output1 = a;}
        inline int getoutput2(){return output2;}
        inline void setoutput2(int a){this->output2 = a;}
        inline int getoutput3(){return output3;}
        inline void setoutput3(int a){this->output3 = a;}
        inline int getvalue(){return value;}
        inline void setvalue(int a){this->value = a;}
        inline int getinput_1(){return input_1;}
        inline void setinput_1(int a){this->input_1 = a;}
        inline int getinput_2(){return input_2;}
        inline void setinput_2(int a){this->input_2 = a;}
        inline int getflop(){return flop;}
        inline void setflop(int a){this->flop = a;}
    private:
        string inputfile;
        string circuitfile;
        string input1;    //bu degisken birinci inputlarin adi icin tutulmustur
        string input2;    //bu degisken ikinci inputlarin adi icin tutulmustur
        string outputName;
        string gateName;    //bu degisken kapilarin adlari icin tutulmustur
        string gateName1;    //bu degisken kapilarin adlari icin tutulmustur
        string gateName2;    //bu degisken kapilarin adlari icin tutulmustur
        string gateName3;    //bu degisken kapilarin adlari icin tutulmustur
        string inputName;    //bu degisken dosyadan alinan 1-0 degerlerinin adlari icin tutulmustur
        int type;      //bu degisken kapilarin tipleri icin tutulmustur
        int value;
        int output;      //bu degisken kapilarin ciktilari icin tutulmustur
        int output1;      //bu degisken kapilarin ciktilari icin tutulmustur
        int output2;      //bu degisken kapilarin ciktilari icin tutulmustur
        int output3;      //bu degisken kapilarin ciktilari icin tutulmustur
        int flop;

};
class orgate:public gates{
    public:
        orgate(int a, int b):gates(a,b){}       //operation fonksiyonu poliformizim yapilmitir
        int operation(){
            return input_1 || input_2;          //or islemi gerceklenir
        }
};
class andgate:public gates{
    public:
        andgate(int a, int b):gates(a,b){}
        int operation(){    //operation fonksiyonu poliformizim yapilmitir
            return input_1 && input_2;  //and islemi gerceklenir
        }
};
class notgate:public gates{
     public:
        notgate(int a, int b):gates(a,b){}
        int operation(){    //operation fonksiyonu poliformizim yapilmitir
            return !input_1;    //not islemi gerceklenir
        }
};
class flipFlop:public gates{
    public:
        flipFlop(int a, int b):gates(a,b){}
        int operation(){        //operation fonksiyonu poliformizim yapilmitir
            if(input_1==input_2)        //flipflop islemi gerceklenir
                return 0;
            else
                return 1;
        }
};
class decoder:public gates{
    public:
        decoder(int a, int b):gates(a,b){}
        int operation(){                        //operation fonksiyonu poliformizim yapilmitir
            if(input_1== 0 && input_2==0){
                return 0;
            }else if(input_1== 0 && input_2==1)         //decoder islemi gerceklenir
                return 1;
            else if(input_1== 1 && input_2==0)
                return 2;
            else if(input_1== 1 && input_2==1)
                return 3;
            return 0;
        }
};

    static int inputNum;   //bu dedisken input.txt dosyasindaki degisken sayisi icin tutulmustur
    static int gateNum;    //bu dedisken circuit.txt dosyasindaki degisken sayisi icin tutulmustur
    static int outputNum;   //bu dedisken outputlarin sayisi icin tutulmustur

gates::gates(): inputfile(""),circuitfile(""),input1(""),input2(""),outputName(""),gateName(""),gateName1(""),gateName2(""),gateName3(""),inputName(""),type(0),value(0),output(0),output1(0),output2(0),output3(0),flop(0){
}

gates::gates(string circuitFileName){
    gates nurullah;
    char c;
    int e=0,i=0;
    inputNum=0;
    outputNum=0;           //dosyalardki degisken sayilari sifilanir
    gateNum=0;
    bool lastLine=false;         //satirlari okumak icin kolaylyk saglamsi icin kullanilmistir
    string gaten, strkapi, str1, str2,output1,output2,output3,output4;  //dosyalardan okunan degiskenleri tutmak icin atanan arraylar
    ifstream file1;
    setcircuitFilename(circuitFileName);
    file1.open(getcircuitFilename());
    if(!file1.is_open()){
        cout<<"Error opening file"<<endl;    //dosya acilip acilmama kotrolu yapilir
        return;
    }
    while(!file1.eof()){
        file1.get(c);
       // cout<<c;
        if(e==1 && c==' '){
            outputNum++;
        }
        if(c==' ' && lastLine == false){     //circuit dosyasi okunur ve kac input ve kapi oldugu sayisi tutulur
            inputNum++;
        }
        if(c=='\n'){
        gateNum++;
        lastLine=true;
        e++;
        }
    }
    file1.close();
    gateNum--;

    gate=new gates[gateNum];
    outputs=new gates[outputNum];
    inputs=new gates[inputNum];
    file1.open(getcircuitFilename());
    if(!file1.is_open()){
        cout<<"Error opening file"<<endl;    //dosya acilip acilmama kotrolu yapilir
        return;
    }
    file1>>str1;
                 //circuit dosyasi bir daha okunur
    for(i=0; i<inputNum; i++){
        file1>>str1;
        inputs[i].setinputname(str1);                                //dosyadan okunan bilgiler durumuna gore ayrilir
    }
    file1>>str1;
    for(i=0; i<outputNum; i++){
        file1>>str1;
        outputs[i].setinputname(str1);                                //dosyadan okunan bilgiler durumuna gore ayrilir
    }
    i = 0;
    while(!file1.eof()){
        file1>>gaten;
        if(gaten=="NOT" || gaten=="FLIPFLOP"){
        file1>>strkapi>>str1;
        }else if(gaten=="AND" || gaten=="OR"){
            file1>>strkapi>>str1>>str2;
       }else if(gaten=="DECODER"){
            file1>>output1>>output2>>output3>>output4>>str1>>str2;
       }
       if(gaten=="OR"){
           gate[i].setgatename(strkapi);       //okunan her kapinin type, input1,input2 ve adlary tutulur
           gate[i].settype(0);           //kapi or kapisiysa typena 0 atanir
           gate[i].setinput1(str1);
           gate[i].setinput2(str2);
       }else if(gaten=="AND"){
            gate[i].setgatename(strkapi);       //okunan her kapinin type, input1,input2 ve adlary tutulur
            gate[i].settype(1);           //kapi and kapisiysa typena 1 atanir
            gate[i].setinput1(str1);
            gate[i].setinput2(str2);
       }else if(gaten=="NOT"){
           gate[i].setgatename(strkapi);
           gate[i].settype(2);           //kapi not kapisiysa typena 2 atanir
           gate[i].setinput1(str1);
       }else if(gaten=="FLIPFLOP"){
            gate[i].setgatename(strkapi);
            gate[i].settype(3);           //kapi flipfolp kapisiysa typena 3 atanir
            gate[i].setinput1(str1);
            gate[i].setflop(0);
       }else if (gaten=="DECODER"){
            gate[i].setgatename(output1);
            gate[i].setgatename1(output2);      //decoderin output isimleri tutulur
            gate[i].setgatename2(output3);
            gate[i].setgatename3(output4);
            gate[i].settype(4);
            gate[i].setinput1(str1);            //kapi decoder kapisiysa typena 4 atanir
            gate[i].setinput2(str2);
        }
        i++;
    }
    file1.close();

    free(inputs);           //class free yapilir
    free(outputs);
    free(gate);
}

int gates::evaluate(gates *a,gates *b,gates *c,string str){
    int i=0;

    for(i=0; i<inputNum; i++){
        if(b[i].getinputname()==str){    //inputun adiyla gatesin inputunun adi karsilastirilir
            return b[i].getvalue();}       //eger aynyysa inputun degeri dondurulur
    }
    for(i=0; i<gateNum; i++){
        if(a[i].getgatename()==str){    //kapinin adiyla gatesin inputunun adi karsilastirilir
            return a[i].getoutput();       //eger aynyysa kapini output degeri dondurulur
        }
    }
    for(i=0; i<gateNum; i++){
        if(a[i].gettype()==4){
            if(a[i].getgatename1()==str)
                return a[i].getoutput1();
            else if(a[i].getgatename2()==str)       //decoderin kapiismlerine esitligi kontrol edilir sonuca gore return yapilir
                return a[i].getoutput2();
            else if(a[i].getgatename3()==str)
                return a[i].getoutput3();
        }
    }
    return 0;
}

int main(){

    int i,d,j=0,f;
    int input_1,input_2;
    gates nurullah("circuit.txt");
    ifstream file;

    nurullah.setinputFilename("input.txt");
    file.open(nurullah.getinputFilename());

    if(!file.is_open()){
        cout<<"Error opening file"<<endl;    //dosya acilip acilmama kotrolu yapilir
        return 0;
    }
    while(!file.eof()){
        for(i=0; i<inputNum; i++){
            file>>d;                                        //dosya icindeki degerlerin inputlarla baglantisi yapilir
            nurullah.inputs[j].setvalue(d);
            j++;
        }
        j=0;
        for(i=0; i<gateNum; i++){
            switch (nurullah.gate[i].gettype()){        //kapilar typelarina gore switche girer
                case 0: {
                    input_1=nurullah.evaluate(nurullah.gate,nurullah.inputs,nurullah.outputs,nurullah.gate[i].getinput1());
                    input_2=nurullah.evaluate(nurullah.gate,nurullah.inputs,nurullah.outputs,nurullah.gate[i].getinput2());         //input1, input2 ve output degerleri atanir
                    orgate  n(input_1,input_2);             //evaluate fonksiyonu inputlarin integer degferlerini dondurur
                    nurullah.gate[i].setoutput(n.operation());          //operation fonksiyonu polymorfism yapar
                    break;
                }
                case 1: {
                    input_1=nurullah.evaluate(nurullah.gate,nurullah.inputs,nurullah.outputs,nurullah.gate[i].getinput1());
                    input_2=nurullah.evaluate(nurullah.gate,nurullah.inputs,nurullah.outputs,nurullah.gate[i].getinput2());
                    andgate a(input_1, input_2);            //evaluate fonksiyonu inputlarin integer degferlerini dondurur
                    nurullah.gate[i].setoutput(a.operation()); //operation fonksiyonu polymorfism yapar
                    break;
                }
                case 2:{
                    input_1=nurullah.evaluate(nurullah.gate,nurullah.inputs,nurullah.outputs,nurullah.gate[i].getinput1());
                    notgate b(input_1, 0);          //evaluate fonksiyonu inputlarin integer degferlerini dondurur
                    nurullah.gate[i].setoutput(b.operation()); //operation fonksiyonu polymorfism yapar
                    break;
                }
                case 3:{
                    input_1=nurullah.evaluate(nurullah.gate,nurullah.inputs,nurullah.outputs,nurullah.gate[i].getinput1());
                    input_2=nurullah.gate[i].getflop();
                    flipFlop c(input_1,input_2);            //evaluate fonksiyonu inputlarin integer degferlerini dondurur
                    nurullah.gate[i].setoutput(c.operation()); //operation fonksiyonu polymorfism yapar
                    nurullah.gate[i].setflop(nurullah.gate[i].getoutput());
                    break;
                }
                case 4:{
                    input_1=nurullah.evaluate(nurullah.gate,nurullah.inputs,nurullah.outputs,nurullah.gate[i].getinput1());
                    input_2=nurullah.evaluate(nurullah.gate,nurullah.inputs,nurullah.outputs,nurullah.gate[i].getinput2());
                    decoder d(input_1,input_2);     //evaluate fonksiyonu inputlarin integer degferlerini dondurur
                    f=d.operation();                 //operation fonksiyonu polymorfism yapar
                    if(f==0){
                        nurullah.gate[i].setoutput(1);
                        nurullah.gate[i].setoutput1(0);         // f sonucuna gore decoderin islem sonuclari uygulanir
                        nurullah.gate[i].setoutput2(0);
                        nurullah.gate[i].setoutput3(0);
                    }else if(f==1){
                        nurullah.gate[i].setoutput(0);
                        nurullah.gate[i].setoutput1(1);
                        nurullah.gate[i].setoutput2(0);
                        nurullah.gate[i].setoutput3(0);
                    }else if(f==2){
                        nurullah.gate[i].setoutput(0);
                        nurullah.gate[i].setoutput1(0);
                        nurullah.gate[i].setoutput2(1);
                        nurullah.gate[i].setoutput3(0);
                    }else if(f==3){
                        nurullah.gate[i].setoutput(0);
                        nurullah.gate[i].setoutput1(0);
                        nurullah.gate[i].setoutput2(0);
                        nurullah.gate[i].setoutput3(1);
                    }
                }
            }
        }
        for(int k=0; k<outputNum; k++){
            for(int l=0; l<gateNum; l++)
                if(nurullah.gate[l].getgatename()==nurullah.outputs[k].getinputname())
                    cout<<nurullah.gate[l].getoutput()<<" ";
        }
        int h;
        for(h=0; h<gateNum; h++){                   //verilen output isimleriyle kapilarin output isimleri karsilastirilir eger output ismi kapininkiyle ayniysa
            if(nurullah.gate[h].gettype()==4)       //kapinin outputu yazdirilir
                break;
        }
        if(nurullah.gate[h].getgatename1()==nurullah.outputs[1].getinputname())
            cout<<nurullah.gate[h].getoutput1()<<" ";
        if(nurullah.gate[h].getgatename2()==nurullah.outputs[2].getinputname())
            cout<<nurullah.gate[h].getoutput2()<<" ";
        if(nurullah.gate[h].getgatename3()==nurullah.outputs[3].getinputname())
            cout<<nurullah.gate[h].getoutput3()<<" ";
            cout<<endl;
    }
    file.close();
}
