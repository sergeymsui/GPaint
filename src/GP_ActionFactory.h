
#pragma once

#include <QAction>
#include <QObject>

class GP_ActionHandler;
class GP_ApplicationWindow;
class GP_ActionGroupManager;

class GP_ActionFactory : public QObject {
    Q_OBJECT
public:
    enum EnumEnv {
        FileNew,
        FileOpen,
        FileNewTemplate,
        FileSave,
        FileSaveAs,
        FileQuit,
        // --
        ZoomPan,
    };

    explicit GP_ActionFactory(GP_ApplicationWindow* parent, GP_ActionHandler* a_handler);
    void fillActionContainer(QMap<EnumEnv, QAction*>& a_map, GP_ActionGroupManager* agm);
    void commonActions(QMap<QString, QAction*>& a_map, GP_ActionGroupManager* agm);
    bool using_theme;

private:
    GP_ApplicationWindow* main_window = nullptr;
    GP_ActionHandler* action_handler = nullptr;
};
