#include "XmlConverter.hpp"

#include <QJsonObject>
#include <QJsonArray>

XmlConverter::XmlConverter()
{

}

QString XmlConverter::convert(QXmlStreamReader &xml)
{
    QJsonDocument jsonDoc;
    createXmlDoc(xml);
    jsonDoc.setObject( xmlDocToJson() );

    return jsonDoc.toJson();
}

QJsonObject XmlConverter::xmlDocToJson()
{
    QJsonObject object;

    for ( int i=0; i<m_xmlDoc.childNodes().size(); ++i )
        object.insert( m_xmlDoc.childNodes().at(i).nodeName(), QJsonValue( nodeToJson( m_xmlDoc.childNodes().at(i) ) ) );

    return object;
}

QJsonObject XmlConverter::nodeToJson(const QDomNode &node)
{
    QJsonObject object;

    if ( node.hasAttributes() )
        insertNodeAttributesToJson( object, node.attributes() );

    if ( node.hasChildNodes() )
        insertNodeChildsToJson( object, node );

    return object;
}

QJsonArray XmlConverter::nodesToArray(const QDomNodeList &nodes)
{
    QJsonArray array;

    for ( int i=0; i<nodes.size(); ++i )
        array.append( QJsonValue(nodeToJson(nodes.at(i))) );
    return array;
}

QStringList XmlConverter::nodeChildsNames(const QDomNodeList &nodeChilds)
{
    QStringList names;
    for ( int i=0; i<nodeChilds.size(); ++i)
        if ( !names.contains( nodeChilds.at(i).nodeName() ) )
            names << nodeChilds.at(i).nodeName();
    return names;
}

void XmlConverter::insertNodeAttributesToJson(QJsonObject &object, const QDomNamedNodeMap &attributes)
{
    for ( int i=0; i<attributes.size(); ++i)
        object.insert( attributes.item(i).nodeName(), QJsonValue(attributes.item(i).nodeValue()) );
}

void XmlConverter::insertNodeChildsToJson(QJsonObject &object, const QDomNode &node)
{
    QStringList names = nodeChildsNames( node.childNodes() );

    for ( int i=0; i<names.size(); ++i )
    {
        QDomNodeList nodes = node.toElement().elementsByTagName( names.at(i) );

        if ( nodes.size() == 1 )
            object.insert( names.at(i), QJsonValue(nodeToJson(nodes.at(0))) );
        else
            object.insert( names.at(i), QJsonValue(nodesToArray(nodes)) );
    }
}
