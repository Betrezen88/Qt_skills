#include "Dialog.h"

#include <QVBoxLayout>
#include <QLabel>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    m_quitBtn = new QPushButton( "Quit" );
    m_runBtn = new QPushButton( "Run" );
    m_statusBar = new QStatusBar();
    m_resultView = new QTextEdit();

    m_resultView->setReadOnly( true );
    m_statusBar->showMessage( "Ready" );

    connect( m_quitBtn, &QPushButton::clicked, this, &Dialog::close );

    QVBoxLayout *resultL = new QVBoxLayout();
    resultL->addWidget( new QLabel("Result:") );
    resultL->addWidget( m_resultView );

    QHBoxLayout *buttonsL = new QHBoxLayout();
    buttonsL->addWidget( m_runBtn );
    buttonsL->addWidget( m_quitBtn );

    QVBoxLayout *all = new QVBoxLayout();
    all->addLayout( resultL );
    all->addLayout( buttonsL );
    all->addWidget( m_statusBar );

    setLayout( all );
}

Dialog::~Dialog()
{

}
