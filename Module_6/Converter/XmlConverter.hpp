#ifndef XMLCONVERTER_HPP
#define XMLCONVERTER_HPP

#include "Converter.hpp"

class XmlConverter : public Converter
{
public:
    XmlConverter();

    QString convert(QXmlStreamReader &xml);

private:
    QJsonObject xmlDocToJson();
    QJsonObject nodeToJson(const QDomNode &node);
    QJsonArray nodesToArray(const QDomNodeList &nodes);
    QStringList nodeChildsNames(const QDomNodeList &nodeChilds);
    void insertNodeAttributesToJson(QJsonObject &object, const QDomNamedNodeMap &attributes);
    void insertNodeChildsToJson(QJsonObject &object, const QDomNode &node);
};

#endif // XMLCONVERTER_HPP
