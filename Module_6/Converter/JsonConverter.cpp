#include "JsonConverter.hpp"

JsonConverter::JsonConverter()
{

}

QString JsonConverter::convert(QJsonDocument &json)
{
    createXmlDoc( json );
    return m_xmlDoc.toString();
}
