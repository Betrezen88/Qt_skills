#include "Converter.hpp"

#include <QJsonArray>
#include <QDebug>

Converter::Converter()
{

}

QJsonDocument Converter::xmlToJson(QXmlStreamReader &xml)
{
    QJsonDocument jsonDoc;
    createXmlDoc(xml);
    jsonDoc.setObject( xmlDocToJson() );

    return jsonDoc;
}

void Converter::createXmlDoc(QXmlStreamReader &xml)
{
    QDomNode current;

    while ( !xml.atEnd() )
    {
        xml.readNext();

        if ( xml.isStartElement() && !xml.name().isEmpty() )
            addNode( toDomNode(xml), current );
        else if ( xml.isEndElement()  )
            closeNode( current );
    }
}

void Converter::addNode(const QDomNode node, QDomNode &current)
{
    if ( !m_xmlDoc.childNodes().isEmpty() )
    {
        current.appendChild( node );
        current = current.lastChild();
    }
    else
    {
        m_xmlDoc.appendChild( node );
        current = m_xmlDoc.lastChild();
    }
}

void Converter::closeNode(QDomNode &current)
{
    current = current.parentNode();
}

QDomNode Converter::toDomNode(const QXmlStreamReader &node)
{
    QDomElement element = m_xmlDoc.createElement( node.name().toString() );

    if ( !node.attributes().isEmpty() )
        addAttributes( element, node.attributes() );

    return element;
}

void Converter::addAttributes(QDomElement element, const QXmlStreamAttributes &attributes)
{
    for ( int i=0; i<attributes.size(); ++i )
        element.setAttribute( attributes.at(i).name().toString(), attributes.at(i).value().toString() );
}

QStringList Converter::nodeChildsNames(const QDomNodeList &nodeChilds)
{
    QStringList names;
    for ( int i=0; i<nodeChilds.size(); ++i)
        if ( !names.contains( nodeChilds.at(i).nodeName() ) )
            names << nodeChilds.at(i).nodeName();
    return names;
}

QJsonObject Converter::xmlDocToJson()
{
    QJsonObject object;

    for ( int i=0; i<m_xmlDoc.childNodes().size(); ++i )
        object.insert( m_xmlDoc.childNodes().at(i).nodeName(), QJsonValue( nodeToJson( m_xmlDoc.childNodes().at(i) ) ) );

    return object;
}

QJsonObject Converter::nodeToJson(const QDomNode &node)
{
    QJsonObject object;

    if ( node.hasAttributes() )
        insertNodeAttributesToJson( object, node.attributes() );

    if ( node.hasChildNodes() )
    {
        QStringList names = nodeChildsNames( node.childNodes() );

        for ( int i=0; i<names.size(); ++i )
        {
            QDomNodeList nodes = node.toElement().elementsByTagName( names.at(i) );

            if ( nodes.size() == 1 )
                object.insert( names.at(i), QJsonValue( nodeToJson(nodes.at(0)) ) );
            else
            {
                QJsonArray array;

                for ( int i=0; i<nodes.size(); ++i)
                    array.append( QJsonValue(nodeToJson(nodes.at(i))) );

                object.insert( names.at(i), QJsonValue(array) );
            }
        }
    }

    return object;
}

void Converter::insertNodeAttributesToJson(QJsonObject &object, const QDomNamedNodeMap &attributes)
{
    for ( int i=0; i<attributes.size(); ++i)
        object.insert( attributes.item(i).nodeName(), QJsonValue(attributes.item(i).nodeValue()) );
}
