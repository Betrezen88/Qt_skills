#ifndef JSONCONVERTER_HPP
#define JSONCONVERTER_HPP

#include "Converter.hpp"

class JsonConverter : public Converter
{
public:
    JsonConverter();

    QString convert(QJsonDocument &json);
};

#endif // JSONCONVERTER_HPP
