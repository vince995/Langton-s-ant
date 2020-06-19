#include "dialog.h"
#include <vector>
#include <fstream>

Dialog::Dialog(QWidget *parent) : QDialog(parent)
{
    mainLayout = new QVBoxLayout;
    setLayout(mainLayout);

    QWidget *firstPage = new QWidget;
    QWidget *secondPage = new QWidget;
    QVBoxLayout *firstPageLayout = new QVBoxLayout;
    secondPageLayout = new QVBoxLayout;
    secondPageLayout->setDirection(QBoxLayout::BottomToTop);
    firstPage->setLayout(firstPageLayout);
    secondPage->setLayout(secondPageLayout);
    stack = new QStackedWidget;
    stack->addWidget(firstPage);
    stack->addWidget(secondPage);
    QPushButton *validate = new QPushButton;
    validate->setText("start");
    secondPageLayout->addWidget(validate);


    QHBoxLayout *numberRulesLayout = new QHBoxLayout;
    QPushButton *numberRulesButton = new QPushButton;
    numberRulesButton->setText("validate");
    numberRules = new QSpinBox;
    numberRulesLayout->addWidget(numberRulesButton);
    numberRulesLayout->addWidget(numberRules);
    firstPageLayout->addLayout(numberRulesLayout);
    mainLayout->addWidget(stack);
    connect(numberRulesButton, SIGNAL(released()), this, SLOT(NewRules()));
    connect(validate, SIGNAL(released()), this, SLOT(Validate()));
}

Dialog::~Dialog()
{
    Rules.clear();
}

void Dialog::NewRules(){
    for(int i = 0; i < numberRules->value(); i++){
        QAntRulesWidget *rules = new QAntRulesWidget;
        secondPageLayout->addWidget(rules);
        Rules.push_back(rules);
    }
    stack->setCurrentIndex(1);
}

void Dialog::DeleteRules(int index){
    mainLayout->removeWidget(Rules[index]);
    Rules.erase(Rules.begin()+index);
}

int Dialog::getNUmber(){
    return Rules.size();
}

void Dialog::Validate(){
    std::ofstream file("config.txt");
    //std::vector<QColor> colors;
    //std::vector<int> rules;
    for(int i = 0; i < Rules.size(); i++){
        //colors.push_back(Rules[i]->getColor());
        //rules.push_back(Rules[i]->getRule());
        if(Rules[i]->getRule())
            file << Rules[i]->getColor().red() << "," <<Rules[i]->getColor().green() << "," << Rules[i]->getColor().blue() << ";" << "R" << std::endl;
        else
            file << Rules[i]->getColor().red() << "," <<Rules[i]->getColor().green() << "," << Rules[i]->getColor().blue() << ";" << "L" << std::endl;


    }
    accept();
}
