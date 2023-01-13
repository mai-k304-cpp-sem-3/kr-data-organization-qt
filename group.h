#ifndef GROUP_H
#define GROUP_H

#include <string> // Подключение библиотеки для работы со string

using namespace std;

struct group { // Структура группы
    int id; // Индекс
    group* next; // Следующий элемент списка
    int count; // Кол-во учеников в группе
    string name; // Название группы
};

// Добавление нового элемента в список
void addPageGroup(group** start, int _count, string _name);

// Удаление определённого элемента в списке
void deletePageGroup(group** start, int _id);

// Удаление списка
void deleteListGroup(group** start);

// Считывания списка из файла
void fileReadGroup(group** start, string fileName); // Считывания списка из файла

// Установка количества учеников
void setCountGroup(group* start, int _id, int _count);

// Установка названия группы
void setNameGroup(group* start, int _id, string _name);

// Поиск элемента по id
group* givePageGroup(group* start, int _id);

// Поиск элемента по количеству учеников
group* findCountGroup(group* start, int countKey);

// Поиск элементов по названию группы
group* findNameGroup(group* start, string nameKey);

#endif
