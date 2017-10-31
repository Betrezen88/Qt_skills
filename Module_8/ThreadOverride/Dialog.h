#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QStatusBar>
#include <QTextEdit>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    QPushButton *m_quitBtn;
    QPushButton *m_runBtn;
    QStatusBar *m_statusBar;
    QTextEdit *m_resultView;
};

#endif // DIALOG_H
