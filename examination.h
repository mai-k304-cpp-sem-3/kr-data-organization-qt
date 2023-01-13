#ifndef EXAMINATION_H
#define EXAMINATION_H

#include "professor.h" // Подключение заголовочного файла преподователя
#include "group.h" // Подключение заголовочного файла группы
#include "date.h" // Покдлючение заголовочного файла с датами

#include <string> // Подключение библиотеки для работы со string

using namespace std;

struct examinationAccepts { // Структура принятия экзамена
    int id; // Индекс
    examinationAccepts* back; // Преведущий элемент списка
    examinationAccepts* next; // Следующий элемент списка
    int idProfessor; // ID профессора
    string item; // Предмет
    int classroom; // Аудитория
    date dateDelivery; // Дата сдачи
    date dateRetake; // Дата пересдачи
};

// Добавление нового элемента в список принятия экзамена
void addExaminationAccepts(examinationAccepts** start, int _idProfessor, string _item, int _classroom, date _dateDelivery, date _dateRetake);

// Удаление определённого элемента в списке принятия экзамена
void deletePageExaminationAccepts(examinationAccepts** start, int _id);

// Удаление списка принятия экзамена
void deleteListExaminationAccepts(examinationAccepts** start);

// Считывания списка принятия экзамена из файла
void fileReadExaminationAccepts(examinationAccepts** start, string fileName);

// Установка id профессора в списке принятия экзамена
void setIdProfessorExaminationAccepts(examinationAccepts* start, int _id, int _idProfessor);

// Установка предмета в списке принятия экзамена
void setItemExaminationAccepts(examinationAccepts* start, int _id, string _item);

// Установка аудитории в списке принятия экзамена
void setClassroomExaminationAccepts(examinationAccepts* start, int _id, int _classroom);

// Установка даты сдачи в списке принятия экзамена
void setDateDeliveryExaminationAccepts(examinationAccepts* start, int _id, date _dateDelivery);

// Установка даты пересдачи в списке принятия экзамена
void setDateRetakeExaminationAccepts(examinationAccepts* start, int _id, date _dateRetake);

// Поиск элемента по id в списке принятия экзамена
examinationAccepts* getPageExaminationAccepts(examinationAccepts* start, int _id);

// Поиск элемента по id преподователя в списке принятия экзамена
examinationAccepts* findIdProfessorExaminationAccepts(examinationAccepts* start, int idProfessorsKey);

// Поиск элемента по предмету в списке принятия экзамена
examinationAccepts* findItemExaminationAccepts(examinationAccepts* start, int itemKey);

// Поиск элемента по аудитории в списке принятия экзамена
examinationAccepts* findClassroomExaminationAccepts(examinationAccepts* start, string classroomKey);

// Поиск элемента по дате сдачи в списке принятия экзамена
examinationAccepts* findDateDeliveryExaminationAccepts(examinationAccepts* start, string dateDeliveryKey);

// Поиск элемента по дате пересдачи в списке принятия экзамена
examinationAccepts* findDateRetakeExaminationAccepts(examinationAccepts* start, string dateRetakeKey);

struct examinationTaking { // Структура сдачи экзамена
    int id; // Индекс
    examinationTaking* back; // Преведущий элемент списка
    examinationTaking* next; // Следующий элемент списка
    int idGroup; // ID группы
    string item; // Предмет
    int classroom; // Аудитория
    date dateDelivery; // Дата сдачи
    date dateRetake; // Дата пересдачи
};

// Добавление нового элемента в список сдачи экзамена
void addExaminationTaking(examinationTaking** start, int _idGroup, string _item, int _classroom, date _dateDelivery, date _dateRetake);

// Удаление определённого элемента в списке сдачи экзамена
void deletePageExaminationTaking(examinationTaking** start, int _id);

// Удаление списка сдачи экзамена
void deleteListExaminationTaking(examinationTaking** start);

// Считывания списка сдачи экзамена из файла
void fileReadExaminationTaking(examinationTaking** start, string fileName);

// Установка id профессора в списке сдачи экзамена
void setIdGroupExaminationTaking(examinationTaking* start, int _idGroup);

// Установка предмета в списке сдачи экзамена
void setItemExaminationTaking(examinationTaking* start, string _item);

// Установка аудитории в списке сдачи экзамена
void setClassroomExaminationTaking(examinationTaking* start, int _classroom);

// Установка даты сдачи в списке сдачи экзамена
void setDateDeliveryExaminationTaking(examinationTaking* start, date _dateDelivery);

// Установка даты пересдачи в списке сдачи экзамена
void setDateRetakeExaminationTaking(examinationTaking* start, date _dateRetake);

// Поиск элемента по id в списке сдачи экзамена
examinationTaking* getPageExaminationTaking(examinationTaking* start, int _id);

// Поиск элемента по id группы в списке сдачи экзамена
examinationTaking* findIdGroupExaminationTaking(examinationTaking* start, int idGroupKey);

// Поиск элемента по предмету в списке сдачи экзамена
examinationTaking* findItemExaminationTaking(examinationTaking* start, int itemKey);

// Поиск элемента по аудитории в списке сдачи экзамена
examinationTaking* findClassroomExaminationTaking(examinationTaking* start, string classroomKey);

// Поиск элемента по дате сдачи в списке сдачи экзамена
examinationTaking* findDateDeliveryExaminationTaking(examinationTaking* start, string dateDeliveryKey);

// Поиск элемента по дате пересдачи в списке сдачи экзамена
examinationTaking* findDateRetakeExaminationTaking(examinationTaking* start, string dateRetakeKey);

#endif
