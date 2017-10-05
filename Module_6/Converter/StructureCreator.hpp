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

    void addNode(const QDomNode node, QDomNode &current)
    {
        if ( !m_structure.childNodes().isEmpty() )
        {
            current.appendChild( node );
            current = current.lastChild();
        }
        else
        {
            m_structure.appendChild( node );
            current = m_structure.lastChild();
        }
    }

    void closeNode(QDomNode &node)
    {
        node = node.parentNode();
    }

protected:
    QDomDocument m_structure;
    QString m_error;
    bool m_success;
};

#endif // STRUCTURECREATOR_HPP
