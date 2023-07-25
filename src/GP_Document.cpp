
#include "GP_Document.h"

GP_Document::GP_Document(QString name) : QObject(), m_documentName(std::move(name)) {
    //
}

GP_Document::~GP_Document() {}

QString GP_Document::documentName() const {
    return m_documentName;
}
