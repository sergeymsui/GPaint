
#pragma once

#include <QObject>

class GP_ActionHandler :  public QObject {
    Q_OBJECT
public:
    explicit GP_ActionHandler(QObject* parent = nullptr);
    ~GP_ActionHandler() override = default;
};
