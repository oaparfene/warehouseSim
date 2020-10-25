#include "warehousefloor.h"

WarehouseFloor::WarehouseFloor(QWidget *parent) :
    QWidget(parent),
    gridHeight(GH),
    gridWidth(GW),
    cellHeight(CH),
    cellWidth(CW)
{
    timer = new QTimer(nullptr);
    timer->setInterval(30);
    connect(timer, SIGNAL(timeout()), this, SLOT(simulate()));
    instance_environment();
}

void WarehouseFloor::instance_environment()
{
    dep = new DepositDock(this, "Deposit Bay", 0, 0);
    //itemList.append(dep);
    MuleRobot* mule = new MuleRobot(this, "mule1", 100,100, 5, 25, 10);
    itemList.append(mule);
    update();
}

void WarehouseFloor::paintEvent(QPaintEvent *)
{
    QPainter p(this);

    for (int i=0; i<=GW; i++)
    {
        p.drawLine((i*CW),0,(i*CW),CH*GH);
    }
    for (int i=0; i<=GH; i++)
    {
        p.drawLine(0,(i*CH),CW*GW,(i*CH));
    }


    paint_renderItems(p);
}

void WarehouseFloor::paint_renderItems(QPainter &p)
{
    QList<RenderItem*>::iterator it;
    for (it = itemList.begin() ; it != itemList.end() ; it++)
    {
        (*it)->paintObject(p);
    }
    QList<CargoItem*>::iterator cit;
    for (cit = cargoList.begin() ; cit != cargoList.end() ; cit++)
    {
        (*cit)->paintObject(p);
    }
    dep->paintObject(p);
}

void WarehouseFloor::startSim()
{
    timer->start();
}

void WarehouseFloor::simulate()
{
    QList<RenderItem*>::iterator it;
    for (it = itemList.begin() ; it != itemList.end() ; it++)
    {
        if((*it)->simulate())
            break;
    }
    update();
}

void WarehouseFloor::newOrder()
{
    int orderSize = QRandomGenerator::global()->bounded(1,10);
    for (int i = 0 ; i < orderSize ; i++)
    {
        float tempx = QRandomGenerator::global()->bounded(2,GW-1);
        float tempy = QRandomGenerator::global()->bounded(0,GH*0.8);
        if (tempy >= GH*0.4)
            tempy += GH*0.2;
        tempx = int(tempx);
        tempy = int(tempy);
        CargoItem* obj = new CargoItem(this, "box" + QString::number(i+1), tempx, tempy, 1);
        cargoList.append(obj);
        itemList.append(obj);
    }
    update();
}

CargoItem* WarehouseFloor::getOrder()
{
    if (cargoList.isEmpty())
        return nullptr;
    return cargoList.takeFirst();
}

DepositDock* WarehouseFloor::getDep() const
{
    return dep;
}

QVector2D WarehouseFloor::getDepPos() const
{
    return dep->getPos();
}

void WarehouseFloor::removeCargo(CargoItem * cargo)
{
    itemList.removeOne(cargo);
}
