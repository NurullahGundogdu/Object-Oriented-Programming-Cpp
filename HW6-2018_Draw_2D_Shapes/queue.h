#ifndef QUEUE_H
#define QUEUE_H
#include "collection.h"


namespace collec{

    template<class E,class Container>

    class Queue:public Collection<E,Container>
    {
        public:
            Queue(){}
            virtual ~Queue(){}
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
            //add(E e);
            virtual void element()=0;
            virtual void offer(E e)=0;
            virtual void poll()=0;

    };
}
#endif // QUEUE_H
