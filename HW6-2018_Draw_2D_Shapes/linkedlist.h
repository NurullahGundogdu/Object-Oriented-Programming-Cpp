#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "queue.h"
#include "list.h"
#include "collection.h"

using namespace std;
namespace collec{


    template<class E,class Container >
    class LinkedList:public List<E, Container> , public Queue<E, Container>
    {
        public:
            LinkedList();
            virtual ~LinkedList();

            iterator() const override;
            void add(const E e)override;
            void addAll(const Collection<E,Container> &c)override;
            void clear()override;
            bool contains(const E e) const override;
            bool containsAll(const Collection<E,Container> &c) const override;
            bool isEmpty() const override;
            void remove(const E e)override;
            void removeAll(const Collection<E,Container> &c) override;
            void retainAll(const Collection<E,Container> &c) override;
            int size() const override;
            //add(E e);
            void element() override;
            void offer(const E e) override;
            void poll() override;

        protected:

        private:
            vector<E> data;
    };
}
#endif // LINKEDLIST_H
