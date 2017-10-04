#include "StructureToJson.hpp"

#include <QJsonDocument>

StructureToJson::StructureToJson(const QDomDocument &structure)
{
    convert(structure);
}

void StructureToJson::convert(const QDomDocument &structure)
{
    QJsonObject root;
    const QDomNodeList nodes = structure.childNodes();

    for ( int i=0; i<nodes.size(); ++i )
        root.insert( nodes.at(i).nodeName(), QJsonValue(nodeToJson(nodes.at(i))) );

    QJsonDocument json(root);
    m_result = json.toJson();
}

QJsonObject StructureToJson::nodeToJson(const QDomNode &node)
{
    QJsonObject object;

    if ( node.hasAttributes() )
        addAttributes( object, node.attributes() );

    if ( node.hasChildNodes() )
        addChildObjects( object, node );

    return object;
}

void StructureToJson::addAttributes(QJsonObject &object, const QDomNamedNodeMap &attributes)
{
    for ( int i=0; i<attributes.size(); ++i)
        object.insert( attributes.item(i).nodeName(), QJsonValue(attributes.item(i).nodeValue()) );
}

void StructureToJson::addChildObjects(QJsonObject &object, const QDomNode &node)
{
    QStringList names = childNodesNames( node.childNodes() );

    foreach (const QString &name, names)
    {
        QDomNodeList namedNodes = node.toElement().elementsByTagName( name );

        if ( namedNodes.size() == 1 )
            object.insert( name, QJsonValue(nodeToJson(namedNodes.at(0))) );
        else
            object.insert( name, QJsonValue() );
    }
}

QStringList StructureToJson::childNodesNames(const QDomNodeList &childNodes)
{
    QStringList names;

    for ( int i=0; i<childNodes.size(); ++i )
        if ( !names.contains( childNodes.at(i).nodeName() ) )
            names << childNodes.at(i).nodeName();

    return names;
}

QJsonArray StructureToJson::nodesToArray(const QDomNodeList &nodes)
{
    QJsonArray array;

    for ( int i=0; i<nodes.size(); ++i )
        array.append( QJsonValue(nodeToJson(nodes.at(i))) );

    return array;
}
