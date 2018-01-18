#include "Dialog.h"

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QProgressBar>
#include <QHBoxLayout>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    QLabel* pArraySizeLabel = new QLabel( "Array size:", this );
    QLabel* pObjectCountLabel = new QLabel( "Object count:", this );

    m_pArraySize = new QLineEdit;
    m_pObjectCount = new QLineEdit;
    m_pProgressBar = new QProgressBar;
    m_pRunBtn = new QPushButton( "Run" );
    m_pQuitBtn = new QPushButton( "Quit" );

    connect( m_pQuitBtn, &QPushButton::clicked, this, &Dialog::close );

    QHBoxLayout* pArrayLayout = new QHBoxLayout;
    pArrayLayout->addWidget( pArraySizeLabel );
    pArrayLayout->addWidget( m_pArraySize );

    QHBoxLayout* pObjectLayout = new QHBoxLayout;
    pObjectLayout->addWidget( pObjectCountLabel );
    pObjectLayout->addWidget( m_pObjectCount );

    QHBoxLayout* pButtons = new QHBoxLayout;
    pButtons->addWidget( m_pRunBtn );
    pButtons->addWidget( m_pQuitBtn );

    QVBoxLayout* all = new QVBoxLayout;
    all->addLayout( pArrayLayout );
    all->addLayout( pObjectLayout );
    all->addWidget( m_pProgressBar );
    all->addLayout( pButtons );

    setLayout( all );
}

Dialog::~Dialog()
{

}
