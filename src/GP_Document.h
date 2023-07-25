
#pragma once

#include <QObject>
#include <utility>

class GP_Document : public QObject {
    Q_OBJECT
public:
    explicit GP_Document(QString name = "Unknown");
    ~GP_Document() override;

public:
    [[nodiscard]] QString documentName() const;

private:
    QString m_documentName;
};
