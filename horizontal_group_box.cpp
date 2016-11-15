#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStackedWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QFormLayout>
#include <QGroupBox>
#include <QtWidgets>


MainWindow::MainWindow(QWidget *parent) : //constructor, QMainWindow jest widgetem KONTENEREM
    QMainWindow(parent),
    ui(new Ui::MainWindow) //initializing UI object

{

    createHorizontalGroupBox();
    createMainGridGroupBox();
    ui->setupUi(this); //opens window

    this->setFixedSize(1000, 700);
    this->setWindowTitle("LightsApp");

    //centralny Widget dla MainWindow
    centralWidget = new QStackedWidget(this);
    this->setCentralWidget(centralWidget);

    /* {-*-} {-*-} {-*-} {-*-} {-*-} */
    //pierwsza strona stackWidgetu i layout
    menuPage = new QWidget(this);
    menuPageLayout = new QVBoxLayout(this);  //new QGridLayout(this);
    menuPage->setLayout(menuPageLayout);
    centralWidget->addWidget(menuPage);

    QLabel *title = new QLabel(tr("Light Control App"));
    menuPageLayout->addWidget(title);
    menuPageLayout->addWidget(mainGridGroupBox);


    //0 przycisk

/*
    //1 przycisk
    hallwayButton = new QPushButton("Hallway", this);
    hallwayButton->setFixedSize(200,200);
    menuPageLayout->addWidget(hallwayButton);
    connect(hallwayButton, SIGNAL (clicked()), this, SLOT (on_hallway_btn_clicked()));

    //2 przycisk
    livingRoomButton = new QPushButton("Living Room", this);
    livingRoomButton->setFixedSize(200,200);
    menuPageLayout->addWidget(livingRoomButton,1,2);
    connect(livingRoomButton, SIGNAL (clicked()), this, SLOT (on_livigRoom_btn_clicked()));

    //3 przycisk
    kitchenButton = new QPushButton("Kitchen", this);
    kitchenButton->setFixedSize(200,200);
    menuPageLayout->addWidget(kitchenButton,2,0);

    //4 przycisk
    bedroomButton = new QPushButton("Bedroom", this);
    bedroomButton->setFixedSize(200,200);
    menuPageLayout->addWidget(bedroomButton,2,1);

    //5 przycisk
    bathroomButton = new QPushButton("Bathroom", this);
    bathroomButton->setFixedSize(200,200);
    menuPageLayout->addWidget(bathroomButton,2,2);


    /* {-*-} {-*-} {-*-} {-*-} {-*-} */
    //druga strona
    hallwayPage = new QWidget(this);
    hallwayLay = new QVBoxLayout(this);
    hallwayPage->setLayout(hallwayLay);
    centralWidget->addWidget(hallwayPage);

    menuBckButton = new QPushButton("Back", this);
    //menuBckButton->setFixedSize(50,30);

    QPixmap pixmap("C:/Users/Olka/Documents/Studia 4/ENG THESIS/home-512.png");
    pixmap = pixmap.scaledToWidth(50);
    QIcon ButtonIcon(pixmap);
    menuBckButton->setIcon(ButtonIcon);
    menuBckButton->setIconSize(pixmap.rect().size());

    hallwayLay->addWidget(horizontalGroupBox);
    hallwayLay->addWidget(menuBckButton);
    connect(menuBckButton, SIGNAL (clicked()), this, SLOT(on_menu_bck_button_clicked()));


    /* {-*-} {-*-} {-*-} {-*-} {-*-} */

    livingRoomPage = new QWidget(this);
    livingRoomLay = new QFormLayout(this);
    livingRoomPage->setLayout(livingRoomLay);
    centralWidget->addWidget(livingRoomPage);

    QPushButton *menuBckButton2 = new QPushButton("Back", this);
    menuBckButton2->setFixedSize(50,30);
    livingRoomLay->addWidget(menuBckButton2);
    connect(menuBckButton2, SIGNAL (clicked()), this, SLOT(on_menu_bck_button_clicked()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createMainGridGroupBox()
{
    mainGridGroupBox = new QGroupBox();
    QGridLayout *layout = new QGridLayout;

    addRoomButton = new QPushButton("Add Button");
    addRoomButton->setFixedSize(200,200);
    layout->addWidget(addRoomButton,0,0);

    hallwayButton = new QPushButton("Hallway");
    hallwayButton->setFixedSize(200,200);
    layout->addWidget(hallwayButton,0,1);
    connect(hallwayButton, SIGNAL (clicked()), this, SLOT (on_hallway_btn_clicked()));

    livingRoomButton = new QPushButton("Living Room");
    livingRoomButton->setFixedSize(200,200);
    layout->addWidget(livingRoomButton,0,2);
    connect(livingRoomButton, SIGNAL (clicked()), this, SLOT (on_livigRoom_btn_clicked()));

    kitchenButton = new QPushButton("Kitchen", this);
    kitchenButton->setFixedSize(200,200);
    layout->addWidget(kitchenButton,1,0);

    bedroomButton = new QPushButton("Bedroom", this);
    bedroomButton->setFixedSize(200,200);
    layout->addWidget(bedroomButton,1,1);

    bathroomButton = new QPushButton("Bathroom", this);
    bathroomButton->setFixedSize(200,200);
    layout->addWidget(bathroomButton,1,2);

    layout->setRowStretch(0,15);
    layout->setRowStretch(1,15);
    layout->setColumnStretch(0,5);
    layout->setColumnStretch(1,5);
    layout->setColumnStretch(2,5);
    //layout->setColumnStretch(2, 20);
    mainGridGroupBox->setLayout(layout);
}


void MainWindow::createHorizontalGroupBox()
{
    horizontalGroupBox = new QGroupBox(tr("Horizontal layout"));
    QHBoxLayout *layout = new QHBoxLayout;

    for (int i = 0; i < 4; ++i) {
        buttons[i] = new QPushButton(tr("Button %1").arg(i + 1));
        layout->addWidget(buttons[i]);
    }
    horizontalGroupBox->setLayout(layout);
}

void MainWindow::on_hallway_btn_clicked()
{
    centralWidget->setCurrentWidget(hallwayPage);
}
void MainWindow::on_menu_bck_button_clicked()
{
    centralWidget->setCurrentWidget(menuPage);
}
void MainWindow::on_livigRoom_btn_clicked()
{
    centralWidget->setCurrentWidget(livingRoomPage);
}

/*
void MainWindow::on_living_room_btn_clicked()
{
}

void MainWindow::on_kitchen_btn_clicked()
{
}

void MainWindow::on_bedroom_btn_clicked()
{
}

void MainWindow::on_bathroom_btn_clicked()
{
}

void MainWindow::on_bathroom_bck_clicked()
{
}

void MainWindow::on_add_room_btn_clicked()
{
}
*/
