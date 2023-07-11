
#include "GP_ActionFactory.h"
#include "GP_ApplicationWindow.h"
#include "GP_ActionHandler.h"
#include "GP_ActionGroupManager.h"

GP_ActionFactory::GP_ActionFactory(GP_ApplicationWindow *parent, GP_ActionHandler *a_handler)
    : QObject(parent),
    using_theme(false),
    main_window(parent),
    action_handler(a_handler) {}

void GP_ActionFactory::fillActionContainer(QMap<EnumEnv, QAction *> &a_map, GP_ActionGroupManager *agm) {
    auto panningZoomAction = new QAction(tr("Zoom &Panning"), agm->other);
    panningZoomAction->setIcon(QIcon(":/icons/zoom_pan.svg"));
    connect(panningZoomAction, SIGNAL(triggered()), action_handler, SLOT(slotZoomPan()));
    panningZoomAction->setObjectName("ZoomPan");
    a_map[EnumEnv::ZoomPan] = panningZoomAction;

    auto newFileAction = new QAction(tr("&New"), agm->other);
    newFileAction->setIcon(QIcon(":/icons/new.svg"));
    connect(newFileAction, SIGNAL(triggered()), main_window, SLOT(slotFileNewNew()));
    newFileAction->setObjectName("FileNew");
    a_map[EnumEnv::FileNew] = newFileAction;

    auto openFileAction = new QAction(tr("&Open..."), agm->file);
    openFileAction->setIcon(QIcon(":/icons/open.svg"));
    openFileAction->setShortcut(QKeySequence::Open);
    connect(openFileAction, SIGNAL(triggered()), main_window, SLOT(slotFileOpen()));
    openFileAction->setObjectName("FileOpen");
    a_map[EnumEnv::FileOpen] = openFileAction;

    auto saveAction = new QAction(tr("&Save"), agm->file);
    saveAction->setIcon(QIcon(":/icons/save.svg"));
    saveAction->setShortcut(QKeySequence::Save);
    connect(saveAction, SIGNAL(triggered()), main_window, SLOT(slotFileSave()));
    saveAction->setObjectName("FileSave");
    a_map[EnumEnv::FileSave] = saveAction;

    auto saveAsAction = new QAction(tr("Save &as..."), agm->file);
    saveAsAction->setIcon(QIcon(":/icons/save_as.svg"));
    saveAsAction->setShortcut(QKeySequence::SaveAs);
    connect(saveAsAction, SIGNAL(triggered()), main_window, SLOT(slotFileSaveAs()));
    saveAsAction->setObjectName("FileSaveAs");
    a_map[EnumEnv::FileSaveAs] = saveAsAction;

    auto quitAction = new QAction(tr("&Quit"), agm->file);
    quitAction->setIcon(QIcon(":/icons/quit.svg"));
    quitAction->setShortcut(QKeySequence::Quit);
    connect(quitAction, SIGNAL(triggered()), main_window, SLOT(slotFileQuit()));
    quitAction->setObjectName("FileQuit");
    a_map[EnumEnv::FileQuit] = quitAction;
}

void GP_ActionFactory::commonActions(QMap<QString, QAction *> &a_map, GP_ActionGroupManager *agm) {}
