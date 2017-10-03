#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <QDomDocument>
#include <QXmlStreamReader>
#include <QJsonDocument>
#include <QJsonObject>

class Converter
{
public:
    Converter();

    QString convert(QXmlStreamReader &xml);

    QString xmlDocToString() { return m_xmlDoc.toString(); }

protected:
    void createXmlDoc(QXmlStreamReader &xml);

    void addNode(const QDomNode node, QDomNode &current);
    void closeNode(QDomNode &current);
    QDomNode toDomNode(const QXmlStreamReader &node);
    void addAttributes(QDomElement element, const QXmlStreamAttributes &attributes);


protected:
    QDomDocument m_xmlDoc;
};

#endif // CONVERTER_HPP
