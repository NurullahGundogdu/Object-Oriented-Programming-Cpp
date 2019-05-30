#include <iostream>
#include <fstream>
#include<string.h>
using namespace std;

class base{
    public:
        base(){}
        void assignnment(string arr, base *a);
        void Delete(string arr);
        void Copy(string arr, string arr2);
        void Move(string arr, string arr2);
        int type;
        string data;
        base *next;
        base *next1;
    private:
};


class file:public base{
    public:

    private:
};

class directory:public base{
    public:
        string data;
        base *next1;

    private:

};

base *head;


int main(){

    base *arr=new base;

    char str[100],str1[20];

    string a(str);
    ifstream file;
    file.open("files.txt");

    if(!file.is_open()){
        cout<<"Error opening file"<<endl;    //dosya acilip acilmama kotrolu yapilir
        return 0;
    }
    while(!file.eof()){
        file>>str;
        a=str;
    }


}
void base::assignnment(string arr, base *a){

    if(a->type==1){
        base *newlist=new base;     // eklenecek nense icin yer acilir.
        newlist->data=arr;         // data ve next pointer lar atanir.
        newlist->next=0;
        base *p=a;             // listede dolasicak bir pointer tanimlanir.

        if(p==0)
            a=newlist;
        else{
            while(p->next!=0)
                p=p->next;
            p->next=newlist;    // en sona gelindiginde eleman eklenmis olur.
        }
    }else{
        base *newlist=new base;     // eklenecek nense icin yer acilir.
        newlist->data=arr;         // data ve next pointer lar atanir.
        newlist->next1=0;
        base *p=a;             // listede dolasicak bir pointer tanimlanir.

        if(p==0)
            a=newlist;
        else{
            while(p->next1!=0)
                p=p->next1;
          p->next1=newlist;    // en sona gelindiginde eleman eklenmis olur.
        }
    }
}

void base::Delete(string arr){

    base *p=head;
    base *temp=head;
    p=p->next;                      // diger durumlarin siindigi yer .

    while(p){
        if(p->data==arr){       //verilen string listede aranir
            temp->next=p->next;     //bulundugunda bir sonraki pointerina atanir
            break;
        }
        p=p->next;
        temp=temp->next;
    }
    delete p;   //bulunan parca silinir

}

void base::Copy(string arr, string arr2){

    base *p=head;
    base *temp=head;
    p=p->next;                      // kopyalama icin farkli lissteler tutulur
    temp=temp->next;
    while(p){
        if(p->data==arr){//verilen string listede aranir
            while(temp){
                if(temp->data==arr2){       //diger string de listede aranir
                    p->next=temp;
                    break;
                }
                temp=temp->next;    //ikisi de bulununca biri digerinin sonunakopyalnir
            }
            break;
        }
        p=p->next;
    }

}
void base::Move(string arr,string arr2){

    base *p=head;
    base *temp=head;
    p=p->next;                      // kopyalama icin farkli lissteler tutulur
    temp=temp->next;

    while(p){
        if(p->data==arr){       //verilen string listede aranir
            while(temp){
                if(temp->data==arr2){
                    p->next=temp;   //diger string de listede aranir
                    break;
                }
                temp=temp->next;
            }       //ikisi de bulununca biri digerinin sonunakopyalnir
            break;
        }
        p=p->next;
    }

    delete temp;//kopyalanan liste silinir
}
