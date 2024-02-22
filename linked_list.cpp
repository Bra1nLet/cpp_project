#include "linked_list.h"
#include <iostream>

// Додає новий вузол з вказаним значенням в кінець списку
PNODE add_element_to_list(PNODE head, int data)
{
    // Створення нового вузла
    PNODE newNode = new NODE;
    newNode->data = data;
    newNode->next = nullptr;

    // Перевірка, чи список порожній
    if (head == nullptr)
    {
        head = newNode; // Якщо порожній, новий вузол стає головою списку
    }
    else
    {
        // Якщо список не порожній, додаємо новий вузол в кінець
        PNODE current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
    }

    return head;
}

// Повертає розмір списку
int get_size_list(const PNODE head)
{
    int count = 0;
    PNODE current = head;
    // Проходження через весь список та підрахунок елементів
    while (current != nullptr)
    {
        count++;
        current = current->next;
    }
    return count;
}

// Повертає елемент списку за індексом
const PNODE get_element_from_list(const PNODE head, int index)
{
    PNODE current = head;
    int count = 0;
    // Пошук вузла за вказаним індексом
    while (current != nullptr && count < index)
    {
        count++;
        current = current->next;
    }
    return current;
}

// Видаляє елемент списку за індексом
PNODE delete_element_from_list(PNODE head, int index)
{
    // Перевірка коректності індексу та наявності елементів у списку
    if (index < 0 || head == nullptr)
    {
        return head;
    }

    // Видалення першого елемента списку
    if (index == 0) {
        PNODE temp = head->next;
        delete head;
        return temp;
    }

    // Пошук елемента за попереднім індексом
    PNODE current = head;
    int count = 0;
    while (current != nullptr && count < index - 1)
    {
        count++;
        current = current->next;
    }

    // Перевірка коректності індексу та наявності елемента
    if (current == nullptr ||  current->next == nullptr)
    {
        return head;
    }

    // Видалення елемента зі списку
    PNODE temp = current->next;
    current->next = temp->next;
    delete temp;

    return head;
}

// Очищає список, видаляючи всі його елементи
PNODE clear_list(PNODE head)
{
    // Видалення усіх елементів зі списку
    while (head != nullptr)
    {
        PNODE temp = head;
        head = head->next;
        delete temp;
    }
    return nullptr;
}

// Виводить значення всіх елементів списку на екран
void print_list(const PNODE head)
{
    PNODE current = head;
    // Виведення значень елементів списку
    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}