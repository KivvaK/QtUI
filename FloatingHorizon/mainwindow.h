#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <functional>
#include <vector>

#include <QMainWindow>
#include <QGraphicsPixmapItem>

#include "camera.h"
#include "surfaces.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{

    Q_OBJECT
    Camera* cam;
    QGraphicsPixmapItem* pmi;
    std::vector<std::function<float(float, float)>> surfaces = {
            mhat,
            sinc,
            peaks
        };

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pbDraw_clicked();
    void on_changed(QString s);

    void on_pbRLeft_clicked();

    void on_pbRRight_clicked();

    void on_pbRDown_clicked();

    void on_pbRUp_clicked();

    void on_cbxSurfaces_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    void updateCam(const QPaintDevice& pd);
    void update();
};
#endif // MAINWINDOW_H
