#include "MainDialog.h"

#include <QIntValidator>
#include <QLabel>
#include <QHBoxLayout>

MainDialog::MainDialog(QWidget *parent)
    : QDialog(parent)
{
    m_sum = 0;
    QLabel *elements = new QLabel( "How many elements:" );
    QLabel *sum = new QLabel( QString("Sum: %1").arg(m_sum) );
    m_elements = new QLineEdit();
    m_generateBtn = new QPushButton( "Generate" );
    m_sumBtn = new QPushButton( "Sum" );
    m_quitBtn = new QPushButton( "Quit" );
    m_progressBar = new QProgressBar();

    m_elements->setValidator( new QIntValidator(1, 9999999, this) );
    enableGenerateBtn( m_elements->text() );

    connect( m_quitBtn, &QPushButton::clicked, this, &QDialog::close );
    connect( m_elements, &QLineEdit::textChanged, this, &MainDialog::enableGenerateBtn );

    QHBoxLayout *generateL = new QHBoxLayout();
    generateL->addWidget( elements );
    generateL->addWidget( m_elements );
    generateL->addWidget( m_generateBtn );

    QHBoxLayout *sumL = new QHBoxLayout();
    sumL->addWidget( m_progressBar );
    sumL->addWidget( m_sumBtn );

    QHBoxLayout *resultL = new QHBoxLayout();
    resultL->addWidget( sum );
    resultL->addWidget( m_quitBtn );

    QVBoxLayout *all = new QVBoxLayout();
    all->addLayout( generateL );
    all->addLayout( sumL );
    all->addLayout( resultL );

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
    m_array.clear();
}

void MainDialog::sumArray()
{

}
