#ifndef LIST_H
#define LIST_H

/**
 * A very minimal List containr class with an iterator.
 * Adding items at the head of the list (prepend) for simplicity, so
 * they are iterated in reverse order!
 * 
*/
template <class T> class List {
    public:
        template <class E> struct Node {
            E item;
            Node<E> *pNext;
        };

        struct Iterator {
            explicit Iterator(Node<T> *pNode) :
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
