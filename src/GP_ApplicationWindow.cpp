
#include <QDebug>
#include <QIcon>
#include <QSettings>

#include "GP_ActionFactory.h"
#include "GP_WidgetFactory.h"
#include "GP_ApplicationWindow.h"
#include "GP_ActionGroupManager.h"

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
}
