#include "Converter.hpp"

#include <QDebug>

Converter::Converter()
{

}

void Converter::xmlToJson(QXmlStreamReader &xml)
{
    QDomNode current;

    while ( !xml.atEnd() )
    {
        xml.readNext();

        if ( xml.isStartElement() && !xml.name().isEmpty() )
        {
            addNode( toDomNode(xml), current);
        }

        if ( xml.isEndElement()  )
        {
            closeNode(current);
        }
    }
}

void Converter::addNode(const QDomNode node, QDomNode &current)
{
    if ( !m_xmlDoc.childNodes().isEmpty() )
    {
        current.appendChild(node);
        current = current.lastChild();
    }
    else
    {
        m_xmlDoc.appendChild(node);
        current = m_xmlDoc.lastChild();
    }
}

void Converter::closeNode(QDomNode current)
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
