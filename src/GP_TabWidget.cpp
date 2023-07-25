
#include "GP_Document.h"

#include "GP_TabWidget.h"

GP_TabWidget::GP_TabWidget(QWidget *parent) : QTabWidget(parent) {}

GP_TabWidget::~GP_TabWidget() {}

void GP_TabWidget::addWindow(const QSharedPointer<GP_TabWindow>& w) {
    addTab(w.get(), w->getDocument()->documentName());
}
