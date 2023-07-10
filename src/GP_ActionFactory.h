
#pragma once

#include "GP_ActionGroupManager.h"
#include "GP_ActionHandler.h"
#include "GP_ApplicationWindow.h"
#include <QObject>

class GP_ActionFactory : public QObject {
    Q_OBJECT
public:
    explicit GP_ActionFactory(GP_ApplicationWindow* parent, GP_ActionHandler* a_handler);
    void fillActionContainer(QMap<QString, QAction*>& a_map, GP_ActionGroupManager* agm);
    void commonActions(QMap<QString, QAction*>& a_map, GP_ActionGroupManager* agm);
    bool using_theme;

private:
    GP_ApplicationWindow* main_window;
    GP_ActionHandler* action_handler;
};
