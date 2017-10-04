#ifndef STRUCTURETOJSON_HPP
#define STRUCTURETOJSON_HPP

#include "StructureConverter.hpp"

#include <QDomDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QStringList>

class StructureToJson : public StructureConverter
{
public:
    StructureToJson(const QDomDocument &structure);

protected:
    void convert(const QDomDocument &structure);

private:
    QJsonObject nodeToJson(const QDomNode &node);
    void addAttributes(QJsonObject &object, const QDomNamedNodeMap &attributes);
    void addChildObjects(QJsonObject &object, const QDomNode &node);
    QStringList childNodesNames(const QDomNodeList &childNodes);
    QJsonArray nodesToArray(const QDomNodeList &nodes);
};

#endif // STRUCTURETOJSON_HPP
