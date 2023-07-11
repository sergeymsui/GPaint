
#pragma once

#include <QMainWindow>

#include "GP_ActionFactory.h"

class GP_ActionHandler;
class GP_ActionGroupManager;

class GP_ApplicationWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit GP_ApplicationWindow(QWidget* parent = nullptr);
    ~GP_ApplicationWindow() override = default;
private:
    GP_ApplicationWindow* appWindow = nullptr;
    GP_ActionHandler* actionHandler = nullptr;

    GP_ActionGroupManager* ag_manager = nullptr;
    QMap<GP_ActionFactory::EnumEnv, QAction*> a_map;
};
