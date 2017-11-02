#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QTextEdit>
#include <QComboBox>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void runExample();

private:
    void exampleConcurrentRun();
    void exampleFilter();
    void exampleFiltered();

private:
    QPushButton *m_quitBtn;
    QPushButton *m_runBtn;
    QTextEdit *m_resultView;
    QComboBox *m_exampleBox;
};

#endif // DIALOG_H
