#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QTextEdit>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void startWorker();

private:
    QPushButton *m_quitBtn;
    QPushButton *m_runBtn;
    QTextEdit *m_resultView;
};

#endif // DIALOG_H