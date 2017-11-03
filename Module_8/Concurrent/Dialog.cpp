#include "Dialog.h"
#include "external.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QtConcurrent/QtConcurrent>
#include <QFuture>
#include <QString>
#include <QStringList>
#include <QTime>

#include <QDebug>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    m_quitBtn = new QPushButton( "Quit" );
    m_runBtn = new QPushButton( "Run" );
    m_resultView = new QTextEdit;
    m_exampleBox = new QComboBox;

    m_resultView->setReadOnly( true );
    m_exampleBox->addItem( "QtConcurrent::run(aFunction)" );
    m_exampleBox->addItem( "QtConcurrent::filter()" );
    m_exampleBox->addItem( "Qt::Concurrent::filtered()" );
    m_exampleBox->addItem( "Qt::Concurrent::filteredReduce()" );

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

    setMinimumSize(500, 500);
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
        exampleFilter();
        break;
    case 2:
        exampleFiltered();
        break;
    case 3:
        exampleFilteredReduce();
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

void Dialog::exampleFilter()
{
    QString result = "QtConcurrent::filter(), shows how to filter container by method. Method checks if value is bigger than 10. Method filter modify container passed as argument. \n\nVector before filter: ";
    QVector<int> array;
    qsrand( QTime::currentTime().msec() );
    for ( int i=0; i<10; ++i ) {
        array.append( qrand() % 20 + 1 );
        result += QString::number( array.at(i) ) + ", ";
    }

    QFuture<void> future = QtConcurrent::filter( array, lessThen10 );

    future.waitForFinished();

    result += "\n\nVector after filter: ";
    for( int i=0; i<array.size(); ++i )
        result += QString::number( array.at(i) ) + ", ";

    m_resultView->setText( result );
}

void Dialog::exampleFiltered()
{
    QStringList strings;
    strings << "small" << "Big" << "smaller" << "Bigger" << "smallest" << "Biggest";

    QFuture<QString> lowerStrings = QtConcurrent::filtered( strings, isLowerCase );
    m_resultView->setText(
                "QtConcurrent:filtered(), show how to execute method in seperate thread. "
                "Method accepts QStringList and QFuture as a result returns QList<QString> with lower cap."
                "\n\nUnfiltered strings: " + strings.join(", ")
                + "\n\nFiltered strings: " + QStringList( lowerStrings.results() ).join(", ")
                );
}

void Dialog::exampleFilteredReduce()
{
    QStringList strings;
    strings << "small" << "Big" << "smaller" << "Bigger" << "smallest" << "Biggest";

    QFuture<QStringList> dictionary = QtConcurrent::filteredReduced( strings, isLowerCase, addToDictionary );

    m_resultView->setText(
                "QtConcurrent::filteredReduce(), show how to execute method on seperate thread. "
                "You need function that will filter container. Result is available from QFuture.\n\n"
                "Unfiltered container: " + strings.join(", ")
                + "\n\nFiltered container: " + dictionary.result().join(", ")
            );
}
