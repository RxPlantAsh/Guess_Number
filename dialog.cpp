#include "dialog.h"
#include <QGridLayout>

#include <stdlib.h>
#include <time.h>

#define CHANCE 10

int randValue;
int chance = CHANCE;

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    srand(time(NULL));
    randValue = rand() % 99 + 1;

    label1 = new QLabel(this);
    label_check = new QLabel(this);
    label_chance = new QLabel(this);
    lineEdit_num = new QLineEdit(this);
    button_check = new QPushButton(this);
    button_exit = new QPushButton(this);

    label1->setText("Press your value:");
    label_chance->setNum(chance);
    button_check->setText("Check");
    button_exit->setText("Exit");

    QGridLayout *mainLayout = new QGridLayout(this);

    mainLayout->addWidget(label1, 0, 0);
    mainLayout->addWidget(lineEdit_num, 0, 1);
    mainLayout->addWidget(label_chance, 1, 0);
    mainLayout->addWidget(button_check, 1, 1);
    mainLayout->addWidget(label_check, 2, 0);
    mainLayout->addWidget(button_exit, 2, 1);

    connect(button_check, SIGNAL(clicked()), this, SLOT(CheckValue()));
    connect(button_exit, SIGNAL(clicked()), this, SLOT(close()));
}

Dialog::~Dialog()
{
    delete label1;
    delete label_check;
    delete lineEdit_num;
    delete button_check;
}

void Dialog::CheckValue()
{
    QString Str_fail = "NO MORE CHANCE!randValue = ";
    QString tempStr;
    if (--chance <= 0) {
        tempStr.setNum(randValue);
        Str_fail.append(tempStr);
        label_check->setText(Str_fail);
        label_chance->setNum(0);
        lineEdit_num->setEnabled(false);
        button_check->setEnabled(false);
        return;
    }

    QString Str_win = "Whoops!Right value.";
    QString Str_TooBig = "Wrong value, too big.";
    QString Str_TooSmall = "Wrong value, too small";

    bool ok;
    int userValue;

    tempStr = lineEdit_num->text();
    userValue = tempStr.toInt(&ok);

    if(userValue == randValue){
        label_check->setText(Str_win);
        lineEdit_num->setEnabled(false);
        button_check->setEnabled(false);
        return;
    } else if (userValue == 114514){
        label_check->setText("?!Maybe you win...");
        lineEdit_num->setEnabled(false);
        button_check->setEnabled(false);
        return;
    }
    label_chance->setNum(chance);
    label_check->setText(userValue > randValue? Str_TooBig: Str_TooSmall);
}
