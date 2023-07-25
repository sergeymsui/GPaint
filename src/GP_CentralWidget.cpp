
#include <QFrame>
#include <QVBoxLayout>

#include "GP_TabWidget.h"
#include "GP_CentralWidget.h"

GP_CentralWidget::GP_CentralWidget(QWidget *parent) : QFrame(parent), tab_area(new GP_TabWidget(this)) {
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);

    auto layout = new QVBoxLayout;
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(tab_area.get());

    tab_area->setFocusPolicy(Qt::ClickFocus);
    tab_area->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    tab_area->setTabsClosable(true);
    tab_area->setTabPosition(QTabWidget::South);

    setLayout(layout);
}

GP_CentralWidget::~GP_CentralWidget() {
    qDebug() << "GP_CentralWidget::~GP_CentralWidget()";
}

QSharedPointer<GP_TabWidget> GP_CentralWidget::getTabArea() {
    return tab_area;
}
