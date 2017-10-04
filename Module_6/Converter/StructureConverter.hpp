#ifndef STRUCTURECONVERTER_HPP
#define STRUCTURECONVERTER_HPP

#include <QString>
#include <QDomDocument>

class StructureConverter
{
public:
    virtual ~StructureConverter() {}

    QString resutl() { return m_result; }

protected:
    virtual void convert(const QDomDocument &structure)=0;

protected:
    QString m_result;
};

#endif // STRUCTURECONVERTER_HPP
