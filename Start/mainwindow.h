#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/// Класс логики главного окна программы
class MainWindow : public QMainWindow
{    
    Q_OBJECT        // Обязательно для всех объектов Qt,
                    // которые работают с сигналами и слотами

public:
    MainWindow(QWidget *parent = nullptr);  // Конструктор объекта логики окна
    ~MainWindow();                          // Деструктор объекта логики окна

    // Слоты окна
private slots:
    void on_pbClose_clicked();    // Слот обработки нажатия кнопки pbClose (Выход)

    void on_pbCalc_clicked();     // Слот обработки нажатия кнопки pbCalc (=)

    void on_input();              // Слот обработки ввода данных в leA или leB
private:
    Ui::MainWindow *ui;           // Указатель на объект интерфейса главного окна программы
};
#endif // MAINWINDOW_H
