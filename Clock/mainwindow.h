#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QPen>
#include <QBrush>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QGraphicsPixmapItem* pmi;
    QPen pn, pnH, pnM, pnS;
    QBrush br;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_timeout();
    void on_pbStartStop_clicked();

private:
    Ui::MainWindow *ui;
    QTimer timer;
};
#endif // MAINWINDOW_H
