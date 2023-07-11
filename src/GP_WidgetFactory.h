
#pragma once

#include <QAction>
#include <QMenuBar>
#include <QToolBar>

#include "GP_ActionFactory.h"

class GP_ActionHandler;
class GP_ApplicationWindow;
class GP_ActionGroupManager;

class GP_WidgetFactory : public QObject {
    Q_OBJECT
public:
    explicit GP_WidgetFactory(GP_ApplicationWindow* main_win,
                              QMap<GP_ActionFactory::EnumEnv, QAction*>& action_map,
                              GP_ActionGroupManager* agm);
    ~GP_WidgetFactory() override = default;

    void createRightSidebar(GP_ActionHandler* action_handler) {}
    QToolBar* createCategoriesToolbar() {
        return nullptr;
    }
    void createStandardToolbars(GP_ActionHandler* action_handler) {}

    void createMenus(QMenuBar* menu_bar);

private:
    GP_ApplicationWindow* main_window = nullptr;
    QMap<GP_ActionFactory::EnumEnv, QAction*>& a_map;
    GP_ActionGroupManager* ag_manager = nullptr;
};