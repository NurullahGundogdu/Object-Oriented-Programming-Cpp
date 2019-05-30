#include "hashset.h"

namespace collec{


    template<class E,class Container>

    HashSet<E,Container>::HashSet()
    {
        //ctor
    }
    template<class E,class Container>
    HashSet<E,Container>::~HashSet()
    {
        //dtor
    }
    template<class E,class Container>
    HashSet<E,Container>::iterator()const{
    }

    template<class E,class Container>
    void HashSet<E,Container>::add(const E e){
        data.insert(e);
    }

    template<class E,class Container>
    void HashSet<E,Container>::addAll(const Collection<E,Container> &c){
        for(int i=0; i<c.size(); i++){
            this->add(c[i]);
        }
    }

    template<class E,class Container>
    void HashSet<E,Container>::clear(){
        data.clear();
    }

    template<class E,class Container>
    bool HashSet<E,Container>::contains(const E e)const{
        for(int i = 0; i < data.size(); i++){
            if(data[i] == e)
                return true;
        }
        return false;
    }

    template<class E,class Container>
    bool HashSet<E,Container>::containsAll(const Collection<E,Container> &c)const{
        if(data.size() < c.size())
            return false;

        for(int i = 0; i < c.size(); i++){
            if(this->contains(c[i]) == false)
                return false;
        }

        return true;
    }

    template<class E,class Container>
    bool HashSet<E,Container>::isEmpty()const{
        return data.empty();
    }

    template<class E,class Container>
    void HashSet<E,Container>::remove(const E e){
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
    void HashSet<E,Container>::removeAll(const Collection<E,Container> &c){
        for(int i = 0; i < c->Container.size(); i++){
                if(this->contains(c[i]))
                    this->remove(c[i]);
            }
    }

    template<class E,class Container>
    void HashSet<E,Container>::retainAll(const Collection<E,Container> &c){
            HashSet<E,Container> temp;

            for(int i = 0; i < c->size(); i++){
                if(this->contains(c[i])){
                    temp.add(c[i]);
                }
            }
            return temp;
    }

    template<class E,class Container>
    int HashSet<E,Container>::size()const{
        return data.size();
    }

}
