#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include <QDialog>
#include <QProgressBar>
#include <QPushButton>
#include <QLineEdit>
#include <QVector>
#include <QThreadPool>
#include <QLabel>
#include <QStatusBar>

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
    void assignArray(QVector<int> array);
    void assignSum(const int sum);

private:
    QLabel *m_sumLabel;
    QProgressBar *m_progressBar;
    QLineEdit *m_elements;
    QPushButton *m_generateBtn;
    QPushButton *m_sumBtn;
    QPushButton *m_quitBtn;
    qint64 m_sum;
    QVector<int> m_array;
    QThreadPool *m_threadPool;
    QStatusBar *m_statusBar;
};

#endif // MAINDIALOG_H
