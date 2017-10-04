#include "JsonConverter.hpp"

JsonConverter::JsonConverter()
{

}

QString JsonConverter::convert(QJsonDocument &json)
{
    m_result.clear();
    createXmlDoc( json );
    m_result = m_xmlDoc.toString();
    return m_result;
}
