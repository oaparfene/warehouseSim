#ifndef CARGOITEM_H
#define CARGOITEM_H

#include "griditem.h"

class CargoItem : public GridItem
{
public:
    CargoItem(WarehouseFloor* _parent, QString _name, int _cellX, int _cellY, int _size);
    virtual ~CargoItem() {};
    int getSize() const;
    bool loadCargo(QVector2D mulePos);

private:
    int cargoID;
    int size;

};

#endif // CARGOITEM_H
