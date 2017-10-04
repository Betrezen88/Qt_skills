#include "Converter.hpp"

#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>

Converter::Converter()
{

}

void Converter::createXmlDoc(QJsonDocument &json)
{
    QDomNode current;
    QJsonObject object = json.object();

    foreach ( const QString &key, object.keys() ) {
        if ( object.value(key).isObject() )
            addNode( toDomNode(key, object.value(key).toObject()), current );
    }
}

QDomNode Converter::toDomNode(const QString &key, const QJsonObject &object)
{
    QDomElement element = m_xmlDoc.createElement( key );

    foreach ( const QString &key, object.keys() ) {
        if ( object.value(key).isObject() )
            element.appendChild( toDomNode(key, object.value(key).toObject()) );
        else if ( object.value(key).isArray() )
            addJsonArrayToNode( key, object.value(key).toArray(), element );
        else if ( object.value(key).isString() )
            element.setAttribute( key, object.value(key).toString() );
    }

    return element;
}

void Converter::addJsonArrayToNode(const QString &key, const QJsonArray &array, QDomElement &element)
{
    for ( int i=0; i<array.size(); ++i )
        element.appendChild( toDomNode(key, array.at(i).toObject()) );
}

void Converter::createXmlDoc(QXmlStreamReader &xml)
{
    QDomNode current;

    while ( !xml.atEnd() )
    {
        xml.readNext();

        if ( xml.isStartElement() && !xml.name().isEmpty() ) {
            addNode( toDomNode(xml), current );
        }
        else if ( xml.isEndElement()  ) {
            closeNode( current );
        }

        if ( xml.hasError() ) {
            m_result = "Error in line: " + QString::number( xml.lineNumber() ) + "\n"
                    + "   in column: " + QString::number( xml.columnNumber() ) + "\n"
                    + "        offset: " + QString::number( xml.characterOffset() ) + "\n"
                    + "Error message:\n   " + xml.errorString();
        }
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
