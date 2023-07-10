#pragma once

#include <QActionGroup>

#include "GP_ApplicationWindow.h"

class GP_ActionGroupManager : public QObject {
    Q_OBJECT
public:
    explicit GP_ActionGroupManager(GP_ApplicationWindow* parent = nullptr) {}

    QActionGroup* block = nullptr;
    QActionGroup* circle = nullptr;
    QActionGroup* curve = nullptr;
    QActionGroup* edit = nullptr;
    QActionGroup* ellipse = nullptr;
    QActionGroup* file = nullptr;
    QActionGroup* dimension = nullptr;
    QActionGroup* info = nullptr;
    QActionGroup* layer = nullptr;
    QActionGroup* line = nullptr;
    QActionGroup* modify = nullptr;
    QActionGroup* options = nullptr;
    QActionGroup* other = nullptr;
    QActionGroup* polyline = nullptr;
    QActionGroup* restriction = nullptr;
    QActionGroup* select = nullptr;
    QActionGroup* snap = nullptr;
    QActionGroup* snap_extras = nullptr;
    QActionGroup* view = nullptr;
    QActionGroup* widgets = nullptr;
};
