#ifndef DEPOSITDOCK_H
#define DEPOSITDOCK_H

#include "griditem.h"

class DepositDock : public GridItem
{
public:
    DepositDock(WarehouseFloor* _parent, QString _name, int _cellX, int _cellY);
    virtual ~DepositDock() {};
    bool unloadCargo(QVector2D mulePos);
};

#endif // DEPOSITDOCK_H
