#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <QDomDocument>
#include <QXmlStreamReader>
#include <QJsonDocument>

#include "StructureCreator.hpp"

class Converter
{
public:
    Converter();

    QString xmlToJson(const QString &content);

    QString convert(QXmlStreamReader &xml);
    QString convert(QJsonDocument &json);

    QString result() { return m_result; }

protected:
    void createXmlDoc(QJsonDocument &json);
    QDomNode toDomNode(const QString &key, const QJsonObject &object);
    void addJsonArrayToNode(const QString &key, const QJsonArray &array, QDomElement &element);

    void createXmlDoc(QXmlStreamReader &xml);
    void addNode(const QDomNode node, QDomNode &current);
    void closeNode(QDomNode &current);
    QDomNode toDomNode(const QXmlStreamReader &node);
    void addAttributes(QDomElement element, const QXmlStreamAttributes &attributes);

protected:
    QDomDocument m_structure;

    QDomDocument m_xmlDoc;
    QString m_result;

};

#endif // CONVERTER_HPP
