#include "Converter.hpp"

#include "XmlToStructure.hpp"
#include "JsonToStructure.hpp"
#include "StructureToJson.hpp"

#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>

Converter::Converter()
{

}

QString Converter::xmlToJson(const QString &content)
{
    {
        XmlToStructure creator( content );

        if ( !creator.success() )
            return creator.error();

        m_structure = creator.structure();
    }
    StructureToJson converter( m_structure );
    return converter.resutl();
}

QString Converter::jsonToXml(const QString &content)
{
    {
        JsonToStructure creator( content );

        if ( !creator.success() )
            return creator.error();

        m_structure = creator.structure();
    }
    return m_structure.toString();
}
