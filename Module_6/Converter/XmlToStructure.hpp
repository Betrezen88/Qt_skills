#ifndef XMLTOSTRUCTURE_HPP
#define XMLTOSTRUCTURE_HPP

#include "StructureCreator.hpp"

#include <QXmlStreamReader>

class XmlToStructure : public StructureCreator
{
public:
    XmlToStructure(const QString &content);
    ~XmlToStructure();

protected:
    bool createStructure(const QString &content);

private:
    QDomNode toDomNode(const QXmlStreamReader &xml);
    void addAttributes(QDomElement &element, const QXmlStreamAttributes &attributes);
    void createErrorMessage(const QXmlStreamReader &xml);
};

#endif // XMLTOSTRUCTURE_HPP
