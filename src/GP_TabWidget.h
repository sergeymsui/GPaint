
#pragma once

#include <QTabWidget>
#include "GP_TabWindow.h"

class GP_TabWidget : public QTabWidget {
    Q_OBJECT
public:
    explicit GP_TabWidget(QWidget* parent = nullptr);
    ~GP_TabWidget() override;

public:
    void addWindow(const QSharedPointer<GP_TabWindow>& w);
};