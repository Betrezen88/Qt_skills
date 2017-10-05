#include "XmlToStructure.hpp"

XmlToStructure::XmlToStructure(const QString &content)
{
    m_success = createStructure( content );
}

XmlToStructure::~XmlToStructure()
{

}

bool XmlToStructure::createStructure(const QString &content)
{
    QXmlStreamReader reader(content);
    QDomNode current;

    while ( !reader.atEnd() )
    {
        reader.readNext();

        if ( reader.hasError() )
        {
            createErrorMessage( reader );
            return false;
        }

        if ( reader.isStartElement() && !reader.name().isEmpty() )
            addNode( toDomNode(reader) , current );
        else if ( reader.isEndElement() )
            closeNode( current );
    }
    return true;
}

QDomNode XmlToStructure::toDomNode(const QXmlStreamReader &xml)
{
    QDomElement element = m_structure.createElement( xml.name().toString() );

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
