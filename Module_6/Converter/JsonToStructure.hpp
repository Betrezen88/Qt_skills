#ifndef JSONTOSTRUCTURE_HPP
#define JSONTOSTRUCTURE_HPP

#include "StructureCreator.hpp"

#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>

class JsonToStructure : public StructureCreator
{
public:
    JsonToStructure(const QString &content);
    ~JsonToStructure();

protected:
    bool createStructure(const QString &content);
    void addArray(const QString &key, const QJsonArray &array, QDomElement &element);
    QDomNode toDomNode(const QString &key, const QJsonObject &object);
    void createErrorMessage(const QJsonParseError &error);
};

#endif // JSONTOSTRUCTURE_HPP
