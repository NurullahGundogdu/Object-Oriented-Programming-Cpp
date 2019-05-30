#include "linkedlist.h"
#include "queue.h"
#include "list.h"
#include "collection.h"

namespace collec{


    template<class E,class Container>
    LinkedList<E,Container>::LinkedList()
    {
        //ctor
    }

    template<class E,class Container>
    LinkedList<E,Container>::~LinkedList()
    {
        //dtor
    }

    template<class E,class Container>
    LinkedList<E,Container>::iterator()const{
    }

    template<class E,class Container>
    void LinkedList<E,Container>::add(const E e){
        data.push_back(e);
    }

    template<class E,class Container>
    void LinkedList<E,Container>::addAll(const Collection<E,Container> &c){
        for(int i=0; i<c.size(); i++){
            this.add(c[i]);
        }
    }

    template<class E,class Container>
    void LinkedList<E,Container>::clear(){
        data.clear();
    }

    template<class E,class Container>
    bool LinkedList<E,Container>::contains(const E e)const{
        for(int i=0; i<data.size(); i++){
            if(data[i] == e)
                return true;
        }
        return false;
    }

    template<class E,class Container>
    bool LinkedList<E,Container>::containsAll(const Collection<E,Container> &c)const{
        for(int i=0; i<c.size(); i++){
            if(this->contains(c[i]) == false)
                return false;
        }
        return true;
    }

    template<class E,class Container>
    bool LinkedList<E,Container>::isEmpty()const{
        if(data.size() == 0)
            return true;
        else
            return false;
    }

    template<class E,class Container>
    void LinkedList<E,Container>::remove(const E e){
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
    void LinkedList<E,Container>::removeAll(const Collection<E,Container> &c){
        for(int i = 0; i < c->size(); i++){
                if(this->contains(c[i]))
                    this->remove(c[i]);
            }
    }

    template<class E,class Container>
    void LinkedList<E,Container>::retainAll(const Collection<E,Container> &c){
        LinkedList<E,Container> temp;

        for(int i = 0; i < c->size(); i++){
            if(this->contains(c[i])){
                temp.add(c[i]);
            }
        }
        return temp;
    }

    template<class E,class Container>
    int LinkedList<E,Container>::size()const{
        return data.size();
    }

    template<class E,class Container>
    void LinkedList<E,Container>::element(){
        return data.front();
    }

    template<class E,class Container>
    void LinkedList<E,Container>::offer(const E e){
        data.push_back(e);
    }

    template<class E,class Container>
    void LinkedList<E,Container>::poll(){
        E temp = data.front();
        data.erase(data.begin());
       // return temp;
    }

}
