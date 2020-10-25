#ifndef KINEMATICITEM_H
#define KINEMATICITEM_H

#include "renderitem.h"

class KinematicItem : public RenderItem
{
public:
    KinematicItem(WarehouseFloor* _parent, QString _name, float _x, float _y, float _speed, float _r);
    virtual ~KinematicItem() {};
    void paintObject(QPainter &p) override;
    virtual bool simulate() override;

protected:
    float speed,r;
    QVector2D velDir;
};

#endif // KINEMATICITEM_H
