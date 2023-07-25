
#pragma once

#include <QVector>
#include <QTabWidget>
#include <QMainWindow>

#include "GP_ActionFactory.h"
#include "GP_TabWindow.h"

class GP_Document;
class GP_TabWidget;
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

    QSharedPointer<GP_TabWidget> tabAreaCAD;
    QVector<QSharedPointer<GP_TabWindow>> m_tabWindows; // tab window buffer

    QSharedPointer<GP_TabWindow> fileNew(GP_Document*);
public slots:

    void slotFileOpen() {};
    void slotZoomPan() {};
    void slotFileNew();;
    void slotFileSave() {};
    void slotFileSaveAs() {};
    void slotFileQuit() {};
};
