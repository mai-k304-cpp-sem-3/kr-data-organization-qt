#include <iostream>
#include <fstream>
#include <iomanip>

#include "examination.h"

using namespace std;

// Добавление нового элемента в список принятия экзамена
void addExaminationAccepts(examinationAccepts** start, int _idProfessor, string _item, int _classroom, date _dateDelivery, date _dateRetake) {
    bool New = false;
    examinationAccepts* current;
    examinationAccepts* newExaminationAccepts = new examinationAccepts;

    if (*start == NULL) {
        *start = new examinationAccepts;
        (*examinationAccepts)->next = *start;
        New = true;
    }

    current = *examinationAccepts;

    int i = 0;
    if (!New) {
        while (current->next != *newExaminationAccepts) {
            current = current->next;
            i = current->id;
        }
        i++;
        newExaminationAccepts->next = current->next;
        current->next = newExaminationAccepts;
        current = current->next;
    }
    current->id = i;
    current->idProfessor = _idProfessor;
    current->item = _item;
    current->classroom = _classroom;
    current->dateDelivery = _dateDelivery;
    current->dateRetake = _dateRetake;
}

// Удаление определённого элемента в списке принятия экзамена
void deletePageExaminationAccepts(examinationAccepts** start, int _id) { // Удаление определённого элемента в списке
    examinationAccepts* current = *start;
    examinationAccepts* del;
    if (*start) {
        while ((current->next) && (current->next->id != _id)) {
            current = current->next;
        }
        if (current->next) {
            if (current->next == *start) {
                del = *start;
                *start = (*start)->next;
                current->next = *start;
            } else {
                del = current->next;
                current->next = current->next->next;
            }
            delete del;
            return true;
        }
    }
}

// Удаление списка принятия экзамена
void deleteListExaminationAccepts(examinationAccepts** start) {
    if (*start) {
            examinationAccepts* current = (*start)->next;
            examinationAccepts* del = current;
            while (current->next != *start) {
                current = current->next;
                delete del;
                del = current;
            }
            delete* start;
            *start = NULL;
        }
}

// Считывания списка принятия экзамена из файла
void fileReadExaminationAccepts(examinationAccepts** start, string fileName) {
    ifstream ifs(fileName);
    if (ifs.is_open()) {
        bool New = false;
        examinationAccepts* current;
        string temp;

        if (*start == NULL) {
            *start = new examinationAccepts;
            New = true;
        }

        current = *start;

        if (!New) {
            while (current->next != *start) {
                current = current->next;
                current->next = NULL;
            }
        }
        while (!ifs.eof()) {
            ifs >> temp;
            if (temp == "") {
                break;
            }
            if (!New) {
                current->next = new examinationAccepts;
                current = current->next;
            }
            else {
                New = false;
            }
            if (!ifs.eof()) {
                current->id = stoi(temp);
                temp = "";
                ifs >> current->id;
                ifs >> current->idProfessor;
                ifs >> current->item;
                ifs >> current->classroom;
                ifs >> current->dateDelivery;
                ifs >> current->dateRetake;
            }
        }
        current->next = *start;
    } else {
        cout << "Файл пуст\n.";
    }
}

// Установка id профессора в списке принятия экзамена
void setIdProfessorExaminationAccepts(examinationAccepts* start, int _id, int _idProfessor) {
    examinationAccepts* current = start;
    while ((current->next) && (current->id != _id)) {
        current = current->next;
    }
    if (current->id == _id) {
        current->idProfessor = _idProfessor;
    }
}

// Установка предмета в списке принятия экзамена
void setItemExaminationAccepts(examinationAccepts* start, string _item) {
    examinationAccepts* current = start;
    while ((current->next) && (current->id != _id)) {
        current = current->next;
    }
    if (current->id == _id) {
        current->item = _item;
    }
}

// Установка аудитории в списке принятия экзамена
void setClassroomExaminationAccepts(examinationAccepts* start, int _id, int _classroom) {
    examinationAccepts* current = start;
    while ((current->next) && (current->id != _id)) {
        current = current->next;
    }
    if (current->id == _id) {
        current->classroom = _classroom;
    }
}

// Установка даты сдачи в списке принятия экзамена
void setDateDeliveryExaminationAccepts(examinationAccepts* start, int _id, date _dateDelivery) {
    examinationAccepts* current = start;
    while ((current->next) && (current->id != _id)) {
        current = current->next;
    }
    if (current->id == _id) {
        current->dateDelivery = _dateDelivery;
    }
}

// Установка даты пересдачи в списке принятия экзамена
void setDateRetakeExaminationAccepts(examinationAccepts* start, int _id, date _dateRetake) {
    examinationAccepts* current = start;
    while ((current->next) && (current->id != _id)) {
        current = current->next;
    }
    if (current->id == _id) {
        current->dateRetake = _dateRetake;
    }
}

// Поиск элемента по id в списке принятия экзамена
examinationAccepts* getPageExaminationAccepts(examinationAccepts* start, int _id) {
    examinationAccepts* current = start;
    while ((current->next) && (current->id != _id)) {
        current = current->next;
    }
    if (current->id == _id) {
        return current;
    } else {
        return NULL;
    }
}

// Поиск элемента по id преподователя в списке принятия экзамена
examinationAccepts* findIdProfessorExaminationAccepts(examinationAccepts* start, int idProfessorsKey) {
    examinationAccepts* current = start;
    while ((current->next) && (current->idProfessor != idProfessorsKey)) {
        current = current->next;
    }
    if (current->idProfessor == idProfessorsKey) {
        return current;
    } else {
        return NULL;
    }
}

// Поиск элемента по предмету в списке принятия экзамена
examinationAccepts* findItemExaminationAccepts(examinationAccepts* start, int itemKey) {
    examinationAccepts* current = start;
    while ((current->next) && (current->item != itemKey)) {
        current = current->next;
    }
    if (current->item == itemKey) {
        return current;
    } else {
        return NULL;
    }
}

// Поиск элемента по аудитории в списке принятия экзамена
examinationAccepts* findClassroomExaminationAccepts(examinationAccepts* start, string classroomKey) {
    examinationAccepts* current = start;
    while ((current->next) && (current->classroom != classroomKey)) {
        current = current->next;
    }
    if (current->classroom == classroomKey) {
        return current;
    } else {
        return NULL;
    }
}

// Поиск элемента по дате сдачи в списке принятия экзамена
examinationAccepts* findDateDeliveryExaminationAccepts(examinationAccepts* start, string dateDeliveryKey) {
    examinationAccepts* current = start;
    while ((current->next) && (current->dateDelivery != dateDeliveryKey)) {
        current = current->next;
    }
    if (current->dateDelivery == dateDeliveryKey) {
        return current;
    } else {
        return NULL;
    }
}

// Поиск элемента по дате пересдачи в списке принятия экзамена
examinationAccepts* findDateRetakeExaminationAccepts(examinationAccepts* start, string dateRetakeKey) {
    examinationAccepts* current = start;
    while ((current->next) && (current->dateRetake != dateRetakeKey)) {
        current = current->next;
    }
    if (current->dateRetake == dateRetakeKey) {
        return current;
    } else {
        return NULL;
    }
}

// Добавление нового элемента в список сдачи экзамена
void addExaminationTaking(examinationTaking** start, int _idGroup, string _item, int _classroom, date _dateDelivery, date _dateRetake) {
    bool New = false;
    examinationTaking* current;
    examinationTaking* newExaminationTaking = new examinationTaking;

    if (*start == NULL) {
        *start = new examinationTaking;
        (*examinationTaking)->next = *examinationTaking;
        New = true;
    }

    current = *examinationTaking;

    int i = 0;
    if (!New) {
        while (current->next != *newExaminationTaking) {
            current = current->next;
            i = current->id;
        }
        i++;
        newExaminationTaking->next = current->next;
        current->next = newExaminationTaking;
        current = current->next;
    }
    current->id = i;
    current->idGroup = _idGroup;
    current->item = _item;
    current->classroom = _classroom;
    current->dateDelivery = _dateDelivery;
    current->dateRetake = _dateRetake;
}

// Удаление определённого элемента в списке сдачи экзамена
void deletePageExaminationTaking(examinationTaking** start, int _id) { // Удаление определённого элемента в списке
    examinationTaking* current = *start;
    examinationTaking* del;
    if (*start) {
        while ((current->next) && (current->next->id != _id)) {
            current = current->next;
        }
        if (current->next) {
            if (current->next == *start) {
                del = *start;
                *start = (*start)->next;
                current->next = *start;
            } else {
                del = current->next;
                current->next = current->next->next;
            }
            delete del;
            return true;
        }
    }
}

// Удаление списка сдачи экзамена
void deleteListExaminationTaking(examinationTaking** start) {
    if (*start) {
            examinationTaking* current = (*start)->next;
            examinationTaking* del = current;
            while (current->next != *start) {
                current = current->next;
                delete del;
                del = current;
            }
            delete* start;
            *start = NULL;
        }
}

// Считывания списка сдачи экзамена из файла
void fileReadExaminationTaking(examinationTaking** start, string fileName) {
    ifstream ifs(fileName);
    if (ifs.is_open()) {
        bool New = false;
        examinationTaking* current;
        string temp;

        if (*start == NULL) {
            *start = new examinationTaking;
            New = true;
        }

        current = *start;

        if (!New) {
            while (current->next != *start) {
                current = current->next;
                current->next = NULL;
            }
        }
        while (!ifs.eof()) {
            ifs >> temp;
            if (temp == "") {
                break;
            }
            if (!New) {
                current->next = new examinationTaking;
                current = current->next;
            }
            else {
                New = false;
            }
            if (!ifs.eof()) {
                current->id = stoi(temp);
                temp = "";
                ifs >> current->id;
                ifs >> current->idGroup;
                ifs >> current->item;
                ifs >> current->classroom;
                ifs >> current->dateDelivery;
                ifs >> current->dateRetake;
            }
        }
        current->next = *start;
    } else {
        cout << "Файл пуст\n.";
    }
}

// Установка id профессора в списке сдачи экзамена
void setIdGroupExaminationTaking(examinationTaking* start, int _id, int _idGroup) {
    examinationTaking* current = start;
    while ((current->next) && (current->id != _id)) {
        current = current->next;
    }
    if (current->id == _id) {
        current->idGroup = _idGroup;
    }
}

// Установка предмета в списке сдачи экзамена
void setItemExaminationTaking(examinationTaking* start, string _item) {
    examinationTaking* current = start;
    while ((current->next) && (current->id != _id)) {
        current = current->next;
    }
    if (current->id == _id) {
        current->item = _item;
    }
}

// Установка аудитории в списке сдачи экзамена
void setClassroomExaminationTaking(examinationTaking* start, int _id, int _classroom) {
    examinationTaking* current = start;
    while ((current->next) && (current->id != _id)) {
        current = current->next;
    }
    if (current->id == _id) {
        current->classroom = _classroom;
    }
}

// Установка даты сдачи в списке сдачи экзамена
void setDateDeliveryExaminationTaking(examinationTaking* start, int _id, date _dateDelivery) {
    examinationTaking* current = start;
    while ((current->next) && (current->id != _id)) {
        current = current->next;
    }
    if (current->id == _id) {
        current->dateDelivery = _dateDelivery;
    }
}

// Установка даты пересдачи в списке сдачи экзамена
void setDateRetakeExaminationTaking(examinationTaking* start, int _id, date _dateRetake) {
    examinationTaking* current = start;
    while ((current->next) && (current->id != _id)) {
        current = current->next;
    }
    if (current->id == _id) {
        current->dateRetake = _dateRetake;
    }
}

// Поиск элемента по id в списке сдачи экзамена
examinationTaking* getPageExaminationTaking(examinationTaking* start, int _id) {
    examinationTaking* current = start;
    while ((current->next) && (current->id != _id)) {
        current = current->next;
    }
    if (current->id == _id) {
        return current;
    } else {
        return NULL;
    }
}

// Поиск элемента по id преподователя в списке сдачи экзамена
examinationTaking* findIdProfessorExaminationTaking(examinationTaking* start, int idGroupKey) {
    examinationTaking* current = start;
    while ((current->next) && (current->idGroup != idGroupKey)) {
        current = current->next;
    }
    if (current->idGroup == idGroupKey) {
        return current;
    } else {
        return NULL;
    }
}

// Поиск элемента по предмету в списке сдачи экзамена
examinationTaking* findItemExaminationTaking(examinationTaking* start, int itemKey) {
    examinationTaking* current = start;
    while ((current->next) && (current->item != itemKey)) {
        current = current->next;
    }
    if (current->item == itemKey) {
        return current;
    } else {
        return NULL;
    }
}

// Поиск элемента по аудитории в списке сдачи экзамена
examinationTaking* findClassroomExaminationTaking(examinationTaking* start, string classroomKey) {
    examinationTaking* current = start;
    while ((current->next) && (current->classroom != classroomKey)) {
        current = current->next;
    }
    if (current->classroom == classroomKey) {
        return current;
    } else {
        return NULL;
    }
}

// Поиск элемента по дате сдачи в списке сдачи экзамена
examinationTaking* findDateDeliveryExaminationTaking(examinationTaking* start, string dateDeliveryKey) {
    examinationTaking* current = start;
    while ((current->next) && (current->dateDelivery != dateDeliveryKey)) {
        current = current->next;
    }
    if (current->dateDelivery == dateDeliveryKey) {
        return current;
    } else {
        return NULL;
    }
}

// Поиск элемента по дате пересдачи в списке сдачи экзамена
examinationTaking* findDateRetakeExaminationTaking(examinationTaking* start, string dateRetakeKey) {
    examinationTaking* current = start;
    while ((current->next) && (current->dateRetake != dateRetakeKey)) {
        current = current->next;
    }
    if (current->dateRetake == dateRetakeKey) {
        return current;
    } else {
        return NULL;
    }
}
