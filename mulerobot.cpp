#include "mulerobot.h"
#include "warehousefloor.h"

MuleRobot::MuleRobot(WarehouseFloor* _parent, QString _name, float _x, float _y, float _speed, float _r, int _cargoBaySize) : KinematicItem(_parent, _name, _x, _y, _speed, _r)
{
    color = QColor(0xEBCB8B);
    cargoBaySize = _cargoBaySize;
    cargoBayCurrent = 0;
}

bool MuleRobot::simulate()
{
    fetchOrder();
    if (orderQueue.isEmpty())
    {
        velDir = QVector2D(0, 0);
        deposit();
    }
    else
    {
        CargoItem* target = orderQueue.first();
        if (target->getSize() <= cargoBaySize - cargoBayCurrent)
        {
            QVector2D dest = target->getPos();
            velDir = (dest - pos).normalized();
            if (target->loadCargo(pos))
            {
                orderQueue.removeFirst();
                cargoBayQueue.append(target);
                cargoBayCurrent += target->getSize();
            }
        }
        else
        {
            velDir = QVector2D(0, 0);
            deposit();
        }
    }

    attemptInteraction();
    KinematicItem::simulate();
    return true;
}

void MuleRobot::fetchOrder()
{
    if (orderQueue.isEmpty())
    {
        while(orderQueue.size()<=5)
        {
            CargoItem* temp = parent->getOrder();
            if (temp == nullptr)
                break;
            orderQueue.append(temp);
        }

    }
}

void MuleRobot::deposit()
{
    if (!cargoBayQueue.isEmpty())
    {
        QVector2D dest = parent->getDepPos();
        velDir = (dest - pos).normalized();
    }
    //qDebug() << "deposited";
    //cargoBayQueue.clear(); // to do: pass on to deposit bay
}

void MuleRobot::attemptInteraction()
{
    DepositDock* target = parent->getDep();
    if (target->unloadCargo(pos))
    {
        QList<CargoItem*>::iterator it;
        for (it = cargoBayQueue.begin() ; it != cargoBayQueue.end() ; it++)
        {
            parent->removeCargo(*it);
        }
        cargoBayQueue.clear();
        cargoBayCurrent = 0;
    }
    //qDebug() << "attempted interaction";
}
