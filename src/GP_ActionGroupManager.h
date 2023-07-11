#pragma once

#include <QActionGroup>

#include "GP_ApplicationWindow.h"

class GP_ActionGroupManager : public QObject {
    Q_OBJECT
public:
    explicit GP_ActionGroupManager(GP_ApplicationWindow* parent = nullptr)
        : QObject(parent),
        block(new QActionGroup(this)),
        circle(new QActionGroup(this)),
        curve(new QActionGroup(this)),
        edit(new QActionGroup(this)),
        ellipse(new QActionGroup(this)),
        file(new QActionGroup(this)),
        dimension(new QActionGroup(this)),
        info(new QActionGroup(this)),
        layer(new QActionGroup(this)),
        line(new QActionGroup(this)),
        modify(new QActionGroup(this)),
        options(new QActionGroup(this)),
        other(new QActionGroup(this)),
        polyline(new QActionGroup(this)),
        restriction(new QActionGroup(this)),
        select(new QActionGroup(this)),
        snap(new QActionGroup(this)),
        snap_extras(new QActionGroup(this)),
        view(new QActionGroup(this)),
        widgets(new QActionGroup(this))
    {}

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
