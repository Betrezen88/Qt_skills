#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include <QDialog>
#include <QProgressBar>
#include <QPushButton>
#include <QLineEdit>

class MainDialog : public QDialog
{
    Q_OBJECT

public:
    MainDialog(QWidget *parent = 0);
    ~MainDialog();

private:
    QProgressBar *m_progressBar;
    QLineEdit *m_elements;
    QPushButton *m_generateBtn;
    QPushButton *m_sumBtn;
    QPushButton *m_quitBtn;
    qint64 m_sum;
};

#endif // MAINDIALOG_H
