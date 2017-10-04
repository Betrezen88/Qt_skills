#ifndef STRUCTURECREATOR_HPP
#define STRUCTURECREATOR_HPP

#include <QDomDocument>

class StructureCreator
{
public:
    virtual ~StructureCreator() {}

    QDomDocument result() { return m_result; }
    QString error() { return m_error; }

protected:
    virtual void createStructure(const QString &content)=0;

protected:
    QDomDocument m_result;
    QString m_error;
};

#endif // STRUCTURECREATOR_HPP
