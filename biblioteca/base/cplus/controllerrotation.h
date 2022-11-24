#ifndef CONTROLLERROTATION_H
#define CONTROLLERROTATION_H

#include <QObject>



class ControllerRotation : public QObject
{Q_OBJECT
    Q_PROPERTY(double angulo READ getAngulo WRITE setAngulo NOTIFY anguloChanged)
    Q_PROPERTY(double axisX READ getAxisX WRITE setAxisX NOTIFY axisXChanged)
    Q_PROPERTY(double axisY READ getAxisY WRITE setAxisY NOTIFY axisYChanged)
    Q_PROPERTY(double axisZ READ getAxisZ WRITE setAxisZ NOTIFY axisZChanged)
    Q_PROPERTY(double originX READ getOriginX WRITE setOriginX NOTIFY originXChanged)
    Q_PROPERTY(double originY READ getOriginY WRITE setOriginY NOTIFY originYChanged)
    Q_PROPERTY(QList<double> valuesofRotation READ getValuesofRotation WRITE setValuesofRotation NOTIFY valuesofRotationChanged)

public:
    ControllerRotation(QObject * parent= nullptr);

    void setAngulo(double i);
    void setAxisX(double i);
    void setAxisY(double i);
    void setAxisZ(double i);
    void setOriginX(double i);
    void setOriginY(double i);
    void setValuesofRotation(QList<double> list);




    Q_INVOKABLE double getAngulo();
   Q_INVOKABLE double getAxisX();
   Q_INVOKABLE double getAxisY();
  Q_INVOKABLE double getAxisZ();
  Q_INVOKABLE double getOriginX();
   Q_INVOKABLE double getOriginY();
    Q_INVOKABLE QList<double> getValuesofRotation();

    signals:
    void anguloChanged(double i);
    void axisXChanged(double i);
    void axisYChanged(double i);
    void axisZChanged(double i);
    void originXChanged(double i);
    void originYChanged(double i);
    void valuesofRotationChanged(QList<double> list);

private:
    double angulo;
    double axisX;
    double axisY;
    double axisZ;
    double originX;
    double originY;
    QList<double> valuesofRotation;
};

#endif // CONTROLLERROTATION_H
