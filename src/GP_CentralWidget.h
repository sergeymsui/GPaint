
#pragma once

#include <QFrame>

class QTabWidget;
class QVBoxLayout;

class GP_TabWidget;

class GP_CentralWidget : public QFrame {
    Q_OBJECT
public:
    explicit GP_CentralWidget(QWidget* parent);
    ~GP_CentralWidget() override;

public:
    QSharedPointer<GP_TabWidget> getTabArea();
protected:
    QSharedPointer<GP_TabWidget> tab_area{};
};
