#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
private:
    QLabel *label1, *label_check, *label_chance;
    QLineEdit *lineEdit_num;
    QPushButton *button_check, *button_exit;
private slots:
    void CheckValue();
};
#endif // DIALOG_H
