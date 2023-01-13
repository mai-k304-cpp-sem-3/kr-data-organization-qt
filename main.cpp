#include <iostream>
#include <string>

#include "mainwindow.h"
#include "professor.h"
#include "group.h"
#include "examination.h"

#include <QApplication>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
