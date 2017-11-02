#include "Dialog.h"
#include "external.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QtConcurrent/QtConcurrent>
#include <QFuture>
#include <QString>
#include <QStringList>

//extern QString function();

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    m_quitBtn = new QPushButton( "Quit" );
    m_runBtn = new QPushButton( "Run" );
    m_resultView = new QTextEdit;
    m_exampleBox = new QComboBox;

    m_resultView->setReadOnly( true );
    m_exampleBox->addItem( "QtConcurrent::run(aFunction)" );
    m_exampleBox->addItem( "Qt::Concurrent::filtered()" );

    connect( m_quitBtn, &QPushButton::clicked, this, &Dialog::close );
    connect( m_runBtn, &QPushButton::clicked, this, &Dialog::runExample );

    QVBoxLayout *resultL = new QVBoxLayout;
    resultL->addWidget( new QLabel("Result:") );
    resultL->addWidget( m_resultView );

    QHBoxLayout *exampleL = new QHBoxLayout;
    exampleL->addWidget( new QLabel("Example") );
    exampleL->addWidget( m_exampleBox );

    QHBoxLayout *buttonsL = new QHBoxLayout;
    buttonsL->addWidget( m_runBtn );
    buttonsL->addWidget( m_quitBtn );

    QVBoxLayout *all = new QVBoxLayout;
    all->addLayout( resultL );
    all->addLayout( exampleL );
    all->addLayout( buttonsL );

    setLayout( all );
}

Dialog::~Dialog()
{

}

void Dialog::runExample()
{
    switch ( m_exampleBox->currentIndex() ) {
    case 0:
        exampleConcurrentRun();
        break;
    case 1:
        exampleFiltered();
        break;
    default:
        break;
    }
}

void Dialog::exampleConcurrentRun()
{
    QFuture<QString> future = QtConcurrent::run( myFunction );
    m_resultView->setText( future.result() );
}

void Dialog::exampleFiltered()
{
    QStringList strings;
    strings << "small" << "Big" << "smaller" << "Bigger" << "smallest" << "Biggest";

    QFuture<QString> lowerStrings = QtConcurrent::filtered( strings, isLowerCase );
    m_resultView->setText(
                "QtConcurrent:filtered(), show how to execute method in seperate thread. Method accepts QStringList and QFuture as a result returns QList<QString> with lower cap.\n\nUnfiltered strings: "
                + strings.join(", ")
                + "\n\nFiltered strings: " + QStringList( lowerStrings.results() ).join(", ")
            );
}
