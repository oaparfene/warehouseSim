#include "kinematicitem.h"

KinematicItem::KinematicItem(WarehouseFloor* _parent, QString _name, float _x, float _y, float _speed, float _r) : RenderItem(_parent, _name, _x, _y)
{
    r = _r;
    speed = _speed;
    velDir = QVector2D(0,0);
    color = Qt::red;
}

void KinematicItem::paintObject(QPainter &p)
{
    QBrush brush;
    brush.setColor(color);
    brush.setStyle(Qt::SolidPattern);
    p.setBrush(brush);
    p.drawEllipse(pos.x() - r, pos.y() -r, 2*r,2*r);
}

bool KinematicItem::simulate()
{
    pos += velDir*speed;
    return true;
}
