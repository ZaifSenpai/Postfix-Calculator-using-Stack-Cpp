#include <iostream>
#include "Node.cpp"

using namespace std;

class LinkedList {
    public:
    	
        LinkedList() {
            headNode = new Node();
            headNode->setNext(NULL);
            currentNode = NULL;
            size = 0;
            prevCounter = 0;
        }

        void add(int addObject) {
            Node* newNode = new Node();
            newNode->set(addObject);
        
            if (currentNode != NULL) {
                newNode->setNext(currentNode->getNext());
                currentNode->setNext( newNode );
                lastCurrentNode = currentNode;
                currentNode = newNode;
            }
           else {
                newNode->setNext(NULL);
                headNode->setNext(newNode);
                lastCurrentNode = headNode;
                currentNode =  newNode;
            }
            size++;
            prevCounter = 0;
        }

        int get() {
            if (currentNode != NULL)
                return currentNode->get();
        }
        
        bool next() {
            if (currentNode == NULL) return false;

            lastCurrentNode = currentNode;
            currentNode = currentNode->getNext();
            prevCounter = 0;
            if (currentNode == NULL || size == 0) 
                return false;
            else
                return true;
        }

        bool next(int n) {
            bool b;
			for (int i = 0; i < n; i++)
            	b = next();
            return b;
        }
        
        bool previous() {
        	if (currentNode != headNode && prevCounter != 1) {
        		currentNode = lastCurrentNode;
        		prevCounter = 1;
			}
			return 0;
		}

        void start() {
            lastCurrentNode = currentNode;
            currentNode = headNode->getNext();
            prevCounter = 0;
        }

        void remove() {
            if(currentNode != headNode) {
                lastCurrentNode->setNext(currentNode->getNext());
                delete currentNode;
                currentNode = lastCurrentNode->getNext();
                size--;
            }
        };

        int length() { 
            return size; 
        }

    private:
        int size;
        bool prevCounter; // To prevent consecutive previous functions()
        Node *headNode;
        Node *currentNode, *lastCurrentNode;
};
