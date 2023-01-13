#include <iostream>
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "examination.h"
#include "professor.h"
#include "group.h"

const string EXAMINATIONS_FILE_NAME = "examinations.txt";
const string PROFESSOR_FILE_NAME = "professors.txt";
const string GROUP_FILE_NAME = "groups.txt";

professor* professors = new professor;
group* groups = new group;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_fileReadButton_clicked() {
    if (ui->choiceDBBox->currentText() == QString::fromStdString("Преподователи")) {
        deleteListProfessor(&professors);
        professors = new professor;
        fileReadProfessor(&professors, PROFESSOR_FILE_NAME);
        professor* current = professors;
        int i = 0;
        if (current != NULL) {
            while (current != NULL) {
                ui->tableWidgetProfessors->setRowCount(i);
                ui->tableWidgetProfessors->setItem(i - 1, 0, new QTableWidgetItem(QString::number(current->id)));
                ui->tableWidgetProfessors->setItem(i - 1, 1, new QTableWidgetItem(QString::fromStdString(current->name)));
                ui->tableWidgetProfessors->setItem(i - 1, 2, new QTableWidgetItem(QString::fromStdString(current->surname)));
                i++;
                current = current->next;
            }
            ui->statusbar->showMessage("Успех: Список преподователей заполнен из файла");
        } else { // Если списка нет, то выводится соответствующее сообщение
            ui->statusbar->showMessage("Ошибка: Список пуст");
        }
    }
    if (ui->choiceDBBox->currentText() == QString::fromStdString("Группы")) {
        deleteListGroup(&groups);
        groups = new group;
        fileReadGroup(&groups, GROUP_FILE_NAME);
        group* current = groups;
        int i = 0;
        if (current != NULL) {
            while (current != NULL) {
                ui->tableWidgetGroups->setRowCount(i);
                ui->tableWidgetGroups->setItem(i - 1, 0, new QTableWidgetItem(QString::number(current->id)));
                ui->tableWidgetGroups->setItem(i - 1, 1, new QTableWidgetItem(QString::number(current->count)));
                ui->tableWidgetGroups->setItem(i - 1, 2, new QTableWidgetItem(QString::fromStdString(current->name)));
                i++;
                current = current->next;
            }
            ui->statusbar->showMessage("Успех: Список групп заполнен из файла");
        } else { // Если списка нет, то выводится соответствующее сообщение
            ui->statusbar->showMessage("Ошибка: Список пуст");
        }
    }
}


void MainWindow::on_deleteListButton_clicked() {
    if (ui->choiceDBBox->currentText() == QString::fromStdString("Преподователи")) {
        deleteListProfessor(&professors);
        ui->tableWidgetProfessors->clear();
        QStringList headers;
        headers << "Id" << "Имя" << "Фамилия";
        ui->tableWidgetProfessors->setHorizontalHeaderLabels(headers);
        ui->statusbar->showMessage("Успех: Список преподователей удалён");
    }
    if (ui->choiceDBBox->currentText() == QString::fromStdString("Группы")) {
        deleteListGroup(&groups);
        ui->tableWidgetGroups->clear();
        QStringList headers;
        headers << "Id" << "Кол-во" << "Номер";
        ui->tableWidgetGroups->setHorizontalHeaderLabels(headers);
        ui->statusbar->showMessage("Успех: Список групп удалён");
    }
}


void MainWindow::on_deletePageButton_clicked() {
    if (ui->choiceDBBox->currentText() == QString::fromStdString("Преподователи")) {
        if (givePageProfessor(professors, ui->choiceIdBox->value())) {
            deletePageProfessor(&professors, ui->choiceIdBox->value());
            professor* current = professors;
            ui->tableWidgetProfessors->setRowCount(ui->tableWidgetProfessors->rowCount() - 1);
            int i = 0;
            while (current != NULL) {
                ui->tableWidgetProfessors->setItem(i - 1, 0, new QTableWidgetItem(QString::number(current->id)));
                ui->tableWidgetProfessors->setItem(i - 1, 1, new QTableWidgetItem(QString::fromStdString(current->name)));
                ui->tableWidgetProfessors->setItem(i - 1, 2, new QTableWidgetItem(QString::fromStdString(current->surname)));
                i++;
                current = current->next;
            }
            ui->statusbar->showMessage("Успех: Преподователь с id: " + QString::number(ui->choiceIdBox->value()) + " удалён из списка");
        } else {
            ui->statusbar->showMessage("Ошибка: В списке преподователей не найден элемент с id: " + QString::number(ui->choiceIdBox->value()));
        }
    }
    if (ui->choiceDBBox->currentText() == QString::fromStdString("Группы")) {
        if (givePageGroup(groups, ui->choiceIdBox->value())) {
            deletePageGroup(&groups, ui->choiceIdBox->value());
            group* current = groups;
            ui->tableWidgetGroups->setRowCount(ui->tableWidgetGroups->rowCount() - 1);
            int i = 0;
            while (current != NULL) {
                ui->tableWidgetGroups->setItem(i - 1, 0, new QTableWidgetItem(QString::number(current->id)));
                ui->tableWidgetGroups->setItem(i - 1, 1, new QTableWidgetItem(QString::number(current->count)));
                ui->tableWidgetGroups->setItem(i - 1, 2, new QTableWidgetItem(QString::fromStdString(current->name)));
                i++;
                current = current->next;
            }
            ui->statusbar->showMessage("Успех: Группа с id: " + QString::number(ui->choiceIdBox->value()) + " удалёна из списка");
        } else {
            ui->statusbar->showMessage("Ошибка: В списке групп не найден элемент с id: " + QString::number(ui->choiceIdBox->value()));
        }
    }
}


void MainWindow::on_choiceDBBox_currentTextChanged(const QString &arg1) {
    if (ui->choiceDBBox->currentText() == "Преподователи") {
        ui->choiceDataBox->clear();
        ui->choiceDataBox->addItem("Имя");
        ui->choiceDataBox->addItem("Фамилия");
    }
    if (ui->choiceDBBox->currentText() == "Группы") {
        ui->choiceDataBox->clear();
        ui->choiceDataBox->addItem("Кол-во");
        ui->choiceDataBox->addItem("Номер");
    }
}

void MainWindow::on_setButton_clicked() {
    if (ui->choiceDBBox->currentText() == "Преподователи") {
        if (ui->choiceDataBox->currentText() == "Имя") {
            if (givePageProfessor(professors, ui->choiceIdBox->value())) {
                setNameProfessor(professors, ui->choiceIdBox->value(), ui->choiceLineEdit->text().toStdString());
                professor* current = professors;
                int i = 0;
                while (current != NULL) {
                    ui->tableWidgetProfessors->setItem(i - 1, 0, new QTableWidgetItem(QString::number(current->id)));
                    ui->tableWidgetProfessors->setItem(i - 1, 1, new QTableWidgetItem(QString::fromStdString(current->name)));
                    ui->tableWidgetProfessors->setItem(i - 1, 2, new QTableWidgetItem(QString::fromStdString(current->surname)));
                    i++;
                    current = current->next;
                }
                ui->statusbar->showMessage("Успех: Имя преподователя с id: " + QString::number(ui->choiceIdBox->value()) + ", изменено на " + ui->choiceLineEdit->text());
            } else {
                ui->statusbar->showMessage("Ошибка: В списке преподователей не найден элемент с id: " + QString::number(ui->choiceIdBox->value()));
            }
        }
        if (ui->choiceDataBox->currentText() == "Фамилия") {
            if (givePageProfessor(professors, ui->choiceIdBox->value())) {
                setSurnameProfessor(professors, ui->choiceIdBox->value(), ui->choiceLineEdit->text().toStdString());
                professor* current = professors;
                int i = 0;
                while (current != NULL) {
                    ui->tableWidgetProfessors->setItem(i - 1, 0, new QTableWidgetItem(QString::number(current->id)));
                    ui->tableWidgetProfessors->setItem(i - 1, 1, new QTableWidgetItem(QString::fromStdString(current->name)));
                    ui->tableWidgetProfessors->setItem(i - 1, 2, new QTableWidgetItem(QString::fromStdString(current->surname)));
                    i++;
                    current = current->next;
                }
                ui->statusbar->showMessage("Успех: Фамилия преподователя с id: " + QString::number(ui->choiceIdBox->value()) + ", изменено на " + ui->choiceLineEdit->text());
            } else {
                ui->statusbar->showMessage("Ошибка: В списке преподователей не найден элемент с id: " + QString::number(ui->choiceIdBox->value()));
            }
        }
    }
    if (ui->choiceDBBox->currentText() == "Группы") {
        if (ui->choiceDataBox->currentText() == "Кол-во") {
            if (givePageGroup(groups, ui->choiceIdBox->value())) {
                setCountGroup(groups, ui->choiceIdBox->value(), ui->choiceLineEdit->text().toInt());
                group* current = groups;
                int i = 0;
                while (current != NULL) {
                    ui->tableWidgetGroups->setItem(i - 1, 0, new QTableWidgetItem(QString::number(current->id)));
                    ui->tableWidgetGroups->setItem(i - 1, 1, new QTableWidgetItem(QString::number(current->count)));
                    ui->tableWidgetGroups->setItem(i - 1, 2, new QTableWidgetItem(QString::fromStdString(current->name)));
                    i++;
                    current = current->next;
                }
                ui->statusbar->showMessage("Успех: Кол-во группы с id: " + QString::number(ui->choiceIdBox->value()) + ", изменён на " + ui->choiceLineEdit->text());
            } else {
                ui->statusbar->showMessage("Ошибка: В списке групп не найден элемент с id: " + QString::number(ui->choiceIdBox->value()));
            }
        }
        if (ui->choiceDataBox->currentText() == "Номер") {
            if (givePageGroup(groups, ui->choiceIdBox->value())) {
                setNameGroup(groups, ui->choiceIdBox->value(), ui->choiceLineEdit->text().toStdString());
                group* current = groups;
                int i = 0;
                while (current != NULL) {
                    ui->tableWidgetGroups->setItem(i - 1, 0, new QTableWidgetItem(QString::number(current->id)));
                    ui->tableWidgetGroups->setItem(i - 1, 1, new QTableWidgetItem(QString::number(current->count)));
                    ui->tableWidgetGroups->setItem(i - 1, 2, new QTableWidgetItem(QString::fromStdString(current->name)));
                    i++;
                    current = current->next;
                }
                ui->statusbar->showMessage("Успех: Номер группы с id: " + QString::number(ui->choiceIdBox->value()) + ", изменён на " + ui->choiceLineEdit->text());
            } else {
                ui->statusbar->showMessage("Ошибка: В списке групп не найден элемент с id: " + QString::number(ui->choiceIdBox->value()));
            }
        }
    }
}


void MainWindow::on_findIdButton_clicked() {
    if (ui->choiceDBBox->currentText() == "Преподователи") {
        if(givePageProfessor(professors, ui->choiceIdBox->value())) {
            ui->statusbar->showMessage("Успех: " + QString::fromStdString(givePageProfessor(professors, ui->choiceIdBox->value())->name) + " " + QString::fromStdString(givePageProfessor(professors, ui->choiceIdBox->value())->surname));
        } else {
            ui->statusbar->showMessage("Ошибка: В списке преподователей не найден элемент с id: " + QString::number(ui->choiceIdBox->value()));
        }
    }
    if (ui->choiceDBBox->currentText() == "Группы") {
        if(givePageGroup(groups, ui->choiceIdBox->value())) {
            ui->statusbar->showMessage("Успех: " + QString::number(givePageGroup(groups, ui->choiceIdBox->value())->count) + " " + QString::fromStdString(givePageGroup(groups, ui->choiceIdBox->value())->name));
        } else {
            ui->statusbar->showMessage("Ошибка: В списке групп не найден элемент с id: " + QString::number(ui->choiceIdBox->value()));
        }
    }
}


void MainWindow::on_findButton_clicked() {
    if (ui->choiceDBBox->currentText() == "Преподователи") {
        if(givePageProfessor(professors, ui->choiceIdBox->value())) {
            if (ui->choiceDataBox->currentText() == "Имя") {
                if (findNameProfessor(professors, ui->choiceLineEdit->text().toStdString())) {
                    ui->statusbar->showMessage("Успех : Преподователь с именем: " + ui->choiceLineEdit->text() + " имеет id: " + QString::number(findNameProfessor(professors, ui->choiceLineEdit->text().toStdString())->id));
                } else {
                    ui->statusbar->showMessage("Ошибка: В списке преподователей не найден элемент с именем: " + ui->choiceLineEdit->text());
                }
            }
            if (ui->choiceDataBox->currentText() == "Фамилия") {
                if (findSurnameProfessor(professors, ui->choiceLineEdit->text().toStdString())) {
                    ui->statusbar->showMessage("Успех : Преподователь с фамилией: " + ui->choiceLineEdit->text() + " имеет id: " + QString::number(findSurnameProfessor(professors, ui->choiceLineEdit->text().toStdString())->id));
                } else {
                    ui->statusbar->showMessage("Ошибка: В списке преподователей не найден элемент с фамилией: " + ui->choiceLineEdit->text());
                }
            }
        } else {
            ui->statusbar->showMessage("Ошибка: В списке преподователей не найден элемент с id: " + QString::number(ui->choiceIdBox->value()));
        }
    }
    if (ui->choiceDBBox->currentText() == "Группы") {
        if(givePageGroup(groups, ui->choiceIdBox->value())) {
            if (ui->choiceDataBox->currentText() == "Кол-во") {
                if (findCountGroup(groups, ui->choiceLineEdit->text().toInt())) {
                    ui->statusbar->showMessage("Успех : Группа с кол-вом: " + ui->choiceLineEdit->text() + " имеет id: " + QString::number(findCountGroup(groups, ui->choiceLineEdit->text().toInt())->id));
                } else {
                    ui->statusbar->showMessage("Ошибка: В списке групп не найден элемент с кол-вом: " + ui->choiceLineEdit->text());
                }
            }
            if (ui->choiceDataBox->currentText() == "Номер") {
                if (findNameGroup(groups, ui->choiceLineEdit->text().toStdString())) {
                    ui->statusbar->showMessage("Успех : Группа с номером: " + ui->choiceLineEdit->text() + " имеет id: " + QString::number(findNameGroup(groups, ui->choiceLineEdit->text().toStdString())->id));
                } else {
                    ui->statusbar->showMessage("Ошибка: В списке групп не найден элемент с номером: " + ui->choiceLineEdit->text());
                }
            }
        } else {
            ui->statusbar->showMessage("Ошибка: В списке групп не найден элемент с id: " + QString::number(ui->choiceIdBox->value()));
        }
    }
}


void MainWindow::on_autor_clicked() {
    ui->statusbar->showMessage("Пысларь Александр Игоревич: https://github.com/AlexPyslar03");
}


void MainWindow::on_addButton_clicked() {
    if (ui->choiceDBBox->currentText() == "Преподователи") {
        addPageProfessor(&professors, ui->professorAddNameLineEdit->text().toStdString(), ui->professorAddSurnameLineEdit->text().toStdString());
        professor* current = professors;
        ui->tableWidgetProfessors->setRowCount(ui->tableWidgetProfessors->rowCount() + 1);
        int i = 0;
        while (current != NULL) {
            ui->tableWidgetProfessors->setItem(i - 1, 0, new QTableWidgetItem(QString::number(current->id)));
            ui->tableWidgetProfessors->setItem(i - 1, 1, new QTableWidgetItem(QString::fromStdString(current->name)));
            ui->tableWidgetProfessors->setItem(i - 1, 2, new QTableWidgetItem(QString::fromStdString(current->surname)));
            i++;
            current = current->next;
        }
        ui->statusbar->showMessage("Успех: Преподователь добавлен");
    }
    if (ui->choiceDBBox->currentText() == "Группы") {
        addPageGroup(&groups, ui->groupAddCountLineEdit->text().toInt(), ui->groupAddNameLineEdit->text().toStdString());
        group* current = groups;
        ui->tableWidgetGroups->setRowCount(ui->tableWidgetGroups->rowCount() + 1);
        int i = 0;
        while (current != NULL) {
            ui->tableWidgetGroups->setItem(i - 1, 0, new QTableWidgetItem(QString::number(current->id)));
            ui->tableWidgetGroups->setItem(i - 1, 1, new QTableWidgetItem(QString::number(current->count)));
            ui->tableWidgetGroups->setItem(i - 1, 2, new QTableWidgetItem(QString::fromStdString(current->name)));
            i++;
            current = current->next;
        }
        ui->statusbar->showMessage("Успех: Группа добавлена");
    }
}

