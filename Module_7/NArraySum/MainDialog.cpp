#include "MainDialog.h"
#include "Generator.h"
#include "Adder.h"

#include <QThreadPool>
#include <QIntValidator>
#include <QLabel>
#include <QHBoxLayout>

MainDialog::MainDialog(QWidget *parent)
    : QDialog(parent)
{
    m_sum = 0;
    m_threadPool = QThreadPool::globalInstance();
    QLabel *elements = new QLabel( "How many elements:" );
    m_sumLabel = new QLabel( QString("Sum: %1").arg(m_sum) );
    m_elements = new QLineEdit();
    m_generateBtn = new QPushButton( "Generate" );
    m_sumBtn = new QPushButton( "Sum" );
    m_quitBtn = new QPushButton( "Quit" );
    m_progressBar = new QProgressBar();
    m_statusBar = new QStatusBar();

    m_elements->setValidator( new QIntValidator(1, 100000, this) );
    enableGenerateBtn( m_elements->text() );
    m_progressBar->setMinimum( 0 );
    m_statusBar->showMessage( "Ready" );

    connect( m_quitBtn, &QPushButton::clicked, this, &QDialog::close );
    connect( m_elements, &QLineEdit::textChanged, this, &MainDialog::enableGenerateBtn );
    connect( m_generateBtn, &QPushButton::clicked, this, &MainDialog::generateArray );
    connect( m_sumBtn, &QPushButton::clicked, this, &MainDialog::sumArray );

    QHBoxLayout *generateL = new QHBoxLayout();
    generateL->addWidget( elements );
    generateL->addWidget( m_elements );
    generateL->addWidget( m_generateBtn );

    QHBoxLayout *sumL = new QHBoxLayout();
    sumL->addWidget( m_progressBar );
    sumL->addWidget( m_sumBtn );

    QHBoxLayout *resultL = new QHBoxLayout();
    resultL->addWidget( m_sumLabel );
    resultL->addWidget( m_quitBtn );

    QVBoxLayout *all = new QVBoxLayout();
    all->addLayout( generateL );
    all->addLayout( sumL );
    all->addLayout( resultL );
    all->addWidget( m_statusBar );

    setLayout( all );
}

MainDialog::~MainDialog()
{

}

void MainDialog::enableGenerateBtn(const QString &value)
{
    m_generateBtn->setEnabled( value.toInt() > 0 );
}

void MainDialog::generateArray()
{
    m_statusBar->showMessage( "Generating array..." );
    qRegisterMetaType<QVector<int>>();
    m_progressBar->setMaximum( m_elements->text().toInt() );
    Generator *gen = new Generator( m_elements->text().toInt() );

    connect( gen, &Generator::update, m_progressBar, &QProgressBar::setValue );
    connect( gen, &Generator::finished, this, &MainDialog::assignArray );

    m_threadPool->start( gen );
}

void MainDialog::sumArray()
{
    m_statusBar->showMessage( "Adding array..." );
    Adder *adder = new Adder( m_array );

    connect( adder, &Adder::update, m_progressBar, &QProgressBar::setValue );
    connect( adder, &Adder::finished, this, &MainDialog::assignSum );

    m_threadPool->start( adder );
}

void MainDialog::assignArray(QVector<int> array)
{
    m_array = array;
    m_statusBar->showMessage( "Generating array done !" );
}

void MainDialog::assignSum(const int sum)
{
    m_sum = sum;
    m_sumLabel->setText( QString("Sum: %1").arg(m_sum) );
    m_statusBar->showMessage( "Adding array done !" );
}
