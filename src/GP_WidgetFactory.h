
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

    void createMenus(QMenuBar* menu_bar);
    void createStandardToolbars(GP_ActionHandler* action_handler);

private:
    GP_ApplicationWindow* main_window = nullptr;
    QMap<GP_ActionFactory::EnumEnv, QAction*>& a_map;
    GP_ActionGroupManager* ag_manager = nullptr;

    QList<QAction*> file_actions;
    QList<QAction*> line_actions;
    QList<QAction*> circle_actions;
    QList<QAction*> curve_actions;
    QList<QAction*> ellipse_actions;
    QList<QAction*> polyline_actions;
    QList<QAction*> select_actions;
    QList<QAction*> dimension_actions;
    QList<QAction*> modify_actions;
    QList<QAction*> info_actions;
    QList<QAction*> layer_actions;
    QList<QAction*> block_actions;
};