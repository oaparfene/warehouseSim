#ifndef GRIDITEM_H
#define GRIDITEM_H

#include "renderitem.h"

class GridItem : public RenderItem
{
public:
    GridItem(WarehouseFloor* _parent, QString _name, int _cellX, int _cellY);
    virtual ~GridItem() {};
    void paintObject(QPainter &p) override;
    virtual bool simulate() override;

protected:
    int cellX, cellY;

};

#endif // GRIDITEM_H
