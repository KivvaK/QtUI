#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    enum State {
        FirstDigit,
        InputNumber,
        Calculation
    };
    State state;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_number_input();

private:
    Ui::MainWindow *ui;

    void reset();
};
#endif // MAINWINDOW_H
