#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <limits>
#include <QPen>

void clear(QPaintDevice& pd, const QColor color = QColor("White")) {
    QPainter p(&pd);
    p.fillRect(0, 0, pd.width(), pd.height(), color);
}

void plot(std::function<float(float)> f,
          QPaintDevice& img,
          const Camera& cam,
          float yMin[],
          float yMax[],
          QPen pn) {
    QPainter p(&img);
    pn.setStyle(Qt::SolidLine);
    p.setPen(pn);

    float y = cam.yScreen(f(cam.xReal(0.f)));
    for (int x = 1; x < img.width(); x++) {
        float y1 = cam.yScreen(f(cam.xReal(x)));

        bool lower = y1 < yMin[x], higher = y1 > yMax[x];
        if (lower)
            yMin[x] = y1;
        if (higher)
            yMax[x] = y1;
        if (lower || higher)
            p.drawLine(x - 1, y, x, y1);

        y = y1;
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QGraphicsScene* scene = new QGraphicsScene();
    pmi = new QGraphicsPixmapItem();
    scene->addItem(pmi);
    ui->gvPlot->setScene(scene);

    cam = new Camera(ui->gvPlot->width(), ui->gvPlot->height(),
                     -ui->dsbXShrink->value(), ui->dsbXShrink->value(),
                     -ui->dsbZShrink->value(), ui->dsbZShrink->value(),
                     10.f, 0.05f, 0.1f);

    connect(
        ui->sbHorizonCount, &QSpinBox::textChanged,
        this, &MainWindow::on_changed
        );
    connect(
        ui->dsbXShrink, &QDoubleSpinBox::textChanged,
        this, &MainWindow::on_changed
        );
    connect(
        ui->dsbZShrink, &QDoubleSpinBox::textChanged,
        this, &MainWindow::on_changed
        );
    connect(
        ui->dsbYDepth, &QDoubleSpinBox::textChanged,
        this, &MainWindow::on_changed
        );

}

MainWindow::~MainWindow()
{
    delete ui;
    delete cam;
}

void MainWindow::updateCam(const QPaintDevice& pd) {
    cam->setScreenW(pd.width());
    cam->setScreenH(pd.height());
    cam->setXMin(-ui->dsbXShrink->value());
    cam->setXMax(ui->dsbXShrink->value());
    cam->setZMin(-ui->dsbZShrink->value());
    cam->setZMax(ui->dsbZShrink->value());
}

void MainWindow::update() {
    QPixmap image(ui->gvPlot->size());
    QPen pn(QColor("Blue"));
    pn.setWidth(3);

    updateCam(image);
    clear(image);
    float* yBufMin = new float[image.width()],
        *yBufMax = new float[image.width()];
    for (int i = 0; i < image.width(); i++) {
        yBufMin[i] = std::numeric_limits<float>::infinity();
        yBufMax[i] = -std::numeric_limits<float>::infinity();
    }

    int n = ui->sbHorizonCount->value();
    float yMin = -ui->dsbYDepth->value(), yMax = ui->dsbYDepth->value(),
        dy = (yMax - yMin) / n;

    float start, end, step;
    if (cam->inverseYPlaneOrder(yMin, yMax)) {
        start = 0;
        end = n;
        step = 1;
    }
    else {
        start = n;
        end = 0;
        step = -1;
    }

    for (float i = start; i != end; i += step) {
        float y = yMin + i * dy;
        cam->setPlaneY(y);
        std::function<float(float, float)> surf = surfaces[ui->cbxSurfaces->currentIndex()];
        plot([surf, y] (float x) { return surf(x, y); }, image, *cam, yBufMin, yBufMax, pn);
    }

    delete[] yBufMin;
    delete[] yBufMax;

    pmi->setPixmap(image);
}

void MainWindow::on_pbDraw_clicked()
{
    update();
}

void MainWindow::on_changed(QString s) {
    update();
}

void MainWindow::on_pbRLeft_clicked()
{
    cam->rotateZ(-1);
    update();
}


void MainWindow::on_pbRRight_clicked()
{
    cam->rotateZ(1);
    update();
}


void MainWindow::on_pbRDown_clicked()
{
    cam->rotateX(1);
    update();
}


void MainWindow::on_pbRUp_clicked()
{
    cam->rotateX(-1);
    update();
}


void MainWindow::on_cbxSurfaces_currentIndexChanged(int index)
{
    update();
}

