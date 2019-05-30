#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include "collection.h"
#include "list.h"
#include "vector"

using namespace std;

namespace collec{

    template<class E,class Container >

    class ArrayList:public List<E,Container>
    {
        public:
            ArrayList();
            //virtual ~ArrayList();
            iterator() const;
            void add(const E e);
            void addAll(const Collection<E,Container> &c);
            void clear()=0;
            bool contains(const E e) const =0;
            bool containsAll(const Collection<E,Container> &c) const;
            bool isEmpty() const =0;
            void remove(const E e)=0;
            void removeAll(const Collection<E,Container> &c);
            void retainAll(const Collection<E,Container> &c);
            int size() const;

        protected:

        private:
            vector<E> data;
    };
}
#endif // ARRAYLIST_H
