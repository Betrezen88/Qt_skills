#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QComboBox>
#include <QPushButton>
#include <QTextEdit>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void translateInput();

private:
    void fromJSONtoXML();
    void fromXMLtoJSON();
    void readXML();

private:
    QWidget *m_centralWidget;
    QComboBox *m_translation;
    QPushButton *m_translateBtn;
    QTextEdit *m_inputEdit;
    QTextEdit *m_outputEdit;
};

#endif // MAINWINDOW_HPP
