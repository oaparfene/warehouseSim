#ifndef WAREHOUSEFLOOR_H
#define WAREHOUSEFLOOR_H

#include <QWidget>
#include <QTimer>
#include <QPainter>
#include <QRandomGenerator>
#include <QDebug>
#include "cargoitem.h"
#include "mulerobot.h"
#include "depositdock.h"

#define GH 10
#define GW 20
#define CH 50
#define CW 50

class WarehouseFloor : public QWidget
{
    Q_OBJECT
public:
    WarehouseFloor(QWidget *parent = 0);
    virtual ~WarehouseFloor() {};
    virtual void paintEvent(QPaintEvent *event);
    void startSim();
    void newOrder();

    CargoItem* getOrder();
    DepositDock* getDep() const;
    QVector2D getDepPos() const;
    void removeCargo(CargoItem*);

    const int gridHeight;
    const int gridWidth;
    const int cellHeight;
    const int cellWidth;

private slots:
    void simulate();

private:
    DepositDock* dep;
    QList<RenderItem*> itemList;
    QList<CargoItem*> cargoList;
    void instance_environment();
    void paint_renderItems(QPainter &p);
    QTimer* timer;
};

#endif // WAREHOUSEFLOOR_H
