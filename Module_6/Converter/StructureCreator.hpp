#ifndef STRUCTURECREATOR_HPP
#define STRUCTURECREATOR_HPP

#include <QDomDocument>

class StructureCreator
{
public:
    virtual ~StructureCreator() {}

    QDomDocument structure() { return m_structure; }
    QString error() { return m_error; }
    bool success() { return m_success; }

protected:
    virtual bool createStructure(const QString &content)=0;

protected:
    QDomDocument m_structure;
    QString m_error;
    bool m_success;
};

#endif // STRUCTURECREATOR_HPP
