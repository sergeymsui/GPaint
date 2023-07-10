
#pragma once

#include <QMainWindow>

class GP_ApplicationWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit GP_ApplicationWindow(QWidget* parent = nullptr);

private:
    GP_ApplicationWindow* appWindow = nullptr;
};
