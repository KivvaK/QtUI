#include "mainwindow.h"
#include "./ui_mainwindow.h"

// Функция очистки изображения image цветом color
void clear(QPixmap& image, const QColor color = QColor::fromRgb(0, 255, 255)) {
    // Создаём QPainter для изображения image
    QPainter p(&image);
    // Рисуем закрашенный прямоугольник размером с прямоугольник изображения
    // цветом color
    p.fillRect(image.rect(), color);

    // При выходе из функции p уничтожается, и все изменения сохраняются в image
}

// Функция рисования треугольника на изображении image пером pn
void draw(QPixmap& image, const QPen& pn) {
    // Создаём QPainter для изображения image
    QPainter p(&image);
    // Задаём перо для рисования
    p.setPen(pn);

    // Рисуем треугольник
    p.drawLine(100, 100, 200, 100);
    p.drawLine(200, 100, 150, 200);
    p.drawLine(150, 200, 100, 100);

    // При выходе из функции p уничтожается, и все изменения сохраняются в image
}

// Функция вывода текста text в положение (x, y)
// на изображении image пером pn и шрифтом fnt
void print(const QString& text,
           int x, int y,
           QPixmap& image,
           const QPen& pn,
           const QFont& fnt) {
    // Создаём QPainter для изображения image
    QPainter p(&image);
    // Задаём перо и шрифт для вывода текста
    p.setPen(pn);
    p.setFont(fnt);

    // Выводим текст на изображение
    p.drawText(x, y, text);

    // При выходе из функции p уничтожается, и все изменения сохраняются в image
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Создаём сцену - сцена содержит отображаемые объекты
    QGraphicsScene* scene = new QGraphicsScene(this);
    // Добавляем изображение в сцену. При этом создаётся отображаемый
    // объект класса QGraphicsPixmapItem - сохраняем его адрес в pmi
    pmi = scene->addPixmap(image);
    // Устанавливаем созданную сцену в качестве сцены gvDrawer
    ui->gvDrawer->setScene(scene);

    // Задаём цвет фона - серый
    bgColor = QColor::fromRgb(150, 150, 150);
    // Создаём перо жёлтого цвета
    pn = QPen(QColor::fromRgb(255, 255, 0));
    // Устанавливаем толщину пера 3 пикселя
    pn.setWidth(3);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Слот для сигнала нажатия на кнопку pbDraw
void MainWindow::on_pbDraw_clicked()
{
    // Создаём новое изображение размером с прямоугольник gvDrawer'а,
    // сохраняем в image
    image = QPixmap(ui->gvDrawer->rect().size());
    // Вызываем функцию очистки этого изображения (см. выше) цветом фона
    clear(image, bgColor);

    // Рисуем треугольник (см. выше) при помощи пера
    draw(image, pn);

    // Создаём шрифт семейства Helvetica, размер 16, курсивный
    QFont fnt("Helvetica", 16);
    fnt.setItalic(true);
    // Выводим на изображение текст (в нижний угол нарисованного треугольника)
    print("Hello, world!", 150, 200, image, pn, fnt);

    // Меняем изображение в отображаемом объекте сцены на новое
    pmi->setPixmap(image);
}

