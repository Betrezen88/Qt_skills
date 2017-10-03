#include "MainWindow.hpp"
#include "XmlConverter.hpp"
#include "JsonConverter.hpp"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QXmlStreamReader>
#include <QJsonDocument>
#include <QJsonObject>
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
        fromJSONtoXML();
    else
        fromXMLtoJSON();
}

void MainWindow::fromJSONtoXML()
{
    readJson();
}

void MainWindow::fromXMLtoJSON()
{
    readXML();
}

void MainWindow::readXML()
{
    QXmlStreamReader xmlReader( m_inputEdit->toPlainText() );
    XmlConverter converter;

    m_outputEdit->setPlainText( converter.convert(xmlReader) );
}

void MainWindow::readJson()
{
    QJsonDocument jsonReader = QJsonDocument::fromJson( m_inputEdit->toPlainText().toLocal8Bit() );
    JsonConverter converter;

    m_outputEdit->setPlainText( converter.convert(jsonReader) );
}
