#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QComboBox>
#include <QPushButton>
#include <QTextEdit>

#include "Converter.hpp"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void translateInput();

private:
    QWidget *m_centralWidget;
    QComboBox *m_translation;
    QPushButton *m_translateBtn;
    QTextEdit *m_inputEdit;
    QTextEdit *m_outputEdit;
    Converter m_converter;
};

#endif // MAINWINDOW_HPP
