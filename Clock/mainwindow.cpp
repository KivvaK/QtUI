#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <cmath>

#include <QTime>

void clear(QPixmap& image, const QColor& color = QColor::fromRgb(255, 255, 255)) {
    QPainter p(&image);
    p.fillRect(image.rect(), color);
}

void clockFace(QPixmap& image,
               const QPen& pn,
               const QBrush& br,
               int x, int y,
               float r, float dashPercent) {
    QPainter p(&image);
    p.setPen(pn);
    p.setBrush(br);

    QPointF c(x, y);
    p.drawEllipse(c.x() - r, c.y() - r, 2*r, 2*r);

    float dashLen = r * dashPercent;
    float dx1 = 0, dy1 = -r,
          dx2 = 0, dy2 = -r * (1 - dashPercent);

    const int n = 12;
    float dphi = 2 * M_PI / n;
    for (int i = 0; i < n; i++) {
        float phi = i * dphi;
        float cs = cos(phi), sn = sin(phi);

        QPointF p1(round(c.x() + dx1 * cs + dy1 * sn),
                   round(c.y() - dx1 * sn + dy1 * cs));
        QPointF p2(round(c.x() + dx2 * cs + dy2 * sn),
                  round(c.y() - dx2 * sn + dy2 * cs));

        p.drawLine(p1, p2);
    }
}

void drawArrows(QPixmap& image,
                const QPen& pnS,
                const QPen& pnM,
                const QPen& pnH,
                int x, int y,
                int slen, int mlen, int hlen,
                const QTime& tm) {
    QPainter p(&image);

    QPointF c(x, y);
    float dxH = 0, dyH = -hlen,
          dxM = 0, dyM = -mlen,
          dxS = 0, dyS = -slen;
    int h = tm.hour(), m = tm.minute(), s = tm.second();
    float phiS = 2 * M_PI * s / 60,
          phiM = (2 * M_PI * m + phiS) / 60,
          phiH = (2 * M_PI * h + phiM) / 12;

    float csH = cos(phiH), snH = sin(phiH),
          csM = cos(phiM), snM = sin(phiM),
          csS = cos(phiS), snS = sin(phiS);
    QPointF H(c.x() + dxH * csH - dyH * snH,
              c.y() + dxH * snH + dyH * csH),
            M(c.x() + dxM * csM - dyM * snM,
              c.y() + dxM * snM + dyM * csM),
            S(c.x() + dxS * csS - dyS * snS,
              c.y() + dxS * snS + dyS * csS);

    p.setPen(pnH);
    p.drawLine(c, H);
    p.setPen(pnM);
    p.drawLine(c, M);
    p.setPen(pnS);
    p.drawLine(c, S);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    pn = QPen(QColor::fromRgb(0, 0, 0));
    pn.setWidth(10);
    pnH = QPen(QColor::fromRgb(150, 88, 0));
    pnH.setWidth(10);
    pnM = QPen(QColor::fromRgb(200, 118, 0));
    pnM.setWidth(7);
    pnS = QPen(QColor::fromRgb(255, 150, 0));
    pnS.setWidth(3);

    br = QBrush(QColor::fromRgb(200, 200, 200));

    QGraphicsScene* scene = new QGraphicsScene(this);
    pmi = new QGraphicsPixmapItem();
    scene->addItem(pmi);

    ui->gvDraw->setScene(scene);

    timer.setInterval(1000);
    connect(
        &timer, &QTimer::timeout,
        this, &MainWindow::on_timeout
    );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_timeout() {
    QPixmap image(ui->gvDraw->rect().size());
    clear(image, QColor::fromRgb(0, 0, 255));
    int x = image.width() / 2, y = image.height() / 2;
    float r = 200;
    clockFace(image, pn, br, x, y, r, 0.2);
    drawArrows(image,
               pnS, pnM, pnH,
               x, y,
               r * 0.9, r * 0.7, r * 0.4,
               QDateTime::currentDateTime().time());
    pmi->setPixmap(image);
}

void MainWindow::on_pbStartStop_clicked()
{
    QPushButton* pb = dynamic_cast<QPushButton*>(sender());
    if (timer.isActive()) {
        timer.stop();
        pb->setText("Пуск");
    }
    else {
        timer.start();
        pb->setText("Стоп");
    }
}

