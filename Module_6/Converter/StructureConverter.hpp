#ifndef STRUCTURECONVERTER_HPP
#define STRUCTURECONVERTER_HPP

#include <QString>

class StructureConverter
{
public:
    virtual ~StructureConverter() {}

    QString resutl() { return m_result; }

protected:
    QString m_result;
};

#endif // STRUCTURECONVERTER_HPP
