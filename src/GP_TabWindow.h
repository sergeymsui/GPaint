
#pragma once

class QWidget;
class QGraphicsView;

class GP_Document;

class GP_TabWindow : public QWidget {
    Q_OBJECT
public:
    explicit GP_TabWindow(GP_Document* doc, QWidget* parent);
    ~GP_TabWindow() override;
private:
    QGraphicsView* graphicView { nullptr };
    GP_Document* m_document { nullptr };
public:
    [[nodiscard]] QGraphicsView* getGraphicView() const;
    [[nodiscard]] GP_Document* getDocument() const;
};