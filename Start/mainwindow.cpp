#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QMessageBox>  // Необходимо для показа сообщений в отдельном окне

/// Конструктор объекта логики главного окна программы
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);  // Инициализация объекта интерфейса окна

    // Привязываем *два* сигнала изменения текста
    // (сигнал textChanged LineEdit'а "leA"
    // и сигнал textChanged LineEdit'а "leB")
    // к *одному и тому же* слоту on_input
    // главного окна программы (на него указывает this).
    connect(
        ui->leA, &QLineEdit::textChanged,
        this, &MainWindow::on_input
        );
    connect(
        ui->leB, &QLineEdit::textChanged,
        this, &MainWindow::on_input
        );
}

/// Деструктор объекта логики главного окна программы
MainWindow::~MainWindow()
{
    delete ui;  // Освобождение ресурсов из-под объекта интерфейса окна
}

/// Слот обработки нажатия кнопки pbClose (Выход) главного окна
void MainWindow::on_pbClose_clicked()
{
    QApplication::quit();   // Выход из программы
}

/// Слот обработки нажатия кнопки pbCalc (=) главного окна
void MainWindow::on_pbCalc_clicked()
{
    // Получаем текст из leA и leB в виде строк типа QString
    QString sa = ui->leA->text(), sb = ui->leB->text();

    // Пытаемся преобраовать текст в числа
    bool a_ok, b_ok;
    double a = sa.toDouble(&a_ok), b = sb.toDouble(&b_ok);

    if (!a_ok || !b_ok) {   // Если не удалось
        QMessageBox msgb;   // Объявляем объект "окно сообщения"
        msgb.setText("Ошибка ввода");   // Задаём текст сообщения
        msgb.exec();                    // Показываем окно сообщения пользователю
    }
    else {  // Иначе (если удалось преобразовать текст в числа)
        double res = a + b; // Вычисляем результат операции
        // Преобразуем результат (число) в строку с 2 знаками после запятой
        // и помещаем эту строку в качестве текста lblResult
        ui->lblResult->setText(QString::number(res, 'f', 2));
    }
}

/// Слот обработки ввода данных в leA или leB
void MainWindow::on_input() {
    ui->lblResult->setText(""); // Очищаем текст lblResult
}

