#ifndef MULEROBOT_H
#define MULEROBOT_H

#include "kinematicitem.h"
#include "cargoitem.h"

class MuleRobot : public KinematicItem
{
public:
    MuleRobot(WarehouseFloor* _parent, QString _name, float _x, float _y, float _speed, float _r, int _cargoBaySize);
    virtual ~MuleRobot() {};
    virtual bool simulate() override;

private:
    int cargoBaySize;
    int cargoBayCurrent;
    QList<CargoItem*> orderQueue;
    QList<CargoItem*> cargoBayQueue;
    void fetchOrder();
    void deposit();
    void attemptInteraction();
};

#endif // MULEROBOT_H
