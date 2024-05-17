#include "mainwindow.h"
#include "./ui_mainwindow.h"

void clear(QPixmap& image,
           const QColor& color = QColor::fromRgb(255, 255, 255)) {
    QPainter p(&image);
    p.fillRect(image.rect(), color);
}

void drawLine(QPixmap& image,
              const QPen& pn,
              const QPointF& start,
              const QPointF& end) {
    QPainter p(&image);
    p.setPen(pn);
    p.setRenderHint(QPainter::Antialiasing);
    p.drawLine(start, end);
}

void floodFillStep(QImage& img, std::stack<QPoint>& stack,
                   const QColor& background, const QColor& color) {
    int w1 = img.width() - 1, h1 = img.height() - 1;

    QPoint p = stack.top();
    stack.pop();

    for (int y = std::max(p.y() - 1, 0); y <= std::min(p.y() + 1, h1); y++)
        for (int x = std::max(p.x() - 1, 0); x <= std::min(p.x() + 1, w1); x++) {
            QPoint neighbour(x, y);
            if (img.pixelColor(neighbour) == background) {
                img.setPixelColor(neighbour, color);
                stack.push(neighbour);
            }
        }
}

// Заливка
void MainWindow::floodFill(QPixmap& pixmap, const QPoint& start, const QColor& color) {
    floodImg = pixmap.toImage();

    background = floodImg.pixelColor(start);
    if (background != color) {
        stack = std::stack<QPoint>();

        floodImg.setPixelColor(start, color);
        stack.push(start);

        if (ui->cbxAnimatedFloodFill->checkState() == Qt::Checked) {
            floodColor = color;
            timer.start();
        }
        else {
            while (!stack.empty())
                floodFillStep(floodImg, stack, background, color);

            pixmap = QPixmap::fromImage(floodImg);
            floodInProgress = false;
        }
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer.setInterval(1);

    image = QPixmap(800, 600);
    clear(image);

    QGraphicsScene* scene = new QGraphicsScene();
    pmi = new QGraphicsPixmapItem(image);
    scene->addItem(pmi);

    ui->gvDrawer->setScene(scene);

    pen = QPen(QColor::fromRgb(0, 0, 0));
    pen.setWidth(ui->lblWidth->text().toInt());

    // Присоединим сигналы о событиях мыши к соответствующим слотам
    connect(
        ui->gvDrawer, &MouseGraphicsView::mouseDown,
        this, &MainWindow::on_mouseDown
    );
    connect(
        ui->gvDrawer, &MouseGraphicsView::mouseUp,
        this, &MainWindow::on_mouseUp
    );
    connect(
        ui->gvDrawer, &MouseGraphicsView::mouseMove,
        this, &MainWindow::on_mouseMove
    );
    connect(
        ui->gvDrawer, &MouseGraphicsView::mouseWheel,
        this, &MainWindow::on_mouseWheel
    );

    connect(
        &timer, &QTimer::timeout,
        this, &MainWindow::on_timeout
    );
}

// Реализуем обработку сигналов мыши в слотах
void MainWindow::on_mouseDown(const QPointF& pos, Qt::MouseButton button) {
    if (button == Qt::MouseButton::LeftButton) {
        leftPressed = true;
        // Преобразуем положение курсора из координат виджета в координаты сцены
        // и запоминаем положение курсора мыши в качестве предыдущего
        QPointF scenePos = ui->gvDrawer->mapToScene(QPoint(pos.x(), pos.y()));
        prev.setX(scenePos.x());
        prev.setY(scenePos.y());
    }
}

void MainWindow::on_mouseUp(const QPointF& pos, Qt::MouseButton button) {
    if (button == Qt::MouseButton::LeftButton)
        leftPressed = false;
    else
        if (button == Qt::MouseButton::RightButton && !floodInProgress) {
            floodInProgress = true;

            floodFill(image,
                      ui->gvDrawer->mapToScene(pos.toPoint()).toPoint(),
                      QColor("Lime"));
            pmi->setPixmap(image);
        }
}

void MainWindow::on_mouseMove(const QPointF& pos) {
    if (leftPressed) {
        // Преобразуем положение курсора из координат виджета в координаты сцены
        QPointF scenePos = ui->gvDrawer->mapToScene(QPoint(pos.x(), pos.y()));
        QPoint cur(scenePos.x(), scenePos.y());
        // Проводим линию
        drawLine(image, pen, prev, cur);
        pmi->setPixmap(image);
        // Запоминаем положение курсора мыши в качестве предыдущего
        prev = cur;
    }
}

void MainWindow::on_mouseWheel(int delta) {
    int w = pen.width() + delta / wheelDeltaStep;
    if (w > 0) {
        pen.setWidth(w);
        ui->lblWidth->setText(QString::number(pen.width()));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pbClear_clicked()
{
    clear(image);
    pmi->setPixmap(image);
}

void MainWindow::on_timeout() {
    if (!stack.empty()) {
        floodFillStep(floodImg, stack, background, floodColor);
        pmi->setPixmap(QPixmap::fromImage(floodImg));
    }
    else {
        timer.stop();
        image = QPixmap::fromImage(floodImg);
        floodInProgress = false;
    }
}
