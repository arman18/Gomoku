#include "cell.h"
#include <QDebug>
Cell::Cell(QPoint position)
{
    this->position = position;
    is_setImage = false;
    setStyleSheet("QLabel { background-color : green; color : blue; }");
}

void Cell::setImage(QImage image)
{
    setPixmap(QPixmap::fromImage(image));
    //repaint();
    is_setImage = true;
}

void Cell::clearImage()
{
    clear();
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
    return QSize(25,25);
}

