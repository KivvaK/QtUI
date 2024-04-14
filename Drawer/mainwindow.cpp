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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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

