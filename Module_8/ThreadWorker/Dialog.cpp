#include "Dialog.h"

#include <QLabel>
#include <QVBoxLayout>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    m_quitBtn = new QPushButton( "Quit" );
    m_runBtn = new QPushButton( "Run" );
    m_resultView = new QTextEdit();

    m_resultView->setReadOnly( true );

    connect( m_quitBtn, &QPushButton::clicked, this, &Dialog::close );
    connect( m_runBtn, &QPushButton::clicked, this, &Dialog::startWorker );

    QVBoxLayout *resultL = new QVBoxLayout();
    resultL->addWidget( new QLabel("Result:") );
    resultL->addWidget( m_resultView );

    QHBoxLayout *buttonsL = new QHBoxLayout();
    buttonsL->addWidget( m_runBtn );
    buttonsL->addWidget( m_quitBtn );

    QVBoxLayout *all = new QVBoxLayout();
    all->addLayout( resultL );
    all->addLayout( buttonsL );

    setLayout( all );
}

Dialog::~Dialog()
{

}

void Dialog::startWorker()
{

}
