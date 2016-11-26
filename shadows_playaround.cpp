#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStackedWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QFormLayout>
#include <QGroupBox>
#include <QtWidgets>
#include <QGraphicsScene>


MainWindow::MainWindow(QWidget *parent) : //constructor, QMainWindow jest widgetem KONTENEREM
    QMainWindow(parent),
    ui(new Ui::MainWindow) //initializing UI object

{

    createHorizontalGroupBox();
    //createVerticalGroupBox();
    createMainGridGroupBox();
    ui->setupUi(this); //opens window

    this->setStyleSheet(
                    "QPushButton {"
                    "font: bold 14px; }"

                    "QMainWindow {"
                    "color: qlineargradient(spread:pad, x1:0 y1:0, x2:1 y2:01 stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));"
                    "background: qlineargradient( x1:0 y1:0, x2:1 y2:1, stop:0 grey, stop:1 black);}"

                    "QGroupBox {"
                    "border:0; }"
                    );

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


    /* ----------------------------- */
    //druga strona
    hallwayPage = new QWidget(this);
    hallwayLay = new QVBoxLayout(this);
    hallwayPage->setLayout(hallwayLay);
    centralWidget->addWidget(hallwayPage);

    menuBckButton = new QToolButton(this);
    //menuBckButton->setFixedSize(50,30);

    QPixmap pixmap("C:/Users/Olka/Documents/Studia 4/ENG THESIS/home-512.png");
    pixmap = pixmap.scaledToWidth(60);
    QIcon ButtonIcon(pixmap);
    menuBckButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    menuBckButton->setText("Back");
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

    QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect;
    effect->setBlurRadius(5);
    effect->setColor(Qt::magenta);
    QGraphicsScene scene;
    scene.setSceneRect( -100.0, -100.0, 200.0, 200.0 );


    QPixmap btn1("C:/Users/Olka/Documents/Studia 4/ENG THESIS/icons/1.png");
    btn1 = btn1.scaledToHeight(200);
    QIcon btn1icon(btn1);
    QPixmap btn2("C:/Users/Olka/Documents/Studia 4/ENG THESIS/icons/2.png");
    btn2 = btn2.scaledToHeight(200);
    QIcon btn2icon(btn2);
    QPixmap btn3("C:/Users/Olka/Documents/Studia 4/ENG THESIS/icons/3.png");
    btn3 = btn3.scaledToHeight(200);
    QIcon btn3icon(btn3);
    QPixmap btn4("C:/Users/Olka/Documents/Studia 4/ENG THESIS/icons/4.png");
    btn4 = btn4.scaledToHeight(200);
    QIcon btn4icon(btn4);
    QPixmap btn5("C:/Users/Olka/Documents/Studia 4/ENG THESIS/icons/5.png");
    btn5 = btn5.scaledToHeight(200);
    QIcon btn5icon(btn5);

    bulb_icons.append(btn1icon);
    bulb_icons.append(btn2icon);
    bulb_icons.append(btn3icon);
    bulb_icons.append(btn4icon);
    bulb_icons.append(btn5icon);

    bulb_icons_pixmap.append(btn1);
    bulb_icons_pixmap.append(btn2);
    bulb_icons_pixmap.append(btn3);
    bulb_icons_pixmap.append(btn4);
    bulb_icons_pixmap.append(btn5);

    QGraphicsPixmapItem *gpItem = scene.addPixmap(btn5);
    //gpItem->setTransformationMode(Qt::SmoothTransformation);

    gpItem->setGraphicsEffect(effect);

    for (int i = 0; i < 5; ++i) {

        buttons[i] = new QPushButton(this);
        verticalGroupBox[i] = new QGroupBox();        //*
        Vlayout[i] = new QVBoxLayout;
        horProgBarGB[i] = new QGroupBox();
        horProgBarLay[i] = new QHBoxLayout;
        verticalSliders[i] = new QSlider(Qt::Vertical,this);
        Vstatus[i] = new QProgressBar(this);
        Vstatus[i]->setOrientation(Qt::Vertical);
        Vstatus[i]->setTextVisible(true);
        //Vstatus[i]->setAlignment(Qt::AlignCenter);
        //buttons[i] = new QPushlButton(tr("Button %1").arg(i + 1));
        Vlayout[i]->addWidget(buttons[i]);
        horProgBarLay[i]->addWidget(verticalSliders[i]);
        horProgBarLay[i]->addWidget(Vstatus[i]);

        connect(verticalSliders[i], SIGNAL (valueChanged(int)), Vstatus[i], SLOT(setValue(int)));

        buttons[i]->setIcon(bulb_icons[i]);
        buttons[i]->setIconSize(bulb_icons_pixmap[i].rect().size());
        horProgBarGB[i]->setLayout(horProgBarLay[i]);
        verticalGroupBox[i]->setLayout(Vlayout[i]);                      //*
        Vlayout[i]->addWidget(horProgBarGB[i]);
        layout->addWidget(verticalGroupBox[i]);                          //*
    }
    horizontalGroupBox->setLayout(layout);
}
/*
void MainWindow::createVerticalGroupBox(){
    verticalGroupBox = new QGroupBox(tr("Vertical layout"));
    QVBoxLayout *Vlayout = new QVBoxLayout;

    Vlayout->addWidget(buttons[i]);
    verticalGroupBox->setLayout(Vlayout);
}*/

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
