#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtWidgets>
#include <vector>
#include "qantruleswidget.h"

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();
    int getNUmber();

public slots:
    void NewRules();
    void DeleteRules(int index);
    void Validate();

private:
    std::vector<QAntRulesWidget*> Rules;
    QVBoxLayout *mainLayout;
    QSpinBox *numberRules;
    QStackedWidget *stack;
    QVBoxLayout *secondPageLayout;
};

#endif // DIALOG_H
