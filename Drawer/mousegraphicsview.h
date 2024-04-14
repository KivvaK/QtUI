#ifndef MOUSEGRAPHICSVIEW_H
#define MOUSEGRAPHICSVIEW_H

// Подключаем необходимые библиотеки
#include <QGraphicsView>
#include <QMouseEvent>

class MouseGraphicsView : public QGraphicsView // Наследуем наш виджет от QGraphicsView
{
    Q_OBJECT

public:
    // Добавляем конструкторы с такими же параметрами, как у QGraphicsView
    // (чтобы потом в .cpp-файле вызвать соответствующие конструкторы QGraphicsView
    //  перед кодом конструктора нашего виджета)
    MouseGraphicsView(QWidget *parent = nullptr);
    MouseGraphicsView(QGraphicsScene *scene, QWidget *parent = nullptr);

    // Пишем прототипы сигналов о событиях мыши
    // (для сигналов нужны только прототипы, реализация не нужна)
signals:
    // Пусть вместе с сигналом о нажатии кнопки мыши передаются
    // текущие координаты курсора pos и нажатая кнопка мыши button
    void mouseDown(const QPointF& pos, Qt::MouseButton button);
    // Пусть вместе с сигналом об отпускании кнопки мыши передаются
    // текущие координаты курсора pos и нажатая кнопка мыши button
    void mouseUp(const QPointF& pos, Qt::MouseButton button);
    // Пусть вместе с сигналом движении курсора мыши передаются
    // текущие координаты курсора pos
    void mouseMove(const QPointF& pos);
    // Пусть вместе с сигналом вращении колёсика мыши передаётся
    // значение поворота колёсика delta
    void mouseWheel(int delta);

    // Переопределяем функции обработки событий мыши базового класса QGraphicsView
private:
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void wheelEvent(QWheelEvent* event) override;
};

#endif // MOUSEGRAPHICSVIEW_H
