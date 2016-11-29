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
    //createVerticalGroupBox();
    createMainGridGroupBox();
    ui->setupUi(this); //opens window

    //none,0
    this->setStyleSheet(
                    "#buttonsStyle {"
                    "font: bold 14px;"
                    "border: none;  }"

                    "#bckHome {"
                    "border: none;  }"

                    "#bckHome:pressed {"
                    "border: none;"
                    "padding-left: 1px;"
                    "padding-top: 1px;}"

                    "QMainWindow {"
                    "color: qlineargradient(spread:pad, x1:0 y1:0, x2:1 y2:01 stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));"
                    "background: qlineargradient( x1:0 y1:0, x2:1 y2:1, stop:0 black, stop:1 white);}"

                    "QGroupBox {"
                    "border: 0; }"

                    "#mainStyle {"
                    "background-image: url(C:/Users/Olka/Documents/Studia 4/ENG THESIS/icons/x.png); "
                    "background-position: bottom; "
                    "background-repeat: no-repeat;"
                    "background-size: cover; }"

                    "#horBulbsStyle {"
                    "background-color: rgba(227, 227, 227, 120);"
                    "border-radius: 10px; "
                    "padding:20px;}"

                    "@font-face {"
                    "font-family: Dejavu; "
                    "src: url(C:/Users/Public/Pictures/Photoshop/Fonts/dejavu-sans-mono/DejaVuSansMono.ttf); }"

                    "#menuName {"
                    "font-family: DejaVuSansMono;"
                    "font-style: bold;"
                    "font-size: 50px;"
                    "color: white; }"

                    "#mainStrip {"
                    "background-color: rgba(227, 227, 227, 120);}"

                    "#mainBtns {"
                    "background-color: rgba(59, 239, 253, 120);"
                    "background: qlineargradient(spread:pad, x1:0, y1:0.5, x2:0, y2:1, stop:0 rgba(211, 211, 211, 180), stop:0.5 rgba(175, 175, 175, 180));"
                    "border-radius: 3px;"
                    "font-family: Tahoma;"
                    "font-weight: bold;"
                    "font-size: 15px;"
                    "color: white;}" //07cac3

                    "#mainBtns:hover {"
                    "background-color: rgba(59, 239, 253, 120);"
                    "background: qlineargradient(spread:pad, x1:0, y1:0.57, x2:0, y2:1, stop:0 rgba(191, 232, 235, 180), stop:0.5 rgba(109, 221, 230, 180));"
                    "border-radius: 3px;"
                    "font-family: Tahoma;"
                    "font-weight: bold;"
                    "font-size: 15px;"
                    "border-style:outset;"
                    "border-width:1px;"
                    "border-top-color: #618c8a;"
                    "border-left-color: #618c8a;"
                    "border-right-color: #6ab5b2;"
                    "border-bottom-color: #6ab5b2;"
                    "color: white;}"

                    "#mainBtns:pressed {"
                    "background-color: rgba(59, 239, 253, 120);"
                    "background: qlineargradient(spread:pad, x1:0, y1:0.57, x2:0, y2:1, stop:0 rgba(59, 239, 253, 180), stop:0.5 rgba(7, 202, 195, 180));"
                    "border-radius: 3px;"
                    "font-family: Tahoma;"
                    "font-weight: bold;"
                    "font-size: 15px;"
                    "border-style: inset;"
                    "border-width:1px;"
                    "border-right-color: #427876;"
                    "border-bottom-color: #427876;"
                    "border-top-color: #699c9a;" //699c9a,659896,569693
                    "border-left-color: #699c9a;"
                    "padding-left: 1px;"
                    "padding-top: 1px;"
                    "color: white;}"
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
    menuPage->setObjectName("mainStyle");
    centralWidget->addWidget(menuPage);

    QLabel *strip = new QLabel(this);
    strip->setObjectName("mainStrip");
    strip->setGeometry(QRect(0, 26, 1000, 66));


    QLabel *title = new QLabel(tr("Light Control App"));
    title->setObjectName("menuName");
    menuPageLayout->addWidget(title);
    menuPageLayout->addSpacing(10);
    menuPageLayout->addWidget(cleanVGB);


    /* ----------------------------- */
    //druga strona
    hallwayPage = new QWidget(this);
    hallwayLay = new QVBoxLayout(this);
    hallwayPage->setLayout(hallwayLay);

    QLabel *titleH = new QLabel(tr("Hallway"));
    titleH->setObjectName("menuName");
    hallwayLay->addWidget(titleH);

    hallwayLay->addSpacing(50);
    centralWidget->addWidget(hallwayPage);

    menuBckButton = new QToolButton(this);
    //menuBckButton->setFixedSize(50,30);
    menuBckButton->setObjectName("bckHome");



    QPixmap pixmap("C:/Users/Olka/Documents/Studia 4/ENG THESIS/home-512.png");
    pixmap = pixmap.scaledToWidth(60);
    QIcon ButtonIcon(pixmap);
    menuBckButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    //menuBckButton->setText("Back");
    menuBckButton->setIcon(ButtonIcon);
    menuBckButton->setIconSize(pixmap.rect().size());

    hallwayLay->addWidget(horizontalGroupBox);
    hallwayLay->addWidget(menuBckButton);
    connect(menuBckButton, SIGNAL (clicked()), this, SLOT(on_menu_bck_button_clicked()));
    hallwayLay->setAlignment(Qt::AlignCenter);

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

    cleanVGB = new QGroupBox(this);
    QVBoxLayout *cleanVL = new QVBoxLayout(this);

    mainVGroupBox = new QGroupBox();
    QVBoxLayout *mainVLayout = new QVBoxLayout();

    mainGridGroupBox = new QGroupBox();
    QGridLayout *layout = new QGridLayout;

    addRoomButton = new QPushButton("ADD BUTTON", this);
    addRoomButton->setFixedSize(180,100);
    addRoomButton->setObjectName("mainBtns");
    layout->addWidget(addRoomButton,0,0);

    //addRoomButton->setAttribute(Qt::WA_TranslucentBackground, true);//////////////////////

    hallwayButton = new QPushButton("HALLWAY", this);
    hallwayButton->setFixedSize(180,100);
    hallwayButton->setObjectName("mainBtns");
    layout->addWidget(hallwayButton,0,1);
    connect(hallwayButton, SIGNAL (clicked()), this, SLOT (on_hallway_btn_clicked()));

    livingRoomButton = new QPushButton("LIVING ROOM",this);
    livingRoomButton->setFixedSize(180,100);
    livingRoomButton->setObjectName("mainBtns");
    layout->addWidget(livingRoomButton,0,2);
    connect(livingRoomButton, SIGNAL (clicked()), this, SLOT (on_livigRoom_btn_clicked()));

    kitchenButton = new QPushButton("KITCHEN", this);
    kitchenButton->setFixedSize(180,100);
    kitchenButton->setObjectName("mainBtns");
    layout->addWidget(kitchenButton,1,0);

    bedroomButton = new QPushButton("BEDROOM", this);
    bedroomButton->setFixedSize(180,100);
    bedroomButton->setObjectName("mainBtns");
    layout->addWidget(bedroomButton,1,1);

    bathroomButton = new QPushButton("BATHROOM", this);
    bathroomButton->setFixedSize(180,100);
    bathroomButton->setObjectName("mainBtns");
    layout->addWidget(bathroomButton,1,2);

    layout->setRowStretch(0,15);
    layout->setRowStretch(1,15);
    layout->setColumnStretch(0,5);
    layout->setColumnStretch(1,5);
    layout->setColumnStretch(2,5);
    //layout->setColumnStretch(2, 20);
    mainGridGroupBox->setLayout(layout);

    //mainVLayout->insertSpacing(0,50);
    mainVLayout->addWidget(mainGridGroupBox);
    mainVGroupBox->setLayout(mainVLayout);

    cleanVL->addSpacing(190);
    cleanVL->addWidget(mainVGroupBox);
    cleanVGB->setLayout(cleanVL);
}


void MainWindow::createHorizontalGroupBox()
{
    horizontalGroupBox = new QGroupBox(tr("Horizontal layout"), this);
    QHBoxLayout *layout = new QHBoxLayout;
    horizontalGroupBox->setObjectName("horBulbsStyle");
    //myFilter->draw(painter, QPoint(0, 0), originalPixmap);
    //effect->setBlurRadius(5);
    //effect->setColor(Qt::magenta);
    //QGraphicsScene scene;
    //scene.setSceneRect( -100.0, -100.0, 200.0, 200.0 );


    QPixmap btn11("C:/Users/Olka/Documents/Studia 4/ENG THESIS/icons/1.png");
    btn11 = btn11.scaledToHeight(100);
    QIcon btn11icon(btn11);
    QPixmap btn22("C:/Users/Olka/Documents/Studia 4/ENG THESIS/icons/111.png");
    btn22 = btn22.scaledToHeight(100);
    QIcon btn22icon(btn22);
    QPixmap btn33("C:/Users/Olka/Documents/Studia 4/ENG THESIS/icons/333.png");
    btn33 = btn33.scaledToHeight(100);
    QIcon btn33icon(btn33);
    QPixmap btn44("C:/Users/Olka/Documents/Studia 4/ENG THESIS/icons/3.png");
    btn44 = btn44.scaledToHeight(100);
    QIcon btn44icon(btn44);
    QPixmap btn55("C:/Users/Olka/Documents/Studia 4/ENG THESIS/icons/4.png");
    btn55 = btn55.scaledToHeight(100);
    QIcon btn55icon(btn55);

    bulb_icons2.append(btn11icon);
    bulb_icons2.append(btn22icon);
    bulb_icons2.append(btn33icon);
    bulb_icons2.append(btn44icon);
    bulb_icons2.append(btn55icon);

    bulb_icons_pixmap2.append(btn11);
    bulb_icons_pixmap2.append(btn22);
    bulb_icons_pixmap2.append(btn33);
    bulb_icons_pixmap2.append(btn44);
    bulb_icons_pixmap2.append(btn55);

    QPixmap btn1("C:/Users/Olka/Documents/Studia 4/ENG THESIS/icons/11.png");
    btn1 = btn1.scaledToHeight(100);
    QIcon btn1icon(btn1);
    QPixmap btn2("C:/Users/Olka/Documents/Studia 4/ENG THESIS/icons/22.png");
    btn2 = btn2.scaledToHeight(100);
    QIcon btn2icon(btn2);
    QPixmap btn3("C:/Users/Olka/Documents/Studia 4/ENG THESIS/icons/33.png");
    btn3 = btn3.scaledToHeight(100);
    QIcon btn3icon(btn3);
    QPixmap btn4("C:/Users/Olka/Documents/Studia 4/ENG THESIS/icons/44.png");
    btn4 = btn4.scaledToHeight(100);
    QIcon btn4icon(btn4);
    QPixmap btn5("C:/Users/Olka/Documents/Studia 4/ENG THESIS/icons/55.png");
    btn5 = btn5.scaledToHeight(100);
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

    QLabel *imageLabel = new QLabel(this);
    QLabel *imageLabel2 = new QLabel(this);
    layout->addWidget(imageLabel);
    layout->addWidget(imageLabel2);
    imageLabel->setGeometry(100,100, 100,100);
    imageLabel2->setGeometry(100,100, 100,100);
    imageLabel->setPixmap(btn2);
    imageLabel2->setPixmap(btn22);

    for (int i = 0; i < 5; ++i) {

        buttons[i] = new QPushButton(this);
        buttons[i]->setObjectName("buttonsStyle");
        verticalGroupBox[i] = new QGroupBox();        //*
        Vlayout[i] = new QVBoxLayout;
        horProgBarGB[i] = new QGroupBox();
        horProgBarLay[i] = new QHBoxLayout;
        verticalSliders[i] = new QSlider(Qt::Vertical,this);
        //Vstatus[i]->setAlignment(Qt::AlignCenter);
        //buttons[i] = new QPushlButton(tr("Button %1").arg(i + 1));
        Vlayout[i]->addWidget(buttons[i]);
        horProgBarLay[i]->addWidget(verticalSliders[i]);

        //buttons[i]->setIcon(bulb_icons[i]);
        //buttons[i]->setIconSize(bulb_icons_pixmap[i].rect().size());


//        buttons[i]->setIcon(dummyIcon);
  //      buttons[i]->setIconSize(comboPixmap.rect().size());

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
