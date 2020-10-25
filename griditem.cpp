#include "griditem.h"
#include "warehousefloor.h"


GridItem::GridItem(WarehouseFloor* _parent, QString _name, int _cellX, int _cellY) : RenderItem(_parent, _name, (_cellX+0.5)*CW, (_cellY+0.5)*CH)
{
    cellX = _cellX;
    cellY = _cellY;
    color =  Qt::blue;
}

void GridItem::paintObject(QPainter &p)
{
    QBrush brush;
    brush.setColor(color);
    brush.setStyle(Qt::SolidPattern);
    p.setBrush(brush);
    p.drawRect(cellX*CW, cellY*CH, CW, CH);
}

bool GridItem::simulate()
{
    return true;
}
