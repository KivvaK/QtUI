#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QPen>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QGraphicsPixmapItem* pmi;
    QPixmap image;

    bool leftPressed = false;
    QPoint prev;   // Предыдущее положение курсора мыши в координатах сцены
    QPen pen;
    // Какой delta соответствует единичный поворот колёсика мыши
    int wheelDeltaStep = 15;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // Добавим слоты для обработки сигналов о событиях мыши от MouseGraphicsView
    // (их список параметров должен совпадать со списком параметров
    // соответствующих сигналов)
private slots:
    void on_mouseDown(const QPointF& pos, Qt::MouseButton button);
    void on_mouseUp(const QPointF& pos, Qt::MouseButton button);
    void on_mouseMove(const QPointF& pos);
    void on_mouseWheel(int delta);

    void on_pbClear_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
