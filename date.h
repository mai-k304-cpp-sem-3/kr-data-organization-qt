#ifndef DATE_H
#define DATE_H

struct date {
    int mon; // Месяц
    int day; // День
    int hour; // Час
    int min; // Минуты
};

bool isCorrect(date* _date); // Функция проверки даты

#endif