#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

class QLineEdit;
class QProgressBar;
class QPushButton;

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    QLineEdit* m_pArraySize;
    QLineEdit* m_pObjectCount;
    QProgressBar* m_pProgressBar;
    QPushButton* m_pRunBtn;
    QPushButton* m_pQuitBtn;
};

#endif // DIALOG_H
