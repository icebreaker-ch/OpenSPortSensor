#ifndef LINKED_LIST_H
#define LINKED_LIST_H
    template <class T> struct LinkedListElement {
        T element;
        LinkedListElement *pNext;
    };

    template <class T> class LinkedList {
        public:
            LinkedList() :
                pHead(nullptr) {                
            }

            ~LinkedList() {
                LinkedListElement<T> *p = pHead;
                while (p) {
                    LinkedListElement<T> *pNext = p->pNext;
                    delete p;
                    p = pNext;
                }
            }

            void add(T element) {
                LinkedListElement<T> *p = new LinkedListElement<T>();
                p->element = element;
                p->pNext = pHead;
                pHead = p;
            }

            LinkedListElement<T> *getHead() {
                return pHead;
            }

        private:
            LinkedListElement<T> *pHead;
    };

#endif
