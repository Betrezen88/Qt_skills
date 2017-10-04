#include "XmlToStructure.hpp"

XmlToStructure::XmlToStructure(const QString &content)
{
    createStructure( content );
}

XmlToStructure::~XmlToStructure()
{

}

void XmlToStructure::createStructure(const QString &content)
{
    m_result.clear();
    m_error.clear();

    QXmlStreamReader reader(content);
    QDomNode current;

    while ( !reader.atEnd() )
    {
        reader.readNext();

        if ( reader.hasError() )
        {
            createErrorMessage( reader );
            break;
        }

        if ( reader.isStartElement() && !reader.name().isEmpty() )
            addNode( toDomNode(reader) , current );
        else if ( reader.isEndElement() )
            closeNode( current );
    }
}

void XmlToStructure::addNode(const QDomNode node, QDomNode &current)
{
    if ( !m_result.childNodes().isEmpty() )
    {
        current.appendChild( node );
        current = current.lastChild();
    }
    else
    {
        m_result.appendChild( node );
        current = m_result.lastChild();
    }
}

void XmlToStructure::closeNode(QDomNode &node)
{
    node = node.parentNode();
}

QDomNode XmlToStructure::toDomNode(const QXmlStreamReader &xml)
{
    QDomElement element = m_result.createElement( xml.name().toString() );

    if ( !xml.attributes().isEmpty() )
        addAttributes( element, xml.attributes() );

    return element;
}

void XmlToStructure::addAttributes(QDomElement &element, const QXmlStreamAttributes &attributes)
{
    for ( int i=0; i<attributes.size(); ++i )
        element.setAttribute( attributes.at(i).name().toString(), attributes.at(i).value().toString() );
}

void XmlToStructure::createErrorMessage(const QXmlStreamReader &xml)
{
    m_error = "Error occured in line: " + QString::number( xml.lineNumber() )
            + "\n                 in column: " + QString::number( xml.columnNumber() )
            + "\n      character offset: " + QString::number( xml.characterOffset() )
            + "\n\nError message: " + xml.errorString();
}
