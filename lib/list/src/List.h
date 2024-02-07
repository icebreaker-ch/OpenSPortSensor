#ifndef LIST_H
#define LIST_H

template <class T> class List {
    public:
        template <class E> struct Node {
            E item;
            Node<E> *pNext;
        };

        struct Iterator {
            Iterator(Node<T> *pNode) :
                pNode(pNode) { }

            T &operator*() {
                return pNode->item;
            }

            Iterator &operator++() {    
                pNode = pNode->pNext;
                return *this;            
            }

            bool operator==(const Iterator &other) {
                return pNode == other.pNode;
            }

            bool operator!=(const Iterator &other) {
                return pNode != other.pNode;
            }
            Node<T> *pNode;
        };


        List<T>() :
            pHead(nullptr) {
        }

        void add(const T &item) {
            Node<T> *pNode = new Node<T>();
            pNode->item = item;
            pNode->pNext = pHead;
            pHead = pNode;
        }

        Iterator begin() {
            return Iterator(pHead);
        }

        Iterator end() {
            return Iterator(nullptr);
        }

    private:
        Node<T> *pHead;
};

#endif
