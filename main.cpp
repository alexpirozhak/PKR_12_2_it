#include <iostream>

using namespace std;

// Структура для вузла списку
struct Node {
    int data;
    Node* next;
};

// Функція для додавання елемента в кінець списку
void append(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Функція для друку списку
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Функція для обчислення кількості елементів з непарними значеннями
int countOddElements(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data % 2 != 0) {
            count++;
        }
        temp = temp->next;
    }
    return count;
}

// Функція для ручного введення значень списку
void inputList(Node*& head) {
    int n, value;
    cout << "Введіть кількість елементів: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Введіть значення елемента " << i + 1 << ": ";
        cin >> value;
        append(head, value);
    }
}

// Головна функція
int main() {
    Node* list = nullptr;
    int choice;

    cout << "Виберіть опцію:" << endl;
    cout << "1. Вручну ввести значення" << endl;
    cout << "2. Використати заздалегідь визначені значення" << endl;
    cout << "Ваш вибір: ";
    cin >> choice;

    if (choice == 1) {
        inputList(list);
    } else if (choice == 2) {
        append(list, 1);
        append(list, 2);
        append(list, 3);
        append(list, 4);
        append(list, 5);
    } else {
        cout << "Неправильний вибір" << endl;
        return 1;
    }

    // Друк списку
    cout << "Список: ";
    printList(list);

    // Обчислення кількості елементів з непарними значеннями
    int oddCount = countOddElements(list);
    cout << "Кількість елементів з непарними значеннями: " << oddCount << endl;

    return 0;
}
