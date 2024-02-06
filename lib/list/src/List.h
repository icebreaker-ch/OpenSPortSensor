#ifndef LIST_H
#define LIST_H

template <class T> class List {
    template <class E> struct Node {
        E item;
        Node<E> *pNext;
    };

    public:
        List<T>() :
            pHead(nullptr) {
        }

        void add(const T &item) {
            Node<T> *pNode = new Node<T>();
            pNode->item = item;
            pNode->pNext = pHead;
            pHead = pNode;
        }

        Node<T> *getHead() {
            return pHead;
        }
        
    private:
        Node<T> *pHead;
};

#endif
