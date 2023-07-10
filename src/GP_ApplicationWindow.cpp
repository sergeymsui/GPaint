
#include <QDebug>
#include <QIcon>
#include <QSettings>

#include "GP_ApplicationWindow.h"

GP_ApplicationWindow::GP_ApplicationWindow(QWidget *parent) {
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
}
