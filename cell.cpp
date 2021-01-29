#include "cell.h"

Cell::Cell(QPoint position)
{
    this->position = position;
    is_setImage = false;
    setStyleSheet("QLabel { background-color : red; color : blue; }");
}

void Cell::setImage(QImage image)
{
    setPixmap(QPixmap::fromImage(image));
    is_setImage = true;
}

void Cell::clearImage()
{
    repaint();
    is_setImage = false;
}

bool Cell::isImageSet()
{
    return is_setImage;
}

void Cell::mousePressEvent(QMouseEvent *ev)
{
    if(is_setImage) return;
    emit(getPosition(position));
}

QSize Cell::sizeHint() const
{
    return QSize(50,50);
}

