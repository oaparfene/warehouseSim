#include "depositdock.h"
#include "warehousefloor.h"

DepositDock::DepositDock(WarehouseFloor* _parent, QString _name, int _cellX, int _cellY): GridItem(_parent, _name, _cellX, _cellY)
{
    color = QColor(0xB48EAD);
}

bool DepositDock::unloadCargo(QVector2D mulePos)
{
    if (mulePos.x() > cellX*CW && mulePos.x() < (cellX+1)*CW && mulePos.y() > cellY*CH && mulePos.y() < (cellY+1)*CH)
    {
        color = QColor(0xA3BE8C);
        return true;
    }
    return false;
}
