#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_fileReadButton_clicked();
    void on_deleteListButton_clicked();
    void on_deletePageButton_clicked();

    void on_choiceDBBox_currentTextChanged(const QString &arg1);

    void on_setButton_clicked();

    void on_findIdButton_clicked();

    void on_findButton_clicked();

    void on_autor_clicked();

    void on_addButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
