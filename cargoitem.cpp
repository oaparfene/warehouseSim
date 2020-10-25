#include "cargoitem.h"
#include "warehousefloor.h"

CargoItem::CargoItem(WarehouseFloor* _parent, QString _name, int _cellX, int _cellY, int _size) : GridItem(_parent, _name, _cellX, _cellY)
{
    size = _size;
    color = QColor(0x5E81AC);
}

int CargoItem::getSize() const
{
    return size;
}

bool CargoItem::loadCargo(QVector2D mulePos)
{
    if (mulePos.x() > cellX*CW && mulePos.x() < (cellX+1)*CW && mulePos.y() > cellY*CH && mulePos.y() < (cellY+1)*CH)
    {
        color = QColor(0xBF616A);
        return true;
    }
    return false;
}
