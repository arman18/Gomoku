#ifndef CELL_H
#define CELL_H

#include <QLabel>



class Cell : public QLabel
{
    Q_OBJECT
private:
    QPoint position;
    bool is_setImage;
public:
    Cell(QPoint position);
    void setImage(QImage image);
    void clearImage();
    bool isImageSet();
    void mousePressEvent(QMouseEvent *ev) override;
    QSize sizeHint() const override;
signals:
    void getPosition(QPoint pos);

};

#endif // CELL_H
