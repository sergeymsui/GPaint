
#include <QToolBar>

#include "GP_WidgetFactory.h"
#include "GP_ApplicationWindow.h"

GP_WidgetFactory::GP_WidgetFactory(GP_ApplicationWindow *main_win, QMap<GP_ActionFactory::EnumEnv, QAction *> &action_map,
                                   GP_ActionGroupManager *agm)
        : QObject(nullptr),
        main_window(main_win),
        a_map(action_map),
        ag_manager(agm)
{
    file_actions
            << a_map[GP_ActionFactory::FileNew]
            << a_map[GP_ActionFactory::FileNewTemplate]
            << a_map[GP_ActionFactory::FileOpen]
            << a_map[GP_ActionFactory::FileSave]
            << a_map[GP_ActionFactory::FileSaveAs];
}

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

void GP_WidgetFactory::createStandardToolbars(GP_ActionHandler *action_handler) {
    QSizePolicy toolBarPolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    auto file_toolbar = new QToolBar(tr("File"), main_window);
    file_toolbar->setSizePolicy(toolBarPolicy);
    file_toolbar->addActions(file_actions);
    file_toolbar->addAction(a_map[GP_ActionFactory::FilePrint]);
    file_toolbar->addAction(a_map[GP_ActionFactory::FilePrintPreview]);

    //
    main_window->addToolBar(Qt::TopToolBarArea, file_toolbar);
}
