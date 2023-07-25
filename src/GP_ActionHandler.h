
#pragma once

#include <QDebug>
#include <QObject>

class GP_ActionHandler :  public QObject {
    Q_OBJECT
public:
    explicit GP_ActionHandler(QObject* parent = nullptr);
    ~GP_ActionHandler() override = default;

public slots:
    void slotZoomPan() {
        qDebug() << "slotZoomPan" ;
    }
};
