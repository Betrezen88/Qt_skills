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

    QJsonDocument xmlToJson(QXmlStreamReader &xml);

    QString xmlDocToString() { return m_xmlDoc.toString(); }

private:
    void createXmlDoc(QXmlStreamReader &xml);

    void addNode(const QDomNode node, QDomNode &current);
    void closeNode(QDomNode &current);
    QDomNode toDomNode(const QXmlStreamReader &node);
    void addAttributes(QDomElement element, const QXmlStreamAttributes &attributes);
    QStringList nodeChildsNames(const QDomNodeList &nodeChilds);

    QJsonObject xmlDocToJson();
    QJsonObject nodeToJson(const QDomNode &node);
    void insertNodeAttributesToJson(QJsonObject &object, const QDomNamedNodeMap &attributes);

private:
    QDomDocument m_xmlDoc;
};

#endif // CONVERTER_HPP
