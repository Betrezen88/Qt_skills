#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <QDomDocument>
#include <QXmlStreamReader>

class Converter
{
public:
    Converter();

    void xmlToJson(QXmlStreamReader &xml);

    QString xmlDocToString() { return m_xmlDoc.toString(); }

private:
    void addNode(const QDomNode node, QDomNode &current);
    void closeNode(QDomNode current);
    QDomNode toDomNode(const QXmlStreamReader &node);
    void addAttributes(QDomElement element, const QXmlStreamAttributes &attributes);

private:
    QDomDocument m_xmlDoc;
};

#endif // CONVERTER_HPP
