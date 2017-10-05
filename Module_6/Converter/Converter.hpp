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
    QString jsonToXml(const QString &content);

private:
    QDomDocument m_structure;
};

#endif // CONVERTER_HPP
