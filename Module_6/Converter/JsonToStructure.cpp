#include "JsonToStructure.hpp"

#include <QJsonDocument>
#include <QStringList>

JsonToStructure::JsonToStructure(const QString &content)
{
    m_success = createStructure( content );
}

JsonToStructure::~JsonToStructure()
{

}

bool JsonToStructure::createStructure(const QString &content)
{
    QJsonParseError error;
    QJsonDocument json = QJsonDocument::fromJson( content.toLocal8Bit(), &error );

    if ( error.error == QJsonParseError::NoError )
    {
        QDomNode current;
        QJsonObject object = json.object();

        foreach ( const QString &key, object.keys() )
        {
            if ( object.value(key).isObject() )
                addNode( toDomNode(key, object.value(key).toObject()), current );
        }
    }
    else
    {
        createErrorMessage( error );
        return false;
    }
    return true;
}

void JsonToStructure::addArray(const QString &key, const QJsonArray &array, QDomElement &element)
{
    for ( int i=0; i<array.size(); ++i )
        element.appendChild( toDomNode(key, array.at(i).toObject()) );
}

QDomNode JsonToStructure::toDomNode(const QString &key, const QJsonObject &object)
{
    QDomElement element = m_structure.createElement( key );

    foreach ( const QString &key, object.keys() )
    {
        if ( object.value(key).isObject() )
            element.appendChild( toDomNode(key, object.value(key).toObject()) );
        else if ( object.value(key).isString() )
            element.setAttribute( key, object.value(key).toString() );
        else if ( object.value(key).isDouble() )
            element.setAttribute( key, object.value(key).toDouble() );
        else if ( object.value(key).isArray() )
            addArray( key, object.value(key).toArray(), element );
    }

    return element;
}

void JsonToStructure::createErrorMessage(const QJsonParseError &error)
{
    m_error = "Error occured in character offset: " + QString::number( error.offset )
            + "\nError message: " + error.errorString();
}
