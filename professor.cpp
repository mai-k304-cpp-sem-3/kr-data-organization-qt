#include <iostream>
#include <fstream>
#include <iomanip>

#include "professor.h"

using namespace std;

// Добавление нового элемента в список
void addPageProfessor(professor** start, string _name, string _surname) {
    bool isNew = false; // Новый ли список
    professor* current = *start;
	int i = 1;

	// Если списка нет то создаем его первый элемент
    if (*start == NULL) {
		*start = new professor;
		isNew = true;
	}
    current = *start;

	//Если список не новый, то идем в конец и создаем новый элемент в конце списка
    if (!isNew) {
		while (current->next != NULL) {
			current = current->next;
		}
		i = current->id + 1;
		current->next = new professor;
		current = current->next;
    }
    current->id = i++;
	current->name = _name;
    current->surname = _surname;
}

// Удаление определённого элемента в списке
void deletePageProfessor(professor** start, int _id) {
	professor* current = *start;
	professor* del; // Указатель на удаляемый элемент
	if (start) {
        if (_id == 0) {
			del = *start;
			*start = (*start)->next;
			delete del;
        } else {
            while ((current->next) && (current->next->id != _id)) {
				current = current->next;
			}
			if (current->next) {
				del = current->next;
                if (current->next->next) {
                    current->next = current->next->next;
                } else {
                    current->next = NULL;
                }
				delete del;
            }
		}
	}
}

// Удаление списка
void deleteListProfessor(professor** start) {
    professor* current = *start; // Вспомогательный эллемент для движения по списку
	while (current != NULL) { // Пока есть элемент
        current = current->next; // Движение по списку
        delete *start; // Удаление корня
        *start = current; // Обозначения первого элемента списка как корень
	}
}

// Считывания списка из файла
void fileReadProfessor(professor** start, string fileName) {
	ifstream ifs(fileName); // Открытие файла
	if (ifs.is_open()) {
		bool isNew = false; // Флаг, говорящий нам о том новый ли это список
		professor* current; // Текущий элемент
		string temp; // Временная переменная 
		if (*start == NULL) { // Если список новый, то создаем его
			*start = new professor;
			isNew = true; // И запоминаем что он новый
		}
		current = *start; // Используем вспомогательный указатель, что бы двигаться по списку
		if (!isNew) { // Если же список не новый то идем до конца списка
			while (current->next != NULL) {
				current = current->next;
			}
		}
        int i = 0;
		while (!ifs.eof()) { // И если он открылся считываем данные из него
			ifs >> temp;
			if (temp == "") { // Проверка на то, считается ли хоть что - нибудь
				break;
			}
			if (!isNew) { // Если список не новый, то создаем новый пустой элемент 
				current->next = new professor;
				current = current->next; // И переходим на него
			}
			else {
				isNew = false;
			}
            if (!ifs.eof()) { // И если файл не кончился то считываем данные в наш пустой элемент
                current->id = i;
				temp = "";
				ifs >> current->name;
                ifs >> current->surname;
                i++;
			}
		}
    } else {
		cout << "Файл не найден\n.";
	}
}

// Установка имени
void setNameProfessor(professor* start, int _id, string _name) {
	professor* current = start;
    while ((current->next) && (current->id != _id)) {
		current = current->next;
	}
    if (current->id == _id) {
        current->name = _name;
    }
}

// Установка фамилии
void setSurnameProfessor(professor* start, int _id, string _surname) {
    professor* current = start;
    while ((current->next) && (current->id != _id)) {
        current = current->next;
    }
    if (current->id == _id) {
        current->surname = _surname;
    }
}

// Поиск элемента по id
professor* givePageProfessor(professor* start, int _id) {
    professor* current = start;
    while ((current->next) && (current->id != _id)) {
        current = current->next;
    }
    if (current->id == _id) {
        return current;
    } else {
        return NULL;
    }
}

// Поиск элемента по имени
professor* findNameProfessor(professor* start, string nameKey) {
    professor* current = start;
    while ((current->next) && (current->name != nameKey)) {
        current = current->next;
    }
    if (current->name == nameKey) {
        return current;
    } else {
        return NULL;
    }
}

// Поиск элемента по фамилии
professor* findSurnameProfessor(professor* start, string surnameKey) {
    professor* current = start;
    while ((current->next) && (current->name != surnameKey)) {
        current = current->next;
    }
    if (current->surname == surnameKey) {
        return current;
    } else {
        return NULL;
    }
}
