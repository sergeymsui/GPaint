
#include "GP_ActionFactory.h"
#include "GP_ApplicationWindow.h"
#include "GP_ActionHandler.h"
#include "GP_ActionGroupManager.h"

#include <QIcon>
#include <QPainter>
#include <QSvgRenderer>



GP_ActionFactory::GP_ActionFactory(GP_ApplicationWindow *parent, GP_ActionHandler *a_handler)
    : QObject(parent),
    using_theme(false),
    main_window(parent),
    action_handler(a_handler) {}

void GP_ActionFactory::fillActionContainer(QMap<EnumEnv, QAction *> &a_map, GP_ActionGroupManager *agm) {
    auto panningZoomAction = new QAction(tr("Zoom &Panning"), agm->other);
    panningZoomAction->setIcon(QIcon(":/icons/zoom_pan.svg"));
    connect(panningZoomAction, SIGNAL(triggered()), action_handler, SLOT(slotZoomPan()));
    a_map[EnumEnv::ZoomPan] = panningZoomAction;

    auto newFileAction = new QAction(tr("&New"), agm->other);
    newFileAction->setIcon(QIcon(":/icons/new.png"));
    connect(newFileAction, SIGNAL(triggered()), main_window, SLOT(slotFileNew()));
    a_map[EnumEnv::FileNew] = newFileAction;

    auto openFileAction = new QAction(tr("&Open..."), agm->file);
    openFileAction->setIcon(QIcon(":/icons/open.png"));
    openFileAction->setShortcut(QKeySequence::Open);
    connect(openFileAction, SIGNAL(triggered()), main_window, SLOT(slotFileOpen()));
    a_map[EnumEnv::FileOpen] = openFileAction;

    auto saveAction = new QAction(tr("&Save"), agm->file);
    if (using_theme)
        saveAction->setIcon(QIcon::fromTheme("document-save", QIcon(":/icons/save.svg")));
    else
        saveAction->setIcon(QIcon(":/icons/save.png"));
    saveAction->setShortcut(QKeySequence::Save);
    connect(saveAction, SIGNAL(triggered()), main_window, SLOT(slotFileSave()));
    a_map[EnumEnv::FileSave] = saveAction;

    auto saveAsAction = new QAction(tr("Save &as..."), agm->file);
    saveAsAction->setIcon(QIcon(":/icons/save-as.png"));
    saveAsAction->setShortcut(QKeySequence::SaveAs);
    connect(saveAsAction, SIGNAL(triggered()), main_window, SLOT(slotFileSaveAs()));
    a_map[EnumEnv::FileSaveAs] = saveAsAction;

    auto printAction = new QAction(tr("&Print..."), agm->file);
    printAction->setIcon(QIcon(":/icons/print.png"));
    printAction->setShortcut(QKeySequence::Print);
    connect(printAction, SIGNAL(triggered()), main_window, SLOT(slotFilePrint()));
    connect(main_window, SIGNAL(printPreviewChanged(bool)), printAction, SLOT(setChecked(bool)));
    a_map[FilePrint] = printAction;

    auto printPreviewAction = new QAction(tr("Print Pre&view"), agm->file);
    printPreviewAction->setIcon(QIcon(":/icons/print_preview.svg"));
    printPreviewAction->setCheckable(true);
    connect(printPreviewAction, SIGNAL(triggered(bool)), main_window, SLOT(slotFilePrintPreview(bool)));
    // connect(main_window, SIGNAL(printPreviewChanged(bool)), printPreviewAction, SLOT(setChecked(bool)));
    a_map[FilePrintPreview] = printPreviewAction;

    auto quitAction = new QAction(tr("&Quit"), agm->file);
    quitAction->setIcon(QIcon(":/icons/quit.svg"));
    quitAction->setShortcut(QKeySequence::Quit);
    connect(quitAction, SIGNAL(triggered()), main_window, SLOT(slotFileQuit()));
    quitAction->setObjectName("FileQuit");
    a_map[EnumEnv::FileQuit] = quitAction;
}

void GP_ActionFactory::commonActions(QMap<QString, QAction *> &a_map, GP_ActionGroupManager *agm) {}
