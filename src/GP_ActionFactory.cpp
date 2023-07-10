
#include "GP_ActionFactory.h"

GP_ActionFactory::GP_ActionFactory(GP_ApplicationWindow *parent, GP_ActionHandler *a_handler) : QObject(parent),
    using_theme(false),
    main_window(parent),
    action_handler(a_handler) {}

void GP_ActionFactory::fillActionContainer(QMap<QString, QAction *> &a_map, GP_ActionGroupManager *agm) {
    auto panningZoomAction = new QAction(tr("Zoom &Panning"), agm->other);
    panningZoomAction->setIcon(QIcon(":/icons/zoom_pan.svg"));
    connect(panningZoomAction, SIGNAL(triggered()), action_handler, SLOT(slotZoomPan()));
    panningZoomAction->setObjectName("ZoomPan");
    a_map["ZoomPan"] = panningZoomAction;

    auto newFileAction = new QAction(tr("&New"), agm->other);
    newFileAction->setIcon(QIcon(":/icons/new.svg"));
    connect(newFileAction, SIGNAL(triggered()), main_window, SLOT(slotFileNewNew()));
    newFileAction->setObjectName("FileNew");
    a_map["FileNew"] = newFileAction;
}

void GP_ActionFactory::commonActions(QMap<QString, QAction *> &a_map, GP_ActionGroupManager *agm) {}
