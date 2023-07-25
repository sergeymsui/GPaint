
#include <QWidget>
#include <QGraphicsView>

#include "GP_TabWindow.h"

GP_TabWindow::GP_TabWindow(GP_Document *doc, QWidget *parent) : QWidget(parent) {
    m_document = doc;
}

GP_TabWindow::~GP_TabWindow() {
    qDebug() << "GP_TabWindow::~GP_TabWindow()";
}

QGraphicsView *GP_TabWindow::getGraphicView() const {
    return (graphicView) ? graphicView : nullptr;
}

GP_Document *GP_TabWindow::getDocument() const {
    return (m_document) ? m_document : nullptr;
}
