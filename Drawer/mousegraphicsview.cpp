#include "mousegraphicsview.h"

// Перед кодом конструктора нашего виджета вызываем конструктор базового
MouseGraphicsView::MouseGraphicsView(QWidget *parent) : QGraphicsView(parent) {

}

// Перед кодом конструктора нашего виджета вызываем конструктор базового
MouseGraphicsView::MouseGraphicsView(QGraphicsScene *scene,
                                     QWidget *parent) : QGraphicsView(parent) {

}

// В коде переопределённых обработчиков событий мыши просто посылаем
// соответствующие сигналы, передав вместе с ними необходимые параметры
void MouseGraphicsView::mousePressEvent(QMouseEvent* event) {
    emit mouseDown(event->pos(), event->button());
}

void MouseGraphicsView::mouseReleaseEvent(QMouseEvent* event) {
    emit mouseUp(event->pos(), event->button());
}

void MouseGraphicsView::mouseMoveEvent(QMouseEvent* event) {
    emit mouseMove(event->pos());
}

void MouseGraphicsView::wheelEvent(QWheelEvent* event) {
    emit mouseWheel(event->angleDelta().y() / 8);
}
