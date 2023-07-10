
#include <clocale>
#include <QDebug>
#include <QSettings>
#include <QSplashScreen>

#include "GP_ApplicationWindow.h"
#include "GP_Application.h"

int main(int argc, char** argv) {
    // QT_REQUIRE_VERSION(argc, argv, "5.2.1");

    GP_Application app(argc, argv);
    QCoreApplication::setOrganizationName("GPaint");
    QCoreApplication::setApplicationName("GPaint");
    QCoreApplication::setApplicationVersion("0.01");

    QSettings settings;

    bool first_load = settings.value("Startup/FirstLoad", 1).toBool();

    auto splash = new QSplashScreen;
    bool show_splash = settings.value("Startup/ShowSplash", 1).toBool();

    if (show_splash) {
        QPixmap pixmap(":/main/splash_librecad.png");
        splash->setPixmap(pixmap);
        splash->setAttribute(Qt::WA_DeleteOnClose);
        splash->show();
        splash->showMessage(QObject::tr("Loading.."), Qt::AlignRight|Qt::AlignBottom, Qt::black);
        app.processEvents();
        qDebug() << "main: splashscreen: OK";
    }

    GP_ApplicationWindow appWin;

    appWin.setWindowTitle(QApplication::applicationName());

    settings.beginGroup("Geometry");
    int windowWidth = settings.value("WindowWidth", 1024).toInt();
    int windowHeight = settings.value("WindowHeight", 1024).toInt();
    int windowX = settings.value("WindowX", 32).toInt();
    int windowY = settings.value("WindowY", 32).toInt();
    settings.endGroup();

    if (!first_load)
        appWin.resize(windowWidth, windowHeight);

    appWin.move(windowX, windowY);

    bool maximize = settings.value("Startup/Maximize", 0).toBool();

    if (maximize || first_load)
        appWin.showMaximized();
    else
        appWin.show();

    qDebug() << "main: set focus";
    appWin.setFocus();
    qDebug() << "main: creating main window: OK";

    if (show_splash) {
        qDebug() << "main: updating splash";
        splash->raise();
        splash->showMessage(QObject::tr("Loading..."), Qt::AlignRight|Qt::AlignBottom, Qt::black);
        qDebug() << "main: processing events";
        qApp->processEvents();
        qDebug() << "main: updating splash: OK";
    }

    // Set LC_NUMERIC so that entering numeric values uses . as the decimal separator
    setlocale(LC_NUMERIC, "C");

    qDebug() << "main: loading files..";

    if (show_splash)
        splash->finish(&appWin);
    else
        delete splash;

    if (first_load)
        settings.setValue("Startup/FirstLoad", 0);

    qDebug() << "main: entering Qt event loop";
    int return_code = QApplication::exec();
    qDebug() << "main: exited Qt event loop";

    return return_code;
}
