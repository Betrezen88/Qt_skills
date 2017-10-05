#include "MainWindow.hpp"

#include <QSpacerItem>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QXmlStreamReader>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("JSON & XML translator");
    setMinimumSize( 700, 500 );

    m_centralWidget = new QWidget;
    m_translation = new QComboBox;
    m_inputEdit = new QTextEdit;
    m_outputEdit = new QTextEdit;
    m_translateBtn = new QPushButton("Translate");

    m_translateBtn->setFixedWidth( 100 );

    m_translation->addItem("From JSON to XML");
    m_translation->addItem("From XML to JSON");

    connect(m_translateBtn, &QPushButton::clicked, this, &MainWindow::translateInput);

    QHBoxLayout *translateL = new QHBoxLayout;
    translateL->addWidget(new QLabel("Translate:"));
    translateL->addWidget(m_translation);
    translateL->addStretch(1);

    QVBoxLayout *inputL = new QVBoxLayout;
    inputL->addWidget(new QLabel("Input:"));
    inputL->addWidget(m_inputEdit);

    QVBoxLayout *outputL = new QVBoxLayout;
    outputL->addWidget(new QLabel("Output"));
    outputL->addWidget(m_outputEdit);

    QHBoxLayout *inpoutL = new QHBoxLayout;
    inpoutL->addLayout(inputL);
    inpoutL->addLayout(outputL);

    QVBoxLayout *all = new QVBoxLayout;
    all->addLayout(translateL);
    all->addLayout(inpoutL);
    all->addWidget(m_translateBtn);

    m_centralWidget->setLayout(all);
    setCentralWidget(m_centralWidget);
}

MainWindow::~MainWindow()
{

}

void MainWindow::translateInput()
{
    m_outputEdit->clear();
    if ( m_translation->currentIndex() == 0 )
        m_outputEdit->setPlainText( m_converter.jsonToXml(m_inputEdit->toPlainText()) );
    else
        m_outputEdit->setPlainText( m_converter.xmlToJson(m_inputEdit->toPlainText()) );
}
