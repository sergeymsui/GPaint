
#include <QDebug>
#include <QIcon>
#include <QSettings>
#include <QStatusBar>
#include <QSharedPointer>

#include "GP_Document.h"
#include "GP_TabWidget.h"
#include "GP_TabWindow.h"
#include "GP_ActionFactory.h"
#include "GP_WidgetFactory.h"
#include "GP_ApplicationWindow.h"
#include "GP_ActionGroupManager.h"
#include "GP_CentralWidget.h"

GP_ApplicationWindow::GP_ApplicationWindow(QWidget *parent)
    : ag_manager(new GP_ActionGroupManager(this))
{
    qDebug() << "QC_ApplicationWindow::QC_ApplicationWindow";

    setWindowIcon(QIcon(":/icons/logo.png"));

    //accept drop events to open files
    setAcceptDrops(true);

    // make the left and right dock areas dominant
    setCorner(Qt::TopLeftCorner, Qt::LeftDockWidgetArea);
    setCorner(Qt::BottomLeftCorner, Qt::LeftDockWidgetArea);
    setCorner(Qt::TopRightCorner, Qt::RightDockWidgetArea);
    setCorner(Qt::BottomRightCorner, Qt::RightDockWidgetArea);

    appWindow = this;

    QSettings settings;

    GP_ActionFactory a_factory(this, actionHandler);
    a_factory.using_theme = settings.value("Widgets/AllowTheme", 0).toBool();
    a_factory.fillActionContainer(a_map, ag_manager);

    GP_WidgetFactory widget_factory(this, a_map, ag_manager);
    widget_factory.createRightSidebar(actionHandler);
    widget_factory.createCategoriesToolbar();
    widget_factory.createStandardToolbars(actionHandler);

    widget_factory.createMenus(menuBar());

    auto central = new GP_CentralWidget(this);
    setCentralWidget(reinterpret_cast<QWidget *>(central));

    tabAreaCAD = central->getTabArea();
}

QSharedPointer<GP_TabWindow> GP_ApplicationWindow::fileNew(GP_Document* doc) {
    qDebug() << "GP_ApplicationWindow::slotFileNew()";

    static int id = 0;
    id++;

    statusBar()->showMessage(tr("Creating new file..."));

    auto w = QSharedPointer<GP_TabWindow>(new GP_TabWindow(doc, tabAreaCAD.get()));
    tabAreaCAD->addWindow(w);

    statusBar()->showMessage(tr("New Drawing created."), 2000);

    return w;
}

void GP_ApplicationWindow::slotFileNew() {
    qDebug() << "slotFileNew";

    auto document = new GP_Document;
    auto w = fileNew(document);

    m_tabWindows << w;
}
