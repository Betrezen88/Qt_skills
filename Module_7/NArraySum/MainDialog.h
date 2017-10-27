#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include <QDialog>
#include <QProgressBar>
#include <QPushButton>
#include <QLineEdit>
#include <QVector>

class MainDialog : public QDialog
{
    Q_OBJECT

public:
    MainDialog(QWidget *parent = 0);
    ~MainDialog();

public slots:
    void enableGenerateBtn(const QString &value);
    void generateArray();
    void sumArray();

private:
    QProgressBar *m_progressBar;
    QLineEdit *m_elements;
    QPushButton *m_generateBtn;
    QPushButton *m_sumBtn;
    QPushButton *m_quitBtn;
    qint64 m_sum;
    QVector m_array;
};

#endif // MAINDIALOG_H
