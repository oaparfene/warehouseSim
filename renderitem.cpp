#include "renderitem.h"

int RenderItem::itemCount = 0;

RenderItem::RenderItem(WarehouseFloor *_parent, QString _name, float _x, float _y)
{
    parent = _parent;
    ID = ++itemCount;
    name = _name;
    pos = QVector2D(_x, _y);
}

QVector2D RenderItem::getPos() const
{
    return pos;
}
