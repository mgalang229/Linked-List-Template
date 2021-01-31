#ifndef FLOATLIST_H
#define FLOATLIST_H

using namespace std;

template <class T>
class FloatList {
	private:
		struct ListNode {
			T value;
			struct ListNode *next;
		};
		ListNode *head;
	public:
		FloatList();
		~FloatList();
		void appendNode(T);
		void insertNode(T);
		void deleteNode(T);
		void displayList();
};

template <class T>
FloatList<T>::FloatList() {
	// constructor
	head = NULL;
}

template <class T>
FloatList<T>::~FloatList() {
	// destructor
	ListNode *nodePtr, *nextNode;
	nodePtr = head;
	while (nodePtr != NULL) {
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
	cout << "Linked List has been DESTROYED!" << endl;
}

template <class T>
void FloatList<T>::appendNode(T num) {
	ListNode *newNode, *nodePtr;
	newNode = new ListNode;
	newNode->value = num;
	newNode->next = NULL;
	if (!head) {
		head = newNode;
	} else {
		nodePtr = head;
		while (nodePtr->next) {
			nodePtr = nodePtr->next;
		}
		nodePtr->next = newNode;
	}
	cout << "Input has been APPENDED!" << endl;
}

template <class T>
void FloatList<T>::insertNode(T num) {
	ListNode *newNode, *nodePtr, *previousNode;
	newNode = new ListNode;
	newNode->value = num;
	if (!head) {
		head = newNode;
		newNode->next = NULL;
	} else {
		nodePtr = head;
		previousNode = NULL;
		while (nodePtr != NULL && nodePtr->value < num) {
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		if (previousNode == NULL) {
			head = newNode;
			newNode->next = nodePtr;
		} else{
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}
	}
	cout << "Input has been INSERTED!" << endl;
}

template <class T>
void FloatList<T>::deleteNode(T num) {
	ListNode *nodePtr, *previousNode;
	int found = 0;
	if (!head) {
		return;
	}
	if (head->value == num) {
		nodePtr = head->next;
		delete head;
		head = nodePtr;
		found = 1;
	} else {
		nodePtr = head;
		previousNode = NULL;
		while (nodePtr != NULL && nodePtr->value != num) {
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		if (nodePtr != NULL) {
			previousNode->next = nodePtr->next;
			delete nodePtr;
			cout << "Input has been DELETED!" << endl;
			found = 1;
		}
	}
	if (found == 0) {
		cout << "Input not in the list!" << endl;
	}
}

template <class T>
void FloatList<T>::displayList() {
	ListNode *nodePtr;
	if (head == NULL) {
		cout << "The list is empty!" << endl;
	} else {
		nodePtr = head;
		while (nodePtr) {
			cout << nodePtr->value << endl;
			nodePtr = nodePtr->next;
		}
	}
}

#endif
