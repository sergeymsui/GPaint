
#pragma once

#include <QStringList>
#include <QApplication>

class GP_Application : public QApplication {
    Q_OBJECT
public:
    explicit GP_Application(int &argc, char **argv) : QApplication(argc, argv) {}

    QStringList const& fileList(void) const {
        return files;
    }

protected:
    bool event(QEvent *event) Q_DECL_OVERRIDE {
#ifdef Q_OS_MAC
        if (QEvent::FileOpen == event->type()) {
            QFileOpenEvent *openEvent = static_cast<QFileOpenEvent *>(event);
            files.append( openEvent->file());
        }
#endif
        return QApplication::event(event);
    }

private:
    QStringList files;
};