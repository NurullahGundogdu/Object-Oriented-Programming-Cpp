#ifndef LIST_H
#define LIST_H
#include "collection.h"

namespace collec{

    template<class E,class Container = std::vector<E> >

    class List:public Collection<E,Container>
    {
        public:
            List(){}
            virtual ~List(){}
            virtual iterator() const =0;
            virtual void add(const E e)=0;
            virtual void addAll(const Collection<E,Container> &c)=0;
            virtual void clear()=0;
            virtual bool contains(const E e) const =0;
            virtual bool containsAll(const Collection<E,Container> &c) const =0;
            virtual bool isEmpty() const =0;
            virtual void remove(const E e)=0;
            virtual void removeAll(const Collection<E,Container> &c)=0;
            virtual void retainAll(const Collection<E,Container> &c)=0;
            virtual int size() const =0;

    };

}
#endif // LIST_H
