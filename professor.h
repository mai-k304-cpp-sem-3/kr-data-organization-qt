#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <string> // Подключение библиотеки для работы со string

using namespace std;

struct professor { // Структура преподователя
    int id; // Индекс
    professor* next; // Следующий элемент списка
    string name; // Имя преподователя
    string surname; // Фамилия преподователя
};

// Добавление нового элемента в список
void addPageProfessor(professor** start, string _name, string _surname);

// Удаление определённого элемента в списке
void deletePageProfessor(professor** start, int _id);

// Удаление списка
void deleteListProfessor(professor** start);

// Считывания списка из файла
void fileReadProfessor(professor** start, string fileName);

// Установка имени
void setNameProfessor(professor* start, int _id, string _name);

// Установка фамилии
void setSurnameProfessor(professor* start, int _id, string _surname);

// Поиск элемента по id
professor* givePageProfessor(professor* start, int _id);

// Поиск элемента по имени
professor* findNameProfessor(professor* start, string nameKey);

// Поиск элемента по фамилии
professor* findSurnameProfessor(professor* start, string surnameKey);

#endif
