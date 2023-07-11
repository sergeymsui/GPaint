
#include "GP_WidgetFactory.h"

GP_WidgetFactory::GP_WidgetFactory(GP_ApplicationWindow *main_win, QMap<GP_ActionFactory::EnumEnv, QAction *> &action_map,
                                   GP_ActionGroupManager *agm)
        : QObject(nullptr),
        main_window(main_win),
        a_map(action_map),
        ag_manager(agm) {}

void GP_WidgetFactory::createMenus(QMenuBar *menu_bar) {
    auto file_menu = new QMenu(tr("&File"), menu_bar);
    file_menu->setTearOffEnabled(true);
    file_menu->addAction(a_map[GP_ActionFactory::FileNew]);
    file_menu->addAction(a_map[GP_ActionFactory::FileNewTemplate]);
    file_menu->addAction(a_map[GP_ActionFactory::FileOpen]);
    file_menu->addSeparator();
    file_menu->addAction(a_map[GP_ActionFactory::FileSave]);
    file_menu->addAction(a_map[GP_ActionFactory::FileSaveAs]);
    file_menu->addSeparator();
    file_menu->addAction(a_map[GP_ActionFactory::FileQuit]);
    menu_bar->addMenu(file_menu);
}