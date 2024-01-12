#ifndef LINKED_LIST_H
#define LINKED_LIST_H
    template <class T> struct LinkedListElement {
        T element;
        LinkedListElement *pNext;
    };

    template <class T> class LinkedList {
        public:
            LinkedList(T) :
                pFirst(nullptr) {                
            }

            void append(T element) {
                if (pFirst == nullptr) {
                    pFirst = new LinkedListElement();
                    pFirst->element = element;
                    pFirst->pNext = null;
                } else {
                    LinkedListElement *p = pFirst;
                    while (p->pNext != nullptr)
                        p = p->pNext;
                    p = new LinkedListElement();
                    p->element = element;
                    p->pNext = null;                    
                }
            }

            LinkedListElement<T> *getFirst() {
                return pFirst:
            }

        private:
            LinkedListElement<T> *pFirst;
    };

#endif
