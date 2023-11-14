#include <iostream>
#include <fstream>
#include <iomanip>

#include "group.h"

using namespace std;



// Добавление нового элемента в список
void addPageGroup(group** start, int _count, string _name) { // Добавление нового элемента в список
	bool isNew = false; // Новый ли список
	group* current;
	int i = 1;

	// Если списка нет то создаем его первый элемент
	if (*start == NULL) {
		*start = new group;
		isNew = true;
	}
	current = *start;

	//Если список не новый, то идем в конец и создаем новый элемент в конце списка
	if (!isNew) {
		while (current->next != NULL) {
			current = current->next;
		}
		i = current->id + 1;
		current->next = new group;
		current = current->next;
	}
	current->id = i++;
	current->count = _count;
	current->name = _name;
}

// Удаление определённого элемента в списке
void deletePageGroup(group** start, int _id) {
    group* current = *start;
    group* del; // Указатель на удаляемый элемент
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
void deleteListGroup(group** start) {
	group* current = *start; // Вспомогательный эллемент для движения по списку
	while (current != NULL) { // Пока есть элемент
		current = current->next; // Движение по списку
		delete *start; // Удаление корня
		*start = current; // Обозначения первого элемента списка как корень
	}
}

// Считывания списка из файла
void fileReadGroup(group** start, string fileName) { // Считывания списка из файла
	ifstream ifs(fileName); // Открытие файла
	if (ifs.is_open()) {
		bool isNew = false; // Флаг, говорящий нам о том новый ли это список
		group* current; // Текущий элемент
		string temp; // Временная переменная 
		if (*start == NULL) { // Если список новый, то создаем его
			*start = new group;
			isNew = true; // И запоминаем что он новый
		}
		current = *start; // Используем вспомогательный указатель, что бы двигаться по списку
		if (!isNew) { // Если же список не новый то идем до конца списка
			while (current->next != NULL) {
				current = current->next;
			}
		}
		while (!ifs.eof()) { // И если он открылся считываем данные из него
			ifs >> temp;
			if (temp == "") { // Проверка на то, считается ли хоть что - нибудь
				break;
			}
			if (!isNew) { // Если список не новый, то создаем новый пустой элемент 
				current->next = new group;
				current = current->next; // И переходим на него
			}
			else {
				isNew = false;
			}
			if (!ifs.eof()) { // И если файл не кончился то считываем данные в наш пустой элемент
				current->id = stoi(temp);
				temp = "";
                ifs >> current->count;
				ifs >> current->name;
			}
		}
    } else {
		cout << "Файл не найден\n.";
	}
}

// Установка количества учеников
void setCountGroup(group* start, int _id, int _count) {
    group* current = start;
    while ((current->next) && (current->id != _id)) {
        current = current->next;
    }
    if (current->id == _id) {
        current->count = _count;
    }
}

void setNameGroup(group* start, int _id, string _name) {
    group* current = start;
    while ((current->next) && (current->id != _id)) {
        current = current->next;
    }
    if (current->id == _id) {
        current->name = _name;
    }
}

// Поиск элемента по id
group* givePageGroup(group* start, int _id) {
    group* current = start;
    while ((current->next) && (current->id != _id)) {
        current = current->next;
    }
    if (current->id == _id) {
        return current;
    } else {
        return NULL;
    }
}

// Поиск элемента по количеству учеников
group* findCountGroup(group* start, int countKey) {
    group* current = start;
    while ((current->next) && (current->count != countKey)) {
        current = current->next;
    }
    if (current->count == countKey) {
        return current;
    } else {
        return NULL;
    }
}

// Поиск элементов по названию группы
group* findNameGroup(group* start, string nameKey) {
    group* current = start;
    while ((current->next) && (current->name != nameKey)) {
        current = current->next;
    }
    if (current->name == nameKey) {
        return current;
    } else {
        return NULL;
    }
}
