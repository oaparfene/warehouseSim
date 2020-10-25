#ifndef RENDERITEM_H
#define RENDERITEM_H

#include <QObject>
#include <QPainter>
#include <QVector2D>

class WarehouseFloor;

class RenderItem : public QObject
{
    Q_OBJECT
public:
    RenderItem(WarehouseFloor* _parent, QString _name, float _x, float _y);
    virtual ~RenderItem() {};
    virtual void paintObject(QPainter &p) = 0;
    virtual bool simulate() = 0; // returns false if item was deleted during simulation timestep, true otherwise
    QVector2D getPos() const;
    int ID;

protected:
    static int itemCount;
    QVector2D pos;
    QString name;
    QColor color;
    WarehouseFloor* parent;
};

#endif // RENDERITEM_H
