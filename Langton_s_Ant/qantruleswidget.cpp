#include "qantruleswidget.h"

QAntRulesWidget::QAntRulesWidget(QWidget *parent) : QWidget(parent)
{
    QHBoxLayout *rules = new QHBoxLayout;
    colorButton = new QPushButton();
    QPixmap colorPixmap(16,16);
    colorPixmap.fill(Qt::white);
    QIcon ButtonIcon(colorPixmap);
    colorButton->setIcon(ButtonIcon);
    ruleButton = new QPushButton;
    colorButton->setText("color");
    ruleButton->setText("R");
    rules->addWidget(colorButton);
    rules->addWidget(ruleButton);
    setLayout(rules);
    color = Qt::white;
    rule = 0;
    connect(colorButton, SIGNAL(clicked(bool)), this, SLOT(setColor()));
    connect(ruleButton, SIGNAL(clicked(bool)), this, SLOT(setRule()));
}

QColor QAntRulesWidget::getColor(){
    return color;
}

int QAntRulesWidget::getRule(){
    return rule;
}

void QAntRulesWidget::setColor(){
    QColorDialog *dlg = new QColorDialog;
    color = dlg->getRgba();
    QPixmap colorPixmap(16,16);
    colorPixmap.fill(color);
    QIcon ButtonIcon(colorPixmap);
    colorButton->setIcon(ButtonIcon);;
}

void QAntRulesWidget::setRule(){
    if(rule){
        rule = 0;
        ruleButton->setText("R");
    }else{
        rule = 1;
        ruleButton->setText("L");
    }

}
