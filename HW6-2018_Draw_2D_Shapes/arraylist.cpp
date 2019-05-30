#include "arraylist.h"
#include "collection.h"
#include "list.h"

namespace collec{


    template<class E,class Container>
    ArrayList<E,Container>::ArrayList():List<E,Container>()
    {
        //ctor
    }

    template<class E,class Container>
    ArrayList<E,Container>::iterator() const{
    }

    template<class E,class Container>
    void ArrayList<E,Container>::add(const E e){
        //this->Container.push_back(e);
       // data.push_back(e);
    }



    template<class E,class Container>
    void ArrayList<E,Container>::addAll(const Collection<E,Container> &c){

        for(int i = 0; i < c.size(); i++)
            data.push_back(c[i]);

    }

    template<class E,class Container>
    void ArrayList<E,Container>::clear(){
        data.clear();

    }

    template<class E,class Container>
    bool ArrayList<E,Container>::contains(const E e)const{

        for(int i = 0; i < data.size(); i++){
            if(data[i] == e)
                return true;
        }
        return false;
    }

    template<class E,class Container>
    bool ArrayList<E,Container>::containsAll(const Collection<E,Container> &c)const{
        if(data.size() < c.size())
            return false;

        for(int i = 0; i < c.size(); i++){
            if(this->contains(c[i]) == false)
                return false;
        }

        return true;
    }

    template<class E,class Container>
    bool ArrayList<E,Container>::isEmpty()const{

        if(data.size() == 0)
            return true;

        return false;

    }

    template<class E,class Container>
    void ArrayList<E,Container>::remove(const E e){
        int index;
        if(this->contains(e) == true){
            for(int i = 0; i < data.size(); i++){
                if(data[i] == e){
                    index = i;
                }
            }

            data.erase (data.begin()+index);
        }
    }



    template<class E,class Container>
    void ArrayList<E,Container>::removeAll(const Collection<E,Container> &c){

            for(int i = 0; i < c->size(); i++){
                if(this->contains(c[i]))
                    this->remove(c[i]);
            }


    }

    template<class E,class Container>
    void ArrayList<E,Container>::retainAll(const Collection<E,Container> &c){
           for(int i = 0; i < c->size(); i++){
                if(this->contains(c[i])==true){
                }
                else
                    this->remove();
            }
    }

    template<class E,class Container>
    int ArrayList<E,Container>::size()const{

        return data.size();
    }

}
